/*
 * function: GFL_NET_STATE_DeviceInitialized
 * address:  0x0203AF40
 * packet:   pkt_0203AF40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closes docs/notes/pkt_0203AF40.c.txt, which parked this at "DIFF, 10
 * concrete bytes" with an r4/r5 end-to-end swap and additionally predicted a
 * MATCH ceiling.  BOTH of those conclusions were wrong.
 *
 * 1. The r4/r5 swap was an artefact of that attempt's declaration order, not
 *    the real residue.  Declaring the two call results in source order
 *    (`s = GFL_NET_GetSession()` then `c = GFL_NET_GetInitParam()`) puts them in r5/r0
 *    exactly as the image does and the swap never appears.  That left a
 *    2-byte residue at +0x54/+0x58, not 10.
 *
 * 2. THE 2-BYTE RESIDUE: the image reloads the +0x2C callback into r1 and
 *    does `blx r1`, where the obvious C reloads into r0.  The tell is the
 *    `bl GFL_NET_GetUserArg` immediately before it whose result looks discarded.
 *    It is not discarded -- it is the callback's ARGUMENT.  Spelling the
 *    field `void (*f2c)(u32)` and writing `p->f2c(GFL_NET_GetUserArg())` pins r0
 *    to the argument, so the function pointer has to land in r1.  EXACT.
 *    This is the same shape src/pending/GFL_NET_STATE_ChangeoverParentConnectWait.c documents for its
 *    own callback ("takes GFL_NET_GetUserArg's return value in r0, which is why
 *    the function pointer is loaded into r1") -- a family idiom, not a
 *    one-off.
 *
 * 3. The note's MATCH-ceiling claim ("0x0203C00C is a data address with no
 *    outside witness") is also wrong: 0x0203C00C has TWENTY pool words
 *    image-wide (layout/data_objects.txt line 207 lists six plus twelve
 *    more) and resolves `literal x20, e.g. 0203B5CC`.  All 7 relocation
 *    sites resolve and the file is EXACT, not MATCH.
 *
 * The permuter was run before the hand fix and found nothing: --mode hill
 * --budget 800 (120 singles tried) and --mode anneal --budget 900 (900
 * compiles in 84s) both stayed flat at asm=10 bytes-out=2.  The lever is a
 * change to a function-pointer's SIGNATURE (arity), which is outside the
 * mutation table -- the same class of miss the permuter.md field reports
 * record for `cnt = *p++` and `int weight`.
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_SYSTEM_ResetAll  0x02037D78  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   unk_0203C00C   0x0203C00C  arm
 *   _pNetState     0x021469DC  data
 */

#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Sys *_pNetState;
extern void unk_0203C00C(void);

struct Vt {
    u8  pad_00[4];
    void (*f04)(u16 key, void *obj, u32 zero, u32 arg);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
    u8         pad_344[8];
    u32        f34c;
};

struct Cur {
    u8  pad_00[0x56];
    u16 f56;
    u8  pad_58[0xd];
    u8  f65;
};

struct Rec {
    u8  pad_00[0x2c];
    void (*f2c)(u32 a);
};

extern void *GFL_NET_GetSession(void);
extern void *GFL_NET_GetInitParam(void);
extern void GFL_NET_SYSTEM_ResetAll(void);
extern u32  GFL_NET_GetUserArg(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_DeviceInitialized(struct Rec *p)
{
    struct Obj *s = GFL_NET_GetSession();
    struct Cur *c = GFL_NET_GetInitParam();

    if (c->f65 != 1 && c->f65 != 2)
        s->f340->f04(c->f56, s, 0, s->f34c);
    GFL_NET_SYSTEM_ResetAll();
    if (p->f2c != 0) {
        p->f2c(GFL_NET_GetUserArg());
        p->f2c = 0;
    }
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(u32 *)&_pNetState), (void *)unk_0203C00C, 0, 0x12f);
}
