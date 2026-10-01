/*
 * function: func_021ABFC0
 * address:  0x021ABFC0
 * packet:   pkt_ov021_021ABFC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC03C  0x021AC03C  thumb
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T;

extern void func_021AC03C(int a);
extern void func_02030DA4(int a);
extern void func_020307B0(void *p);

void func_021ABFC0(T *t)
{
    if (t->f20 != 0) {
        func_021AC03C(t->f20);
        func_02030DA4(t->f1c);
        func_020307B0(t->f18);
    }
}
