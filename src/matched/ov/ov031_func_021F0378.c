/*
 * function: UNION_SUBDISP_LoadFrameBg
 * address:  0x021F0378
 * packet:   pkt_ov031_021F0378
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Both copy pointers are u16 element offsets (+0x2A0), not byte offsets:
 * `(u16 *)(out + 0xC) + 0x2A0` keeps the +0xC add apart, so the 0x540 byte
 * offset is built as `lsls rN, r7, #6` off the register holding 0x15
 * instead of folding with 0xC into a pooled 0x54C.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   func_02049658  0x02049658  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
extern u32 BG_SYS_CreateRun(u32 a, u32 b, u32 c);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 BG_SYS_GetBuf(int channel);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *p, u32 a, u32 b, void **out, u16 d);
extern void MI_CpuCopy8(void *src, void *dst, int n);
extern u32 func_020307B0(void *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void ARC_TOOL_DeleteHandle(void *h);

void UNION_SUBDISP_LoadFrameBg(u32 *p)
{
    void *h;
    u32 r;
    u16 *pal;
    void *res;
    u8 *out;
    int i;

    h = func_020490F4(0x53, 0x15);
    r = BG_SYS_CreateRun(5, 0x80, 1);
    p[1] = r;
    func_02049658(h, 0x1C, 5, r, 0x80, 0, 0x15);
    pal = (u16 *)BG_SYS_GetBuf(5);
    res = ARC_UTIL_LoadPaletteDataFromHandle(h, 0x1D, 0, (void **)&out, 0x15);
    MI_CpuCopy8((u16 *)(out + 0xC) + 0x2A0, pal + 0x2A0, 0xC0);
    func_020307B0(res);
    for (i = 0; i < 0x60; i++)
        pal[0x2A0 + i] = (pal[0x2A0 + i] & 0xFFF) + r + 0xD000;
    func_02049B68(h, 0x1B, 4, 0x1A0, 0x20, 0x15);
    ARC_TOOL_DeleteHandle(h);
}
