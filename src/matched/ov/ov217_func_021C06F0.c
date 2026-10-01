/*
 * function: func_021C06F0
 * address: 0x021C06F0
 * packet: pkt_ov217_021C06F0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C377C 0x021C377C data a4
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   func_020255A0 0x020255A0 thumb
 *   func_02025774 0x02025774 thumb
 *   func_020257D0 0x020257D0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Param { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };
struct Entry { s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };
struct Sys;
struct Grid;
struct Obj;
extern const struct Entry d_021C377C[];
extern u32 func_021BF9F0(void *,u32);
extern struct Grid *func_020255A0(struct Sys *,const struct Param *);
extern void func_02025774(u8 *,u32);
extern void func_020257D0(struct Obj *);
void func_021C06F0(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct Param param;
    int i;
    const struct Entry *q;
    u8 *dest;
    sysOff=0x3B0; sysOff=0x3A4;
    outOff=0x3B0; outOff=0x3A8;
    callOff=0x3B0; callOff=0x3A8;
    uploadOff=0x3B0; uploadOff=0x3A8;
    for(i=0;i<2;i++) {
        dest=p+i*4;
        param.bmp=*(void **)(dest+0x3B0);
        q=&d_021C377C[i];
        param.x=q->x; param.y=q->y;
        param.f8=func_021BF9F0(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=func_020255A0(*(struct Sys **)(p+sysOff),&param);
        func_02025774(*(u8 **)(dest+callOff),0);
        func_020257D0(*(struct Obj **)(dest+uploadOff));
    }
}
