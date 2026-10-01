/*
 * function: func_021BA81C
 * address: 0x021BA81C
 * packet: pkt_ov223_021BA81C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB974 0x021BB974 thumb
 */
typedef unsigned char u8;
extern void func_021BB974(void *,unsigned,int);
void func_021BA81C(char *p,unsigned selected)
{
    u8 i;
    for(i=0;i<3;i++) {
        if(i==selected) func_021BB974(p,i,0); else func_021BB974(p,i,2);
        if(i==selected) {
            *(unsigned *)(p+i*148+224)=1;
            *(unsigned *)(p+i*148+228)=1;
        } else {
            *(unsigned *)(p+i*148+224)=2;
            *(unsigned *)(p+i*148+228)=1;
        }
    }
}
