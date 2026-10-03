/*
 * function: func_021DF3E4
 * address: 0x021DF3E4
 * packet: pkt_ov119_021DF3E4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBBD0 0x021DBBD0 thumb ov119
 */
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_021E12AC(char *p);
extern void func_021D8E84(void *, int);
extern void func_021DBBD0(char *p);
void func_021DF3E4(void *p)
{
    func_020399A8();
    if (func_021E12AC(p)) {
        func_021D8E84(p, (int)func_021DBBD0);
    }
}
