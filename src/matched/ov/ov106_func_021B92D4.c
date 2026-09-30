/*
 * function: func_021B92D4
 * address: 0x021B92D4
 * packet: pkt_ov106_021B92D4
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B9680 0x021B9680 data ov106 a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { void *bmp; s16 x,y; int f8,fc;u8 f10,f11;u16 f12;int f14; } Param;
extern const char d_021B9680[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_020457B0(int,u16);
extern void *func_02043678(unsigned,unsigned,unsigned,u16);
extern void *func_020255A0(void *,Param *);
void *func_021B92D4(const u8 *pos,u16 a,u16 b,int c,u8 d,int e,void *sys,void *owner,u16 heap) {
 u8 *p; Param cfg;
 p=func_02030734(heap,36,0,d_021B9680,3402);
 func_02082BCC(p,0,36);
 *(void **)(p+32)=owner;
 *(void **)(p+24)=func_020457B0(128,heap);
 *(void **)p=func_02043678(a,b,32,heap);
 func_02082BCC(&cfg,0,24);
 cfg.bmp=*(void **)p;cfg.x=*(s16 *)pos;cfg.y=*(s16 *)(pos+2);
 cfg.f8=c;cfg.f10=pos[6];cfg.f12=e;cfg.f14=e;cfg.f11=pos[7];cfg.fc=d;
 *(void **)(p+28)=func_020255A0(sys,&cfg);
 return p;
}
