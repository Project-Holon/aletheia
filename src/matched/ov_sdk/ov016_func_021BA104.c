/*
 * function: SetSingleElement
 * address:  0x021BA104
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SetElementData  0x021BA0A4  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol SetSingleElement (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BA104.c \
 *       --func SetSingleElement --addr 0x021BA104 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef struct _ELEMENTHEADER {
    unsigned short FullLength;
    unsigned short Reserved[3];
} ELEMENTHEADER;

extern unsigned char *SetElementData(unsigned char *lpb, int eid, unsigned char *pele, int esize);

int SetSingleElement(unsigned char *lpbuff, int eid, unsigned char *pele, int esize)
{
    ELEMENTHEADER *peh;
    unsigned char *lpb;

    peh = (ELEMENTHEADER *)lpbuff;
    lpbuff[0] = 0;
    lpbuff[1] = 0;
    lpbuff[2] = 0;
    lpbuff[3] = 0;
    lpbuff[4] = 0;
    lpbuff[5] = 0;
    lpbuff[6] = 0;
    lpbuff[7] = 0;
    lpb = SetElementData(lpbuff + 8, eid, pele, esize);
    peh->FullLength = (lpb - lpbuff) - 8;
    return lpb - lpbuff;
}
