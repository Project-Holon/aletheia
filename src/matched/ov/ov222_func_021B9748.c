/*
 * function: func_021B9748
 * address: 0x021B9748
 * packet: pkt_ov222_021B9748
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum do-while preserves one-trip loop (124 vs112 B).
 * volatile: 021B976C BLDCNT store; 021B9770..021B9776 DISPCNT read and store
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_021B9D64 0x021B9D64 thumb ov222
 *   func_021B9B84 0x021B9B84 thumb ov222
 *   func_021B9960 0x021B9960 thumb ov222
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B9FB8 0x021B9FB8 thumb ov222
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021BA1F4 0x021BA1F4 data a4
 */
#include "../include/Obj02559.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { COUNT=1 } LayerCount;
typedef struct {u32 layer;u8 data[40];} Row;
extern const Row d_021BA1F4[];
extern void func_020403F4(u32 i);
extern void func_021B9D64(char*);
extern void func_021B9B84(char*);
extern void func_021B9960(char*);
struct Node;
struct PrintSys;
struct S020315D4;
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201D83C(void*);
extern void func_021B9FB8(char*);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
int func_021B9748(void*scene,int unused1,int unused2,char*p)
{
 LayerCount i;
 i=0;
 do {
  func_020403F4((u8)d_021BA1F4[i].layer);
  i++;
 } while((u32)i<COUNT);
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 func_021B9D64(p);
 func_021B9B84(p);
 func_021B9960(p);
 func_02030EAC(*(void* *)&((struct Obj02559 *)p)->f14);
 func_0201C6EC(*(void* *)&((struct Obj02559 *)p)->f10);
 func_0201C4C0(*(void* *)&((struct Obj02559 *)p)->f10);
 func_0201D83C(*(void* *)&((struct Obj02559 *)p)->fC);
 func_021B9FB8(*(char* *)&((struct Obj02559 *)p)->f8);
 func_020315D4(scene);
 func_020306F0(0x83);
 return 1;
}
