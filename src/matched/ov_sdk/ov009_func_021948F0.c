/*
 * function: TeamOpFloat
 * address:  0x021948F0
 * packet:   pkt_ov009_021948F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TeamOpFloat (gstats.o)
 *
 * symbols:
 *   GetTeamIndex 0x021946F4  arm
 *   OS_SPrintf   0x02084F40  arm
 *   ServerOpFloat 0x021947C0  arm
 *   gGstatsTeamOpFormat   0x021A590C  data
 */

extern int GetTeamIndex(int *game, int tnum);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern double ServerOpFloat(void *game, char *name, void *func, double value, int index);
extern char gGstatsTeamOpFormat[];

double TeamOpFloat(void *game, char *name, void *func, double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, gGstatsTeamOpFormat, name, GetTeamIndex(game, index));
    return ServerOpFloat(game, fullname, func, value, index);
}
