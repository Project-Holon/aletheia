/*
 * function: crc
 * address:  0x021B7FD0
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss    0x021DC040  data
 *   update_crc  0x021B7FF8  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol crc (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 * crc_table is crc's own function-scope static (crc_table$9182), at .bss+0x2C0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7FD0.c \
 *       --func crc --addr 0x021B7FD0 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

#include "../include/G_AOSS_BSS.h"

/*
 * aoss.o's main .bss section (3424 bytes at 0x021DC040). The vendor object
 * addresses these statics section-relative (one pool word for the section
 * base plus a field offset), so they are declared here as one object laid
 * out in the object's own order; member names are the vendor statics.
 */
typedef struct {
    unsigned char *p_name;
    unsigned int   p_name_len;
    unsigned int   sLevel;
    unsigned int   aLevel;
    unsigned int   apAddr;
    unsigned int   apMask;
    char           ip_chg;
    char           p_type;
} _AOSS_INFO;

typedef struct {
    unsigned long x;
    unsigned long mul;
    unsigned long add;
} MATHRandContext16;

typedef struct {
    int            SecurityType;    /* +0x000 */
    void          *bssList;         /* +0x004 */
    int            initflg;         /* +0x008 */
    void          *linkInfo;        /* +0x00C */
    unsigned int   gError;          /* +0x010 */
    void          *s_buf;           /* +0x014 */
    MATHRandContext16 randContext;  /* +0x018 */
    _AOSS_INFO     gData;           /* +0x024 */
    unsigned char  ProductInfo[0x280];   /* +0x040 PRODUCT_INFO_AOSS */
    unsigned long  crc_table[256];       /* +0x2C0 */
    unsigned char  SecurityInfo[0x6A0];  /* +0x6C0 ASTS_DATA_INFO[2] */
} AOSS_BSS;

extern struct AOSS_BSS aoss_bss;

extern unsigned long update_crc(unsigned long crc, unsigned char *buf, int len,
                                int crc_table_computed, unsigned long *crc_table);

unsigned char crc(unsigned char *buf, int len)
{
    return update_crc(0xffffffffL, buf, len, 0, aoss_bss.crc_table) ^ 0xffffffffL;
}
