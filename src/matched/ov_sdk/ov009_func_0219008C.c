/*
 * function: gpiFindBuddy
 * address:  0x0219008C
 * packet:   pkt_ov009_0219008C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiFindBuddy (gpiprofile.o)
 *
 * symbols:
 *   gpiProfileMap                    0x0218FFFC arm
 *   gpiCheckForBlock                 0x0219003C arm
 */

struct GPIProfile;

struct GPIFindProfileData
{
	int blockIndex;
	struct GPIProfile * profile;
};

extern int gpiProfileMap(void ** connection, int (*func)(void *, struct GPIProfile *, void *), void * data);
extern int gpiCheckForBlock(void * unused, struct GPIProfile * profile, void * udata);

struct GPIProfile * gpiFindBuddy(void ** connection, int blockIndex)
{
	struct GPIFindProfileData data;

	data.blockIndex = blockIndex;
	data.profile = 0;
	gpiProfileMap(connection, gpiCheckForBlock, &data);
	return data.profile;
}
