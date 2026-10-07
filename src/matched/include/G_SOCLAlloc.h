#ifndef ALETHEIA_G_SOCLALLOC_H
#define ALETHEIA_G_SOCLALLOC_H
/* g_021AA4BC (arm9) */
struct SOCLAlloc {
    unsigned long w00;
    void * (*free_)(int, void *, unsigned long);
    unsigned long w08;
    void * (*alloc_)(int, unsigned long);
    unsigned char pad_10[0x8];
    unsigned char *addrList[2];
    char *hostent_name;
    char **hostent_aliases;
    short hostent_addrType;
    short hostent_length;
    unsigned char **hostent_addrList;
    unsigned char pad_30[0x20];
    int soclConfig_use_dhcp;
    unsigned int soclConfig_my_ip;
    unsigned int soclConfig_net_mask;
    unsigned int soclConfig_gateway_ip;
    unsigned int soclConfig_dns_ip0;
    unsigned int soclConfig_dns_ip1;
    void * (*soclConfig_alloc)(unsigned int);
    void (*soclConfig_free)(void *);
    unsigned int soclConfig_cmd_packet_max;
    unsigned int soclConfig_pad24[3];
    long soclConfig_mtu;
    long soclConfig_rwin;
};
#endif
