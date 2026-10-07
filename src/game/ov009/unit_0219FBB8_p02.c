/*
 * file:     unit_0219FBB8_p02.c
 * unit:     yes
 * function: func_0219FE10, func_0219FE44
 * address:  0x0219FE10
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   unit_02092344  0x02092344  arm
 *   rand  0x02094694  arm  ov009
 */
#define LIST_CHALLENGE_LEN 8
#define CALCULATEODDMODE(buffer, i, oddmode) ((buffer[i-1] & 1) ^ (i & 1) ^ oddmode ^ (buffer[0] & 1) ^ ((buffer[0] < 79) ? 1 : 0) ^ ((buffer[i-1] < buffer[0]) ? 1 : 0))
struct SBL { char pad0[0x74]; char chal[LIST_CHALLENGE_LEN]; };

extern void *unit_02092344(void *dst, const void *src, unsigned long n);
extern int func_02094694(void);
void func_0219FE10(char **buffer, char *data, int dlen, int *len);
void func_0219FE44(struct SBL *slist);


/*
 * sdk:      BufferAddData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FE10(char **buffer, char *data, int dlen, int *len)
{
    unit_02092344(*buffer, data, dlen);
    *len += dlen;
    *buffer += dlen;
}


/*
 * sdk:      SetupListChallenge (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
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
