/*
 * function: func_021BF08C
 * address: 0x021BF08C
 * packet: pkt_ov217_021BF08C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 114 code bytes; show at 021BF0FE proves two zero alignment bytes before next aligned function.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021BF810 0x021BF810 thumb ov217
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct ArcFile;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int u32;
extern u32 func_021BF810(void *p);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *,unsigned,unsigned);
extern int func_02062B30(void *,void **);
extern void func_02041090(unsigned,unsigned,unsigned,unsigned,u8,u8);
extern void func_020409B4(unsigned);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021BF08C(char *p)
{
    struct ArcFile *arc;
    void *file,*out;
    unsigned id;
    arc=func_020490F4(192,((struct Obj00021 *)p)->f4);
    if (((struct Obj00021 *)p)->f3D0!=0) id=8;
    else if (func_021BF810(p)==0) id=6;
    else {
        id=6;
        if (((struct Obj00021 *)p)->f3C8!=0) id=7;
    }
    file=ARC_TOOL_LoadHandleMember(arc,id,((struct Obj00021 *)p)->f4);
    func_02062B30(file,&out);
    func_02041090(2,(unsigned)out+12,0,0,32,32);
    func_020409B4(2);
    func_020307B0(file);
    ARC_TOOL_DeleteHandle(arc);
}
