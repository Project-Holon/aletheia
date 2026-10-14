/*
 * function: GURU2_MAIN_StateAnimateSlots
 * address: 0x021DEE4C
 * packet: pkt_ov137_021DEE4C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: unlabelled follower at 021DEED8, filed separately.
 * lever: raw unsigned byte-table address and a named row byte offset restore r6.
 * symbols:
 *   GURU2_MAIN_GetSendBuffer 0x021E16C0 thumb ov137
 *   GURU2_MAIN_StartDropEffect 0x021E0C08 thumb ov137
 *   gGuru2PointerAngleTable 0x021E1FDC data a2
 */
#include "../include/Obj06537.h"
typedef unsigned short u16;
extern char *GURU2_MAIN_GetSendBuffer(char *p);
extern void GURU2_MAIN_StartDropEffect(char *,int,int,int,int,int,int *);
extern const u16 gGuru2PointerAngleTable[][5];
int GURU2_MAIN_StateAnimateSlots(char *p)
{
    int *r;
    int value, a, row;
    if (--((struct Obj06537 *)p)->fC>0) return 0;
    ((struct Obj06537 *)p)->fC=15;
    r=(int *)GURU2_MAIN_GetSendBuffer(p);
    row=r[5]*10;
    value=*(const u16 *)((unsigned)gGuru2PointerAngleTable+row+r[4]*2);
    a=*(u16 *)(p+0x7e + r[4]*4);
    *(u16 *)(p+0x60+r[4]*2)=value;
    GURU2_MAIN_StartDropEffect(p,a,r[4],r[0],value,r[1],(int *)(p+0x2e0+r[4]*0xb4));
    r[4]++;
    r[4]%=r[5];
    if (++r[0]==r[5]) {
        ((struct Obj06537 *)p)->fC=0;
        ((struct Obj06537 *)p)->f0=18;
    }
    return 0;
}
