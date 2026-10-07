/*
 * function: func_021A1928
 * address:  0x021A1928
 * packet:   pkt_021A1928
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * SDK SBListThink (libdwcgsserverbrowsing.TWL.HYB.a, sb_serverlist.o, 76
 * bytes); all three callees are SDK members of the same object, so the
 * dependency tree is empty of game code and the SDK labels are overruled.
 * The listing extent runs long (5060 bytes) because the follower at
 * 0x021A1974 is unlabelled data, not a function; hence EXACT*.
 *
 * symbols:
 *   func_0219F7D8  0x0219F7D8  arm  ov009
 *   func_021A153C  0x021A153C  arm  ov009
 *   func_021A1804  0x021A1804  arm  ov009
 */

struct SBL;
struct SBServerList;
extern void func_0219F7D8(struct SBL *slist);
extern int func_021A153C(struct SBL *slist);
extern int func_021A1804(struct SBServerList *slist);

int func_021A1928(int *p)
{
    func_0219F7D8((struct SBL *)p);
    switch (p[0]) {
    case 2:
    case 3:
        return func_021A153C((struct SBL *)p);
    case 0:
        return func_021A1804((struct SBServerList *)p);
    case 1:
    default:
        return 0;
    }
}
