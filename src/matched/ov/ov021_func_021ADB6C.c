/*
 * function: func_021ADB6C
 * address:  0x021ADB6C
 * packet:   pkt_ov021_021ADB6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 */
typedef unsigned short u16;

typedef struct S40 {
    int w[10];
} S40;

typedef struct Dst {
    u16 h0;
    u16 pad2;
    S40 s4;
    int pad2c[2];
    int f34;
} Dst;

extern int *func_021AC1AC(int a);
extern void func_021AC1CC(int a, int *b);
extern int func_021AC1A0(int a);
extern void func_021AC178(int a);

void func_021ADB6C(int a, Dst *b)
{
    int *s = func_021AC1AC(a);

    b->f34 = s[0];
    b->s4 = *(S40 *)s;
    func_021AC1CC(a, s + 7);
    if (func_021AC1A0(a) == 0) {
        b->h0 = 1;
    }
    func_021AC178(a);
}
