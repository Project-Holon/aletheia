/*
 * function: func_021C6134
 * address: 0x021C6134
 * packet: pkt_ov093_021C6134
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 */
typedef unsigned char u8;
struct UtilWork;
extern void func_021D5FC0(struct UtilWork *, unsigned int);
extern u8 func_021D5440(u8 *);
extern void func_021CD4B0(void *, unsigned int, ...);
void func_021C6134(u8 *p, u8 *a, unsigned int n)
{
    func_021D5FC0((struct UtilWork *)a, n);
    func_021CD4B0(*(void **)(p + 12), 0x1b, func_021D5440(a), n);
}
