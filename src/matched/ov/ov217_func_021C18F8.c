/*
 * function: func_021C18F8
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
 *   func_021C1AB4 0x021C1AB4 thumb ov217
 *   func_021C1B60 0x021C1B60 thumb ov217
 *   func_021C1B4C 0x021C1B4C thumb ov217
 *   func_021C1B28 0x021C1B28 thumb ov217
 *   func_0207CA30 0x0207CA30 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
enum Counter { ZERO=0 };
struct Range {u8 max,min;u16 x,y,z;};
extern void *func_021C1AB4(void *,u32);
extern u16 func_021C1B60(void *);
extern u16 func_021C1B4C(void *);
extern void func_021C1B28(u8 *,u8 *,u8 *);
extern void func_0207CA30(const s16 *,const s16 *,s16 *);
void func_021C18F8(u8 *p)
{
    struct Range range;
    int count=p[0x1ac];
    int k=0;
    int i;
    for(i=0;i<count;i++) {
        u8 *rec;
        u16 color,color2;
        int j;
        rec=func_021C1AB4(p,i);
        color=func_021C1B60(rec);
        color2=func_021C1B4C(rec);
        func_021C1B28(rec,&range.min,&range.max);
        range.x=*(s16 *)(p+0x1b4);
        range.y=*(s16 *)(p+0x1b6);
        range.z=*(s16 *)(p+0x1b8)+i*205;
        for(j=range.min;j<=range.max;j++) {
            u8 *q=p+k*10;
            *(u16 *)(q+0x418)=color;
            *(u16 *)(q+0x412)=range.x;
            *(u16 *)(q+0x414)=range.y;
            *(u16 *)(q+0x416)=range.z;
            q[0x41a]=i;
            *(u16 *)(q+0x422)=color2;
            func_0207CA30((s16 *)&range.x,(s16 *)(p+0x1ba+j*6),(s16 *)(p+0x412+((u32)k+1)*10));
            q[0x424]=i;
            *(u16 *)(q+0x42c)=color2;
            func_0207CA30((s16 *)&range.x,(s16 *)(p+0x1ba+((j+1)%100)*6),(s16 *)(p+0x412+((u32)k+2)*10));
            q[0x42e]=i;
            k+=3;
        }
    }
}
