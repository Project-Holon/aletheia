/*
 * function: func_021DDFF8
 * address:  0x021DDFF8
 * packet:   pkt_021DDFF8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02183A24  0x02183A24  arm
 *   g_021E3B54     0x021E3B54  data
 *
 * Hand the +0x1c handle, the shared 0x021E3B54 descriptor and the +0x0c value
 * to func_02183A24; a refusal (0) is reported as 5.
 */

typedef unsigned int u32;

extern u32 g_021E3B54[];
extern int func_02183A24(u32, u32 *, u32);

int func_021DDFF8(char *p)
{
    return func_02183A24(*(u32 *)(p + 0x1c), g_021E3B54, *(u32 *)(p + 0xc)) == 0 ? 5 : 0;
}
