/*
 * function: MONOLITH_TOOL_SetHighlightMode
 * address:  0x021B6DB4
 * packet:   pkt_ov071_021B6DB4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   MONOLITH_TOOL_GetHighlightColorA  0x021B6E00  thumb  ov071
 *   MONOLITH_TOOL_GetHighlightColorCount  0x021B6E18  thumb  ov071
 *   PALANM_BlendChannel  0x02021FD8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct Chan02021FD8;
void MONOLITH_TOOL_SetHighlightMode(int *p, int a, int idx)
{
    void MI_CpuFill8(void *, int, int);
    int MONOLITH_TOOL_GetHighlightColorA(unsigned int x);
    int MONOLITH_TOOL_GetHighlightColorCount(int);
    void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
    u8 *e;

    e = (u8 *)p + 0xC + idx * 8;
    MI_CpuFill8(e, 0, 8);
    e[2] = a;
    PALANM_BlendChannel((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)MONOLITH_TOOL_GetHighlightColorA(idx), (u16)MONOLITH_TOOL_GetHighlightColorCount(idx), 0, 0);
}
