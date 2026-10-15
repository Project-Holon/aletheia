/*
 * function: STAFF_ROLL_StepWindowSlide
 * address: 0x021BA83C
 * packet: pkt_ov181_021BA83C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display register stores at 04000050 and 04000052.
 * symbols:
 *   STAFF_ROLL_ReloadGraphics 0x021B9A80 thumb ov181
 *   func_0207D63C 0x0207D63C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   BUTTON_MAN_RotScaleMtx22 0x02051E74 arm
 *   BG_SYS_SetScrollRegs 0x02040860 arm
 */
#include "../include/Obj00682.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
struct Mtx22 { int m[4]; };
extern void STAFF_ROLL_ReloadGraphics(void *, int);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *, unsigned, const void *, const void *, u8);
extern void BG_SYS_SetScrollRegs(unsigned, unsigned, unsigned, unsigned);
int STAFF_ROLL_StepWindowSlide(char *p)
{
    struct Mtx22 matrix;
    int v;
    unsigned scale;
    switch (((struct Obj00682 *)p)->f2CE) {
    case 0:
        STAFF_ROLL_ReloadGraphics(p, 1);
        func_0207D63C(0x04000050, 8, 0x20, 0, 16);
        BG_SYS_SetMainPlaneVisible(8, 1);
        GXx_SetMasterBrightness_((void *)0x0400006c, 0);
        GXx_SetMasterBrightness_((void *)0x0400106c, 0);
        *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
        ++((struct Obj00682 *)p)->f2CE;
        break;
    case 1:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2D0 += 8;
        else ((struct Obj00682 *)p)->f2D0 += 2;
        v = ((struct Obj00682 *)p)->f2D0;
        if (v >= 16) {
            *(volatile u16 *)0x04000052 = 16;
            BUTTON_MAN_RotScaleMtx22(&matrix, 0, (const void *)0x1000, (const void *)0x1000, 0);
            BG_SYS_SetScrollRegs(3, (unsigned)&matrix, 0x80, 0x60);
            *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
            *(u16 *)&((struct Obj00682 *)p)->f2DA = 0xa6;
            ++((struct Obj00682 *)p)->f2CE;
        } else {
            *(volatile u16 *)0x04000052 = v | ((16 - v) << 8);
            scale = 8 - ((struct Obj00682 *)p)->f2D0 / 2;
            BUTTON_MAN_RotScaleMtx22(&matrix, 0, (const void *)(scale << 12), (const void *)(scale << 12), 0);
            BG_SYS_SetScrollRegs(3, (unsigned)&matrix, 0x80, 0x60);
        }
        break;
    case 2:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2DA -= 4;
        else --((struct Obj00682 *)p)->f2DA;
        if (((struct Obj00682 *)p)->f2DA <= 0) {
            ((struct Obj00682 *)p)->f2DA = 0;
            ++((struct Obj00682 *)p)->f2CE;
        }
        break;
    case 3:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2D0 += 8;
        else ((struct Obj00682 *)p)->f2D0 += 2;
        v = ((struct Obj00682 *)p)->f2D0;
        if (v >= 16) {
            *(volatile u16 *)0x04000050 = 0;
            BG_SYS_SetMainPlaneVisible(8, 0);
            BUTTON_MAN_RotScaleMtx22(&matrix, 0, (const void *)0x1000, (const void *)0x1000, 0);
            BG_SYS_SetScrollRegs(3, (unsigned)&matrix, 0x80, 0x60);
            STAFF_ROLL_ReloadGraphics(p, 0);
            *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
            ((struct Obj00682 *)p)->f2CE = 0;
            return 0;
        } else {
            *(volatile u16 *)0x04000052 = (16 - v) | (v << 8);
            scale = ((struct Obj00682 *)p)->f2D0 / 2 + 1;
            BUTTON_MAN_RotScaleMtx22(&matrix, 0, (const void *)(scale << 12), (const void *)(scale << 12), 0);
            BG_SYS_SetScrollRegs(3, (unsigned)&matrix, 0x80, 0x60);
        }
        break;
    }
    return 1;
}
