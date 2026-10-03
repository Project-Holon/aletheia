/*
 * function: func_022002A0
 * address: 0x022002A0
 * packet: pkt_ov135_022002A0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: full-word int cast on the window-read address breaks the loop register tie; unsigned base/index addition happens before the cast.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_022028C8 0x022028C8 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020450F0(u32,u8,u8,u8,u8,u8,u16);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u32);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u32 func_02045730(void *);
extern void func_020409B4(u32);
extern u32 func_022028C8(void *,u32,void *,u32,u32,u32,u16,void *);
void func_022002A0(u8 *p)
{
    int i;
    u32 w;
    *(void **)(p+0xD48)=func_020450F0(1,2,1,0x1C,2,1,1);
    func_02043B5C(func_02045770(*(void **)(p+0xD48)),0xA);
    w=*(u32 *)(p+0xD48);
    func_02045334((void *)w); func_02045374((void *)w); func_020409B4(func_02045730((void *)w));
    func_022028C8(*(void **)(p+0xD48),0,*(void **)(p+0xB8C),0,2,0,0x35CA,p+0xFA0);
    for(i=0;i<3;i++) {
        u32 window;
        *(void **)((u32)p+i*4+0xD50)=func_020450F0(1,9,i*5+6,0xF,2,1,1);
        func_02043B5C(func_02045770(*(void **)((int)((u32)p+i*4)+0xD50)),1);
        window=*(u32 *)((u32)p+i*4+0xD50);
        func_02045334((void *)window); func_02045374((void *)window); func_020409B4(func_02045730((void *)window));
    }
    *(void **)(p+0xD40)=func_020450F0(0,2,0x15,0x1B,2,0xD,1);
    func_02043B5C(func_02045770(*(void **)(p+0xD40)),0xF);
    *(void **)(p+0xDD0)=func_020450F0(0,2,0x13,0x1B,4,0xD,1);
    func_02043B5C(func_02045770(*(void **)(p+0xDD0)),0xF);
}
