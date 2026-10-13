/*
 * function: P_STA_SUB_SetPetOffset
 * address: 0x021D79A8
 * packet: pkt_ov131_021D79A8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _ll_mul 0x0209C054 arm
 *   d_021DC1EC 0x021DC1EC data a4
 *   d_020A5078 0x020A5078 data a2
 *   P_STA_SUB_ApplyMcssOffset 0x021D7A1C thumb ov131
 */
#include "../include/Obj00994.h"
typedef struct {int x,y,z;} Vec;
extern const Vec d_021DC1EC;
extern const short d_020A5078[];
extern void P_STA_SUB_ApplyMcssOffset(void *,void *,Vec *);
static inline int mul(int a,int b) {return (int)(((long long)a*b+0x800LL)>>12);}
void P_STA_SUB_SetPetOffset(void *p,unsigned char *q,int radius) {
 Vec v=d_021DC1EC;
 ((struct Obj00994 *)q)->f4C=mul(d_020A5078[10],radius);
 ((struct Obj00994 *)q)->f50=mul(d_020A5078[11],radius);
 ((struct Obj00994 *)q)->f54=0;
 P_STA_SUB_ApplyMcssOffset(p,q,&v);
}
