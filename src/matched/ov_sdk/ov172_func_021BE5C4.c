/*
 * function: func_021BE5C4
 * address:  0x021BE5C4
 * packet:   pkt_ov172_021BE5C4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *   mtx               0x021C8B1C  data
 *   jw                0x021C959C  data
 *   qy                0x021C8A1C  data
 *   asl               0x021C72AC  data
 *   zig               0x021C726C  data
 *   draw_block        0x021C8D9C  data
 *   dcr               0x021C899C  data
 *   dcb               0x021C891C  data
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   SSP_ExifDecode    0x021C0BB4  arm  ov172
 *   func_021BEFB8     0x021BEFB8  arm  ov172
 *   func_021BF15C     0x021BF15C  arm  ov172
 *   func_021BFA68     0x021BFA68  arm  ov172
 */

typedef unsigned char u8;

typedef struct {
    int mincode[17];   /* +0x00 */
    int maxcode[18];   /* +0x44 */
    short valptr[17];  /* +0x8c */
} HuffTbl;

/* jpegdec.o .bss block; declaration order gives the vendor offsets */
static int xstep = 0;
static HuffTbl *ti = 0;
static int SSPiErrorFlag = 0;
static HuffTbl *ts = 0;
static int xblock = 0;
static int bitlen = 0;
static int chit = 0;
static unsigned long SSPiInputDataSize = 0;
static int yblock = 0;
static int bcode2 = 0;
static int ystep = 0;

extern short mtx[5][64];
extern u8 jw[6144];
extern short qy[128];
extern short asl[64];
extern u8 zig[64];
extern short draw_block[1024];
extern short dcr[64];
extern short dcb[64];

extern void MIi_CpuClearFast(unsigned long data, void *destp, unsigned long size);
extern long SSP_ExifDecode(u8 *src, unsigned long src_size, int *cur, int option);
extern void func_021BEFB8(u8 *g, short *d, int *p, int n);
extern void func_021BF15C(short *d, short n);
extern void func_021BFA68(u8 *d, int x, int y, int dx, int dy);

int func_021BE5C4(u8 *d, u8 *a, unsigned long length, long maxWidth,
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
                ts = (HuffTbl *)&jw[m + 0x270];
                ti = (HuffTbl *)&jw[m + 0x270];
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
                        ts->valptr[j] = g;
                        ti->mincode[j] = huffcode[g];
                        g += jw[i + j];
                        if (g >= 257) {
                            SSPiErrorFlag = 1;
                            return 0;
                        }
                        ti->maxcode[j] = huffcode[g - 1];
                    } else {
                        ti->maxcode[j] = -1;
                    }
                }
                ti->maxcode[17] = 0xfffff;
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
                        func_021BEFB8(a, mtx[0], &p, 0);
                        func_021BF15C(&draw_block[i * 64], 0);
                    }
                    func_021BEFB8(a, mtx[3], &p, 2);
                    func_021BF15C(dcr, 3);
                    func_021BEFB8(a, mtx[4], &p, 2);
                    func_021BF15C(dcb, 4);
                    func_021BFA68(d, x, y, dx, dy);
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
