/*
 * function: func_021D9138
 * address: 0x021D9138
 * packet: pkt_ov121_021D9138
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021DAB50 0x021DAB50 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021DAB50(int,void *,u16,int,void *,void *);
void func_021D9138(u8 *p)
{
    switch(*(int *)(p+32)) {
    case 0: *(int *)(p+32)=1; return;
    case 1:
        *(u16 *)(p+48)=(*(unsigned *)(p+24)*32767u)/60u;
        func_021DAB50(15,p+50,*(u16 *)(p+48),0,p+146,p+114);
        func_021DAB50(31,p+82,*(u16 *)(p+48),0,p+146,p+114);
        if((*(unsigned *)(p+24))++ >60) {
            *(unsigned *)(p+24)=0;
            *(int *)(p+32)=2;
            return;
        }
        break;
    case 2: *(int *)(p+8)=1; break;
    }
}
