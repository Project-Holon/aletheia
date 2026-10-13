/*
 * function: MONOLITH_TOOL_SLOT_SELECT_ShowMessage
 * address:  0x021B79A0
 * packet:   pkt_ov071_021B79A0
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   func_02040588  0x02040588  arm
 *   d_021BABF4     0x021BABF4  data  a1
 */

typedef unsigned int u32;

struct MsgBank;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char func_02012FFC(void);
extern void *PRINTSYS_PrintStream(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u32 a8, u32 a9);
extern void func_02040588(unsigned char which, unsigned char enable);
extern char d_021BABF4[];

void MONOLITH_TOOL_SLOT_SELECT_ShowMessage(void **p, int *c, int idx)
{
    if (p[2] != 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    GF_FONT_SetTextColor(1, 2, 15);
    p[1] = func_02045EC0((void *)c[0x28 / 4], idx);
    p[2] = PRINTSYS_PrintStream(p[0], 0, 0, p[1], c[0xc / 4], func_02012FFC(), (void *)c[0x18 / 4], 10, 0x61, 15);
    func_02040588(5, 1);
}
