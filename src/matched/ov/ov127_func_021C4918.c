/*
 * function: func_021C4918, func_021C4948
 * address: 0x021C4918
 * packet: pkt_ov127_021C4918
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   func_021C4A98 0x021C4A98 thumb ov127
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj03278.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *func_021C4A98(void *);
extern void func_02082BCC(void *,int,int);
void func_021C4918(void *a,u16 *s) { u8 *p; s16 x,y;p=func_021C4A98(a);x=(s16)s[0];y=(s16)s[1];((struct Obj03278 *)p)->f4=x;((struct Obj03278 *)p)->f6=y;((struct Obj03278 *)p)->f8=x;((struct Obj03278 *)p)->fA=y;((struct Obj03278 *)p)->fC=s[2];p[21]=s[3];p[20]=s[4];((struct Obj03278 *)p)->fE=s[5];((struct Obj03278 *)p)->f0=1; }
void func_021C4948(void *p) { func_02082BCC(p,0,24); }
