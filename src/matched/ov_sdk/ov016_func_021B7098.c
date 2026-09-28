/*
 * function: AOSS_StatusExclusion
 * address:  0x021B7098
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_data     0x021DAAB4  data
 *   AOSSi_Status  0x021B89C8  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_StatusExclusion (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 * before is the function's own static (before$8610) at .data+4 of aoss.o's
 * 96-byte .data section (s_sFd, before, soconfig), declared as one object for the
 * same reason as aoss_bss.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7098.c \
 *       --func AOSS_StatusExclusion --addr 0x021B7098 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

/*
 * aoss.o's 96-byte .data section (0x021DAAB4): s_sFd, AOSS_StatusExclusion's
 * static before, and soconfig, declared as one object because the vendor
 * object addresses them section-relative.
 */
typedef struct {
    unsigned char  pad00[0x10];
    unsigned long  addr;       /* +0x10 */
    unsigned long  netmask;    /* +0x14 */
    unsigned long  router;     /* +0x18 */
    unsigned char  pad1C[0x58 - 0x1C];
} SOCConfig;

typedef struct {
    int       s_sFd;
    int       before;
    SOCConfig soconfig;
} AOSS_DATA_SECTION;

extern AOSS_DATA_SECTION aoss_data;
extern int AOSSi_Status(int stat);

int AOSS_StatusExclusion(int stat)
{
    if (stat == -1) {
        aoss_data.before = stat;
        return 0;
    }
    if (aoss_data.before != stat) {
        aoss_data.before = stat;
        return AOSSi_Status(stat);
    }
    return 0;
}
