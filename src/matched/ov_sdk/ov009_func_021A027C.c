/*
 * function: FreeKeyList
 * address:  0x021A027C
 * packet:   pkt_ov009_021A027C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FreeKeyList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   SBReleaseStr  0x0219F920  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 */

struct SBL { char pad0[8]; void *keys; };
extern int ArrayLength(const int *p);
extern void *func_02184208(void *a, int n);
extern void SBReleaseStr(void *slist, char *s);
extern void func_021841B0(void *a);
void FreeKeyList(struct SBL *slist)
{
	int i;
	if (slist->keys == 0)
		return;
	for (i = 0; i < ArrayLength(slist->keys); i++)
		SBReleaseStr(slist, *(char **)func_02184208(slist->keys, i));
	func_021841B0(slist->keys);
	slist->keys = 0;
}
