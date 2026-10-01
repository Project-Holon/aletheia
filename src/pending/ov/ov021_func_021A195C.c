/*
 * function: func_021A195C
 * address:  0x021A195C
 * packet:   pkt_ov021_021A195C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: TexImageParam/TexPlttBase pair. Original spills the first call's
 * result to [sp], loads the u8 fields in order 22,21,20,25,23,24 and keeps
 * fmt (+0x24) live in r5 across the second call; OR order differs. Draft
 * semantics are right, schedule is not.
 *
 * symbols:
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x20];
    u8 sizeS;
    u8 sizeT;
    u8 repeat;
    u8 flip;
    u8 fmt;
    u8 pltt0;
    u8 pad26[2];
    u32 key;
} Obj021A195C;

u32 func_02047388(u32 key);
u32 func_020473B8(u32 key);

static inline void TexImageParam021A195C(int fmt, int gen, int s, int t, int repeat, int flip, int pltt0, u32 addr)
{
    *(volatile u32 *)0x040004A8 = (u32)(((addr) >> 3) | ((s) << 20) | ((t) << 23) | ((repeat) << 16) |
                                        ((flip) << 18) | ((pltt0) << 29) | ((fmt) << 26) | ((gen) << 30));
}

static inline void TexPlttBase021A195C(u32 addr, int fmt)
{
    *(volatile u32 *)0x040004AC = addr >> (4 - (fmt == 2));
}

void func_021A195C(Obj021A195C *p)
{
    u16 a = func_02047388(p->key);

    TexImageParam021A195C(p->fmt, 1, p->sizeS, p->sizeT, p->repeat, p->flip, p->pltt0, (u32)a << 3);
    TexPlttBase021A195C((u32)(u16)func_020473B8(p->key) << 3, p->fmt);
}
