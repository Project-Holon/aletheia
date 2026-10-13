/*
 * unit:     no
 * function: func_0202C794
 * address:  0x0202C794
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMusicalWork  0x0201297C  thumb
 *   MOVE_POKEMON_FindEntryByZone  0x0215E6A8  thumb
 *   func_0202C8B8  0x0202C8B8  thumb
 *   func_0202C934  0x0202C934  thumb
 *   func_0202C970  0x0202C970  thumb
 *   func_0202C824  0x0202C824  thumb
 *   CALENDER_GetWeatherThunk  0x021647E8  thumb  ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *
 * note:     wave 16: promoted.  0x021647E8 is the unlabelled ov010 tail-call
 *           thunk matched in src/matched/CALENDER_GetWeatherThunk.c (`matched, overlay`
 *           under the ov010 hint); 0x0202C8B8 now resolves as `matched`.
 *
 * A chain of four probes, each returning a u8 reason code unless it comes
 * back 0xffff ("nothing to say"); the sentinel is kept in a callee-saved
 * register, which is why it is one pool word and four `cmp r0, r7`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetMusicalWork(const struct BigObj *p);
extern u32 MOVE_POKEMON_FindEntryByZone(u32 a, u16 b);
typedef signed int     s32;
extern s32 func_0202C8B8(void *a0, u32 a1, u32 a2);
extern s32 func_0202C934(void *a0, u32 a1, u32 a2);
extern u32 func_0202C970(void *a, void *b, u32 c);
extern int func_0202C824(int a0);
extern u32 CALENDER_GetWeatherThunk(void *arg, unsigned int b);
extern u32 ZONEDATA_GetWeatherId(u32 id);

u8 func_0202C794(void *a0, u32 a1)
{
    u32 ctx = (u32)GAMESYSTEM_GetGameData(a0);
    u32 saved = GAME_DATA_GetMusicalWork((const struct BigObj *)ctx);
    u32 r;

    r = MOVE_POKEMON_FindEntryByZone(ctx, (u16)a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C8B8(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C934(a0, ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    r = func_0202C970(a0, (void *)ctx, a1);
    if (r != 0xffff) {
        return (u8)r;
    }
    if (func_0202C824(ctx) != 0) {
        return (u8)CALENDER_GetWeatherThunk((void *)saved, (u16)a1);
    }
    return (u8)ZONEDATA_GetWeatherId((u16)a1);
}
