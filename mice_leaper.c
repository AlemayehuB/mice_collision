#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// #define MAXPNT  20000		/* maximum number of points */
//
double x[596], y[596], z[596], vx[596], vy[596], vz[596];
//
// void energy(float *en);
// double rand_0_1(void);
// struct vector plum_sp(void);


void leapstep();				/* routine to take one step */
void accel();
void printstate();

int readresults(FILE *results);

int main()
{       int row, item, i, mstep, nstep, nout, n;

        char *fn = "out.dat";
        float dt, tnow;
        FILE *f=fopen("./setup/init.out", "r");
        FILE *out = fopen(fn, "w+");
        n = 596;

        for(row=0; row<n; row++){
                item = fscanf(f, "%lf %lf %lf %lf %lf %lf\n", &x[row], &y[row], &z[row], &vx[row], &vy[row], &vz[row]);
                //printf("%f %f\n", x[row],y[row]);
        }
        mstep = 64*125;				/* number of steps to take  */
        nout = 32;					/* steps between outputs    */
        dt = 1.0/32.0;		/* timestep for integration */
        tnow = 0.0;

        for (nstep = 0; nstep < mstep; nstep++) {	/* loop mstep times in all  */
            dt = 1.0/32.0;
            if (nstep % nout == 0)			/* if time to output state  */
              printstate(n, tnow, fn, nstep);		/* then call output routine */
            // if(nstep > mstep*0.5)
            //   dt = dt*0.25;
            leapstep(n, dt);			/* take integration step    */
            tnow = tnow + dt;			/* and update value of time */
          }
        fclose(f);
        fclose(out);
        return 0;
}


void accel(ax, ay, az, n)
 double ax[], ay[], az[];
 int n;
 {
  // G = 1
  double dx_a, dx_b, dy_a, dy_b, dz_a, dz_b, a_r3, b_r3, gm, x_cm, y_cm, z_cm, e;
  int i, j, k, galA_ind, galB_ind, neg;
  gm = 2.0;
  galA_ind = 0;
  galB_ind = 298;
  e = 0.0;
  for(k = 0; k < n; k++){
    // Acceleration of the test particles
     x_cm = x[galB_ind] + x[galA_ind];
     y_cm = y[galB_ind] + y[galA_ind];
     z_cm = z[galB_ind] + z[galA_ind];

     dx_a = x[k] - x[galA_ind];
     dx_b = x[k] - x[galB_ind];
     dy_a = y[k] - y[galA_ind];
     dy_b = y[k] - y[galB_ind];
     dz_a = z[k] - z[galA_ind];
     dz_b = z[k] - z[galB_ind];
     a_r3 = fabs(powf(((dx_a*dx_a) + (dy_a*dy_a)+ (dz_a*dz_a) + e*e),-1.5));
     b_r3 = fabs(powf(((dx_b*dx_b) + (dy_b*dy_b)+ (dz_b*dz_b) + e*e),-1.5));
     // ax[k] = -gm*dx_a*a_r3 - gm*dx_b*b_r3;
     // ay[k] = -gm*dy_a*a_r3 - gm*dy_b*b_r3;
     // az[k] = -gm*dz_a*a_r3 - gm*dz_b*b_r3;
     if (k > 298){
       ax[k] = -gm*dx_b*b_r3 ;
       ay[k] = -gm*dy_b*b_r3;
       az[k] = -gm*dz_b*b_r3;
    }
    if (k < 298){
      ax[k] = -gm*dx_a*a_r3 ;
      ay[k] = -gm*dy_a*a_r3;
      az[k] = -gm*dz_a*a_r3;
   }
     if (galA_ind == k){
       // Core Acceleration
       dx_a = x[k] - x[galB_ind];
       dy_a = y[k] - y[galB_ind];
       dz_a = z[k] - z[galB_ind];

       a_r3 = fabs(powf(((dx_a*dx_a) + (dy_a*dy_a)+ (dz_a*dz_a)+e*e),-1.5));
       ax[k] = -gm*dx_a*a_r3;
       ay[k] = -gm*dy_a*a_r3;
       az[k] = -gm*dz_a*a_r3;
    }
    if (galB_ind == k){
      // Core Acceleration
      dx_a = x[k] - x[galA_ind];
      dy_a = y[k] - y[galA_ind];
      dz_a = z[k] - z[galA_ind];

      a_r3 = fabs(powf(((dx_a*dx_a) + (dy_a*dy_a)+ (dz_a*dz_a)+e*e),-1.5));
      ax[k] = -gm*dx_a*a_r3;
      ay[k] = -gm*dy_a*a_r3;
      az[k] = -gm*dz_a*a_r3;
   }
      }
    }



 void leapstep(n, dt)
 int n;						/* number of points         */
 double dt;					/* timestep for integration */
 {
     int i;
     double ax[596];
     double ay[596];
     double az[596];

     accel(ax, ay, az, n);		/* call acceleration code   */
     for (i = 0; i < n; i++)	{		/* loop over all points...  */
 	     vx[i]= vx[i] + 0.5 * dt * ax[i];		/* advance vel by half-step */
       vy[i]= vy[i] + 0.5 * dt * ay[i];		/* advance vel by half-step */
       vz[i]= vz[i] + 0.5 * dt * az[i];
 }
     for (i = 0; i < n; i++){			/* loop over points again...*/
       x[i] = x[i] + dt * vx[i];		/* advance vel by half-step */
       y[i] = y[i] + dt * vy[i];		/* advance vel by half-step */
       z[i] = z[i] + dt * vz[i];		/* advance pos by full-step */
 }
     accel(ax, ay, az, n);			/* call acceleration code   */
     for (i = 0; i < n; i++)	{		/* loop over all points...  */
 	     vx[i]= vx[i] + 0.5 * dt * ax[i];		/* advance vel by half-step */
       vy[i]= vy[i] + 0.5 * dt * ay[i];		/* advance vel by half-step */
       vz[i]= vz[i] + 0.5 * dt * az[i];

 }
}
//
void printstate(n, tnow, fn, nstep)
int n;
char *fn;						/* number of points         */
double tnow;
int nstep;					/* current value of time    */
{
    int i;
    FILE *fp;
    char *fn_1;
//    printf("Writing step# %d....\n",nstep);

    fp = fopen(fn, "a");
    // fprintf(fp, "596 %12.6f\n", tnow);
    for (i = 0; i < n; i++)	/* loop over all points...  */
      fprintf(fp, "%12.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n",  x[i], y[i], z[i], vx[i], vy[i], vz[i]) ;
    fclose(fp);
}
