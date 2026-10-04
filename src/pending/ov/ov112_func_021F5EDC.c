/*
 * function: func_021F5EDC
 * address: 0x021F5EDC
 * packet: pkt_ov112_021F5EDC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-04 wave D3 lane 18: DIFF, same size (576 bytes), only the 21 lines at +0068..+0098 differ.
 * G3 sequence matches (volatile stores, TexPlttBase, Translate, Scale, quad with TexCoord and Vtx16).
 * Residue: original loads the pa pointer (sp+0x50) before the 0x040004A4 store, and keeps e2 in r0 (a9*8 in r0, arr in r2). Compiled keeps e2 in r1 with a movs r2,#2 hoisted.
 * Tried: one expression, split e1/e2, raw offsets, struct chain, i1/i2 locals, hdr local, q = pa copy early. All give the same 21 lines.
 * Original frame: ang sp28, x sp24, y sp20 (declare ang, x, y); pk(v) = (u16)((v<<8)>>16) with no extra s16 cast; texcoord s0/s1/t0/t1 locals.
 * symbols:
 *   func_0207D760 0x0207D760 arm
 *   func_0207D888 0x0207D888 arm
 *   d_020A1B38 0x020A1B38 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct E2 { s16 p0; s16 f2; s16 f4; s16 p6; };
struct E1 { int p0; struct E2 *arr; };
struct H { int p0; struct E1 *tbl; };

struct S {
    int pad0;
    int f4;
    int f8;
    s16 fC;
    s16 fE;
};

extern s16 d_020A1B38[];
extern void func_0207D760(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void func_0207D888(int a, int b);

static inline void G3_TexPlttBase(u32 addr, int fmt)
{
    u32 param = (u32)(addr >> (4 - (fmt == 2)));
    *(volatile u32 *)0x040004AC = param;
}

static inline void G3_Translate(int x, int y, int z)
{
    *(volatile u32 *)0x04000470 = (u32)x;
    *(volatile u32 *)0x04000470 = (u32)y;
    *(volatile u32 *)0x04000470 = (u32)z;
}

static inline void G3_Scale(int x, int y, int z)
{
    *(volatile u32 *)0x0400046C = (u32)x;
    *(volatile u32 *)0x0400046C = (u32)y;
    *(volatile u32 *)0x0400046C = (u32)z;
}

static inline u32 pk(int v)
{
    return (u16)((v << 8) >> 16);
}

static inline void G3_TexCoord(u32 s, u32 t)
{
    *(volatile u32 *)0x04000488 = s | (t << 16);
}

static inline void G3_Vtx(u32 xy, u32 z)
{
    *(volatile u32 *)0x0400048C = xy;
    *(volatile u32 *)0x0400048C = z;
}

void func_021F5EDC(char *p, int a1, int a2, int a3, int a4, int a5, int a6, struct S *s, u16 *pa, int a9, int flag, int *pz, int mode)
{
    u16 ang;
    int x;
    int y;
    struct E2 *e2;
    struct E1 *e1;
    u32 s0;
    u32 s1;
    u32 t0;
    u32 t1;

    if (flag != 0) {
        func_0207D760(0x60000, 0xFFFA1000, 0xFFF81000, 0x80000, 0x1000, 0x3E8000, 0x1000, 1, 0);
        *(volatile u32 *)0x04000440 = 2;
    }
    *(volatile u32 *)0x04000450 = 0x1D;
    G3_TexPlttBase(*(u32 *)(p + 0xBC), *(int *)(p + 0xB4));
    *(volatile u32 *)0x040004A4 = 0x001F00C0;
    e1 = &(*(struct H **)(p + 0x6C))->tbl[*pa];
    e2 = &e1->arr[a9];
    x = (s->fC + e2->f2) << 8;
    y = -(s->fE + e2->f4) << 8;
    if (mode == 0) {
        ang = *(u16 *)(p + 0xFC);
    } else if ((mode & 1) != 0) {
        ang = (u16)(0x10000 - *(u16 *)(p + 0xFC));
    }
    func_0207D888(-d_020A1B38[(ang >> 4) * 2], d_020A1B38[(ang >> 4) * 2 + 1]);
    G3_Translate(x, y, *pz);
    func_0207D888(-d_020A1B38[(*(u16 *)((char *)s + 2) >> 4) * 2], d_020A1B38[(*(u16 *)((char *)s + 2) >> 4) * 2 + 1]);
    if (mode == 0) {
        G3_Scale(s->f4, s->f8, 0x1000);
        G3_Translate(a1, a2, 0);
        G3_Scale(a3, a4, 0x1000);
    } else if ((mode & 1) != 0) {
        G3_Scale(-s->f4, s->f8, 0x1000);
        G3_Translate(-a1, a2, 0);
        G3_Scale(a3, a4, 0x1000);
        G3_Translate(-0x100, 0, 0);
        a5 = 0x200000 - a5 - a3;
    }
    *(volatile u32 *)0x04000500 = 1;
    t0 = pk(a6) << 16;
    s0 = pk(a5);
    *(volatile u32 *)0x04000488 = s0 | t0;
    G3_Vtx(0, 0);
    s1 = pk(a5 + a3);
    *(volatile u32 *)0x04000488 = s1 | t0;
    G3_Vtx(0x100, 0);
    t1 = pk(a6 + a4) << 16;
    *(volatile u32 *)0x04000488 = s1 | t1;
    G3_Vtx(0xFF000100, 0);
    *(volatile u32 *)0x04000488 = s0 | t1;
    G3_Vtx(0xFF000000, 0);
    *(volatile u32 *)0x04000504 = 0;
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000450 = 0;
    *(volatile u32 *)0x04000440 = 2;
    if (flag == 0) {
        *pz = *pz - 0x100;
    } else {
        *pz = *pz - 0x400;
    }
}
