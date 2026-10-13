/*
 * file:     field_bbd_color.c
 * unit:     yes
 * function: FIELD_BBD_COLOR_Create, FIELD_BBD_COLOR_Delete, FIELD_BBD_COLOR_Load, FIELD_BBD_COLOR_Apply
 * address:  0x021CD1C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): __FILE__ anchor 021CD1EC (d_021DE5D4 "field_bbd_color.c").
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DE5D4  0x021DE5D4  data  ov021
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   VEC_Fx16Normalize  0x0207CDB8  arm
 *   func_0204ED4C  0x0204ED4C  arm
 *   func_0204ED80  0x0204ED80  arm
 *   func_0204ED8C  0x0204ED8C  arm
 *   func_0204ED98  0x0204ED98  arm
 *   func_0204EDA4  0x0204EDA4  arm
 */
struct ArcFile;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct FieldBbdRgb {
    u16 r;
    u16 g;
    u16 b;
} FieldBbdRgb;

/* One member of archive 0xAF: billboard light vector and material colors. */
typedef struct FieldBbdColorData {
    int lightVector[3];
    FieldBbdRgb diffuse;
    FieldBbdRgb ambient;
    FieldBbdRgb specular;
    FieldBbdRgb emission;
} FieldBbdColorData;

/* 0x28 bytes. */
typedef struct FieldBbdColor {
    struct ArcFile *arc;
    FieldBbdColorData data;
} FieldBbdColor;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern void VEC_Fx16Normalize(u16 *a, u16 *b);
extern void func_0204ED4C(u8 *a0, short *a1);
extern void func_0204ED80(u8 *dst, u16 *src);
extern void func_0204ED8C(u8 *dst, u16 *src);
extern void func_0204ED98(u8 *dst, u16 *src);
extern void func_0204EDA4(u8 *dst, u16 *src);

FieldBbdColor *FIELD_BBD_COLOR_Create(u32 heapId);
int FIELD_BBD_COLOR_Delete(FieldBbdColor *bbdColor);
void FIELD_BBD_COLOR_Load(FieldBbdColor *bbdColor, u32 colorId);
void FIELD_BBD_COLOR_Apply(FieldBbdColor *bbdColor, void *bbdSys);

extern const char d_021DE5D4[];

/* Opens archive 0xAF for the billboard color sets. */
FieldBbdColor *FIELD_BBD_COLOR_Create(u32 heapId)
{
    FieldBbdColor *bbdColor = func_02030734(heapId, 0x28, 1, d_021DE5D4, 0x5b);
    bbdColor->arc = func_020490F4(0xaf, heapId);
    return bbdColor;
}

int FIELD_BBD_COLOR_Delete(FieldBbdColor *bbdColor)
{
    ARC_TOOL_DeleteHandle(bbdColor->arc);
    return func_020307B0(bbdColor);
}

void FIELD_BBD_COLOR_Load(FieldBbdColor *bbdColor, u32 colorId)
{
    ARC_TOOL_ReadHandleMember(bbdColor->arc, colorId, &bbdColor->data);
}

/* Applies the loaded light vector (normalized) and the four material colors as GX RGB555. */
void FIELD_BBD_COLOR_Apply(FieldBbdColor *bbdColor, void *bbdSys)
{
    u16 lightVector[3];
    u16 color[4];

    lightVector[0] = bbdColor->data.lightVector[0];
    lightVector[1] = bbdColor->data.lightVector[1];
    lightVector[2] = bbdColor->data.lightVector[2];
    VEC_Fx16Normalize(lightVector, lightVector);
    func_0204ED4C(bbdSys, (short int *)lightVector);
    color[3] = bbdColor->data.diffuse.r | (bbdColor->data.diffuse.g << 5) | (bbdColor->data.diffuse.b << 10);
    func_0204ED80(bbdSys, &color[3]);
    color[2] = bbdColor->data.ambient.r | (bbdColor->data.ambient.g << 5) | (bbdColor->data.ambient.b << 10);
    func_0204ED8C(bbdSys, &color[2]);
    color[1] = bbdColor->data.specular.r | (bbdColor->data.specular.g << 5) | (bbdColor->data.specular.b << 10);
    func_0204ED98(bbdSys, &color[1]);
    color[0] = bbdColor->data.emission.r | (bbdColor->data.emission.g << 5) | (bbdColor->data.emission.b << 10);
    func_0204EDA4(bbdSys, &color[0]);
}
