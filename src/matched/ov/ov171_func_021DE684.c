/*
 * function: DENDOU_VIEW_SortActorPriorities
 * address: 0x021DE684
 * packet: pkt_ov171_021DE684
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_GetActiveActorBase 0x021DE5F4 thumb ov171
 *   DENDOU_VIEW_GetActorPos 0x021DE0E4 thumb ov171
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 */
#include "../include/Obj10661.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int DENDOU_VIEW_GetActiveActorBase(char *);
extern void DENDOU_VIEW_GetActorPos(u8 *,int,s16 *,s16 *);
struct Node;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
void DENDOU_VIEW_SortActorPriorities(u8 *p)
{
    u8 order[6];
    s16 a[2],b[2];
    int start=DENDOU_VIEW_GetActiveActorBase((char *)p);
    u8 i,j,t;
    void *r;
    for(i=0;i<6;i++) order[i]=start+i;
    for(i=0;i<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4)-1;i++) {
        DENDOU_VIEW_GetActorPos(p,order[i],&a[1],&a[0]);
        for(j=i+1;j<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4);j++) {
            DENDOU_VIEW_GetActorPos(p,order[j],&b[1],&b[0]);
            if(a[0]<b[0]) {t=order[i];order[i]=order[j];order[j]=t;a[0]=b[0];}
        }
    }
    for(i=0;i<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4);i++) {
        r=*(void **)(p+order[i]*4+0xb74);
        if(r) CLACT_SetActorDrawPriority(r,i);
    }
}
