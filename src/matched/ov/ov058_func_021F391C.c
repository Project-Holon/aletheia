/*
 * function: FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains
 * address:  0x021F391C
 * packet:   pkt_ov058_021F391C
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     places four entries (i, j, i + 2, j + 2) and rotates each by a
 *           (sin, cos) pair of the arm9 table at 0x020A1B38: pair 0x400 for
 *           the first two, pair 0xC00 for the last two (the pool words
 *           0x020A2B38 / 0x020A4B38 are that table plus 0x1000 / 0x3000).
 *           The cos values are separate locals y and y2 (two stack slots)
 *           while the sin value reuses x in r7; y declared before x puts x
 *           in r7 (x first swaps them). The function is 264 bytes, the rest
 *           of the handed 612 is data.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   func_0207AF1C  0x0207AF1C  thumb
 *   FX_SinCosTable_     0x020A1B38  data  a2
 */

typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern s16 FX_SinCosTable_[];

typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void  FLD_EXP_OBJ_SetModelCullDraw(void *p, int i, u16 j, int v);
extern void  func_0207AF1C(void *m, int a, int b);

void FIELD_GIMMICK_LANE_TRAINS_PlaceLaneTrains(void *unused, void *a, int i, int j)
{
    void *s;
    V *e;
    int y;
    int x;
    int y2;

    FIELDMAP_GetHeapId(a);
    s = (void *)FIELDMAP_GetExpObj(a);

    e = (V *)FLD_EXP_OBJ_GetModelStatus(s, (int)0, (u16)i);
    e->a = 0x1770000;
    e->b = 0x50000;
    e->c = 0x2100000;
    x = FX_SinCosTable_[0x800];
    y = FX_SinCosTable_[0x801];
    func_0207AF1C((char *)e + 0x18, x, y);
    FLD_EXP_OBJ_SetModelCullDraw(s, 0, i, 1);

    e = (V *)FLD_EXP_OBJ_GetModelStatus(s, (int)0, (u16)j);
    e->a = 0x1710000;
    e->b = 0x50000;
    e->c = 0x2100000;
    func_0207AF1C((char *)e + 0x18, x, y);
    FLD_EXP_OBJ_SetModelCullDraw(s, 0, j, 1);

    e = (V *)FLD_EXP_OBJ_GetModelStatus(s, (int)0, (u16)(i + 2));
    e->a = 0x1C60000;
    e->b = 0x50000;
    e->c = 0x20B0000;
    x = FX_SinCosTable_[0x1800];
    y2 = FX_SinCosTable_[0x1801];
    func_0207AF1C((char *)e + 0x18, x, y2);
    FLD_EXP_OBJ_SetModelCullDraw(s, 0, i + 2, 1);

    e = (V *)FLD_EXP_OBJ_GetModelStatus(s, (int)0, (u16)(j + 2));
    e->a = 0x1CC0000;
    e->b = 0x50000;
    e->c = 0x20B0000;
    func_0207AF1C((char *)e + 0x18, x, y2);
    FLD_EXP_OBJ_SetModelCullDraw(s, 0, j + 2, 1);
}
