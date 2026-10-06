/*
 * function: func_021B8934
 * address: 0x021B8934
 * packet: pkt_ov102_021B8934
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Clears 0x350 bytes, stores the record count (0x1e or from 0x0200A8AC) at +0x34e,
 * then initialises count records of 0x1c bytes through func_021B8810.
 * Note 2026-10-05: func_021B8810 is matched with three parameters, but this caller
 * loads d into r3 before the call, so the original call site passes four. The older
 * draft that declared three arguments dropped that load (DIFF 109/128).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0200A8AC  0x0200A8AC  thumb
 *   func_021B78EC  0x021B78EC  thumb  ov102
 *   func_02005728  0x02005728  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_021B8810  0x021B8810  thumb  ov102
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *, int, u32);
typedef signed int     s32;
struct Rec;
extern s32 func_0200A8AC(struct Rec *r);
extern u32 func_021B78EC(void *, int);
extern u32 func_02005728(u32);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern void func_021B8810(int a0, int b, int c, int a3);

void func_021B8934(u8 *a, void *b, void *c, int d)
{
    int i;
    func_02082BCC(a, 0, 0x350);
    if (c == 0)
        *(u16 *)(a + 0x34e) = 0x1e;
    else
        *(u16 *)(a + 0x34e) = func_0200A8AC(c);
    for (i = 0; i < *(u16 *)(a + 0x34e); i++) {
        u32 t = func_021B78EC(b, i);
        u32 u;
        if (c == 0)
            u = func_02005728(2);
        else
            u = (func_0200A8F8(c, i) == 1);
        func_021B8810((int)(a + i * 0x1c), t, u, d);
    }
}
