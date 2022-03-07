#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// #define MAXPNT  20000		/* maximum number of points */
//
// float pos[MAXPNT][3];
// float vel[MAXPNT][3];
//
// void energy(float *en);
// double rand_0_1(void);
// struct vector plum_sp(void);


void leapstep();				/* routine to take one step */

void accel();					/* accel. for harmonic osc. */
void parseLine();
void printstate();

int readresults(FILE *results);

int main()
{       int row, item, i;
        FILE *f=fopen("./midterm_p/init.out", "r");
        double x[596], y[596], z[596], vx[596], vy[596], vz[596];
        for(row=0; row<596; row++)
        {
                item = fscanf(f, "%lf %lf %lf %lf %lf %lf\n", &x[row], &y[row], &z[row], &vx[row], &vy[row], &vz[row]);
                //printf("%f %f\n", x[row],y[row]);

        }

        mstep = 10;				/* number of steps to take  */
        nout = 2;					/* steps between outputs    */
        dt = 1.0/2.0;		/* timestep for integration */
        tnow = 0.0;
        fprintf(fil, "Kinetic E. Potential E. Total E. Ang. Mom.\n" );

        for (nstep = 0; nstep < mstep; nstep++) {	/* loop mstep times in all  */
           if (nstep % nout == 0)			/* if time to output state  */
             printstate(MAXPNT, tnow, fn, nstep);		/* then call output routine */
           energy(en);
           // printf( "%.10f %.10f %.10f %.10f %.10f\n", tnow, en[0],en[1],en[2],en[3]);
           fprintf(fil, "%.10f %.10f %.10f %.10f %.10f\n", tnow, en[0],en[1],en[2],en[3]);
     //
        // for(i=0; i<50; i++)
        // {
        //    printf("%f %f %f %f %f %f\n", x[i],y[i],z[i], vx[i],vy[i], vz[i]);
        // }
        fclose(f);
        return 0;
}

// }
//  void main(argc, argv)
//    int argc;
//    char *argv[];
//  {
//
//    char *fn = argv[1];
//    float en[4];
//    FILE *fil = fopen(efn, "w+");
//    double pi = 22.0/7.0;
//    struct vector plum_sp();
//    int i, j, n, mstep, nout, nstep;
//    double tnow, dt;
//    printf("Creating Plummer Sphere with %d Bodies\n", MAXPNT);
//    for (i = 0; i<MAXPNT; i++) {
//      if ((i % 1000)==0)
//       printf("Creating %d particle \n",i);
//      for(j=0;j<3;j++){
//        struct vector  plum_v = plum_sp();
//        pos[i][j] = plum_v.pos[j];
//        vel[i][j] = plum_v.vel[j];
//        // vel[i][j] = 0; //Collapsing Sphere
//     }
//    }
//    printf("Done making sphere\n");
   // mstep = 10;				/* number of steps to take  */
//    nout = 2;					/* steps between outputs    */
//    dt = 1.0/2.0;		/* timestep for integration */
//    tnow = 0.0;
//    fprintf(fil, "Kinetic E. Potential E. Total E. Ang. Mom.\n" );
//
//    for (nstep = 0; nstep < mstep; nstep++) {	/* loop mstep times in all  */
//       if (nstep % nout == 0)			/* if time to output state  */
//         printstate(MAXPNT, tnow, fn, nstep);		/* then call output routine */
//       energy(en);
//       // printf( "%.10f %.10f %.10f %.10f %.10f\n", tnow, en[0],en[1],en[2],en[3]);
//       fprintf(fil, "%.10f %.10f %.10f %.10f %.10f\n", tnow, en[0],en[1],en[2],en[3]);
// //
//       leapstep(MAXPNT, dt);			/* take integration step    */
//       tnow = tnow + dt;			/* and update value of time */
//
//
//     // if (mstep % nout == 0){			/* if last output wanted    */
//     //   printstate(MAXPNT, tnow, fn,nstep);		/* then output last step    */
//     //   energy(en);
//     //   fprintf(fil, "%.10f %.10f %.10f %.10f %.10f\n", tnow, en[0],en[1],en[2],en[3]);
//     // }
//   }
//     printstate(MAXPNT, tnow, fn,nstep);		/* then output last step    */
//     energy(en);
//     fprintf(fil, "%.10f %.10f %.10f %.10f %.10f\n", tnow, en[0],en[1],en[2],en[3]);
//
// }
//  double rand_0_1(void){
//      return rand() / ((double) RAND_MAX);
//  }
//
//  void accel(ax, ay, az, n)
//  double ax[], ay[], az[];
//  int n;
//  {
//   double dx, dy, dz, inv_r3, gm;
//   int i, j, k;
//   gm = 1.0;
//
//   for(k = 0; k < n; k++){
//     ax[k] = 0.0;
//     ay[k] = 0.0;
//     az[k] = 0.0;
//     for(j = 0; j < n; j++){
//       if (j != k){
//          dx = pos[j][0] - pos[k][0];
//          dy = pos[j][1] - pos[k][1];
//          dz = pos[j][2] - pos[k][2];
//          inv_r3 = powf(((dx*dx) + (dy*dy)+ (dz*dz)),-1.5);
//          ax[k] = ax[j] + (mass)*dx*inv_r3 ;
//          ay[k] = ay[j] + (mass)*dy*inv_r3;
//          az[k] = az[j] +  (mass)*dz*inv_r3;
//      }
//     }
//   }
//  }
//
//  void leapstep(n, dt)
//  int n;						/* number of points         */
//  double dt;					/* timestep for integration */
//  {
//      int i;
//      double ax[MAXPNT];
//      double ay[MAXPNT];
//      double az[MAXPNT];
//
//      accel(ax, ay, az, n);		/* call acceleration code   */
//      for (i = 0; i < n; i++)	{		/* loop over all points...  */
//  	     vel[i][0] = vel[i][0] + 0.5 * dt * ax[i];		/* advance vel by half-step */
//        vel[i][1] = vel[i][1] + 0.5 * dt * ay[i];		/* advance vel by half-step */
//        vel[i][2] = vel[i][2] + 0.5 * dt * az[i];
//  }
//      for (i = 0; i < n; i++){			/* loop over points again...*/
//        pos[i][0] = pos[i][0] + dt * vel[i][0];		/* advance vel by half-step */
//        pos[i][1] = pos[i][1] + dt * vel[i][1];		/* advance vel by half-step */
//        pos[i][2] = pos[i][2] + dt * vel[i][2];		/* advance pos by full-step */
//  }
//      accel(ax, ay, az, n);			/* call acceleration code   */
//      for (i = 0; i < n; i++){			/* loop over all points...  */
//        vel[i][0] = vel[i][0] + 0.5 * dt * ax[i];		/* advance vel by half-step */
//        vel[i][1] = vel[i][1] + 0.5 * dt * ay[i];		/* advance vel by half-step */
//        vel[i][2] = vel[i][2] + 0.5 * dt * az[i];
//
//  }
// }
//
// void printstate(n, tnow, fn, nstep)
// int n;
// char *fn;						/* number of points         */
// double tnow;
// int nstep;					/* current value of time    */
// {
//     int i;
//     FILE *fp;
//     char *fn_1;
//     char s1[15];
//     // Convert both the integers to string
//     sprintf(s1, "%s_%d",fn,nstep);
//
//     printf("Writing to %s....\n",s1);
//
//     fp = fopen(s1, "w+");
//     for (i = 0; i < n; i++)	/* loop over all points...  */
//       fprintf(fp, "%12.6f %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n", mass, pos[i][0], pos[i][1], pos[i][2], vel[i][0], vel[i][1], vel[i][2]) ;
//     fclose(fp);
//
//     memset(s1, 0, sizeof s1);
//
// }
//

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
