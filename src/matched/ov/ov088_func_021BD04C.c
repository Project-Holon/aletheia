/*
 * function: func_021BD04C
 * address:  0x021BD04C
 * packet:   pkt_ov088_021BD04C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045808  0x02045808  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_020461D4  0x020461D4  arm
 */
#include "../include/Obj04351.h"

extern int func_02028604(int a0);
struct Rec;
struct S02031140;
struct U16Vec;
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_020461D4(unsigned char);

void func_021BD04C(unsigned char *p)
{
    func_02028604((int)(((struct Obj04351 *)p)->f24));
    func_02031140(((struct Obj04351 *)p)->f18);
    func_02045808(((struct Obj04351 *)p)->f10);
    func_0201D83C(((struct Obj04351 *)p)->f4);
    func_02045C04(((struct Obj04351 *)p)->f8);
    func_020461D4(p[0x0C]);
}
