/*
 * function: func_021B9D10
 * address: 0x021B9D10
 * packet: pkt_ov218_021B9D10
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA554 0x021BA554 thumb ov218
 *   FRAME_LIST_GetScrollBarTop 0x021B8AB8 thumb ov067
 *   func_021BA680 0x021BA680 thumb ov218
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   func_021BA6BC 0x021BA6BC thumb ov218
 */
#include "../include/Obj03959.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021BA554(const char *p, int delta);
extern int FRAME_LIST_GetScrollBarTop(u8 *);
extern void func_021BA680(char *p, int v);
extern int FRAME_LIST_GetSelectedIndex(char *);
extern int FRAME_LIST_GetCursor(char *);
extern void func_021BA6BC(char *p, int y);
void func_021B9D10(u8 *p,int delta)
{
    int selected;
    s16 y;
    func_021BA554((const char *)p,(int)(0u-(u32)delta));
    y=FRAME_LIST_GetScrollBarTop(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    func_021BA680((char *)p,y);
    selected=FRAME_LIST_GetSelectedIndex(*(char * *)&((struct Obj03959 *)p)->f2C);
    func_021BA6BC((char *)p,(int)(((u32)selected-(u32)FRAME_LIST_GetCursor(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}
