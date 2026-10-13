/*
 * function: ISS_SYS_Setup
 * address:  0x0202B59C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Parked: five of the six initialisers resolve as `matched` (0x0202B5FC,
 * 0x0202B610, 0x0202B624, 0x0202B63C, 0x0202B65C).  The one that does not is
 * 0x0202B64C at +002A, which is itself capped on 0x0202C070, which is capped
 * on 0x0202C148 (DIFF).  Every concrete byte reproduces; the C is final.
 *
 * Constructor hub: fills the four word/halfword members of a node and runs
 * its six initialisers in order.
 *
 * symbols:
 *   ISS_SYS_CreateRoad  0x0202B5FC  thumb
 *   ISS_SYS_CreateCity  0x0202B610  thumb
 *   ISS_SYS_CreateDungeon  0x0202B624  thumb
 *   ISS_SYS_CreateZone  0x0202B63C  thumb
 *   ISS_SYS_CreateSwitch  0x0202B64C  thumb
 *   ISS_SYS_Create3ds  0x0202B65C  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern void ISS_SYS_CreateRoad(struct Obj *o);
extern void ISS_SYS_CreateCity(struct Obj *o);
extern void ISS_SYS_CreateDungeon(struct Obj *o);
extern void ISS_SYS_CreateZone(struct Obj *o);
extern void ISS_SYS_CreateSwitch(struct Obj *o);
extern void ISS_SYS_Create3ds(struct Obj *o);

struct SaveBlock;

void ISS_SYS_Setup(u8 *p, struct SaveBlock *a, u32 b)
{
    ((struct Obj00563 *)p)->f4  = (u32)a;
    ((struct Obj00563 *)p)->f8  = 0xffffffff;
    ((struct Obj00563 *)p)->f0  = (u16)b;
    ((struct Obj00563 *)p)->fC = 0;

    ISS_SYS_CreateRoad((struct Obj *)p);
    ISS_SYS_CreateCity((struct Obj *)p);
    ISS_SYS_CreateDungeon((struct Obj *)p);
    ISS_SYS_CreateZone((struct Obj *)p);
    ISS_SYS_CreateSwitch((struct Obj *)p);
    ISS_SYS_Create3ds((struct Obj *)p);
}
