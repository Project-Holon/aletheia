/*
 * function: procInit1
 * address:  0x021C4FAC
 * packet:   pkt_ov016_021C4FAC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit1 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   func_021C4FD0                    0x021C4FD0  arm
 */
typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_021C4FD0(void);

static void procInit1(void)
{
    if (!DWCi_EFFlCheck(0))
        DWCi_ChangeScene(func_021C4FD0);
}
