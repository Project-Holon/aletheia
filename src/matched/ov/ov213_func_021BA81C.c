/*
 * function: func_021BA81C
 * address: 0x021BA81C
 * packet: pkt_ov213_021BA81C
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA8BC 0x021BA8BC thumb ov213
 *   func_02050C04 0x02050C04 arm
 *   func_02051758 0x02051758 arm
 *   func_02051648 0x02051648 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051B04 0x02051B04 arm
 *   func_020056BC 0x020056BC thumb
 *   func_02051230 0x02051230 arm
 *   d_021BB324 0x021BB324 data a4
 *   d_021BB330 0x021BB330 data a4
 *   d_021BB360 0x021BB360 data a4
 * arity: 51758 reads only a0; full body calls 48AC4 with p20 only;
 * 48AC4 forwards that sole pointer to 307B0. Caller supplies no r2/r3.
 * 8BC receives visibly live p and p10 at 021BA82A.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Src648 {u32 f00,f04,f08,f0c,f10,f14,f18,f1c;};
struct Dst648;
extern int d_021BB324[],d_021BB330[],d_021BB360[];
extern void func_021BA8BC(u8 *p,int object);
extern int func_02050C04(int a,int b,int c,int d);
extern int func_02051758(int a);
extern void func_02051648(struct Dst648 *p,struct Src648 *src,u16 a2,int *a3,int *a4,int *a5,u32 heap);
extern int func_0205121C(u32 a,u32 b,u32 c);
extern u16 func_02051B04(void *res);
extern u32 func_020056BC(void);
extern void func_02051230(u8 *o,u32 a1,u32 a2,u32 a3);
void func_021BA81C(u8 *p,unsigned code)
{
    struct Src648 config;
    int resource;
    u32 context;
    if(*(int *)(p+16)) func_021BA8BC(p,*(int *)(p+16));
    *(int *)(p+16)=func_02050C04((int)(p+20),0x4800,1,*(u16 *)(p+4));
    config.f04=0x3000;
    config.f08=-0x3000;
    config.f00=2;
    config.f0c=-0x4000;
    config.f10=0x4000;
    config.f14=0x1000;
    config.f18=0x400000;
    config.f1c=0;
    func_02051758(*(int *)(p+16));
    func_02051648(*(struct Dst648 **)(p+16),&config,0x2000,d_021BB330,d_021BB324,d_021BB360,*(u16 *)(p+4));
    resource=func_0205121C(0xB5,code,*(u16 *)(p+4));
    p[0x4814]=func_02051B04((void *)resource);
    context=func_020056BC();
    func_02051230(*(u8 **)(p+16),resource,0,context);
}
