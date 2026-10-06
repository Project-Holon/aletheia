/*
 * function: func_021A7620
 * address:  0x021A7620
 * packet:   pkt_ov021_021A7620
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A78DC  0x021A78DC  thumb
 *   func_021A77E8  0x021A77E8  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;

typedef struct {
    u8 b[0x40];
} E;

typedef struct {
    E e[16];
    void *p;
} S;

typedef unsigned int   u32;
extern int func_021A78DC(u32 a);

extern void func_021A77E8(E *e);
extern u32 func_020307B0(void *p);

void func_021A7620(S *s)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (func_021A78DC((u32)(&s->e[i]))) {
            func_021A77E8(&s->e[i]);
        }
    }
    if (s->p != 0) {
        func_020307B0(s->p);
        s->p = 0;
    }
}
