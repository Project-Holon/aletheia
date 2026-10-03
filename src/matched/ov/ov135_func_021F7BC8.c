/*
 * function: func_021F7BC8
 * address: 0x021F7BC8
 * packet: pkt_ov135_021F7BC8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: signed halfword selection store keeps the unsigned argument truncation after it.
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F7B9C 0x021F7B9C thumb ov135
 *   func_021F81C8 0x021F81C8 thumb ov135
 *   func_021F89A8 0x021F89A8 thumb ov135
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F99F0(void *);
extern void func_0201F7A8(void *,u32);
extern void func_021F4EC0(void *,u32,u32);
extern u32 func_0201ADE4(u16,u16,u16);
extern u32 func_0201AE1C(u32,u32);
extern void func_0201AE14(u32);
extern int func_021F7B9C(void *,int);
extern void func_021F81C8(void *,void *,void *,void *,int,int,int,void *);
extern void func_021F89A8(void *,int,u16,u16);
int func_021F7BC8(u8 *p)
{
    int result=func_021F99F0(*(void **)(p+0xDE4));
    u32 h,v;
    int mode;
    u8 *target;
    switch(result) {
    case (u32)-2:
        func_0201F7A8(*(void **)(p+0xD40),0);
        func_021F4EC0(p,5,5);
        *(u32 *)(p+0x28)=2;
        target=*(u8 **)(p+0xE00);
        func_021F89A8(p+0xEEC,*(u16 *)(target+6)+*(u16 *)(target+4),*(u16 *)(target+10),*(u16 *)(target+8));
        break;
    case (u32)-1:
        break;
    default:
        *(short *)(p+0xB50)=result;
        h=func_0201ADE4((u16)result,0,0x48);
        v=func_0201AE1C(h,20);
        func_0201AE14(h);
        *(u32 *)(*(u8 **)(p+0xE00)+0x20)=v;
        if(func_021F7B9C(p+0xB50,*(u32 *)(*(u8 **)(p+0xE00)+0x20))) {
            *(u32 *)(p+0x28)=10;
            mode=*(signed char *)(p+0xB52);
        } else {
            *(u32 *)(p+0x28)=7;
            mode=3;
        }
        func_021F81C8(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(void **)(p+0xB68),p+0xD90,*(short *)(p+0xB50),mode,-1,p+0xFA0);
        target=*(u8 **)(p+0xE00);
        func_021F89A8(p+0xEEC,*(u16 *)(target+6)+*(u16 *)(target+4),*(u16 *)(target+10),*(u16 *)(target+8));
        break;
    }
    return 2;
}
