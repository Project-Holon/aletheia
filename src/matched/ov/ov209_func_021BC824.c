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
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
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
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
void func_021BC824(char *p)
{
    ((struct Obj00123 *)p)->f3C = func_02045B38(0, 2, 0x114, 0x6B);
    ((struct Obj00123 *)p)->f38 = GF_FONT_Create(0x17, 0, 0, 0, 0x6B);
    ((struct Obj00123 *)p)->f40 = func_0201EC64(0x6B);
    ((struct Obj00123 *)p)->f48 = PRINTSYS_QUE_Create((void *)0x6B);
    ((struct Obj00123 *)p)->f44 = STRBUF_Create(0x80, 0x6B);
}
