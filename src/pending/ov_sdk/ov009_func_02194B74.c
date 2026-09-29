/*
 * function: func_02194B74
 * address:  0x02194B74
 * packet:   pkt_ov009_02194B74
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gti2GetChallenge (libdwcgsgt2.TWL.HYB.a(gt2auth.o))
 *
 * symbols:
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_020946C8  0x020946C8  arm
 *   func_02094694  0x02094694  arm
 *
 * near miss: 2 instructions differ (eor operand order for the last two xors of oddmode)
 */

extern unsigned int func_0217F264(void);
extern void func_020946C8();
extern int func_02094694();

unsigned char *func_02194B74(unsigned char *buffer)
{
	int i;
	int oddmode;

	func_0217F264();
	func_020946C8();
	buffer[0] = func_02094694() % 93 + 0x21;
	oddmode = 0;
	for (i = 1; i < 32; i++) {
		oddmode = ((buffer[i - 1] < buffer[0]) ^ (((buffer[0] & 1) ^ (oddmode ^ ((i ^ buffer[i - 1]) & 1))) ^ (buffer[0] < 0x4f)));
		buffer[i] = func_02094694() % 93 + 0x21;
		if ((oddmode && !(buffer[i] & 1)) || (!oddmode && (buffer[i] & 1) == 1))
			buffer[i]++;
	}
	return buffer;
}
