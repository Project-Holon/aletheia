/*
 * file:     gt2auth.c
 * unit:     yes
 * function: func_02194AD8, func_02194B74, func_02194C6C, func_02194D74
 * address:  0x02194AD8
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
 *   current_time  0x0217F264  arm  ov009
 *   srand         0x020946C8  arm
 *   rand          0x02094694  arm
 *   strlen                   0x0209477C  arm
 *   gti2VerifyChallenge      0x02194AD8  arm  ov009
 *   _s32_div_f               0x0209C0A4  arm
 *   abs                      0x02091588  arm
 *   g_021A591C               0x021A591C  data
 */
#define CALCULATEODDMODE(buffer, i, oddmode) ((buffer[i-1] & 1) ^ (i & 1) ^ oddmode ^ (buffer[0] & 1) ^ ((buffer[0] < 79) ? 1 : 0) ^ ((buffer[i-1] < buffer[0]) ? 1 : 0))
extern unsigned int current_time(void);
extern void srand();
extern int rand();
extern int strlen();
extern int gti2VerifyChallenge();
extern int abs();
int func_02194AD8(unsigned char *buffer);
unsigned char *func_02194B74(unsigned char *buffer);
unsigned char *func_02194C6C(unsigned char *buffer, unsigned char *challenge);
int func_02194D74(unsigned char *p, unsigned char *q);
extern char g_021A591C[];

/*
 * sdk:      gti2VerifyChallenge (gt2auth.o)
 *
 * The two comparisons are written as `? 1 : 0` conditional expressions (w6_nm);
 * as plain comparisons the last two eor operands come out swapped.
 */
int func_02194AD8(unsigned char *buffer)
{
    int oddmode;
    int i;

    oddmode = 0;
    for (i = 1; i < 32; i++) {
        oddmode = (buffer[i - 1] & 1) ^ (i & 1) ^ oddmode ^ (buffer[0] & 1) ^ ((buffer[0] < 79) ? 1 : 0) ^ ((buffer[i - 1] < buffer[0]) ? 1 : 0);
        if ((oddmode && !(buffer[i] & 1)) || (!oddmode && (buffer[i] & 1) == 1))
            return 0;
    }
    return 1;
}


/*
 * sdk:      gti2GetChallenge (gt2auth.o)
 *
 * Fills a 32-byte GT2 challenge: two PRNG seeds, 33 + rand() % 93 per byte and
 * the odd/even parity fix-up driven by the vendor CALCULATEODDMODE macro.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02194B74.c  *       --func func_02194B74 --addr 0x02194B74 --region ov009 --arm --cc 1.1p1 --lang c99
 */
unsigned char *func_02194B74(unsigned char *buffer)
{
	int i;
	int oddmode;

	current_time();
	srand();
	buffer[0] = (unsigned char)(33 + rand() % 93);

	oddmode = 0;
	for (i = 1; i < 32; i++)
	{
		oddmode = CALCULATEODDMODE(buffer, i, oddmode);
		buffer[i] = (unsigned char)(33 + rand() % 93);

		if ((oddmode && (buffer[i] & 1) == 0) || (!oddmode && ((buffer[i] & 1) == 1)))
			buffer[i]++;
	}
	return buffer;
}


/*
 * sdk:      gti2GetResponse (libdwcgsgt2.TWL.HYB.a(gt2auth.o))
 */
unsigned char *func_02194C6C(unsigned char *buffer, unsigned char *challenge)
{
    int i;
    int valid;
    char cchar;
    int keylen;
    int chalrand;

    keylen = strlen(g_021A591C);
    valid = gti2VerifyChallenge(challenge);
    for (i = 0; i < 32; i++)
    {
        if (!valid || i == 0 || i == 13)
        {
            chalrand = rand();
            buffer[i] = (unsigned char)(33 + chalrand % 93);
        }
        else
        {
            if (i == 1 || i == 14)
                cchar = challenge[i];
            else
                cchar = challenge[i - 1];
            chalrand = g_021A591C[(i + challenge[i]) % keylen];
            buffer[i] = (unsigned char)(33 + abs(challenge[(i * challenge[i] + chalrand) % 32] ^ g_021A591C[(cchar * (i * 17991)) % keylen]) % 93);
        }
    }
    return buffer;
}

/*
 * Compares 0x20 bytes, skipping the first and the 0xdth: 0 at the first
 * difference, 1 when the rest agree.
 */
int func_02194D74(unsigned char *p, unsigned char *q)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (i != 0 && i != 0xd && p[i] != q[i]) return 0;
    }
    return 1;
}
