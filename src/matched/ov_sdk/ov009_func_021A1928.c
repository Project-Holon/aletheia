/*
 * function: SBListThink
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
 *   SBFreeDeadList  0x0219F7D8  arm  ov009
 *   ProcessIncomingData  0x021A153C  arm  ov009
 *   ProcessLanData  0x021A1804  arm  ov009
 */

struct SBL;
struct SBServerList;
extern void SBFreeDeadList(struct SBL *slist);
extern int ProcessIncomingData(struct SBL *slist);
extern int ProcessLanData(struct SBServerList *slist);

int SBListThink(int *p)
{
    SBFreeDeadList((struct SBL *)p);
    switch (p[0]) {
    case 2:
    case 3:
        return ProcessIncomingData((struct SBL *)p);
    case 0:
        return ProcessLanData((struct SBServerList *)p);
    case 1:
    default:
        return 0;
    }
}
