/*
 * function: func_021B7798
 * address: 0x021B7798
 * packet: pkt_ov106_021B7798
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9360 0x021B9360 thumb ov106
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B8304 0x021B8304 thumb ov106
 *   func_021B8FC4 0x021B8FC4 thumb ov106
 *   func_021B8D9C 0x021B8D9C thumb ov106
 *   func_021B78AC 0x021B78AC thumb ov106
 *   func_021B807C 0x021B807C thumb ov106
 *   func_021B8D5C 0x021B8D5C thumb ov106
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02025588 0x02025588 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   GAME_DATA_Delete 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj03744.h"
typedef unsigned char u8;
struct PrintSys;
struct Rec;
struct S020315D4;
extern void func_021B9360(u8 *p);
extern void func_021B71C0(void *);
extern void func_021B8304(u8 *p);
extern void func_021B8FC4(void *);
extern void func_021B8D9C(void *);
extern void func_021B78AC(void *);
extern void func_021B807C(u8 *p);
extern void func_021B8D5C(u8 *p);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_02025588(void *);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C4C0(struct PrintSys *p);
extern void GAME_DATA_Delete(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021B7798(void *a,int b,int *state,u8 *p)
{
 int i;
 for(i=0;i<4;i++)func_021B9360(*(void **)(p+0x62C+i*4));
 func_0204ADA4((u32)(((struct Obj03744 *)p)->f644));
 func_021B71C0(((struct Obj03744 *)p)->f614);
 func_021B8304(p+0x38);
 func_021B8FC4(p+0x600); func_021B8D9C(p+0x5D4);func_021B78AC(p+0x28);
 func_02025588(((struct Obj03744 *)p)->f624);func_021B807C(p);func_021B8D5C(((struct Obj03744 *)p)->f63C);
 func_02045C04(((struct Obj03744 *)p)->f620);func_0201D83C(((struct Obj03744 *)p)->f618);func_0201C4C0(((struct Obj03744 *)p)->f61C);
 if(*state==0)GAME_DATA_Delete(((struct Obj03744 *)p)->f628);
 func_020315D4(a);func_020306F0(67);return 1;
}
