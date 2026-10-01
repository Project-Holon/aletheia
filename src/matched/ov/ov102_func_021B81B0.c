/*
 * function: func_021B81B0
 * address: 0x021B81B0
 * packet: pkt_ov102_021B81B0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_020870D0 0x020870D0 arm
 * func_0209C2B0 0x0209C2B0 arm
 * func_021B8624 0x021B8624 thumb ov102
 * func_021B86FC 0x021B86FC thumb ov102
 * func_021B870C 0x021B870C thumb ov102
 * func_021B86F8 0x021B86F8 thumb ov102
 * func_021B7254 0x021B7254 thumb ov101
 * func_021B7250 0x021B7250 thumb ov101
 * func_021B72A0 0x021B72A0 thumb ov101
 * func_021B72A8 0x021B72A8 thumb ov101
 * func_021B63BC 0x021B63BC thumb ov101
 * func_021B7F08 0x021B7F08 thumb ov102
 * func_021B7DFC 0x021B7DFC thumb ov102
 * func_021B82DC 0x021B82DC thumb ov102
 * func_021B838C 0x021B838C thumb ov102
 * func_021B7F24 0x021B7F24 thumb ov102
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned long long func_020870D0(void);
extern u32 func_0209C2B0(u32,u32);
extern void func_021B8624(u8 *);
extern int func_021B86FC(u8 *),func_021B870C(u8 *,u32 *);
extern void func_021B86F8(u8 *,u32);
extern int func_021B7254(void *),func_021B7250(void *);
extern void func_021B72A0(void *,int),func_021B72A8(void *,u32);
extern void func_021B63BC(void *);
extern void func_021B7F08(u8 *,void (*)(u8 *,u16 *));
extern void func_021B7DFC(u8 *,void *,int,int,short);
extern void func_021B82DC(u8 *,u16 *),func_021B838C(u8 *,u16 *),func_021B7F24(u8 *,u16 *);
void func_021B81B0(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        *(u32 *)(p+0x494)=2;
        *(u32 *)(p+0x4a0)=0;
        *(u32 *)(p+0x490)=func_0209C2B0((u32)func_020870D0()<<6,33514);
        *state=1;
        break;
    case 1:
        func_021B8624(p+0xc0);
        if(func_021B86FC(p+0xc0)) func_021B72A0(*(void **)(p+0x468),0);
        if(func_021B870C(p+0xc0,(u32 *)(p+0x494))) {
            switch(*(u32 *)(p+0x494)) {
            case 0: *state=2; break;
            case 1:
                *(u32 *)(*(u8 **)(p+0x48c)+12)=1;
                func_021B7F08(p,func_021B82DC);
                break;
            }
        }
        *(u32 *)(p+0x498)=func_0209C2B0((u32)func_020870D0()<<6,33514)-*(u32 *)(p+0x490);
        if(func_021B7254(*(void **)(p+0x468))) func_021B86F8(p+0xc0,0);
        if(func_021B7250(*(void **)(p+0x468))==1) {
            func_021B63BC(*(void **)(*(u8 **)(p+0x48c)+4));
            func_021B7F08(p,func_021B838C);
        }
        break;
    case 2:
        func_021B7DFC(p+0xac,p+0x9c,3,0,0);
        func_021B72A8(*(void **)(p+0x468),1);
        func_021B72A0(*(void **)(p+0x468),0);
        func_021B7F08(p,func_021B7F24);
        break;
    }
}
