#ifndef ALETHEIA_G_APC_BSS_H
#define ALETHEIA_G_APC_BSS_H
/* apc_bss (arm9) */
struct APC_BSS {
    void *apci_WCMBuffer;
    unsigned long apci_search_option;
    void *apci_WCMConfig;
    unsigned long apci_connect_option;
    unsigned char *apci_bssid_ptr;
    unsigned char *apci_essid_ptr;
    int apci_state;
    void (*apci_user_callback)(int, void *);
    void *apci_wmbssdesc;
    unsigned char *apci_Wep;
};
#endif
