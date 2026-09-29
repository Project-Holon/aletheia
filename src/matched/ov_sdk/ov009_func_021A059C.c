/*
 * function: func_021A059C
 * address:  0x021A059C
 * packet:   pkt_ov009_021A059C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ParseServerIPPort (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   (none)
 */

struct SBL { char pad0[0x6ac]; unsigned short defport; };
typedef struct { unsigned char b[4]; } B4;
typedef struct { unsigned char b[2]; } B2;
void func_021A059C(struct SBL *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port)
{
	unsigned char flags;
	if (len < 5)
		return;
	flags = *buf++;
	*(B4 *)ip = *(B4 *)buf;
	buf += 4;
	len -= 5;
	if (flags & 0x10) {
		if (len < 2)
			return;
		*(B2 *)port = *(B2 *)buf;
	} else {
		*port = slist->defport;
	}
}
