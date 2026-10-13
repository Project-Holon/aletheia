/*
 * function: func_021F760C
 * address: 0x021F760C
 * packet: pkt_ov112_021F760C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 4B3C forwards full r0 to4AA8(int); its extern remains int despite superseded i5 narrow score.
 * lever: split records/record pointer steps, expand immutable position at4B88, record/id declaration swap (permuter183).
 * symbols:
 *   func_021F5204 0x021F5204 thumb ov112
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_021F77EC 0x021F77EC thumb ov112
 *   func_021F4B3C 0x021F4B3C thumb ov112
 *   func_021F4B88 0x021F4B88 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   func_020056EC 0x020056EC thumb
 */
#include "../include/Obj00723.h"
#include "../include/Obj02824.h"
#include "../include/Obj03762.h"
#include "../include/Obj10319.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u8 *func_021F5204(void *,u8 *,u32);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern void func_021F77EC(u32,u8 *,u32);
extern void *func_021F4B3C(int type);
extern void *func_021F4B88(void *,int,u32,int *);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
extern void func_021F4E6C(u8 *p, u8 *e, u32 value);
typedef signed int     s32;
struct Board;
struct Vec3;
extern s32 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);
extern u32 func_020056EC(u32);
void func_021F760C(u8 *p,u8 *input)
{
    u8 i;
    void *personal;
    int *position;
    u8 *records;
    u8 *q;
    u8 *row;
    u32 id;
    int scale;
    u8 *record;
    u32 flag;
    for(i=0;i<9;i++) {
        if(*(int *)(p+20+264*i)==0) break;
    }
    q=p+20+264*i;
    ((struct Obj00723 *)q)->f0=1;
    ((struct Obj00723 *)q)->f4=1;
    ((struct Obj00723 *)q)->f8=1;
    ((struct Obj00723 *)q)->fC=0;
    ((struct Obj00723 *)q)->f10=0;
    ((struct Obj00723 *)q)->f14=0;
    ((struct Obj00723 *)q)->f104=0;
    *(u8 * *)&((struct Obj00723 *)q)->f58=func_021F5204(((struct Obj03762 *)p)->fC,input,1);
    personal=func_0201ADE4((u32)((struct Obj10319 *)input)->f8,(u32)input[11],(u32)((struct Obj03762 *)p)->f0);
    if(func_0201AE1C(personal,16)==1) ((struct Obj00723 *)q)->f10=1;
    if(func_0201AE1C(personal,34)==1) ((struct Obj00723 *)q)->f14=1;
    func_0201AE14(personal);
    ((struct Obj00723 *)q)->f18=0;
    ((struct Obj00723 *)q)->f1C=0;
    ((struct Obj00723 *)q)->f20=0;
    ((struct Obj00723 *)q)->f30=0;
    ((struct Obj00723 *)q)->f34=0;
    ((struct Obj00723 *)q)->f38=0;
    ((struct Obj00723 *)q)->f24=4096;
    ((struct Obj00723 *)q)->f28=4096;
    ((struct Obj00723 *)q)->f2C=4096;
    func_021F77EC((u32)p,q,((struct Obj10319 *)input)->f8);
    ((struct Obj00723 *)q)->f48=0;
    position=(int *)(q+24);
    scale=1024;
    records=input;
    records=records+20;
    for(i=0;i<9;i++) {
        id=*(u16 *)(input+20+6*i);
        record=records;
        record=record+6*i;
        row=q+4*i;
        *(u8 * *)&((struct Obj02824 *)row)->fA8=record;
        if(id!=255) {
            ((struct Obj02824 *)row)->fCC=1;
            ((struct Obj02824 *)row)->f60=(int)func_021F4B3C(id);
            ((struct Obj02824 *)row)->f84=func_021F4B88(((struct Obj03762 *)p)->f10,id,*(u32 *)&((struct Obj02824 *)row)->f60,(int *)(q+24));
            func_021F4EB4(*(int *)&((struct Obj03762 *)p)->f10,*(int *)&((struct Obj02824 *)row)->f84,scale,scale);
            func_021F4E6C((u8 *)(*(int *)&((struct Obj03762 *)p)->f10),(u8 *)(*(int *)&((struct Obj02824 *)row)->f84),0);
        } else {
            ((struct Obj02824 *)row)->fCC=0;
            ((struct Obj02824 *)row)->f60=0;
            *(int *)&((struct Obj02824 *)row)->f84=0;
        }
    }
    *(int *)&((struct Obj00723 *)q)->f5C=BILLBOARD_AddElem(((struct Obj03762 *)p)->f8,((struct Obj03762 *)p)->f438,1024,768,(struct Vec3 *)(q+24),30,0,0);
    flag=1;
    BILLBOARD_SetElemVisible(((struct Obj03762 *)p)->f8,((struct Obj00723 *)q)->f5C,&flag);
    ((struct Obj00723 *)q)->f50=func_020056EC(150)>>1;
    ((struct Obj00723 *)q)->f4C=1;
}
