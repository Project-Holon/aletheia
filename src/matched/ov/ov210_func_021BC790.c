/*
 * function: func_021BC790
 * address: 0x021BC790
 * packet: pkt_ov210_021BC790
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 */
struct PalAnmSlot;
extern void *func_02021518(unsigned);
extern void func_0202155C(struct PalAnmSlot *,unsigned,unsigned,unsigned);
extern void func_020216D4(unsigned,int,int,int);
void func_021BC790(char *p)
{
    *(void **)(p+12)=func_02021518(123);
    func_0202155C(*(struct PalAnmSlot **)(p+12),0,512,123);
    func_0202155C(*(struct PalAnmSlot **)(p+12),1,512,123);
    func_0202155C(*(struct PalAnmSlot **)(p+12),2,512,123);
    func_0202155C(*(struct PalAnmSlot **)(p+12),3,512,123);
    func_020216D4(*(unsigned *)(p+12),0,0,512);
    func_020216D4(*(unsigned *)(p+12),1,0,512);
    func_020216D4(*(unsigned *)(p+12),2,0,512);
    func_020216D4(*(unsigned *)(p+12),3,0,512);
}
