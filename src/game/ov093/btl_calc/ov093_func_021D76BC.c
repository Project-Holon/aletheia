/*
 * function: func_021D76BC
 * address:  0x021D76BC
 * packet:   pkt_ov093_021D76BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021F3ECC     0x021F3ECC  data
 *   func_021D77E8  0x021D77E8  thumb  ov093
 */

#include "../../../matched/include/G_Tbl.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef struct {
    u32 count;
    u16 keys[0x60];
    u32 vals[0x60];
    u32 a[0x60];
    u32 b[0x60];
    u8 c[0x60];
} Tbl;

extern struct Tbl g_021F3ECC;
extern int func_021D77E8(Tbl *p, int key);

int func_021D76BC(int key, u32 val)
{
    Tbl *t = ((Tbl *)&g_021F3ECC);
    int i = func_021D77E8(t, key);

    if (i >= 0 && t->c[i] <= 1) {
        t->keys[i] = key;
        t->vals[i] = val;
        if (t->c[i] == 1)
            t->c[i] = 2;
        return 1;
    }
    return 0;
}
