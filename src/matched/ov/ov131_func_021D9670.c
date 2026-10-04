/*
 * function: func_021D9670
 * address: 0x021D9670
 * packet: pkt_ov131_021D9670
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02041570 0x02041570 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040AE0 0x02040AE0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204A8D4(u32 i);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_02041570(int,u16);
extern void func_02041B6C(u32 bit);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
void func_021D9670(u8 *a,u8 *p)
{
    u8 *q;
    if(*(int *)(p+4)==1) {
        func_0204A8D4((u32)(*(void **)(p+0x18)));
        func_0204B3B4(*(void **)(p+0x1c));
        func_02041570(4,0);
        func_02041B6C(4);
        *(int *)(p+4)=0;
        q=*(u8 **)(p+0x30);
        func_02040AE0(6,q+0xc,*(u32 *)(q+8));
        func_02041B6C(6);
    }
}
