/*
 * function: INTRUDE_FIELD_AddAreaMapCount
 * address:  0x0217BC94
 * packet:   pkt_ov018_0217BC94
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAP_MATRIX_Create  0x02159B48  thumb  ov010
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   MAP_MATRIX_Delete  0x02159BBC  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_AppendMatrix  0x0218CD20  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 *MAP_MATRIX_Create(int a);
extern int MAP_MATRIX_Load(int a0, int a1, int a2, int a3);
extern void MAP_MATRIX_Delete(int);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern void FIELD_G3D_MAPPER_AppendMatrix(int, int, int);

void INTRUDE_FIELD_AddAreaMapCount(int a, int n)
{
    int r;

    if (n >= 3)
        n = 2;
    r = (int)MAP_MATRIX_Create(0x15);
    MAP_MATRIX_Load(r, 0x76, 0x76 + 0xa1, 0x8015);
    while (n > 0) {
        FIELD_G3D_MAPPER_AppendMatrix(a, FIELDMAP_GetG3dMapper((u8 *)a), r);
        n--;
    }
    MAP_MATRIX_Delete(r);
}
