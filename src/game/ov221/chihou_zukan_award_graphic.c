/*
 * file:     chihou_zukan_award_graphic.c
 * unit:     yes
 * function: func_021B9E78, func_021B9F20, func_021B9F7C, func_021B9F90, func_021B9F9C, func_021B9FB0, func_021BA010, func_021BA048, func_021BA04C, func_021BA054, func_021BA094, func_021BA0B0, func_021BA0B8, func_021BA0C4
 * address:  0x021B9E78
 * region:   ov221
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021BA2F0 0x021BA2F0 data a1
 *   d_021BA220 0x021BA220 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA130 0x021BA130 thumb ov221
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BA1D4 0x021BA1D4 data a4
 *   d_021BA250 0x021BA250 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021B9DD4 0x021B9DD4 thumb ov221
 *   d_021BA1B0 0x021BA1B0 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 */
#include "../../matched/include/Obj26071.h"
#include "../../matched/include/Obj26072.h"
#include "../../matched/include/Obj14784.h"
#include "../../matched/include/Obj26073.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef struct {u32 layer; u8 cfg[32];u32 type,enable;} Row;

typedef signed short s16;

typedef struct {u32 x,y,z;} Vec3;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void*,int,u32);
extern void func_0204335C(u32);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void* func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
extern int func_021BA130(int*);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(unsigned char);
extern void func_020450C8(void),func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021B9DD4(void);
extern void func_02046440(u32,u32,u32,u32,u16,u32,void(*)(void));
extern u32* func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,Vec3*,Vec3*,Vec3*,u32);
void* func_021B9E78(u32 swap,u32 heap);
/* volatile accesses: display cleanup, original 021B9F46..021B9F60. */ void func_021B9F20(char*p);
void func_021B9F7C(char *p);
unsigned func_021B9F90(char *p);
void func_021B9F9C(void *unused, char *p);
void func_021B9FB0(void*p,u32 heap);
void func_021BA010(void *p);
void func_021BA048(void *p);
void func_021BA04C(void *p);
void func_021BA054(unsigned char *p, int a, int b);
void func_021BA094(char *p);
void func_021BA0B0(void *a0);
void func_021BA0B8(void *p);
unsigned func_021BA0C0(unsigned *p);
void func_021BA0C4(u32**p,u32 heap);
extern char d_021BA2F0[];
extern u32 d_021BA220[];
extern const Row d_021BA250[];
extern u32 d_021BA1D4[];
extern Vec3 d_021BA1B0[3];
extern const s16 d_020A1EB8[];

/*
 * volatile: 021B9EA0..021B9EB4 BLDCNT/DISPCNT stores and reads
 * prototype evidence: 434CC full 16B body and both 4349C/434B4 full bodies ignore all input; no caller setup.
 */
void* func_021B9E78(u32 swap,u32 heap)
{
 char*p;
 u32*g;
 p=func_02030734(heap,16,0,d_021BA2F0,0x1cc);
 func_02082BCC(p,0,16);
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 func_0204335C(0);
 g=d_021BA220;
 func_020433E0((const struct DispVram *)g);
 func_0204363C(swap);
 func_0204361C();
 func_020434CC();
 func_02043588();
 func_0201DD60();
 func_021B9FB0(p,heap);
 func_021BA054((unsigned char*)p+4,(int)g,heap);
 func_021BA0C4((u32**)(p+8),heap);
 *(void* *)&((struct Obj26071 *)p)->fC=func_020056A0((u32)func_021B9F9C,(u32)p,0);
 return p;
}

/* volatile accesses: display cleanup, original 021B9F46..021B9F60. */
void func_021B9F20(char*p)
{
 func_02030EAC(*(void* *)&((struct Obj26072 *)p)->fC);
 func_021BA130((int*)(p+8));
 func_021BA094(p+4);
 func_021BA010(p);
 func_0201DD68();
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 func_02082BCC(p,0,16);
 func_020307B0(p);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021B9F7C(char *p)
{
    func_021BA0B0(p + 4);
    func_021BA048(p);
}

unsigned func_021B9F90(char *p){return func_021BA0C0((unsigned *)(p+4));}


void func_021B9F9C(void *unused, char *p)
{
    func_021BA04C(p);
    func_021BA0B8(p + 4);
}

/*
 * lever: named row pointer fixes 8 register bytes; heap widened to preserve untruncated calls.
 */
void func_021B9FB0(void*p,u32 heap)
{
 u32 i;
 func_02082BCC(p,0,4);
 func_0203F8F4(heap);
 func_02045088(heap);
 func_0203FC28((struct DispConfig *)d_021BA1D4);
 for(i=0;i<2;i++){
  const Row *row=&d_021BA250[i];
  u32 layer=row->layer;
  func_0203FCA0((u8)layer,(const struct BgTemplate *)row->cfg,(u8)row->type);
  func_020414AC(layer);
  func_02040588(layer,row->enable);
 }
}

void func_021BA010(void *p){unsigned base=(unsigned)d_021BA250;unsigned i;for(i=0;i<2;i++)func_020403F4(*(unsigned *)(base+i*44));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}

void func_021BA048(void *p){}

void func_021BA04C(void *p){func_020419E4();}


void func_021BA054(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021BA1E4, a, b);
    ((struct Obj14784 *)p)->f0 = (int)func_0204B100(0x80, 0, b);
    func_0204B270((void *)((struct Obj14784 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_021BA094(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26073 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}

void func_021BA0B0(void *a0) { func_0204A600(); }

void func_021BA0B8(void *p){func_0204A648();}

unsigned func_021BA0C0(unsigned *p){return *p;}

void func_021BA0C4(u32**p,u32 heap)
{
 func_02046440(0,1,0,1,0,heap,func_021B9DD4);
 *p=func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&d_021BA1B0[1],&d_021BA1B0[0],&d_021BA1B0[2],heap);
}
