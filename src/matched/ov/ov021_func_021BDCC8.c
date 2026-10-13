/*
 * function: ENTRANCE_CAMERA_Setup
 * address:  0x021BDCC8
 * packet:   pkt_ov021_021BDCC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENTRANCE_CAMERA_Setup  0x021BDCC8  thumb
 *   ENTRANCE_CAMERA_SetRequest  0x021BE184  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetData  0x0218FEA0  thumb  ov021
 *   ENTRANCE_CAMERA_HasRecord  0x021BE1A0  thumb  ov021
 *   ENTRANCE_CAMERA_SetupLeaveByRecord  0x021BDFB0  thumb  ov021
 *   ENTRANCE_CAMERA_SetupArriveByRecord  0x021BE068  thumb  ov021
 *   ENTRANCE_CAMERA_SetupLeaveByDir  0x021BDDC0  thumb  ov021
 *   ENTRANCE_CAMERA_SetupArriveByDir  0x021BDEB4  thumb  ov021
 */
#include "../include/Obj00282.h"

extern void ENTRANCE_CAMERA_SetRequest(void *a, void *b);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void FIELD_CAMERA_ANIME_SetData(u8 *p, u32 v);
extern int ENTRANCE_CAMERA_HasRecord(u32 a);
extern void ENTRANCE_CAMERA_SetupLeaveByRecord(char *a);
extern void ENTRANCE_CAMERA_SetupArriveByRecord(void *a);
extern void ENTRANCE_CAMERA_SetupLeaveByDir(void *a);
extern void ENTRANCE_CAMERA_SetupArriveByDir(void *a);

void ENTRANCE_CAMERA_Setup(char *a, int *b)
{
    ENTRANCE_CAMERA_SetRequest(a, b);
    FIELD_CAMERA_ANIME_SetData(((struct Obj00282 *)a)->f54, (u32)(a + 8));
    if (ENTRANCE_CAMERA_HasRecord((u32)a) != 0) {
        switch (b[1]) {
        case 0:
            ENTRANCE_CAMERA_SetupLeaveByRecord(a);
            break;
        case 1:
            ENTRANCE_CAMERA_SetupArriveByRecord(a);
            break;
        }
    } else {
        switch (b[1]) {
        case 0:
            ENTRANCE_CAMERA_SetupLeaveByDir(a);
            break;
        case 1:
            ENTRANCE_CAMERA_SetupArriveByDir(a);
            break;
        }
    }
    ((struct Obj00282 *)a)->f64 = 1;
}
