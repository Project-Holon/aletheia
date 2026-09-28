/*
 * function: gpiGetProfile
 * address:  0x0218FD9C
 * packet:   pkt_ov009_0218FD9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiGetProfile (gpiprofile.o)
 *
 * symbols:
 *   TableLookup                      0x0218482C arm
 */

typedef struct GPIProfile
{
	int profileId;
	char pad[0x2C];
} GPIProfile;

typedef struct GPIConnection
{
	char pad[0x5C8];
	void * profiles;
} GPIConnection;

extern void * TableLookup(void * table, void * elemKey);

int gpiGetProfile(void ** connection, int profileid, GPIProfile ** pProfile)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;
	GPIProfile profileTemp;
	GPIProfile * profile;

	profileTemp.profileId = profileid;
	profile = (GPIProfile *)TableLookup(iconnection->profiles, &profileTemp);
	if (pProfile)
		*pProfile = profile;
	return profile != 0;
}
