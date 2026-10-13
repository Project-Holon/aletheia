/*
 * function: func_021B6F54
 * address:  0x021B6F54
 * packet:   pkt_ov071_021B6F54
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The flag is a u16 local assigned from a ternary over enum constants: every
 * int-constant spelling (ternary, if/else, e != 0) is folded to a boolean and
 * comes out with the opposite branch polarity (beq to 0, not bne to 1).
 * const on d lets both d[] loads go ahead of the stores into s.
 *
 * symbols:
 *   d_021BA844     0x021BA844  data  a2
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef enum { B_FALSE, B_TRUE } Bool;

struct H4 {
    u16 a, b, c, d;
};

struct Ent {
    int w[4];
};

struct P { int w[6]; int pad[10]; struct Ent e[2]; };

extern struct H4 d_021BA844;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);

int func_021B6F54(struct P *p, u8 *q, int c, const int *d, int e)
{
    struct H4 s;
    int r;
    u16 flag;
    u8 *m;

    s = d_021BA844;
    flag = e == 0 ? B_FALSE : B_TRUE;
    s.a = d[0];
    s.b = d[1];
    m = q + 6;
    if (m[c] == 1) {
        s.c = 5;
    }
    r = (int)CLACT_CreateActor((void *)p->w[5], p->e[e].w[1], p->e[e].w[0], p->e[e].w[2], &s, flag, 0x61);
    if (m[c] == 0) {
        func_0204B3DC((struct Obj *)r, 0);
    }
    func_0204B92C((struct Obj *)r, 1);
    return r;
}
