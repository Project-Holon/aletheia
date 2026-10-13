/*
 * function: func_021D696C
 * address: 0x021D696C
 * packet: pkt_ov116_021D696C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_IsActive 0x0204E804 arm
 */
#include "../include/Obj13858.h"
extern int FADE_IsActive(void);
int func_021D696C(unsigned char *a,int b) { if(b<=13 && FADE_IsActive()==0 && ((struct Obj13858 *)a)->fB68!=0 && ((struct Obj13858 *)a)->fB6A==0) return 1; return 0; }
