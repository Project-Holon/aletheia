/*
 * file:     unit_0218F9F8_p02.c
 * unit:     yes
 * function: func_0218FCD8
 * address:  0x0218FCD8
 * packet:   pkt_ov009_0218FCD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProfileListAdd (libdwcgsgp.TWL.HYB.a(gpiprofile.o))
 *
 * symbols:
 *   func_0218FD9C  0x0218FD9C  arm  ov009
 *   func_0218474C  0x0218474C  arm  ov009
 */

struct GPIProfile {
    int profileId;
    char *nick;
    char pad0[8];
    int a;
    int b;
    int c;
    int d;
    char pad1[0xc];
    int e;
};

struct GPIConnection {
    char pad[0x5c8];
    void *table;
    int num;
};

extern int func_0218FD9C(void **connection, int profileid, struct GPIProfile **pProfile);
extern void func_0218474C(void *table, void *newElem);

struct GPIProfile *func_0218FCD8(void **connection, int id)
{
    struct GPIConnection *profileList = (struct GPIConnection *)*connection;
    struct GPIProfile *pProfile;

    if (id <= 0)
        return 0;
    if (func_0218FD9C(connection, id, &pProfile))
        return pProfile;
    {
        struct GPIProfile profile = {0};

        profile.profileId = id;
        profile.nick = 0;
        profile.a = 0;
        profile.b = 0;
        profile.d = 0;
        profile.c = 0;
        profile.e = 0;
        func_0218474C(profileList->table, &profile);
        profileList->num++;
    }
    if (func_0218FD9C(connection, id, &pProfile))
        return pProfile;
    return 0;
}
