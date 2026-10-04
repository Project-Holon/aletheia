/*
 * function: func_021BB3F4
 * address:  0x021BB3F4
 * packet:   pkt_ov070_021BB3F4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB368  0x021BB368  thumb  ov070
 *   func_021BB5A4  0x021BB5A4  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_02012BF8  0x02012BF8  thumb
 *   func_020056BC  0x020056BC  thumb
 *   func_0202173C  0x0202173C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3F4  0x0204B3F4  arm
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern int func_021BB368(int);
struct Obj;
struct PalAnmSlot;
extern void func_021BB5A4(char *p);
extern void func_021BB580(char *p, int v);
extern int func_02012BF8(int, int);
extern u32 func_020056BC(void);
extern int func_0202173C(int p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, u32 ctx);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0204B3F4(struct Obj *p);

void func_021BB3F4(int p, int mode)
{
    int r;

    if (((struct Obj00002 *)p)->f858 == mode) {
        return;
    }
    ((struct Obj00002 *)p)->f858 = mode;
    r = func_02012BF8(*(int *)&((struct Obj00002 *)p)->f0, func_021BB368(((struct Obj00002 *)p)->f80C));
    if (mode == 1) {
        func_0202173C(((struct Obj00002 *)p)->f854, 4, 0x23CF, 0, 0, 0, 0, func_020056BC());
        func_0202173C(((struct Obj00002 *)p)->f854, 1, 1, 0, 0, 0, 0, func_020056BC());
        func_0207D658(0x04000050, 6, 0);
        func_021BB5A4((char *)p);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f710), 4);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f714), 5);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f71C), 0);
        if (r == 1) {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 7);
        } else {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 6);
        }
        func_021BB580((char *)p, 1);
    } else {
        func_020216D4((struct PalAnmSlot *)(((struct Obj00002 *)p)->f854), 2, 0, 0x200);
        func_0202173C(((struct Obj00002 *)p)->f854, 4, 0x23CF, 0, 8, 8, 0, func_020056BC());
        func_0202173C(((struct Obj00002 *)p)->f854, 1, 1, 0, 8, 8, 0, func_020056BC());
        if (((struct Obj00002 *)p)->f10 == 4 && func_0204B3F4((struct Obj *)(((struct Obj00002 *)p)->f710)) == 0) {
            func_0207D658(0x04000050, 2, -8);
        } else {
            func_0207D658(0x04000050, 6, -8);
        }
        func_0204B878((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C), 4);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f710), 0x12);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f714), 0x13);
        func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f71C), 0xE);
        if (r == 1) {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 0x16);
        } else {
            func_0204B878((struct Obj *)(((struct Obj00002 *)p)->f718), 0x15);
        }
    }
}
