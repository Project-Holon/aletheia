/*
 * function: func_021BC824
 * address: 0x021BC824
 * packet: pkt_ov209_021BC824
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2 bytes of alignment padding
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 */
#include "../include/Obj00123.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
void func_021BC824(char *p)
{
    ((struct Obj00123 *)p)->f3C = func_02045B38(0, 2, 0x114, 0x6B);
    ((struct Obj00123 *)p)->f38 = func_0201D7EC(0x17, 0, 0, 0, 0x6B);
    ((struct Obj00123 *)p)->f40 = func_0201EC64(0x6B);
    ((struct Obj00123 *)p)->f48 = func_0201C440((void *)0x6B);
    ((struct Obj00123 *)p)->f44 = func_020457B0(0x80, 0x6B);
}
