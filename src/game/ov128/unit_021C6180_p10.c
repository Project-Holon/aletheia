/*
 * file:     unit_021C6180_p10.c
 * unit:     yes
 * function: func_021C8850, func_021C8880, func_021C88AC, func_021C88BC, func_021C88C0, func_021C8904
 * address:  0x021C8850
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B8F4 0x0204B8F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021C8A50 0x021C8A50 thumb ov128
 *   func_021C8A80 0x021C8A80 thumb ov128
 *   func_021C8B90 0x021C8B90 thumb ov128
 */
#include "../../matched/include/Obj00179.h"
#include "../../matched/include/Obj23089.h"
#include "../../matched/include/Obj05381.h"
#include "../../matched/include/Obj23090.h"
#include "../../matched/include/Obj23091.h"

struct Actor;
struct Obj;
struct BigObj;
struct CharBuf;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed int s32;

extern u32 func_0204B98C(struct Actor *);
extern u32 func_0204B8F4(struct Obj *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
extern u32 func_0201283C(const struct BigObj *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_021C8A50(char *p, int unused);
extern void func_021C8A80(u8 *p, void *a, u8 *b, int unused, int i, void *base, int idx, u16 heap);
extern void func_021C8B90(char *p, char *q, int unused, int i, u16 h);
int func_021C8850(u8 *p, u8 *a1);
void func_021C8880(u8 *p);
void func_021C88AC(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap);
void func_021C88BC(void *a0, void *a1);
void func_021C88C0(s16 *p, void *unused, u8 *q);
void func_021C8904(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap);

int func_021C8850(u8 *p, u8 *a1) {u32 n;if(func_0204B98C(*(struct Actor * *)&((struct Obj00179 *)p)->f1A0)==0)return 1;n=func_0204B8F4(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0);if(n-((struct Obj00179 *)p)->f1A8>=2) ((struct Obj00179 *)p)->f1A8=n;return 0;}

/*
 * volatile: display control MMIO 0x04000000 read/write at 021C888A and 021C8892.
 */
void func_021C8880(u8 *p) {*(volatile u32 *)0x04000000 &= ~0xe000u;func_0204B3DC(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0,0);func_0204B92C(*(struct Obj * *)&((struct Obj00179 *)p)->f1A0,0);}


void func_021C88AC(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

/*
 * extent: bx lr followed by two zero alignment bytes.
 */
void func_021C88BC(void *a0, void *a1) {}

void func_021C88C0(s16 *p, void *unused, u8 *q)
{
    int y = p[1];
    int x;
    u16 *t;
    if (y < 0) y = -y;
    x = p[0];
    if (x < 0) x = -x;
    t = *(u16 * *)&((struct Obj23089 *)q)->f8;
    func_02041090((int)2, (u32)((u8 *)t + 12), (u8)x, (u8)y, (t[0] >> 3) & 255, (t[1] >> 3) & 255);
    func_02041B6C(2);
}

void func_021C8904(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {
 int i;int offset;void *base;int found;char *row;void *v;
 base=(void *)func_0201283C(((struct Obj23090 *)q)->f4);
 v=func_02045770(**(void ** *)&((struct Obj05381 *)p)->f8);
 found=0;
 func_02043B5C(v,0);
 func_021C8A50(p,(int)r);
 offset=page*8;i=0;row=table+offset;
 for(;i<8;i++) {
  if(((struct Obj23091 *)table)->f0 > offset+i) {
   func_021C8A80((u8 *)p,s,r,t,i,base,(u8)row[i+8],heap);found=1;
  } else func_021C8B90(p,r,t,i,heap);
 }
 if(!found)func_02045334(**(void ** *)&((struct Obj05381 *)p)->f8);
}
