/*
 * function: func_02164844
 * address:  0x02164844
 * packet:   pkt_ov010_02164844
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up a table entry; 0xFFFF means missing and forwards to
 * func_02013C10, otherwise reads one byte through func_0204944C.
 *
 * symbols:
 *   func_021648A8  0x021648A8  thumb ov010
 *   func_02013C10  0x02013C10  thumb
 *   func_021648CC  0x021648CC  thumb ov010
 *   func_0204944C  0x0204944C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_021648A8(void *a, u32 b);
extern u8   func_02013C10(u32 b);
extern u32  func_021648CC(int n, int k);
extern void func_0204944C(u32 a, int b, u16 c, int d, u8 *e);

u8 func_02164844(u8 *a, u32 b, int c, int d)
{
    u32 t = func_021648A8(a, b);
    u8 out;
    u16 s;
    if (t == 0xffff) {
        return func_02013C10(b);
    }
    s = t + func_021648CC(c, d);
    func_0204944C(*(u32 *)(a + 8), 0, s, 1, &out);
    return out;
}
