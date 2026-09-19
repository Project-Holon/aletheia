/*
 * function: func_0207524C
 * address:  0x0207524C
 * packet:   pkt_0207524C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  +0020 PC24 func_020896AC           -> unresolved: 020896AC (arm, from header) has no witness outside 0207524C..02075274
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * symbols:
 *   func_020751F4    0x020751F4  arm
 *   func_020896AC    0x020896AC  arm
 *
 * Reads a bank header, then invalidates the range [p, p + len) of sequence
 * data; the length survives in r4 across the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0207524C.c \
 *       --func func_0207524C --addr 0x0207524C --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_020751F4(u8 *p, u32 b, u32 c);
extern void func_020896AC(u8 *p, u8 *end);

void func_0207524C(u8 *p, u32 len, u32 b, u32 c)
{
    func_020751F4(p, b, c);
    func_020896AC(p, p + len);
}
