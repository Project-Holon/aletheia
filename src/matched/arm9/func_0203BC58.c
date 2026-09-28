/*
 * function: func_0203BC58
 * address:  0x0203BC58
 * packet:   pkt_0203B6EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BC58.c \
 *       --func func_0203BC58 --addr 0x0203BC58 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern u8 *func_0203D788(void);
extern void func_0203AD80(u32 a, u32 b, u32 c, u32 d);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void func_0203BBB0(u32 a);

void func_0203BC58(u8 v56, u8 v53, const void *src)
{
    func_0203D788();
    g_021469DC[0x53] = v53;
    g_021469DC[0x56] = v56;

    if (src != 0) {
        MI_CpuCopy8(src, g_021469DC + 0x57, 6);
    } else {
        MI_CpuFill8(g_021469DC + 0x57, 0xFF, 6);
    }

    func_0203AD80((u32)g_021469DC, 0x0203BBB0, 0, 0x406);
    func_0203BBB0((u32)g_021469DC);
}
