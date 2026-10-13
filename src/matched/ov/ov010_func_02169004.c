/*
 * function: FIELD_CLOCK_UpdateDays
 * address:  0x02169004
 * packet:   pkt_ov010_02169004
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CLOCK_GetCounter  0x02169138  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_ClearTimeFlags  0x020143F0  thumb
 *   MOVE_POKEMON_SAVE_RollStartLocation  0x0200D440  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKERUS_DecreaseDays  0x0201B100  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008E30  0x02008E30  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200952C  0x0200952C  thumb
 *   FIELD_WFBC_DATA_LOCAL_AdvanceDays  0x021862A8  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E518  0x0200E518  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_0200AB04  0x0200AB04  thumb
 *
 * evidence: 0x0200E518 is an unlabelled ARM9 leaf ("push {r4, r5, r6, r7}",
 * no lr, right after the "pop {r4, pc}" at 0x0200E516) that the prologue
 * sweep misses.  The bl at +0x52 is its only reference in the image; its
 * start is seeded in layout/function_starts.txt, and the callee itself is
 * matched EXACT* (src/matched/arm9/func_0200E518.c), so +0x52 attests as
 * `matched`.
 */

struct BigObj;
struct Tally;
extern int FIELD_CLOCK_GetCounter(int a0);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
struct Rec0200AB04;
struct Sub02009470Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void ZONEDATA_ClearTimeFlags(u8 *a);
extern void MOVE_POKEMON_SAVE_RollStartLocation(void *sys);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void POKERUS_DecreaseDays(void *, int);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void func_02008E30(void *a0);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void func_0200952C(struct Sub02009470Obj *obj);
extern void FIELD_WFBC_DATA_LOCAL_AdvanceDays(int, int, int);
extern void *func_0200E394(void *a0);
extern void func_0200E518(struct Tally *t);
extern void *func_0200A8A0(void *sys);
extern void func_0200AB04(struct Rec0200AB04 *o);

void FIELD_CLOCK_UpdateDays(int a, int b)
{
    int x;
    FIELD_CLOCK_GetCounter(a);
    x = (int)GAME_DATA_GetSaveControl((struct Big *)a);
    ZONEDATA_ClearTimeFlags((u8 *)GAME_DATA_GetEventWork((const struct BigObj *)a));
    MOVE_POKEMON_SAVE_RollStartLocation((void *)x);
    POKERUS_DecreaseDays(GAME_DATA_GetMyParty((void *)a), b);
    func_02008E30(GAME_DATA_GetTrainerRecord((int *)a));
    func_0200952C(func_02009470((void *)x));
    FIELD_WFBC_DATA_LOCAL_AdvanceDays(a, b, 4);
    func_0200E518(func_0200E394((void *)x));
    func_0200AB04(func_0200A8A0((void *)x));
}
