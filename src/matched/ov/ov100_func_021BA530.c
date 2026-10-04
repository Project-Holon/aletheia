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
 *   veneer evidence cannot attest the target. Ilias owns the ARM9 fix.
 * blocker: 0x0203E590 ARM, verified EXACT with one in blocker-1.log.
 *   symbols: d_021469F0 0x021469F0 data a4
 *   extern unsigned char *d_021469F0;
 *   int func_0203E590(void) {
 *     unsigned char *p=d_021469F0;
 *     if(p==0) return 0;
 *     return p[0x108];
 *   }
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: callee func_0203D170 (veneer to 0x0203E590) still has no witness; func_0203E590 filed EXACT as src/matched/arm9/func_0203E590.c, integrator must regenerate labels/manifest so the veneer resolves.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_0203D170 0x0203D170 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 */
extern int func_020450F0(int,int,int,int,unsigned char,unsigned char,unsigned char),func_02045770(int),func_0203D170(void);
extern void func_02043B5C(int,int),func_02045374(int),func_02045334(int),func_0201F73C(int,int,unsigned short,int),func_02045CAC(int,int,int),func_0201EFA4(int,int,int,int,int,int),func_0201F250(int,int,int),func_0201C7A4(int,short,short,int,int);
void func_021BA530(int b,int a) {
 if(*(int *)(a+0x280)==0) *(int *)(a+0x280)=func_020450F0(5,1,8,23,4,13,0);
 func_02043B5C(func_02045770(*(int *)(a+0x280)),255);
 func_02045374(*(int *)(a+0x280));
 func_02045334(*(int *)(a+0x280));
 func_0201F73C(*(int *)(a+0x280),0,*(int *)(a+0x304),14);
 func_02045CAC(*(int *)(a+0x288),b,*(int *)(a+0x294));
 func_0201EFA4(*(int *)(a+0x28c),0,func_0203D170(),2,1,1);
 func_0201F250(*(int *)(a+0x28c),*(int *)(a+0x298),*(int *)(a+0x294));
 func_0201C7A4(func_02045770(*(int *)(a+0x280)),0,2,*(int *)(a+0x298),*(int *)(a+0x290));
 func_02045334(*(int *)(a+0x280));
}
