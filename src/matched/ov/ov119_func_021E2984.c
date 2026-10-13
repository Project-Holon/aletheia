/*
 * function: func_021E2984
 * address: 0x021E2984
 * packet: pkt_ov119_021E2984
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   APP_TASKMENU_WIN_CreateEx 0x0202800C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B6558 0x021B6558 thumb ov067
 */
#include "../include/Obj02172.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
struct Obj;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
typedef unsigned char  u8;
extern u32 *APP_TASKMENU_WIN_CreateEx(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
void *func_021E2984(char *p,int a) {
    void *t;
    t=STRBUF_Create(100,((struct Obj02172 *)p)->f5F4);
    ((struct Obj02172 *)p)->f650=t;
    MSGDATA_ReadString(((struct Obj02172 *)p)->f720,a,t);
    ((struct Obj02172 *)p)->f654=0x39e3;
    ((struct Obj02172 *)p)->f658=0;
    ((struct Obj02172 *)p)->f648=APP_TASKMENU_WIN_CreateEx((u32)(((struct Obj02172 *)p)->f6B0),(u32)(p+0x650),8,21,16,3,0,1,((struct Obj02172 *)p)->f5F4);
    STRBUF_Delete(((struct Obj02172 *)p)->f650);
    func_0204B3DC(((struct Obj02172 *)p)->fF04,0);
    func_021B6558((unsigned char *)(((struct Obj02172 *)p)->f9C0),8,0);
    return ((struct Obj02172 *)p)->f648;
}
