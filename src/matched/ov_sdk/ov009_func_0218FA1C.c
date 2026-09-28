/*
 * function: gpiProfilesTableFree
 * address:  0x0218FA1C
 * packet:   pkt_ov009_0218FA1C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProfilesTableFree (gpiprofile.o)
 *
 * symbols:
 *   gsifree                          0x0217EAE0 arm
 *   ArrayFree                        0x021841B0 arm
 *   gpiFreeInfoCache                 0x0218D71C arm
 */

typedef struct GPIBuddyStatus
{
	char pad[8];
	void * field8;
	void * fieldC;
} GPIBuddyStatus;

typedef struct GPIBuddyStatusInfo
{
	char pad[8];
	void * field8;
	void * fieldC;
	void * field10;
	void * field14;
	char pad2[0x38 - 0x18];
	void * field38;
} GPIBuddyStatusInfo;

struct GPIProfile
{
	char pad[8];
	GPIBuddyStatus * buddyStatus;
	GPIBuddyStatusInfo * buddyStatusInfo;
	int pad10;
	void * field14;
	int pad18;
	void * field1C;
};

extern void gsifree(void * ptr);
extern void ArrayFree(void * array);
extern void gpiFreeInfoCache(struct GPIProfile * profile);

void gpiProfilesTableFree(void * arg)
{
	struct GPIProfile * profile = (struct GPIProfile *)arg;

	if (profile->buddyStatus != 0)
	{
		gsifree(profile->buddyStatus->field8);
		profile->buddyStatus->field8 = 0;
		gsifree(profile->buddyStatus->fieldC);
		profile->buddyStatus->fieldC = 0;
		gsifree(profile->buddyStatus);
		profile->buddyStatus = 0;
	}
	if (profile->buddyStatusInfo != 0)
	{
		gsifree(profile->buddyStatusInfo->field8);
		profile->buddyStatusInfo->field8 = 0;
		gsifree(profile->buddyStatusInfo->fieldC);
		profile->buddyStatusInfo->fieldC = 0;
		gsifree(profile->buddyStatusInfo->field10);
		profile->buddyStatusInfo->field10 = 0;
		gsifree(profile->buddyStatusInfo->field14);
		profile->buddyStatusInfo->field14 = 0;
		if (profile->buddyStatusInfo->field38 != 0)
		{
			ArrayFree(profile->buddyStatusInfo->field38);
			profile->buddyStatusInfo->field38 = 0;
		}
		gsifree(profile->buddyStatusInfo);
		profile->buddyStatusInfo = 0;
	}
	gpiFreeInfoCache(profile);
	gsifree(profile->field14);
	profile->field14 = 0;
	gsifree(profile->field1C);
	profile->field1C = 0;
}
