/*
 * function: func_02163130
 * address: 0x02163130
 * packet: pkt_ov010_02163130
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D57C 0x0216D57C thumb ov010
 *   func_021641C8 0x021641C8 thumb ov010
 *   func_02163230 0x02163230 thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_0216D57C(void *p, u32 v);
extern void func_021641C8(void *a);
extern void func_02163230(char *p);
extern void func_0216D570(char *p, u32 v);
void func_02163130(char *p)
{
    if (func_0216D57C(p, 0x20)) {
        func_021641C8(p);
        func_02163230(p);
    }
    func_0216D570(p, 0xa0);
}
