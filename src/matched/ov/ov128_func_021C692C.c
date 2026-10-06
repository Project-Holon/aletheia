/*
 * function: func_021C692C
 * address: 0x021C692C
 * packet: pkt_ov128_021C692C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 */
#include "../include/Obj05377.h"
typedef unsigned char u8;
extern void func_0201DD68(void);
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0203101C(unsigned,unsigned,unsigned,unsigned);
extern u32 func_0201C440(void *p);
void func_021C692C(u8 *p, int heap)
{
    func_0201DD68();
    ((struct Obj05377 *)p)->f0=func_0201EC64(heap);
    ((struct Obj05377 *)p)->f4=func_02045B38(0,2,211,heap);
    ((struct Obj05377 *)p)->f17C=func_0201D7EC(23,0,0,0,heap);
    ((struct Obj05377 *)p)->f28=func_0203101C(heap,heap,3,256);
    ((struct Obj05377 *)p)->f2C=0;
    ((struct Obj05377 *)p)->f34=(void *)func_0201C440((void *)heap);
}
