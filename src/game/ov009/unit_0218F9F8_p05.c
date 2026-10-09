/*
 * file:     unit_0218F9F8_p05.c
 * unit:     yes
 * function: func_0218FFE0, func_0218FFFC, func_0219003C
 * address:  0x0218FFE0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

extern void * TableMapSafe2(void * table, int (*cb)(void *, void *), void * udata);
extern int gpiProfileMapCallback(void * arg, void * udata);
void func_0218FFE0(int a, int *p);
int gpiProfileMap(void ** connection, int (*func)(void *, struct GPIProfile *, void *), void * data);
int gpiCheckForBuddy(void * unused, struct GPIProfile * profile, void * udata);

/*
 * Calls the handler the object carries on its three words.
 */
void func_0218FFE0(int a, int *p)
{
    ((void (*)(int, int, int))p[1])(p[0], a, p[2]);
}


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
