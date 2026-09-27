/*
 * function: aoss_release
 * address:  0x021B6CF0
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss   0x021DC040  data
 *   AOSS_FREE  0x021B61C0  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol aoss_release (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Pin tell: the image reloads the .bss pool word before each of the three
 * accesses (ldr r0, [pc] at 0x021B6CF2, 0x021B6CFE, 0x021B6D04, 0x021B6D10 against
 * the single word at 0x021B6D18) and is 44 bytes; dsi/1.1p1 keeps the base live in
 * a register and emits 40 bytes (31 concrete bytes out). Under 2.0/sp1p2 the same
 * C is 44 bytes, 0 mismatches.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B6CF0.c \
 *       --func aoss_release --addr 0x021B6CF0 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

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

extern AOSS_BSS aoss_bss;

extern void AOSS_FREE(void *p);

void aoss_release(void)
{
    if (aoss_bss.linkInfo != 0) {
        AOSS_FREE(aoss_bss.linkInfo);
        aoss_bss.linkInfo = 0;
    }
    if (aoss_bss.bssList != 0) {
        AOSS_FREE(aoss_bss.bssList);
        aoss_bss.bssList = 0;
    }
}
