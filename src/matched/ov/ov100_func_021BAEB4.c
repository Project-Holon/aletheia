/*
 * function: func_021BAEB4
 * address: 0x021BAEB4
 * packet: pkt_ov100_021BAEB4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: caller uses r0 after BLX; extern return retains that live value.
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_021B95C0 0x021B95C0 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 */
#include "../include/Obj22086.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02035C60(void);
extern void func_021B95C0(u8 *p);
extern void func_021B95B8(u8 *,u32);
extern void func_021B96B8(u8 *a);
void func_021BAEB4(int p) {
    if(func_02035C60()!=0) {
        func_021B95C0((u8 *)p);
        *(int *)(((struct Obj22086 *)p)->f244+0x1c)=13;
        func_021B95B8((u8 *)p,(u32)func_021B96B8);
    }
}
