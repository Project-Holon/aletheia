/*
 * function: func_021CECB4
 * address:  0x021CECB4
 * packet:   pkt_ov093_021CECB4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021CF5B0  0x021CF5B0  thumb  ov093
 */
#include "../include/Obj21136.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 *q; u8 f[4]; } Ent;

struct S2;
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *q);
struct QG;
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D5584(void *q, u8 i);
extern u32 func_021D54C0(void *q, u8 i);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);

void func_021CECB4(u8 *p, Ent *out)
{
    u32 i;
    u32 j;
    u8 *q;
    u32 n;
    u32 k;
    Ent *e;
    for (i = 0; i < 3; i++) {
        q = func_021B9C00(((struct Obj21136 *)p)->f118, (u8)i);
        e = out + i;
        e->q = q;
        for (j = 0; j < 4; j++) {
            e->f[j] = 0;
        }
        if (func_021D5B68(q) == 0) {
            n = func_021D5448((struct QG *)q);
            for (k = 0; k < n; k++) {
                if (func_021D5584(q, k) == 0 || func_021CF5B0(p, q, func_021D54C0(q, k), 0) != 0) {
                    e->f[k] = 0;
                } else {
                    e->f[k] = 1;
                }
            }
        }
    }
}
