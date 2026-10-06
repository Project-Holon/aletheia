/*
 * function: func_021DC428
 * address: 0x021DC428
 * packet: pkt_ov119_021DC428
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_02014BA8 0x02014BA8 thumb
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 */
#include "../include/Obj00001.h"
extern void func_021E36D8(void *, int);
typedef unsigned char  u8;
extern void func_02014BA8(u8 *a0);
typedef unsigned int   u32;
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
void func_021DC428(char *p)
{
    func_021E36D8(p, 0);
    func_021E36D8(p, 1);
    func_02014BA8(((struct Obj00001 *)p)->f840);
    ((struct Obj00001 *)p)->f840 = 0;
    func_02048AC4(((struct Obj00001 *)p)->f810);
    func_02046788();
}
