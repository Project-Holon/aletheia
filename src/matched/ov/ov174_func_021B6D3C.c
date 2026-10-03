/*
 * unit: yes
 * function: func_021B6D3C,func_021B6F24
 * address: 0x021B6D3C
 * packet: pkt_ov174_021B6D3C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: trailing store-and-return follower 021B6F24 included in this unit; 021B6F2A..021B6F2C is alignment padding.
 * symbols:
 *   func_021B7180 0x021B7180 thumb ov174
 *   func_021B71A0 0x021B71A0 thumb ov174
 *   func_020307B0 0x020307B0 arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020056EC 0x020056EC thumb
 *   func_0204B95C 0x0204B95C arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B918 0x0204B918 arm
 *   func_0204B974 0x0204B974 arm
 *   d_021B7485 0x021B7485 data a1
 *   d_021B7481 0x021B7481 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021B7180(u8 *,u8 *,int);
extern void func_021B71A0(int,int *,int,int,int);
extern void func_020307B0(void *);
typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
extern unsigned func_020056EC(unsigned);
extern void func_0204B95C(void *),func_0204B9A0(void *),func_0204B974(void *);
extern int func_0204B98C(void *),func_0204B918(void *);
extern const u8 d_021B7485[],d_021B7481[];
void func_021B6D3C(u8 *p,u8 *q)
{
    unsigned size;
    unsigned pal;
    unsigned base;
    unsigned step;
    if(*(int *)(p+8)==2) size=0x6000; else size=0x3000;
    if(p[13]==0) pal=0;else pal=0xC000;
    if(*(int *)(p+8)==2) base=0;else base=0x1C00;
    switch(*(unsigned *)(q+8)) {
    case 1:
        q[1]=0;
        func_021B7180(p,q,q[4]+d_021B7485[q[2]*3]);
        *(unsigned *)(q+8)=2;
        break;
    case 2:
        step=q[1]*0x3000u;
        func_021B71A0((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x10000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            *(unsigned *)(q+8)=3;
            func_020307B0(*(void **)(q+16));
            *(void **)(q+16)=0;
        }
        break;
    case 3:
        q[1]=0;
        func_021B7180(p,q,(q[5]+d_021B7481[q[3]*2])+(*(int *)(p+16)*2));
        *(unsigned *)(q+8)=4;
        break;
    case 4:
        step=q[1]*0x3000u;
        func_021B71A0((int)p,(int *)q,base+step,pal+(step+(size*q[0]+0x28000)),0x3000);
        q[1]++;
        if(q[1]*0x3000u>=size) {
            *(unsigned *)(q+8)=5;
            func_020307B0(*(void **)(q+16));
            *(void **)(q+16)=0;
        }
        break;
    case 0:
        break;
    }
    if(q[6]<40) q[6]++;
    else if(*(unsigned *)(q+8)==5 || *(unsigned *)(q+8)==0) {
        q[6]=0;
        q[4]=q[4]==0?1:0;
        q[5]=q[5]==0?1:0;
    }
    if(*(int *)(q+20)==1 && func_0201C6B4(*(void **)(p+120))==1) {
        func_02045334(*(void **)(q+24));
        *(int *)(q+20)=0;
    }
    *(u16 *)(q+48)+=(u16)(func_020056EC(2)+1);
    if(*(u16 *)(q+48)>=150) {
        func_0204B95C(*(void **)(q+40));
        func_0204B9A0(*(void **)(q+40));
        *(u16 *)(q+48)=0;
    }
    if(*(int *)(q+52)==1 || *(u16 *)(q+56)!=0) {
        if(func_0204B98C(*(void **)(q+44))==0) func_0204B95C(*(void **)(q+44));
    } else {
        if(func_0204B98C(*(void **)(q+44))==1 && func_0204B918(*(void **)(q+44))==0)
            func_0204B974(*(void **)(q+44));
    }
    if(*(u16 *)(q+56)!=0) (*(u16 *)(q+56))--;
}
void func_021B6F24(u8 *unused,u8 *q,int unused2)
{
    *(int *)(q+8)=1;
}
