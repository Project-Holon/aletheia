/*
 * file:     unit_0689BB7C.c
 * function: func_0689BB7C
 * address:  0x0689BB7C
 * packet:   pkt_ov095_0689BB7C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689BBD0   0x0689BBD0  thumb  ov095
 *   func_0689BBE0   0x0689BBE0  thumb  ov095
 *   func_0689BBF0   0x0689BBF0  thumb  ov095
 *   func_0689BC00   0x0689BC00  thumb  ov095
 *   func_0689BC10   0x0689BC10  thumb  ov095
 *   func_0689BC20   0x0689BC20  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rec {
    u8 pad[4];
    u16 f04;
    u8 f06;
    u8 f07;
    u8 f08[1];
} Rec;

extern int func_0689BBD0(void *);
extern Rec *func_0689BBE0(void *, int, int);
extern int func_0689BBF0(void *, int);
extern void func_0689BC00(void *, int, int);
extern void func_0689BC10(void *, int);
extern void func_0689BC20(void *, void *);

void func_0689BB7C(void *a, void *b, int c)
{
    Rec *r;

    if (func_0689BBD0(b) == 0) {
        r = func_0689BBE0(a, 6, c);
        r->f06 = c;
        r->f07 = 0x1f;
        r->f04 = func_0689BBF0(b, 0x10);
        func_0689BC00(r->f08, 2, 0x2e3);
        func_0689BC10(r->f08, c);
        func_0689BC20(a, r);
    }
}
