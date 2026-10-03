/*
 * function: func_021EC338
 * address:  0x021EC338
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Forward with a resolved handle and the object table entry.
 */

typedef unsigned int   u32;
extern u32 func_0201BA68(void *mon);
extern void func_02049E74(int, int, int, void *, int);

void func_021EC338(char *p, void *b, void *c)
{
    func_02049E74(*(int *)(p + 0x1b0), func_0201BA68(b), 0, c, 0x4c);
}

