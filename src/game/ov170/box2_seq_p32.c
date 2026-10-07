/*
 * file:     box2_seq_p32.c
 * unit:     yes
 * function: func_021EA928, func_021EA984, func_021EA9F4, func_021EAA3C, func_021EAA80
 * address:  0x021EA928
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
 *   func_02007A80 0x02007A80 thumb
 *   func_021E8F50 0x021E8F50 thumb ov170
 *   func_021E949C 0x021E949C thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF480 0x021EF480 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021DD238 0x021DD238 thumb
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   d_021EFC20 0x021EFC20 data a1
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23959.h"
#include "../../matched/include/Obj23960.h"
#include "../../matched/include/Obj23961.h"

#define WORK(p) (*(char **)((p)+0x2C))
#define MGR(p) (*(struct WinMgr **)(*(char **)((char *)(p) + 0x2C) + 0x74))
struct WinMgr;
typedef struct {
    unsigned char pad[0x1C];
    unsigned char lo : 4;
    unsigned char hi : 4;
} Obj;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_02007A80(void *,unsigned);
extern int func_021E8F50(char *p, int v);
extern int func_021E949C(char *p, int a, int b);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED888(char *,int);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_020061E4(unsigned se);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021DD238(char *p);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
int func_021EA928(unsigned char *p,int a);
void func_021EA984(unsigned char *p);
void func_021EA9F4(Obj *p, int v);
void func_021EAA3C(Obj *p, int v);
void func_021EAA80(unsigned char *p);
extern const unsigned char d_021EFC20[];

int func_021EA928(unsigned char *p,int a) {
 if((unsigned char)WORK(p)[0xA17C]<=4 || ((unsigned char)WORK(p)[0xA17C]==5 && func_02007A80(((struct Obj23959 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f4,2)==0))
  WORK(p)[0xA17B]=((unsigned char)WORK(p)[0xA17C]-1)*4+a-1;
 else WORK(p)[0xA17B]=((unsigned char)WORK(p)[0xA17C]-1)*4+a;
 return func_021E949C((char *)p,a,func_021E8F50((char *)p,0x66));
}

void func_021EA984(unsigned char *p) {
 switch(((struct Obj23961 *)(*(char * *)&((struct Obj23960 *)p)->f0))->f24) {
 case 0: func_021ECB20((char *)p,2,1); return;
 case 1: case 3: func_021ED888(WORK(p),0); func_021ECB20((char *)p,1,1); return;
 case 2: case 4: case 5:
  func_021ED888(WORK(p),0);
  if(func_021EF480(*(struct WinMgr **)(WORK(p)+0x74))==1) {
   func_021ECB20((char *)p,2,1); return;
  } else { func_021ECB20((char *)p,1,1); return; }
 }
}


void func_021EA9F4(Obj *p, int v)
{
    func_020061E4(0x54C);
    if (func_021EF5E8(MGR(p)) == 1)
        p->lo = 2;
    else
        p->lo = 1;
    p->hi = 0;
    func_021DD238((char *)p);
    func_021E8F50((char *)p, v);
}


void func_021EAA3C(Obj *p, int v)
{
    func_020061E4(0x54C);
    if (func_021EF5E8(MGR(p)) == 1)
        p->lo = 2;
    else
        p->lo = 1;
    p->hi = 0;
    func_021E8F50((char *)p, v);
}

void func_021EAA80(unsigned char *p) {
 const unsigned char *x; unsigned i;
 func_02045088(0x4C);
 x=d_021EFC20;
 for(i=0;i<28;i++,x+=6)
  *(void **)(WORK(p)+0x94+i*8)=(void *)func_020450F0(x[0],x[1],x[2],x[3],x[4],x[5],1);
}
