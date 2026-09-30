/*
 * function: func_021BFA68
 * address:  0x021BFA68
 * packet:   pkt_ov172_021BFA68
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  codegen / global register colouring, not semantics.  The body now
 *           reproduces case for case (same instructions, same order, the
 *           coalesced `mov zero; str counter` case inits, the per-case index
 *           sums in the original's left-to-right evaluation order, and the
 *           redundant dy self-store) but the allocator colours the three
 *           long-lived callee-saved values of each case differently and spills
 *           case 4's `m`, so the frame is 0x30 (original 0x2c), the prologue
 *           also saves r3, and the body is 1412 B (original 1372; 1336 code +
 *           36 pool).  Original colours per case: case3 z=sb j=r8 off=r7
 *           i=[sp+0x1c]; case4 e=r7 j=sb off=r8 m=lr n=[sp+0x24]; case5 like
 *           case4 with s=[sp+4] t=[sp+0x20]; case6 e=r5 j=r7 off=r6 d2=fp
 *           c=[sp] s=[sp+8].  Compiled is a cyclic permutation of
 *           {r7,r8,sb} with `m` spilled to [sp+0x2c].  Fixing this needs the
 *           original block-scoped locals' declaration order/scope verbatim;
 *           semantic, verified against the listing.
 *
 * sdk:      writeblock (libssp.TWL.HYB.a jpegdec.o)
 *
 * YCbCr block merge + colour convert.  Four near-identical 8x8 loops,
 * selected by the component sampling factors bcode2.f14 (H) and bcode2.f04
 * (V): switch (f04*2 + f14) with cases 3..6 for (1,1)/(2,1)/(1,2)/(2,2).
 * Each output pixel packs
 *   0x8000 | ((b1 & 0xf8) << 2) | ((b0 & 0xf8) >> 3) | ((b2 & 0xf8) << 7)
 * from three bytes of limits[] offset by draw_block[] plus a colour table.
 * Cases 3/4/5 take red from dcb and blue from dcr; case 6 swaps them.
 *
 * symbols:
 *   bcode2      0x021C88F0  data
 *   draw_block  0x021C8D9C  data
 *   dcb         0x021C891C  data
 *   dcr         0x021C899C  data
 *   limits      0x021C802C  data
 *   Crrtab      0x021C752C  data
 *   Crgtab      0x021C7B2C  data
 *   Cbbtab      0x021C732C  data
 *   Cbgtab      0x021C772C  data
 */

typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

typedef struct {
    s32 pad0;
    s32 f04;
    s32 pad8;
    s32 pad0c;
    s32 pad10;
    s32 f14;
} BCode2;

extern BCode2 bcode2;
extern s16 draw_block[1024];
extern s16 dcb[64];
extern s16 dcr[64];
extern u8 limits[];
extern s16 Crrtab[256];
extern s32 Crgtab[256];
extern s16 Cbbtab[256];
extern s32 Cbgtab[256];

void func_021BFA68(u8 *d, int x, int y, int dx, int dy)
{
    int n, m, t, s, c, d2, z, e, off, j, i, idx;
    u8 *yp;
    int v;

    switch (bcode2.f04 * 2 + bcode2.f14) {
    case 3:
        i = z = 0;
        for (; i < 8; i++) {
            if (y + i >= dy)
                return;
            off = 2 * (dx * (y + i) + x);
            for (j = 0; j < 8; j++, z++) {
                if (x + j >= dx)
                    break;
                yp = limits + draw_block[z];
                v = ((yp[(Cbgtab[dcr[z]] + Crgtab[dcb[z]]) >> 16] & 0xf8) << 2)
                    | ((yp[Crrtab[dcb[z]]] & 0xf8) >> 3)
                    | ((yp[Cbbtab[dcr[z]]] & 0xf8) << 7)
                    | 0x8000;
                d[off] = v;
                d[off + 1] = v >> 8;
                off += 2;
            }
        }
        break;

    case 4:
        n = e = 0;
        for (; n < bcode2.f14; n++) {
            for (m = 0; m < 8; m++) {
                if (y + m >= dy)
                    break;
                off = 2 * (dx * (y + m) + x + n * 8);
                for (j = 0; j < 8; j++, e++) {
                    if (x + n * 8 + j >= dx)
                        break;
                    idx = (j >> 1) + n * 4 + m * 8;
                    yp = limits + draw_block[e];
                    v = ((yp[(Cbgtab[dcr[idx]] + Crgtab[dcb[idx]]) >> 16] & 0xf8) << 2)
                        | ((yp[Crrtab[dcb[idx]]] & 0xf8) >> 3)
                        | ((yp[Cbbtab[dcr[idx]]] & 0xf8) << 7)
                        | 0x8000;
                    d[off] = v;
                    d[off + 1] = v >> 8;
                    off += 2;
                }
            }
        }
        break;

    case 5:
        t = e = 0;
        for (; t < bcode2.f04; t++) {
            for (s = 0; s < 8; s++) {
                if (s + y + t * 8 >= dy)
                    break;
                off = 2 * (dx * (s + y + t * 8) + x);
                for (j = 0; j < 8; j++, e++) {
                    if (x + j >= dx)
                        break;
                    idx = j + (s >> 1) * 8 + t * 32;
                    yp = limits + draw_block[e];
                    v = ((yp[(Cbgtab[dcr[idx]] + Crgtab[dcb[idx]]) >> 16] & 0xf8) << 2)
                        | ((yp[Crrtab[dcb[idx]]] & 0xf8) >> 3)
                        | ((yp[Cbbtab[dcr[idx]]] & 0xf8) << 7)
                        | 0x8000;
                    d[off] = v;
                    d[off + 1] = v >> 8;
                    off += 2;
                }
            }
        }
        break;

    case 6:
        c = e = 0;
        for (; c < bcode2.f04; c++) {
            for (d2 = 0; d2 < bcode2.f14; d2++) {
                for (s = 0; s < 8; s++) {
                    if (s + y + c * 8 >= dy)
                        break;
                    off = 2 * (dx * (s + y + c * 8) + x + d2 * 8);
                    for (j = 0; j < 8; j++, e++) {
                        if (x + d2 * 8 + j >= dx)
                            break;
                        idx = (j >> 1) + d2 * 4 + (s >> 1) * 8 + c * 32;
                        yp = limits + draw_block[e];
                        v = ((yp[(Cbgtab[dcb[idx]] + Crgtab[dcr[idx]]) >> 16] & 0xf8) << 2)
                            | ((yp[Crrtab[dcr[idx]]] & 0xf8) >> 3)
                            | ((yp[Cbbtab[dcb[idx]]] & 0xf8) << 7)
                            | 0x8000;
                        d[off] = v;
                        d[off + 1] = v >> 8;
                        off += 2;
                    }
                }
            }
        }
        break;

    default:
        break;
    }
}
