/*
 * function: func_021F2D84
 * address: 0x021F2D84
 * packet: pkt_ov029_021F2D84
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F2DA8 0x021F2DA8 thumb ov029
 *   func_021F0EB0 0x021F0EB0 thumb ov029
 */
typedef unsigned char u8;
extern int func_021F2DA8(u8 *p);
extern void func_021F0EB0(char *p, int flag);
void func_021F2D84(u8 *p)
{
    if (p[0x45e] != 0) {
        func_021F0EB0((char *)p, func_021F2DA8(p));
        p[0x45e] = 0;
    }
}
