/*
 * function: func_021F91CC
 * address: 0x021F91CC
 * packet: pkt_ov132_021F91CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (wave P10 lane Y2): palette fade, 16 colours. Wraps the u16 phase at +0x168 by
 * 0x160 (0x10000 - 0xFEA0), reads the cosine table d_020A1B38 for a factor ((t + 0x1000) / 2),
 * adds (s8 delta * factor >> 12) to each 5 bit channel (deltas at +0x18A red, +0x19A green,
 * +0x1AA blue), writes 16 colours at +0x1BA and calls func_02061CA4(31, 0, p + 0x1BA, 32).
 * Twins: ov068 021B9D68, ov104 021B89DC (same channel pack and u8/s8 casts).
 * Compiled 252 of 256 B. The prologue now matches the image: k = 0x168 as a u32 local with the
 * offset locals k + 2/0x42/0x22/0x32/0x52 hoisted into the same spill slots in the same order,
 * mask 0x3E0 in its own slot. Residue: the image spills p ([sp]) and keeps p + i (r2) and
 * p + 2i (r7) in registers, factor in r4; the build keeps p in r6 and spills p + 2i instead,
 * with factor in r2. This also drops the shared strh after the wrap join (the image reloads p).
 * Tried: int/u32/s16 factor, int/u32 offset locals, declaration order, u32 p parameter, a
 * q = p + i local, an e = p + 2i local, int colour local, plain literals (a.c: 260 B, worse),
 * and each of the six per-function pragmas (252/248 B, no closure). Callee func_02061CA4
 * returns int in matched callers (4 args), arity checked, no void problem.
 * Idioms read: a-spilled-offset-derived-at-the-top-is-an-early-pointer-local,
 * statement-order-of-scratch-temporaries, two-long-lived-values-in-each-others-registers,
 * a-byte-locals-signedness-flips-its-callee-saved-colour,
 * signed-and-unsigned-byte-fields-do-not-share-a-truncation.
 * symbols:
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
extern const s16 d_020A1B38[];
extern int func_02061CA4(void *, u32, u32, int);
void func_021F91CC(u8 *p)
{
    u32 k = 0x168;
    u32 oc, ob, orr, og, oo;
    int factor;
    u8 i;
    if (*(u16 *)(p + k) + 0x160 >= 0x10000)
        *(u16 *)(p + k) = *(u16 *)(p + k) - 0xFEA0;
    else
        *(u16 *)(p + k) = *(u16 *)(p + k) + 0x160;
    factor = (d_020A1B38[(*(u16 *)(p + k) >> 4) * 2] + 0x1000) / 2;
    oc = k + 2; ob = k + 0x42; orr = k + 0x22; og = k + 0x32; oo = k + 0x52;
    for (i = 0; i < 16; i++) {
        u16 c = *(u16 *)(p + i * 2 + oc);
        u8 b = (c & 0x7C00) >> 10;
        u8 r = c & 0x1F;
        u8 g = (c & 0x3E0) >> 5;
        int B = b + (s8)((*(s8 *)(p + i + ob) * factor) >> 12);
        int R = r + (s8)((*(s8 *)(p + i + orr) * factor) >> 12);
        int G = g + (s8)((*(s8 *)(p + i + og) * factor) >> 12);
        *(u16 *)(p + i * 2 + oo) = (B << 10) | (R | (G << 5));
    }
    func_02061CA4((void *)31, 0, (u32)(p + 0x1BA), 32);
}
