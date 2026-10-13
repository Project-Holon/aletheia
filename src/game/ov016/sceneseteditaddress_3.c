/*
 * file:     sceneseteditaddress_3.c
 * unit:     yes
 * function: func_021C7314, func_021C73A0
 * address:  0x021C7314
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
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BF390  0x021BF390  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021BF6F4  0x021BF6F4  arm  ov016
 *   func_021C7690  0x021C7690  arm  ov016
 *   func_021BF708  0x021BF708  arm  ov016
 *   func_021BF71C  0x021BF71C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   func_021BF6E0  0x021BF6E0  arm  ov016
 *   DWCi_SceneSetEditAddress_procScene  0x021C73C0  arm  ov016
 */
#include "../../matched/include/G_MemSsea.h"

typedef struct MemSsea MemSsea;

extern int func_021D5580();
extern void func_021BF390();
extern void func_021CFFAC(unsigned int v);
extern void func_021BF6F4(unsigned char v);
extern int func_021C7690(int val);
extern void func_021BF708(unsigned char v);
extern void func_021BF71C(unsigned char v);
extern void func_021C0E40(unsigned int v);
extern unsigned char func_021BF6E0(void);
extern void DWCi_SceneSetEditAddress_procScene();
void func_021C7314(void);
void func_021C73A0(void);
extern struct MemSsea *g_021DE5E4;


/*
 * sdk:      procInit1 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C7314(void)
{
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    func_021BF390();
    func_021CFFAC(0x14);
    if (g_021DE5E4->pos == 0) {
        func_021BF6F4(0);
        func_021BF71C(0);
    } else {
        if (func_021C7690(0x1A))
            func_021BF708(0);
        func_021BF71C(0);
    }
    func_021C0E40((unsigned int)func_021C73A0);
}


/*
 * sdk:      procInit2 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C73A0(void)
{
    if (func_021BF6E0() == 0x1F)
        return;
    func_021C0E40((unsigned int)DWCi_SceneSetEditAddress_procScene);
}
