/*
 * function: func_021ABFDC
 * address:  0x021ABFDC
 * packet:   pkt_ov021_021ABFDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030D28  0x02030D28  arm
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

extern void func_02030D28(int a);

void func_021ABFDC(T *t)
{
    if (t->f1c != 0) {
        func_02030D28(t->f1c);
    }
}
