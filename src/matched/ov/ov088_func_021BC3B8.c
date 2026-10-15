/*
 * function: STARTMENU_BattleFlagProcInit
 * address:  0x021BC3B8
 * packet:   pkt_ov088_021BC3B8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_0200873C  0x0200873C  thumb
 *   BEACON_GetBlock  0x0200C0F0  thumb
 */

typedef unsigned int u32;

struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
struct Sub02007084Ctrl;
extern struct Sub02007084Ctrl *func_020070A4(void);
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *BEACON_GetBlock(void *sys);

int STARTMENU_BattleFlagProcInit(struct Obj0203159C *a0)
{
    u32 *q = PROCSYS_AllocProcWork(a0, 0x5c, 1);

    q[0] = 1;
    q[1] = (u32)func_0200873C(func_020070A4());
    q[3] = (u32)BEACON_GetBlock(func_020070A4());
    q[2] = 0;
    return 1;
}
