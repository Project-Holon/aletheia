/*
 * function: func_02184134
 * address: 0x02184134
 * packet: pkt_ov022_02184134
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Original r0 return from 020399A8 flows into unused parameter 0 of
 * 0203D1E8; its r1 argument is literal payload 1. No implicit arguments.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_0203D1E8(u32, void *);
void func_02184134(u8 *p)
{
    func_0203D1E8((u32)func_020399A8(), (void *)1);
    p[9] = 0;
}
