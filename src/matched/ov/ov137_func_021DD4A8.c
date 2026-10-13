/*
 * function: func_021DD4A8
 * address: 0x021DD4A8
 * packet: pkt_ov137_021DD4A8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P13 B4: the older draft was DIFF 2/200 (v in r4 instead
 *   of r5). `i = 0;` assigned before `table = ...` (so the counter web starts
 *   while v is live) and `for (; i < 5; ...)` gives EXACT in c99 and c. v is a
 *   plain u8 (the enum local is not needed). Callees: 02008550 returns u8-range
 *   index, 0204B100 returns a pointer, others as in matched callers.
 * symbols:
 * GAME_DATA_GetMyStatus 0x02012944 thumb
 * func_02008550 0x02008550 thumb
 * func_020490F4 0x020490F4 arm
 * CLACT_InitSystem 0x0204A48C arm
 * CLACT_CreateUnit 0x0204B100 arm
 * CLACT_RegisterCharacter 0x0204A6C8 arm
 * CLACT_RegisterPaletteEx 0x0204AC18 arm
 * CLACT_RegisterCellAnim 0x0204AF28 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * gClActorInitParam 0x020A1448 data a4
 * d_021E1B40 0x021E1B40 data a4
 * d_021E1B20 0x021E1B20 data a4
 * d_021E1B30 0x021E1B30 data a4
 * d_021E1B38 0x021E1B38 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *GAME_DATA_GetMyStatus(void *);
struct Bank;
struct Cfg;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020490F4(u32 id, u32 heap);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern const u32 gClActorInitParam[],d_021E1B40[],d_021E1B20[],d_021E1B30[],d_021E1B38[];
void func_021DD4A8(const u8 *p)
{
    u8 v;
    long i;
    u32 a,b;
    const u32 *table;
    void *arc;
    v=func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(*(void **)(*(u8 **)(*(u8 **)(p+12)+20)+4)));
    arc=func_020490F4(31,114);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)d_021E1B40,114);
    *(void **)(p+104)=CLACT_CreateUnit(30,1,114);
    i=0;
    table=d_021E1B20+v;
    a=table[0]; b=table[2];
    for(;i<5;i++) {
        *(int *)(p+i*4+128)=CLACT_RegisterCharacter(arc,a,0,0,114);
        *(int *)(p+i*4+108)=CLACT_RegisterPaletteEx(arc,b,0,(u16)(i*32),0,1,114);
    }
    *(int *)(p+148)=CLACT_RegisterCellAnim(arc,d_021E1B30[v],d_021E1B38[v],114);
    ARC_TOOL_DeleteHandle(arc);
    *(void **)(p+52)=func_020490F4(32,114);
}
