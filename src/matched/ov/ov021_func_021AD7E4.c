/*
 * function: func_021AD7E4
 * address:  0x021AD7E4
 * packet:   pkt_ov021_021AD7E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021AD8DC  0x021AD8DC  thumb  ov021
 *   func_021AD96C  0x021AD96C  thumb  ov021
 *   d_021DE094     0x021DE094  data  a2
 */
typedef unsigned short u16;

typedef struct Rec {
    u16 h[7];
} Rec;

extern Rec d_021DE094[];
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021ABE24(u8 *p);
extern void func_021AD8DC(int *a, Rec *b, int c);
extern void func_021AD96C(int *a, Rec *b, int c);

#define R(a) ((Rec *)((char *)(a) + 0x88))

void func_021AD7E4(int *a, int b)
{
    int t;

    *R(a) = d_021DE094[b];
    t = func_021ABE24((u8 *)(*a));
    if (b == 0) {
        func_021AD8DC(a, R(a), t);
    } else {
        func_021AD96C(a, R(a), t);
    }
}
