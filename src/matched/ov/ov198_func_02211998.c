/*
 * function: B_PLIST_MAIN_CreateCursor
 * address: 0x02211998
 * packet: pkt_ov198_02211998
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum offset retains 0x218C across calls and derives 0x2184.
 * ABI: 02211A24 explicitly receives the forwarded entry r2 as its r1.
 * symbols:
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_EnableInput 0x02025D1C thumb
 *   CURSOR_MOVE_SetMode 0x02025D24 thumb
 *   B_PLIST_MAIN_LayoutCursorActors 0x02211A24 thumb ov198
 *   d_022122D4 0x022122D4 data a4
 *   d_022122A0 0x022122A0 data a4
 */
#include "../include/Obj10855.h"
#include "../include/Obj25289.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef enum { task_offset=0x218c } Offset;
struct Struct_02025CD0;
struct Struct_02025D1C;
struct Struct_02025D24;
extern struct Struct_02025CD0 *CURSOR_MOVE_Create(u32,u32,u32,u32,u8,u16);
extern void CURSOR_MOVE_EnableInput(struct Struct_02025D1C *);
extern void CURSOR_MOVE_SetMode(struct Struct_02025D24 *);
extern void B_PLIST_MAIN_LayoutCursorActors(u8 *,u32);
extern const u32 d_022122D4[],d_022122A0[];
void B_PLIST_MAIN_CreateCursor(u8 *p,u32 index,u32 b)
{
    Offset offset=task_offset;
    struct Struct_02025CD0 *result;
    result=CURSOR_MOVE_Create(d_022122D4[index],(u32)d_022122A0,(u32)p,*(u32 *)(p+offset),b,((struct Obj25289 *)(*(u8 * *)&((struct Obj10855 *)p)->f0))->f10);
    *(struct Struct_02025CD0 **)(p+(offset-8))=result;
    CURSOR_MOVE_EnableInput((struct Struct_02025D1C *)result);
    offset-=8;
    CURSOR_MOVE_SetMode(*(struct Struct_02025D24 **)(p+offset));
    B_PLIST_MAIN_LayoutCursorActors(p,b);
}
