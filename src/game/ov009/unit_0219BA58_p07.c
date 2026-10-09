/*
 * file:     unit_0219BA58_p07.c
 * unit:     yes
 * function: func_0219C154
 * address:  0x0219C154
 * packet:   pkt_ov009_0219C154
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr_process_query (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0219BED8  0x0219BED8  arm  ov009
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 *   func_0219BE80  0x0219BE80  arm  ov009
 *   g_021A76E4     0x021A76E4  data
 *   g_021A7720     0x021A7720  data
 *   g_021A775C     0x021A775C  data
 *   g_021A7798     0x021A7798  data
 *   g_021A77D4     0x021A77D4  data
 *   g_021A7804     0x021A7804  data
 *   g_021A7830     0x021A7830  data
 */

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

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_0219BED8(qr2_t qrec, qr2_buffer_t buf, QRSplitQueryProgress *progress);
extern int func_0217ECA4(int sock, char *buf, int len, int flags, SOCSockAddr *addr, int tolen);
extern void func_0219BE80(qr2_t qrec, qr2_buffer_t buf, int serverkeycount, unsigned char *serverkeys,
                          int playerkeycount, unsigned char *playerkeys, int teamkeycount,
                          unsigned char *teamkeys);

extern char g_021A76E4[];
extern char g_021A7720[];
extern char g_021A775C[];
extern char g_021A7798[];
extern char g_021A77D4[];
extern char g_021A7804[];
extern char g_021A7830[];

void func_0219C154(qr2_t qrec, qr2_buffer_t buf, unsigned char *qdata, int len, SOCSockAddr *sender)
{
    unsigned char serverkeycount;
    unsigned char playerkeycount;
    unsigned char teamkeycount;
    unsigned char exflags = 0;
    unsigned char *serverkeys = 0;
    unsigned char *playerkeys = 0;
    unsigned char *teamkeys = 0;

    if (len < 3) {
        func_0217D254(3, 0, 2, g_021A76E4, len);
        return;
    }
    serverkeycount = *qdata++;
    len--;
    if (serverkeycount != 0 && serverkeycount != 0xFF) {
        serverkeys = qdata;
        len -= serverkeycount;
        qdata += serverkeycount;
    }

    if (len < 2) {
        func_0217D254(3, 0, 2, g_021A7720, len);
        return;
    }
    playerkeycount = *qdata++;
    len--;
    if (playerkeycount != 0 && playerkeycount != 0xFF) {
        playerkeys = qdata;
        len -= playerkeycount;
        qdata += playerkeycount;
    }

    if (len < 1) {
        func_0217D254(3, 0, 2, g_021A775C, len);
        return;
    }
    teamkeycount = *qdata++;
    len--;
    if (teamkeycount != 0 && teamkeycount != 0xFF) {
        teamkeys = qdata;
        len -= teamkeycount;
        qdata += teamkeycount;
    }

    if (len < 0) {
        func_0217D254(3, 0, 2, g_021A7798, len);
        return;
    }
    if (len > 0)
        exflags = *qdata;

    if ((exflags & 1) == 1) {
        QRSplitQueryProgress progress;

        progress.mCurPacketNum = 0;
        progress.mCurKeyType = 0;
        progress.mCurKeyIndex = 0;
        progress.mCurSubCount = 0;
        progress.mCurSubIndex = 0;
        progress.mKeyBuffer.numkeys = 0;

        func_0217D254(3, 0, 0x10, g_021A77D4);
        while (func_0219BED8(qrec, buf, &progress) == 1) {
            func_0217ECA4(qrec->hbsock, buf->buffer, buf->len, 0, sender, 8);
            buf->len = 5;
            if (progress.mCurPacketNum > 7)
                return;
        }
        func_0217D254(3, 0, 0x10, g_021A7804, progress.mCurPacketNum);
        return;
    }

    func_0217D254(3, 0, 0x10, g_021A7830);
    func_0219BE80(qrec, buf, serverkeycount, serverkeys, playerkeycount, playerkeys, teamkeycount, teamkeys);
    func_0217ECA4(qrec->hbsock, buf->buffer, buf->len, 0, sender, 8);
}
