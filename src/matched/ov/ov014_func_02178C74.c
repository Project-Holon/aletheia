/*
 * function: func_02178C74
 * address: 0x02178C74
 * packet: pkt_ov014_02178C74
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217814C 0x0217814C thumb ov014
 *   func_02179498 0x02179498 thumb ov014
 *   func_02178C98 0x02178C98 thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02178138(int);
extern void func_0217814C(int);
extern void func_02179498(void);
extern int func_02178C98(void);
void func_02178C74(void *arg)
{
    int result = ((u16 *)arg)[1];
    if (result != 0) {
        func_0217814C(result);
        func_02179498();
        return;
    }
    if (func_02178C98() == 0)
        func_02178138(9);
}
