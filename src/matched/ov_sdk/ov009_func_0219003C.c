/*
 * function: gpiCheckForBuddy
 * address:  0x0219003C
 * packet:   pkt_ov009_0219003C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiCheckForBuddy (gpiprofile.o)
 *
 * symbols:
 */

struct GPIBlock
{
	int id;
};

struct GPIProfile
{
	char pad[8];
	struct GPIBlock * b8;
	struct GPIBlock * bC;
};

struct GPIFindProfileData
{
	int blockIndex;
	struct GPIProfile * profile;
};

int gpiCheckForBuddy(void * unused, struct GPIProfile * profile, void * udata)
{
	struct GPIFindProfileData * data = (struct GPIFindProfileData *)udata;

	if (profile->b8 != 0 && data->blockIndex == profile->b8->id)
	{
		data->profile = profile;
		return 0;
	}
	if (profile->bC != 0 && data->blockIndex == profile->bC->id)
	{
		data->profile = profile;
		return 0;
	}
	return 1;
}
