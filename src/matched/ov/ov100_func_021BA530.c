/*
 * function: func_021BA530
 * address: 0x021BA530
 * packet: pkt_ov100_021BA530
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 veneer 0x0203D170 points to unlabelled 0x0203E590;
 *   veneer evidence cannot attest the target. the integrator owns the ARM9 fix.
 * blocker: 0x0203E590 ARM, verified EXACT with one in blocker-1.log.
 *   symbols: d_021469F0 0x021469F0 data a4
 *   extern unsigned char *d_021469F0;
 *   int GFL_NET_IRC_WIRELESS_GetRetryCountValue(void) {
 *     unsigned char *p=d_021469F0;
 *     if(p==0) return 0;
 *     return p[0x108];
 *   }
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: callee GFL_NET_IRC_WIRELESS_GetRetryCount (veneer to 0x0203E590) still has no witness; GFL_NET_IRC_WIRELESS_GetRetryCountValue filed EXACT as src/matched/arm9/GFL_NET_IRC_WIRELESS_GetRetryCountValue.c, integrator must regenerate labels/manifest so the veneer resolves.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   GFL_NET_IRC_WIRELESS_GetRetryCount 0x0203D170 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 */
typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern int GFL_NET_IRC_WIRELESS_GetRetryCount(void);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
void func_021BA530(int b,int a) {
 if(*(int *)(a+0x280)==0) *(int *)(a+0x280)=(int)func_020450F0((int)5,(int)1,(int)8,(int)23,4,13,0);
 func_02043B5C(func_02045770((struct Descriptor *)(*(int *)(a+0x280))),(int)255);
 func_02045374((struct Cfg *)(*(int *)(a+0x280)));
 func_02045334((struct Descriptor *)(*(int *)(a+0x280)));
 func_0201F73C((void *)(*(int *)(a+0x280)),0,(unsigned short)(*(int *)(a+0x304)),14);
 func_02045CAC((struct MsgBank *)(*(int *)(a+0x288)),(int)b,(void *)(*(int *)(a+0x294)));
 func_0201EFA4((struct WordSet *)(*(int *)(a+0x28c)),(int)0,(int)GFL_NET_IRC_WIRELESS_GetRetryCount(),(int)2,(int)1,(int)1);
 func_0201F250((struct WordSet *)(*(int *)(a+0x28c)),(void *)(*(int *)(a+0x298)),(void *)(*(int *)(a+0x294)));
 func_0201C7A4(func_02045770((struct Descriptor *)(*(int *)(a+0x280))),0,2,(void *)(*(int *)(a+0x298)),(void *)(*(int *)(a+0x290)));
 func_02045334((struct Descriptor *)(*(int *)(a+0x280)));
}
