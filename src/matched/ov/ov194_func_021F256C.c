/*
 * function: func_021F256C
 * address: 0x021F256C
 * packet: pkt_ov194_021F256C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021F4D94 0x021F4D94 thumb ov194
 *   func_021F299C 0x021F299C thumb ov194
 *   func_021F2BC8 0x021F2BC8 thumb ov194
 *   func_021F2F8C 0x021F2F8C thumb ov194
 *   func_021F28FC 0x021F28FC thumb ov194
 *   func_021F2A88 0x021F2A88 thumb ov194
 *   func_021F2F68 0x021F2F68 thumb ov194
 *   d_021F555C 0x021F555C data a4
 */
#include "../include/Obj02530.h"
extern void func_02082BCC(void *,unsigned,unsigned);
typedef unsigned int   u32;
extern u32 func_021F4D94(const unsigned char *p, u32 i);
extern int func_021F299C(int *,int *);extern void func_021F2BC8(int *,int *,void *);
extern int func_021F2F8C(int *,int *);extern int func_021F28FC(int *,int *);
typedef unsigned char  u8;
extern void func_021F2A88(int *p, int *delta, u8 *saved);extern int func_021F2F68(int *,int *);
extern const unsigned char d_021F555C[];
void func_021F256C(char *p, unsigned mode, int index, void *table, u32 a4) {
 int i;
 func_02082BCC(p,0,36);((struct Obj02530 *)p)->f0=(void *)func_021F4D94(table,index);
 switch(mode) {
 case 3:
 ((struct Obj02530 *)p)->f20=11;((struct Obj02530 *)p)->f22=4;
 ((struct Obj02530 *)p)->f14=func_021F299C;((struct Obj02530 *)p)->f18=func_021F2BC8;((struct Obj02530 *)p)->f1C=func_021F2F8C;break;
 case 0:case 1:case 2:
 ((struct Obj02530 *)p)->f20=13;((struct Obj02530 *)p)->f22=6;
 ((struct Obj02530 *)p)->f14=func_021F28FC;((struct Obj02530 *)p)->f18=func_021F2A88;((struct Obj02530 *)p)->f1C=func_021F2F68;break;
 }
 for(i=0;i<13;i++)*(unsigned char *)(p+4+i)=d_021F555C[i];
}
