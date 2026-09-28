/*
 * function: SOC_Socket
 * address:  0x0215f428
 * packet:   pkt_ov009_0215F428
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Socket (soc.o)
 *
 * note:     DWARF declares one parameter (type), but the body reads r1, so
 *           the object was compiled from a two-parameter prototype whose
 *           first argument is unused; the C below spells that first slot.
 *
 * symbols:
 *   SOCL_CreateSocket    0x0215d070 arm
 *   SOCLSocketParamTCP   0x021a1cfc data
 *   SOCLSocketParamUDP   0x021a1ce4 data
 */

struct SOCLSocketParam {
    unsigned long w[16];
};

extern int SOCL_CreateSocket(struct SOCLSocketParam *param);
extern struct SOCLSocketParam SOCLSocketParamTCP;
extern struct SOCLSocketParam SOCLSocketParamUDP;

int SOC_Socket(int unused, int type)
{
    if (type == 1)
        return SOCL_CreateSocket(&SOCLSocketParamTCP);
    return SOCL_CreateSocket(&SOCLSocketParamUDP);
}
