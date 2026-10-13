/*
 * function: BTL_EVENT_MultiplyVar
 * address:  0x021D7704
 * packet:   pkt_ov093_021D7704
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlEventVarStack     0x021F3ECC  data
 *   func_021D77E8  0x021D77E8  thumb  ov093
 *   BTL_EVENT_ClampVar  0x021D780C  thumb  ov093
 *   _ll_mul        0x0209C054  arm
 */

#include "../include/G_Tbl.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef signed long long s64;
typedef struct {
    u32 count;
    u16 keys[0x60];
    s32 vals[0x60];
    u32 a[0x60];
    u32 b[0x60];
    u8 c[0x60];
} Tbl;

extern struct Tbl gBtlEventVarStack;
extern int func_021D77E8(Tbl *p, int key);
extern int BTL_EVENT_ClampVar(Tbl *p, int i, int v);

void BTL_EVENT_MultiplyVar(int key, s32 m)
{
    Tbl *t = ((Tbl *)&gBtlEventVarStack);
    int i = func_021D77E8(t, key);

    if (i >= 0 && t->c[i] == 3) {
        s32 v = t->vals[i];
        s64 prod = (s64)v * (s64)m;
        t->vals[i] = BTL_EVENT_ClampVar(t, i, (s32)((prod + 0x800) >> 12));
    }
}
