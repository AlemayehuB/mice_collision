#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.141592654
// #define MAXPNT  20000		/* maximum number of points */
//
void rot_mat();
double rot[3][3];
//
// void energy(float *en);
// double rand_0_1(void);
// struct vector plum_sp(void);


int main()
{       int row, item, i, j, mstep, nstep, nout, n;

        float dt, tnow, wa, wb, ia, ib, x_l, y_l, z_l, u_l, v_l, w_l, mass, u_in, x_in, v_in, y_in;
        float x_b, y_b, z_b, u_b, v_b, w_b;

        FILE *f=fopen("micemin.tab", "r");
        FILE *fn = fopen( "min_galAB.dat", "w+");
        wa = -30.0;
        ia = 25.0;
        wb = 60.0;
        ib = 40.0;
        x_in =4.6635;
        y_in = 21.5;
        u_in = 0.01;
        v_in = 0.77;
        // rot_mat(0.0, 0.0, 1.0, 30.0);
        item = fscanf(f, "%d %f \n", &n, &tnow);
        float x[n], y[n], z[n], vx[n], vy[n], vz[n];
        fprintf(fn, "%d %12.6f\n", 2*n, tnow);
        for(row=0; row<n; row++){
            item = fscanf(f, "%f %f %f %f %f %f %f\n", &mass, &x[row], &y[row], &z[row], &vx[row], &vy[row], &vz[row]);
            // Galaxy A
            rot_mat(0.0, 0.0, 1.0, wa);
            // printf("Rotation 1\n");
            // printf("%12.6f  %12.6f  %12.6f\n", rot[0][0], rot[0][1], rot[0][2]);
            // printf("%12.6f  %12.6f  %12.6f\n", rot[1][0], rot[1][1], rot[1][2]);
            // printf("%12.6f  %12.6f  %12.6f\n", rot[2][0], rot[2][1], rot[2][2]);
            x_l = rot[0][0]*x[row] + rot[0][1]*y[row]+ rot[0][2]*z[row];
            y_l = rot[1][0]*x[row] + rot[1][1]*y[row]+ rot[1][2]*z[row];
            z_l = rot[2][0]*x[row] + rot[2][1]*y[row]+ rot[2][2]*z[row];
            u_l = rot[0][0]*vx[row] + rot[0][1]*vy[row]+ rot[0][2]*vz[row];
            v_l = rot[1][0]*vx[row] + rot[1][1]*vy[row]+ rot[1][2]*vz[row];
            w_l = rot[2][0]*vx[row] + rot[2][1]*vy[row]+ rot[2][2]*vz[row];
            // printf("Rotation 2\n");
            rot_mat(1.0, 0.0, 0.0, -ia);
            // printf("%12.6f  %12.6f  %12.6f\n", rot[0][0], rot[0][1], rot[0][2]);
            // printf("%12.6f  %12.6f  %12.6f\n", rot[1][0], rot[1][1], rot[1][2]);
            // printf("%12.6f  %12.6f  %12.6f\n", rot[2][0], rot[2][1], rot[2][2]);
            x_l = rot[0][0]*x_l + rot[0][1]*y_l+ rot[0][2]*z_l + x_in;
            y_l = rot[1][0]*x_l + rot[1][1]*y_l+ rot[1][2]*z_l - y_in;
            z_l = rot[2][0]*x_l + rot[2][1]*y_l+ rot[2][2]*z_l;
            u_l = rot[0][0]*u_l + rot[0][1]*v_l+ rot[0][2]*w_l - u_in;
            v_l = rot[1][0]*u_l + rot[1][1]*v_l+ rot[1][2]*w_l + v_in;
            w_l = rot[2][0]*u_l + rot[2][1]*v_l+ rot[2][2]*w_l;
           fprintf(fn, "%.12f %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n", mass, x_l, y_l, z_l, u_l, v_l, w_l);
        }
        for(row = 0; row<n; row++){
          // Galaxy B
          rot_mat(0.0, 0.0, 1.0, wb);
          x_b = rot[0][0]*x[row] + rot[0][1]*y[row]+ rot[0][2]*z[row];
          y_b = rot[1][0]*x[row] + rot[1][1]*y[row]+ rot[1][2]*z[row];
          z_b = rot[2][0]*x[row] + rot[2][1]*y[row]+ rot[2][2]*z[row];
          u_b = rot[0][0]*vx[row] + rot[0][1]*vy[row]+ rot[0][2]*vz[row];
          v_b = rot[1][0]*vx[row] + rot[1][1]*vy[row]+ rot[1][2]*vz[row];
          w_b = rot[2][0]*vx[row] + rot[2][1]*vy[row]+ rot[2][2]*vz[row];
          // printf("Rotation 2\n");
          rot_mat(1.0, 0.0, 0.0, -ib);
          // printf("%12.6f  %12.6f  %12.6f\n", rot[0][0], rot[0][1], rot[0][2]);
          // printf("%12.6f  %12.6f  %12.6f\n", rot[1][0], rot[1][1], rot[1][2]);
          // printf("%12.6f  %12.6f  %12.6f\n", rot[2][0], rot[2][1], rot[2][2]);
          x_b = rot[0][0]*x_b + rot[0][1]*y_b+ rot[0][2]*z_b - x_in;
          y_b = rot[1][0]*x_b + rot[1][1]*y_b+ rot[1][2]*z_b + y_in;
          z_b = rot[2][0]*x_b + rot[2][1]*y_b+ rot[2][2]*z_b;
          u_b = rot[0][0]*u_b + rot[0][1]*v_b+ rot[0][2]*w_b + u_in;
          v_b = rot[1][0]*u_b + rot[1][1]*v_b+ rot[1][2]*w_b - v_in;
          w_b = rot[2][0]*u_b + rot[2][1]*v_b+ rot[2][2]*w_b;
         fprintf(fn, "%.12f %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n", mass, x_b, y_b, z_b, u_b, v_b, w_b);
        }

        fclose(f);
        fclose(fn);
        return 0;
}



void rot_mat(n1, n2, n3, ang)
float n1, n2, n3, ang;
{
  float a, s, c, rad;
  rad = ang*(M_PI/180.0);
  // printf("Radians: %12f\n",rad);
  c = cos(rad);
  s = sin(rad);
  a = 1.0 - cos(rad);
  rot[0][0] = a*n1*n1 + c;
  rot[0][1] = a*n1*n2 - s*n3;
  rot[0][2] = a*n1*n3 + s*n2;
  rot[1][0] = a*n1*n2 + s*n3;
  rot[1][1] = a*n2*n2 + c;
  rot[1][2] = a*n2*n3 - s*n1;
  rot[2][0] = a*n1*n3 - s*n2;
  rot[2][1] = a*n2*n3 + s*n1;
  rot[2][2] = a*n3*n3 + c;

}
