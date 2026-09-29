/*
 * function: CPSi_sha1_block
 * address:  0x02163628
 * packet:   pkt_ov009_02163628
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      CPSi_sha1_block (libssl.TWL.HYB.a(sha1.o))
 *
 * blocker: codegen, no provenance problem (stamp 4.0.0.1024 = dsi/1.1p1).
 *          This is a full SHA-1 compression body reconstructed from the
 *          object's DWARF locals (a=r5 b=r6 c=r10 d=r8 e=r9, w[16] at fb+16),
 *          its .debug_line mapping (sha1.c lines 263-330, source path
 *          C:\CW_DSi_11\TwlWiFi\build\libraries\ssl\common\src\sha1.c) and the
 *          annotated disassembly.  It compiles 1676 bytes vs the original
 *          1652 and diverges from the first instruction: the original frame
 *          is sub sp,#0x50 with w at fb+16, two loop counters (i in r0, j in
 *          r1) and three spilled per-stage counters at fb+4/fb+8/fb+0xc
 *          (sha1.c L278, L295, L306, L317); this spelling uses one counter and
 *          a 0x44 frame.  Structure recovered: stage 1 = 3x5 unrolled rounds
 *          (w[i+0..4]) then rounds 15 (w[15]) and 16-19 (R(0..3)); stages 2-4
 *          = 4x5 rounds each calling R(sl..sl+4) with sl advancing 5 mod 16.
 *
 * symbols:
 *   long_from_char   0x021635E0  arm
 *   R                0x02163558  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 state[5];
} CPSSha1Ctx;

extern void long_from_char(u32 *d, u8 *s, u32 len);
extern u32 R(int t, u32 *w);

#define ROL(x, n) (((x) << (n)) | ((u32)(x) >> (32 - (n))))

void CPSi_sha1_block(CPSSha1Ctx *ctx, u8 *m)
{
    u32 w[16];
    u32 a, b, c, d, e;
    int i, j;

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    long_from_char(w, m, 64);

    i = 0;
    for (j = 0; j < 3; j++) {
        e = e + ROL(a, 5) + ((b & (c ^ d)) ^ d) + w[i + 0] + 0x5a827999; b = ROL(b, 30);
        d = d + ROL(e, 5) + ((a & (b ^ c)) ^ c) + w[i + 1] + 0x5a827999; a = ROL(a, 30);
        c = c + ROL(d, 5) + ((e & (a ^ b)) ^ b) + w[i + 2] + 0x5a827999; e = ROL(e, 30);
        b = b + ROL(c, 5) + ((d & (e ^ a)) ^ a) + w[i + 3] + 0x5a827999; d = ROL(d, 30);
        a = a + ROL(b, 5) + ((c & (d ^ e)) ^ e) + w[i + 4] + 0x5a827999; c = ROL(c, 30);
        i += 5;
    }
    e = e + ROL(a, 5) + ((b & (c ^ d)) ^ d) + w[15] + 0x5a827999; b = ROL(b, 30);
    d = d + ROL(e, 5) + ((a & (b ^ c)) ^ c) + R(0, w) + 0x5a827999; a = ROL(a, 30);
    c = c + ROL(d, 5) + ((e & (a ^ b)) ^ b) + R(1, w) + 0x5a827999; e = ROL(e, 30);
    b = b + ROL(c, 5) + ((d & (e ^ a)) ^ a) + R(2, w) + 0x5a827999; d = ROL(d, 30);
    a = a + ROL(b, 5) + ((c & (d ^ e)) ^ e) + R(3, w) + 0x5a827999; c = ROL(c, 30);

    i = 0;
    for (j = 0; j < 4; j++) {
        e = e + ROL(a, 5) + (b ^ c ^ d) + R((i + 0) & 0x0f, w) + 0x6ed9eba1; b = ROL(b, 30);
        d = d + ROL(e, 5) + (a ^ b ^ c) + R((i + 1) & 0x0f, w) + 0x6ed9eba1; a = ROL(a, 30);
        c = c + ROL(d, 5) + (e ^ a ^ b) + R((i + 2) & 0x0f, w) + 0x6ed9eba1; e = ROL(e, 30);
        b = b + ROL(c, 5) + (d ^ e ^ a) + R((i + 3) & 0x0f, w) + 0x6ed9eba1; d = ROL(d, 30);
        a = a + ROL(b, 5) + (c ^ d ^ e) + R((i + 4) & 0x0f, w) + 0x6ed9eba1; c = ROL(c, 30);
        i += 5;
    }

    i = 0;
    for (j = 0; j < 4; j++) {
        e = e + ROL(a, 5) + ((b & c) | (b & d) | (c & d)) + R((i + 0) & 0x0f, w) + 0x8f1bbcdc; b = ROL(b, 30);
        d = d + ROL(e, 5) + ((a & b) | (a & c) | (b & c)) + R((i + 1) & 0x0f, w) + 0x8f1bbcdc; a = ROL(a, 30);
        c = c + ROL(d, 5) + ((e & a) | (e & b) | (a & b)) + R((i + 2) & 0x0f, w) + 0x8f1bbcdc; e = ROL(e, 30);
        b = b + ROL(c, 5) + ((d & e) | (d & a) | (e & a)) + R((i + 3) & 0x0f, w) + 0x8f1bbcdc; d = ROL(d, 30);
        a = a + ROL(b, 5) + ((c & d) | (c & e) | (d & e)) + R((i + 4) & 0x0f, w) + 0x8f1bbcdc; c = ROL(c, 30);
        i += 5;
    }

    i = 0;
    for (j = 0; j < 4; j++) {
        e = e + ROL(a, 5) + (b ^ c ^ d) + R((i + 0) & 0x0f, w) + 0xca62c1d6; b = ROL(b, 30);
        d = d + ROL(e, 5) + (a ^ b ^ c) + R((i + 1) & 0x0f, w) + 0xca62c1d6; a = ROL(a, 30);
        c = c + ROL(d, 5) + (e ^ a ^ b) + R((i + 2) & 0x0f, w) + 0xca62c1d6; e = ROL(e, 30);
        b = b + ROL(c, 5) + (d ^ e ^ a) + R((i + 3) & 0x0f, w) + 0xca62c1d6; d = ROL(d, 30);
        a = a + ROL(b, 5) + (c ^ d ^ e) + R((i + 4) & 0x0f, w) + 0xca62c1d6; c = ROL(c, 30);
        i += 5;
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
}
