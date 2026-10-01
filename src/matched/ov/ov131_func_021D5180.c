/*
 * function: func_021D5180
 * address: 0x021D5180
 * packet: pkt_ov131_021D5180
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D89FC 0x021D89FC thumb ov131
 *   func_021D9BD4 0x021D9BD4 thumb ov131
 *   func_021D694C 0x021D694C thumb ov131
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
extern void func_021D89FC(void *,void *);
extern void func_021D9BD4(void *,void *);
extern void func_021D694C(void *,void *);
extern void func_0204B3B4(void *);
void func_021D5180(char *p)
{
    u8 i;
    func_021D89FC(p,*(void **)(p+0x94));
    func_021D9BD4(p,*(void **)(p+0x90));
    func_021D694C(p,*(void **)(p+0x88));
    for (i=0;i<8;i++) func_0204B3B4(*(void **)(p+i*4+0x178));
    for (i=0;i<2;i++) func_0204B3B4(*(void **)(p+i*4+0x198));
}
