/*
 * function: ISS_SYS_Update
 * address:  0x0202B500
 * packet:   pkt_0202B500
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * cap: label -- two call targets have no witness outside this range:
 *   0x0202B84C (ISS_SYS_SwitchMode) and 0x0202B710 (ISS_SYS_Update3ds).
 *   Both are still-open band_0_64 addresses; each is called exactly once
 *   image-wide and that call site is inside this function, so the `label`
 *   class refuses (every witness is in-range). No C change can fix this:
 *   the moment either callee has its own manifest entry the site attests
 *   and this file turns EXACT untouched.
 *   All 68 bytes concrete-identical; 7 of 9 relocation sites resolved.
 *
 * symbols:
 *   ISS_SYS_UpdateRoad  0x0202B6CC  thumb
 *   ISS_SYS_UpdateCity  0x0202B6DC  thumb
 *   ISS_SYS_UpdateDungeon  0x0202B6EC  thumb
 *   ISS_SYS_UpdateZone  0x0202B6F8  thumb
 *   ISS_SYS_UpdateSwitch  0x0202B704  thumb
 *   ISS_SYS_Update3ds  0x0202B710  thumb
 *   ISS_SYS_GetCurrentBgmId  0x0202B810  thumb
 *   ISS_SYS_HasBgmChanged  0x0202B834  thumb
 *   ISS_SYS_SwitchMode  0x0202B84C  thumb
 */
#include "../include/Obj02010.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern u32 ISS_SYS_HasBgmChanged(struct Obj *o);
extern void ISS_SYS_SwitchMode(void *a);
extern u32 ISS_SYS_GetCurrentBgmId(void);
extern void ISS_SYS_UpdateRoad(u8 *p);
extern void ISS_SYS_UpdateCity(u8 *p);
extern void ISS_SYS_UpdateDungeon(u8 *p);
extern void ISS_SYS_UpdateZone(u8 *p);
extern void ISS_SYS_UpdateSwitch(u8 *p);
extern void ISS_SYS_Update3ds(u8 *p);

void ISS_SYS_Update(u8 *p)
{
    if (ISS_SYS_HasBgmChanged((struct Obj *)p) == 1) {
        ISS_SYS_SwitchMode(p);
        ((struct Obj02010 *)p)->f8 = ISS_SYS_GetCurrentBgmId();
    }
    ISS_SYS_UpdateRoad(p);
    ISS_SYS_UpdateCity(p);
    ISS_SYS_UpdateDungeon(p);
    ISS_SYS_UpdateZone(p);
    ISS_SYS_UpdateSwitch(p);
    ISS_SYS_Update3ds(p);
    ((struct Obj02010 *)p)->fC = ((struct Obj02010 *)p)->fC + 1;
}
