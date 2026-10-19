/*
 * function: SCRCMD_POKEMON_FLD_RegisterRecordSpecies
 * address:  0x021B5C80
 * packet:   pkt_ov021_021B5C80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_GetTeam  0x0200C2D0  thumb
 *   WORDSET_SetSlotSpeciesName  0x0201EE60  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk34;
struct WordSet;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *GAME_DATA_GetMiscSave(int *p);
extern void BEACON_GetTeam(struct Blk34 *p, u32 i, u16 *dest);
extern void WORDSET_SetSlotSpeciesName(struct WordSet *p, u32 i, u16 v);

int SCRCMD_POKEMON_FLD_RegisterRecordSpecies(void *a, void *b)
{
    void *t;
    struct WordSet *w;
    unsigned int k;
    u16 *out;
    int i;
    int n;
    u16 arr[6];

    t = SCRCMD_WORK_GetGameData(b);
    w = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(b));
    k = SCRIPT_WORK_ReadWorkValue(a, b);
    out = SCRIPT_WORK_ReadWorkPointer(a, b);
    BEACON_GetTeam(GAME_DATA_GetMiscSave(t), k, arr);
    for (i = 0, n = 0; i < 6; i++) {
        if (arr[i] != 0) {
            WORDSET_SetSlotSpeciesName(w, n, arr[i]);
            n++;
        }
    }
    *out = n;
    return 0;
}
