/*
 * function: ZKNSEARCH_MAIN_InitClact
 * address:  0x021BEE94
 * packet:   pkt_ov210_021BEE94
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_SYS_GetVramBanks 0x021BC3E8 thumb ov210
 *   CLACT_InitSystem 0x0204A48C arm
 *   d_021C0990 0x021C0990 data a4 ov210
 */

typedef unsigned int u32;
typedef struct { u32 w[7]; } Tbl;
extern const Tbl d_021C0990;

struct Cfg;
extern void *ZKNSEARCH_SYS_GetVramBanks(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

void ZKNSEARCH_MAIN_InitClact(void)
{
    Tbl tbl = d_021C0990;

    CLACT_InitSystem((const struct Cfg *)(&tbl), (u32)ZKNSEARCH_SYS_GetVramBanks(), 0x7b);
}
