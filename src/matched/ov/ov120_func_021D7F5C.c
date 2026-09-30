/*
 * function: func_021D7F5C
 * address: 0x021D7F5C
 * packet: pkt_ov120_021D7F5C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02045CAC(void *,u16,int);
extern void *func_020450F0(u8,u8,u8,u8,u8,u8,u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,int);
extern void func_0201DD78(int,int,int);
extern void func_0201C7A4(void *,int,int,int,int);
extern void func_02045334(void *);
extern void func_02045374(void *);
void func_021D7F5C(char *p,u16 n)
{
    void *q;
    func_02045CAC(*(void **)(p+0xc),n,*(int *)(p+0x18));
    if(!*(void **)(p+0x94)) *(void **)(p+0x94)=func_020450F0(1,1,13,14,3,4,1);
    q=*(void **)(p+0x94);
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,14,0);
    func_0201C7A4(func_02045770(q),2,3,*(int *)(p+0x18),*(int *)(p+0x14));
    func_02045334(q);
    func_02045374(q);
}
