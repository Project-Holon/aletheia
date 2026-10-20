#ifndef GAME_ARM9_OS_OWNERINFOEX_H
#define GAME_ARM9_OS_OWNERINFOEX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of os_ownerinfoex.c, prototypes copied from their definitions. */

struct OSOwnerInfoEx;
typedef struct OSOwnerInfoEx OSOwnerInfoEx;

#include "../types.h"

/* Parental control word of the TWL settings: only the two wireless bits are read. */
typedef struct OSParentalControlInfo {
    u32 wirelessOn : 1;
    u32 reserved0 : 4;
    u32 parentalWirelessOn : 1;
    u32 reserved1 : 26;
} OSParentalControlInfo;

char *OSi_GetOwnerInfoExBuffer(void);
void OS_GetOwnerInfoEx(OSOwnerInfoEx *info);
BOOL OS_IsAvailableWireless(void);
BOOL OS_IsAgreeEULA(void);
u8 OS_GetAgreedEULAVersion(void);
u8 OS_GetROMHeaderEULAVersion(void);
const OSParentalControlInfo *OS_GetParentalControlInfoPtr(void);
BOOL OS_IsForceDisableWireless(void);
/* END mkheaders: generated region */

typedef struct OSOwnerInfoEx OSOwnerInfoEx;

#endif
