/*
 * function: func_021B6824
 * address: 0x021B6824
 * packet: pkt_ov174_021B6824
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes 021B687A..021B687C.
 * symbols:
 *   func_02028604 0x02028604 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_0201DD68 0x0201DD68 thumb
 */
#include "../include/Obj00681.h"
typedef unsigned char u8;
extern int func_02028604(int a0);
extern void func_0201C4C0(void *);
extern void func_0201CE48(void *);
extern void func_02045808(void *);
extern void func_0201ED04(void *);
extern void func_02045C04(void *);
extern void func_020452E8(void *);
extern void func_0201D83C(void *);
extern void func_02031140(void *);
extern void func_0201DD68(void);
void func_021B6824(u8 *p)
{
    func_02028604((int)(((struct Obj00681 *)p)->f7C));
    func_0201C4C0(((struct Obj00681 *)p)->f78);
    if(((struct Obj00681 *)p)->f64) func_0201CE48(((struct Obj00681 *)p)->f64);
    if(((struct Obj00681 *)p)->f70) func_02045808(((struct Obj00681 *)p)->f70);
    if(((struct Obj00681 *)p)->f74) func_0201ED04(((struct Obj00681 *)p)->f74);
    func_02045C04(((struct Obj00681 *)p)->f6C);
    func_02045C04(((struct Obj00681 *)p)->f68);
    if(((struct Obj00681 *)p)->f5C) func_020452E8(((struct Obj00681 *)p)->f5C);
    func_0201D83C(((struct Obj00681 *)p)->f60);
    func_02031140(((struct Obj00681 *)p)->f58);
    func_0201DD68();
}
