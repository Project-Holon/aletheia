/*
 * file:     jpegdec.c
 * unit:     yes
 * function: Mel_JPEGDecodeExif, Mel_JPEGDecode, getmatrix, get_matrix_sub, decode_block, decode_block_sub, loadbit, hloadbit, writeblock, SSP_StartJpegDecoder
 * address:  0x021BE468
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   bcode2            0x021C88F0  data
 *   yblock            0x021C88F4  data
 *   SSPiInputDataSize 0x021C88F8  data
 *   chit              0x021C88FC  data
 *   bitlen            0x021C8900  data
 *   xblock            0x021C8904  data
 *   ts                0x021C8908  data
 *   SSPiErrorFlag     0x021C890C  data
 *   ti                0x021C8910  data
 *   xstep             0x021C8914  data
 *   ystep             0x021C8918  data
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   SSP_ExifDecode    0x021C0BB4  arm  ov172
 *   mtx               0x021C8B1C  data ov172
 *   jw                0x021C959C  data ov172
 *   qy                0x021C8A1C  data
 *   asl               0x021C72AC  data
 *   zig               0x021C726C  data
 *   draw_block        0x021C8D9C  data
 *   dcr               0x021C899C  data
 *   dcb               0x021C891C  data
 *   gJpegIdctBlock        0x021C8B9C  data
 *   gJpegDecodeClampTable        0x021C80AC  data
 *   ntbl              0x021C725C  data
 *   limits            0x021C7F2C  data
 *   Crrtab            0x021C752C  data
 *   Crgtab            0x021C7B2C  data
 *   Cbbtab            0x021C732C  data
 *   Cbgtab            0x021C772C  data
 *   OS_IsRunOnTwl           0x02085D3C  arm
 *   MI_CpuCopy8             0x02082D44  arm
 *   MI_CpuFill8             0x02082BCC  arm
 *   AESi_Init               0x027073AC  arm
 *   AESi_VerifySignForJpeg  0x0270788C  arm
 *   SSPiDecodeSignCheckMode 0x021CADA4  data ov172
 */

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/*
 * jpegdec.o .bss block; declaration order gives the vendor offsets.
 * bcode2 +0x00 (the bit buffer), yblock +0x04, SSPiInputDataSize +0x08,
 * chit +0x0c (set after an 0xff byte), bitlen +0x10, xblock +0x14, ts +0x18,
 * SSPiErrorFlag +0x1c, ti +0x20, xstep +0x24, ystep +0x28.
 */
static int xstep = 0;
static int *ti = 0;
static int SSPiErrorFlag = 0;
static short *ts = 0;
static int xblock = 0;
static int bitlen = 0;
static int chit = 0;
static unsigned long SSPiInputDataSize = 0;
static int yblock = 0;
static int bcode2 = 0;
static int ystep = 0;

extern void MIi_CpuClearFast(unsigned long data, void *destp, unsigned long size);
extern long SSP_ExifDecode(u8 *src, unsigned long src_size, int *cur, int option);
extern int OS_IsRunOnTwl(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void AESi_Init(void);
extern int AESi_VerifySignForJpeg(unsigned char *sign, unsigned int data, unsigned int length);
extern int SSPiDecodeSignCheckMode;
extern short mtx[5][64];
extern u8 jw[6144];
extern short qy[128];
extern short asl[64];
extern u8 zig[64];
extern short draw_block[1024];
extern short dcr[64];
extern short dcb[64];
extern short gJpegIdctBlock[64];
extern unsigned char gJpegDecodeClampTable[];
extern int ntbl[4];
extern u8 limits[];
extern s16 Crrtab[256];
extern s32 Crgtab[256];
extern s16 Cbbtab[256];
extern s32 Cbgtab[256];

int Mel_JPEGDecodeExif(u8 *a, unsigned long length, int option);
int Mel_JPEGDecode(u8 *d, u8 *a, unsigned long length, long maxWidth, long maxHeight, int option);
void getmatrix(unsigned char *g, short *d, int *p, int n);
int get_matrix_sub(unsigned char *s, int *p, int ax, int cx);
void decode_block(short *d, short n);
void decode_block_sub(short *s, short *d, int n);
int loadbit(u8 *data, int *pos);
int hloadbit(u8 *b, int *p, int n);
void writeblock(u8 *d, int x, int y, int dx, int dy);


/*
 * Mel_JPEGDecodeExif notes (from the old part 1)
 *
 * wave7: sdkobj confirms the object is Metrowerks 4.0.0.1024 -> dsi/1.1p1 and its
 *        322-byte listing is byte-identical to the image, with DWARF locals
 *        result(r0), b(r0), s(r0), p([fb+0]) (reverse source: p, s, b, result),
 *        which the draft already matches.  The residue is confined to the three
 *        table clears: the image materialises each pointer immediately before
 *        its own strh and assigns r3=D, r0=C, r2=B, ours hoists the three ldrs
 *        (r0, r2, r3) and sinks the B store past the MIi_CpuClearFast argument
 *        setup.  The 6 chain permutations and 5 other clear-block spellings
 *        already measured here stay at 21-31; wave7 found no source shape for
 *        the interleave under 1.1p1.
 *
 * sdk:      Mel_JPEGDecodeExif (libssp.TWL.HYB.a jpegdec.o)
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   SSP_ExifDecode  0x021C0BB4  arm  ov172
 *   gJpegDecodeState     0x021C88F0  data
 *   gJpegDecodeQuantTable     0x021C8D1C  data ov172
 *   gJpegDecodeAcTable     0x021C8C1C  data ov172
 *   gJpegDecodeDcTable     0x021C8B1C  data ov172
 *   gJpegDecodeExifState     0x021C959C  data ov172
 *
 * Static: clears the decoder state, validates the SOI marker and walks the marker segments until
 * the APP1 (Exif) segment, which SSP_ExifDecode parses.
 *
 * Lane U8 (2026-09-30): the three table clears are written in the order the image's *literal pool*
 * holds them (0x021C8C1C, 0x021C8B1C, 0x021C8D1C), not the order the image's `strh` stores run in.
 * With that order our pool AND our store order both come out exactly as the image's (the previous
 * order had the pool rotated and the stores reversed, which is what the "pool vs stores" note in
 * docs/notes/lane_t9_ov172_sdk_rows.md was recording). 34 -> 31 concrete bytes; the whole body from
 * +0x4C on was and stays byte-identical.
 * Residue: the prologue block only, two clusters.
 *   +0x0014  image `mov r8, r0` | ours `mov r6, r2`   (parameter home-copies come out in the
 *            order option, length, a; the image uses a, option, length. Same destination registers.)
 *   +0x0020  image `ldr r3, [pc, #0x124]` | ours `ldr r2, [pc, #0x124]`  (which register each of the
 *            four prologue pointers lands in, and the interleave of loads/stores: the image keeps
 *            `mov r0, r5` / `mov r2, #0x1000` for the call at +0x40/+0x44, ours hoists them to
 *            +0x38/+0x3C, which is why r0 is not free for the third pointer.)
 * Tried and rejected this lane (all compile, none below 31): every permutation of the three clears
 * (6), the call moved before/inside the clears, `bits = 0` moved after the clears, three spellings
 * of the call arguments, a comma-joined clear statement, and two local declaration orders.
 * Declaration order is confirmed by DWARF (locals listed result, b, s, p = reverse source order).
 *
 * Lane U67 (2026-09-30): the three clears are a *chained assignment*
 *   `gJpegDecodeAcTable[0x40] = gJpegDecodeQuantTable[0] = gJpegDecodeDcTable[0] = 0;`
 * That single change fixed the parameter home-copies (+0x14..+0x1C now `mov r8,r0` / `mov r6,r2` /
 * `mov r7,r1` exactly as the image) and keeps the correct literal pool and store order; 31 -> 21
 * concrete bytes.  Measured over all 6 chain permutations (21/22/23/23/24 diffs; only the
 * `C1C = D1C = B1C` order gives the image's pool D,C,B *and* store order D,C,B — and only the chained
 * form reproduces the image's home-copy order at all; the same order written as three statements
 * gives the right pool/stores but the copies come out option,length,a for 31).
 * Remaining 21 bytes, all inside the clear block at +0x20..+0x44: the image materialises each
 * pointer immediately before its own `strh` (ldr r3/sth, ldr r0/sth, ldr r2/sth, then the call's
 * `mov r0,r5` / `mov r2,#0x1000`), ours issues the three `ldr`s first and sinks the second and third
 * `strh` past the call-argument setup.  Register rotation is a consequence: image r3,r0,r2 | ours
 * r0,r2,r3.  `bits = 0` before vs after the chain, parenthesised/cast forms of the chain and the
 * esc/bits store order do not move it.
 */

int Mel_JPEGDecodeExif(u8 *a, unsigned long length, int option)
{
    int p;
    int s;
    unsigned char b;
    long result;

    chit = 0;
    bitlen = 0;
    mtx[0][0] = mtx[3][0] = mtx[4][0] = 0;
    MIi_CpuClearFast(0, jw, 0x1000);
    SSPiInputDataSize = length;
    if (length <= 2) return 0;
    if (a[0] != 0xFF || a[1] != 0xD8) return 0;
    p = 2;
    while ((unsigned long)(p + 1) < length) {
        s = a[p++];
        if (s == 0xFF) {
            b = a[p++];
            if (b == 0xD9) break;
            if ((unsigned long)(p + 1) >= length) return 0;
            s = (a[p] << 8) | a[p + 1];
            if (b == 0xE1) {
                result = SSP_ExifDecode(a, length, &p, option);
                if (result != 0 && result != 1) return 0;
                break;
            }
            p += s;
        }
    }
    return -(p <= SSPiInputDataSize);
}

/*
 * closed (lane05, 2026-10-01): full rewrite from the listing and DWARF.
 *   (1) the "bcode2 struct" is eleven separate 4-byte .bss objects of
 *   jpegdec.o (bcode2, yblock, SSPiInputDataSize, chit, bitlen, xblock, ts,
 *   SSPiErrorFlag, ti, xstep, ystep at +0..+0x28) addressed off one anchor.
 *   Defined here as zero-initialised file statics, declared in the order that
 *   reproduces the vendor offsets (1.1p1 puts the last declared at the end
 *   and the rest in reverse). As separate objects the main-loop length check
 *   reloads after the p stores, `cmp length,#3` folds at loop entry and the
 *   RST bitlen store stays behind the p update; the struct spelling got none
 *   of the three. (2) Variable identity per phase settles the DHT colours
 *   (toff=i, soff=m, loop index h, k=g, code gen j/g/s); DQT uses s/j/i.
 *   (3) for-step increments: `i++, q += 2` in DQT, `j++, g++` in the code
 *   tables, `y--, x++` in the fill loop, `h++, q++` for the value copy.
 *   (4) `a[q + 1] + (a[q] << 8)` for the 16-bit DQT entries.
 *
 * sdk:      Mel_JPEGDecode (libssp.TWL.HYB.a jpegdec.o)
 *
 * Baseline JPEG decoder driver: validates SOI, then walks marker segments
 * (APP1/Exif, SOF0/1, DHT, SOS, DQT, DRI) and runs the MCU decode loops
 * through getmatrix/decode_block/writeblock.
 */
int Mel_JPEGDecode(u8 *d, u8 *a, unsigned long length, long maxWidth,
                  long maxHeight, int option)
{
    int dx;
    int dy;
    int h;
    int g;
    int i;
    int j;
    int m;
    int p;
    int q;
    int s;
    int x;
    int y;
    int RSTn_intr;
    int RSTn_work;
    u8 b;
    unsigned short huffcode[257];
    char huffsize[257];
    long result;

    dx = 0;
    chit = 0;
    bitlen = 0;
    mtx[4][0] = dx;
    mtx[3][0] = dx;
    dy = dx;
    RSTn_work = dx;
    mtx[0][0] = dx;
    RSTn_intr = dx;
    MIi_CpuClearFast(0, jw, 0x1000);
    SSPiInputDataSize = length;
    if (length <= 2)
        return dx;
    if (a[0] != 0xff || a[1] != 0xd8)
        return 0;

    p = 2;
    while (p + 1 < SSPiInputDataSize) {
        if (a[p++] != 0xff)
            continue;
        b = a[p++];
        if (b == 0xd9)
            break;
        if (p + 1 >= SSPiInputDataSize)
            return 0;
        s = (a[p] << 8) | a[p + 1];
        if (b == 0xe1) {
            result = SSP_ExifDecode(a, SSPiInputDataSize, &p, option);
            if (result != 0 && result != 1)
                return 0;
        } else if (b == 0xc0 || b == 0xc1) {
            if (p + 9 >= SSPiInputDataSize)
                return 0;
            dy = (a[p + 3] << 8) | a[p + 4];
            dx = (a[p + 5] << 8) | a[p + 6];
            m = a[p + 9];
            p += s;
            if (m != 0x11 && m != 0x21 && m != 0x12 && m != 0x22)
                return 0;
            xblock = m >> 4;
            yblock = m & 0xf;
            xstep = (m >> 4) << 3;
            ystep = (m & 0xf) << 3;
            if (dx > maxWidth || dy > maxHeight)
                return 0;
        } else if (b == 0xc4) {
            q = p + 2;
            if (q >= SSPiInputDataSize)
                return 0;
            p += s;
            while (q < p) {
                if (q + 17 >= SSPiInputDataSize)
                    return 0;
                b = a[q++];
                i = 0;
                m = 0;
                if (b & 1) {
                    m += 0x560;
                    i += 0x138;
                }
                if (b & 0x10) {
                    m += 0x2b0;
                    i += 0x24;
                }
                ts = (short *)&jw[m + 0x270];
                ti = (int *)&jw[m + 0x270];
                jw[i] = 0;
                for (h = 1, j = 0; h <= 16; h++) {
                    b = a[q++];
                    jw[i + h] = b;
                    j += b;
                }
                if (q + j >= SSPiInputDataSize)
                    return 0;
                for (h = 0; h < j; h++, q++)
                    jw[i + 0x14 + h] = a[q];
                g = 0;
                for (h = 1; h <= 16; h++) {
                    for (j = 1; j <= jw[i + h] && g <= 256; j++, g++)
                        huffsize[g] = (char)h;
                }
                if (g >= 257) {
                    SSPiErrorFlag = 1;
                    return 0;
                }
                huffsize[g] = 0;
                j = 0;
                g = huffsize[0];
                s = 0;
                while (huffsize[s] != 0) {
                    while (huffsize[s] == g) {
                        huffcode[s++] = j++;
                        if (s >= 257) {
                            SSPiErrorFlag = 1;
                            return 0;
                        }
                    }
                    j <<= 1;
                    g++;
                }
                g = 0;
                for (j = 1; j <= 16; j++) {
                    if (jw[i + j] != 0) {
                        ts[j + 0x46] = g;
                        ti[j] = huffcode[g];
                        g += jw[i + j];
                        if (g >= 257) {
                            SSPiErrorFlag = 1;
                            return 0;
                        }
                        ti[17 + j] = huffcode[g - 1];
                    } else {
                        ti[17 + j] = -1;
                    }
                }
                ti[34] = 0xfffff;
                g = 0;
                for (h = 1; h <= 8; h++) {
                    for (j = 1; j <= jw[i + h]; j++, g++) {
                        if (g >= 257) {
                            SSPiErrorFlag = 1;
                            return 0;
                        }
                        x = huffcode[g] << (8 - h);
                        if (x < -3118 || x + (1 << (8 - h)) >= 3027) {
                            SSPiErrorFlag = 1;
                            return 0;
                        }
                        for (y = 1 << (8 - h); y > 0; y--, x++) {
                            if (m + 0x31e + x < 0 || m + 0x41e + x >= 0x1800) {
                                SSPiErrorFlag = 1;
                                return 0;
                            }
                            jw[m + 0x31e + x] = (u8)h;
                            jw[m + 0x41e + x] = jw[i + 0x14 + g];
                        }
                    }
                }
            }
        } else if (b == 0xd8) {
        } else if (b == 0xda) {
            if (p + 12 >= SSPiInputDataSize)
                return 0;
            p += 12;
            for (y = 0; y < dy; y += ystep) {
                for (x = 0; x < dx; x += xstep) {
                    if (RSTn_intr != 0 && --RSTn_work == 0) {
                        RSTn_work = RSTn_intr;
                        if (bitlen > 7)
                            p = p - chit - 1;
                        p += 2;
                        bitlen = 0;
                        mtx[0][0] = mtx[3][0] = mtx[4][0] = 0;
                    }
                    for (i = 0; i < xblock * yblock; i++) {
                        getmatrix(a, mtx[0], &p, 0);
                        decode_block(&draw_block[i * 64], 0);
                    }
                    getmatrix(a, mtx[3], &p, 2);
                    decode_block(dcr, 3);
                    getmatrix(a, mtx[4], &p, 2);
                    decode_block(dcb, 4);
                    writeblock(d, x, y, dx, dy);
                }
            }
            break;
        } else if (b == 0xdb) {
            q = p + 2;
            p += s;
            while (q < p) {
                s = a[q];
                if (s & 0xf0) {
                    if (q + 0x82 >= SSPiInputDataSize)
                        return 0;
                    j = (s & 0xf) << 6;
                    q++;
                    for (i = 0; i < 64; i++, q += 2) {
                        if (j + zig[i] > 0x7f)
                            return 0;
                        qy[j + zig[i]] = (asl[i] * (a[q + 1] + (a[q] << 8)) + 0x800) >> 12;
                    }
                } else {
                    if (q + 0x41 >= SSPiInputDataSize)
                        return 0;
                    i = s << 6;
                    q++;
                    for (s = 0; s < 64; s++, q++) {
                        if (i + zig[s] > 0x7f)
                            return 0;
                        qy[i + zig[s]] = (a[q] * asl[s] + 0x800) >> 12;
                    }
                }
            }
        } else if (b == 0xdd) {
            if (p + 3 >= SSPiInputDataSize)
                return 0;
            RSTn_intr = (a[p + 2] << 8) | a[p + 3];
            p += s;
            RSTn_work = RSTn_intr + 1;
        } else {
            p += s;
        }
    }
    if (p > SSPiInputDataSize)
        return 0;
    return dx | (dy << 16);
}

/*
 * sdk:      getmatrix (jpegdec.o)
 */
void getmatrix(unsigned char *g, short *d, int *p, int n)
{
    int ax;
    int cx;
    int i;
    int j;
    int m;
    int k;

    d[0] += get_matrix_sub(g, p, 0, hloadbit(g, p, n));
    for (i = 63, j = 1; i > 0; i--) {
        cx = hloadbit(g, p, n + 1);
        if (cx == 0) {
            for (; j < 64; j++)
                d[j] = 0;
            return;
        }
        m = cx >> 4;
        i -= m;
        if (j + m > 63)
            return;
        for (k = 0; k < m; k++)
            d[j++] = 0;
        d[j++] = get_matrix_sub(g, p, 0, cx & 0xf);
    }
}

/*
 * sdk:      get_matrix_sub (libssp.TWL.HYB.a jpegdec.o)
 *
 * Reads the extra bits of a JPEG coefficient: a leading 0 bit means negative (subtract
 * 2^cx - 1), then cx - 1 more bits are shifted in, with a bounds check before each read.
 * gJpegDecodeState[2] is the jpegdec.o static SSPiInputDataSize (.bss +8 off the bcode2 anchor).
 * Earlier waves parked a cx<->i register 2-cycle (~230 spellings) as a front-end wall.
 * Closed 2026-10-01 (lane22): `cx--` written in each if/else arm (the image merges it after
 * the arms; a single cx-- after the if gives cx a fresh web and the low register), plus
 * `int i; int dx;` in the DWARF order (locals listed reverse: dx then i).
 */
int get_matrix_sub(unsigned char *s, int *p, int ax, int cx)
{
    int i;
    int dx;

    if (cx != 0) {
        dx = 0;
        if ((unsigned int)(*p + 1) >= SSPiInputDataSize)
            return dx;
        if (loadbit(s, p) == 0) {
            dx = (1 << cx) - 1;
            cx--;
        } else {
            ax = (ax << 1) | 1;
            cx--;
        }
        for (i = 0; i < cx; i++) {
            if ((unsigned int)(*p + 1) >= SSPiInputDataSize)
                return 0;
            ax = (ax << 1) | loadbit(s, p);
        }
        ax -= dx;
    }
    return ax;
}

void decode_block(short *d, short n)
{
    int i;
    int p;
    int q;

    for (q = 0, p = 0, i = 0; i < 64; i++, p++, q++) {
        mtx[1][zig[q]] = mtx[n][p];
    }
    if (n == 0) {
        decode_block_sub(gJpegIdctBlock, d, 0);
    } else {
        decode_block_sub(gJpegIdctBlock, d, 64);
    }
}

/*
 * sdk:      decode_block_sub (jpegdec.o)
 *
 * AAN integer IDCT: pass 1 dequantises through qy[n..] into mtx[2], pass 2
 * range-limits through limits+0x180 (gJpegDecodeClampTable) into d.  The odd-part sum
 * is spelled tmp5 + tmp10 in both passes (operand order of the add).
 */
void decode_block_sub(short *s, short *d, int n)
{
    int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    int tmp10, tmp11, tmp12, tmp13;
    int z5, z10, z11, z12, z13;
    unsigned char *limtbl = gJpegDecodeClampTable;
    int i;

    for (i = 0; i < 8; i++) {
        if ((s[8 * 1 + i] | s[8 * 2 + i] | s[8 * 3 + i] | s[8 * 4 + i] |
             s[8 * 5 + i] | s[8 * 6 + i] | s[8 * 7 + i]) == 0) {
            mtx[2][8 * 0 + i] = mtx[2][8 * 1 + i] =
            mtx[2][8 * 2 + i] = mtx[2][8 * 3 + i] =
            mtx[2][8 * 4 + i] = mtx[2][8 * 5 + i] =
            mtx[2][8 * 6 + i] = mtx[2][8 * 7 + i] =
                s[8 * 0 + i] * qy[n + 8 * 0 + i];
            continue;
        }

        tmp0 = s[8 * 0 + i] * qy[n + 8 * 0 + i];
        tmp1 = s[8 * 2 + i] * qy[n + 8 * 2 + i];
        tmp2 = s[8 * 4 + i] * qy[n + 8 * 4 + i];
        tmp3 = s[8 * 6 + i] * qy[n + 8 * 6 + i];

        tmp10 = tmp0 + tmp2;
        tmp11 = tmp0 - tmp2;

        tmp13 = tmp1 + tmp3;
        tmp12 = (((tmp1 - tmp3) * 362) >> 8) - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        tmp4 = s[8 * 1 + i] * qy[n + 8 * 1 + i];
        tmp5 = s[8 * 3 + i] * qy[n + 8 * 3 + i];
        tmp6 = s[8 * 5 + i] * qy[n + 8 * 5 + i];
        tmp7 = s[8 * 7 + i] * qy[n + 8 * 7 + i];

        z13 = tmp6 + tmp5;
        z10 = tmp6 - tmp5;
        z11 = tmp4 + tmp7;
        z12 = tmp4 - tmp7;

        tmp7 = z11 + z13;
        tmp11 = ((z11 - z13) * 362) >> 8;

        z5 = ((z10 + z12) * 473) >> 8;
        tmp10 = ((z12 * 277) >> 8) - z5;
        tmp12 = ((z10 * -669) >> 8) + z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp5 + tmp10;

        mtx[2][8 * 0 + i] = tmp0 + tmp7;
        mtx[2][8 * 7 + i] = tmp0 - tmp7;
        mtx[2][8 * 1 + i] = tmp1 + tmp6;
        mtx[2][8 * 6 + i] = tmp1 - tmp6;
        mtx[2][8 * 2 + i] = tmp2 + tmp5;
        mtx[2][8 * 5 + i] = tmp2 - tmp5;
        mtx[2][8 * 4 + i] = tmp3 + tmp4;
        mtx[2][8 * 3 + i] = tmp3 - tmp4;
    }

    for (i = 0; i < 8; i++) {
        if ((mtx[2][i * 8 + 1] | mtx[2][i * 8 + 2] | mtx[2][i * 8 + 3] | mtx[2][i * 8 + 4] | mtx[2][i * 8 + 5] | mtx[2][i * 8 + 6] | mtx[2][i * 8 + 7]) == 0) {
            d[i * 8 + 0] = d[i * 8 + 1] = d[i * 8 + 2] = d[i * 8 + 3] =
            d[i * 8 + 4] = d[i * 8 + 5] = d[i * 8 + 6] = d[i * 8 + 7] =
                limtbl[(mtx[2][i * 8 + 0] >> 5) & 0x3ff];
            continue;
        }

        tmp10 = mtx[2][i * 8 + 0] + mtx[2][i * 8 + 4];
        tmp11 = mtx[2][i * 8 + 0] - mtx[2][i * 8 + 4];

        tmp13 = mtx[2][i * 8 + 2] + mtx[2][i * 8 + 6];
        tmp12 = (((mtx[2][i * 8 + 2] - mtx[2][i * 8 + 6]) * 362) >> 8) - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        z13 = mtx[2][i * 8 + 5] + mtx[2][i * 8 + 3];
        z10 = mtx[2][i * 8 + 5] - mtx[2][i * 8 + 3];
        z11 = mtx[2][i * 8 + 1] + mtx[2][i * 8 + 7];
        z12 = mtx[2][i * 8 + 1] - mtx[2][i * 8 + 7];

        tmp7 = z11 + z13;
        tmp11 = ((z11 - z13) * 362) >> 8;

        z5 = ((z10 + z12) * 473) >> 8;
        tmp10 = ((z12 * 277) >> 8) - z5;
        tmp12 = ((z10 * -669) >> 8) + z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp5 + tmp10;

        d[i * 8 + 0] = limtbl[((tmp0 + tmp7) >> 5) & 0x3ff];
        d[i * 8 + 7] = limtbl[((tmp0 - tmp7) >> 5) & 0x3ff];
        d[i * 8 + 1] = limtbl[((tmp1 + tmp6) >> 5) & 0x3ff];
        d[i * 8 + 6] = limtbl[((tmp1 - tmp6) >> 5) & 0x3ff];
        d[i * 8 + 2] = limtbl[((tmp2 + tmp5) >> 5) & 0x3ff];
        d[i * 8 + 5] = limtbl[((tmp2 - tmp5) >> 5) & 0x3ff];
        d[i * 8 + 4] = limtbl[((tmp3 + tmp4) >> 5) & 0x3ff];
        d[i * 8 + 3] = limtbl[((tmp3 - tmp4) >> 5) & 0x3ff];
    }
}

int loadbit(u8 *data, int *pos)
{
    if (bitlen == 0) {
        int i = *pos;
        u32 v;

        *pos = i + 1;
        v = data[i];
        bcode2 = v;
        chit = 0;
        if (v == 0xff) {
            (*pos)++;
            bcode2 = 0xff;
            chit = 1;
        }
        bitlen = 8;
    }
    bitlen--;
    return (bcode2 >> bitlen) & 1;
}

/*
 * hloadbit notes (from the old part 4)
 *
 * closed (lane09, 2026-10-01): full rewrite from the listing and DWARF.
 *   (1) the "bcode2 struct" is the separate jpegdec.o .bss statics
 *   (bcode2, SSPiInputDataSize, chit, bitlen, ts, SSPiErrorFlag, ti ...),
 *   declared as in sibling 021BE5C4; ts is a short table and ti an int table
 *   (index s+0x46 and 17+s, matching the bounds checks), stored in that order.
 *   (2) only the DWARF locals v, t, s: t is the peek/code, s the code length,
 *   and the 9-bit refill reads its byte into s (the first refill uses t); that
 *   variable identity fixed the walk's r6/r7/r8 colours. (3) DWARF order:
 *   declared v, t, s. Each switch arm checks then does t = jw[...]; break;
 *   default returns t.
 *
 * sdk:      hloadbit (libssp.TWL.HYB.a jpegdec.o)
 *
 * Huffman decode of one coefficient for table n: an 8-bit fast lookup in jw,
 * else a 9+ bit canonical walk against the maxcode/mincode/valptr tables at
 * jw + ntbl[n], every jw index bounds-checked (error flag, return 0).
 */

int hloadbit(u8 *b, int *p, int n)
{
    int v;
    int t;
    int s;

    v = ntbl[n];
    ts = (short *)(jw + v);
    ti = (int *)(jw + v);

    if (bitlen < 8) {
        bcode2 <<= 8;
        if (*p + 1 >= SSPiInputDataSize)
            return 0;
        t = b[(*p)++];
        chit = 0;
        if (t == 0xff) {
            (*p)++;
            t = 0xff;
            chit = 1;
        }
        bitlen += 8;
        bcode2 |= t;
    }

    t = (bcode2 >> (bitlen - 8)) & 0xff;
    if (v + 0xae + t < 0 || v + 0xae + t >= 6144) {
        SSPiErrorFlag = 1;
        return 0;
    }
    if (jw[v + 0xae + t] != 0) {
        bitlen -= jw[v + 0xae + t];
        if (v + 0x1ae + t < 0 || v + 0x1ae + t >= 6144) {
            SSPiErrorFlag = 1;
            return 0;
        }
        return jw[v + 0x1ae + t];
    }

    while (bitlen < 9) {
        bcode2 <<= 8;
        if (*p + 1 >= SSPiInputDataSize)
            return 0;
        s = b[(*p)++];
        chit = 0;
        if (s == 0xff) {
            (*p)++;
            s = 0xff;
            chit = 1;
        }
        bitlen += 8;
        bcode2 |= s;
    }

    t = (bcode2 >> (bitlen - 9)) & 0x1ff;
    bitlen -= 9;
    s = 9;
    if (v + 17 + s >= 6144) {
        SSPiErrorFlag = 1;
        return 0;
    }
    while (t > ti[17 + s]) {
        if (bitlen == 0) {
            if (*p + 1 >= SSPiInputDataSize)
                return 0;
            bcode2 = b[(*p)++];
            chit = 0;
            if (bcode2 == 0xff) {
                (*p)++;
                bcode2 = 0xff;
                chit = 1;
            }
            bitlen = 8;
        }
        t = (t << 1) | ((bcode2 >> (bitlen - 1)) & 1);
        s++;
        bitlen--;
        if (v + 17 + s >= 6144) {
            SSPiErrorFlag = 1;
            return 0;
        }
    }

    if (s > 16 || v + s < 0 || v + s + 0x46 >= 6144) {
        SSPiErrorFlag = 1;
        return 0;
    }

    switch (n) {
    case 0:
        if (t + ts[s + 0x46] - ti[s] + 0x14 < 0 || t + ts[s + 0x46] - ti[s] + 0x14 >= 6144) {
            SSPiErrorFlag = 1;
            return 0;
        }
        t = jw[t + ts[s + 0x46] - ti[s] + 0x14];
        break;
    case 1:
        if (t + ts[s + 0x46] - ti[s] + 0x38 < 0 || t + ts[s + 0x46] - ti[s] + 0x38 >= 6144) {
            SSPiErrorFlag = 1;
            return 0;
        }
        t = jw[t + ts[s + 0x46] - ti[s] + 0x38];
        break;
    case 2:
        if (t + ts[s + 0x46] - ti[s] + 0x14c < 0 || t + ts[s + 0x46] - ti[s] + 0x14c >= 6144) {
            SSPiErrorFlag = 1;
            return 0;
        }
        t = jw[t + ts[s + 0x46] - ti[s] + 0x14c];
        break;
    case 3:
        if (t + ts[s + 0x46] - ti[s] + 0x170 < 0 || t + ts[s + 0x46] - ti[s] + 0x170 >= 6144) {
            SSPiErrorFlag = 1;
            return 0;
        }
        t = jw[t + ts[s + 0x46] - ti[s] + 0x170];
        break;
    }
    return t;
}

/*
 * writeblock notes (from the old part 5)
 *
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
 */

/*
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
 */
void writeblock(u8 *d, int x, int y, int dx, int dy)
{
    int e, m, n, s, t, z, rr;
    int g, b, cb, cr;
    u8 *lim = limits + 256;

    switch (yblock * 2 + xblock) {
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
        for (s = z = 0; s < xblock; s++) {
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
        for (t = z = 0; t < yblock; t++) {
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
        for (t = z = 0; t < yblock; t++) {
            for (s = 0; s < xblock; s++) {
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

/*
 * SSP_StartJpegDecoder notes (from the old part 6)
 *
 * notes:    all 940 bytes reproduced (905 concrete + the 35 bytes of the 11
 *           relocation fields) and all 11 sites resolve, so EXACT.
 *
 *           Witnesses for the two data words: both bcode2 (0x021C88F0) and
 *           SSPiDecodeSignCheckMode (0x021CADA4) live in ov172's own bss
 *           (0x021C88E0..0x021CC540), so the site's own window already fixes
 *           which overlay they are and the original image's pool words at
 *           +0x03A8 / +0x039C already hold those addresses (sole-ref/self).
 *           bcode2's `symbols:` line deliberately carries NO overlay hint:
 *           ov114 starts an object at 0x021C88F0 too, so an ov172 hint there is
 *           contested (audit finding 6) and only the site window may choose.
 *
 *           Recovered forms: the option-to-DSP mask is a parenthesised OR of
 *           three `(opt & m) ? m : 0` terms in the order 1, 4, 0x10; the tag
 *           loops use an unsigned counter; the second entry-count check adds 2
 *           to offset before the multiply test; the tail is one `if (both
 *           halves) { ... return 1;} return 0;`; locals declared offset,
 *           registrationNumber, moff, i, tag.  bcode2 is reached only through
 *           its +0x1c int, so the struct is spelled to put err at +0x1c.
 */

int SSP_StartJpegDecoder(unsigned char *data, unsigned long size, void *dst,
                  short *width, short *height, unsigned long option)
{
    unsigned long offset;
    unsigned long registrationNumber;
    unsigned long moff;
    unsigned long i;
    unsigned short tag;
    int aesResult;
    int ret;
    int optionForDsp;
    unsigned char sign[28];

    if (SSPiDecodeSignCheckMode == 1) {
        if (OS_IsRunOnTwl() == 1) {
            if (size < 0x17)
                return 0;
            offset = data[0x13] + 0xc;
            if (offset + 2 > size)
                return 0;
            registrationNumber =
                (unsigned short)(data[offset + 1] + (data[offset] << 8));
            if (registrationNumber * 12 + (offset + 2) > size)
                return 0;
            tag = 0;
            offset += 2;
            for (i = 0; i < registrationNumber; offset += 0xc, i++) {
                tag = (unsigned short)(data[offset + 1] + (data[offset] << 8));
                if (tag == 0x8769) {
                    offset = (data[offset + 8] << 24) + (data[offset + 9] << 16)
                           + (data[offset + 10] << 8) + data[offset + 11] + 0xc;
                    break;
                }
            }
            if (tag != 0x8769)
                return 0;

            if (offset + 2 > size)
                return 0;
            registrationNumber =
                (unsigned short)(data[offset + 1] + (data[offset] << 8));
            offset += 2;
            if (registrationNumber * 12 + offset > size)
                return 0;
            tag = 0;
            for (i = 0; i < registrationNumber; offset += 0xc, i++) {
                tag = (unsigned short)(data[offset + 1] + (data[offset] << 8));
                if (tag == 0x927c) {
                    offset = (data[offset + 8] << 24) + (data[offset + 9] << 16)
                           + (data[offset + 10] << 8) + data[offset + 11] + 0xc;
                    break;
                }
            }
            if (tag != 0x927c)
                return 0;

            moff = offset;
            if (moff + 4 > size)
                return 0;
            if (data[moff + 2] != 0x10 || data[moff + 3] != 0)
                return 0;
            if (moff + 0xe > size)
                return 0;
            offset = (data[moff + 0xa] << 24) + (data[moff + 0xb] << 16)
                   + (data[moff + 0xc] << 8) + data[moff + 0xd] + 0xc;
            if (offset + 0x1c > size)
                return 0;

            MI_CpuCopy8(data + offset, sign, 0x1c);
            MI_CpuFill8(data + offset, 0, 0x1c);
            if (OS_IsRunOnTwl())
                AESi_Init();
            aesResult = AESi_VerifySignForJpeg(sign, (unsigned int)data, size);
            MI_CpuCopy8(sign, data + offset, 0x1c);
            if (aesResult != 1)
                return 0;
        }
    }

    SSPiErrorFlag = 0;
    optionForDsp = (((option & 1) ? 1 : 0) | ((option & 4) ? 4 : 0)) | ((option & 0x10) ? 0x10 : 0);

    if (option & 0x10) {
        ret = Mel_JPEGDecodeExif(data, size, optionForDsp);
    } else {
        ret = Mel_JPEGDecode(dst, data, size, *width, *height, optionForDsp);
    }

    if (SSPiErrorFlag != 0)
        return 0;
    if ((ret & 0xffff0000) != 0 && (unsigned short)ret != 0) {
        if ((option & 0x10) == 0) {
            *width = ret;
            *height = ret >> 16;
        }
        return 1;
    }
    return 0;
}
