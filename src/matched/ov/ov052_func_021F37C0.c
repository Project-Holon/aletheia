/*
 * function: FIELD_GIMMICK_BSUBWAY_StartTrain
 * address:  0x021F37C0
 * packet:   pkt_ov052_021F37C0
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_GIMMICK_BSUBWAY_FindZoneEntry  0x021F3998  thumb  ov052
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_BTRAIN_Start  0x021D0218  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void FIELD_GIMMICK_BSUBWAY_FindZoneEntry(int, int *, int *);
extern char *GIMMICK_WORK_GetSaveArea(unsigned, int);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern int FLDEFF_BTRAIN_Start(int, int, int);

void FIELD_GIMMICK_BSUBWAY_StartTrain(void *a, int b, int c)
{
    int s1;
    int s0;
    unsigned h;
    int *r5;

    FIELDMAP_GetHeapId(a);
    h = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a)));
    FIELD_GIMMICK_BSUBWAY_FindZoneEntry(FIELDMAP_GetZoneId(a), &s0, &s1);
    r5 = *(int **)(GIMMICK_WORK_GetSaveArea(h, s0) + 0x24);
    *r5 = FLDEFF_BTRAIN_Start(FIELDMAP_GetEffect(a), b, c);
}
