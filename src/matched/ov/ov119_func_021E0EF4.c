/*
 * function: func_021E0EF4
 * address: 0x021E0EF4
 * packet: pkt_ov119_021E0EF4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 0201F73C arg2 is u16 because 021E0FC4..021E0FC6 truncates the loaded full word before the call.
 * prototype: 0201CCE4 forwarding wrapper leaves r0 live; caller stores it at 021E0F94 despite legacy void declaration.
 * symbols:
 *   func_021E106C 0x021E106C thumb ov119
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_02028470 0x02028470 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Cfg;
struct CharBuf;
extern void func_021E106C(char *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_020450F0(u32,u8,u8,u8,u8,u32,u32);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32,u32,u32);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void func_02028470(u8 *,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_0201F73C(void *,int,u16,int);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021E0EF4(char *p,int flag,int x,int y,int w,int h)
{
    void *v;
    func_021E106C(p);
    func_02049B40(23,5,4,448,32,*(u16 *)(p+0x5f4));
    v=func_020450F0(6,x,y,w,h,14,0);
    *(void **)(p+0x71c)=v;
    func_02043B5C(func_02045770(v),15);
    func_0201DD78(1,2,15);
    if(flag==0) {
        *(u32 *)(p+0x72c)=func_0201CCE4((u32)v,0,0,*(u32 *)(p+0x738),*(u32 *)(p+0x728),func_02012FFC(),*(u32 *)(p+0x744),2,*(u16 *)(p+0x5f4),15);
        func_02028470((u8 *)p+0x11d4,2);
    } else {
        func_0201C7A4(func_02045770(v),0,0,*(void **)(p+0x738),*(void **)(p+0x728));
    }
    func_0201F73C(v,1,*(u32 *)(p+0x644),15);
    func_02045334(v);func_02045374(v);func_02041B6C(6);
}
