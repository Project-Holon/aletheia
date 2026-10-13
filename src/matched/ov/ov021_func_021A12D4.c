/*
 * function: FIELD_SUBSCREEN_LoadBackdrop
 * address:  0x021A12D4
 * packet:   pkt_ov021_021A12D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FIELDMAP_GetVReq  0x02188E30  thumb  ov021
 *   FLD_VREQ_SetMainBlendBrightnessExt  0x021D3270  thumb  ov021
 *   FLD_VREQ_SetBgVisible  0x021D3244  thumb  ov021
 *
 * Lever: func_020490F4 takes (id, heap); passing x as its second argument
 * is what gives x its register before the constant's.
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern void func_02049658(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heap);
extern void ARC_UTIL_UploadBgPaletteAddFromHandle(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *h);
typedef unsigned char  u8;
struct St021D3244;
extern u32 FIELDMAP_GetVReq(u8 *p);
extern void FLD_VREQ_SetMainBlendBrightnessExt(u32 a, int b, int c, int d, int e, int f);
extern void FLD_VREQ_SetBgVisible(struct St021D3244 *p, int i, u8 v);

void FIELD_SUBSCREEN_LoadBackdrop(u32 *p, u32 x)
{
    void *h = func_020490F4(0x47, x);
    ARC_UTIL_UploadPaletteFromHandle(h, 0, 0, 0x140, 0x140, 0x20, x);
    func_02049658(h, 3, 1, 0x64, 0, 0, x);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 0xf, 1, 0, 0x64, 0, 0, x);
    ARC_TOOL_DeleteHandle(h);
    FLD_VREQ_SetMainBlendBrightnessExt(FIELDMAP_GetVReq((u8 *)p[5]), 1, 0, 0, 0, -6);
    FLD_VREQ_SetBgVisible((struct St021D3244 *)FIELDMAP_GetVReq((u8 *)p[5]), 1, 1);
}
