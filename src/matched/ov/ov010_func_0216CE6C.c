/*
 * function: FLDMMDL_AddMmdlParam
 * address:  0x0216CE6C
 * packet:   pkt_ov010_0216CE6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a, p0;
    u16 b, p1;
    u16 c, p2;
} In3;

typedef struct { u16 f, g; } W2;
typedef struct {
    u16 a, b, c;
    u16 pad0[3];
    u16 d;
    u16 pad1[5];
    u32 e;
    W2 w;
    u32 pad2;
} Big;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *FLDMMDL_AddMmdl(void *o, Big *b, u32 c);

void *FLDMMDL_AddMmdlParam(void *o, u32 f, u32 g, u32 d, In3 in, u32 x)
{
    Big s;
    In3 *ip = &in;
    Big *v = &s;
    W2 *w;

    func_02082BCC(&s, 0, 0x24);
    v->a = ip->a;
    v->b = ip->b;
    v->c = ip->c;
    v->d = d;
    s.e = 0;
    w = &s.w;
    w->f = f;
    w->g = g;
    return FLDMMDL_AddMmdl(o, &s, x);
}
