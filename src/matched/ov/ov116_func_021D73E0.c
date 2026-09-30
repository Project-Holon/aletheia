/*
 * function: func_021D73E0
 * address: 0x021D73E0
 * packet: pkt_ov116_021D73E0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120B4 0x020120B4 thumb
 *   d_021D654C 0x021D654C data ov115 a4
 *   ov115_id 0x73 data
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020120B4(void *, u32, void *, void *);
extern u32 d_021D654C[];
extern u8 ov115_id[];
void func_021D73E0(u8 *p) {
    *(u32 *)(p+0x9d8)=*(u32 *)(p+0x1844);
    *(u32 *)(p+0x9dc)=0;
    *(u32 *)(p+0x9e0)=1;
    *(u32 *)(p+0x9e4)=1;
    func_020120B4(*(void **)(*(u8 **)p+4),(u32)ov115_id,d_021D654C,p+0x9d8);
}
