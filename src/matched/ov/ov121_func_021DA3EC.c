/*
 * function: func_021DA3EC
 * address: 0x021DA3EC
 * packet: pkt_ov121_021DA3EC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Copy 0x02045838 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D9BE8 0x021D9BE8 thumb ov121
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 */
#include "../include/Obj03262.h"
#include "../include/Obj06449.h"
#include "../include/Obj22885.h"
#include "../include/Obj22886.h"
#include "../include/Obj22887.h"
#include "../include/Obj22888.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef struct { int x,y; } Pair;
struct CharBuf;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct MsgBank;
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020307B0(void *p);
extern void func_021D9BE8(int,Pair *,void *,void *,int,Pair *);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021DA3EC(char *p,char *desc,void *dst)
{
    u32 i;
    Pair pos,out;
    void *text=STRBUF_Create(512,((struct Obj06449 *)p)->f0);
    for(i=0;i<((struct Obj22885 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f4;i++) {
        char *d=desc+i*24;
        if(((struct Obj03262 *)d)->f0) {
            BMP_Clear(*(void **)(p+i*4+8),(u8)(((struct Obj03262 *)d)->f14&31));
            pos.x=((struct Obj03262 *)d)->f10;
            pos.y=((struct Obj03262 *)d)->f12;
            func_021D9BE8(((struct Obj03262 *)d)->fC,&pos,*(void **)(p+i*4+8),text,((struct Obj22886 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,&out);
            if(((struct Obj03262 *)d)->f8) STRBUF_Copy(text,(struct U16Vec *)(((struct Obj03262 *)d)->f8));
            else MSGDATA_ReadString((struct MsgBank *)(((struct Obj22887 *)(*(char * *)&((struct Obj06449 *)p)->f4))->fC),((struct Obj03262 *)d)->f4,text);
            PRINTSYS_PrintQueColor(dst,(u32)(*(void **)(p+i*4+8)),(s16)out.x,(s16)out.y,(u32)text,((struct Obj22888 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,((struct Obj03262 *)d)->f14);
        }
    }
    func_020307B0(text);
}
