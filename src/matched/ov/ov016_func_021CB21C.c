/*
 * function: func_021CB21C
 * address:  0x021CB21C
 * packet:   pkt_ov016_021CB21C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_021D5580  0x021D5580  arm
 *   func_021D5CA8  0x021D5CA8  arm
 *   func_021BD138  0x021BD138  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E8C  0x021C0E8C  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021CD80C  0x021CD80C  arm
 */
extern int func_021D5580(int x);
extern void func_021D5CA8(int x);
extern void func_021BD138(void);
extern void func_021D6090(int a, int b);
extern void func_021C0E50(int a, int b);
extern void func_021C0E8C(int a, int b);
extern void func_021C0E40(void *p);
extern void func_021CD80C(void);

void func_021CB21C(void)
{
    if (func_021D5580(1) != 0)
        return;
    if (func_021D5580(0) != 0)
        return;
    func_021D5CA8(0);
    func_021BD138();
    func_021D6090(1, 1);
    func_021D6090(0, 0x15);
    func_021C0E50(0, 0);
    func_021C0E8C(0, 1);
    func_021C0E40(func_021CD80C);
}
