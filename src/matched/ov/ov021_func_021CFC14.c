/*
 * function: INTRUDE_StartOfferEvent
 * address:  0x021CFC14
 * packet:   pkt_ov021_021CFC14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_TakeOfferSlot  0x021CFB1C  thumb  ov021
 *   INTRUDE_OfferEventMain  0x021CFBA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Rec;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *INTRUDE_GetFromSave(void *sys);
extern void INTRUDE_TakeOfferSlot(void *a, void *b, void *c);
extern int INTRUDE_OfferEventMain(u32 a, u32 unused, const struct Rec *src);

void *INTRUDE_StartOfferEvent(void *a, void *unused, void *c)
{
    void *task = func_020122C0(a, 0, INTRUDE_OfferEventMain, 0x14);
    void *work = func_020124E8(task);

    INTRUDE_TakeOfferSlot(INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(a))), c, work);
    return task;
}
