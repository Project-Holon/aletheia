/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov058_021F36C0
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   GIMMICK58_PlaceTrains  0x021F38F4  thumb  ov058
 *   d_021F3B60  0x021F3B60  data  ov058  a4
 */

typedef unsigned short u16;

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void FLD_EXP_OBJ_AddUnitFromArchive(int a, void *b, int c);
extern void GIMMICK58_PlaceTrains(void *unused, void *a);
extern char d_021F3B60[];

void func_021F36C0(int a)
{
    int r4;
    void *r6;

    FIELDMAP_GetHeapId((u8 *)a);
    r4 = FIELDMAP_GetExpObj((int *)a);
    GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a)));
    FIELDMAP_AllocCommonWork((unsigned char *)a, 1, FIELDMAP_GetHeapId((u8 *)a), 0x20);
    r6 = FIELDMAP_GetCommonWork((char *)a, 1);
    FLD_EXP_OBJ_AddUnitFromArchive(r4, d_021F3B60, 0);
    GIMMICK58_PlaceTrains(r6, (void *)a);
}
