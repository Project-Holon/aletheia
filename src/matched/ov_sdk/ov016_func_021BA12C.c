/*
 * function: IsSearchCommand
 * address:  0x021BA12C
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GetFrameData    0x021B9EEC  thumb
 *   GetElementData  0x021B9F5C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol IsSearchCommand (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * The element pointer reuses the lpframe parameter; a fresh block local costs 14 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BA12C.c \
 *       --func IsSearchCommand --addr 0x021BA12C --region ov016 --cc ../2.0/sp1p2 --thumb
 */
extern unsigned char *GetFrameData(unsigned char *lpframe, int *pid, int *psize);
extern unsigned char *GetElementData(unsigned char **lplpb, unsigned char *lplimit, int *pid, int *psize);

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))

int IsSearchCommand(unsigned char *lpframe, int *pdual)
{
    int id;
    int size;
    int eid;
    int esize;
    unsigned char *lpb;
    unsigned char *lplimit;
    int iMajor;
    int iMinor;
    int iSP;

    lpb = GetFrameData(lpframe, &id, &size);
    iMajor = 0;
    iMinor = 0;
    iSP = 0;
    if (lpb == 0)
        return 0;
    if (id != 1)
        return 0;
    lplimit = lpb + size;
    lpb += 8;
    while ((lpframe = GetElementData(&lpb, lplimit, &eid, &esize)) != 0) {
        switch (eid) {
        case 1:
            iMajor = SWAP16(*(unsigned short *)lpframe);
            break;
        case 2:
            iMinor = SWAP16(*(unsigned short *)lpframe);
            break;
        case 5:
            iSP = SWAP16(*(unsigned short *)lpframe);
            break;
        }
    }
    if (iMajor != 1 || iMinor != 1)
        return 0;
    if (iSP >= 1)
        *pdual = 1;
    else
        *pdual = 0;
    return 1;
}
