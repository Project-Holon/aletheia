/*
 * function: SetElementData
 * address:  0x021BA0A4
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   memset  0x020923B0  arm
 *   memcpy  0x02092344  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol SetElementData (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BA0A4.c \
 *       --func SetElementData --addr 0x021BA0A4 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef struct _ELEMENTINFO {
    unsigned short ElementID;
    unsigned short ElementLength;
} ELEMENTINFO;

extern void *memset(void *dst, int c, unsigned long n);
extern void *memcpy(void *dst, const void *src, unsigned long n);

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))

unsigned char *SetElementData(unsigned char *lpb, int eid, unsigned char *pele, int esize)
{
    ELEMENTINFO *pei;
    int size;

    pei = (ELEMENTINFO *)lpb;
    lpb[0] = 0;
    lpb[1] = 0;
    lpb[2] = 0;
    lpb[3] = 0;
    pei->ElementID = SWAP16((unsigned short)eid);
    size = ((esize + 11) & ~7) - 4;
    pei->ElementLength = SWAP16((unsigned short)esize);
    lpb = (unsigned char *)(pei + 1);
    memset(lpb, 0, size);
    memcpy(lpb, pele, esize);
    return lpb + size;
}
