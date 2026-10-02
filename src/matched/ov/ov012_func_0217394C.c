/*
 * function: func_0217394C
 * address: 0x0217394C
 * packet: pkt_ov012_0217394C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012138 0x02012138 thumb
 *   func_02026474 0x02026474 thumb
 * 02012138 reads incoming r0; its u32 handle feeds 02026474(void *).
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026474(void *p);
int func_0217394C(const struct Ctx *p)
{
    u8 *w = (u8 *)func_02026474((void *)func_02012138(p));
    if (w == 0) return 0;
    if ((w[0x2831] == 0 || w[0x2831] == 0x2a) && w[0x3563] == 0) return 1;
    return 0;
}
