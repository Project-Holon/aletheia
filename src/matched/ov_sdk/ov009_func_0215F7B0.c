/*
 * function: SOC_GetHostID
 * address:  0x0215f7b0
 * packet:   pkt_ov009_0215F7B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_GetHostID (soc.o)
 *
 * symbols:
 *   SOCL_GetHostID   0x0215ef48 arm
 */

extern unsigned long SOCL_GetHostID(void);

long SOC_GetHostID(void)
{
    unsigned long hostid = SOCL_GetHostID();

    return (long)(((hostid >> 24) & 0xff) | ((hostid >> 8) & 0xff00)
                | ((hostid << 8) & 0xff0000) | ((hostid << 24) & 0xff000000));
}
