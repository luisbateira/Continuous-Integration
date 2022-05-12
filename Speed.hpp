#ifndef SPEED_H
#define SPEED_H

#include "stdbool.h"

#define CONVERT_MILES         (float) 1.609
#define SPEED_BAD_VALUE       0xFFFFFFFF
#define MIN_SPEED             0
#define PARK_SPEED            5
#define MAX_SPEED             300
#define SPEED_TOLERANCE       (float) 1.1

typedef enum {
    eStatus__RESERVED_0,
    eStatus__IGNITION_OFF,
    eStatus__IGNITION_ON,
    eStatus__IGNITION_CRANKING,
    eStatus__IGNITION_ON_ENGINE_ON,
    eStatus__RESERVED_1,
    eStatus__RESERVED_2,
    eStatus__RESERVED_3,
    eStatus__MAX,
}eStatus;

typedef enum {
    eUnits__KMH,
    eUnits__MPH,
    eUnits__MAX
}eUnits;

class Speed {
public:

    Speed ();

    //Vehichle Speed
    void vSetVehichleSpeed (unsigned int in_iVehichleSpeed);
    unsigned int iGetVehichleSpeed (void);

    //Vehichle Status
    void vSetVehichleStatus (unsigned int in_iVehichleStatus);
    unsigned int iGetVehichleStatus (void);

    //Speed Unit
    void vSetSpeedUnit (unsigned int in_iSpeedUnit);
    unsigned int iGetSpeedUnit (void);

    //Speed Fail
    void vSetSpeedFail (bool in_bSpeedFail);
    bool iGetSpeedFail (void);

    // Final Speed for GUI
    unsigned int iGetGUISpeed (void);
	
private:

    unsigned int guiVehichleSpeed;
    unsigned int guiVehichleStatus;
    eUnits giSpeedUnit;
    bool gbSpeedFail;
    float gfUnitFactor;
};

#endif  //SPEED_H
