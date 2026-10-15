/*
 * function: func_0220D7F0
 * address: 0x0220D7F0
 * packet: pkt_ov197_0220D7F0
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2 zero alignment bytes at 0x0220D846.
 * symbols:
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 */
extern void BG_SYS_ResetSlot(unsigned int, unsigned int, unsigned int);
void func_0220D7F0(void *unused, int mode)
{
    switch (mode) {
    case 0:
        BG_SYS_ResetSlot(6, 0, 0);
        BG_SYS_ResetSlot(6, 3, 0);
        break;
    case 1:
        BG_SYS_ResetSlot(6, 0, 256);
        BG_SYS_ResetSlot(6, 3, 0);
        break;
    case 2:
        BG_SYS_ResetSlot(6, 0, 0);
        BG_SYS_ResetSlot(6, 3, 256);
        break;
    }
}
