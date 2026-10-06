/*
 * function: func_021BB440
 * address: 0x021BB440
 * packet: pkt_ov091_021BB440
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021BB46C 0x021BB46C thumb ov091
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_021BB2C0(u8 *a, u8 *s);
extern void func_021BB46C(u8 *p, u32 *q);
void func_021BB440(u8 *p, u32 *q, int v)
{
    if (q[7] != v) {
        if (v < 6) {
            q[7] = v;
        } else {
            func_021BB46C(p, (u32 *)q);
        }
        func_021BB2C0(p, (u8 *)q);
    }
}
