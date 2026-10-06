/*
 * function: func_021B9280
 * address: 0x021B9280
 * packet: pkt_ov067_021B9280
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
void func_021B9280(u8 *p, int a, u32 b) {
    s16 pos = (s8)p[102]/8 + ((s8)p[3] + a*p[5]);
    u16 i = 0;
    for (; i < p[5]; i++) {
        if (pos < 0) pos += 32;
        else if (pos >= 32) pos -= 32;
        func_020413B0(p[0],p[2],(u8)pos,p[4],1,(u8)b);
        pos++;
    }
    func_02041B6C(p[0]);
}
