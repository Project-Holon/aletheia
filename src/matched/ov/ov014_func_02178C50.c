/*
 * function: func_02178C50
 * address: 0x02178C50
 * packet: pkt_ov014_02178C50
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02178C74 0x02178C74 thumb ov014
 *   WM_EndMP 0x0208FDEC arm
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217814C 0x0217814C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02178C74(void *);
extern int WM_EndMP(void (*)(void *));
extern void func_02178138(int);
extern void func_0217814C(int);
int func_02178C50(void)
{
    int result;
    func_02178138(3);
    result = WM_EndMP(func_02178C74);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}
