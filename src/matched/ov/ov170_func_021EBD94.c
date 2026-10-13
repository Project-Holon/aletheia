/*
 * function: func_021EBD94
 * address: 0x021EBD94
 * packet: pkt_ov170_021EBD94
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021EBDD6.
 * symbols:
 *   func_021EBDF4 0x021EBDF4 thumb ov170
 *   func_021EBE24 0x021EBE24 thumb ov170
 *   func_021EBEAC 0x021EBEAC thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EE120 0x021EE120 thumb ov170
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
#include "../include/Obj00000.h"
extern void func_021EBDF4(void *);
extern void func_021EBE24(char *p);
extern void func_021EBEAC(unsigned char *);
extern void func_021EE038(char *, int, int, int);
extern void func_021EE120(char *p);
extern void func_020434DC(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
void func_021EBD94(unsigned char *p)
{
    func_021EBDF4(((struct Obj00000 *)p)->f2C);
    func_021EBE24(((struct Obj00000 *)p)->f2C);
    func_021EBEAC(p);
    func_021EE038((char *)p, p[0x1f], p[0x20], p[0x21]);
    func_021EE120(((struct Obj00000 *)p)->f2C);
    func_020434DC(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}
