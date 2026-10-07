/*
 * file:     namein_graphic_p15.c
 * unit:     yes
 * function: func_021F3D70, func_021F3DE0, func_021F3E18, func_021F3E78
 * address:  0x021F3D70
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0201EE84 0x0201EE84 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 */
#include "../../matched/include/Obj02239.h"
#include "../../matched/include/Obj02532.h"
#include "../../matched/include/Obj05513.h"

struct Descriptor;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct WordSet;
struct U16Vec;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long long u64;

extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
/* Callee species is u16; this caller passes r2 without truncation. */
extern void *func_020173F0(u32,u16,u64,u16);
extern void func_02017E40(void *,u32,u32);
extern u32 func_020307B0(void *p);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
void func_021F3D70(char *p,int value);
void func_021F3DE0(char *p,int value,u32 id,u32 form,u16 heap);
void func_021F3E18(char *p,int value,void *mon);
int func_021F3E78(u8 *p);

void func_021F3D70(char *p,int value) {
    int window;
    while (func_0201C6C4((struct PrintSys *)(((struct Obj02239 *)p)->f10),(void *)((int)func_02045770((struct Descriptor *)((struct Obj02239 *)p)->f14))))
        func_0201C4E4((struct PrintSys *)(((struct Obj02239 *)p)->f10));
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj02239 *)p)->f14)),((struct Obj02239 *)p)->f20);
    func_02045CAC((struct MsgBank *)(((struct Obj02239 *)p)->f0),value,(void *)(((struct Obj02239 *)p)->f1C));
    window=((struct Obj02239 *)p)->f10;
    func_0201C6FC((struct PrintSys *)window,(int)func_02045770((struct Descriptor *)((struct Obj02239 *)p)->f8),0,0,(void *)(*(int *)&((struct Obj02239 *)p)->f1C),((struct Obj02239 *)p)->f4);
    ((struct Obj02239 *)p)->fC=1;
}

void func_021F3DE0(char *p,int value,u32 id,u32 form,u16 heap) {void *mon;mon=func_020173F0(id,1,0,heap);func_02017E40(mon,111,form);func_021F3E18(p,value,mon);func_020307B0(mon);}

void func_021F3E18(char *p,int value,void *mon) {
    int text,window;
    func_0201EE84(((struct Obj02532 *)p)->f18,0,mon);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj02532 *)p)->f14)),((struct Obj02532 *)p)->f20);
    text=(int)func_02045EC0((struct MsgBank *)(((struct Obj02532 *)p)->f0),value);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj02532 *)p)->f18),((struct Obj02532 *)p)->f1C,(void *)text);
    window=((struct Obj02532 *)p)->f10;
    func_0201C6FC((struct PrintSys *)window,(int)func_02045770((struct Descriptor *)((struct Obj02532 *)p)->f8),0,0,(void *)(*(int *)&((struct Obj02532 *)p)->f1C),((struct Obj02532 *)p)->f4);
    ((struct Obj02532 *)p)->fC=1;
    func_02045808((struct U16Vec *)text);
}

int func_021F3E78(u8 *p) {int window;window=((struct Obj05513 *)p)->f10;if(p[12]) {if(func_0201C6C4((struct PrintSys *)window,(void *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj05513 *)p)->f8)))==0) {func_02045334(((struct Obj05513 *)p)->f8);p[12]=0;}}if(!p[12]) return 1;return 0;}
