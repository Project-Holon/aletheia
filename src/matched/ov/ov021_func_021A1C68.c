/*
 * function: func_021A1C68
 * address:  0x021A1C68
 * packet:   pkt_ov021_021A1C68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D886C     0x021D886C  data  ov021  a4
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_021A2050  0x021A2050  thumb  ov021
 *   func_021A21B0  0x021A21B0  thumb  ov021
 *   func_021A1C04  0x021A1C04  thumb  ov021
 *   func_021A1BF8  0x021A1BF8  thumb  ov021
 *   func_021A1FEC  0x021A1FEC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00755.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u32 d_021D886C[];
extern const u32 d_021D8868[];
struct O;
extern void func_021A2050(struct O *p, u32 a, u32 b);
extern int func_021A21B0(u32 obj);
extern void func_021A1C04(u8 *p);
extern void func_021A1BF8(void *p, u32 v);
extern void func_021A1FEC(struct O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);

void func_021A1C68(u8 *p, int x)
{
    switch (((struct Obj00755 *)p)->fA) {
    case 0:
        break;
    case 1:
        func_021A2050((struct O *)(((struct Obj00755 *)p)->f20), 1, 1);
        ((struct Obj00755 *)p)->fA = 2;
        break;
    case 2:
        if (func_021A21B0(((struct Obj00755 *)p)->f20) == 0) {
            func_021A1C04(p);
            ((struct Obj00755 *)p)->fA = 3;
        }
        break;
    case 3:
        func_021A1BF8(p, d_021D886C[((struct Obj00755 *)p)->fE * 2]);
        ((struct Obj00755 *)p)->fA = 4;
        break;
    case 4:
        func_021A1FEC((struct O *)(((struct Obj00755 *)p)->f20), d_021D8868[((struct Obj00755 *)p)->fE * 2], 1, 1, 1,
                      ((struct Obj00755 *)p)->f10, x);
        ((struct Obj00755 *)p)->f10 = 1;
        ((struct Obj00755 *)p)->fC = ((struct Obj00755 *)p)->fE;
        ((struct Obj00755 *)p)->fE = 0xFFFF;
        ((struct Obj00755 *)p)->fA = 0;
        break;
    }
}
