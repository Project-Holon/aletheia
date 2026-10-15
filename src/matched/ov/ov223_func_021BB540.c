/*
 * function: PSEL_GRAPHIC_LoadFadeSources
 * address: 0x021BB540
 * packet: pkt_ov223_021BB540
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02061CA4 0x02061CA4 arm
 *   d_021BC73C 0x021BC73C data a1
 *   d_021BC6FC 0x021BC6FC data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent { u8 a, b, c, d, e; };
extern const struct Ent d_021BC73C[3];
extern const u8 d_021BC6FC[];
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *, void *, unsigned);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern int func_02061CA4(void *, unsigned, unsigned, int);
void PSEL_GRAPHIC_LoadFadeSources(u8 *p)
{
    void *object = func_020490F4(205, *(u16 *)p);
    u8 i;
    for (i = 0; i < 3; i++) {
        u8 *out;
        void *buffer = ARC_UTIL_LoadPaletteBlockFromHandle(object, d_021BC73C[i].b, (u32)&out, *(u16 *)p);
        MI_CpuCopy8(*(u8 **)(out + 0xC), p + 0x74 + i * 0x94, 0x20);
        func_020307B0(buffer);
        buffer = ARC_UTIL_LoadPaletteBlockFromHandle(object, d_021BC73C[i].e, (u32)&out, *(u16 *)p);
        MI_CpuCopy8(*(u8 **)(out + 0xC), p + 0x94 + i * 0x94, 0x20);
        func_020307B0(buffer);
    }
    ARC_TOOL_DeleteHandle(object);
    for (i = 0; i < 3; i++) {
        *(u16 *)(p + 0xD4 + i * 0x94) = 2;
        *(u16 *)(p + 0xD6 + i * 0x94) = 0x10;
    }
    for (i = 0; i < 3; i++) {
        MI_CpuCopy8(p + 0x94 + i * 0x94, p + 0xB4 + i * 0x94, 0x20);
        func_02061CA4((void *)0x1E, d_021BC6FC[i] << 5, (u32)(p + 0xB4 + i * 0x94), 0x20);
    }
}
