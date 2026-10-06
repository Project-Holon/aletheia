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

extern void func_021BB7A4(void *p, u32 *s);
struct PrintSys;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0202F038(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern u32 func_020307B0(void *p);

void func_021BB5FC(void *a, int *s)
{
    if (s[0] != 4) {
        func_021BB7A4(a, (u32 *)s);
    }
    if (s[13] != 0) {
        func_0202F038((u8 *)s[13]);
    }
    if (s[3] != 0) {
        func_0201CE48((struct Rec3 *)s[3]);
        func_02045808((struct U16Vec *)s[4]);
    }
    func_0201C6EC((struct PrintSys *)s[10]);
    func_0201C4C0((struct PrintSys *)s[10]);
    func_02028604(s[5]);
    func_02031140((struct S02031140 *)s[2]);
    func_020307B0(s);
}
