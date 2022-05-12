#include <stdio.h>
#include "Speed.hpp"
#include <math.h>

Speed::Speed()
           : guiVehichleSpeed (SPEED_BAD_VALUE),
             guiVehichleStatus ((unsigned int)eStatus__IGNITION_OFF),
             giSpeedUnit (eUnits__KMH),
             gbSpeedFail (false),
             gfUnitFactor (1.0)
           {

}

//Vehichle Speed
void Speed::vSetVehichleSpeed (unsigned int in_iVehichleSpeed) {
    guiVehichleSpeed = in_iVehichleSpeed;
}

unsigned int Speed::iGetVehichleSpeed (void) {
    return guiVehichleSpeed;
}

//Vehichle Status
void Speed::vSetVehichleStatus (unsigned int in_iVehichleStatus) {
    guiVehichleStatus = in_iVehichleStatus;
}

unsigned int Speed::iGetVehichleStatus (void) {
    return guiVehichleStatus;
}

//Speed Unit
void Speed::vSetSpeedUnit (unsigned int in_iSpeedUnit) {
    if (in_iSpeedUnit < eUnits__MAX) {
        giSpeedUnit = (eUnits) in_iSpeedUnit;
		if (giSpeedUnit == eUnits__MPH) {
			gfUnitFactor = CONVERT_MILES;
		} else {
			gfUnitFactor = 1.0;
		}
    } else {
        giSpeedUnit = eUnits__MAX;
	}
}

unsigned int Speed::iGetSpeedUnit (void) {
    return (int) giSpeedUnit;
}

//Speed Fail
void Speed::vSetSpeedFail (bool in_bSpeedFail) {
    gbSpeedFail = in_bSpeedFail;
}

bool Speed::iGetSpeedFail (void) {
    return gbSpeedFail;
}

unsigned int Speed::iGetGUISpeed (void) {
    unsigned int iCurrSpeed = SPEED_BAD_VALUE;
    float fCurrSpeed = 0.0;
	
    if (false == gbSpeedFail && MAX_SPEED >= guiVehichleSpeed) {
        if ((eStatus__IGNITION_ON_ENGINE_ON == (eStatus)guiVehichleStatus) && \
		    (PARK_SPEED < guiVehichleSpeed)) {

			fCurrSpeed = (float)guiVehichleSpeed * SPEED_TOLERANCE;
			iCurrSpeed = (unsigned int) roundf(fCurrSpeed);

			if (MAX_SPEED >= iCurrSpeed) {
				iCurrSpeed = (unsigned int) roundf(fCurrSpeed / gfUnitFactor);
			} else {
				iCurrSpeed = SPEED_BAD_VALUE;
			}
        } else {
			iCurrSpeed = 0;
		}
    } else {
        iCurrSpeed = SPEED_BAD_VALUE;
    }

    return iCurrSpeed;
}
