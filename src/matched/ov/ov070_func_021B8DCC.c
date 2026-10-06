/*
 * function: func_021B8DCC
 * address: 0x021B8DCC
 * packet: pkt_ov070_021B8DCC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7DD0 0x021B7DD0 thumb ov070
 *   func_0204B92C 0x0204B92C arm
 *   func_021BB3F4 0x021BB3F4 thumb ov070
 *   func_020355C4 0x020355C4 arm
 *   func_021B80C4 0x021B80C4 thumb ov070
 *   func_021B8AF4 0x021B8AF4 thumb ov070
 */
#include "../include/Obj00002.h"
extern void func_021B7DD0(void *p);
struct Obj;
extern void func_0204B92C(struct Obj *object, unsigned int flag);
extern void func_021BB3F4(int p, int mode);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void func_021B80C4(struct Obj *o, int flag);
extern void func_021B8AF4(void *p);
void func_021B8DCC(char *p)
{
    int flag;
    func_021B7DD0(p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4((int)p, 1);
    flag = 1;
    if (func_020355C4())
        flag = 0;
    func_021B80C4((struct Obj *)p, flag);
    func_021B8AF4(p);
}
