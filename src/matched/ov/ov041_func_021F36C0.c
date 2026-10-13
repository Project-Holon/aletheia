/*
 * function: FIELD_GIMMICK_CANNONS_Init
 * address:  0x021F36C0
 * packet:   pkt_ov041_021F36C0
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The counter is 32-bit with a u8 wraparound increment, so its (u16)
 * conversion is a separate value and the counter spills to [sp+4]; a u8
 * counter stays in a register.  i = 0 sits between the BE760 call and the
 * table copy (the store is scheduled above the call into r2); as the for
 * initialiser it lands after the copy loop.  s declared last puts it in r5.
 *
 * symbols:
 *   gGimmick41UnitSetup     0x021F40A4  data  a4
 *   gGimmick41CannonPos     0x021F4208  data  a4
 *   gGimmick41CannonQuarterTurns     0x021F4660  data  a1
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    V v[10];
} T;

extern int gGimmick41UnitSetup;
extern T gGimmick41CannonPos;
extern u8 gGimmick41CannonQuarterTurns[];
extern s16 FX_SinCosTable_[];

extern int FIELDMAP_GetExpObj(int *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *p, void *a, int b);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void  FLD_EXP_OBJ_SetModelCullDraw(void *p, int i, u16 j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern void  func_0207AF1C(void *m, int a, int b);

void FIELD_GIMMICK_CANNONS_Init(void *a0)
{
    char *e;
    unsigned int i;
    u8 j;
    int k;
    T tbl;
    void *s;

    s = (void *)FIELDMAP_GetExpObj(a0);
    FIELDMAP_AllocCommonWork(a0, 1, FIELDMAP_GetHeapId(a0), 0x730);
    FLD_EXP_OBJ_AddUnitFromArchive(s, &gGimmick41UnitSetup, 0);
    i = 0;
    tbl = gGimmick41CannonPos;
    for (; i < 10; i = (u8)(i + 1)) {
        e = (char *)FLD_EXP_OBJ_GetModelStatus(s, (int)0, (u16)i);
        FLD_EXP_OBJ_SetModelCullDraw(s, 0, i, 1);
        *(V *)e = tbl.v[i];
        k = ((gGimmick41CannonQuarterTurns[i] << 14) >> 4) * 2;
        func_0207AF1C(e + 0x18, FX_SinCosTable_[k], FX_SinCosTable_[k + 1]);
        for (j = 0; j < 4; j++) {
            FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(s, 0, (u16)i, (u16)(j * 2)), 0);
            FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(s, 0, (u16)i, (u16)(j * 2 + 1)), 0);
        }
    }
}
