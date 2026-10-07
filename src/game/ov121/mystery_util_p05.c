/*
 * file:     mystery_util_p05.c
 * unit:     yes
 * function: func_021DA280, func_021DA2A8, func_021DA2C8, func_021DA2F0, func_021DA318, func_021DA338, func_021DA3C0
 * address:  0x021DA280
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D9A40 0x021D9A40 thumb ov121
 *   func_020307B0 0x020307B0 arm
 *   func_021D9A58 0x021D9A58 thumb ov121
 *   func_021D9B34 0x021D9B34 thumb ov121
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021D9B9C 0x021D9B9C thumb ov121
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_02043994 0x02043994 arm
 *   func_02043678 0x02043678 arm
 *   d_021DFBA0 0x021DFBA0 data a4
 *   func_020437AC 0x020437AC arm
 */
#include "../../matched/include/Obj22879.h"
#include "../../matched/include/Obj22880.h"
#include "../../matched/include/Obj22881.h"
#include "../../matched/include/Obj13951.h"
#include "../../matched/include/Obj22882.h"
#include "../../matched/include/Obj13952.h"
#include "../../matched/include/Obj13953.h"
#include "../../matched/include/Obj22883.h"
#include "../../matched/include/Obj22884.h"

struct CharBuf;
struct Descriptor;
struct Bmp;
struct Obj020437AC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021D9A40(u8 *);
extern u32 func_020307B0(void *p);
extern void func_021D9A58(u8 *);
extern int func_021D9B34(u8 *);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_021D9B9C(u8 *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u8 func_02043994(struct Bmp *b);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
void func_021DA280(u8 *p);
void func_021DA2A8(u8 *p);
int func_021DA2C8(u8 *p);
void func_021DA2F0(u8 *p,u32 i);
void func_021DA318(u8 *p);
void *func_021DA338(char *p,u16 heap);
void func_021DA3C0(u8 *p);
extern char d_021DFBA0[];

void func_021DA280(u8 *p) { u32 i; for(i=0;i<((struct Obj22879 *)p)->f4;i++) func_021D9A40(*(u8 **)(p+16+i*4)); func_020307B0(p); }

void func_021DA2A8(u8 *p) { u32 i; for(i=0;i<((struct Obj22880 *)p)->f4;i++) func_021D9A58(*(u8 **)(p+16+i*4)); }

int func_021DA2C8(u8 *p) { u32 i; int result=1; for(i=0;i<((struct Obj22881 *)p)->f4;i++) result &= func_021D9B34(*(u8 **)(p+16+i*4)); return result; }

void func_021DA2F0(u8 *p,u32 i) { u8 *d=*(u8 **)(p+16+i*4); func_02043B5C(func_02045770(((struct Obj13951 *)d)->fC),((struct Obj13951 *)d)->f16&31); func_02045334(*(void **)(*(u8 **)(p+16+i*4)+12)); }

void func_021DA318(u8 *p) { u32 i; for(i=0;i<((struct Obj22882 *)p)->f4;i++) func_021D9B9C(*(u8 **)(p+16+i*4)); }

/*
 * lever: heap is u16 in this function and the two callees receiving it.
 */
void *func_021DA338(char *p,u16 heap)
{
    u32 i;
    int size=((struct Obj13952 *)p)->f4*4+8;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x42e);
    func_02082BCC(out,0,size);
    *(char * *)&((struct Obj13953 *)out)->f4=p;
    ((struct Obj13953 *)out)->f0=heap;
    for(i=0;i<((struct Obj13952 *)p)->f4;i++) {
        void *win=func_02045770(*(void **)(*(char **)(p+16+i*4)+12));
        u32 x=func_020437DC(win);
        u32 y=func_020437E4(win);
        u32 type=func_02043994(win);
        *(void **)(out+i*4+8)=func_02043678(x/8,y/8,type,heap);
    }
    return out;
}

void func_021DA3C0(u8 *p) { u32 i; for(i=0;i<((struct Obj22884 *)(*(u8 * *)&((struct Obj22883 *)p)->f4))->f4;i++) func_020437AC(*(void **)(p+8+i*4)); func_020307B0(p); }
