/*
 * unit: yes
 * function: func_021E79C8, func_021E7A04
 * address: 0x021E79C8
 * packet: pkt_ov170_021E79C8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E070C 0x021E070C thumb ov170
 *   func_021E8FE0 0x021E8FE0 thumb ov170
 *   func_021E95CC 0x021E95CC thumb ov170
 */
extern void func_021EF57C(int mgr);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(unsigned char *p);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E070C(unsigned char *p);
extern int func_021E8FE0(unsigned char *p, int v);
extern int func_021E95CC(unsigned char *p, unsigned char v);
#define WORK(p) (*(char **)((p) + 0x2C))
void func_021E79C8(unsigned char *p)
{
    func_021EF57C(*(int *)(WORK(p) + 0x74));
    func_021ED6E4((char **)p, 0);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C(p);
    func_021E8FC0(p, func_021E070C, func_021E8FE0(p, 0x4B));
}
int func_021E7A04(unsigned char *p)
{
    return func_021E95CC(p, 0);
}
