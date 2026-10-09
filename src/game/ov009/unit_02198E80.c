/*
 * file:     unit_02198E80.c
 * function: func_02198E80
 * address:  0x02198E80
 * packet:   pkt_ov009_02198E80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DetermineNatType (libdwcgsnatneg.TWL.HYB.a natify.o)
 *
 * symbols:
 *   func_02091588  0x02091588  arm
 *
 * abs is declared __attribute__((const)): the object keeps ipRestricted and
 * portRestricted in registers across every abs call, which a plain extern
 * prototype does not allow.
 */

typedef struct _AddressMapping {
    unsigned int privateIp;
    unsigned short privatePort;
    unsigned int publicIp;
    unsigned short publicPort;
} AddressMapping;

typedef enum { no_nat, firewall_only, full_cone, restricted_cone, port_restricted_cone, symmetric, unknown } NatType;
typedef enum { promiscuous, not_promiscuous, port_promiscuous, ip_promiscuous, promiscuity_not_applicable } NatPromiscuity;
typedef enum { unrecognized, private_as_public, consistent_port, incremental, mixed } NatMappingScheme;

typedef struct _NAT {
    char brand[32];                  /* 0x00 */
    char model[32];                  /* 0x20 */
    char firmware[64];               /* 0x40 */
    int ipRestricted;                /* 0x80 */
    int portRestricted;              /* 0x84 */
    NatPromiscuity promiscuity;      /* 0x88 */
    NatType natType;                 /* 0x8C */
    NatMappingScheme mappingScheme;  /* 0x90 */
    AddressMapping mappings[4];      /* 0x94 */
    int qr2Compatible;               /* 0xD4 */
} NAT;

extern int func_02091588(int x) __attribute__((const));

/*
 * sdk:      DetermineNatType (libdwcgsnatneg.TWL.HYB.a natify.o)
 *
 * abs is declared __attribute__((const)): the object keeps ipRestricted and
 * portRestricted in registers across every abs call, which a plain extern
 * prototype does not allow.
 */
int func_02198E80(NAT *nat)
{
    nat->natType = unknown;
    nat->promiscuity = promiscuity_not_applicable;
    nat->qr2Compatible = 1;

    if (nat->mappings[0].publicIp == 0 || nat->mappings[1].publicIp == 0 || nat->mappings[2].publicIp == 0)
        return 0;

    if (!nat->portRestricted && !nat->ipRestricted && nat->mappings[0].publicIp == nat->mappings[0].privateIp)
        nat->natType = no_nat;
    else if (nat->mappings[0].publicIp == nat->mappings[0].privateIp)
        nat->natType = firewall_only;
    else {
        if (!nat->ipRestricted && !nat->portRestricted
            && func_02091588(nat->mappings[2].publicPort - nat->mappings[1].publicPort) >= 1) {
            nat->natType = symmetric;
            nat->promiscuity = promiscuous;
        } else if (nat->ipRestricted && !nat->portRestricted
                   && func_02091588(nat->mappings[2].publicPort - nat->mappings[1].publicPort) >= 1) {
            nat->natType = symmetric;
            nat->promiscuity = port_promiscuous;
        } else if (!nat->ipRestricted && nat->portRestricted
                   && func_02091588(nat->mappings[2].publicPort - nat->mappings[1].publicPort) >= 1) {
            nat->natType = symmetric;
            nat->promiscuity = ip_promiscuous;
        } else if (nat->ipRestricted && nat->portRestricted
                   && func_02091588(nat->mappings[2].publicPort - nat->mappings[1].publicPort) >= 1) {
            nat->natType = symmetric;
            nat->promiscuity = not_promiscuous;
        } else if (nat->portRestricted)
            nat->natType = port_restricted_cone;
        else if (nat->ipRestricted && !nat->portRestricted)
            nat->natType = restricted_cone;
        else if (!nat->ipRestricted && !nat->portRestricted)
            nat->natType = full_cone;
        else
            nat->natType = unknown;
    }

    if (nat->mappings[0].publicPort == nat->mappings[0].privatePort
        && nat->mappings[1].publicPort == nat->mappings[1].privatePort
        && nat->mappings[2].publicPort == nat->mappings[2].privatePort)
        nat->mappingScheme = private_as_public;
    else if (nat->mappings[0].publicPort == nat->mappings[1].publicPort
             && nat->mappings[1].publicPort == nat->mappings[2].publicPort)
        nat->mappingScheme = consistent_port;
    else if (nat->mappings[0].publicPort == nat->mappings[0].privatePort
             && nat->mappings[2].publicPort - nat->mappings[1].publicPort == 1)
        nat->mappingScheme = mixed;
    else if (nat->mappings[2].publicPort - nat->mappings[1].publicPort == 1)
        nat->mappingScheme = incremental;
    else
        nat->mappingScheme = unrecognized;

    if (nat->mappings[3].publicPort != 0 && nat->mappings[0].publicPort != nat->mappings[3].publicPort)
        nat->qr2Compatible = 0;

    return 1;
}
