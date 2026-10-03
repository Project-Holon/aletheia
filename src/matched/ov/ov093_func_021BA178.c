/*
 * function: func_021BA178
 * address: 0x021BA178
 * packet: pkt_ov093_021BA178
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 */
extern int func_0201AA18(void *);
typedef unsigned int u32;
extern void *func_0201AB28(void *p, u32 idx);
void *func_021BA178(void *p, int i, int mode)
{
    if (mode) {
        if (func_0201AA18(*(void **)(((u32)p + 0x2a8) + (u32)i * 4)))
            func_0201AB28(*(void **)(((u32)p + 0x2a8) + (u32)i * 4), 0);
        return *(void **)(((u32)p + 0x2a8) + (u32)i * 4);
    }
    return *(void **)((u32)p + (u32)i * 4 + 0x298);
}
