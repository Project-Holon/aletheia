/*
 * file:     unit_021D4240_p04.c
 * unit:     yes
 * function: func_021D4FE4, func_021D5004, func_021D503C, func_021D50B4
 * address:  0x021D4FE4
 * region:   ov122
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02051C88 0x02051C88 arm
 *   func_021D4D98 0x021D4D98 thumb ov122
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045808 0x02045808 arm
 *   func_02158630 0x02158630 thumb ov010
 *   func_0204B898 0x0204B898 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0203D798 0x0203D798 arm
 *   func_0203CF3C 0x0203CF3C arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../../matched/include/Obj00265.h"
#include "../../matched/include/Obj13965.h"
#include "../../matched/include/Obj22932.h"

struct U16Vec;
struct Ctx;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_020221A4(void);
extern int func_02051C88(void *);
extern void func_021D4D98(char *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(void *,int,void *);
extern void func_02045808(void *);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158630(int a);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_0203D798(void);
extern void *func_0203CF3C(u32);
extern void func_02082D44(const void *,void *,u32);
void func_021D4FE4(char *p);
void func_021D5004(char *p);
void func_021D503C(char *p);
void func_021D50B4(char *p,u32 n);

void func_021D4FE4(char *p) {if(func_020221A4())func_02051C88(((struct Obj00265 *)p)->f40);func_021D503C(p);func_021D4D98(p);}

/*
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 */
void func_021D5004(char *p) {void *t;t=func_020457B0(100,*(u16 *)(p+12));*(void **)(p+0x328)=t;func_02045CAC(*(void **)(p+0x44),9,t);*(u16 *)(p+0x32c)=0x39e3;*(u32 *)(p+0x330)=1;func_02045808(*(void **)(p+0x328));}

/*
 * extent: zero padding at 0x021D50B2; next function at 0x021D50B4.
 */
void func_021D503C(char *p)
{
    switch (func_02158630(func_02012138(((struct Obj00265 *)p)->f354))) {
    case 0:
    case 1:
        if (func_0204B898(((struct Obj00265 *)p)->f390) == 20) {
            func_0204B92C(((struct Obj00265 *)p)->f390, 0);
            func_0204B878(((struct Obj00265 *)p)->f390, 12);
        }
        break;
    case 2:
    case 3:
        if (func_0204B898(((struct Obj00265 *)p)->f390) == 12) {
            func_0204B92C(((struct Obj00265 *)p)->f390, 1);
            func_0204B878(((struct Obj00265 *)p)->f390, 20);
        }
        break;
    }
}

void func_021D50B4(char *p,u32 n) {void *q;func_0203D798();q=func_0203CF3C(n);((struct Obj22932 *)(*(char * *)&((struct Obj13965 *)p)->f344))->f10=2;func_02082D44(q,*(char * *)&((struct Obj13965 *)p)->f344+20,6);}
