/*
 * function: func_0219FE44
 * address:  0x0219FE44
 * packet:   pkt_ov009_0219FE44
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SetupListChallenge (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   rand  0x02094694  arm  ov009
 */

#define LIST_CHALLENGE_LEN 8

#define CALCULATEODDMODE(buffer, i, oddmode) ((buffer[i-1] & 1) ^ (i & 1) ^ oddmode ^ (buffer[0] & 1) ^ ((buffer[0] < 79) ? 1 : 0) ^ ((buffer[i-1] < buffer[0]) ? 1 : 0))

struct SBL { char pad0[0x74]; char chal[LIST_CHALLENGE_LEN]; };

extern int func_02094694(void);

void func_0219FE44(struct SBL *slist)
{
	int i;
	int oddmode;

	slist->chal[0] = (char)(33 + func_02094694() % 93);	/* chars in the range 33 - 125 */
	oddmode = 0;
	for (i = 1; i < LIST_CHALLENGE_LEN; i++)
	{
		oddmode = CALCULATEODDMODE(slist->chal, i, oddmode);
		slist->chal[i] = (char)(33 + func_02094694() % 93);
		/* if oddmode make sure the char is odd, otherwise make sure it's even */
		if ((oddmode && (slist->chal[i] & 1) == 0) || (!oddmode && ((slist->chal[i] & 1) == 1)))
			slist->chal[i]++;
	}
}
