/*
 * function: sakeGetFileDownloadURL
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
 *   OS_SNPrintf  0x02084F80  arm
 *   sFileDownloadUrlOverride  0x021E4B88  data
 *   sFileDownloadUrlFormatOverride  0x021E363C  data
 *   sFileDownloadUrlFormatDefault  0x021E365C  data
 */

typedef struct SAKEInternal {
    int startedUp;
    char gameName[0x10];
    int gameId;
    unsigned char pad18[0xC];
    int profileSet;
    int profileId;
} SAKEInternal;

extern char sFileDownloadUrlOverride[128];
extern char sFileDownloadUrlFormatOverride[];
extern char sFileDownloadUrlFormatDefault[];
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

int sakeGetFileDownloadURL(SAKEInternal *sake, int fileId, char *url)
{
    int rcode;

    if (!sake || !url || !sake->startedUp || !sake->profileSet)
        return 0;
    if (sFileDownloadUrlOverride[0])
        rcode = OS_SNPrintf(url, 128, sFileDownloadUrlFormatOverride, sFileDownloadUrlOverride, fileId, sake->gameId, sake->profileId);
    else
        rcode = OS_SNPrintf(url, 128, sFileDownloadUrlFormatDefault, sake->gameName, fileId, sake->gameId, sake->profileId);
    if (rcode < 0)
        return 0;
    return 1;
}
