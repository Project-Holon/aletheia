/*
 * function: func_021C3FDC
 * address: 0x021C3FDC
 * packet: pkt_ov127_021C3FDC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C4358 0x021C4358 thumb ov127
 *   func_021C4354 0x021C4354 thumb ov127
 *   func_021C435C 0x021C435C thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021C4358(int, int);
extern int func_021C4354(int);
extern void func_021C435C(char *p, int i, int a, int b, int c, int mode);
void func_021C3FDC(u8 *p, int a, int b, int c, int d)
{
    func_021C4358(a,c);
    func_021C435C((char *)p,func_021C4354(a),b,c,d,0);
}
