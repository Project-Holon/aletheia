/*
 * function: func_021D7184
 * address: 0x021D7184
 * packet: pkt_ov116_021D7184
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
int func_021D7184(int *p) {
    int result=0;
    if(p[0]<0) {
        switch(p[0]) {
        case -2: result=16; break;
        case -6: result=17; break;
        case -1: result=15; break;
        case -7: result=19; break;
        case -4: result=18; break;
        case -3: result=20; break;
        default: result=22; break;
        }
    } else {
        switch(p[1]) {
        case 1: result=13; break;
        case 2: result=14; break;
        case 0:
            switch(p[3]) {
            case 1: result=23; break;
            case 2: result=23; break;
            case 0: if(*(u16 *)((char *)p+8)!=0) result=16; break;
            }
            break;
        }
    }
    return result;
}
