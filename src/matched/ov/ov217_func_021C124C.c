/*
 * function: CircleGraph_DrawSlices
 * address: 0x021C124C
 * packet: pkt_ov217_021C124C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: geometry FIFO 040004A4,04000500,04000480,0400048C,04000504 written at 021C133E..021C13C8.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef enum { GX_POLYGONMODE_MODULATE=0 } GXPolygonMode;
typedef enum { GX_CULL_NONE=3 } GXCull;
typedef enum { GX_BEGIN_TRIANGLES=0 } GXBegin;
static inline void G3_PolygonAttr(int light,GXPolygonMode mode,GXCull cull,int id,int alpha,int misc)
{
    *(volatile u32 *)0x040004a4=light|(mode<<4)|(cull<<6)|(id<<24)|(alpha<<16)|misc;
}
static inline void G3_Begin(GXBegin primitive) { *(volatile u32 *)0x04000500=primitive; }
static inline void G3_Color(u16 rgb) { *(volatile u32 *)0x04000480=rgb; }
static inline void G3_Vtx(s16 x,s16 y,s16 z)
{
    *(volatile u32 *)0x0400048c=(u32)(u16)x|((u32)(u16)y<<16);
    *(volatile u32 *)0x0400048c=(u32)(u16)z;
}
static inline void G3_End(void) { *(volatile u32 *)0x04000504=0; }
void CircleGraph_DrawSlices(u8 *p)
{
    int n,i,index;
    u32 rest=(u32)p;
    switch(*(u32 *)(p+8)) {
    case 0: n=0; break;
    case 1: n=*(u32 *)(p+16)*100/120; rest=100-n; break;
    case 2: n=*(u32 *)(p+16)*100/30; rest=100-n; break;
    case 3: n=(20-*(u32 *)(p+16))*100/20; rest=100-n; break;
    case 4: n=100; rest=0; break;
    case 5: n=*(u32 *)(p+16)*100/60; rest=100-n; break;
    }
    index=rest*3;
    for(i=0;i<n;i++) {
        G3_PolygonAttr(0,GX_POLYGONMODE_MODULATE,GX_CULL_NONE,p[index*10+0x41a],31,0);
        G3_Begin(GX_BEGIN_TRIANGLES);
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16 *)(p+index*10+0x412),*(s16 *)(p+index*10+0x414),*(s16 *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16 *)(p+index*10+0x412),*(s16 *)(p+index*10+0x414),*(s16 *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16 *)(p+index*10+0x412),*(s16 *)(p+index*10+0x414),*(s16 *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_End();
    }
}
