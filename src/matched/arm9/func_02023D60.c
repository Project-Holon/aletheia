/*
 * function: func_02023D60
 * address:  0x02023D60
 * packet:   pkt_02023D60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 fC;
};

extern void func_020056A0(u32 fn, void *rec, u32 one);

void func_02023D60(u8 *p, u16 a, u16 b, u16 c, u32 d, u32 e, u32 f)
{
    struct Rec *r = (struct Rec *)(p + 0x80 + f * 32 + e * 16);

    r->f0 = a;
    r->f2 = b;
    r->f4 = c;
    r->f6 = (u16)d;
    r->f8 = e;
    r->fC = f;
    func_020056A0(0x02023DDD, r, 1);
}
