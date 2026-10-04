/*
 * function: func_021B829C
 * address: 0x021B829C
 * packet: pkt_ov104_021B829C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Enum subblock offset and grouped offset arithmetic retain the far-field register.
 * symbols:
 *   func_021B727C 0x021B727C thumb ov101
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B884C 0x021B884C thumb ov104
 *   func_021B86A0 0x021B86A0 thumb ov104
 *   func_021B8C3C 0x021B8C3C thumb ov104
 *   func_021B8624 0x021B8624 thumb ov104
 *   func_021B8614 0x021B8614 thumb ov104
 *   func_021B7F1C 0x021B7F1C thumb ov104
 *   func_021B8384 0x021B8384 thumb ov104
 *   func_021B818C 0x021B818C thumb ov104
 *   func_021B817C 0x021B817C thumb ov104
 *   func_021B8528 0x021B8528 thumb ov104
 */
#include "../include/Obj05275.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern int func_021B727C(int);
extern int func_021B7250(int *);
extern int func_021B6480(int *);
extern int func_021B884C(int *);
extern int func_021B86A0(u8 *);
extern void func_021B8C3C(u8 *p, const void *a, int color);
extern void func_021B8624(u8 *);
extern int func_021B8614(u8 *);
extern void func_021B7F1C(u8 *,void *,int,int,s16);
extern void func_020061E4(u32 a);
extern void func_021B8384(u8 *,u16 *);
extern void func_021B818C(u8 *);
extern void func_021B817C(u8 *,void (*)(u8 *,u16 *));
extern void func_021B8528(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
typedef enum { BASE=0x814 } Offset;
void func_021B829C(u8 *p,u16 *state) {
 Offset base=BASE;
 int point[2];
 *(u32 *)(p+(base+0x98))=0;
 if(!func_021B727C(*(int *)(p+(base-0x68)))) {
  if(func_021B884C(point)) {
   func_021B8C3C(p+0x278,point,func_021B86A0(p+base));
   if(!*(u16 *)(p+(base+0x8c))) func_021B8624(p+base);
   ((struct Obj05275 *)p)->f8AC=1;
  }
 }
 if(func_021B8614(p+base)) {
  if(!((struct Obj05275 *)p)->f89C) {
   func_021B7F1C(p+0xcc,p+0xbc,1,0,0);
   func_020061E4(0x654);
   ((struct Obj05275 *)p)->f89C=1;
  }
  if(((struct Obj05275 *)p)->f89C) func_021B8384(p,(u16 *)(p+0x8a0));
 }
 if(!((struct Obj05275 *)p)->f89C) {
  if(func_021B7250(*(int * *)&((struct Obj05275 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); }
  if(func_021B6480(*(int **)(CTX(p)+4))) func_021B817C(p,func_021B8528);
 }
}
