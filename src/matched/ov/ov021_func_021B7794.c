/*
 * function: PDW_POSTMAN_CreateListEvent
 * address:  0x021B7794
 * packet:   pkt_ov021_021B7794
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   PDW_POSTMAN_CreateReceivableList  0x021B7640  thumb
 *   PDW_POSTMAN_ListEvent  0x021B7574  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

struct Rec { unsigned short *f0; char pad04[4]; void *f8; char fC[4]; u16 f10; };

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Work;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Big;
struct Sub02009448Obj;
struct Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned char  u8;
struct Pair;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern struct Pair *PDW_POSTMAN_CreateReceivableList(u32 a, u32 b, u32 c, int *d);
extern int PDW_POSTMAN_ListEvent(void *task, int *st, struct Work *w);

void *PDW_POSTMAN_CreateListEvent(void *p)
{
    void *a;
    void *b;
    void *res;
    struct Rec *r;

    a = GAMESYSTEM_GetGameData(p);
    b = func_02009448(GAME_DATA_GetSaveControl(a));
    res = func_020122C0(p, 0, (void *)PDW_POSTMAN_ListEvent, 0x14);
    r = func_020124E8(res);
    r->f0 = GAMESYSTEM_GetFieldMap(p);
    r->f10 = 0;
    r->f8 = PDW_POSTMAN_CreateReceivableList((u32)a, FIELDMAP_GetHeapId((u8 *)r->f0), (u32)b, (int *)r->fC);
    return res;
}
