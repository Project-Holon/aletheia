/*
 * function: func_021C5224
 * address:  0x021C5224
 * packet:   pkt_ov021_021C5224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5334 0x021C5334 thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021C59BC 0x021C59BC thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_021C553C 0x021C553C thumb ov021
 *   func_021C5768 0x021C5768 thumb ov021
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj01216.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021C5334(u32 a);
extern void func_020061E4(u32 se);
extern void *func_020056A0(void *callback, void *ctx, int a2);
typedef unsigned char  u8;
struct Node;
extern void func_021C59BC(void *a, u8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_021C553C(char *p);
extern int func_021C5768(char *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02040618(u32 layer, u32 a, u32 b);

void func_021C5224(char *p)
{
    int r;
    int i;

    if (func_021C5334((u32)p) == 0) {
        return;
    }
    switch (((struct Obj01216 *)p)->f70) {
    case 0:
        break;
    case 1:
        func_020061E4(0x54C);
        ((struct Obj01216 *)p)->f72 = 0;
        ((struct Obj01216 *)p)->f80 = 0;
        ((struct Obj01216 *)p)->f84 = func_020056A0((void *)func_021C59BC, p, 0);
        ((struct Obj01216 *)p)->f70 = 2;
        break;
    case 2:
        if (((struct Obj01216 *)p)->f80 != 0) {
            func_02030EAC(((struct Obj01216 *)p)->f84);
            ((struct Obj01216 *)p)->f70 = 3;
        }
        break;
    case 3:
        func_021C553C(p);
        r = func_021C5768(p);
        switch (r) {
        case -1:
            ((struct Obj01216 *)p)->f74 = 0;
            break;
        case -2:
            ((struct Obj01216 *)p)->f74 = 2;
            break;
        default:
            ((struct Obj01216 *)p)->f74 = 1;
            ((struct Obj01216 *)p)->f78 = r;
            break;
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0x58 + i * 4), 0);
        }
        ((struct Obj01216 *)p)->f72 = 4;
        ((struct Obj01216 *)p)->f70 = 5;
        break;
    case 5:
        func_02040618(1, 3, ((struct Obj01216 *)p)->f72 * 0xC0 / 4 - 0xC0);
        if ((((struct Obj01216 *)p)->f72)-- == 0) {
            ((struct Obj01216 *)p)->f70 = 0;
        }
        break;
    }
}
