/*
 * function: func_0216D040
 * address:  0x0216D040
 * packet:   pkt_ov010_0216D040
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216CFC4  0x0216CFC4  thumb  ov010
 *   func_0216E3D8  0x0216E3D8  thumb  ov010
 *   func_0216D594  0x0216D594  thumb  ov010
 *   func_0216E39C  0x0216E39C  thumb  ov010
 *   func_0216D02C  0x0216D02C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

extern int func_0216CFC4(u8 *o, u16 *r);
extern u32 func_0216E3D8(u32 a, u32 b);
extern void func_0216D594(u8 *o, u32 v);
extern void func_0216E39C(u32 a, u32 v, u8 *o);
extern void func_0216D02C(u8 *o, u16 *r);

void func_0216D040(u8 *o, u16 *r, u32 b, u32 c)
{
    u32 id;
    s8 *p;

    func_0216CFC4(o, r);
    id = func_0216E3D8(b, r[1]);
    func_0216D594(o, id);
    func_0216E39C(c, id, o);
    p = (s8 *)(o + 0xe4);
    if (id == 0xb9) {
        o[0x7c] = r[7];
        o[0x7d] = r[8];
        if (o[0x7c] == 0)
            o[0x7c] += 1;
        if (o[0x7d] == 0)
            o[0x7d] += 1;
    } else {
        o[0x7c] = ((u8 *)p)[0xb];
        o[0x7d] = ((u8 *)p)[0xc];
    }
    o[0x7e] = p[0xd];
    o[0x7f] = p[0xe];
    o[0x80] = p[0xf];
    func_0216D02C(o, r);
}
