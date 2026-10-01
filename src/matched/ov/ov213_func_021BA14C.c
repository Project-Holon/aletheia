/*
 * function: func_021BA14C
 * address: 0x021BA14C
 * packet: pkt_ov213_021BA14C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA034 0x021BA034 thumb ov213
 */
extern void func_021BA034(char *,unsigned);
void func_021BA14C(char *p,unsigned limit)
{
    if(*(unsigned char *)(p+0x28)) {
        switch(*(unsigned char *)(p+8)) {
        case 0:break;
        case 1:limit=12;break;
        case 3:
            if(*(unsigned char *)(p+9)==0 || *(unsigned char *)(p+9)==2) limit=15;
            else if(*(unsigned char *)(p+9)==1 || *(unsigned char *)(p+9)==3) limit=19;
            break;
        case 2:limit=8;break;
        case 4:
            if(*(unsigned char *)(p+9)==0 || *(unsigned char *)(p+9)==2) limit=11;
            else if(*(unsigned char *)(p+9)==1 || *(unsigned char *)(p+9)==3) limit=15;
            break;
        }
        if(*(unsigned *)(p+0x24)>=limit) func_021BA034(p,limit);
        (*(unsigned *)(p+0x24))++;
    }
}
