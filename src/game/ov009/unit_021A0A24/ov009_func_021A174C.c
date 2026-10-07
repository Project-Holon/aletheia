/*
 * function: func_021A174C
 * address:  0x021A174C
 * packet:   pkt_ov009_021A174C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021A1620  0x021A1620  arm  ov009
 *
 * SBSendNatNegotiateCookieToServer: fills a 10-byte natneg cookie packet
 * (6 magic bytes + the big-endian cookie) and hands it to SBSendMessageToServer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_021A174C.c \
 *       --func func_021A174C --addr 0x021A174C --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */

#include "../../../matched/arm9_sdk/libc/string.h"

#define NATNEG_MAGIC_LEN 6
#define NN_MAGIC_0 0xfd
#define NN_MAGIC_1 0xfc
#define NN_MAGIC_2 0x1e
#define NN_MAGIC_3 0x66
#define NN_MAGIC_4 0x6a
#define NN_MAGIC_5 0xb2

#define SOC_HtoNl(hostlong) \
	( \
		(unsigned int) \
			( \
				(((unsigned int)(hostlong) >> 24) & 0x000000ff) | (((unsigned int)(hostlong) >> 8) & 0x0000ff00) | \
					(((unsigned int)(hostlong) << 8) & 0x00ff0000) | (((unsigned int)(hostlong) << 24) & 0xff000000) \
			) \
	)

extern int func_021A1620(void *slist, unsigned int ip, unsigned short port, char *data, int len);

int func_021A174C(void *slist, unsigned int ip, unsigned short port, int cookie)
{
	unsigned char negotiateBuffer[NATNEG_MAGIC_LEN + 4];

	negotiateBuffer[0] = NN_MAGIC_0;
	negotiateBuffer[1] = NN_MAGIC_1;
	negotiateBuffer[2] = NN_MAGIC_2;
	negotiateBuffer[3] = NN_MAGIC_3;
	negotiateBuffer[4] = NN_MAGIC_4;
	negotiateBuffer[5] = NN_MAGIC_5;
	cookie = (int)SOC_HtoNl((unsigned int)cookie);
	memcpy(negotiateBuffer + NATNEG_MAGIC_LEN, &cookie, 4);
	return func_021A1620(slist, ip, port, (char *)negotiateBuffer, NATNEG_MAGIC_LEN + 4);
}
