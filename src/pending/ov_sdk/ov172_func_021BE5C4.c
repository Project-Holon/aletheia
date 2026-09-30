/*
 * function: func_021BE5C4
 * address:  0x021BE5C4
 * packet:   pkt_ov172_021BE5C4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  codegen / register allocation.  Full marker walker reconstructed
 *           (SOI, APP1/Exif, SOF0/1, DHT table build, SOS MCU loops, DQT,
 *           DRI); it compiles to 2468 bytes against the original 2548 and all
 *           21 relocations resolve, but register allocation, loop-invariant
 *           materialisation and the shared epilogue differ throughout (2092
 *           of ~2480 concrete bytes).  Two fast-Huffman-table bounds checks
 *           on pool constants 0xfffff3d2 / 0x00000bd3 are omitted because
 *           they are dead for any in-range code (ip < 256).  Semantics follow
 *           the listing; byte-exact needs the original source shape.
 *
 *           The object DWARF (tools/sdkobj.py 0x021BE5C4 --brief) gives that
 *           shape and is the way in for the next lane:
 *             prototype: static int Mel_JPEGDecode(unsigned char *d,
 *                unsigned char *a, unsigned long length, long maxWidth,
 *                long maxHeight, int option)
 *             locals (DWARF print order, offsets are frame base):
 *               result r0; huffsize char[257] [fb+76]; huffcode u16[257]
 *               [fb+334]; b u8 r0; RSTn_work [fb+24]; RSTn_intr [fb+28];
 *               y r14; x r12; s r0; q r0; p [fb+72]; m r1; j r0; i r0;
 *               g r4 (bcode2 base, pool_021BEF80); h r6; dy [fb+32];
 *               dx [fb+36] (dy/dx are the SOF height/width locals)
 *             frame is fixed by huffcode@0x14E + 0x202 = 0x350.
 *           Lever already applied: spelling `u16 huffcode[257];` before
 *           `char huffsize[257];` moved the frame 0x348 -> 0x350 and matched
 *           the entry prologue (2098 -> 2092 differing bytes).  The body still
 *           uses guessed names (marker/seglen/k, width/height) instead of the
 *           DWARF set, so the allocation stays wrong.  Rebuild the declaration
 *           list and the marker-arm temporaries from the DWARF list and the
 *           per-arm register colour, not from the disassembly text.
 *           See docs/idioms/draft-sdk-declarations-from-the-object-dwarf.md.
 *
 * sdk:      Mel_JPEGDecode (libssp.TWL.HYB.a jpegdec.o)
 *
 * Full baseline JPEG decoder driver: validates SOI, then walks marker
 * segments (APP1/Exif, SOF0/1, DHT, SOS, DQT, DRI) and runs the MCU decode
 * loops through getmatrix/decode_block/writeblock.  Reconstructed from the
 * vendor disassembly; the two fast-Huffman-table bounds checks and the exact
 * register allocation are not reproduced (see blocker in the header).
 *
 * symbols:
 *   bcode2           0x021C88F0  data
 *   mtx              0x021C8B1C  data
 *   jw               0x021C959C  data
 *   qy               0x021C8A1C  data
 *   asl              0x021C72AC  data
 *   zig              0x021C726C  data
 *   draw_block       0x021C8D9C  data
 *   dcr              0x021C899C  data
 *   dcb              0x021C891C  data
 *   MIi_CpuClearFast 0x02082AC0  arm
 *   SSP_ExifDecode   0x021C0BB4  arm  ov172
 *   func_021BEFB8    0x021BEFB8  arm  ov172
 *   func_021BF15C    0x021BF15C  arm  ov172
 *   func_021BFA68    0x021BFA68  arm  ov172
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s32 byte;    /* +0x00 */
    s32 f04;     /* +0x04 V sampling factor */
    s32 length;  /* +0x08 input length */
    s32 esc;     /* +0x0c escape flag */
    s32 bits;    /* +0x10 bits available */
    s32 f14;     /* +0x14 H sampling factor */
    u8 *p1;      /* +0x18 huffman table base */
    s32 err;     /* +0x1c error flag */
    s32 *p2;     /* +0x20 huffman table base */
    s32 f24;     /* +0x24 H*8 */
    s32 f28;     /* +0x28 V*8 */
} BCode2;

extern BCode2 bcode2;
extern s16 mtx[5][64];
extern u8 jw[6144];
extern s16 qy[256];
extern s16 asl[64];
extern u8 zig[64];
extern s16 draw_block[1024];
extern s16 dcr[64];
extern s16 dcb[64];

extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern long SSP_ExifDecode(u8 *src, u32 src_size, int *cur, int option);
extern void func_021BEFB8(u8 *g, s16 *d, int *p, int n);
extern void func_021BF15C(s16 *d, s16 n);
extern void func_021BFA68(u8 *d, int x, int y, int dx, int dy);

int func_021BE5C4(u8 *d, u8 *a, u32 length, int maxWidth, int maxHeight,
                  int option)
{
    u16 huffcode[257];
    char huffsize[257];
    int RSTn_work = 0;
    int RSTn_intr = 0;
    int width = 0;
    int height = 0;
    int p;
    int marker;
    int seglen;
    int s;
    int i, j, k;
    int x, y;
    long result;

    bcode2.esc = 0;
    bcode2.bits = 0;
    mtx[4][0] = 0;
    mtx[3][0] = 0;
    mtx[0][0] = 0;
    MIi_CpuClearFast(0, jw, 0x1000);
    bcode2.length = length;
    if (length <= 2)
        return 0;
    if (a[0] != 0xff || a[1] != 0xd8)
        return 0;

    p = 2;
    while (p + 1 < length) {
        s = a[p++];
        if (s != 0xff)
            continue;
        marker = a[p++];
        if (marker == 0xd9)
            break;
        if (p + 1 >= length)
            return 0;
        seglen = (a[p] << 8) | a[p + 1];

        switch (marker) {
        case 0xc0:
        case 0xc1:  /* SOF0 / SOF1 */
            if (p + 9 >= length)
                return 0;
            if (a[p + 9] != 0x11 && a[p + 9] != 0x21
                && a[p + 9] != 0x12 && a[p + 9] != 0x22)
                return 0;
            height = (a[p + 4] << 8) | a[p + 3];
            width = (a[p + 6] << 8) | a[p + 5];
            bcode2.f14 = a[p + 9] >> 4;
            bcode2.f04 = a[p + 9] & 0xf;
            bcode2.f24 = (a[p + 9] >> 4) * 8;
            bcode2.f28 = (a[p + 9] & 7) * 8;
            p += seglen;
            if (width > maxWidth || height > maxHeight)
                return 0;
            break;

        case 0xe1:  /* APP1 */
            result = SSP_ExifDecode(a, length, &p, option);
            if (result == 0 || result == 1)
                break;
            return 0;

        case 0xc4: {  /* DHT */
            int cursor = p + 2;
            if (cursor >= length)
                return 0;
            p += seglen;
            while (cursor < p) {
                int toff, soff, total, cnt, T;
                int n;
                if (cursor + 0x11 >= length)
                    return 0;
                T = a[cursor++];
                toff = 0;
                soff = 0;
                if (T & 1) {
                    toff = 0x138;
                    soff = 0x560;
                }
                if (T & 0x10) {
                    toff += 0x24;
                    soff += 0x2b0;
                }
                bcode2.p1 = jw + soff + 0x270;
                bcode2.p2 = (s32 *)bcode2.p1;
                jw[toff] = 0;
                total = 0;
                for (k = 1; k <= 16; k++) {
                    cnt = a[cursor++];
                    jw[toff + k] = cnt;
                    total += cnt;
                }
                if (cursor + total >= length)
                    return 0;
                for (k = 0; k < total; k++)
                    jw[toff + 0x14 + k] = a[cursor++];

                n = 0;
                for (k = 1; k <= 16; k++) {
                    for (i = 1; i <= jw[toff + k]; i++) {
                        if (n <= 0x100)
                            huffsize[n++] = (char)k;
                    }
                }
                if (n >= 0x101) {
                    bcode2.err = 1;
                    return 0;
                }
                huffsize[n] = 0;
                {
                    int code = 0;
                    int si = huffsize[0];
                    k = 0;
                    while (huffsize[k] != 0) {
                        if (huffsize[k] != si)
                            goto nextsi;
                        do {
                            huffcode[k++] = (u16)code;
                            if (k >= 0x101) {
                                bcode2.err = 1;
                                return 0;
                            }
                            code++;
                        } while (huffsize[k] == si);
nextsi:
                        code <<= 1;
                        si++;
                    }
                }
                {
                    int idx = 0;
                    for (k = 1; k <= 16; k++) {
                        if (jw[toff + k] == 0) {
                            bcode2.p2[0x11 + k] = -1;
                            continue;
                        }
                        ((s16 *)bcode2.p1)[0x46 + k] = (s16)idx;
                        bcode2.p2[k] = huffcode[idx];
                        idx += jw[toff + k];
                        if (idx >= 0x101) {
                            bcode2.err = 1;
                            return 0;
                        }
                        bcode2.p2[0x11 + k] = huffcode[idx - 1];
                    }
                    bcode2.p2[0x22] = 0xFFFFF;
                }
                {
                    u8 *base = jw + soff;
                    int idx = 0;
                    for (k = 1; k <= 8; k++) {
                        int step = 1 << (8 - k);
                        int cnt = jw[toff + k];
                        int m;
                        for (m = 0; m < cnt; m++) {
                            int ip = huffcode[idx] << (8 - k);
                            int q2;
                            for (q2 = 0; q2 < step; q2++) {
                                base[0x31e + ip] = (u8)k;
                                base[0x41e + ip] = jw[toff + 0x14 + idx];
                                ip++;
                            }
                            idx++;
                        }
                    }
                }
            }
            break;
        }
        case 0xd8:  /* SOI */
            break;

        case 0xda: {  /* SOS */
            if (p + 0xc >= length)
                return 0;
            p += 0xc;
            if (height > 0) {
                do {
                    x = 0;
                    if (width > 0) {
                        do {
                            if (RSTn_intr != 0) {
                                if (--RSTn_work == 0) {
                                    RSTn_work = RSTn_intr;
                                    if (bcode2.bits > 7)
                                        p = p - bcode2.esc - 1;
                                    p += 2;
                                    bcode2.bits = 0;
                                    mtx[4][0] = 0;
                                    mtx[3][0] = mtx[4][0];
                                    mtx[0][0] = mtx[4][0];
                                }
                            }
                            for (i = 0; i < bcode2.f14 * bcode2.f04; i++) {
                                func_021BEFB8(a, mtx[0], &p, 0);
                                func_021BF15C(draw_block + i * 64, 0);
                            }
                            func_021BEFB8(a, mtx[3], &p, 2);
                            func_021BF15C(dcr, 3);
                            func_021BEFB8(a, mtx[4], &p, 2);
                            func_021BF15C(dcb, 4);
                            func_021BFA68(d, x, y, width, height);
                            x += bcode2.f24;
                        } while (x < width);
                    }
                    y += bcode2.f28;
                } while (y < height);
            }
            goto end;
        }

        case 0xdb: {  /* DQT */
            int q = p + 2;
            int end = p + seglen;
            p = end;
            while (q < end) {
                int T = a[q];
                int k2;
                if (T & 0xf0) {
                    int tbl = (T & 0xf) << 6;
                    q++;
                    if (q + 0x82 >= length)
                        return 0;
                    for (k2 = 0; k2 < 64; k2++) {
                        int z = zig[k2];
                        int v;
                        if (tbl + z > 0x7f)
                            return 0;
                        v = (a[q + 1] << 8) | a[q];
                        q += 2;
                        qy[tbl + z] = (asl[k2] * v + 0x800) >> 12;
                    }
                } else {
                    int tbl = (T & 0xf) << 6;
                    q++;
                    if (q + 0x41 >= length)
                        return 0;
                    for (k2 = 0; k2 < 64; k2++) {
                        int z = zig[k2];
                        if (tbl + z > 0x7f)
                            return 0;
                        qy[tbl + z] = (a[q] * asl[k2] + 0x800) >> 12;
                        q++;
                    }
                }
            }
            break;
        }

        case 0xdd:  /* DRI */
            if (p + 3 >= length)
                return 0;
            RSTn_intr = (a[p + 2] << 8) | a[p + 3];
            p += seglen;
            RSTn_work = RSTn_intr + 1;
            break;

        default:
            p += seglen;
            break;
        }
    }
end:
    if ((u32)p > length)
        return 0;
    return width | (height << 16);
}
