/*
 * function: func_021CA320
 * address: 0x021CA320
 * packet: pkt_ov128_021CA320
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CA25C 0x021CA25C thumb ov128
 * Extent ends with two bytes of zero alignment padding.
 */

extern void func_021CA25C(int,int);
int func_021CA320(char *p)  {
    switch(*(unsigned short *)(p+8))  {
        case 0: func_021CA25C(*(short *)(p+4),1);
        *(unsigned short *)(p+10)=0;
        (*(unsigned short *)(p+8))++;
        break;
        case 1: (*(unsigned short *)(p+10))++;
        if(*(unsigned short *)(p+10)==4)  {
            func_021CA25C(*(short *)(p+4),2);
            *(unsigned short *)(p+10)=0;
            (*(unsigned short *)(p+8))++;
        }
        break;
        case 2: (*(unsigned short *)(p+10))++;
        if(*(unsigned short *)(p+10)==4)  {
            func_021CA25C(*(short *)(p+4),1);
            *(unsigned short *)(p+10)=0;
            (*(unsigned short *)(p+8))++;
        }
        break;
        case 3: (*(unsigned short *)(p+10))++;
        if(*(unsigned short *)(p+10)==4)  {
            func_021CA25C(*(short *)(p+4),2);
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
