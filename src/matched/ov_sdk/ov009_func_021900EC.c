/*
 * function: gpiRemoveBuddyStatusInfo
 * address:  0x021900EC
 * packet:   pkt_ov009_021900EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiRemoveBuddyStatusInfo (gpiprofile.o)
 *
 * symbols:
 *   gsifree                          0x0217EAE0 arm
 *   ArrayFree                        0x021841B0 arm
 */

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

extern void gsifree(void * ptr);
extern void ArrayFree(void * array);

void gpiRemoveBuddyStatusInfo(GPIBuddyStatusInfo * buddyStatusInfo)
{
	gsifree(buddyStatusInfo->field8);
	buddyStatusInfo->field8 = 0;
	gsifree(buddyStatusInfo->fieldC);
	buddyStatusInfo->fieldC = 0;
	gsifree(buddyStatusInfo->field10);
	buddyStatusInfo->field10 = 0;
	gsifree(buddyStatusInfo->field14);
	buddyStatusInfo->field14 = 0;
	ArrayFree(buddyStatusInfo->field38);
	buddyStatusInfo->field38 = 0;
	gsifree(buddyStatusInfo);
}
