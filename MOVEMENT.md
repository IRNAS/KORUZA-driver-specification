# Movement of KORUZA 2.0 unit
This document describes correlation between motors, webcam and movement of the optical beam in space, enabling precise control of the optical beam.

## Relevant mechanical concepts of KORUZA 2.0
KORUZA operates by aiming a collimated optical beam the opposite unit by controlling two motors that via a sliding joint produce angluar displacement of the optical axis and thus aiming the beam.

## Motor behaviour
Stepper motor on each axis may travel over a defined range, hard limited in the negative direction. Due to the limited power of the stepper motors, homing procedure may be done only with an encoder which observes when the movement stops in negative direction. This procedure is called Homing and is performed typically onle during production. When homing is complete, motors must move to the mid-point between 0 and max position. This now becomes the center position, in user coordinate system denoted as 0 (in motor coordiante position this has value depending on max position)

![motor schematic][motor-image.png]

## Webcam behaviour
Webcam is used with magnifying optics to provide an optical alignemnt mechanism for the user, such that the webcam must be directed towards the opposite unit. Because of mechanical error durign manufacturing, a calibration procedure is performed, such that a marker is placed on the image and the marker is then aligned with the opposite unit to establish the optical link.

## Unit orientation
KORUZA unit may not be mounted in its default orientation and may be turned sideways or upside-down. We denote the angular displacement from the normal orientation y axis perpendicular to horizon, x axis aligned with the horizon, with the angle alpha. User interface must take this angle into account and rotate the webcam image and transform the user control coordiante system to the normal orientation.

## User interface coordinate system
User interface uses a coordiante system which enables most intuitive control to the user, controlling the movement in linear manner with respect to the link distance. If the link is 100m long and user clicks on the image 10mm from the marker position, it moves to that location. Same this shoudl happen regardless of what distance of the link is, provided correct link distance is configured.

## User interface features
User interface for positioning should consist of the following features:
 1. webcam image (stationary)
 1. marker overlay (stationary, calibrated value)
 1. unit outline (stationary, must scale with distance)
 1. X and Y axis with 0 position (moving as motors move, shows the center of the movement range)
 1. Maximal movement range shown as a bounding box overlay (moves as motors move, depends on motor max position) Note, may be outside the actual image.
 1. Scale denoted on the shown XY axis (depends on distance)
 
 ![ui schematic][ui-image.png]
