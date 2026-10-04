/*
 * function: func_021DD9DC
 * address: 0x021DD9DC
 * packet: pkt_ov119_021DD9DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 */

struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void func_020452E8(struct Descriptor *d);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);

void func_021DD9DC(unsigned char *p)
{
    if(*(int *)(p+0x5bc)){func_020456F8((struct Descriptor *)(*(int *)(p+0x5bc)));func_020452E8((struct Descriptor *)(*(int *)(p+0x5bc)));*(int *)(p+0x5bc)=0;}if(*(int *)(p+0x5c0)){func_020456F8((struct Descriptor *)(*(int *)(p+0x5c0)));func_020452E8((struct Descriptor *)(*(int *)(p+0x5c0)));*(int *)(p+0x5c0)=0;}if(*(int *)(p+0x5d4)){func_020456F8((struct Descriptor *)(*(int *)(p+0x5d4)));func_020452E8((struct Descriptor *)(*(int *)(p+0x5d4)));*(int *)(p+0x5d4)=0;}if(*(int *)(p+0x5d8)){func_020456F8((struct Descriptor *)(*(int *)(p+0x5d8)));func_020452E8((struct Descriptor *)(*(int *)(p+0x5d8)));*(int *)(p+0x5d8)=0;}func_02041B6C(3);
}
