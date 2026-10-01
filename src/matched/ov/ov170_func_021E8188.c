/*
 * function: func_021E8188
 * address: 0x021E8188
 * packet: pkt_ov170_021E8188
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE7C8 0x021DE7C8 thumb ov170
 *   func_021EC994 0x021EC994 thumb ov170
 *   func_021ECA24 0x021ECA24 thumb ov170
 *   func_021DE7B4 0x021DE7B4 thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 */
extern void func_021DE7C8(unsigned char *p);
extern int func_021EC994(char *p);
extern void func_021ECA24(char *p);
extern void func_021DE7B4(unsigned char *p);
extern int func_021E8F50(unsigned char *p, int v);
#define WORK(p) (*(char **)((p) + 0x2C))
#define SLOT(p) (*(char **)(WORK(p) + 0xA190))
int func_021E8188(unsigned char *p)
{
    func_021DE7C8(p);
    if (func_021EC994(SLOT(p)) == 0) {
        if (((unsigned char *)SLOT(p))[6] != 0)
            return func_021E8F50(p, 0x5C);
        func_021ECA24(SLOT(p));
        func_021DE7B4(p);
        return func_021E8F50(p, 0x5B);
    }
    return 0x5A;
}
