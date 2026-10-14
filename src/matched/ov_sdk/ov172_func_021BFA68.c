/*
 * function: writeblock
 * address:  0x021BFA68
 * packet:   pkt_ov172_021BFA68
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 * retry:    wave8 lane re-attempted the scope lever: moved every case's locals
 *           into per-case blocks with order e,off,j,m,n (case4) / e,off,j,s,t
 *           (case5) / e,off,j,d2,c,s (case6) / i,off,j,z (case3).  Case 3 now
 *           colours z=sb j=r8 off=r7 (was r7/sb/r8) and the diff drops to 1083
 *           concrete bytes, but the frame is still 0x30 and `m` still spills:
 *           the original hoists one table base into `lr` out of the case-3
 *           loops whereas compiled wants `lr` for `limits`, so the whole case
 *           recolours.  A declaration-order/scope sweep is the remaining lever
 *           (see declaration-position-orders-block-scope-colouring).
 *
 * retry:    wave8b lane decoded the pools: the case-3 `lr` base the original
 *           hoists is draw_block (pool @0x021BFFA4 = 0x021C8D9C), not dcb/dcr;
 *           the original case-4 keeps `m` in `lr` and reloads every table base
 *           per iteration, whereas compiled holds `limits` live function-wide
 *           in `lr` and therefore spills `m` to [sp+0x2c] (frame 0x30, push r3).
 *           Tried and all left size 1412 / m spilled / diff 1082-1112: reversing
 *           `limits + draw_block[e]` evaluation order, named draw_block/limits
 *           base pointers in case3, a per-case `lim` pointer in case4, and an
 *           8-way case-4 declaration-order sweep.  Remaining lever: stop the
 *           function-wide `limits` base from claiming `lr` so `m` can take it.
 *
 * 2026-10-01 (lane03): REWRITTEN to the DWARF. writeblock has exactly seven
 *           function-scope locals (rr, z, t, s, n, m, e; no block locals), so
 *           the per-case blocks were stand-ins. The four cases are copies with
 *           one role per name: n row, m column, z draw_block counter, e byte
 *           offset, s horizontal block, t vertical block. rr is reused: the
 *           chroma index, then the packed pixel (case 3: the draw_block
 *           sample, then the pixel; that makes the case-3 loop hoist
 *           draw_block into lr as the image does). An index spelled as an
 *           expression is strength-reduced (+200 B), and an inline helper
 *           hoists limits instead. G is `Crgtab[dcb] + Cbgtab[dcr]`. Case 5/6
 *           offsets reuse the guard's sum `n + (y + t * 8)`. Case 6 uses the
 *           same tables as case 3 (the old "swap" note was wrong). Now 1372/1372
 *           B, every loop, frame slot and DWARF home as the image (e r7, m r8,
 *           z r9, n/t/s at sp+1c/20/24, rr r0); 113 concrete (was 1083).
 *           Residue: in each pixel body the image schedules the R chain
 *           (dcb, Crrtab) before the B chain (dcr, Cbbtab), ours the reverse,
 *           so r4/r5 trade places and the dcb/dcr pool words swap; plus the
 *           bcode2/dy prologue order. All six R/G/B term orders measured, RGB
 *           and GRB best. The four Cxxtab words stay wildcarded (no witness).
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
 * 2026-10-01 (lane 14): still 113 B.  Pool order is the scheduled first-use
 *   order; G spelled `Cbgtab[dcr] + Crgtab[dcb]` gives the image's pool order but
 *   rescheduled the bodies (398 B; with the six R/G/B term orders 124..405 B).
 *   Inert at 113: the object's data defined in the file (dcb/dcr/draw_block
 *   globals, limits/Cxx tables as statics, and bcode2 as the 4-byte global it is
 *   in jpegdec.o with the f04/f14 words as neighbouring 4-byte globals laid out
 *   at +4/+0x14), `limits[X + base]` index order, switch operand order.
 *
 * 2026-10-01 (w3 lane19): still 113 B. Vendor .o symtab: bcode2+4 is yblock,
 *   bcode2+0x14 is xblock (4-byte .bss group), and the limits pool word is
 *   limits+0x100 (source biases the index by 256); 1.1p1 never folds that
 *   bias into the pool (`limits[256 + i]`, `(limits + 256)[i]`, `&limits[256]`,
 *   2-D: all keep `ldrb [rX, #0x100]`, 1420 B). Renaming dcb/dcr and the four
 *   tables (mirror) compiles identically, so names/decl order are not the tie.
 *   G = `Cbgtab[dcr] + Crgtab[dcb]` with OR order B,G,R (or G,B,R) gives the
 *   image's load order and pool order (9/9 relocs) but combines (G|B) then R:
 *   124 B. const tables, per-term `limits[X + Y]` order, mask/shift spellings
 *   and OR parenthesisation (reassociated) measured flat or worse.
 *
 * 2026-10-01 (w4): EXACT. Decoded the vendor .debug_line: line 2059 (before
 *   the switch) loads limits+0x100, so the source has a top-level pointer
 *   local `lim = limits + 256` that copy propagation removes from DWARF (it
 *   also fixes the prologue order). Per pixel the line table shows separate
 *   statements: chroma index into rr, R kept in rr, G and B as single-use
 *   locals forward-substituted into the pack `rr = (rr >> 3) | (g << 2) |
 *   (b << 7) | 0x8000` (only their shared loads keep their own line).
 *   Chroma samples are read into locals cb/cr before rr is reused for R.
 *   g, b, cb, cr and lim all vanish from DWARF, as the image's seven-local
 *   list requires. G is `Cbgtab[cr] + Crgtab[cb]`.
 *
 * symbols:
 *   bcode2      0x021C88F0  data
 *   draw_block  0x021C8D9C  data
 *   dcb         0x021C891C  data
 *   dcr         0x021C899C  data
 *   limits      0x021C7F2C  data
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

void writeblock(u8 *d, int x, int y, int dx, int dy)
{
    int e, m, n, s, t, z, rr;
    int g, b, cb, cr;
    u8 *lim = limits + 256;

    switch (bcode2.f04 * 2 + bcode2.f14) {
    case 3:
        for (n = z = 0; n < 8; n++) {
            if (y + n >= dy)
                return;
            e = 2 * (dx * (y + n) + x);
            for (m = 0; m < 8; m++, z++, e += 2) {
                if (x + m >= dx)
                    break;
                cb = dcb[z];
                cr = dcr[z];
                rr = lim[draw_block[z] + Crrtab[cb]] & 0xf8;
                g = lim[draw_block[z] + ((Cbgtab[cr] + Crgtab[cb]) >> 16)] & 0xf8;
                b = lim[draw_block[z] + Cbbtab[cr]] & 0xf8;
                rr = (rr >> 3) | (g << 2) | (b << 7) | 0x8000;
                d[e] = rr;
                d[e + 1] = rr >> 8;
            }
        }
        break;

    case 4:
        for (s = z = 0; s < bcode2.f14; s++) {
            for (n = 0; n < 8; n++) {
                if (y + n >= dy)
                    break;
                e = 2 * (dx * (y + n) + x + s * 8);
                for (m = 0; m < 8; m++, z++, e += 2) {
                    if (m + (x + s * 8) >= dx)
                        break;
                    rr = (m >> 1) + s * 4 + n * 8;
                    cb = dcb[rr];
                    cr = dcr[rr];
                    rr = lim[draw_block[z] + Crrtab[cb]] & 0xf8;
                    g = lim[draw_block[z] + ((Cbgtab[cr] + Crgtab[cb]) >> 16)] & 0xf8;
                    b = lim[draw_block[z] + Cbbtab[cr]] & 0xf8;
                    rr = (rr >> 3) | (g << 2) | (b << 7) | 0x8000;
                    d[e] = rr;
                    d[e + 1] = rr >> 8;
                }
            }
        }
        break;

    case 5:
        for (t = z = 0; t < bcode2.f04; t++) {
            for (n = 0; n < 8; n++) {
                if (n + (y + t * 8) >= dy)
                    break;
                e = 2 * (dx * (n + (y + t * 8)) + x);
                for (m = 0; m < 8; m++, z++, e += 2) {
                    if (x + m >= dx)
                        break;
                    rr = m + (n >> 1) * 8 + t * 32;
                    cb = dcb[rr];
                    cr = dcr[rr];
                    rr = lim[draw_block[z] + Crrtab[cb]] & 0xf8;
                    g = lim[draw_block[z] + ((Cbgtab[cr] + Crgtab[cb]) >> 16)] & 0xf8;
                    b = lim[draw_block[z] + Cbbtab[cr]] & 0xf8;
                    rr = (rr >> 3) | (g << 2) | (b << 7) | 0x8000;
                    d[e] = rr;
                    d[e + 1] = rr >> 8;
                }
            }
        }
        break;

    case 6:
        for (t = z = 0; t < bcode2.f04; t++) {
            for (s = 0; s < bcode2.f14; s++) {
                for (n = 0; n < 8; n++) {
                    if (n + (y + t * 8) >= dy)
                        break;
                    e = 2 * (dx * (n + (y + t * 8)) + x + s * 8);
                    for (m = 0; m < 8; m++, z++, e += 2) {
                        if (m + (x + s * 8) >= dx)
                            break;
                        rr = (m >> 1) + s * 4 + (n >> 1) * 8 + t * 32;
                        cb = dcb[rr];
                        cr = dcr[rr];
                        rr = lim[draw_block[z] + Crrtab[cb]] & 0xf8;
                        g = lim[draw_block[z] + ((Cbgtab[cr] + Crgtab[cb]) >> 16)] & 0xf8;
                        b = lim[draw_block[z] + Cbbtab[cr]] & 0xf8;
                        rr = (rr >> 3) | (g << 2) | (b << 7) | 0x8000;
                        d[e] = rr;
                        d[e + 1] = rr >> 8;
                    }
                }
            }
        }
        break;
    }
}
