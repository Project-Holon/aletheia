/*
 * function: func_021BB5FC
 * address:  0x021BB5FC
 * packet:   pkt_ov091_021BB5FC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_0202F038  0x0202F038  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021BB7A4(void *a, int *s, int k);
extern void func_0202F038(u32 v);
extern void func_0201CE48(u32 v);
extern void func_02045808(u32 v);
extern void func_0201C6EC(u32 v);
extern void func_0201C4C0(u32 v);
extern void func_02028604(u32 v);
extern void func_02031140(u32 v);
extern void func_020307B0(void *p);

void func_021BB5FC(void *a, int *s)
{
    if (s[0] != 4) {
        func_021BB7A4(a, s, s[0]);
    }
    if (s[13] != 0) {
        func_0202F038(s[13]);
    }
    if (s[3] != 0) {
        func_0201CE48(s[3]);
        func_02045808(s[4]);
    }
    func_0201C6EC(s[10]);
    func_0201C4C0(s[10]);
    func_02028604(s[5]);
    func_02031140(s[2]);
    func_020307B0(s);
}
