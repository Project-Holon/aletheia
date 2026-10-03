/*
 * function: func_021C36E8
 * address: 0x021C36E8
 * packet: pkt_ov093_021C36E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * The final 00 00 at 0x021C371E is alignment padding before 0x021C3720.
 * A separate call-result local keeps the halfword load before that call.
 * symbols:
 *   func_021C604C 0x021C604C thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C16F8 0x021C16F8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C604C(u8 *, u8 *, int);
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C16F8(u8 *, u8 *, int);
void func_021C36E8(u8 *p, u8 *q, u16 *r, int a, int b, u16 c)
{
    int n;
    int v;
    func_021C604C(p, q, c);
    n = *r;
    v = func_021D5440(q);
    func_021CD4B0(*(void **)(p + 12), 0x32, v, (u8)a, n);
    func_021C16F8(p, q, b);
}
