/*
 * function: func_02194B74
 * address:  0x02194B74
 * packet:   pkt_ov009_02194B74
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2GetChallenge (gt2auth.o)
 *
 * symbols:
 *   current_time  0x0217F264  arm  ov009
 *   srand         0x020946C8  arm
 *   rand          0x02094694  arm
 *
 * Fills a 32-byte GT2 challenge: two PRNG seeds, 33 + rand() % 93 per byte and
 * the odd/even parity fix-up driven by the vendor CALCULATEODDMODE macro.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02194B74.c  *       --func func_02194B74 --addr 0x02194B74 --region ov009 --arm --cc 1.1p1 --lang c99
 */

#define CALCULATEODDMODE(buffer, i, oddmode) ((buffer[i-1] & 1) ^ (i & 1) ^ oddmode ^ (buffer[0] & 1) ^ ((buffer[0] < 79) ? 1 : 0) ^ ((buffer[i-1] < buffer[0]) ? 1 : 0))

extern unsigned int current_time(void);
extern void srand();
extern int rand();

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
