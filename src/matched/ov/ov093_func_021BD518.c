/*
 * function: func_021BD518
 * address: 0x021BD518
 * packet: pkt_ov093_021BD518
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * return evidence: func_021CC8D8's matched Lock is one full 32-bit word;
 *   021CC8DA loads it, 021CC900 returns that unchanged word in r0.
 *   This caller saves r0 in r4 and passes it unchanged in r1 to restore.
 *   Scalar u32 return follows matched neighbours 021BD708/021BDA00;
 *   union aggregate spelling gave a spurious 8-byte stack frame (run 1).
 * symbols:
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021BD554 0x021BD554 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D5B68(void *);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
extern void func_021BD554(u8 *, u8 *);
void func_021BD518(u8 *p, u8 *m)
{
    u32 old;
    if (func_021D5B68(m) == 0) {
        old = func_021CC8D8(p + 0x1d74, 2697);
        func_021BD554(p, m);
        func_021CC95C(p + 0x1d74, old, 2699);
    }
}
