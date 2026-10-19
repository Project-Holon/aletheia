/*
 * function: NAMEIN_GRAPHIC_AnimateGrid
 * address: 0x021F33C0
 * packet: pkt_ov194_021F33C0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wD4 lane09: EXACT. The calls in case 0 are written out in each arm of the f118 test (tail merge builds the shared movs r1,#0 join), so the join block holds only the state stores and the zero is not hoisted.
 * symbols:
 *   func_02040804 0x02040804 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   func_02040588 0x02040588 arm
 *   NAMEIN_GRAPHIC_SwitchGridMode 0x021F35A8 thumb ov194
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u32 func_02040804(u32 layer);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void NAMEIN_GRAPHIC_SwitchGridMode(char *, u32);
int NAMEIN_GRAPHIC_AnimateGrid(char *p) {
    int c;
    int y;
    if (*(u32 *)(p + 0x110) != 0)
    switch (*(u16 *)(p + 0x10c)) {
    case 0:
        func_02040804(1);
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        BG_SYS_ChangeScrollImmediate(1, 3, y);
        BG_SYS_ChangeScrollImmediate(3, 3, y);
        if (*(u32 *)(p + 0x118)) BG_SYS_ChangeScrollImmediate(2, 3, y);
        if ((*(u16 *)(p + 0x10a))++ > 7) {
            if (*(u32 *)(p + 0x118)) {
                func_02040588(1, 0);
                func_02040588(2, 0);
                func_02040588(3, 0);
            } else {
                func_02040588(1, 0);
                func_02040588(3, 0);
            }
            *(u16 *)(p + 0x10a) = 0;
            *(u16 *)(p + 0x10c) = 1;
        }
        break;
    case 1:
        y = -48;
        BG_SYS_ChangeScrollImmediate(1, 3, y);
        BG_SYS_ChangeScrollImmediate(3, 3, y);
        if (*(u32 *)(p + 0x118)) BG_SYS_ChangeScrollImmediate(2, 3, y);
        NAMEIN_GRAPHIC_SwitchGridMode(p, *(u32 *)(p + 0x114));
        *(u16 *)(p + 0x10c) = 2;
        break;
    case 2:
        *(u16 *)(p + 0x10a) = 7;
        *(u16 *)(p + 0x10c) = 3;
        func_02040588(1, 1);
        func_02040588(3, 1);
        if (*(u32 *)(p + 0x100) != 3) func_02040588(2, 1);
        *(u16 *)0x04000052 = 1 << 12;
        break;
    case 3:
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        BG_SYS_ChangeScrollImmediate(1, 3, y);
        BG_SYS_ChangeScrollImmediate(3, 3, y);
        if (*(u32 *)(p + 0x118)) BG_SYS_ChangeScrollImmediate(2, 3, y);
        if ((*(u16 *)(p + 0x10a))-- == 0) *(u16 *)(p + 0x10c) = 4;
        break;
    case 4:
        BG_SYS_ChangeScrollImmediate(1, 3, 0);
        BG_SYS_ChangeScrollImmediate(3, 3, 0);
        BG_SYS_ChangeScrollImmediate(2, 3, 0);
        *(u32 *)(p + 0x118) = 0;
        *(u16 *)0x04000050 = 0;
        *(u32 *)(p + 0x110) = 0;
        return 1;
    }
    return 0;
}
