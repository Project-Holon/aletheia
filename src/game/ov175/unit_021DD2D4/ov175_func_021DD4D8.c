/*
 * function: func_021DD4D8
 * address:  0x021DD4D8
 * packet:   pkt_ov175_021DD4D8
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeGetFileUploadURL (sakemain.o)
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   g_021E4C08  0x021E4C08  data
 *   g_021E36B0  0x021E36B0  data
 *   g_021E36C4  0x021E36C4  data
 */

typedef struct SAKEInternal {
    int startedUp;
    char gameName[0x10];
    int gameId;
    unsigned char pad18[0xC];
    int profileSet;
    int profileId;
} SAKEInternal;

extern char g_021E4C08[128];
extern char g_021E36B0[];
extern char g_021E36C4[];
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);

int func_021DD4D8(SAKEInternal *sake, char *url)
{
    int rcode;

    if (!sake || !url || !sake->startedUp || !sake->profileSet)
        return 0;
    if (g_021E4C08[0])
        rcode = func_02084F80(url, 128, g_021E36B0, g_021E4C08, sake->gameId, sake->profileId);
    else
        rcode = func_02084F80(url, 128, g_021E36C4, sake->gameName, sake->gameId, sake->profileId);
    if (rcode < 0)
        return 0;
    return 1;
}
