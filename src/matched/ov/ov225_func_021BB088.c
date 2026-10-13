/*
 * function: func_021BB088
 * address: 0x021BB088
 * packet: pkt_ov225_021BB088
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: declare last before index for spill order; final flag update is
 * an if/else chain rather than a switch. 0202815C forwards pointer to 28164.
 * symbols:
 *   APP_TASKMENU_WIN_ClearScreen 0x0202843C thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BB044 0x021BB044 thumb ov225
 *   APP_TASKMENU_WIN_DeleteNoClear 0x0202815C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_WIN_CreateExNoScreen 0x0202804C thumb
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj00074.h"
#include "../include/Obj26217.h"
#include "../include/Obj26218.h"
#include "../include/Obj26219.h"
#include "../include/Obj26220.h"
#include "../include/Obj26221.h"
#include "../include/Obj26222.h"
#include "../include/Obj26223.h"
#include "../include/Obj26224.h"
#include "../include/Obj26225.h"
#include "../include/Obj26226.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct MsgBank; struct U16Vec;
struct Entry {void *resource;u16 tag,pad;u32 flags;};
extern void APP_TASKMENU_WIN_ClearScreen(u8 *);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u16 func_021BB044(u16 **);
extern void APP_TASKMENU_WIN_DeleteNoClear(void);
extern void *func_02045EC0(struct MsgBank *,u32);
extern u32 *APP_TASKMENU_WIN_CreateExNoScreen(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void APP_TASKMENU_WIN_Update(u8 *);
extern void STRBUF_Delete(struct U16Vec *);
void func_021BB088(char *p)
{
    struct Entry e;
    u8 first,last,i;
    u16 index,end;
    first=0;
    index=(u16)(((struct Obj26217 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC-1);
    if (((struct Obj26218 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC==0) {
        if (*(u8 * *)&((struct Obj00074 *)p)->fC) {
            APP_TASKMENU_WIN_ClearScreen(*(u8 * *)&((struct Obj00074 *)p)->fC);
            ((struct Obj00074 *)p)->f2C=0;
        }
        index=((struct Obj26219 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
        first=1;
        func_0204B3DC(((struct Obj00074 *)p)->f60,0);
    }
    end=(u16)(func_021BB044((u16 **)p)+1);
    if (end>=((struct Obj26220 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f4) end--;
    last=(u8)(first+end-index);
    for(i=last+1;i<=7;i++) {
        if (*(u8 **)(p+i*4+0xc)) {
            APP_TASKMENU_WIN_ClearScreen(*(u8 **)(p+i*4+0xc));
            *(u32 *)(p+i*4+0x2c)=0;
        }
        func_0204B3DC(*(void **)(p+i*4+0x60),0);
    }
    for(i=first;i<=last;i++) {
        if (*(u8 **)(p+i*4+0xc)) APP_TASKMENU_WIN_DeleteNoClear();
        e.resource=func_02045EC0(*(struct MsgBank * *)&((struct Obj26221 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f20,*(u16 *)(*(char * *)&((struct Obj26222 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+2));
        if(i==0 || i==7) e.tag=0x3da3; else e.tag=0x39e3;
        e.flags=0;
        if(((struct Obj00074 *)p)->f94)
            *(u32 **)(p+i*4+0xc)=APP_TASKMENU_WIN_CreateExNoScreen(*(u32 *)&((struct Obj00074 *)p)->f8,(u32)&e,2,(u8)(i*3),28,3,0,0,((struct Obj26223 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
        else
            *(u32 *)(p+i*4+0xc)=APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00074 *)p)->f8,(u32)&e,2,(u8)(i*3),28,((struct Obj26224 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
        APP_TASKMENU_WIN_Update(*(u8 **)(p+i*4+0xc));
        *(u32 *)(p+i*4+0x2c)=1;
        STRBUF_Delete(e.resource);
        if (*(u32 *)(*(char * *)&((struct Obj26225 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+4)==0)
            func_0204B3DC(*(void **)(p+i*4+0x60),0);
        else if (*(u32 *)(*(char * *)&((struct Obj26226 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+4)==1)
            func_0204B3DC(*(void **)(p+i*4+0x60),1);
        index++;
    }
    ((struct Obj00074 *)p)->f94=1;
}
