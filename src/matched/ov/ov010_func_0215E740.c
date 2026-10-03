/*
 * function: func_0215E740
 * address: 0x0215E740
 * packet: pkt_ov010_0215E740
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: slot c is u16 in the function and both receiving externs,
 * causing its immediate home reload; the selected byte remains u8.
 * symbols:
 *   func_0200D478 0x0200D478 thumb
 *   func_020113D8 0x020113D8 thumb
 *   func_02005728 0x02005728 thumb
 *   func_0215E7DC 0x0215E7DC thumb ov010
 *   d_021711A8 0x021711A8 data ov010 a2
 *   d_021711C6 0x021711C6 data ov010 a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent { u16 n; u8 v[4]; };
extern struct Ent d_021711A8[];
extern u16 d_021711C6[];
struct Blk38;
extern u8 func_0200D478(struct Blk38 *p, u32 i);
extern u32 func_020113D8(u32 b);
extern u32 func_02005728(u32 n);
extern void func_0215E7DC(void *p, u32 i, u8 v, u32 n);
void func_0215E740(void *a, u32 b, u16 c, int d)
{
    struct Ent *e;
    int s;
    u8 buf[4];
    u8 w;
    int v;
    int k;
    int i;
    s = func_0200D478(a, c);
    e = &d_021711A8[(u16)func_020113D8(b)];
    if (s != 0x10 && func_02005728(100) < 20) {
        func_0215E7DC(a, c, 0x10, 0xffff);
        return;
    }
    k = 0;
    for (i = 0; i < e->n; i++) {
        v = e->v[i];
        if (v != s && v != d) {
            buf[k++] = v;
        }
    }
    w = buf[func_02005728(k)];
    func_0215E7DC(a, c, w, w > 0x10 ? 0x13f : d_021711C6[w]);
}
