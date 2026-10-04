/*
 * function: func_021D5B58
 * address: 0x021D5B58
 * packet: pkt_ov131_021D5B58
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D5BAC 0x021D5BAC thumb ov131
 *   func_021D5C4C 0x021D5C4C thumb ov131
 */
#include "../include/Obj00039.h"
typedef unsigned int   u32;
struct Mon;
struct Sav;
extern int func_021D5BAC(unsigned char *p, int direction, unsigned short *out);
extern void func_02017528(struct Sav *p);
extern void func_020307B0(void *);
extern void *func_021D6064(unsigned char *p);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_021D5C4C(unsigned char *p);
int func_021D5B58(unsigned char *p,int a) {
 unsigned short n;
 int r=func_021D5BAC(p,a,&n);
 if(r==1) {
 ((struct Obj00039 *)p)->f18=n;
 if((*(unsigned char **)(p+8))[12]==2) {
 if(((struct Obj00039 *)p)->f258) {func_02017528(((struct Obj00039 *)p)->f258);func_020307B0(((struct Obj00039 *)p)->f258);}
 ((struct Obj00039 *)p)->f258=func_0201747C(func_021D6064(p),((struct Obj00039 *)p)->f0);
 }
 func_021D5C4C(p);
 }
 return r;
}
