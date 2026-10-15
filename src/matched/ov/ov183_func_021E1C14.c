/*
 * function: BR_CODEIN_ProfileFindActorIndex
 * address: 0x021E1C14
 * packet: pkt_ov183_021E1C14
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding.
 */
#include "../include/Obj24628.h"

int BR_CODEIN_ProfileFindActorIndex(char *p,int a){int i,n; n=((struct Obj24628 *)p)->f23C;for(i=0;i<n;i++){if(a==*(int *)(p+i*28+4))return i;}return 0;}
