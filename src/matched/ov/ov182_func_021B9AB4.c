/*
 * function: THE_END_GRAPHIC_InitActors
 * address:  0x021B9AB4
 * packet:   pkt_021B9AB4
 * region:   ov182
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B9C0C      0x021B9C0C  data
 *   MI_CpuFill8   0x02082BCC  arm
 *   CLACT_InitSystem   0x0204A48C  arm
 *   CLACT_CreateUnit   0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible   0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible   0x02043598  arm
 *
 * Bring up the graphics object: clear four words, submit the table and
 *   latch the 0x80-byte handle.
 */


extern unsigned char d_021B9C0C[];
extern void MI_CpuFill8(int, int, int);
typedef unsigned char  u8;
struct Bank;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
typedef unsigned int   u32;
struct Bank;
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void THE_END_GRAPHIC_InitActors(int *p, int b, int c)
{
    MI_CpuFill8((int)p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)d_021B9C0C, b, c);
    p[0] = (int)CLACT_CreateUnit(0x80, 0, c);
    CLACT_SetUnitDefaultRenderer((void *)p[0]);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
