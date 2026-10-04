/*
 * function: func_021C446C
 * address:  0x021C446C
 * packet:   pkt_ov136_021C446C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * note:     2026-10-02 only unresolved witness func_02024450 (file exists in src/matched/arm9, no shard yet)
 *
 * symbols:
 *   func_021C446C 0x021C446C thumb
 *   func_02024464 0x02024464 thumb
 *   func_02024450 0x02024450 thumb
 *   d_021C77A0 0x021C77A0 data a1
 */
#include "../include/Obj14184.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 d_021C77A0[][3];
extern int func_02024464(const u16 *p, int v);
extern int func_02024450(const u16 *p);
int func_021C446C(void *a)
{
    int t = 1;
    int n = 0;
    int c0 = 0;
    int c1 = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (d_021C77A0[((u8 *)((struct Obj14184 *)a)->f1C)[0xb]][i] != 0xFF) n++;
    }
    if (n == 3) t = 0;
    for (i = 0; i < 3; i++) {
        u8 *x = *(u8 * *)&((struct Obj14184 *)a)->f1C;
        if (d_021C77A0[x[0xb]][i] != 0xFF) {
            if (func_02024464((u16 *)(x + 0x16 + i * 8), 0x64)) c1++;
        } else {
            if (func_02024450((u16 *)(x + 0x16 + i * 8))) c0++;
        }
    }
    if (c0 < t || c1 < n) return 1;
    return 0;
}
