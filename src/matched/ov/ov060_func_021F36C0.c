/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov060_021F36C0
 * region:   ov060
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
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GIMMICK60_GetIntrudeCommSys  0x021F3938  thumb  ov060
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnit  0x021BE310  thumb  ov021
 *   GIMMICK60_PlaceModels  0x021F37E4  thumb  ov060
 *   GIMMICK60_SetupEffect  0x021F3950  thumb  ov060
 *   d_021F3A34     0x021F3A34  data  a4
 */

typedef unsigned int u32;

extern char d_021F3A34[];

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Big;
struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *a);
extern void *GIMMICK60_GetIntrudeCommSys(void *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void FLD_EXP_OBJ_AddUnit(void *a, void *b, int c);
extern void GIMMICK60_PlaceModels(u8 *out, void *b, void *c, void *d);
extern void GIMMICK60_SetupEffect(void *a, void *b);

void func_021F36C0(void *a)
{
    u32 r6;
    void *s;
    u32 c;
    u32 h;
    void *v;
    void *o;

    r6 = FIELDMAP_GetHeapId(a);
    s = (void *)FIELDMAP_GetExpObj(a);
    c = (u32)FIELDMAP_GetGameSystem(a);
    h = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)c);
    GAME_DATA_GetFieldSave((struct Big *)h);
    v = GIMMICK60_GetIntrudeCommSys((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)c));
    o = FIELDMAP_AllocCommonWork(a, 0, r6, 4);
    FLD_EXP_OBJ_AddUnit(s, d_021F3A34, 0);
    GIMMICK60_PlaceModels(o, a, (void *)h, v);
    GIMMICK60_SetupEffect(o, s);
}
