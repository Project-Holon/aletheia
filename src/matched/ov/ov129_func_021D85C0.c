/*
 * function: func_021D85C0
 * address: 0x021D85C0
 * packet: pkt_ov129_021D85C0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 020434CC is in unit_0204349C.c but omitted from function:;
 *   one MATCH (020434B4 unwitnessed), enclosing 0204349C TU EXACT:
 *   extern unsigned d_02146A48[];
 *   void func_0204349C(void) { d_02146A48[1]&=16; }
 *   void func_020434B4(void) { d_02146A48[1]&=15; }
 *   void func_020434CC(void) { func_0204349C(); func_020434B4(); }
 * blocker: ARM9 02043588 is in unit_02043570.c but omitted from function:;
 *   one EXACT, fixed compiler/flags ARM:
 *   extern void func_02043558(void),func_02043570(void);
 *   void func_02043588(void) { func_02043558(); func_02043570(); }
 * note: local allocated pointer, separate from entry object, fixes r4/r5 coloring.
 * note: 0203159C own void prototype widened because caller consumes returned r0.
 * volatile: GX registers read at 021D8642/021D864C and written at 021D864A/021D8650.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0202E4EC 0x0202E4EC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_02021518 0x02021518 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_021D8804 0x021D8804 thumb ov129
 *   func_021D9838 0x021D9838 thumb ov129
 *   func_021D89C4 0x021D89C4 thumb ov129
 *   func_021D9490 0x021D9490 thumb ov129
 *   func_0207D63C 0x0207D63C arm
 *   func_021D893C 0x021D893C thumb ov129
 *   func_020056A0 0x020056A0 thumb
 *   func_0203D34C 0x0203D34C arm
 *   d_021DA800 0x021DA800 data a4
 */
typedef unsigned u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u32 words[9]; } Param;
extern void func_0203064C(void *,u32,u32);
extern void *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,int,u32);
extern Param *func_0202E4EC(u32,u32,u32,u32,u32 *);
extern void func_020307B0(void *);
extern void func_020434CC(void),func_02043588(void);
extern void *func_020490F4(u32,u16);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void *func_02021518(u32),*func_0201D7EC(int,int,int,int,u32);
extern void func_02021EE4(void *,int),func_0202155C(void *,u32,u32,u32);
extern void func_021D8804(void),func_021D9838(u8 *,const u32 *),func_021D89C4(u8 *),func_021D9490(u8 *);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D893C(int,char *);
extern void *func_020056A0(u32,u32,u32);
extern void func_0203D34C(u32,u32);
extern const u32 d_021DA800[];
static inline void GX_SetVisiblePlane(int plane) { *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & ~0x1F00u)|((u32)plane<<8); }
static inline void GXS_SetVisiblePlane(int plane) { *(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000 & ~0x1F00u)|((u32)plane<<8); }
int func_021D85C0(void *obj,void *unused,const Param *cfg)
{
    u8 *p;
    u32 sizes[3];
    Param *q;
    func_0203064C((void *)1,50,0x40000);
    p=func_0203159C(obj,0x34C,50);
    func_02082BCC(p,0,0x34C);
    if(cfg==0) {
        sizes[0]=4; sizes[1]=4; sizes[2]=4;
        q=func_0202E4EC(50,0,0,12,sizes);
        *(Param *)(p+0x328)=*q;
        func_020307B0(q);
    } else *(Param *)(p+0x328)=*cfg;
    func_020434CC(); func_02043588();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    *(void **)(p+0x258)=func_020490F4(59,50);
    func_0203F8F4(50); func_02045088(50);
    *(void **)(p+0x290)=func_02021518(50);
    *(void **)(p+0x314)=func_0201D7EC(23,0,0,0,50);
    func_02021EE4(*(void **)(p+0x290),1);
    func_0202155C(*(void **)(p+0x290),0,512,50);
    func_021D8804();
    func_021D9838(p,d_021DA800); func_021D89C4(p); func_021D9490(p);
    func_0207D63C((void *)0x04000050,0,6,15,7);
    func_0207D63C((void *)0x04001050,0,14,7,8);
    *(void **)(p+0x318)=func_020056A0((u32)func_021D893C,(u32)p,16);
    func_0203D34C(1,50);
    return 1;
}
