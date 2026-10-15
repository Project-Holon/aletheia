/*
 * function: VS_MULTI_LIST_CreateTextResources
 * address:  0x021F6970
 * packet:   pkt_ov097_021F6970
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 */
#include "../include/Obj00111.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct GfFont;
struct MsgBank;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);

void VS_MULTI_LIST_CreateTextResources(u8 *p)
{
    ((struct Obj00111 *)p)->f14 = func_02045B38(0, 2, 0x12, 0x71);
    ((struct Obj00111 *)p)->fC = GF_FONT_Create(0x17, 0, 0, 0, 0x71);
    ((struct Obj00111 *)p)->f10 = GF_FONT_Create(0x17, 3, 0, 0, 0x71);
    ((struct Obj00111 *)p)->f18 = WORDSET_CreateDefault(0x71);
    ((struct Obj00111 *)p)->f1C = PRINTSYS_QUE_CreateEx(0x800, 0x71);
}
