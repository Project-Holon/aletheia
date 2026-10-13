/*
 * function: WIFICLUB_LoadPanelGraphics
 * address:  0x021BB4EC
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 */
typedef struct {
    char pad[0x9a8];
    int f9a8;               /* 0x9a8 */
} Work;

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *o);

void WIFICLUB_LoadPanelGraphics(Work *w)
{
    void *o = func_020490F4(0x21, 0x21);

    ARC_UTIL_UploadBgPaletteAddFromHandle(o, 0x16, 4, 0, (unsigned short)w->f9a8, 0, 0, 0x21);
    ARC_TOOL_DeleteHandle(o);
}
