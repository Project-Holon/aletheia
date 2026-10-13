/*
 * function: func_021A8214
 * address:  0x021A8214
 * packet:   pkt_ov021_021A8214
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb
 *   FIELD_BUILDMODEL_CreateNodeNearPos  0x0218C7D8  thumb
 */

typedef struct {
    int pad[3];
    int fc;
} R;

typedef struct {
    R *f0;
    int pad[6];
    int f1c[3];
    int f28;
} S;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int FIELD_BUILDMODEL_CreateNodeNearPos(void *p, int b, int c);

void func_021A8214(S *s)
{
    s->f28 = FIELD_BUILDMODEL_CreateNodeNearPos((void *)FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((u8 *)s->f0->fc)), 1, (int)s->f1c);
}
