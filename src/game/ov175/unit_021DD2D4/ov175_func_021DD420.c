/*
 * function: func_021DD420
 * address:  0x021DD420
 * packet:   pkt_ov175_021DD420
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeGetFileDownloadURL (sakemain.o)
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   g_021E4B88  0x021E4B88  data
 *   g_021E363C  0x021E363C  data
 *   g_021E365C  0x021E365C  data
 */

typedef struct SAKEInternal {
    int startedUp;
    char gameName[0x10];
    int gameId;
    unsigned char pad18[0xC];
    int profileSet;
    int profileId;
} SAKEInternal;

extern char g_021E4B88[128];
extern char g_021E363C[];
extern char g_021E365C[];
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);

int func_021DD420(SAKEInternal *sake, int fileId, char *url)
{
    int rcode;

    if (!sake || !url || !sake->startedUp || !sake->profileSet)
        return 0;
    if (g_021E4B88[0])
        rcode = func_02084F80(url, 128, g_021E363C, g_021E4B88, fileId, sake->gameId, sake->profileId);
    else
        rcode = func_02084F80(url, 128, g_021E365C, sake->gameName, fileId, sake->gameId, sake->profileId);
    if (rcode < 0)
        return 0;
    return 1;
}
