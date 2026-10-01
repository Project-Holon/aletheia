/*
 * function: func_021CA014
 * address: 0x021CA014
 * packet: pkt_ov128_021CA014
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initialize value before *ok; multiply and add the u64 digit separately;
 *        cast the u16 counter to int for its bound, and share failure via done.
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_02045A90 0x02045A90 arm
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern u16 func_02045A98(void *);
extern u16 *func_02045A90(void *);
u64 func_021CA014(void *p,int *ok)
{
    u16 end=func_02045A98(p);
    u16 *text=func_02045A90(p);
    u64 value;
    u16 i;
    u16 digit;
    value=0;
    *ok=0;
    i=0;
    while(text[i]!=end) {
        if((int)i>=18) goto done;
        digit=(u16)(text[i]-0x30);
        if(digit>=10) {
            digit=(u16)(text[i]-0xff10);
            if(digit>=10) goto done;
        }
        value*=10;
        value+=(u64)digit;
        i++;
    }
    *ok=1;
done:
    return value;
}
