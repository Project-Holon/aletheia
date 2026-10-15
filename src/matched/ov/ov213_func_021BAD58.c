/*
 * function: COMM_BTL_DEMO_GRAPHIC_InitClact
 * address:  0x021BAD58
 * packet:   pkt_ov213_021BAD58
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Closed by the recursive MATCH unblocker (0x021A0000..0x021BFFFF): the +003C
 * ABS32 0x021BB18C is data in this function's own overlay (ov213, a .word-run
 * start) and the ROM word at the site 0x021BAD94 already names it, so
 * `sole-ref/self` is the right class.  It only failed because the `ov213`
 * token on the symbols line made the hint contested (ov223 also starts a
 * func_021BB18C there) and this function loads no overlay id, so
 * self_hint_accepted() refused.  Dropping the token lets the function's own
 * region pick ov213 and the site resolves `sole-ref` with no outside evidence.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   d_021BB18C     0x021BB18C  data  a4
 */

extern void MI_CpuFill8(void *, int, int);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern int d_021BB18C;

void COMM_BTL_DEMO_GRAPHIC_InitClact(void **out, int a, int b)
{
    MI_CpuFill8(out, 0, 4);
    CLACT_InitSystem((const struct Cfg *)(&d_021BB18C), a, b);
    *out = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(*out);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}