/*
 * function: GetElementData
 * address:  0x021B9F5C
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol GetElementData (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B9F5C.c \
 *       --func GetElementData --addr 0x021B9F5C --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef struct _ELEMENTINFO {
    unsigned short ElementID;
    unsigned short ElementLength;
} ELEMENTINFO;

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))

unsigned char *GetElementData(unsigned char **lplpb, unsigned char *lplimit, int *pid, int *psize)
{
    unsigned char *lpb;
    ELEMENTINFO *pele;

    lpb = *lplpb;
    if (lpb >= lplimit)
        return 0;
    pele = (ELEMENTINFO *)lpb;
    *pid = SWAP16(pele->ElementID);
    *psize = SWAP16(pele->ElementLength);
    lpb += sizeof(ELEMENTINFO);
    *lplpb = lpb + (((*psize + 11) & ~7) - 4);
    return lpb;
}
