/*
 * function: PLEASURE_BOAT_Create
 * address:  0x021C8608
 * packet:   pkt_ov021_021C8608
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GIMMICK_INIT_SetCartLanesFlags  0x021F36C0  thumb  ov037
 *   gPleasureBoatFileName     0x021DE534  data  a4
 *   d_00000024     0x00000024  data  a4
 */
#include "../include/Obj03616.h"

extern char gPleasureBoatFileName;
extern char d_00000024[];

typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(int a);
extern void GIMMICK_INIT_SetCartLanesFlags(char *p);

char *PLEASURE_BOAT_Create(void)
{
    char *p = func_02030734(5, 0x1b8, 1, &gPleasureBoatFileName, 0x31);

    ((struct Obj03616 *)p)->f0 = 0;
    ((struct Obj03616 *)p)->f4 = 0;
    ((struct Obj03616 *)p)->f8 = 0;
    p[0x1b0] = 0;
    p[0x1b1] = 0;
    p[0x1b2] = 0;
    p[0x1b3] = 0;
    ((struct Obj03616 *)p)->f1B4 = 0;
    func_02034AC4((int)d_00000024);
    GIMMICK_INIT_SetCartLanesFlags(p);
    func_02034A5C((int)d_00000024);
    return p;
}
