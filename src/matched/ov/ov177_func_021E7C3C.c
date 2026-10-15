/*
 * function: WIFIBATTLEMATCH_VIEW_CreateRecordActorFromRec
 * address: 0x021E7C3C
 * packet: pkt_ov177_021E7C3C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_GetEntryValue 0x021E7CF0 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_GetFrameIndex 0x021E5978 thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 */
#include "../include/Obj03326.h"
extern unsigned WIFIBATTLEMATCH_VIEW_GetEntryValue(unsigned,unsigned,unsigned);
extern int WIFIBATTLEMATCH_VIEW_GetFrameIndex(int *p, int i);
extern void MI_CpuFill8(void *,int,int);
extern void *CLACT_CreateActor(void *,int,int,int,short *,int,unsigned);
void WIFIBATTLEMATCH_VIEW_CreateRecordActorFromRec(char *p,char *q,void *x,void *data,unsigned heap)
{
 unsigned i,n;
 short b[4];
 n=WIFIBATTLEMATCH_VIEW_GetEntryValue(*(unsigned *)&((struct Obj03326 *)q)->f30,((struct Obj03326 *)q)->f28,((struct Obj03326 *)q)->f2C);
 MI_CpuFill8(b,0,8);
 b[0]=0x100;b[1]=0x10;
 for(i=0;i<n;i++) {
 int a,c,d;
 b[0]+=0x10;b[2]=i+2;
 a=WIFIBATTLEMATCH_VIEW_GetFrameIndex(data,2);c=WIFIBATTLEMATCH_VIEW_GetFrameIndex(data,0);d=WIFIBATTLEMATCH_VIEW_GetFrameIndex(data,4);
 *(void **)(p+i*4+0x68)=CLACT_CreateActor(x,a,c,d,b,0,heap);
 }
}
