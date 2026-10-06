/*
 * function: func_021A753C
 * address:  0x021A753C
 * packet:   pkt_ov021_021A753C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02046F48  0x02046F48  arm
 *   func_0206E954  0x0206E954  arm
 *   func_02047250  0x02047250  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02069C74  0x02069C74  arm
 *   func_02069E88  0x02069E88  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Res { u32 x0, x1; u8 a, cnt; u16 b, c, ofs; } Res;
typedef struct Ctx { u32 flags; u32 *buf; u32 v; } Ctx;

struct Tagged;
extern void *func_02046F48(struct Tagged *p);
extern int func_0206E954(int p0);
extern u32 func_02047250(u32 a);
extern void func_02082BCC(u32 *p, u32 v, u32 n);
extern void func_02069C74(u32 *a, u32 b, u32 c, u32 d);
extern void func_02069E88(u32 a, u32 *b);

static inline u32 *ent(Res *x, u32 idx)
{
    u8 *y = (u8 *)x + 8;
    if (y != 0 && idx < x->cnt)
        return (u32 *)(y + x->ofs + 4 + idx * 4);
    return 0;
}

static inline u32 res0(Res *x)
{
    u32 *z;
    if (x != 0) {
        z = ent(x, 0);
        if (z != 0)
            return (u32)x + *z;
    }
    return 0;
}

void func_021A753C(Ctx *s, u32 b, u32 c, u32 d)
{
    u32 r6;
    r6 = res0((Res *)func_0206E954((u32)func_02046F48((struct Tagged *)b)));
    if (c != 0)
        c = func_02047250(c);
    else
        c = 0;
    func_02082BCC(s->buf, 0, 0x80);
    func_02069C74(s->buf, s->v, r6, c);
    func_02069E88(d, s->buf);
    s->flags = (s->flags & ~1) | 1;
}
