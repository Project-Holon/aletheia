/*
 * function: func_021BAADC
 * address: 0x021BAADC
 * packet: pkt_ov099_021BAADC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two bytes of alignment padding follow at 0x021BAB02.
 * symbols:
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA978 0x021BA978 thumb ov099
 */
#include "../include/Obj13684.h"
extern int func_021BA8BC(void *);
extern void func_0201DD68(void);
extern void func_021BA978(char *, int, int, int);
void func_021BAADC(char *p, int a, int b)
{
    *(int *)&((struct Obj13684 *)p)->f19C = func_021BA8BC(((struct Obj13684 *)p)->f19C);
    func_0201DD68();
    func_021BA978(p, a, b, 0);
}
