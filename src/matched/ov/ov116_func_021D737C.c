/*
 * function: func_021D737C
 * address: 0x021D737C
 * packet: pkt_ov116_021D737C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120B4 0x020120B4 thumb
 *   d_021D6338 0x021D6338 data ov115 a4
 *   ov115_id 0x73 data
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020120B4(void *, u32, void *, void *);
extern u32 d_021D6338[];
extern u8 ov115_id[];
void func_021D737C(u8 *p) {
    *(u32 *)(p+0x9b0)=*(u32 *)(p+0x1844);
    *(u32 *)(p+0x9b4)=0;
    *(u32 *)(p+0x9c8)=1;
    *(u32 *)(p+0x9b8)=1;
    *(u32 *)(p+0x9bc)=44;
    *(void **)(p+0x9c0)=p+0x9f4;
    func_020120B4(*(void **)(*(u8 **)p+4),(u32)ov115_id,d_021D6338,p+0x9b0);
}
