/*
 * function: func_021BC5F0
 * address:  0x021BC5F0
 * packet:   pkt_ov223_021BC5F0
 * region:   ov223
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Closed by the recursive MATCH unblocker (0x021A0000..0x021BFFFF): the +003C
 * ABS32 0x021BC944 is data in this function's own overlay (ov223, a .word-run
 * start) and the ROM word at the site 0x021BC62C already names it, so
 * `sole-ref/self` is the right class.  It only failed because the `ov223`
 * token on the symbols line made the hint contested (ov088 also starts a
 * STARTMENU_ConfigPromptPulseColor there) and this function loads no overlay id, so
 * self_hint_accepted() refused.  Dropping the token lets the function's own
 * region pick ov223 and the site resolves `sole-ref` with no outside evidence.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   d_021BC944     0x021BC944  data  a4
 */

extern void MI_CpuFill8(void *, int, int);
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
extern int d_021BC944;

void func_021BC5F0(int *out, int a, int b)
{
    MI_CpuFill8(out, 0, 4);
    CLACT_InitSystem((const struct Cfg *)(&d_021BC944), a, b);
    *out = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)*out);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
