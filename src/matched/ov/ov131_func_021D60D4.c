/*
 * function: func_021D60D4
 * address: 0x021D60D4
 * packet: pkt_ov131_021D60D4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D60D4 0x021D60D4 thumb ov131
 */
#include "../include/Obj00112.h"
typedef unsigned int   u32;
struct Sav;
extern void *func_021D6064(unsigned char *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
void func_021D60D4(unsigned char *p,int a) {
 void *m;
 switch((*(unsigned char **)(p+8))[12]) {
 case 0:
 m=**(void ** *)&((struct Obj00112 *)p)->f8;
 if(a==1) func_02017D30(m); else func_02017D70(m,1);
 break;
 case 1:
 m=func_0201AB28(**(void ** *)&((struct Obj00112 *)p)->f8,((struct Obj00112 *)p)->f18);
 if(a==1) func_02017D30(m); else func_02017D70(m,1);
 break;
 case 2:
 m=func_021D6064(p);
 if(a==1) {func_02017D30(((struct Obj00112 *)p)->f258);func_02017DBC(m);}
 else {func_02017D70(((struct Obj00112 *)p)->f258,1);func_02017DE4(m,1);}
 break;
 }
}
