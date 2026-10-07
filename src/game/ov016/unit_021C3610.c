/*
 * file:     unit_021C3610.c
 * unit:     yes
 * function: func_021C3610, func_021C3678
 * address:  0x021C3610
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procInit1                        0x021C36B4  arm
 */
typedef volatile unsigned short vu16;

typedef _Bool bool;

extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
void func_021C3610(void);


/*
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(sceneoptmovcompl))
 */
void func_021C3610(void)
{
    *(vu16 *)0x04001008 = (*(vu16 *)0x04001008 & ~3) | 3;
    *(vu16 *)0x0400100A = (*(vu16 *)0x0400100A & ~3) | 3;
    *(vu16 *)0x04000008 = (*(vu16 *)0x04000008 & ~3) | 3;
    *(vu16 *)0x0400000A = (*(vu16 *)0x0400000A & ~3) | 3;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & ~3) | 3;
}


static void procInit1(void);


static void procInit(void)
{
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}
