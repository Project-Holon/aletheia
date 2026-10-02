/*
 * function: func_0217945C
 * address: 0x0217945C
 * packet: pkt_ov014_0217945C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * return-chain: 0209028C result is passed to 0217814C.
 * symbols:
 *   g_021797A8 0x021797A8 data ov014 a4
 *   func_0209028C 0x0209028C arm
 *   func_0217814C 0x0217814C thumb ov014
 *   func_02178CDC 0x02178CDC thumb ov014
 *   func_02178138 0x02178138 thumb ov014
 */
typedef unsigned char u8;
extern u8 *g_021797A8;
extern int func_0209028C(void *);
extern void func_0217814C(int);
extern int func_02178CDC(void);
extern void func_02178138(int);
void func_0217945C(void)
{
    int error;
    if (*(int *)(g_021797A8 + 0x1E70) == 5) {
        error = func_0209028C(g_021797A8 + 0x1444);
        if (error != 0) func_0217814C(error);
    }
    if (func_02178CDC() == 0) func_02178138(10);
}
