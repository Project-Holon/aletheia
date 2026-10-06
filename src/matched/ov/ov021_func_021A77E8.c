/*
 * function: func_021A77E8
 * address:  0x021A77E8
 * packet:   pkt_ov021_021A77E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    int f0;
    void *f4;
    void *f8;
    void *fc;
    void *f10;
    int pad14[2];
    int f1c;
    int pad20[7];
    void *f3c;
} E;

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021A77E8(E *e)
{
    if (e->f1c != 0) {
        func_020307B0(e->f4);
        func_020307B0(e->f8);
        func_020307B0(e->fc);
        func_020307B0(e->f10);
        func_020307B0(e->f3c);
        e->f1c = 0;
        e->f3c = 0;
    }
}
