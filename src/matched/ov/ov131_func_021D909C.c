/*
 * function: func_021D909C
 * address: 0x021D909C
 * packet: pkt_ov131_021D909C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
void func_021D909C(u8 *a,u8 *p)
{
    *(int *)p=0;
    if(*(void **)(p+0x20)!=0) {
        func_020452E8(*(void **)(p+0x20));
        *(void **)(p+0x20)=0;
    }
    if(*(void **)(p+0x24)!=0) {
        func_020452E8(*(void **)(p+0x24));
        *(void **)(p+0x24)=0;
    }
}
