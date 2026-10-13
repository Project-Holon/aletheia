/*
 * function: INTRUDE_FIELD_AddAreaMaps
 * address:  0x0217BBD8
 * packet:   pkt_ov018_0217BBD8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   func_02013D5C  0x02013D5C  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   INTRUDE_FIELD_IsInEdgeMargin  0x0217B94C  thumb  ov018
 *   MAP_MATRIX_Create  0x02159B48  thumb  ov010
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   MAP_MATRIX_Delete  0x02159BBC  thumb
 *   FIELD_G3D_MAPPER_AppendMatrix  0x0218CD20  thumb  ov021
 */

typedef unsigned char u8;
typedef struct { int x, y, z; } Vec;

extern unsigned int FIELDMAP_GetG3dMapper(u8 *p);
typedef unsigned short u16;
extern u16 FIELDMAP_GetZoneId(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *, struct VecFx32 *);
extern int INTRUDE_FIELD_IsInEdgeMargin(int *p);
extern u16 *MAP_MATRIX_Create(int a);
extern int MAP_MATRIX_Load(int a0, int a1, int a2, int a3);
extern void MAP_MATRIX_Delete(int);
extern void FIELD_G3D_MAPPER_AppendMatrix(int, int, int);

void INTRUDE_FIELD_AddAreaMaps(u8 *a, int b, u8 *c)
{
    Vec v;
    int n;
    void *h;
    int buf;

    if (c == 0 || a == 0)
        return;
    if (FIELDMAP_GetG3dMapper(a) == 0)
        return;
    if (func_02013D5C(FIELDMAP_GetZoneId((u8 *)a)) == 0)
        return;
    n = c[0x902] - 1;
    if (n <= 0)
        n = 1;
    if (((unsigned)(c[0x8f8] << 26) >> 31) == 1)
        n = 1;
    if (c[0x901] >= n)
        return;
    h = FIELDMAP_GetFieldPlayer((void *)a);
    if (h == 0)
        return;
    FIELD_PLAYER_GetPos(h, (struct VecFx32 *)&v);
    v.x = v.x % 0x400000;
    if (INTRUDE_FIELD_IsInEdgeMargin((int *)(&v)) == 1)
        return;
    buf = (int)MAP_MATRIX_Create(0x8015);
    MAP_MATRIX_Load(buf, 0x76, 0x76 + 0xa1, 0x8015);
    do {
        FIELD_G3D_MAPPER_AppendMatrix((int)a, FIELDMAP_GetG3dMapper(a), buf);
        c[0x901]++;
    } while (c[0x901] < n);
    MAP_MATRIX_Delete(buf);
}
