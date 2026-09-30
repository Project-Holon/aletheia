/*
 * function: func_021D6A5C
 * address: 0x021D6A5C
 * packet: pkt_ov116_021D6A5C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025C1C 0x02025C1C thumb
 *   func_02025C30 0x02025C30 thumb
 *   func_02025CB0 0x02025CB0 thumb
 *   func_02025C88 0x02025C88 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02025C1C(u32,u32,u32);
extern u32 func_02025C30(u32,u32,u32);
extern u32 func_02025CB0(u32);
extern u32 func_02025C88(u32);
void func_021D6A5C(u8 *p) {
    int i,j;
    u8 *q,*r;
    q=p+14;
    r=p+0x69e;
    for(i=0;i<7;i++) {
        j=i*240;
        q[j+0xc6]=func_02025C1C(q[j+0xc6],q[j+0xc7],q[j+0xc5]);
        q[j+0xc7]=func_02025C30(q[j+0xc6],q[j+0xc7],q[j+0xc5]);
        q[j+0xd5]=func_02025C88(func_02025CB0(q[j+0xd5]));
    }
    for(i=0;i<30;i++) {
        q=r+i*34;
        q[18]=func_02025C1C(q[18],q[19],q[17]);
        q[19]=func_02025C30(q[18],q[19],q[17]);
    }
}
