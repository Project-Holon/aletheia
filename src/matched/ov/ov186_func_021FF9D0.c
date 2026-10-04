/*
 * packet: pkt_ov186_021FF9D0
 * function: func_021FF9D0
 * address: 0x021FF9D0
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D68EC 0x021D68EC thumb ov125
 *   func_02034714 0x02034714 arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   func_021FF8E4 0x021FF8E4 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 */
#include "../include/Obj08337.h"
extern int func_021D68EC(char *, int, unsigned, int, unsigned char);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021FFB68(char *, int);
extern void func_021FF8E4(void *, int, int);
extern const char d_02200D98[];
void func_021FF9D0(char *p, int unused, char *q)
{
    if (!func_021D68EC(q, ((struct Obj08337 *)q)->f5B0, ((struct Obj08337 *)q)->f5B4, ((struct Obj08337 *)q)->f5B2, ((struct Obj08337 *)q)->f5B3))
        func_02034714(d_02200D98, 0, d_02200D98);
    func_021FFB68(p, (int)func_021FF8E4);
}
