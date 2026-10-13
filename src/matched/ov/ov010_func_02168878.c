/*
 * function: FLD_BTL_INST_TOOL_CreateTrainer
 * address:  0x02168878
 * packet:   pkt_ov010_02168878
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_BTL_INST_TOOL_InitTrainerHeader  0x021688BC  thumb
 *   FLD_BTL_INST_TOOL_DrawTrainerParty  0x02168924  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int FLD_BTL_INST_TOOL_InitTrainerHeader(u8 *, int, u16);
extern int FLD_BTL_INST_TOOL_DrawTrainerParty(int, int, u8 *, u8, int, int, int, u16);
extern u32 func_020307B0(void *p);

int FLD_BTL_INST_TOOL_CreateTrainer(u8 *a, int b, int c, int d, int e, int f, u16 g)
{
    int t = FLD_BTL_INST_TOOL_InitTrainerHeader(a, b, g);
    int r = FLD_BTL_INST_TOOL_DrawTrainerParty(t, b, a + 0x30, (u8)c, d, e, f, g);
    func_020307B0((void *)t);
    return r;
}
