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

struct PrintSys;
struct Rec;
struct S02031140;
extern void func_0202F038(u8 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);

void func_021BDC70(u32 *a0)
{
    u32 i;
    u32 v;

    i = 0x77;
    v = a0[i];
    if (v != 0) {
        func_0202F038((u8 *)v);
        a0[i] = 0;
    }
    i = 0x76;
    func_02031140((struct S02031140 *)a0[i]);
    func_0201C6EC((struct PrintSys *)a0[i - 2]);
    func_0201C4C0((struct PrintSys *)a0[i - 2]);
    func_02045C04((struct Rec *)a0[i - 3]);
    func_0201D83C((void *)a0[i - 4]);
}
