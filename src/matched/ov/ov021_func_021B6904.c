/*
 * function: SCRCMD_POKEMON_FLD_MoveLegendToFront
 * address:  0x021B6904
 * packet:   pkt_ov021_021B6904
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   SCRCMD_POKEMON_FLD_FindPartyLegend  0x021B6934  thumb ov021
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb ov010
 *   func_0201AB8C  0x0201AB8C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
struct Party;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern int SCRCMD_POKEMON_FLD_FindPartyLegend(void *);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);

void SCRCMD_POKEMON_FLD_MoveLegendToFront(void *a)
{
    void *t;
    void *u;
    int r;

    t = SCRCMD_WORK_GetGameData(a);
    u = GAME_DATA_GetMyParty(t);
    r = SCRCMD_POKEMON_FLD_FindPartyLegend(t);
    if (r >= 0) {
        func_0201AB8C(u, r, 0, SCRCMD_WORK_GetHeapId(a));
    }
}
