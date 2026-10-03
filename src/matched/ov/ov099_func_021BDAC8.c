/*
 * function: func_021BDAC8
 * address: 0x021BDAC8
 * packet: pkt_ov099_021BDAC8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned byte stores materialize 0xa8 as movs, rather than a signed subtraction.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
typedef unsigned char u8;
extern void func_0201DD68(void);
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
int func_021BDAC8(char *p, int result)
{
    int v;
    func_0201DD68();
    v = func_021BA858(p);
    if (v == -1) return result;
    if (v == 0) *(u8 *)(p + 0x1353) = 0x44;
    else *(u8 *)(p + 0x1353) = 0xa8;
    func_021BA8EC(p);
    *(int *)(p + 0x1cc) = 0x8a;
    return result;
}
