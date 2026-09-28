/*
 * function: func_021BDC70
 * address:  0x021BDC70
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the five handles at +0x1dc down to +0x1c8 through a running slot index.
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0202F038(u32 v);
extern void func_02031140(u32 v);
extern void func_0201C6EC(u32 v);
extern void func_0201C4C0(u32 v);
extern void func_02045C04(u32 v);
extern void func_0201D83C(u32 v);

void func_021BDC70(u32 *a0)
{
    u32 i;
    u32 v;

    i = 0x77;
    v = a0[i];
    if (v != 0) {
        func_0202F038(v);
        a0[i] = 0;
    }
    i = 0x76;
    func_02031140(a0[i]);
    func_0201C6EC(a0[i - 2]);
    func_0201C4C0(a0[i - 2]);
    func_02045C04(a0[i - 3]);
    func_0201D83C(a0[i - 4]);
}
