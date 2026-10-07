/*
 * function: func_021908B0
 * address:  0x021908B0
 * packet:   pkt_ov009_021908B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiOthersBuddyList (libdwcgsgp.TWL.HYB.a(gpisearch.o))
 *
 * symbols:
 *   func_021905A4  0x021905A4  arm  ov009
 *   func_02190650  0x02190650  arm  ov009
 */

struct GPISearchData {
    char pad[0x190];
    int *profiles;
    int numProfiles;
};

extern int func_021905A4(void **connection, struct GPISearchData **searchData, int type);
extern int func_02190650(void *a, int a1, int a2, int a3, int a4);

int func_021908B0(void **connection, int *profiles, int numOfProfiles, int blocking, void (*callback)(void **, void *, void *), void *param)
{
    struct GPISearchData *data;
    int result;

    result = func_021905A4(connection, &data, 9);
    if (result != 0)
        return result;
    data->profiles = profiles;
    data->numProfiles = numOfProfiles;
    result = func_02190650(connection, (int)data, blocking, (int)callback, (int)param);
    if (result != 0)
        return result;
    return 0;
}
