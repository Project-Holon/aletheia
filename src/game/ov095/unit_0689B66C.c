/*
 * file:     unit_0689B66C.c
 * unit:     yes
 * function: func_0689B66C, func_0689B670, func_0689B69C
 * address:  0x0689B66C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F81EC  0x021F81EC  thumb
 *   func_021F8A78  0x021F8A78  thumb
 *   func_0220270C  0x0220270C  thumb
 *   func_022033CC  0x022033CC  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S {
    u8 pad[0x92];
    union {
        u8 raw;
        struct {
            u8 lo : 7;
            u8 hi : 1;
        } b;
    } f;
};

typedef struct {
    u8 pad[0x92];
    struct { u8 state:7, active:1; } f;
    u8 pad2[0x1d];
    void *ctx;
} S;

extern int func_022033CC(void *);
extern void func_0220270C(void *, int, int);
extern void func_021F81EC(int);
extern void func_021F8A78(void);
unsigned char *func_0689B66C(unsigned char *s);
void func_0689B670(struct S *s);
int func_0689B69C(S *s);

/*
 * follower: pointer-return leaf after non-C veneer 0x0689B65C.
 */
unsigned char *func_0689B66C(unsigned char *s)
{
    return s + 0x8f;
}


/*
 * Clears the low seven bits of the byte at +0x92 and sets its top bit,
 * unless the top bit is already set.  The byte is a union of the whole
 * byte and a { lo:7, hi:1 } split, which is why the guard reads as the
 * lsls/lsrs bitfield pair and the two writes stay two stores.
 */
void func_0689B670(struct S *s)
{
    if (s->f.b.hi)
        return;
    s->f.b.lo = 0;
    s->f.b.hi = 1;
}

/*
 * trailing: five fixed veneers plus 16-byte tail stub 0689B780..0689B790; non-C veneers interrupt the lead/stub C unit. Parent cleared B780 conditionally; no follower filed.
 * checks: 1 call arguments and veneer target words audited, 760 argless; 2 B670 union/bitfields and B790 tail twin read; 3 bitfield += (u8)1 gives byte-correct 148B; 4 bitfield/compound-update idioms fit; 5 live ov095 neighbors reread; caller-only TU/split diagnoses wildcard sites.
 */
int func_0689B69C(S *s)
{
    switch (s->f.state) {
    case 0:
        if (func_022033CC(s->ctx) == 0)
            s->f.state += (u8)1;
        break;
    case 1:
        func_0220270C(s->ctx, 0, 0);
        func_021F81EC(8);
        func_021F8A78();
        s->f.state += (u8)1;
        break;
    case 2:
        if (func_022033CC(s->ctx) == 0)
            s->f.state += (u8)1;
        break;
    case 3:
        s->f.active = 0;
        return 1;
    }
    return 0;
}
