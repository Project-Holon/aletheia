/*
 * function: func_02196768
 * address:  0x02196768
 * packet:   pkt_ov021_02196768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02196454  0x02196454  thumb  ov021
 *   func_02040DA8  0x02040DA8  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02040588  0x02040588  arm
 */
#include "../include/Obj03578.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0201DD68(void);
extern void func_02196454(u8 *p);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_0203FB44(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 a);
struct Rec;
struct U16Vec;
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern void func_02040588(u32 a, u32 b);

void func_02196768(u8 *p)
{
    u32 v;

    func_0201DD68();
    func_02196454(p);
    func_02040DA8(5, 1, 0);
    v = ((struct Obj03578 *)p)->f3C;
    func_0203FB44(5, (u16)v, (u16)(v >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04((struct Rec *)(((struct Obj03578 *)p)->f28));
    func_0201D83C((void *)(((struct Obj03578 *)p)->f2C));
    func_02045808((struct U16Vec *)(((struct Obj03578 *)p)->f38));
    func_02040588(5, 0);
}
