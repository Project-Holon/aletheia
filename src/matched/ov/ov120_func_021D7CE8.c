/*
 * function: func_021D7CE8
 * address: 0x021D7CE8
 * packet: pkt_ov120_021D7CE8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D7D2E.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 */
typedef unsigned short u16;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(void *,u16,int);
extern void func_0201C7A4(void *,int,int,int,int);
extern void func_02045334(struct Descriptor *d);
void func_021D7CE8(char *p,u16 n,int i)
{
    void *q=*(void **)(p+0x38+4*i);
    if(q) {
        func_02043B5C(func_02045770(q),0);
        func_02045CAC(*(void **)(p+0xc),n,*(int *)(p+0x18));
        func_0201C7A4(func_02045770(q),2,2,*(int *)(p+0x18),*(int *)(p+0x14));
        func_02045334(q);
    }
}
