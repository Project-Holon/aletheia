/*
 * function: SCRCMD_POKEMON_FLD_GetPokedexRating
 * address:  0x021B5DF8
 * packet:   pkt_ov021_021B5DF8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case blocks are in source order 3, 2, 1; per-case stores to *o1 but a
 * single *o2 store after the switch is what spills o2 (register pressure)
 * and gives o1 r4.
 *
 * Case 3 reads gPokedexRatingTableKind3 and case 1 gPokedexRatingTableKind1 (pool words in that order);
 * the earlier draft had the two swapped, which only the relocation check saw.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   ZUKAN_SAVE_CountCaught  0x0200CF08  thumb
 *   ZUKAN_SAVE_IsNationalCaughtComplete  0x0200D298  thumb
 *   ZUKAN_SAVE_CountSeenRegional  0x0200D0F8  thumb
 *   ZUKAN_SAVE_IsRegionalSeenComplete  0x0200D2C4  thumb
 *   ZUKAN_SAVE_CountCaughtRegional  0x0200CF54  thumb
 *   ZUKAN_SAVE_IsRegionalCaughtComplete  0x0200D2B0  thumb
 *   SCRCMD_POKEMON_FLD_LookupThreshold  0x021B5DD0  thumb  ov021
 *   gPokedexRatingTableKind3     0x021D98DC  data  a4
 *   gPokedexRatingTableKind2     0x021D9904  data  a4
 *   gPokedexRatingTableKind1     0x021D992C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Blk37;
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern u16 ZUKAN_SAVE_CountCaught(struct Blk37 *p, u32 heap);
extern int ZUKAN_SAVE_IsNationalCaughtComplete(void *a0);
extern u16 ZUKAN_SAVE_CountSeenRegional(struct Blk37 *p, u32 heap);
extern int ZUKAN_SAVE_IsRegionalSeenComplete(void *p, unsigned int heap);
extern u16 ZUKAN_SAVE_CountCaughtRegional(struct Blk37 *p, u32 heap);
extern int ZUKAN_SAVE_IsRegionalCaughtComplete(void *a0, int a1);
extern u32 SCRCMD_POKEMON_FLD_LookupThreshold(u16 *t, u32 k);
extern u16 gPokedexRatingTableKind3[];
extern u16 gPokedexRatingTableKind2[];
extern u16 gPokedexRatingTableKind1[];

int SCRCMD_POKEMON_FLD_GetPokedexRating(u32 a, u32 b)
{
    u32 mode;
    u16 *o1;
    u16 *o2;
    u32 id;
    u32 w;
    u32 x;

    mode = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    o1 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    o2 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    id = SCRCMD_WORK_GetHeapId((void *)b);
    w = (u32)ZUKAN_SAVE_GetFromGameData(SCRCMD_WORK_GetGameData((void *)b));
    ZUKAN_SAVE_IsNationalDexEnabled((struct Blk37 *)w);
    *o1 = 5;
    *o2 = 0;
    switch (mode) {
    case 3:
        x = ZUKAN_SAVE_CountCaughtRegional((struct Blk37 *)w, id);
        if (ZUKAN_SAVE_IsRegionalCaughtComplete((void *)w, id) == 1)
            *o1 = 0x1e;
        else
            *o1 = SCRCMD_POKEMON_FLD_LookupThreshold(gPokedexRatingTableKind3, x);
        break;
    case 2:
        x = ZUKAN_SAVE_CountSeenRegional((struct Blk37 *)w, id);
        if (ZUKAN_SAVE_IsRegionalSeenComplete((void *)w, id) == 1)
            *o1 = 0xd;
        else
            *o1 = SCRCMD_POKEMON_FLD_LookupThreshold(gPokedexRatingTableKind2, x);
        break;
    case 1:
        x = ZUKAN_SAVE_CountCaught((struct Blk37 *)w, id);
        if (ZUKAN_SAVE_IsNationalCaughtComplete((void *)w) == 1)
            *o1 = 0x32;
        else
            *o1 = SCRCMD_POKEMON_FLD_LookupThreshold(gPokedexRatingTableKind1, x);
        break;
    default:
        return 0;
    }
    *o2 = x;
    return 0;
}
