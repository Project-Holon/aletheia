/*
 * function: func_021C9D88
 * address: 0x021C9D88
 * packet: pkt_ov128_021C9D88
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021C9E0E before next label 021C9E10.
 * lever: writing the reloaded signed byte on the left of == fixes both cmp operands.
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009864 0x02009864 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
struct BigObj;
extern u32 func_0201283C(const struct BigObj *p);
extern int func_02009864(u32,u32,u32);
int func_021C9D88(u8 *p,int direction)
{
    int index;
    u32 data;
    u32 count;
    data=func_0201283C(*(void **)(p+4));
    index=*(s8 *)(p+11);
    if(direction==0) {
        for(count=0;count<*(u32 *)(p+16)-1;count++) {
            index--;
            if(index<0) index+=*(u32 *)(p+16);
            if(*(s8 *)(p+11)==index) goto fail;
            if(func_02009864(data,p[index+24],9)!=2) return 1;
        }
    } else {
        for(count=0;count<*(u32 *)(p+16)-1;count++) {
            index=(u32)(index+1)%*(u32 *)(p+16);
            if(*(s8 *)(p+11)==index) goto fail;
            if(func_02009864(data,p[index+24],9)!=2) return 1;
        }
    }
fail:
    return 0;
}
