#ifndef ALETHEIA_OV009_QR2_TYPES_H
#define ALETHEIA_OV009_QR2_TYPES_H
/*
 * GameSpy QR2 and socket types shared by unit_0219AEB4 and unit_0219BA58
 * (ov009, qr2.o).  One canonical block, field offsets checked against every
 * view the parts used.
 */

typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned char data[6];
} SOCSockAddr;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    SOCInAddr addr;
} SOCSockAddrIn;

typedef struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
} SOCHostEnt;

typedef enum { key_server, key_player, key_team } qr2_key_type;

typedef struct qr2_buffer_s {
    char buffer[1400];
    int len;
} qr2_buffer_s;

typedef struct qr2_keybuffer_s {
    unsigned char keys[256];
    int numkeys;
} qr2_keybuffer_s;

typedef struct qr2_ipverify_info_s {
    SOCSockAddrIn addr;
    unsigned int challenge;
    unsigned int time;
} qr2_ipverify_info_s;

typedef struct qr2_implementation_s {
    int hbsock;
    char gamename[64];
    char secret_key[64];
    char instance_key[4];
    void (*server_key_callback)(int, qr2_buffer_s *, void *);
    void (*player_key_callback)(int, int, qr2_buffer_s *, void *);
    void (*team_key_callback)(int, int, qr2_buffer_s *, void *);
    void (*key_list_callback)(qr2_key_type, qr2_keybuffer_s *, void *);
    int (*playerteam_count_callback)(qr2_key_type, void *);
    void (*adderror_callback)(int, char *, void *);
    void (*nn_callback)(int, void *);
    void (*cm_callback)(char *, int, void *);
    void (*pa_callback)(unsigned int, unsigned short, void *);
    void (*cc_callback)(int, SOCSockAddrIn *, void *);
    void (*hr_callback)(void *);
    unsigned int lastheartbeat;
    unsigned int lastka;
    int userstatechangerequested;
    int listed_state;
    int ispublic;
    int qport;
    int read_socket;
    int nat_negotiate;
    SOCSockAddrIn hbaddr;
    void (*cdkeyprocess)(char *, int, void *);
    int client_message_keys[10];
    int cur_message_key;
    unsigned int publicip;
    unsigned short publicport;
    void *udata;
    unsigned char backendoptions;
    qr2_ipverify_info_s ipverify[200];
} qr2_implementation_s;

#endif
