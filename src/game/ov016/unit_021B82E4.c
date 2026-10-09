/*
 * file:     unit_021B82E4.c
 * unit:     yes
 * function: func_021B82E4, func_021B830C, func_021B8324, AOSS_Ntohs, func_021B8364, AOSS_Rand
 * address:  0x021B82E4
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   aoss_bss     0x021DC040  data
 *   AOSS_Memset  0x021B8240  thumb
 *   RTC_GetTime  0x0208890C  arm
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

typedef struct {
    unsigned long hour;
    unsigned long minute;
    unsigned long second;
} RTCTime;

extern void *AOSS_Memset(void *s, int c, int n);
extern int RTC_GetTime(RTCTime *time);
unsigned long AOSS_Htonl(unsigned long hostlong);
unsigned short AOSS_Htons(unsigned short hostshort);
unsigned long AOSS_Ntohl(unsigned long netlong);
unsigned short AOSS_Ntohs(unsigned short netshort);
int func_021B8364(const char *p);
int AOSS_Rand(void);
extern AOSS_BSS aoss_bss;




unsigned long AOSS_Htonl(unsigned long hostlong)
{
    return ((hostlong >> 24) & 0xff) | ((hostlong >> 8) & 0xff00) |
           ((hostlong << 8) & 0xff0000) | ((hostlong << 24) & 0xff000000);
}




unsigned short AOSS_Htons(unsigned short hostshort)
{
    return ((hostshort >> 8) & 0xff) | ((hostshort << 8) & 0xff00);
}




unsigned long AOSS_Ntohl(unsigned long netlong)
{
    return ((netlong >> 24) & 0xff) | ((netlong >> 8) & 0xff00) |
           ((netlong << 8) & 0xff0000) | ((netlong << 24) & 0xff000000);
}



unsigned short AOSS_Ntohs(unsigned short netshort)
{
    return ((netshort >> 8) & 0xff) | ((netshort << 8) & 0xff00);
}


int func_021B8364(const char *p)
{
    int n = 0;
    while (p[n] != 0)
        n++;
    return n;
}


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
