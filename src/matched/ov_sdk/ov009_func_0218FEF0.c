/*
 * function: gpiRemoveProfileByID
 * address:  0x0218FEF0
 * packet:   pkt_ov009_0218FEF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiRemoveProfileByID (gpiprofile.o)
 *
 * symbols:
 *   gpiGetProfile                    0x0218FD9C arm
 *   TableRemove                      0x021847BC arm
 */

struct GPIProfile;

typedef struct GPIConnection
{
	char pad[0x5C8];
	void * profiles;
} GPIConnection;

extern int gpiGetProfile(void ** connection, int profileid, struct GPIProfile ** pProfile);
extern int TableRemove(void * table, void * delElem);

void gpiRemoveProfileByID(void ** connection, int profileid)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;
	struct GPIProfile * profile;

	if (gpiGetProfile(connection, profileid, &profile))
		TableRemove(iconnection->profiles, profile);
}
