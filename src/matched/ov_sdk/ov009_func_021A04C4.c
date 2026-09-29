/*
 * function: func_021A04C4
 * address:  0x021A04C4
 * packet:   pkt_ov009_021A04C4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      AllKeysPresent (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0219F978  0x0219F978  arm  ov009
 */

struct KeyEnt { int a; int type; };
struct SBL { char pad0[8]; void *keys; };
extern int func_02184200(void *a);
extern void *func_02184208(void *a, int n);
extern int func_0219F978(char *buf, int len);
int func_021A04C4(struct SBL *slist, char *buf, int len)
{
	int numkeys;
	int i;
	int strindex;
	numkeys = func_02184200(slist->keys);
	for (i = 0; i < numkeys; i++) {
		switch (((struct KeyEnt *)func_02184208(slist->keys, i))->type) {
		case 1:
			buf += 1;
			len -= 1;
			break;
		case 2:
			buf += 2;
			len -= 2;
			break;
		case 0:
			if (len < 1)
				return 0;
			if (*(unsigned char *)buf++ == 0xff) {
				len--;
				strindex = func_0219F978(buf, len);
				if (strindex == -1)
					return 0;
				buf += strindex;
				len -= strindex;
			} else
				len--;
			break;
		default:
			return 0;
		}
		if (len < 0)
			return 0;
	}
	return 1;
}
