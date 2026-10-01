/*
 * function: func_021D8C14
 * address: 0x021D8C14
 * packet: pkt_ov125_021D8C14
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_02082D44 0x02082D44 arm
 *   func_0208CC78 0x0208CC78 arm
 *   func_021D7C7C 0x021D7C7C arm ov125
 *   func_0208CADC 0x0208CADC arm
 *   d_021DAA88 0x021DAA88 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *d_021DAA88;
extern void func_02082D44(const void *, void *, u32);
extern u32 func_0208CC78(const char *);
extern char *func_021D7C7C(u32);
extern void func_0208CADC(char *, const char *);
void func_021D8C14(const char *s, u8 *p)
{
    func_02082D44(d_021DAA88, p, 0x830);
    if (s) {
        *(char **)(p + 0x800) = func_021D7C7C(func_0208CC78(s) + 1);
        func_0208CADC(*(char **)(p + 0x800), s);
    }
}
