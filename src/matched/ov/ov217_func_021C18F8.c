/*
 * function: CircleGraph_BuildVertices
 * address: 0x021C18F8
 * packet: pkt_ov217_021C18F8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Callee B60/B4C full matched bodies explicitly return (u16); caller uses their halfword payloads.
 * symbols:
 *   CircleGraph_GetSlice 0x021C1AB4 thumb ov217
 *   CircleGraph_GetCenterColor 0x021C1B60 thumb ov217
 *   CircleGraph_GetRimColor 0x021C1B4C thumb ov217
 *   CircleGraph_GetPointRange 0x021C1B28 thumb ov217
 *   func_0207CA30 0x0207CA30 arm
 */
#include "../include/Obj00554.h"
#include "../include/Obj03377.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
enum Counter { ZERO=0 };
struct Range {u8 max,min;u16 x,y,z;};
extern void *CircleGraph_GetSlice(void *,u32);
extern u16 CircleGraph_GetCenterColor(void *);
extern u16 CircleGraph_GetRimColor(void *);
extern void CircleGraph_GetPointRange(u8 *,u8 *,u8 *);
extern void func_0207CA30(const s16 *,const s16 *,s16 *);
void CircleGraph_BuildVertices(u8 *p)
{
    struct Range range;
    int count=p[0x1ac];
    int k=0;
    int i;
    for(i=0;i<count;i++) {
        u8 *rec;
        u16 color,color2;
        int j;
        rec=CircleGraph_GetSlice(p,i);
        color=CircleGraph_GetCenterColor(rec);
        color2=CircleGraph_GetRimColor(rec);
        CircleGraph_GetPointRange(rec,&range.min,&range.max);
        range.x=((struct Obj00554 *)p)->f1B4;
        range.y=((struct Obj00554 *)p)->f1B6;
        range.z=((struct Obj00554 *)p)->f1B8+i*205;
        for(j=range.min;j<=range.max;j++) {
            u8 *q=p+k*10;
            ((struct Obj03377 *)q)->f418=color;
            ((struct Obj03377 *)q)->f412=range.x;
            ((struct Obj03377 *)q)->f414=range.y;
            ((struct Obj03377 *)q)->f416=range.z;
            q[0x41a]=i;
            ((struct Obj03377 *)q)->f422=color2;
            func_0207CA30((s16 *)&range.x,(s16 *)(p+0x1ba+j*6),(s16 *)(p+0x412+((u32)k+1)*10));
            q[0x424]=i;
            ((struct Obj03377 *)q)->f42C=color2;
            func_0207CA30((s16 *)&range.x,(s16 *)(p+0x1ba+((j+1)%100)*6),(s16 *)(p+0x412+((u32)k+2)*10));
            q[0x42e]=i;
            k+=3;
        }
    }
}
