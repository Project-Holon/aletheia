/*
 * function: func_021EA1C0
 * address:  0x021EA1C0
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
 * Allocate (0x4c, 0xb8, 1) into the 0x021F140C buffer and store
 * the handle at sub-object +0x60.
 */

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);


void func_021EA1C0(void *p)
{
    int v = (int)func_02030734(0x4c, 0xb8, 1, (const char *)0x021F140C, 0x2130);
    *(int *)(*(int *)((char *)p + 0x2c) + 0x60) = v;
}
