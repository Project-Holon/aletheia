/*
 * function: gpiRemoveBuddyStatus
 * address:  0x021900BC
 * packet:   pkt_ov009_021900BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiRemoveBuddyStatus (gpiprofile.o)
 *
 * symbols:
 *   gsifree                          0x0217EAE0 arm
 */

typedef struct GPIBuddyStatus
{
	char pad[8];
	void * field8;
	void * fieldC;
} GPIBuddyStatus;

extern void gsifree(void * ptr);

void gpiRemoveBuddyStatus(GPIBuddyStatus * buddyStatus)
{
	gsifree(buddyStatus->fieldC);
	buddyStatus->fieldC = 0;
	gsifree(buddyStatus->field8);
	buddyStatus->field8 = 0;
	gsifree(buddyStatus);
}
