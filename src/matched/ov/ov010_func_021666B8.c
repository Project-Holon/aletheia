/*
 * function: SYMBOL_MAP_RecordTaskMain
 * address: 0x021666B8
 * packet: pkt_ov010_021666B8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * former blocker: overlay ID 0xCB reaches GAME_EVENT_CallProc r1, absent from
 * OVERLAY_ID_CONSUMERS. The ov203-qualified descriptor at 0x021BFB3C
 * resolves sole-ref; its first word names ov203 func_021BDA40.
 * Store the flag in each branch to retain the original materialisation.
 * SYMBOL_MAP_StoreResult has an s16 parameter in its own source, but this caller
 * loads the complete f10 word without narrowing; its extern stays int.
 * symbols:
 *   func_020124E8 0x020124E8 thumb
 *   GAME_EVENT_CallProc 0x02012444 thumb
 *   SYMBOL_MAP_StoreResult 0x02166714 thumb ov010
 *   ov203_id 0x000000CB data a1
 *   gDemo3dProcData 0x021BFB3C data ov203 a4
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Work {
    u8 pad00[0x10];
    u32 f10;
    u32 f14;
    u32 f18;
    u16 *f1c;
};
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void SYMBOL_MAP_StoreResult(u8 *p, int n);
extern u8 ov203_id[];
extern u8 gDemo3dProcData[];
int SYMBOL_MAP_RecordTaskMain(void *task, u32 *state)
{
    struct Work *w = func_020124E8(task);
    switch (*state) {
    case 0:
        GAME_EVENT_CallProc(task, (u32)ov203_id, (u32)gDemo3dProcData, (u32)w);
        *state = *state + 1;
        break;
    case 1:
        if (w->f14 == 2) *w->f1c = 1;
        else *w->f1c = 0;
        SYMBOL_MAP_StoreResult((u8 *)w->f18, w->f10);
        return 1;
    }
    return 0;
}
