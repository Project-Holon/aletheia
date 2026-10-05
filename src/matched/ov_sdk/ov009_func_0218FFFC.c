/*
 * function: gpiProfileMap
 * address:  0x0218FFFC
 * packet:   pkt_ov009_0218FFFC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProfileMap (gpiprofile.o)
 *
 * symbols:
 *   TableMapSafe2                    0x021848E4 arm
 *   gpiProfileMapCallback            0x0218FFE0 arm
 */

struct GPIProfile;

typedef struct GPIConnection
{
	char pad[0x5C8];
	void * profiles;
} GPIConnection;

struct GPIProfileMapData
{
	void ** connection;
	int (*func)(void *, struct GPIProfile *, void *);
	void * data;
};

extern void * TableMapSafe2(void * table, int (*cb)(void *, void *), void * udata);
extern int gpiProfileMapCallback(void * arg, void * udata);

int gpiProfileMap(void ** connection, int (*func)(void *, struct GPIProfile *, void *), void * data)
{
	struct GPIProfileMapData mapData;
	GPIConnection * iconnection = (GPIConnection *)*connection;

	mapData.connection = connection;
	mapData.func = func;
	mapData.data = data;
	if (TableMapSafe2(iconnection->profiles, gpiProfileMapCallback, &mapData) == 0)
		return 1;
	return 0;
}
