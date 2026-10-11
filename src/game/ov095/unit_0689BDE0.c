/*
 * file:     unit_0689BDE0.c
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
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D5B48  0x021D5B48  thumb
 *   func_021D5B68  0x021D5B68  thumb
 *   func_021D7B74  0x021D7B74  thumb
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

extern int func_021D5B48(void *);
extern int func_021D5B68(void *);
extern Rec *func_021C88A4(void *, int, int);
extern int func_021D7B74(void *, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, int);
extern void func_021C88C8(void *, void *);

void func_0689BDE0(void *a, void *b, int c)
{
    Rec *r;

    if (func_021D5B48(b) == 0 && func_021D5B68(b) == 0) {
        r = func_021C88A4(a, 6, c);
        r->f06 = c;
        r->f07 = 0x1f;
        r->f04 = func_021D7B74(b, 0x10);
        func_021C8838(r->f08, 2, 0x25c);
        func_021C8860(r->f08, c);
        func_021C88C8(a, r);
    }
}
