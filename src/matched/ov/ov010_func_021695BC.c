/*
 * function: func_021695BC
 * address:  0x021695BC
 * packet:   pkt_ov010_021695BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * lever: The archive length call takes the still-live member argument; the remaining two bytes are zero alignment padding.
 *
 * symbols:
 *   func_02169A88  0x02169A88  thumb  ov010
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02169A88(void *a, u32 b);
struct ArcFile;
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
struct ArcFile;
extern void func_0204944C(struct ArcFile *h, u32 b, u32 c, u32 d, void *e);

typedef struct S {
    u16 pad0;
    u16 busy;
    u8 pad4[0x0c];
    u32 h;
    u8 pad14[0x10];
    u32 n;
    u8 pad28[0x8c];
    u32 cur;
    u32 len;
    u32 tot;
    u8 padc0[0x14];
    u32 base;
} S;

void func_021695BC(S *p, u32 b)
{
    u32 t;

    if (p->busy != 0) {
        func_02169A88(p, b);
        return;
    }
    t = p->base + p->cur;
    p->tot = func_020493D4((struct ArcFile *)p->h, b);
    p->len = 0;
    func_0204944C((struct ArcFile *)p->h, b, 0, p->n, (void *)t);
    p->cur = p->cur + p->n;
    p->len = p->len + p->n;
}
