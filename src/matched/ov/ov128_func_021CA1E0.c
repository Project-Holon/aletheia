/*
 * function: func_021CA1E0
 * address: 0x021CA1E0
 * packet: pkt_ov128_021CA1E0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CA124 0x021CA124 thumb ov128
 * Extent ends with two bytes of zero alignment padding.
 */

typedef unsigned int   u32;
extern void func_021CA124(u32 a, u32 b);
int func_021CA1E0(char *p)  {
    switch(*(unsigned short *)(p+8))  {
        case 0: func_021CA124((u32)(*(void **)p),1);
        *(unsigned short *)(p+10)=0;
        (*(unsigned short *)(p+8))++;
        break;
        case 1: (*(unsigned short *)(p+10))++;
        if(*(unsigned short *)(p+10)==4)  {
            func_021CA124((u32)(*(void **)p),2);
            *(unsigned short *)(p+10)=0;
            (*(unsigned short *)(p+8))++;
        }
        break;
        case 2: (*(unsigned short *)(p+10))++;
        if(*(unsigned short *)(p+10)==4)  {
            func_021CA124((u32)(*(void **)p),1);
            *(unsigned short *)(p+10)=0;
            (*(unsigned short *)(p+8))++;
        }
        break;
        case 3: (*(unsigned short *)(p+10))++;
        if(*(unsigned short *)(p+10)==4)  {
            func_021CA124((u32)(*(void **)p),2);
            *(unsigned short *)(p+10)=0;
            (*(unsigned short *)(p+8))++;
        }
        break;
        case 4: (*(unsigned short *)(p+10))++;
        if(*(unsigned short *)(p+10)==4)  {
            *(unsigned short *)(p+8)=0;
            *(unsigned short *)(p+10)=0;
            return 0;
        }
        break;
    }
    return 1;
}
