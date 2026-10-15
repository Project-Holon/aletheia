/*
 * function: sakeGetFileUploadURL
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
 *   OS_SNPrintf  0x02084F80  arm
 *   sFileUploadUrlOverride  0x021E4C08  data
 *   sFileUploadUrlFormatOverride  0x021E36B0  data
 *   sFileUploadUrlFormatDefault  0x021E36C4  data
 */

typedef struct SAKEInternal {
    int startedUp;
    char gameName[0x10];
    int gameId;
    unsigned char pad18[0xC];
    int profileSet;
    int profileId;
} SAKEInternal;

extern char sFileUploadUrlOverride[128];
extern char sFileUploadUrlFormatOverride[];
extern char sFileUploadUrlFormatDefault[];
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);

int sakeGetFileUploadURL(SAKEInternal *sake, char *url)
{
    int rcode;

    if (!sake || !url || !sake->startedUp || !sake->profileSet)
        return 0;
    if (sFileUploadUrlOverride[0])
        rcode = OS_SNPrintf(url, 128, sFileUploadUrlFormatOverride, sFileUploadUrlOverride, sake->gameId, sake->profileId);
    else
        rcode = OS_SNPrintf(url, 128, sFileUploadUrlFormatDefault, sake->gameName, sake->gameId, sake->profileId);
    if (rcode < 0)
        return 0;
    return 1;
}
