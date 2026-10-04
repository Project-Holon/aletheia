/*
 * unit:     yes
 * function: func_021E556C, func_021E55B8
 * address:  0x021E556C
 * packet:   pkt_ov093_021E556C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2484     0x021F2484  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v; } Word;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int d_021F2484[];

void func_021E556C(int a, void *b, int c, int d, u8 e, int f, Word g, u16 h)
{
    u8 *m;

    if (c == func_021D775C(3)) {
        m = (u8 *)func_021C88A4(b, 0x19, c);
        *(int *)(m + 4) = f;
        m[0xc] = e;
        *(Word *)(m + 8) = g;
        func_021C8838(m + 0x10, 1, h);
        func_021C8860((struct S *)(m + 0x10), e);
        func_021C88C8(b, m);
    }
}

int *func_021E55B8(int *p)
{
    *p = 1;
    return d_021F2484;
}
