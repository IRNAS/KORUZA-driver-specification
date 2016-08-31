#include<stdio.h>
#include <stdlib.h>
#include <math.h>


//constants - same for each Koruza unit
#define STEPS_PER_ROTATION 4096
#define ROTATION_DISTANCE 0.8
#define LEAVER 115.8
#define MOTOR_RANGE 50000

void main()
{
	double angle_per_step = atan(ROTATION_DISTANCE / (STEPS_PER_ROTATION * LEAVER)); //Radians per motor step - constant
	
	double distance; //Distance between two units - user input
	double rotation_angle; //Inclination of the unit - user input

	printf("Enter distance between units in mm: ");
	scanf("%lf", &distance);
	printf("\nEnter inclination of the unit in radians: ");
	scanf("%lf", &rotation_angle);

	printf("\nDistance: %.2f mm, Rotation Angle: %.2f Rad", distance, rotation_angle);

	double X_range[2]; //Half of the range of movement as seen on the image
	X_range[0] = 0.5 * distance * sin(angle_per_step * MOTOR_RANGE); //x-range
	X_range[1] = 0.5 * distance * sin(angle_per_step * MOTOR_RANGE); //y-range

	printf("\nX range: %.2f mm, Y range: %.2f mm\n", X_range[0], X_range[1]);

	double X[2]; //Real coordinate system in [mm], as seen by user on the camera. 
	int motor[2]; //Motor coordinate system in [steps]

	printf("\nEnter desired x-coordinate in mm: ");
	scanf("%lf", &X[0]);
	printf("\nEnter desired y-coordinate in mm: ");
	scanf("%lf", &X[1]);

	printf("\nMove to X: %.2f Y: %.2f\n", X[0], X[1]);

	//Calculate motor position
	motor[0] = (int) ((1.0 / angle_per_step) * asin((X[0] * cos(rotation_angle) + X[1] * sin(rotation_angle) + X_range[0]) / distance));
	motor[1] = (int)((1.0 / angle_per_step) * asin((-X[0] * sin(rotation_angle) + X[1] * cos(rotation_angle) + X_range[1]) / distance));

	printf("\nMove motors to steps: %d, %d.", motor[0], motor[1]);

	//Calculate back position on real coordinate system
	X[0] = cos(rotation_angle) * (distance * sin(angle_per_step * (double) motor[0]) - X_range[0]) - sin(rotation_angle) * (distance * sin(angle_per_step * (double) motor[1]) - X_range[1]);
	X[1] = sin(rotation_angle) * (distance * sin(angle_per_step * (double) motor[0]) - X_range[0]) + cos(rotation_angle) * (distance * sin(angle_per_step * (double) motor[1]) - X_range[1]);

	printf("\nCheck reverse move to X: %.2f Y: %.2f\n", X[0], X[1]);

	getchar();
}
