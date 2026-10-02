/*
 * function: func_021D95F0
 * address: 0x021D95F0
 * packet: pkt_ov119_021D95F0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021D95A0 0x021D95A0 thumb ov119
 */
typedef unsigned int u32;
extern int func_021D8AA8(void *);
extern int func_021D8FA4(void *, int);
extern u32 func_021D95A0(void *);
u32 func_021D95F0(void *p)
{
    int r = 1;
    if (func_021D8AA8(p) != 0)
        r = 0;
    return func_021D95A0((void *)func_021D8FA4(p, r));
}
