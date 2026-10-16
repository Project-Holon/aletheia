/*
 * function: FLD_WIPE_3DOBJ_CreateMapChangeEvent
 * address:  0x021C8268
 * packet:   pkt_ov021_021C8268
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   FLD_WIPE_3DOBJ_MapChangeEventMain  0x021C82C4  thumb  ov021
 */

struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
typedef unsigned char  u8;
struct Ctx;
struct Obj;
struct Sub0200852CObj;
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
struct t;
extern void ZONEDATA_SetZoneStartLocation(struct t *p, int id);
typedef unsigned int   u32;
struct Ctx;
struct TaskCtx;
extern int FLD_WIPE_3DOBJ_MapChangeEventMain(u32 a, int *st, struct TaskCtx *c);

int FLD_WIPE_3DOBJ_CreateMapChangeEvent(void *a, int b, int c)
{
    int r7;
    int *r4;
    int v;

    r7 = (int)func_020122C0(a, 0, FLD_WIPE_3DOBJ_MapChangeEventMain, 0x30);
    r4 = func_020124E8((struct Obj *)r7);
    MI_CpuFill8(r4, 0, 0x30);
    r4[0] = (int)a;
    r4[2] = c;
    if (func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C((const struct Ctx *)a))) == 0) {
        r4[10] = 11;
        v = 12;
    } else {
        r4[10] = 18;
        v = 19;
    }
    r4[11] = v;
    ZONEDATA_SetZoneStartLocation((struct t *)(r4 + 3), (unsigned short)c);
    return r7;
}
