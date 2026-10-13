/*
 * function: SCRCMD_CreateSubProcEvent
 * address:  0x021C5BD0
 * packet:   pkt_ov021_021C5BD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns the SCRCMD_SubProcEventMain task with a 0x14-byte work area.
 *
 * symbols:
 *   SCRCMD_SubProcEventMain  0x021C5C08  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;
    void *f4;
    u32 f8;
    u16 hC;
    u16 pad;
    u32 f10;
} W;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void SCRCMD_SubProcEventMain(void);

void *SCRCMD_CreateSubProcEvent(void *a, u32 b, u32 c)
{
    void *t = func_020122C0(a, 0, SCRCMD_SubProcEventMain, 0x14);
    W *w = func_020124E8(t);

    w->owner = a;
    w->f4 = GAMESYSTEM_GetFieldMap(a);
    w->f10 = c;
    w->f8 = (u32)GAMESYSTEM_GetGameData(a);
    w->hC = b;
    return t;
}
