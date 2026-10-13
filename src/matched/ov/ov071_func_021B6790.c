/*
 * function: MONOLITH_TOOL_InitText
 * address:  0x021B6790
 * packet:   pkt_ov071_021B6790
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   TCBL_Create  0x0203101C  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 */

typedef unsigned int   u32;
typedef unsigned short u16;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct WordSet;
void MONOLITH_TOOL_InitText(int *p)
{
    void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
    struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
    struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
    u32 PRINTSYS_QUE_Create(void *p);
    struct WordSet *func_0201EC64(u32 heap);
    struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

    GF_FONT_SetTextColor(0xf, 2, 0);
    p[6] = (int)TCBL_Create(0x61, 0x61, 4, 0x20);
    p[3] = (int)GF_FONT_Create(0x17, 0, 0, 0, 0x61);
    p[2] = PRINTSYS_QUE_Create((void *)0x61);
    p[4] = (int)func_0201EC64(0x61);
    p[7] = (int)func_02045B38(0, 2, 0x43, 0x61);
    p[8] = (int)func_02045B38(0, 2, 0xa0, 0x61);
    p[9] = (int)func_02045B38(0, 2, 0xa1, 0x61);
    p[10] = (int)func_02045B38(0, 2, 0x45, 0x61);
}
