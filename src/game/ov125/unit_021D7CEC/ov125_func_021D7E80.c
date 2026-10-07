/*
 * function: func_021D7E80
 * address: 0x021D7E80
 * packet: pkt_ov125_021D7E80
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: final halfword swap ORs the right-shifted half before the left-shifted half; reversing them left two byte mismatches.
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021D9F80 0x021D9F80 data a4
 *   d_021DA258 0x021DA258 data a4
 *   func_0215F428 0x0215F428 arm ov009
 *   func_021D7E20 0x021D7E20 arm ov125
 *   func_0215C910 0x0215C910 arm ov009
 *   func_021D8C14 0x021D8C14 arm ov125
 *   func_0215FC80 0x0215FC80 arm ov009
 */

#include "../../../matched/include/G_Clear.h"

typedef unsigned int u32;
typedef unsigned char u8;
extern struct Clear d_021D9E40;
extern char d_021D9F80[];
extern u8 d_021DA258[];
extern int func_0215F428(int, int, int);
extern int func_021D7E20(const char *, char *);
extern unsigned long func_0215C910(char *name);
extern void func_021D8C14(const char *, u8 *);
extern int func_0215FC80(int s, void *con);
int func_021D7E80(void)
{
    char out[16];
    u32 value;
    ((u32 *)&d_021D9E40)[0x26c/4] = func_0215F428(2, 1, 0);
    if (((u32 *)&d_021D9E40)[0x26c/4] == -1u) {
        ((u32 *)&d_021D9E40)[0x250/4] = 3;
        return 0;
    }
    if (!func_021D7E20(d_021D9F80, out)) {
        ((u32 *)&d_021D9E40)[0x250/4] = 5;
        return 0;
    }
    value = func_0215C910(out);
    value = ((value >> 8) & 0x00ff00ff) | ((value << 8) & 0xff00ff00);
    ((u32 *)&d_021D9E40)[0x264/4] = (value >> 16) | (value << 16);
    func_021D8C14(d_021D9F80, d_021DA258);
    if (func_0215FC80(((u32 *)&d_021D9E40)[0x26c/4], d_021DA258) < 0) {
        ((u32 *)&d_021D9E40)[0x250/4] = 15;
        return 0;
    }
    return 1;
}
