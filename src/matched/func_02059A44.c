/*
 * function: DWC_LoginIdToUserName
 * address:  0x02059A44
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 * The tail call passes frienddata as loginid, userdata+36 as gamecode and the untouched username.
 */
extern void DWCi_Acc_LoginIdToUserName(void *loginid, unsigned long gamecode, char *username);

typedef struct { unsigned char pad[36]; unsigned long gamecode; } DWCstAccUserData;

void DWC_LoginIdToUserName(DWCstAccUserData *userdata, void *frienddata, char *username)
{
    DWCi_Acc_LoginIdToUserName(frienddata, userdata->gamecode, username);
}
