/*
 * function: func_02163188
 * address: 0x02163188
 * packet: pkt_ov010_02163188
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment at 0x021631BE before func_021631C0.
 * symbols:
 *   func_0216D57C 0x0216D57C thumb ov010
 *   func_021633A8 0x021633A8 thumb ov010
 *   func_02163340 0x02163340 thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_0216D57C(char *p, u32 v);
extern void func_021633A8(char *p);
extern void func_02163340(char *p);
extern void func_0216D570(char *p, u32 v);
void func_02163188(char *p)
{
    if (func_0216D57C(p, 0x100)) func_021633A8(p);
    else if (func_0216D57C(p, 0x40)) func_02163340(p);
    func_0216D570(p, 0x140);
}
