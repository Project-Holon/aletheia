/*
 * function: gpiFreeInfoCache
 * address:  0x0218D71C
 * packet:   pkt_ov009_0218D71C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiFreeInfoCache (gpiinfo.o)
 *
 * symbols:
 *   gsifree                          0x0217EAE0 arm
 */

typedef struct GPIInfoCache
{
	void * field0;
	void * field4;
	void * field8;
	void * fieldC;
	void * field10;
	void * field14;
	char pad[0xC8 - 0x18];
	void * fieldC8;
} GPIInfoCache;

struct GPIProfile
{
	char pad[0x10];
	GPIInfoCache * infoCache;
};

extern void gsifree(void * ptr);

void gpiFreeInfoCache(struct GPIProfile * profile)
{
	if (profile->infoCache == 0)
		return;
	gsifree(profile->infoCache->field0);
	profile->infoCache->field0 = 0;
	gsifree(profile->infoCache->field4);
	profile->infoCache->field4 = 0;
	gsifree(profile->infoCache->field8);
	profile->infoCache->field8 = 0;
	gsifree(profile->infoCache->fieldC);
	profile->infoCache->fieldC = 0;
	gsifree(profile->infoCache->field10);
	profile->infoCache->field10 = 0;
	gsifree(profile->infoCache->field14);
	profile->infoCache->field14 = 0;
	gsifree(profile->infoCache->fieldC8);
	profile->infoCache->fieldC8 = 0;
	gsifree(profile->infoCache);
	profile->infoCache = 0;
}
