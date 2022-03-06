#include <stdio.h>

#include <math.h>

#define MAXPNT  100				/* maximum number of points */

//double gm = 5.9300767E-6;  // AU^2 (km/s^2)
double gm = 39.478;  // AU^3 (yr^-2)

char planet[4][10] = {"Venus","Earth", "Mars", "Jupiter"};
void leapstep();				/* routine to take one step */

void accel();					/* accel. for harmonic osc. */

void printstate();				/* print out system state   */

void main(argc, argv)
int argc;
char *argv[];

{
    int n, mstep, nout, nstep;
    double x[MAXPNT], y[MAXPNT], vx[MAXPNT], vy[MAXPNT], tnow, dt;

    /* first, set up initial conditions */

    n = 9;					/* set number of points     */
    tnow = 0.0;
    //Speeds in AU/yr and Positions in AU
    //Mecury
    x[0] = 0.466;					/* set initial x-position     */
    vx[0] = 0.0;					/* set initial x-velocity     */
    y[0] = 0.0;					/* set initial x-position     */
    vy[0] = 8.1975;					/* set initial x-velocity     */
    //Venus
    x[1] = 0.7728;					/* set initial x-position     */
    vx[1] = 0.0;					/* set initial x-velocity     */
    y[1] = 0.0;					/* set initial x-position     */
    vy[1] = 7.33893;					/* set initial x-velocity     */
    // Halley
    // x[0] = 35;					/* set initial x-position     */
    // vx[0] = 0.0;					/* set initial x-velocity     */
    // y[0] = 0.0;					/* set initial x-position     */
    // vy[0] = 1;					/* set initial x-velocity     */
    // //Earth
    x[2] = 1.1;					/* set initial x-position     */
    vx[2] = 0.0;					/* set initial x-velocity     */
    y[2] = 0.0;					/* set initial x-position     */
    vy[2] = 6.17871;					/* set initial x-velocity     */
    // Mars
    x[3] = 1.66;				/* set initial x-position     */
    vx[3] = 0.0;					/* set initial x-velocity     */
    y[3] = 0.0;					/* set initial x-position     */
    vy[3] = 4.63456;						/* set initial x-velocity     */
    //Jupiter
    x[4] = 5.46;					/* set initial x-position     */
    vx[4] = 0.0;					/* set initial x-velocity     */
    y[4] = 0.0;					/* set initial x-position     */
    vy[4] = 2.62421;					/* set initial x-velocity     */
    //Saturn
    x[5] = 10.12;					/* set initial x-position     */
    vx[5] = 0.0;					/* set initial x-velocity     */
    y[5] = 0.0;					/* set initial x-position     */
    vy[5] = 1.91753;					/* set initial x-velocity     */
    //Uranus
    x[6] = 20.1;					/* set initial x-position     */
    vx[6] = 0.0;					/* set initial x-velocity     */
    y[6] = 0.0;					/* set initial x-position     */
    vy[6] = 1.36906;					/* set initial x-velocity     */
    //Neptune
    x[7] = 30.4;					/* set initial x-position     */
    vx[7] = 0.0;					/* set initial x-velocity     */
    y[7] = 0.0;					/* set initial x-position     */
    vy[7] = 1.1328;					/* set initial x-velocity     */
    //Pluto
    x[8] = 49.3;					/* set initial x-position     */
    vx[8] = 0.0;					/* set initial x-velocity     */
    y[8] = 0.0;					/* set initial x-position     */
    vy[8] = 0.782623;					/* set initial x-velocity     */
    /* next, set integration parameters */

    mstep = 10000;				/* number of steps to take  */
    //mstep = 5;				/* number of steps to take  */
    nout = 4;					/* steps between outputs    */
    dt = 1.0/32.0;		/* timestep for integration */

    /* now, loop performing integration */

    for (nstep = 0; nstep < mstep; nstep++) {	/* loop mstep times in all  */
	if (nstep % nout == 0)			/* if time to output state  */
	    printstate(x, y, vx, vy, n, tnow);		/* then call output routine */
	leapstep(x, y, vx, vy, n, dt);			/* take integration step    */
	tnow = tnow + dt;			/* and update value of time */
    }
    if (mstep % nout == 0)			/* if last output wanted    */
	printstate(x, y, vx, vy, n, tnow);		/* then output last step    */
}

/*
 * LEAPSTEP: take one step using the leap-from integrator, formulated
 * as a mapping from t to t + dt.  WARNING: this integrator is not
 * accurate unless the timestep dt is fixed from one call to another.
 */

void leapstep(x, y, vx, vy, n, dt)
double x[];					/* positions of all points  */
double y[];					/* positions of all points  */
double vx[];					/* velocities of all points */
double vy[];					/* velocities of all points */
int n;						/* number of points         */
double dt;					/* timestep for integration */
{
    int i;
    double ax[MAXPNT];
    double ay[MAXPNT]
    ;
    accel(ax, ay, x, y, n);		/* call acceleration code   */
    for (i = 0; i < n; i++)	{		/* loop over all points...  */
	vx[i] = vx[i] + 0.5 * dt * ax[i];		/* advance vel by half-step */
  vy[i] = vy[i] + 0.5 * dt * ay[i];		/* advance vel by half-step */
}
    for (i = 0; i < n; i++){			/* loop over points again...*/
	x[i] = x[i] + dt * vx[i];		/* advance pos by full-step */
  y[i] = y[i] + dt * vy[i];		/* advance pos by full-step */
}
    accel(ax, ay, x, y, n);				/* call acceleration code   */
    for (i = 0; i < n; i++){			/* loop over all points...  */
	vx[i] = vx[i] + 0.5 * dt * ax[i];
  vy[i] = vy[i] + 0.5 * dt * ay[i];		/* and complete vel. step   */
}
}

/*
 * ACCEL: compute accelerations for harmonic oscillator(s).
 */

void accel(ax, ay, x, y, n)
double ax[];					/* accelerations of points  */
double x[];					/* positions of points      */
double ay[];					/* accelerations of points  */
double y[];					/* positions of points      */
int n;						/* number of points         */
{
    int i;

    for (i = 0; i < n; i++){			/* loop over all points...  */
	 ax[i] = (-1*gm)*x[i]/pow((x[i]*x[i])+(y[i]*y[i]),1.5);
   ay[i] = (-1*gm)*y[i]/pow((x[i]*x[i])+(y[i]*y[i]),1.5);

  // printf("%.20f %.20f \n", ax[i],ay[i]);
}
}

/*
 * PRINTSTATE: output system state variables.
 */

void printstate(x, y, vx,vy, n, tnow)
double x[];					/* positions of all points  */
double vx[];					/* velocities of all points */
double y[];					/* positions of all points  */
double vy[];					/* velocities of all points */
int n;						/* number of points         */
double tnow;					/* current value of time    */
{
    int i;
//  printf("t x vx y vy");
    for (i = 0; i < n; i++)	{		/* loop over all points...  */
  // printf("%s \n", planet + i);
printf("%8.4f %4d %8.4f %8.4f %4f%12.6f\n", tnow, i, x[i], y[i], vx[i], vy[i]);
}
}
