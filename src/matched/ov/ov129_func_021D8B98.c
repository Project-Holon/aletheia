/*
 * function: func_021D8B98
 * address: 0x021D8B98
 * packet: pkt_ov129_021D8B98
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 */

extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern unsigned func_020221A4(void);
int func_021D8B98(char *p)  {
    switch(*(int *)(p+0x234))  {
        case 0: func_0202208C(0,0,0,0,6,1,50);
        *(int *)(p+0x234)+=1;
        break;
        case 1: if(func_020221A4()==1) *(int *)(p+0x234)+=1;
        break;
        default: return 1;
    }
    return 0;
}
