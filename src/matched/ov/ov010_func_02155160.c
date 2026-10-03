/*
 * function: func_02155160
 * address:  0x02155160
 * packet:   pkt_ov010_02155160
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Walks every entry of a list and applies func_02019CA0 with 50.
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02019CA0  0x02019CA0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0201AA18(void *list);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02019CA0(void *p, u32 v);

void func_02155160(void *list)
{
    int i;

    for (i = 0; i < (int)func_0201AA18(list); i++)
        func_02019CA0(func_0201AB28(list, i), 50);
}
