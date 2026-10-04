/*
 * function: func_021BFF30
 * address:  0x021BFF30
 * packet:   pkt_ov210_021BFF30
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (3 bytes): the 0x2B0 offset goes to r1 where the image uses r2 (b is copied to r4 first, so r1 and r2 are both dead); no spelling moves it.
 *
 * For mode a <= 6, looks up the +0x2b0 record and issues a six-argument event
 * (0, four of its bytes, and the low byte of b) through 0x020413B0, then flushes
 * with 0x02041B6C(0).  Blocker target of func_021BE010.
 *
 * 2026-10-02 (wave C2 lane 04): also tried copy-of-b first, p as pointer param,
 * if-block form and a seven-case switch; all keep r1.
 * PARKED DIFF (3 bytes): the 0x2b0 offset is materialised into r1 where the
 * image uses r2 (the dead `a` parameter register); every spelling still picks
 * r1.  No shard written.
 *
 * symbols:
 *   func_0202616C  0x0202616C  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int func_0202616C(int a);
extern void func_020413B0(int a, int b, int c, int d, int e, int f);
extern void func_02041B6C(int a);

void func_021BFF30(int p, unsigned int a, unsigned int b)
{
    u8 *t;
    int *q = (int *)p;

    if (a > 6)
        return;
    t = (u8 *)func_0202616C(q[0xac]);
    func_020413B0(0, t[0], t[1], t[2], t[3], (u8)b);
    func_02041B6C(0);
}
