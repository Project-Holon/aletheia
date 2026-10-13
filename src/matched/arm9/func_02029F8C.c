/*
 * function: RINGTONE_SYS_TickRing
 * address:  0x02029F8C
 * packet:   pkt_02029F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_0200616C  0x0200616C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern void func_020061F8(int a);
extern void func_0200616C(void *arg, int i);

int RINGTONE_SYS_TickRing(u16 *p)
{
    if (p[2] != 0) {
        p[2] = p[2] - 1;
    }
    if (p[2] == 0) {
        if (GFL_USE_IsSeSlotBusy(4) == 1) {
            func_020061F8(4);
        }
        return 0;
    }
    if (GFL_USE_IsSeSlotBusy(4) == 0) {
        func_0200616C((void *)0x662, 4);
    }
    return 1;
}
