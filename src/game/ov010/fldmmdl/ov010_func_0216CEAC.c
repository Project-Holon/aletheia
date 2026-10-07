/*
 * function: func_0216CEAC
 * address: 0x0216CEAC
 * packet: pkt_ov010_0216CEAC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: zero alignment halfword at 0x0216CEE2, then labelled 0x0216CEE4.
 * interface: E42C forwards r0/r1 unchanged; caller reads r0, so extern returns int.
 * symbols:
 *   func_0216E418 0x0216E418 thumb ov010
 *   func_0216E42C 0x0216E42C thumb ov010
 *   func_0216CDC4 0x0216CDC4 thumb ov010
 */
#include "../../../matched/include/Obj19117.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0216E418(void *a);
extern unsigned int func_0216E42C(void *bitmap, int id);
extern u8 *func_0216CDC4(u32,u8 *,u32,u32);
void func_0216CEAC(u32 a,u8 *p,u32 b,u32 n,u32 c) {
    do {
        if(func_0216E418(p)==1 || func_0216E42C((void *)c,((struct Obj19117 *)p)->f8)==0)
            func_0216CDC4(a,p,b,c);
        p+=0x24;
    } while(--n);
}
