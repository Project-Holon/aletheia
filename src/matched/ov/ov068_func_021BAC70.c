/*
 * function: func_021BAC70
 * address:  0x021BAC70
 * packet:   pkt_ov068_021BAC70
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021BB704     0x021BB704  data  ov068  a4
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB508  0x021BB508  thumb  ov068
 *   func_021BAFD8  0x021BAFD8  thumb  ov068
 *   func_021BACF4  0x021BACF4  thumb  ov068
 */
#include "../include/Obj13141.h"

typedef unsigned char u8;
typedef signed char   s8;
typedef signed short  s16;
typedef unsigned int  u32;

typedef struct {
    u8  pad[0x10];
    s16 f10;
    s16 f12;
    s16 f14;
    s16 f16;
} Ent;

extern Ent d_021BB704[];
extern void func_020061E4(u32 id);
extern int  func_021BB508(int *rect, void *b);
extern void func_021BAFD8(u8 *p, int i);
extern void func_021BACF4(u8 *p, u32 a, u32 b);

void func_021BAC70(u8 *p, void *b)
{
    int i;
    int r[4];
    int x;
    int y;

    for (i = 0; i < 11; i++) {
        Ent *e = &d_021BB704[i];

        y = ((struct Obj13141 *)p)->f34 + e->f12;
        x = e->f10;
        r[1] = y;
        r[0] = x;
        r[3] = y + e->f16;
        r[2] = x + e->f14;
        if (y >= 0x18 && y <= 0xa8 && r[3] >= 0x18 && r[3] <= 0xa8) {
            if (func_021BB508(r, b)) {
                func_020061E4(0x548);
                func_021BAFD8(p + 0x44, i);
                func_021BACF4(p, ((struct Obj13141 *)p)->f47, 0);
                return;
            }
        }
    }
}
