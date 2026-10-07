/*
 * file:     unit_021DDB38_p03.c
 * unit:     yes
 * function: func_021DE0D4, func_021DE0E8, func_021DE100
 * address:  0x021DE0D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E3978  0x021E3978  data
 *   func_02182AC0  0x02182AC0  arm
 *   func_02182CF0  0x02182CF0  arm
 *   g_021E3A8C     0x021E3A8C  data
 *   g_021E3B4C     0x021E3B4C  data
 *   g_021E3B54     0x021E3B54  data
 */
typedef unsigned int u32;

extern int func_021DDB10(void *, int);
extern void func_02182AC0(u32, u32 *, u32 *, u32);
extern void func_02182CF0(u32, u32 *, u32 *, u32);
void func_021DE0D4(void *p);
int func_021DE0E8(void *p);
int func_021DE100(char *p);
extern char d_021E3978[];
extern u32 g_021E3A8C[];
extern u32 g_021E3B4C[];
extern u32 g_021E3B54[];


/*
 * SDK provenance: DSP_MapProcessSegment (TwlSDK/libdsp.TWL.HYB.a, dsp_process.o),
 * ov175.  ARM tail-forwarder to func_021DDB10 with a fixed second argument.
 */
void func_021DE0D4(void *p)
{
    func_021DDB10(p, (int)d_021E3978);
}


/*
 * SDK provenance: sakeiDeleteRecordValidateInput (TwlDWC/libdwcgssake.TWL.HYB.a,
 * sakerequestmodif.o), ov175.  A null record reads as the "out of range" 4,
 * a live record as 0.
 */
int func_021DE0E8(void *p)
{
    return *(u32 *)(*(u32 *)((char *)p + 8)) != 0 ? 0 : 4;
}


/*
 * Forward the +0x08 block's first two words to the two ov009 record readers,
 * both keyed on the +0x18 handle.
 */
int func_021DE100(char *p)
{
    u32 *q = *(u32 **)(p + 8);

    func_02182AC0(*(u32 *)(p + 0x18), g_021E3A8C, g_021E3B4C, q[0]);
    func_02182CF0(*(u32 *)(p + 0x18), g_021E3A8C, g_021E3B54, q[1]);
    return 0;
}
