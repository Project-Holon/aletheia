/*
 * function: func_021AD738
 * address:  0x021AD738
 * packet:   pkt_ov021_021AD738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 */
typedef unsigned short u16;

extern int func_021ABE18(int a);
typedef unsigned int   u32;
extern int func_021C6658(u32 a, u32 b);
extern void func_021AC1B8(int a, int b);

typedef struct S {
    int pad0[4];
    u16 h10;
    u16 pad12;
    int pad14;
    int *p18;
} S;

void func_021AD738(int a, S *s)
{
    func_021AC1B8(a, func_021C6658(func_021ABE18(*s->p18), s->h10));
}
