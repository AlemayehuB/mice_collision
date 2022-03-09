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
        FILE *f=fopen("./midterm_p/init.out", "r");
        FILE *out = fopen(fn, "w+");
        n = 596;

        for(row=0; row<n; row++){
                item = fscanf(f, "%lf %lf %lf %lf %lf %lf\n", &x[row], &y[row], &z[row], &vx[row], &vy[row], &vz[row]);
                //printf("%f %f\n", x[row],y[row]);
        }
        mstep = 64*100;				/* number of steps to take  */
        nout = 64*5;					/* steps between outputs    */
        dt = 1.0/32.0;		/* timestep for integration */
        tnow = 0.0;

        for (nstep = 0; nstep < mstep; nstep++) {	/* loop mstep times in all  */
              if (nstep % nout == 0)			/* if time to output state  */
                printstate(n, tnow, fn, nstep);		/* then call output routine */

              leapstep(n, dt);			/* take integration step    */
              tnow = tnow + dt;			/* and update value of time *
            // if (mstep % nout == 0){			/* if last output wanted    */
            //   printstate(MAXPNT, tnow, fn,nstep);		/* then output last step    */
            //   energy(en);
            //   fprintf(fil, "%.10f %.10f %.10f %.10f %.10f\n", tnow, en[0],en[1],en[2],en[3]);
            // }
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
     x_cm = x[galB_ind] + x[galA_ind];
     y_cm = y[galB_ind] + y[galA_ind];
     z_cm = z[galB_ind] + z[galA_ind];

     dx_a = x[k] - x[galA_ind];
     dx_b = x[k] - x[galB_ind];
     dy_a = y[k] - y[galA_ind];
     dy_b = y[k] - y[galB_ind];
     dz_a = z[k] - z[galA_ind];
     dz_b = z[k] - z[galB_ind];
     a_r3 = fabs(powf(((dx_a*dx_a) + (dy_a*dy_a)+ (dz_a*dz_a) + e),-1.5));
     b_r3 = fabs(powf(((dx_b*dx_b) + (dy_b*dy_b)+ (dz_b*dz_b) + e),-1.5));
     ax[k] = -gm*dx_a*a_r3 - gm*dx_b*b_r3;
     ay[k] = -gm*dy_a*a_r3 - gm*dy_b*b_r3;
     az[k] = -gm*dz_a*a_r3 - gm*dz_b*b_r3;
    //  ax[k] = -gm*dx_a*a_r3;
    //  ay[k] = -gm*dy_a*a_r3;
    //  az[k] = -gm*dz_a*a_r3;
    // ax[k] = +-gm*dx_b*b_r3  ;
    // ay[k] = -gm*dy_b*b_r3  ;
    // az[k] = -gm*dz_b*b_r3 ;
    //  if (k > 297){
    //    ax[k] = -gm*dx_b*b_r3  ;
    //    ay[k] = -gm*dy_b*b_r3  ;
    //    az[k] = -gm*dz_b*b_r3 ;
    // }
     // ax[k] = 0;
     // ay[k] = 0;
     // az[k] = 0;
     if ((galA_ind == k) || (galB_ind ==k)){

       dx_a = x[k] - x_cm;
       dy_a = y[k] - y_cm;
       dz_a = z[k] - z_cm;

       a_r3 = fabs(powf(((dx_a*dx_a) + (dy_a*dy_a)+ (dz_a*dz_a)),-1.5));
       ax[k] = -gm*dx_a*a_r3;
       ay[k] = -gm*dy_a*a_r3;
       az[k] = -gm*dz_a*a_r3;
       // ax[k] = 0;
       // ay[k] = 0;
       // az[k] = 0;
       // if (k != 0){
       //   ax[k] = -1 * ax[k];
       //   ay[k] = -1 * ay[k];
       //   az[k] = -1 * az[k];
       // }
     // printf("%.3f",ax[k] );
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
    printf("Writing step# %d....\n",nstep);

    fp = fopen(fn, "a");
    for (i = 0; i < n; i++)	/* loop over all points...  */
      fprintf(fp, "%12.6f %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n", tnow, x[i], y[i], z[i], vx[i], vy[i], vz[i]) ;
    fclose(fp);
}


 // struct vector mice_init(void)
 // {
   //Plummer model that returns x,y,z, and u,v,w
   // struct vector cel_obj;
 //
 //   double pi = 22.0/7.0;
 //   //Position Vector
 //
 //
 //   float r = powf((powf(x1,-2.0/3.0) -1.0), -0.5);
 //
 //   float z = (1 - 2*x2)*r;
 //   float x3 = rand_0_1();
 //   cel_obj.pos[1] = powf((powf(r,2.0) - powf(z,2.0)),0.5)*sin(2.0*pi*x3);
 //   cel_obj.pos[0] = powf((powf(r,2.0) - powf(z,2.0)),0.5)*cos(2.0*pi*x3);
 //   cel_obj.pos[2] = z;
 //   cel_obj.pos[3] = r;
 //   // printf("%f %f\n",r, powf((powf(cel_obj.pos[1],2.0) + powf(cel_obj.pos[2],2.0) + powf(cel_obj.pos[0],2.0)),0.5));
 //   // Velocity Vector
 //   float vel_esc = powf(2,0.5)*powf((1+powf(r,2.0)),-0.25);
 //   float x4 = rand_0_1();
 //   float x5 = rand_0_1();
 //   float gq = g(x4);
 //   while((0.1*x5) >= gq){
 //     x4 = rand_0_1();
 //     x5 = rand_0_1();
 //     gq = g(x4);
 //   }
 //   float ve = x4 * vel_esc;
 //   float x6 = rand_0_1();
 //   float x7 = rand_0_1();
 //   float w = ve * (1 - 2*x6);
 //   float u = powf(powf(ve,2.0) - powf(w,2),0.5)*cos(2.0*pi*x7);
 //   float v = powf(powf(ve,2.0) - powf(w,2),0.5)*sin(2.0*pi*x7);
 //   cel_obj.vel[0] = u;
 //   cel_obj.vel[1] = v;
 //   cel_obj.vel[2] = w;
 //
 //   return cel_obj;
 // }

// void energy(float *en)
// {
//   float ke = 0;
//   float pe = 0;
//   float p = 0;
//   float dx, dy, dz, r;
//   int i = 0;
//   int j = 0;
//    for (i = 0; i<MAXPNT; i++) {
//      ke += 0.5 * mass *((vel[i][0]*vel[i][0]) + (vel[i][1]*vel[i][1])+ (vel[i][2]*vel[i][2]));
//      p +=  mass*powf(((vel[i][0]*vel[i][0]) + (vel[i][1]*vel[i][1])+ (vel[i][2]*vel[i][2])),0.5)*powf(((pos[i][0]*pos[i][0]) + (pos[i][1]*pos[i][1])+ (pos[i][2]*pos[i][2])),0.5);
//
//      for(j = 0; j<i; j++){
//        dx = pos[i][0] - pos[j][0];
//        dy = pos[i][1] - pos[j][1];
//        dz = pos[i][2] - pos[j][2];
//        r = powf(((dx*dx) + (dy*dy)+ (dz*dz)),0.5);
//        pe -= mass*mass/r;
//      }
//    }
//
//    // printf("r: %.6f\n",r);
//    en[0] =ke;
//    en[1] =pe;
//    en[2] =ke +pe;
//    en[3] =p;
// }
