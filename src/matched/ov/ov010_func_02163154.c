/*
 * function: func_02163154
 * address: 0x02163154
 * packet: pkt_ov010_02163154
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment at 0x02163186 before func_02163188.
 * symbols:
 *   func_0216D57C 0x0216D57C thumb ov010
 *   func_021632F0 0x021632F0 thumb ov010
 *   func_02163288 0x02163288 thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_0216D57C(void *p, u32 v);
extern void func_021632F0(char *p);
extern void func_02163288(char *p);
extern void func_0216D570(char *p, u32 v);
void func_02163154(char *p)
{
    if (func_0216D57C(p, 0x80)) func_021632F0(p);
    else if (func_0216D57C(p, 0x20)) func_02163288(p);
    func_0216D570(p, 0xa0);
}
