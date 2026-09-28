/*
 * function: gpiCheckProfileForUser
 * address:  0x0218FF38
 * packet:   pkt_ov009_0218FF38
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiCheckProfileForUser (gpiprofile.o)
 *
 * symbols:
 *   strcmp                           0x020948E0 arm
 */

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
