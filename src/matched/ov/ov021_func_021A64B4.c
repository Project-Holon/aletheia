/*
 * function: FIELD_PLAYER_NOGRID_CheckActionRail
 * address:  0x021A64B4
 * packet:   pkt_ov021_021A64B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckRailFromStand  0x021A652C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckRailStep  0x021A658C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckRailFromTurn  0x021A661C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckRailFromBlocked  0x021A666C  thumb  ov021
 */
#include "../include/Obj04234.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern int FIELD_PLAYER_NOGRID_CheckRailFromStand(void *a, void *x, int c, int d, int e, int f);
extern int FIELD_PLAYER_NOGRID_CheckRailStep(void *a, void *x, int c, int d, int e, int f);
extern int FIELD_PLAYER_NOGRID_CheckRailFromTurn(void *a, void *x, int c, int d, int e, int f);
extern u32 FIELD_PLAYER_NOGRID_CheckRailFromBlocked(void *a, void *b, u32 c, u32 d, u32 e, u32 f);

int FIELD_PLAYER_NOGRID_CheckActionRail(int *a, int b, int c, int d, int e)
{
    void *x = FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj04234 *)a)->f14);
    int r = 0;
    switch (a[0]) {
    case 0: r = FIELD_PLAYER_NOGRID_CheckRailFromStand(a, x, b, c, d, e); break;
    case 1: r = FIELD_PLAYER_NOGRID_CheckRailStep(a, x, b, c, d, e); break;
    case 2: r = FIELD_PLAYER_NOGRID_CheckRailFromTurn(a, x, b, c, d, e); break;
    case 3: r = FIELD_PLAYER_NOGRID_CheckRailFromBlocked(a, x, b, c, d, e); break;
    }
    return r;
}
