/*
 * function: ov208_func_021BD330
 * address:  0x021BD330
 * packet:   pkt_ov208_021BD330
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD7FC  0x021BD7FC  thumb
 */

typedef unsigned int u32;

struct Ov208Mgr {
    u32 f0;
    u32 count;
};

extern void func_021BD7FC(void *rec, int v);

void ov208_func_021BD330(struct Ov208Mgr *p, int v)
{
    u32 i;

    for (i = 0; i < p->count; i++)
        func_021BD7FC((void *)((u32)p + 0x28 + i * 0x38), v);
}
