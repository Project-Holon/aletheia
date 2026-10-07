/*
 * file:     unit_0218F9F8_p03.c
 * unit:     yes
 * function: func_0218FF38, func_0218FF98
 * address:  0x0218FF38
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
 *   strcmp                           0x020948E0 arm
 *   gpiProfileMap                    0x0218FFFC arm
 */
struct GPIProfile;
struct GPIUserInfo
{
	char * field0;
	int pad;
	char * field8;
};

struct GPIProfile
{
	char pad[0x10];
	struct GPIUserInfo * info;
};

struct GPIFindProfileByUserData
{
	char * nick;
	char * email;
	struct GPIProfile ** profile;
	int found;
};

extern int strcmp(const char * a, const char * b);
extern int gpiProfileMap(void ** connection, int (*func)(void *, struct GPIProfile *, void *), void * data);
int gpiCheckProfileForUser(void * unused, struct GPIProfile * profile, void * udata);
int gpiFindProfileByUser(void ** connection, char * nick, char * email, struct GPIProfile ** profile);


int gpiCheckProfileForUser(void * unused, struct GPIProfile * profile, void * udata)
{
	struct GPIFindProfileByUserData * data = (struct GPIFindProfileByUserData *)udata;
	struct GPIUserInfo * info = profile->info;

	if (info != 0
	    && strcmp(data->nick, info->field0) == 0
	    && strcmp(data->email, info->field8) == 0)
	{
		*(data->profile) = profile;
		data->found = 1;
		return 0;
	}
	return 1;
}


int gpiFindProfileByUser(void ** connection, char * nick, char * email, struct GPIProfile ** profile)
{
	struct GPIFindProfileByUserData data;

	data.nick = nick;
	data.email = email;
	data.profile = profile;
	data.found = 0;
	gpiProfileMap(connection, gpiCheckProfileForUser, &data);
	if (!data.found)
		*profile = 0;
	return 0;
}
