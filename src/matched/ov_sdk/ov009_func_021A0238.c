/*
 * function: FreePopularValues
 * address:  0x021A0238
 * packet:   pkt_ov009_021A0238
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FreePopularValues (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   SBReleaseStr  0x0219F920  arm  ov009
 */

extern void SBReleaseStr(void *s, char *str);
void FreePopularValues(char *slist)
{
	int i;
	for (i = 0; i < *(int *)(slist + 0x480); i++)
		SBReleaseStr(slist, *(char **)(slist + 0x84 + i * 4));
	*(int *)(slist + 0x480) = 0;
}
