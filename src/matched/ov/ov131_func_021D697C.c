/*
 * function: func_021D697C
 * address: 0x021D697C
 * packet: pkt_ov131_021D697C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_021D6D18 0x021D6D18 thumb ov131
 *   func_021D6064 0x021D6064 thumb ov131
 */
#include "../include/Obj00436.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Personal;
extern void *func_021D6064(unsigned char *p);
extern int func_0201ACC4(void *p, u32 pos);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021D6D18(u8 *p, u8 *q, void *mon);
void func_021D697C(unsigned char *p,int *q) {
 void *m=func_021D6064(p);
 void *t;
 int a,b;
 if((*(unsigned char **)(p+8))[12]==1) q[3]=func_0201ACC4(**(void ** *)&((struct Obj00436 *)p)->f8,((struct Obj00436 *)p)->f18); else q[3]=1;
 if(*(int *)&((struct Obj00436 *)p)->f38==0) {
 a=func_02017E88(m,5,0);
 b=func_02017E88(m,111,0);
 t=func_0201ADE4((unsigned short)a,(unsigned short)b,((struct Obj00436 *)p)->f0);
 if(func_0201AE1C(t,16)==1) q[4]=1; else q[4]=0;
 q[5]=func_0201AE1C(t,38);
 func_0201AE14(t);
 } else {q[4]=0;q[5]=0;}
 q[6]=(int)func_020450F0(1,19,0,13,4,14,1);
 q[7]=(int)func_020450F0(1,19,17,13,4,14,1);
 func_021D6D18(p,(u8 *)q,m);
}
