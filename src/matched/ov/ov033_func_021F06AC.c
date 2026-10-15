/*
 * function: DOWSING_InitBgsAndActorUnit
 * address:  0x021F06AC
 * packet:   pkt_ov033_021F06AC
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040618 0x02040618 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   sDowsingBgSetup 0x021F0DF0 data ov033 a4
 */
#include "../include/Obj09802.h"
#include "../include/G_ov033_021F0DF0.h"

typedef struct {
    unsigned f00;
    unsigned f04[8];
    unsigned f24;
    unsigned f28;
} E;

extern struct G_ov033_021F0DF0 sDowsingBgSetup[];
extern void func_02040588(unsigned char which, unsigned char enable);
struct BgTemplate;
extern void BG_SYS_InitBgLayer(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void func_02040618(unsigned char, unsigned, unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);

void DOWSING_InitBgsAndActorUnit(char *p)
{
    int i;
    unsigned id;
    E *e;
    unsigned j;
    for (i = 4; i <= 7; i++)
        func_02040588((unsigned char)i, (unsigned char)0);
    for (j = 0; j < 2; j++) {
        e = &((E *)sDowsingBgSetup)[j];
        id = e->f00;
        BG_SYS_InitBgLayer((unsigned char)id, (const struct BgTemplate *)e->f04, (unsigned char)e->f24);
        BG_SYS_FreeSlot(id);
        func_02040588((unsigned char)id, (unsigned char)e->f28);
        func_02040618(id, 0, 0);
        func_02040618(id, 3, 0);
    }
    ((struct Obj09802 *)p)->fC = CLACT_CreateUnit(8, 0, ((struct Obj09802 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(((struct Obj09802 *)p)->fC);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
