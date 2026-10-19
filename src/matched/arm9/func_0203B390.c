/*
 * function: GFL_NET_STATE_ChangeoverConnect
 * address:  0x0203B390
 * packet:   pkt_0203B390
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closes the residue docs/notes/pkt_0203B390.c.txt recorded ("DIFF, one
 * instruction": `mov r0, #1` hoisted above the `beq` in the original but
 * left inside the alt block in every spelling that note tried).  The note
 * was looking at the wrong constant.  What the original hoists is not the
 * `1`, it is the 0x200 -- `mov r4, #0x200` at +0x24, before the compare
 * chain -- and r4 then serves FOUR uses: the length argument of
 * GFL_NET_SYSTEM_ConnectToParent, the second argument of GFL_NET_SYSTEM_StartBeaconScan on the alt path, and
 * the base of both line numbers (`add r3, r4, #0x45` = 0x245 and
 * `add r3, r4, #0x4a` = 0x24A).  Binding it to ONE local `u32 n = 0x200;`
 * declared before the guards gives it a live range that spans both arms,
 * which is what pins it in r4 and frees r0 for the literal `1` to be
 * materialised in the pre-branch block.  The note's experiment of making
 * `one` a local was the right technique applied to the wrong value.
 *
 * EXACT on the first compile with that change; no permuter search needed.
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_SYSTEM_ConnectToParent  0x02037A6C  arm
 *   GFL_NET_SYSTEM_StartBeaconScan  0x02037928  arm
 *   GFL_NET_STATE_RollChildWaitTime  0x0203B2FC  arm
 *   GFL_NET_STATE_RollParentWaitTime  0x0203B344  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_STATE_ExtendConnectTimer  0x0203B01C  arm
 *   _pNetState     0x021469DC  data
 *   str_0203B950   0x0203B950  data
 */

#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern struct Sys *_pNetState;
extern void GFL_NET_STATE_ExtendConnectTimer(void);
extern char str_0203B950[];

extern void *GFL_NET_GetSession(void);
extern u32   GFL_NET_SYSTEM_ConnectToParent(u32 a, u32 b, u32 c, u32 d);
typedef unsigned short u16;
extern u32 GFL_NET_SYSTEM_StartBeaconScan(u32 a0, u16 a1);
extern u32 GFL_NET_STATE_RollChildWaitTime(char *p);
extern u32 GFL_NET_STATE_RollParentWaitTime(char *p);
extern void  GFL_NET_STATE_ChangeStateDebug(u32 ctx, void *tag, u32 val, u32 line);

struct Vt {
    u8  pad_00[0x78];
    u32 (*f78)(void);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
};

struct Slot {
    u8  pad_00[0x53];
    u8  f53;
    u8  pad_54[2];
    u8  f56;
    u8  f57;
};

void GFL_NET_STATE_ChangeoverConnect(struct Slot *p)
{
    struct Obj *q = (struct Obj *)GFL_NET_GetSession();
    u32 n = 0x200;

    if (q->f340->f78() == 0)
        return;
    if (p->f53 == 0 || p->f56 == 1)
        goto alt;

    if (GFL_NET_SYSTEM_ConnectToParent(1, (u32)&p->f57, n, (u32)GFL_NET_STATE_ExtendConnectTimer) == 0)
        return;
    GFL_NET_STATE_ChangeStateDebug((*(u32 *)&_pNetState), str_0203B950, GFL_NET_STATE_RollChildWaitTime((char *)p), n + 0x45);
    return;

alt:
    if (GFL_NET_SYSTEM_StartBeaconScan(1, n) == 0)
        return;
    GFL_NET_STATE_ChangeStateDebug((*(u32 *)&_pNetState), str_0203B950, GFL_NET_STATE_RollParentWaitTime((char *)p), n + 0x4a);
}
