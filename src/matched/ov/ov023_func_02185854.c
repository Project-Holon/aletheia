/*
 * function: func_02185854
 * address: 0x02185854
 * packet: pkt_ov023_02185854
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return at 0x0218587C.
 * symbols:
 *   func_021857F4 0x021857F4 thumb ov023
 *   func_021861C4 0x021861C4 thumb ov023
 *   func_02186444 0x02186444 thumb ov023
 *   func_02185354 0x02185354 thumb ov023
 */
typedef unsigned char u8;
extern void func_021857F4(char *, int, int);
extern void func_021861C4(u8 *, unsigned int, int);
extern void func_02186444(char *, unsigned int);
extern void func_02185354(char *);
int func_02185854(char *p, int a)
{
    func_021857F4(p, 0, 0);
    func_021861C4((u8 *)p, 3, 1);
    func_02186444(p, 0x13);
    func_02185354(p);
    return a;
}
