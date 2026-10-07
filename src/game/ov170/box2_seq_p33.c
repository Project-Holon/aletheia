/*
 * file:     box2_seq_p33.c
 * unit:     yes
 * function: func_021EAAC4, func_021EAAE4, func_021EAB04, func_021EAB50, func_021EABA0, func_021EABB8, func_021EABD0, func_021EAC28, func_021EAC98, func_021EACA8
 * address:  0x021EAAC4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045334 0x02045334 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02045374  0x02045374  arm  arm9
 *   func_02045730  0x02045730  arm  arm9
 *   func_02041B6C  0x02041B6C  arm  arm9
 *   func_020456F8  0x020456F8  arm  arm9
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045B38  0x02045B38  arm  arm9
 *   func_02043B5C 0x02043B5C arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../../matched/include/Obj18507.h"
#include "../../matched/include/Obj08242.h"
#include "../../matched/include/Obj23962.h"
#include "../../matched/include/Obj00414.h"
#include "../../matched/include/Obj14269.h"
#include "../../matched/include/Obj23963.h"
#include "../../matched/include/Obj23964.h"

#define WORK(p) (*(char **)((p)+0x2C))
struct Descriptor;
struct PrintSys;
struct Cfg;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct CharBuf;
struct Rec;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int);
extern void func_020456F8(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_02045C04(struct Rec *rec);
void func_021EAAC4(char *p);
void func_021EAAE4(unsigned char *p, unsigned i);
void func_021EAB04(unsigned char *w);
void func_021EAB50(unsigned char *w);
void func_021EABA0(void **p);
void func_021EABB8(void **p);
void func_021EABD0(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color);
void func_021EAC28(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color);
void *func_021EAC98(void);
void func_021EACA8(unsigned char *p);

/*
 * Walk 0x1c 8-byte records at p+0x2c+0x94, release each, then
 *   release the pool.  Unsigned counter for the image's blo.
 */
void func_021EAAC4(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1c; i++)
        func_020452E8((struct Descriptor *)(*(int *)(((struct Obj18507 *)p)->f2C + i * 8 + 0x94)));
    func_020450C8();
}

/*
 * Set bit i of the 0x174-byte bitmap hung off p.
 *   Unsigned index, or mwccarm emits asr instead of the image's lsr.
 */
void func_021EAAE4(unsigned char *p, unsigned i)
{
    unsigned char *q = p + 0x174;
    q[i >> 3] |= (unsigned char)(1 << (i & 7));
}

void func_021EAB04(unsigned char *w) {
 unsigned i; unsigned char mask; unsigned char index;
 for(i=0;i<28;i++) {
  if(*(void **)(w+0x94+i*8)!=0) {
   mask=1<<(i&7); index=i>>3;
   if(w[0x174+index]&mask) {
    func_02045334(*(void **)(w+0x94+i*8));
    w[0x174+index]^=mask;
   }
  }
 }
}

void func_021EAB50(unsigned char *w) {
 unsigned i; void *print;
 func_0201C4E4(((struct Obj08242 *)w)->f8C);
 for(i=0;i<28;i++) {
  print=((struct Obj08242 *)w)->f8C;
  if(w[0x98+i*8]) {
   if(func_0201C6C4(print,func_02045770(*(void **)(w+i*8+0x94)))==0) {
    func_02045334(*(void **)(w+i*8+0x94));
    w[0x98+i*8]=0;
   }
  }
 }
}


/*
 * Release both children of the object and then a global one.
 */
void func_021EABA0(void **p)
{
    func_02045374(*p);
    func_02041B6C(func_02045730(*p));
}


void func_021EABB8(void **p)
{
    func_020456F8(*p);
    func_02041B6C(func_02045730(*p));
}

void func_021EABD0(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color) {
 void *s; unsigned print;
 s=func_02045EC0(bank,idx);
 print=((struct Obj23962 *)w)->f8C;
 func_0201C724((void *)print,(u32)func_02045770(*(void **)(w+0x94+i*8)),(short)x,(short)y,(u32)s,font,color);
 *(w+i*8+0x98)=1;
 func_02045808(s);
}


/*
 * Expands message idx of bank into the work string buffer and prints it into
 * message window i; marks the window dirty.
 */
void func_021EAC28(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color)
{
    u32 print;
    void *s;
    s = func_02045EC0(bank, idx);
    func_0201F250(((struct Obj00414 *)w)->f84, (void *)(*(u32 *)&((struct Obj00414 *)w)->f88), s);
    print = ((struct Obj00414 *)w)->f8C;
    func_0201C724((void *)print, (u32)func_02045770(*(void **)(w + i * 8 + 0x94)), (short)x, (short)y, *(u32 *)&((struct Obj00414 *)w)->f88, font, color);
    *(unsigned char *)(w + i * 8 + 0x98) = 1;
    func_02045808(s);
}


/*
 * Call func_02045B38 with fixed arguments.
 */
void *func_021EAC98(void)
{
    return func_02045B38(0, 2, 0xa, 0x4c);
}

void func_021EACA8(unsigned char *p) {
 unsigned char *w; void *bank;
 w=(unsigned char *)WORK(p);
 func_02043B5C(func_02045770(((struct Obj14269 *)w)->f94),0);
 bank=func_021EAC98();
 func_021EABD0(w,0,bank,((struct Obj23964 *)(*(char * *)&((struct Obj23963 *)p)->f0))->f24+0x25,0,8,((struct Obj14269 *)w)->f78,0x440);
 func_02045C04(bank);
 func_021EABA0((void **)(WORK(p)+0x94));
}
