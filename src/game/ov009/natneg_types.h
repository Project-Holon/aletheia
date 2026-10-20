#ifndef OV009_NATNEG_TYPES_H
#define OV009_NATNEG_TYPES_H
/* NAT negotiation types shared by natify and natneg (ov009). */

typedef struct _AddressMapping {
    unsigned int privateIp;
    unsigned short privatePort;
    unsigned int publicIp;
    unsigned short publicPort;
} AddressMapping;

typedef enum { no_nat, firewall_only, full_cone, restricted_cone, port_restricted_cone, symmetric, unknown } NatType;

typedef enum { promiscuous, not_promiscuous, port_promiscuous, ip_promiscuous, promiscuity_not_applicable } NatPromiscuity;

typedef enum { unrecognized, private_as_public, consistent_port, incremental, mixed } NatMappingScheme;

typedef struct NAT {
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

#endif
