#ifndef ALETHEIA_G_QR2_IMPLEMENTATION_S_H
#define ALETHEIA_G_QR2_IMPLEMENTATION_S_H
/* g_021A6600 (arm9) */
struct qr2_implementation_s {
    int hbsock;
    unsigned char pad_4[0x80];
    char instance_key[4];
    void *server_key_callback;
    void *player_key_callback;
    void *team_key_callback;
    void *key_list_callback;
    void *playerteam_count_callback;
    void (*adderror_callback)(int, char *, void *);
    void (*nn_callback)();
    void (*cm_callback)();
    void (*pa_callback)();
    void *cc_callback;
    void (*hr_callback)(void *);
    int lastHeartbeat;
    unsigned int lastka;
    int userstatechangerequested;
    int listed_state;
    int ispublic;
    int qport;
    int ownsSocket;
    int nat_negotiate;
    char hbaddr[8];
    void (*cdkeyprocess)(char *, int, void *);
    int client_message_keys[10];
    int cur_message_key;
    unsigned int publicip;
    unsigned short publicport;
    unsigned char pad_112[0x2];
    void *udata;
    unsigned char backendoptions;
};
#endif
