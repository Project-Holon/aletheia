/*
 * function: B_PLIST_MAIN_CreateTextResources
 * address: 0x02210710
 * packet: pkt_ov198_02210710
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   STRBUF_Create 0x020457B0 arm
 */
#include "../include/Obj02916.h"
#include "../include/Obj25254.h"
#include "../include/Obj25255.h"
#include "../include/Obj25256.h"
#include "../include/Obj25257.h"
#include "../include/Obj25258.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void *PRINTSYS_QUE_CreateEx(u16,u32);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
void B_PLIST_MAIN_CreateTextResources(char *p)
{
    ((struct Obj02916 *)p)->f1EA0=func_02045B38(0,2,0x12,((struct Obj25254 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1E9C=GF_FONT_Create(0x17,3,0,0,((struct Obj25255 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EA4=WORDSET_CreateDefault(((struct Obj25256 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EAC=PRINTSYS_QUE_CreateEx(0x800,((struct Obj25257 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EA8=STRBUF_Create(0x200,((struct Obj25258 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
}
