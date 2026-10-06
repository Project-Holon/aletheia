/*
 * function: func_0216D244
 * address: 0x0216D244
 * packet: pkt_ov010_0216D244
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D230 0x0216D230 thumb ov010
 *   func_0216DF64 0x0216DF64 thumb ov010
 *   func_0216D568 0x0216D568 thumb ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0216D230(int a0);
extern void func_0216DF64(u8 *p, u32 v);
extern void *func_0216D568(void *p, u32 v);
void func_0216D244(u32 v, u8 *p)
{
    func_0216D230((int)p);
    func_0216DF64(p, v);
    func_0216D568(p, 0x1820);
}
