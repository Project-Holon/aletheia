/*
 * function: func_021F11B4
 * address:  0x021F11B4
 * packet:   pkt_ov029_021F11B4
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The byte at +0x456 must be spelled out at each use (no cached pointer
 * local): a local pointer makes the increment reload the pool constant.
 *
 * symbols:
 *   func_021F0B00  0x021F0B00  thumb  ov029
 *   func_021F0A68  0x021F0A68  thumb  ov029
 *   func_021F0A38  0x021F0A38  thumb  ov029
 *   d_021F348C     0x021F348C  data  a4
 */
#include "../include/Obj00106.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { u8 key, row, col, v; } Ent;

extern const Ent d_021F348C[];
extern void func_021F0B00(void *q, void *p, int a, int b, int c, u16 d);
extern int func_021F0A68(char *p);
extern void func_021F0A38(unsigned char *p);

int func_021F11B4(char *p)
{
    unsigned int i;

    if (((struct Obj00106 *)p)->f456 <= 0x7E) {
        for (i = 0; i < 0x24; i++) {
            if (((struct Obj00106 *)p)->f456 == d_021F348C[i].key)
                func_021F0B00(p + 0x2D0 + d_021F348C[i].row * 0x20 + d_021F348C[i].col * 8,
                              p, 4, 0, 4, d_021F348C[i].v);
        }
        ((struct Obj00106 *)p)->f456 = ((struct Obj00106 *)p)->f456 + 1;
    } else {
        if (func_021F0A68(p) == 0)
            return 1;
    }
    func_021F0A38((unsigned char *)p);
    return 0;
}
