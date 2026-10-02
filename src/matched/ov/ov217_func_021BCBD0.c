/*
 * function: func_021BCBD0
 * address: 0x021BCBD0
 * packet: pkt_ov217_021BCBD0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BC6DC 0x021BC6DC thumb ov217
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { char pad0[8]; u16 h8; };
extern int func_021BC6DC(struct S *p);
extern void *func_020490F4(int a, u16 b);
extern void *func_02049250(void *h, int a, int b);
extern int func_02062B30(void *ptr, char **out);
extern void func_02041090(int a, void *b, int c, int d, int e, int f);
extern void func_02041B6C(u32 bg);
extern int func_020307B0(void *p);
extern void func_02049238(void *h);

void func_021BCBD0(struct S *p)
{
    void *heap = func_020490F4(0xc0, (p->h8 & 0x7fff) | 0x8000);
    int v = func_021BC6DC(p) * 3;
    void *res = func_02049250(heap, 5, p->h8);
    char *q;
    func_02062B30(res, &q);
    func_02041090(2, q + 0xc, 0, 0, 0x20, (u8)v);
    func_02041B6C(2);
    func_020307B0(res);
    func_02049238(heap);
}
