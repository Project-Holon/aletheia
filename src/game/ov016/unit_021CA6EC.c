/*
 * file:     unit_021CA6EC.c
 * unit:     yes
 * function: func_021CA6EC, func_021CA740
 * address:  0x021CA6EC
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
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   input                            0x021ca768 arm
 *   draw                             0x021ca76c arm
 *   DWCi_WINlIsInit                  0x021d157c arm
 *   endScene                         0x021ca770 arm
 */
typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_WINlIsInit(void);


static void procScene(void);


static void procInit1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_WINlInitEx(0x44, 5, 1, -1, 0);
    DWCi_ChangeScene(procScene);
}


static void input(void);

static void draw(void);

static void endScene(void);


static void procScene(void)
{
    input();
    draw();
    if (DWCi_WINlIsInit()) {
        return;
    }
    DWCi_ChangeScene(endScene);
}
