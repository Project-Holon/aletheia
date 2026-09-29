/*
 * function: func_021A0238
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
 *   func_0219F920  0x0219F920  arm  ov009
 */

extern void func_0219F920(void *s, char *str);
void func_021A0238(char *slist)
{
	int i;
	for (i = 0; i < *(int *)(slist + 0x480); i++)
		func_0219F920(slist, *(char **)(slist + 0x84 + i * 4));
	*(int *)(slist + 0x480) = 0;
}
