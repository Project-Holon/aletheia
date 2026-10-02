/*
 * function: func_021D9844
 * address: 0x021D9844
 * packet: pkt_ov123_021D9844
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D97CC 0x021D97CC thumb ov123
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021D97CC(int,void *);
extern void *func_020450F0(int,int,u8,int,u8,u8,u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,int);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void func_0201F73C(void *,int,u16,int);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02045CAC(void *,int,void *);
extern void func_02041B6C(int);
void func_021D9844(char *p,int n)
{
    void *q;
    func_021D97CC(n,*(void **)(p+0x2c));
    if (!*(void **)(p+0x40)) *(void **)(p+0x40)=func_020450F0(1,1,8,30,4,11,1);
    q=*(void **)(p+0x40);
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,*(void **)(p+0x2c),*(void **)(p+0x28));
    func_0201F73C(q,1,*(int *)p,12);
    func_02045334(q);
    func_02045374(q);
    if (!*(void **)(p+0x44)) *(void **)(p+0x44)=func_020450F0(1,3,3,22,2,11,1);
    q=*(void **)(p+0x44);
    func_0201DD78(1,2,0);
    func_02045CAC(*(void **)(p+0x20),10,*(void **)(p+0x2c));
    func_0201C7A4(func_02045770(q),0,0,*(void **)(p+0x2c),*(void **)(p+0x28));
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}
