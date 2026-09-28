/*
 * function: GetFirstElement
 * address:  0x021B9FAC
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GetElementData  0x021B9F5C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol GetFirstElement (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B9FAC.c \
 *       --func GetFirstElement --addr 0x021B9FAC --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef struct _ELEMENTHEADER {
    unsigned short FullLength;
    unsigned short Reserved[3];
} ELEMENTHEADER;

extern unsigned char *GetElementData(unsigned char **lplpb, unsigned char *lplimit, int *pid, int *psize);

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))

unsigned char *GetFirstElement(unsigned char *lpelement, int *pid, int *psize)
{
    unsigned char *lpb;

    lpb = lpelement + 8;
    return GetElementData(&lpb, lpb + SWAP16(((ELEMENTHEADER *)lpelement)->FullLength), pid, psize);
}
