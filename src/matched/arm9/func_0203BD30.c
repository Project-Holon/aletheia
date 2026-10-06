/*
 * function: func_0203BD30
 * address:  0x0203BD30
 * packet:   pkt_0203BD30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC      0x021469DC  data
 *   func_0203D788   0x0203D788  arm
 *   func_0203AD80   0x0203AD80  arm
 *   func_0203BCE0   0x0203BCE0  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BD30.c \
 *       --func func_0203BD30 --addr 0x0203BD30 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_021469DC;

extern void *func_0203D788(void);
typedef unsigned short u16;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern void func_0203BCE0(u8 *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);

void func_0203BD30(u32 a0, u32 a1, u8 *a2)
{
    func_0203D788();

    g_021469DC[0x53] = (u8)a1;
    g_021469DC[0x56] = (u8)a0;

    if (a2 != 0)
        MI_CpuCopy8(a2, g_021469DC + 0x57, 6);
    else
        MI_CpuFill8(g_021469DC + 0x57, 0xFF, 6);

    if (g_021469DC[0x56] == 2)
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203B48C, 0, 0x430);

    if (g_021469DC[0x56] == 1) {
        func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203BCE0, 0, 0x438);
        func_0203BCE0(g_021469DC);
    }
}
