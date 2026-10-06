/*
 * function: func_021C991C
 * address: 0x021C991C
 * packet: pkt_ov128_021C991C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: 0202DA18/48 and 0204B294 leave the consumed handle in r0 despite
 * their void declarations. Heap externs are widened when no truncation
 * occurs. 0202DA04's legacy a1-a3 are neither read nor forwarded.
 * bounds: two unsigned loops cover ten eight-byte records at p+0x128;
 * signed q[11] accesses retain modular address arithmetic.
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009864 0x02009864 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045748 0x02045748 arm
 *   func_021B6B2C 0x021B6B2C thumb ov067
 *   func_021C9FC8 0x021C9FC8 thumb ov128
 *   func_021C6C94 0x021C6C94 thumb ov128
 *   func_021C6C20 0x021C6C20 thumb ov128
 *   func_02045334 0x02045334 arm
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_02025C88 0x02025C88 thumb
 *   func_0202DA04 0x0202DA04 thumb
 *   func_0202DA48 0x0202DA48 thumb
 *   func_0202DA18 0x0202DA18 thumb
 *   func_0202DA6C 0x0202DA6C thumb
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   d_021CA640 0x021CA640 data a2
 */
#include "../include/Obj00329.h"
#include "../include/Obj00773.h"
#include "../include/Obj00992.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef struct {u16 v[4];} Bounds;
extern const Bounds d_021CA640;
struct BigObj;
struct CharBuf;
struct Descriptor;
extern u32 func_0201283C(const struct BigObj *p);
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 func_02045748(struct Descriptor *p);
extern void func_021B6B2C(u32 a0, void *a1, u32 a2, u16 a3, u16 a4, u16 a5, u32 a6, u32 a7, u16 heap);
extern void func_021C9FC8(u8 *,void *,u8 *,u32,int,int,int);
extern void func_021C6C94(char **,int);
extern int func_021C6C20(u8 *,u8 *,int);
extern void func_02045334(struct Descriptor *),func_021CA4B4(char *);
extern u32 func_02025C88(u32);
extern int func_0202DA04(int);
extern u32 func_0202DA48(u32,u32,u32,u32);
typedef signed int     s32;
extern s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int func_0202DA6C(int a0, int a1, int a2, unsigned short a3);
extern void func_02049238(void *);
struct Obj;
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
void func_021C991C(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    u32 i,base,id,archive,offset;
    int pos;
    Bounds bounds;
    base=func_0201283C(((struct Obj00992 *)q)->f4);
    func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),9);
    for(i=0;i<10;i++) func_02043B5C(func_02045770(*(void **)(p+i*8+0x128)),0);
    offset=0x128;
    pos=func_02045748(*(void **)(p+offset));
    func_021B6B2C((u32)(p+offset),(void *)(*(u32 *)&((struct Obj00329 *)ctx)->f34),*(u32 *)&((struct Obj00329 *)ctx)->f17C,
        (int)((u32)pos*8)/2,0,0x3C40,
        *(u8 *)((u32)q+((struct Obj00992 *)q)->fB+0x38)+1,((struct Obj00992 *)q)->f14,heap);
    func_021C9FC8(p+(offset+8),q,ctx,19,0,0,0x3C40);
    func_021C9FC8(p+(offset+16),q,ctx,20,0,0,0x3C40);
    func_021C9FC8(p+0x140,q,ctx,21,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),2));
    func_021C9FC8(p+(offset+32),q,ctx,22,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),3));
    func_021C9FC8(p+0x150,q,ctx,22,0,0,0x3C40);
    func_021C9FC8(p+(offset+48),q,ctx,23,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),4));
    func_021C9FC8(p+0x160,q,ctx,24,0,0,0x3C40);
    func_021C9FC8(p+(offset+=64),q,ctx,27,0,0,0x3C40);
    if(func_021C6C20(ctx,q,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24))!=0)
        func_021C9FC8(p+0x170,q,ctx,28,0,0,0x3C40);
    else func_02045334(((struct Obj00773 *)p)->f170);
    for(i=0;i<10;i++) func_021CA4B4(*(char **)(p+i*8+0x128));
    bounds=d_021CA640;
    id=func_02025C88(func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),8));
    archive=func_0202DA04(heap);
    ((struct Obj00773 *)p)->f17C=func_0202DA48(archive,id,0,heap);
    ((struct Obj00773 *)p)->f180=func_0202DA18(archive,id,0,192,heap);
    ((struct Obj00773 *)p)->f184=func_0202DA6C(id,2,0,heap);
    func_02049238((void *)archive);
    ((struct Obj00773 *)p)->f178=(u32)func_0204B294((void *)((struct Obj00329 *)ctx)->f138,((struct Obj00773 *)p)->f17C,
        ((struct Obj00773 *)p)->f180,((struct Obj00773 *)p)->f184,&bounds,0,heap);
}
