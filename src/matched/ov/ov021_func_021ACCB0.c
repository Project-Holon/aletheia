/*
 * function: func_021ACCB0
 * address:  0x021ACCB0
 * packet:   pkt_ov021_021ACCB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9198     0x021D9198  data  a2
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   d_021D91C8     0x021D91C8  data  a4
 *   d_021D91B0     0x021D91B0  data  a2
 *   func_021C6678  0x021C6678  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct V3 { s32 x, y, z; } V3;
typedef struct Ang { u16 x, y, z; } Ang;
typedef struct AngTbl { Ang e[4]; } AngTbl;
typedef struct PosTbl { V3 e[4]; } PosTbl;

typedef struct Node {
    V3 pos;
    V3 scale;
    u8 mtx[0x24];
} Node;

typedef struct Inner {
    u16 a;
    u16 b;
    u8 pad[0x18];
    u16 c;
    u16 pad2;
    V3 scale;
    V3 pos;
} Inner;

typedef struct B {
    u8 pad0[0xc];
    u16 fc;
    u8 pad1[0xa];
    u16 f18;
    u8 pad2[2];
    u32 *f1c;
    u8 pad3[0x18];
    Inner in;
} B;

extern AngTbl d_021D9198;
extern PosTbl d_021D91C8;
extern AngTbl d_021D91B0;
extern u32 func_021ABE18(u32 a);
extern Node *func_021C6658(u32 a, u32 b);
extern void func_020520FC(int ax, int ay, int az, void *dst);
extern void func_021AC1B8(u32 a, Node *n);
extern void func_021C6678(u32 a, u32 b, u32 c);

void func_021ACCB0(u32 a, B *b)
{
    AngTbl t = d_021D9198;
    Ang *e = &t.e[b->fc];
    u32 obj;
    Node *n;

    obj = func_021ABE18(*b->f1c);
    n = func_021C6658(obj, b->f18);
    func_020520FC(e->x, e->y, e->z, n->mtx);
    func_021AC1B8(a, n);
    if (b->in.a == 0) {
        Inner *in = &b->in;
        PosTbl pt = d_021D91C8;
        AngTbl at = d_021D91B0;
        V3 *p = &pt.e[b->fc];
        Ang *g = &at.e[b->fc];
        n = func_021C6658(obj, in->c);
        func_020520FC(g->x, g->y, g->z, n->mtx);
        func_021AC1B8(a, n);
        n->pos.x = n->pos.x + (in->pos.x + p->x);
        n->pos.y = n->pos.y + (in->pos.y + p->y);
        n->pos.z = n->pos.z + (in->pos.z + p->z);
        n->scale = in->scale;
        func_021C6678(obj, in->c, 0);
    } else {
        func_021C6678(obj, b->in.c, 1);
    }
}
