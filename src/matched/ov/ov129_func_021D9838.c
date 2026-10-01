/*
 * function: func_021D9838
 * address: 0x021D9838
 * packet: pkt_ov129_021D9838
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_020A1448 0x020A1448 data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 */

typedef struct  {
    unsigned words[7];
}
Config;
extern const Config d_020A1448;
extern void func_0204A48C(const Config *,unsigned,unsigned);
extern void func_020434DC(unsigned,unsigned);
extern void *func_0204B100(int,unsigned char,unsigned);
extern void func_0204B270(void *);
void func_021D9838(char *p,unsigned a)  {
    Config c = d_020A1448;
    ((unsigned char *)&c)[8] = 16;
    ((unsigned char *)&c)[9] = 112;
    func_0204A48C(&c,a,50);
    func_020434DC(16,1);
    *(void **)(p+0x25c)=func_0204B100(64,0,50);
    func_0204B270(*(void **)(p+0x25c));
}
