/*
 * function: FLDMMDL_SysPauseMove
 * address:  0x0216D9A0
 * packet:   pkt_ov010_0216D9A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckMoveBitSysPauseOff  0x0216DC80  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLDMMDL_SysSetStatusBit  0x0216D4DC  thumb  ov010
 */

typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_CheckMoveBitSysPauseOff(void *it);
extern void FLDMMDL_OnMoveBitMovePause(void *it);
extern void FLDMMDL_SysSetStatusBit(void *map, u32 flag);

void FLDMMDL_SysPauseMove(void *map)
{
    u32 pos = 0;
    void *it;

    while (FLDMMDL_SysSearchUseMmdl(map, (struct Rec **)(&it), &pos) == 1) {
        if (FLDMMDL_CheckMoveBitSysPauseOff(it) == 0)
            FLDMMDL_OnMoveBitMovePause(it);
    }
    FLDMMDL_SysSetStatusBit(map, 0x20);
}
