/*
 * function: func_021DC9F4
 * address: 0x021DC9F4
 * packet: pkt_ov137_021DC9F4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_020307B0 0x020307B0 arm
 * func_02030734 0x02030734 arm
 * func_02082BCC 0x02082BCC arm
 * func_02031348 0x02031348 arm
 * d_021E2260 0x021E2260 data a4
 * d_021DC800 0x021DC800 data a4 ov131
 * d_021E1A44 0x021E1A44 data a4
 * d_00000083 0x00000083 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020307B0(void *);
extern void *func_02030734(u16,u32,int,const void *,int);
extern void func_02082BCC(void *,int,u32);
extern void func_02012944(void *);
extern void *func_0200CA1C(void *);
extern void *func_02012934(void *p);
extern int func_0201AA18(void *);
extern u32 func_0200CA38(void *);
extern void func_02031348(void *,int,const void *,void *);
extern const u8 d_021E2260[],d_021DC800[],d_021E1A44[],d_00000083[];
int func_021DC9F4(u32 *p)
{
    u32 *v=(u32 *)p[6];
    int mode=v[16],sel=v[15];
    void *q;
    void *r;
    func_020307B0(v);
    if(mode==1) {
        func_02012944((void *)p[4]);
        q=func_0200CA1C((void *)p[4]);
        p[7]=(u32)func_02030734(4,40,0,d_021E2260,328);
        func_02082BCC((void *)p[7],0,40);
        r=(void *)func_02012934((void *)p[4]);
        *(void **)p[7]=r;
        *(u32 *)(p[7]+8)=p[4];
        *(u8 *)(p[7]+12)=1;
        *(u8 *)(p[7]+14)=func_0201AA18(r);
        *(u8 *)(p[7]+15)=0;
        *(u8 *)(p[7]+13)=1;
        *(u16 *)(p[7]+20)=0;
        *(u8 *)(p[7]+16)=0;
        *(u32 *)(p[7]+24)=func_0200CA38(q);
        p[1]=sel;
        *(u8 *)(p[7]+15)=sel;
        func_02031348((void *)p[8],(int)d_00000083,d_021DC800,(void *)p[7]);
        p[0]=3;
    } else {
        *(u32 *)(p[3]+4)=sel;
        func_02031348((void *)p[8],-1,d_021E1A44,(void *)p[3]);
        *(u32 *)p[3]=3;
        p[0]=4;
    }
    return 0;
}
