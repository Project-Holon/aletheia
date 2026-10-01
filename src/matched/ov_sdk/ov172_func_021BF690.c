/*
 * function: func_021BF690
 * address:  0x021BF690
 * packet:   pkt_ov172_021BF690
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 *
 * symbols:
 *   ntbl              0x021C725C  data
 *   jw                0x021C959C  data
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
 */

typedef unsigned char u8;

typedef struct {
    int mincode[17];   /* +0x00 */
    int maxcode[18];   /* +0x44 */
    short valptr[17];  /* +0x8c */
} HuffTbl;

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

extern int ntbl[4];
extern u8 jw[6144];

int func_021BF690(u8 *b, int *p, int n)
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
