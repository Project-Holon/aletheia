/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_InitText
 * address: 0x021B7F7C
 * packet: pkt_ov103_021B7F7C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 */
typedef unsigned int u32;
extern void MI_CpuFill8(void *, int, u32);
extern void GF_FONT_InitTextColor(void);
struct GfFont;
struct MsgBank;
struct WordSet;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
void IRC_COMPATIBLE_TOUCH_TEST_InitText(u32 *p, int skip, u32 heap)
{
    MI_CpuFill8(p, 0, 16);
    GF_FONT_InitTextColor();
    if (skip == 0)
        p[0] = (u32)GF_FONT_Create(23, 0, 0, 0, heap);
    p[2] = PRINTSYS_QUE_Create((void *)heap);
    p[1] = (u32)func_02045B38(0, 2, 47, heap);
    p[3] = (u32)GF_FONT_Create_EC64(heap);
}
