/*
 * function: func_0220D328
 * address: 0x0220D328
 * packet: pkt_ov197_0220D328
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: larger follower filed as ov197_func_0220D358.c (parent cleared).
 * symbols:
 *   func_0220D884 0x0220D884 thumb ov197
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 */

typedef unsigned int u32;
extern int func_0220D884(char **);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
int func_0220D328(char *p)
{
    if (func_0220D884((char **)p) == 1) return 18;
    if ((func_020362DC() & 3) || func_02035C60() == 1)
        return *(unsigned char *)(p + 0x531);
    return 15;
}
