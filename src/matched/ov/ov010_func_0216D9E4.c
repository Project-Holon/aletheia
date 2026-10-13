/*
 * function: FLDMMDL_SysResumeMove
 * address:  0x0216D9E4
 * packet:   pkt_ov010_0216D9E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases every record FLDMMDL_SysSearchUseMmdl yields, then FLDMMDL_SysClearStatusBit(c, 0x20).
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 *   FLDMMDL_SysClearStatusBit  0x0216D4E4  thumb  ov010
 */

typedef unsigned int u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern char *FLDMMDL_OffMoveBitMovePause(void *a0);
extern u32 *FLDMMDL_SysClearStatusBit(u32 *p, u32 v);

u32 *FLDMMDL_SysResumeMove(void *c)
{
    u32 iter;
    void *r;

    iter = 0;
    while (FLDMMDL_SysSearchUseMmdl(c, (struct Rec **)(&r), &iter) == 1)
        FLDMMDL_OffMoveBitMovePause(r);
    return FLDMMDL_SysClearStatusBit(c, 0x20);
}
