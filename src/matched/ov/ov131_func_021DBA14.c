/*
 * function: func_021DBA14
 * address: 0x021DBA14
 * packet: pkt_ov131_021DBA14
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DC2B8 0x021DC2B8 data a1
 */
typedef unsigned char u8;
extern const u8 d_021DC2B8[][2];
void func_021DBA14(u8 *a,u8 *b) {
    if (*a<5) {
        b[0]=d_021DC2B8[*a][1]*8;
        b[1]=b[0]+32;
        b[2]=d_021DC2B8[*a][0]*8;
        b[3]=b[2]+136;
    } else { b[0]=0;b[1]=0;b[2]=0;b[3]=0; }
}
