/*
 * file:     unit_021B7560_p11.c
 * unit:     yes
 * function: func_021B8AF4, func_021B8B1C, func_021B8B38
 * address:  0x021B8AF4
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B64F0 0x021B64F0 thumb ov101
 *   func_021B9220 0x021B9220 data a4
 *   func_021B6508 0x021B6508 thumb ov101
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B64B8 0x021B64B8 thumb ov101
 */
#include "../../matched/include/Obj22209.h"
#include "../../matched/include/Obj22210.h"
#include "../../matched/include/Obj04429.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {int words[54];} Block;

extern void func_02082BCC(void *,int,u32);
extern void func_021B64F0(void *,int,void *,int,void *);
extern void func_021B6508(void *,int);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
void func_021B8AF4(u8 *p,void *q);
void func_021B8B1C(u8 *p);
int func_021B8B38(u8 *p,const Block *q);
extern u8 func_021B9220[];

void func_021B8AF4(u8 *p,void *q) {func_02082BCC(p,0,0x294);((struct Obj22209 *)p)->f0=q;func_021B64F0(q,0xe00,func_021B9220,1,p);}

void func_021B8B1C(u8 *p) {func_021B6508(((struct Obj22210 *)p)->f0,0xe00);func_02082BCC(p,0,0x294);}

int func_021B8B38(u8 *p,const Block *q) {
 switch(((struct Obj04429 *)p)->f4) {
 case 0: *(Block *)(p+0x1b8)=*q;((struct Obj04429 *)p)->f4=1;break;
 case 1:
  if(func_021B64B8(((struct Obj04429 *)p)->f0,0xe00,0xd8,(u32)(p+0x1b8),(u8)(func_0203D1A4((struct Link *)((int)func_020399A8()))==0),0,0,1))((struct Obj04429 *)p)->f4=2;
  break;
 case 2:
  if(((struct Obj04429 *)p)->f290) {((struct Obj04429 *)p)->f290=0;((struct Obj04429 *)p)->f4=0;return 1;}
  break;
 }
 return 0;
}
