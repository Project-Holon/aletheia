/*
 * function: func_021B6A14
 * address:  0x021B6A14
 * packet:   pkt_ov070_021B6A14
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020414EC  0x020414EC  arm
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021BADF0(int p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
struct Obj;
extern void func_020414EC(u32 i);
extern void func_021B6138(char *p);
extern void func_021BA6A4(char *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BB3F4(int p, int mode);
extern void func_021B8AF4(void *o);

void func_021B6A14(u8 *p)
{
    if (func_021BADF0((int)p) == 0)
        return;
    if ((func_020362DC() & 3) == 0 && func_02035C60() == 0)
        return;
    func_020414EC(3);
    *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
    func_021B6138((char *)p);
    ((struct Obj00002 *)p)->f83E = 1;
    func_021BA6A4((char *)p);
    func_0204B92C(((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4((int)p, 1);
    func_021B8AF4(p);
}
