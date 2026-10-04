/*
 * function: func_021BFED0
 * address: 0x021BFED0
 * packet: pkt_ov110_021BFED0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(void *,s16,s16,u16,u16,u8);
void func_021BFED0(u8 *p,int amount) {
    int start,end;
    if(amount>0) {
        start=(u8)(*(unsigned *)(p+0x94)+192);
        end=(u8)(start+24*amount);
    } else {
        end=*(unsigned *)(p+0x94);
        start=(u8)(end+24*amount);
    }
    if(start<end) {
        func_02043AF4(func_02045770((struct Descriptor *)*(unsigned *)(p+12)),0,start,208,end-start,0);
    } else {
        func_02043AF4(func_02045770((struct Descriptor *)*(unsigned *)(p+12)),0,start,208,256-start,0);
        func_02043AF4(func_02045770((struct Descriptor *)*(unsigned *)(p+12)),0,0,208,end,0);
    }
}
