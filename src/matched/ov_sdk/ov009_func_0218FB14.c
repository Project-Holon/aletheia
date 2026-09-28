/*
 * function: gpiInitProfiles
 * address:  0x0218FB14
 * packet:   pkt_ov009_0218FB14
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiInitProfiles (gpiprofile.o)
 *
 * symbols:
 *   TableNew                         0x02184610 arm
 *   gpiProfilesTableFree             0x0218FA1C arm
 *   gpiProfilesTableHash             0x0218F9F8 arm
 *   gpiProfilesTableCompare          0x0218FA0C arm
 */

typedef struct GPIConnection
{
	char pad[0x5C8];
	void * profiles;
	int field5CC;
	int field5D0;
	int field5D4;
} GPIConnection;

extern void * TableNew(int elemSize, int nBuckets, int (*hashFn)(void *, int), int (*compFn)(void *, void *), void (*freeFn)(void *));
extern void gpiProfilesTableFree(void * arg);
extern int gpiProfilesTableHash(void * arg, int numBuckets);
extern int gpiProfilesTableCompare(void * arg1, void * arg2);

int gpiInitProfiles(void ** connection)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;
	int result = 0;

	iconnection->field5D0 = 0;
	iconnection->field5D4 = 0;
	iconnection->field5CC = 0;
	iconnection->profiles = TableNew(0x30, 0x20, gpiProfilesTableHash, gpiProfilesTableCompare, gpiProfilesTableFree);
	if (iconnection->profiles != 0)
		result = 1;
	return result;
}
