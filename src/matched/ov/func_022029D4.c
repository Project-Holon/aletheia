/*
 * function: func_022029D4
 * address:  0x022029D4
 * packet:   pkt_022029D4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Release every buffer the object owns, then the object itself.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct PrintSys;
struct Rec;
struct WordSet;
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201D83C(void *ptr);
extern void func_020307B0(void *p);

void func_022029D4(u8 *p)
{
    func_0201ED04((struct WordSet *)(*(u32 *)(p + 8)));
    func_02045C04((struct Rec *)(*(u32 *)(p + 0xc)));
    func_0201C4C0((struct PrintSys *)(*(u32 *)(p + 4)));
    func_0201D83C((void *)(*(u32 *)p));
    func_020307B0((void *)((u32)p));
}
