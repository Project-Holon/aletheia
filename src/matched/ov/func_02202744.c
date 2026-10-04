/*
 * function: func_02202744
 * address:  0x02202744
 * packet:   pkt_02202744
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
 * Free every buffer the object owns and blank the 0x13c-byte tail.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern int func_02028604(int a0);
struct PrintSys;
struct S02031140;
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_02082BCC(u32 p, u32 v, u32 n);

void func_02202744(u8 *p)
{
    func_02028604(*(u32 *)(p + 0x138));
    func_0201C4C0((struct PrintSys *)(*(u32 *)(p + 0xc)));
    func_0201D83C((void *)(*(u32 *)p));
    func_02031140((struct S02031140 *)(*(u32 *)(p + 4)));
    func_02082BCC((u32)p, 0, 0x13c);
}
