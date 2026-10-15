/*
 * function: gpiOthersBuddyList
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
 *   gpiInitSearchData  0x021905A4  arm  ov009
 *   gpiStartSearch  0x02190650  arm  ov009
 */

struct GPISearchData {
    char pad[0x190];
    int *profiles;
    int numProfiles;
};

extern int gpiInitSearchData(void **connection, struct GPISearchData **searchData, int type);
extern int gpiStartSearch(void *a, int a1, int a2, int a3, int a4);

int gpiOthersBuddyList(void **connection, int *profiles, int numOfProfiles, int blocking, void (*callback)(void **, void *, void *), void *param)
{
    struct GPISearchData *data;
    int result;

    result = gpiInitSearchData(connection, &data, 9);
    if (result != 0)
        return result;
    data->profiles = profiles;
    data->numProfiles = numOfProfiles;
    result = gpiStartSearch(connection, (int)data, blocking, (int)callback, (int)param);
    if (result != 0)
        return result;
    return 0;
}
