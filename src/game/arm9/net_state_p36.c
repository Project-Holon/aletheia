/*
 * file:     net_state_p36.c
 * unit:     yes
 * function: func_0203D9EC, func_0203DA20, func_0203DA4C
 * address:  0x0203D9EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469F0  0x021469F0  data
 *   d_021469F0   0x021469F0  data  a4
 */
typedef unsigned char u8;

typedef unsigned int  u32;

extern void func_02034FB8(u32 v);
extern u32 func_020307B0(void *p);
void func_0203D9EC(void);
void func_0203DA20(void);
int func_0203DA4C(void);
extern u8 g_021469F0[];
extern u32 d_021469F0[];


/*
 * Tears down the net_irc_wireless singleton at 0x021469F0: releases it
 * through func_02034FB8(0x20) and the heap release, then clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D9EC.c \
 *       --func func_0203D9EC --addr 0x0203D9EC --arm --cc 1.1p1
 */
void func_0203D9EC(void)
{
    if (*(u32 *)g_021469F0 == 0) {
        return;
    }
    func_02034FB8(0x20);
    func_020307B0(*(void **)g_021469F0);
    *(u32 *)g_021469F0 = 0;
}


/*
 * Calls func_0203D9EC when the net_irc_wireless singleton exists and its
 * +0x101 byte is clear.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203DA20.c \
 *       --func func_0203DA20 --addr 0x0203DA20 --arm --cc 1.1p1
 */
void func_0203DA20(void)
{
    u8 *p = *(u8 **)g_021469F0;

    if (p == 0) {
        return;
    }
    if (p[0x101] != 0) {
        return;
    }
    func_0203D9EC();
}


int func_0203DA4C(void)
{
    return d_021469F0[0] != 0;
}
