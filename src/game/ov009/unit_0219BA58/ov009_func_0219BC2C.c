/*
 * function: func_0219BC2C
 * address:  0x0219BC2C
 * packet:   pkt_ov009_0219BC2C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr_build_partial_query_reply (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   func_0219B660  0x0219B660  arm  ov009
 *   g_021A76CC     0x021A76CC  data
 *   g_021A7C90     0x021A7C90  data
 *   g_021A76D4     0x021A76D4  data
 */

#include "../../../matched/arm9_sdk/libc/string.h"

typedef struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned char data[6];
} SOCSockAddr;

typedef struct qr2_buffer_s {
    char buffer[1400];                                       /* 0x000 */
    int len;                                                 /* 0x578 */
} *qr2_buffer_t;

typedef struct qr2_keybuffer_s {
    unsigned char keys[256];                                 /* 0x000 */
    int numkeys;                                             /* 0x100 */
} qr2_keybuffer_t;

typedef struct qr2_implementation_s {
    int hbsock;                                              /* 0x000 */
    char gamename[64];                                       /* 0x004 */
    char secret_key[64];                                     /* 0x044 */
    char instance_key[4];                                    /* 0x084 */
    void (*server_key_callback)(int, qr2_buffer_t, void *);  /* 0x088 */
    void (*player_key_callback)(int, int, qr2_buffer_t, void *); /* 0x08C */
    void (*team_key_callback)(int, int, qr2_buffer_t, void *);   /* 0x090 */
    void (*key_list_callback)(int, qr2_keybuffer_t *, void *);   /* 0x094 */
    int (*playerteam_count_callback)(int, void *);           /* 0x098 */
    void (*adderror_callback)(int, char *, void *);          /* 0x09C */
    void (*nn_callback)(int, void *);                        /* 0x0A0 */
    void (*cm_callback)(char *, int, void *);                /* 0x0A4 */
    void *pa_callback;                                       /* 0x0A8 */
    void *cc_callback;                                       /* 0x0AC */
    void *hr_callback;                                       /* 0x0B0 */
    unsigned int lastheartbeat;                              /* 0x0B4 */
    unsigned int lastka;                                     /* 0x0B8 */
    int userstatechangerequested;                            /* 0x0BC */
    int listed_state;                                        /* 0x0C0 */
    int ispublic;                                            /* 0x0C4 */
    int qport;                                               /* 0x0C8 */
    int read_socket;                                         /* 0x0CC */
    int nat_negotiate;                                       /* 0x0D0 */
    char hbaddr[8];                                          /* 0x0D4 */
    void *cdkeyprocess;                                      /* 0x0DC */
    int client_message_keys[10];                             /* 0x0E0 */
    int cur_message_key;                                     /* 0x108 */
    unsigned int publicip;                                   /* 0x10C */
    unsigned short publicport;                               /* 0x110 */
    void *udata;                                             /* 0x114 */
    unsigned char backendoptions;                            /* 0x118 */
} *qr2_t;

typedef struct QRSplitQueryProgress {
    int mCurKeyType;                                         /* 0x00 */
    int mCurPacketNum;                                       /* 0x04 */
    int mCurKeyIndex;                                        /* 0x08 */
    int mCurSubCount;                                        /* 0x0C */
    int mCurSubIndex;                                        /* 0x10 */
    qr2_keybuffer_t mKeyBuffer;                              /* 0x14 */
} QRSplitQueryProgress;

extern int func_0219B660(qr2_buffer_t outbuf, const char *value);

extern char g_021A76CC[];
extern const char *g_021A7C90[];
extern char g_021A76D4[];

void func_0219BC2C(qr2_t qrec, qr2_buffer_t buf, int keytype, int keycount, unsigned char *keys)
{
    qr2_keybuffer_t kb;
    int playerteamcount;
    unsigned short cttemp;
    int i;
    int pindex;
    const char *k;
    int len;

    kb.numkeys = 0;
    if (keycount == 0)
        return;

    if (keytype == 1 || keytype == 2) {
        if (1400 - buf->len < (int)sizeof(cttemp))
            return;
        playerteamcount = qrec->playerteam_count_callback(keytype, qrec->udata);
        cttemp = (unsigned short)((((unsigned short)playerteamcount >> 8) & 0xFF)
                                  | (((unsigned short)playerteamcount << 8) & 0xFF00));
        memcpy(buf->buffer + buf->len, &cttemp, sizeof(cttemp));
        buf->len += sizeof(cttemp);
    } else
        playerteamcount = 1;

    if (keycount == 0xFF) {
        qrec->key_list_callback(keytype, &kb, qrec->udata);
        for (i = 0; i < kb.numkeys; i++) {
            k = g_021A7C90[kb.keys[i]];
            if (k == 0)
                k = g_021A76CC;
            func_0219B660(buf, k);
            if (keytype == 0) {
                len = buf->len;
                qrec->server_key_callback(kb.keys[i], buf, qrec->udata);
                if (len == buf->len)
                    func_0219B660(buf, g_021A76D4);
            }
        }
        if (1400 - buf->len < 1)
            return;
        buf->buffer[buf->len++] = 0;
        keycount = kb.numkeys;
        keys = kb.keys;
        if (keytype == 0)
            return;
    }

    for (pindex = 0; pindex < playerteamcount; pindex++) {
        for (i = 0; i < keycount; i++) {
            len = buf->len;
            if (keytype == 0)
                qrec->server_key_callback(keys[i], buf, qrec->udata);
            else if (keytype == 1)
                qrec->player_key_callback(keys[i], pindex, buf, qrec->udata);
            else if (keytype == 2)
                qrec->team_key_callback(keys[i], pindex, buf, qrec->udata);
            if (len == buf->len)
                func_0219B660(buf, g_021A76D4);
        }
    }
}
