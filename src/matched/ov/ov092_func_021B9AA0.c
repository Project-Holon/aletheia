/*
 * function: func_021B9AA0
 * address: 0x021B9AA0
 * packet: pkt_ov092_021B9AA0
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * levers: loop index declared before tier puts j in r2 and tier in r3; omit contested table hint.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021B9D44 0x021B9D44 data a1
 *   d_021B9D6E 0x021B9D6E data ov092 a2
 *   d_021B9D58 0x021B9D58 data ov092 a2
 *   d_021B9D4D 0x021B9D4D data ov092 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02017E40(void *,u32,u32);
extern u32 func_020056EC(u32);
extern const u8 d_021B9D44[];
extern const u16 d_021B9D6E[];
extern const u16 d_021B9D58[];
extern const u8 d_021B9D4D[];
void func_021B9AA0(void *party)
{
    int i;
    void *mon;
    u16 species,item;
    int ability;
    int random;
    int j;
    u8 tier;
    int threshold;
    int index;
    for (i=0;i<(int)func_0201AA18(party);i++) {
        mon = func_0201AB28(party,i);
        species = func_02017E1C(mon,0xab,0);
        item = func_02017E1C(mon,6,0);
        ability = (u8)func_02017E1C(mon,0xa,0);
        if (ability == 0x35 && species != 0 && species != 0x28a && item == 0 && func_020056EC(10) == 0) {
            random = func_020056EC(100);
            tier = (func_02017E1C(mon,0x9e,0)-1)/10u;
            if (tier >= 10) tier=9;
            for (j=0;j<9;j++) {
                if (d_021B9D44[j] > random) {
                    func_02017E40(mon,6,d_021B9D6E[tier+j]);
                    break;
                } else if (random >= 98 && random <= 99) {
                    func_02017E40(mon,6,d_021B9D58[tier+(99-random)]);
                    break;
                }
            }
        }
        if (ability == 0x76 && species != 0 && species != 0x28a && item == 0) {
            index=0;
            threshold=10;
            ability=(u8)func_02017E1C(mon,0x9e,0);
            while (threshold < ability) {
                threshold+=10;
                index++;
            }
            if (func_020056EC(100) < d_021B9D4D[index]) func_02017E40(mon,6,0x5e);
        }
    }
}
