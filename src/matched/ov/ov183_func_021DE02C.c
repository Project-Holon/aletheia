/*
 * function: func_021DE02C
 * address: 0x021DE02C
 * packet: pkt_ov183_021DE02C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200DBA0 0x0200DBA0 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 */
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
struct Blk1AC;
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned ZONEDATA_CheckEventFlag(void *, int);
int func_021DE02C(void *p, void *q)
{
    int a = func_0200DBA0(p, 5, 0);
    unsigned b = ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(q), 0x960);
    if (a && b) return 1;
    return 0;
}
