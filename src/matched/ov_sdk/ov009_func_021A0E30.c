/*
 * function: ProcessPushKeyList
 * address:  0x021A0E30
 * packet:   pkt_ov009_021A0E30
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessPushKeyList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   FreeKeyList  0x021A027C  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   NTSLengthSB  0x0219F978  arm  ov009
 *   SBRefStr  0x0219F8B0  arm  ov009
 *   ArrayAppend  0x02184234  arm  ov009
 */

struct KeyInfo { char *name; int type; };
struct SBL { char pad0[8]; void *keys; };
extern void FreeKeyList(struct SBL *slist);
extern void *func_02184144(int elemSize, int num, void (*fn)(void *));
extern int NTSLengthSB(char *buf, int len);
extern char *SBRefStr(void *slist, char *str);
extern void ArrayAppend(void *array, void *elem);
int ProcessPushKeyList(struct SBL *slist, char *buf, int len)
{
	int i;
	int numkeys;
	int keylen;
	struct KeyInfo ki;
	numkeys = (unsigned char)*buf++;
	len--;
	if (slist->keys != 0)
		FreeKeyList(slist);
	slist->keys = func_02184144(8, numkeys, 0);
	if (slist->keys == 0)
		return 5;
	for (i = 0; i < numkeys; i++) {
		if (len < 2)
			return 4;
		keylen = NTSLengthSB(buf + 1, len - 1);
		if (keylen == -1)
			return 4;
		ki.type = (unsigned char)buf[0];
		ki.name = SBRefStr(slist, buf + 1);
		ArrayAppend(slist->keys, &ki);
		buf += keylen + 1;
		len -= keylen + 1;
	}
	return 0;
}
