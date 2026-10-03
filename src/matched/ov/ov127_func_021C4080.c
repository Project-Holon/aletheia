/*
 * function: func_021C4080
 * address: 0x021C4080
 * packet: pkt_ov127_021C4080
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4594 0x021C4594 thumb ov127
 *   func_021C45E0 0x021C45E0 thumb ov127
 *   func_021C4424 0x021C4424 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C4594(u8 *);
extern void func_021C45E0(u8 *);
extern void func_021C4424(char *, int);
void func_021C4080(u8 *p)
{
    int i;
    func_021C4594(p);
    func_021C45E0(p);
    for (i=0; i<16; i++) func_021C4424((char *)p, i);
}
