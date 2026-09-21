/*
 * unit:     no
 * function: func_02063A54
 * address:  0x02063A54
 * packet:   pkt_0206380C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DC_FlushRange   0x020862F0  arm
 *   GX_BeginLoadTex 0x0207F7A0  arm
 *   GX_LoadTex      0x0207F7FC  arm
 *   GX_EndLoadTex   0x0207F9B4  arm
 *   GX_LoadOBJ      0x0207E780  arm
 *   GXS_LoadOBJ     0x0207E804  arm
 *   func_020637AC   0x020637AC  arm
 *
 * Upload one VRAM resource: optionally repoint the 2D/3D VRAM control word,
 * flush the source range, hand it to the matching GX loader (3D texture,
 * main OBJ, sub OBJ), then fill the caller's descriptor.  When f8 (the bank
 * control word) is zero the two halfword dimensions are translated from
 * pixel sizes (1,2,4,8,0x10,0x20) to GX size codes 0..5; otherwise they are
 * stored raw.
 *
 * 1.1p1 CSEs the shared zero into a callee-saved register (costing r8 and a
 * six-register frame) and cross-jumps the two VRAM-control arms, giving 532
 * bytes against the original's 556; under ../2.0/sp2 the same C is 556
 * bytes, 0 mismatches.  See docs/FRONTEND-PINS.md.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Res {
    u16 f0;
    u16 f2;
    int f4;
    u32 f8;
    int fc;
    u32 f10;
    void *f14;
};

struct Out {
    int f0, f4, f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    u32 f20;
};

extern void DC_FlushRange(void *p, u32 n);
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *src, u32 off, u32 n);
extern void GX_EndLoadTex(void);
extern void GX_LoadOBJ(void *src, u32 off, u32 n);
extern void GXS_LoadOBJ(void *src, u32 off, u32 n);
extern void func_020637AC(struct Out *out, int mode, u32 dst);

void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out)
{
    u32 bank = r->f8;

    switch (mode) {
    case 0:
        break;
    case 1:
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFCFFFEF) | bank;
        break;
    case 2:
        *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & 0xFFCFFFEF) | bank;
        break;
    }
    DC_FlushRange(r->f14, r->f10);
    switch (mode) {
    case 0:
        GX_BeginLoadTex();
        GX_LoadTex(r->f14, dst, r->f10);
        GX_EndLoadTex();
        break;
    case 1:
        GX_LoadOBJ(r->f14, dst, r->f10);
        break;
    case 2:
        GXS_LoadOBJ(r->f14, dst, r->f10);
        break;
    }
    if (r->f8 == 0) {
        int a, b;
        switch (r->f2) {
        case 1:    a = 0; break;
        case 2:    a = 1; break;
        case 4:    a = 2; break;
        case 8:    a = 3; break;
        case 0x10: a = 4; break;
        case 0x20: a = 5; break;
        default:   a = 0; break;
        }
        out->fc = a;
        switch (r->f0) {
        case 1:    b = 0; break;
        case 2:    b = 1; break;
        case 4:    b = 2; break;
        case 8:    b = 3; break;
        case 0x10: b = 4; break;
        case 0x20: b = 5; break;
        default:   b = 0; break;
        }
        out->f10 = b;
    } else {
        out->fc = r->f2;
        out->f10 = r->f0;
    }
    out->f14 = r->f4;
    out->f18 = 0;
    out->f1c = 1;
    out->f20 = r->f8;
    func_020637AC(out, mode, dst);
}
