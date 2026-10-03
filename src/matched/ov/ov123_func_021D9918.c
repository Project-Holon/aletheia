/*
 * function: func_021D9918
 * address: 0x021D9918
 * packet: pkt_ov123_021D9918
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return.
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned int   u32;
struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_020452E8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
void func_021D9918(char *p)
{
    if (*(void **)(p+0x40)) {
        func_0201F7A8(*(void **)(p+0x40),2);
        func_020456F8(*(void **)(p+0x40));
        func_0201F7A8(*(void **)(p+0x44),2);
        func_020456F8(*(void **)(p+0x44));
        func_020452E8(*(void **)(p+0x40));
        func_020452E8(*(void **)(p+0x44));
        func_02041B6C(5);
        *(void **)(p+0x40)=0;
        *(void **)(p+0x44)=0;
    }
}
