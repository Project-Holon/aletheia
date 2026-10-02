/*
 * function: func_021D7FD0
 * address: 0x021D7FD0
 * packet: pkt_ov120_021D7FD0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D80D2.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u32 func_0200856C(void *);
extern u32 func_02008570(void *);
extern u32 func_02008564(void *);
extern u32 func_02025C1C(u32,u32,u32);
extern u32 func_02025C30(u32,u32,u32);
extern void func_0201F048(void *,u32,u32);
extern void func_0201F094(void *,u32,u32,u32);
extern void func_02045CAC(void *,u16,void *);
extern void func_0201F250(void *,void *,void *);
extern void *func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,int);
extern void func_0201DD78(int,int,int);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02041B6C(int);
void func_021D7FD0(char *p,void *r)
{
    u32 a,b,c,d;
    void *q;
    a=func_0200856C(r);
    b=func_02008570(r);
    c=func_02025C1C(a,b,func_02008564(r));
    d=func_02025C30(a,b,func_02008564(r));
    if(a==c && b==d) {
        func_0201F048(*(void **)(p+16),0,func_0200856C(r));
        a=func_0200856C(r);
        func_0201F094(*(void **)(p+16),1,a,func_02008570(r));
    } else {
        func_0201F048(*(void **)(p+16),0,0);
        func_0201F094(*(void **)(p+16),1,0,0);
    }
    func_02045CAC(*(void **)(p+12),34,*(void **)(p+32));
    func_0201F250(*(void **)(p+16),*(void **)(p+24),*(void **)(p+32));
    if(!*(void **)(p+0x84)) *(void **)(p+0x84)=func_020450F0(1,1,15,30,5,11,1);
    q=*(void **)(p+0x84);
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,2,0);
    func_0201C7A4(func_02045770(q),5,5,*(void **)(p+24),*(void **)(p+20));
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}
