/*
 * function: func_021D5ED8
 * address: 0x021D5ED8
 * packet: pkt_ov115_021D5ED8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045874 0x02045874 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021D5FC4 0x021D5FC4 thumb ov115
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern void func_02045CAC(void *,u32,void *);
extern void *func_02045874(void *,u32);
extern void func_0201F250(void *,void *,void *);
extern u32 func_021D5FC4(u32);
extern void *func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_0201F73C(void *,u32,u16,u32);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02041B6C(u32);
extern void func_02045808(void *);
void func_021D5ED8(u8 *p,u32 n) {
    void *w;
    void *s;
    func_02045CAC(*(void **)(p+0x1c),n,*(void **)(p+0x28));
    s=func_02045874(*(void **)(p+0x28),*(u16 *)(p+0x4c));
    func_0201F250(*(void **)(p+0x20),*(void **)(p+0x28),s);
    if (*(void **)(p+0x30)==0) *(void **)(p+0x30)=func_020450F0(func_021D5FC4(*(u32 *)(p+0x50)),1,1,30,16,11,1);
    w=*(void **)(p+0x30);
    func_02043B5C(func_02045770(w),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(w),0,0,*(void **)(p+0x28),*(void **)(p+0x24));
    func_0201F73C(w,1,*(u32 *)(p+4),12);
    func_02045334(w);
    func_02045374(w);
    func_02041B6C(func_021D5FC4(*(u32 *)(p+0x50)));
    func_02045808(s);
}
