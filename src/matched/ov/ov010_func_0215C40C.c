/*
 * function: SCRCMD_PROC_CreateMonFromSpec
 * address: 0x0215C40C
 * packet: pkt_ov010_0215C40C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: POKE_TOOL_CreateEx's matched signature has two u64 inputs; widening the
 * personality result to u64 schedules its high zero before the low-word store.
 * symbols:
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   POKE_TOOL_CreatePersonalRnd 0x020186C8 thumb
 *   POKE_TOOL_CreateEx 0x02017430 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_GetPlaceNameId 0x02013E4C thumb
 *   func_0202F190 0x0202F190 thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Spec {
    u16 f00, pad02;
    u32 f04, f08, f0c, f10, f14, f18, f1c, f20;
} Spec;
typedef unsigned char  u8;
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void *POKE_TOOL_CreateEx(u16, u16, u64, u32, u64, u16);
extern void POKE_TOOL_SetPartyValue(void *, u32, u32);
extern int func_02020FE4(u16, u32, u16);
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);
struct SaveBlock;
struct Rec44;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void POKE_TOOL_RecalcParam(void *);
void *SCRCMD_PROC_CreateMonFromSpec(void *a, Spec *s)
{
    void *r7;
    void *r4;
    u32 t;
    r7 = GAME_DATA_GetMyStatus(a);
    r4 = (void *)func_02008530((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(a));
    t = POKE_TOOL_CreatePersonalRnd((u32)r4, (u16)s->f04, (u16)s->f08, (u32)s->f18, (u32)s->f14, (u32)s->f1c);
    r4 = POKE_TOOL_CreateEx(s->f04, s->f0c, (u32)r4, -1, t, s->f00);
    POKE_TOOL_SetPartyValue(r4, 0x6F, s->f08);
    POKE_TOOL_SetPartyValue(r4, 6, s->f10);
    if (func_02020FE4(s->f20, 0xF, s->f00) == 4)
        POKE_TOOL_SetPartyValue(r4, 0x98, (u32)PALANM_GetPairedCodeForFirst((u16)s->f20));
    func_0202F190(r4, 0, (u32)r7, ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(a))), s->f00);
    POKE_TOOL_RecalcParam(r4);
    return r4;
}
