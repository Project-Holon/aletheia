/*
 * function: func_021F51E4
 * address: 0x021F51E4
 * packet: pkt_ov194_021F51E4
 * region: ov194
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_0206E964 0x0206E964 arm
 *   func_02030734 0x02030734 arm
 *   func_0204B7F0 0x0204B7F0 arm
 *   func_0204AA94 0x0204AA94 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020862F0 0x020862F0 arm
 *   func_0204B764 0x0204B764 arm
 *   func_02063800 0x02063800 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_02049238 0x02049238 arm
 *   func_021F513C 0x021F513C thumb ov194
 *   d_021F57A8 0x021F57A8 data ov194 a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { int w[5]; } Palette;
extern void *func_020490F4(unsigned,u16);
struct ArcFile;
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern u8 *func_0206E964(u8 *);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern u16 func_0204B7F0(u8 *);
extern void func_0204AA94(int,void *,u32,int,int);
extern void func_020307B0(void *);
extern void func_020862F0(void *,unsigned);
extern void func_0204B764(const char *,Palette *);
extern int func_02063800(char *,int);
extern void func_0207E51C(void *,int,unsigned);
extern void func_0207E5D0(void *,int,unsigned);
extern void func_02049238(void *);
extern void func_021F513C(void *,int,int,int,int,int,void *);
extern const char d_021F57A8[];
static inline u8 *entry(u8 *p,u32 i) {
    if(p) {
        u8 *q=p+0x3c;
        if(q && i<*(u8 *)(p+0x3d)) {
                u16 off=*(u16 *)(p+0x42);
                u16 stride=*(u16 *)(q+off);
                return q+off+4+stride*i;
        } else return 0;
    }
    return 0;
}
void func_021F51E4(u8 *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap)
{
    Palette pal;
    u32 size=width*height*32;
    void *archive=func_020490F4(arc,heap);
    u8 *raw=func_02049250(archive,member,heap);
    u8 *tex=func_0206E964(raw);
    u8 *pixels;
    u32 offset;
    offset=(*(u32 *)entry(tex,index)&0xffff)*8;
    pixels=tex+*(u32 *)(tex+20);
    void *buf=func_02030734((u16)((heap&0x7fff)|0x8000),size,0,d_021F57A8,95);
    func_021F513C(pixels+offset,width,0,0,width,height,buf);
    func_0204AA94(func_0204B7F0(dst),buf,size,pos,mode);
    func_020307B0(buf);
    u32 poff=*(u32 *)(tex+56);
    func_020862F0(tex+poff,32);
    func_0204B764((const char *)dst,&pal);
    if(mode==0 || mode==2) func_0207E51C(tex+poff,func_02063800((char *)&pal,1),32);
    if(mode==1 || mode==2) func_0207E5D0(tex+poff,func_02063800((char *)&pal,2),32);
    func_020307B0(raw);
    func_02049238(archive);
}
