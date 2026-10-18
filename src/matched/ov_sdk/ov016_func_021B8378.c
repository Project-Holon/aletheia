/*
 * function: AOSS_Rand
 * address:  0x021B8378
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss     0x021DC040  data
 *   AOSS_Memset  0x021B8240  thumb
 *   RTC_GetTime  0x0208890C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_Rand (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 * initflg and randContext are AOSS_Rand's own function-scope statics
 * (initflg$9426, randContext$9425) at .bss+0x08 and .bss+0x18; the SDK's inline
 * MATH_InitRand16 / MATH_Rand16 are spelled out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8378.c \
 *       --func AOSS_Rand --addr 0x021B8378 --region ov016 --cc ../2.0/sp1p2 --thumb
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

typedef struct {
    unsigned long hour;
    unsigned long minute;
    unsigned long second;
} RTCTime;

extern void *AOSS_Memset(void *s, int c, int n);
extern int RTC_GetTime(RTCTime *time);

static inline void MATH_InitRand16(MATHRandContext16 *context, unsigned long seed)
{
    context->x = seed;
    context->mul = 1566083941LU;
    context->add = 2531011;
}

static inline unsigned short MATH_Rand16(MATHRandContext16 *context, unsigned short max)
{
    context->x = context->mul * context->x + context->add;
    return (unsigned short)(max ? (((context->x >> 16) * max) >> 16) : (context->x >> 16));
}

int AOSS_Rand(void)
{
    RTCTime time;
    int sheed;

    if (aoss_bss.initflg == 0) {
        sheed = 0;
        AOSS_Memset(&time, sheed, sizeof(RTCTime));
        if (RTC_GetTime(&time) == 0) {
            sheed += time.hour << 10;
            sheed += time.minute << 3;
            sheed += time.second;
        }
        MATH_InitRand16(&aoss_bss.randContext, sheed);
        aoss_bss.initflg = 1;
    }
    return MATH_Rand16(&aoss_bss.randContext, 0x7fff);
}
