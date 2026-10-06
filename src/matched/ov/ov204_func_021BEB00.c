/*
 * function: func_021BEB00
 * address: 0x021BEB00
 * packet: pkt_ov204_021BEB00
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment at 0x021BEBEA.
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
int func_021BEB00(void *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02041300(2,0,0,7,64,1,0);
        func_02041300(2,0,0,16,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        func_02041300(2,0,0,8,64,1,0);
        func_02041300(2,0,0,15,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        func_02041300(2,0,0,6,64,1,0);
        func_02041300(2,0,0,14,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        func_02041300(2,0,0,5,64,1,0);
        func_02041300(2,0,0,13,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        func_02040588(2,0);
        *q=0;
        return 1;
    }
    return 0;
}
