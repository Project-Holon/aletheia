/*
 * function: FLD_BTL_INST_TOOL_CreatePartySelectStepEvent
 * address:  0x02168BF0
 * packet:   pkt_ov010_02168BF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   FLD_BTL_INST_TOOL_PartySelectStepEventMain  0x02168C74  thumb ov010
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Desc;

typedef struct {
    void *f0;
    void *f4;
    int f8;
    u16 *fc;
    int f10;
    int f14;
    void *f18;
    void *f1c;
    u32 pad[4];
    int f30;
} R;

struct Big;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern void FLD_BTL_INST_TOOL_PartySelectStepEventMain(void);

struct Desc *FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(int a, int b, int c, int d, u16 *e)
{
    struct Desc *hd;
    void *h;
    R *p;
    int k;
    void *v;
    h = GAMESYSTEM_GetGameData((void *)a);
    hd = func_020122C0((void *)a, 0, (void *)FLD_BTL_INST_TOOL_PartySelectStepEventMain, 0x34);
    p = func_020124E8((struct Obj *)hd);
    p->f0 = (void *)a;
    p->f4 = GAMESYSTEM_GetFieldMap((void *)a);
    p->fc = e;
    p->f30 = b;
    if (c == 0x14 || c == 0x15) {
        if (c == 0x14) {
            p->f10 = 0;
            k = 0x14;
        } else {
            p->f10 = 1;
            k = 0x15;
        }
    } else {
        p->f10 = 0;
        k = 0x14;
    }
    p->f14 = k;
    if (d == 0) {
        p->f1c = 0;
        v = GAME_DATA_GetMyParty(h);
    } else {
        v = func_0200BAF4((int)func_0200BAC8(GAME_DATA_GetSaveControl(h)), 5);
        p->f1c = v;
    }
    p->f18 = v;
    return hd;
}
