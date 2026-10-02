/*
 * function: func_020380E4
 * address:  0x020380E4
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D0     0x021469D0  data
 *   func_0203D798  0x0203D798  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02036428  0x02036428  arm
 *
 * Validates one incoming record against the per-slot table reached through
 * 0x021469D0: the byte at +4 of the record is a presence/state tag (0xFF is
 * "locked out", bit 1 is the "no free slot" rejection), then the two-byte
 * header of the body is checked against the result of 0x0203F1FC, then the
 * slot's own counter byte at 0x1D7+slot is compared with rec[5]-1 before
 * being overwritten with rec[5].  Slot `a0` lives at 0x54 + (a0 << 4), so the
 * per-slot block is 16 bytes and the counter table is a byte array.
 *
 * The +8 bit of rec[4] biases the third argument by 0xFF; both the globals are
 * re-read from the pointer word after every call, which is why the C indexes
 * g_021469D0 directly instead of caching it in a local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020380E4.c \
 *       --func func_020380E4 --addr 0x020380E4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021469D0;
extern void func_0203D798(void);
extern void func_0203D6BC(void);
extern u16 func_0203F1FC(u8 *p, u32 n);
extern void func_02036428(u8 *p, u8 *q, u32 v);

u32 func_020380E4(u32 a0, u8 *rec, u32 len)
{
    int v;
    u32 n;

    func_0203D798();
    func_0203D6BC();

    if (rec[4] == 0xFF)
        return 0;
    if (*(u32 *)(g_021469D0 + (a0 << 4) + 0x54) == 0 && (rec[4] & 2))
        return 0;

    v = func_0203F1FC(rec + 2, len - 2);
    if (rec[0] != (u8)v || ((v & 0xFF00) >> 8) != rec[1])
        return 0;
    if (*(u8 *)(g_021469D0 + 0x1D7 + a0) != 0 &&
        (u8)(rec[5] - 1) != *(u8 *)(g_021469D0 + 0x1D7 + a0))
        return 0;

    *(u8 *)(g_021469D0 + 0x1D7 + a0) = rec[5];
    n = rec[2];
    if (rec[4] & 8)
        n += 0xFF;
    func_02036428(g_021469D0 + 0x4C + (a0 << 4), rec + 7, n);
    *(u32 *)(g_021469D0 + (a0 << 4) + 0x54) = 1;
    return 1;
}
