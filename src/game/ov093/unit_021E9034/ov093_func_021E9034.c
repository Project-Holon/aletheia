/*
 * function: func_021E9034
 * address:  0x021E9034
 * packet:   pkt_ov093_021E9034
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EECD8  0x021EECD8  thumb  ov093
 *   func_021E907C  0x021E907C  thumb  ov093
 *   func_021EB234  0x021EB234  thumb  ov093
 *   func_02031140  0x02031140  arm
 *   func_02045808  0x02045808  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../../matched/include/Obj05223.h"
extern void func_021EECD8(void);
extern void func_021E907C(void *p);
extern void func_021EB234(void *p);
struct S02031140;
struct U16Vec;
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_0201D83C(void *ptr);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021E9034(char *p)
{
    func_021EECD8();
    func_021E907C(((struct Obj05223 *)p)->f180);
    func_021EB234(((struct Obj05223 *)p)->f17C);
    func_02031140(((struct Obj05223 *)p)->f178);
    func_02045808(((struct Obj05223 *)p)->fAC);
    func_0201D83C(((struct Obj05223 *)p)->fB0);
    func_0201D83C(((struct Obj05223 *)p)->fB4);
    func_020307B0(p);
}
