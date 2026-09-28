/*
 * function: gpiFindProfileByUser
 * address:  0x0218FF98
 * packet:   pkt_ov009_0218FF98
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiFindProfileByUser (gpiprofile.o)
 *
 * symbols:
 *   gpiProfileMap                    0x0218FFFC arm
 *   gpiCheckProfileForUser           0x0218FF38 arm
 */

struct GPIProfile;

struct GPIFindProfileByUserData
{
	char * nick;
	char * email;
	struct GPIProfile ** profile;
	int found;
};

extern int gpiProfileMap(void ** connection, int (*func)(void *, struct GPIProfile *, void *), void * data);
extern int gpiCheckProfileForUser(void * unused, struct GPIProfile * profile, void * udata);

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
