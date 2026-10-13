/*
 * function: SCRCMD_POKEMON_FLD_GetPokedexComplete
 * address:  0x021B5EB8
 * packet:   pkt_ov021_021B5EB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200D2B0  0x0200D2B0  thumb
 *   func_0200D2C4  0x0200D2C4  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *func_0200CA1C(void *a);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int func_0200D298(void *a0);
extern int func_0200D2B0(void *a0, int a1);
extern int func_0200D2C4(void *p, unsigned int heap);
extern u16 FIELDMAP_GetHeapId(u8 *p);

int SCRCMD_POKEMON_FLD_GetPokedexComplete(u32 a, u32 b)
{
    u32 w;
    void *s;
    u16 *out;

    w = (u32)func_0200CA1C(SCRCMD_WORK_GetGameData((void *)b));
    s = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b));
    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    switch (SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b)) {
    case 1:
        *out = func_0200D298((void *)w);
        break;
    case 3:
        *out = func_0200D2B0((void *)w, FIELDMAP_GetHeapId(s));
        break;
    case 2:
        *out = func_0200D2C4((void *)w, FIELDMAP_GetHeapId(s));
        break;
    }
    return 0;
}
