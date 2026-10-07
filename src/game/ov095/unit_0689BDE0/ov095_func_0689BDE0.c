/*
 * function: func_0689BDE0
 * address:  0x0689BDE0
 * packet:   pkt_ov095_0689BDE0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0689BE3C   0x0689BE3C  thumb  ov095
 *   func_0689BE4C   0x0689BE4C  thumb  ov095
 *   func_0689BE5C   0x0689BE5C  thumb  ov095
 *   func_0689BE6C   0x0689BE6C  thumb  ov095
 *   func_0689BE7C   0x0689BE7C  thumb  ov095
 *   func_0689BE8C   0x0689BE8C  thumb  ov095
 *   func_0689BE9C   0x0689BE9C  thumb  ov095
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

extern int func_0689BE3C(void *);
extern int func_0689BE4C(void *);
extern Rec *func_0689BE5C(void *, int, int);
extern int func_0689BE6C(void *, int);
extern void func_0689BE7C(void *, int, int);
extern void func_0689BE8C(void *, int);
extern void func_0689BE9C(void *, void *);

void func_0689BDE0(void *a, void *b, int c)
{
    Rec *r;

    if (func_0689BE3C(b) == 0 && func_0689BE4C(b) == 0) {
        r = func_0689BE5C(a, 6, c);
        r->f06 = c;
        r->f07 = 0x1f;
        r->f04 = func_0689BE6C(b, 0x10);
        func_0689BE7C(r->f08, 2, 0x25c);
        func_0689BE8C(r->f08, c);
        func_0689BE9C(a, r);
    }
}
