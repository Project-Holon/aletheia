/*
 * function: func_0220B7AC
 * address: 0x0220B7AC
 * packet: pkt_ov198_0220B7AC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220B6D0 0x0220B6D0 thumb ov198
 */
typedef unsigned char u8;
typedef struct Bits { unsigned char low:4; unsigned char mode:3; unsigned char active:1; } Bits;
extern void func_0220B6D0(u8 *,unsigned int,int,u8);
void func_0220B7AC(u8 *p)
{
    if (((Bits *)(p+0x1E9B))->active != 0) {
        switch (p[0x1E98]) {
        case 0:
            func_0220B6D0(p,p[0x1E9A],1,((Bits *)(p+0x1E9B))->mode);
            p[0x1E98]++;
            break;
        case 1:
            if (p[0x1E99]==4) {
                func_0220B6D0(p,p[0x1E9A],0,((Bits *)(p+0x1E9B))->mode);
                p[0x1E99]=0;
                p[0x1E98]++;
            } else p[0x1E99]++;
            break;
        case 2:
            if (p[0x1E99]==1) {
                p[0x1E99]=0;
                p[0x1E98]=0;
                ((Bits *)(p+0x1E9B))->active=0;
            } else p[0x1E99]++;
            break;
        }
    }
}
