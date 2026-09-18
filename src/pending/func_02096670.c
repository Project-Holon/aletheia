/*
 * function: func_02096670
 * address:  0x02096670
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  callee func_020965B4 has no witness outside 02096670..020966B0
 *           (the only branch to it is the one inside this file).  Byte
 *           correct everywhere else; becomes EXACT with no C change once
 *           0x020965B4 has a shard entry.
 *
 * symbols:
 *   func_020965B4  0x020965B4  arm
 *   func_02096620  0x02096620  arm
 */

typedef unsigned char u8;

extern int func_020965B4(u8 *p, int idx);
extern void func_02096620(u8 *p, int idx);

void func_02096670(u8 *p, int idx)
{
    int r;

    if (idx <= 0)
        return;
    if (idx >= p[4])
        return;
    r = func_020965B4(p, idx);
    p[4] = (u8)idx;
    if (r < 0)
        return;
    func_02096620(p, idx);
}
