/*
 * function: qr2_parse_queryA
 * address:  0x0219C7C0
 * packet:   pkt_ov009_0219C7C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note:     2026-10-01 lane08: EXACT.  Rebuilt from the image listing and
 *   DWARF (locals buf, ptype, reqkey, pos, i [fb+12], backendoptions
 *   [fb+8]): switch case order 9,0,1,2,4,6,8,10 (string @N numbering and
 *   code order agree), sends after the switch, case 8 logs @14962
 *   (0x021A7A38), case 6 copies with memcpy into the buffer and into `i`
 *   with `buf.len += 4` between, and the first `query[0]` is held in `i`
 *   (the int local, not ptype): that is the r5 web the image keeps across
 *   the cdkey/natneg tests, which a char `ptype` rotates into a 3-cycle.
 *
 * sdk:      qr2_parse_queryA (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   func_0219AB8C  0x0219AB8C  arm  ov009
 *   func_0219BA84  0x0219BA84  arm  ov009
 *   func_0219C5B8  0x0219C5B8  arm  ov009
 *   func_0219C724  0x0219C724  arm  ov009
 *   func_0219C154  0x0219C154  arm  ov009
 *   func_0208CF34  0x0208CF34  arm
 *   func_0219BB54  0x0219BB54  arm  ov009
 *   func_0219BAB4  0x0219BAB4  arm  ov009
 *   func_02092344  0x02092344  arm
 *   func_0219C554  0x0219C554  arm  ov009
 *   func_0219C3A4  0x0219C3A4  arm  ov009
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 *   func_0217D32C  0x0217D32C  arm  ov009
 *   current_rec    0x021A6600  data
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021A7874     0x021A7874  data
 *   g_021A788C     0x021A788C  data
 *   g_021A78B4     0x021A78B4  data
 *   g_021A78F0     0x021A78F0  data
 *   g_021A791C     0x021A791C  data
 *   g_021A7944     0x021A7944  data
 *   g_021A7960     0x021A7960  data
 *   g_021A7980     0x021A7980  data
 *   g_021A7988     0x021A7988  data
 *   g_021A79A8     0x021A79A8  data
 *   g_021A79D8     0x021A79D8  data
 *   g_021A79F4     0x021A79F4  data
 *   g_021A7A14     0x021A7A14  data
 *   g_021A7A38     0x021A7A38  data
 *   g_021A7A58     0x021A7A58  data
 *   g_021A7A74     0x021A7A74  data
 */

#include "../../matched/arm9_sdk/libc/string.h"

typedef struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned char data[6];
} SOCSockAddr;

typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    SOCInAddr addr;
} SOCSockAddrIn;

typedef struct qr2_buffer_s {
    char buffer[1400];
    int len;
} qr2_buffer_s;

typedef struct qr2_implementation_s {
    int hbsock;                                        /* 0x000 */
    unsigned char pad0[0x80];
    char instance_key[4];                              /* 0x084 */
    void *server_key_callback;                         /* 0x088 */
    void *player_key_callback;                         /* 0x08C */
    void *team_key_callback;                           /* 0x090 */
    void *key_list_callback;                           /* 0x094 */
    void *playerteam_count_callback;                   /* 0x098 */
    void (*adderror_callback)(int, char *, void *);    /* 0x09C */
    void *nn_callback;                                 /* 0x0A0 */
    void *cm_callback;                                 /* 0x0A4 */
    void *pa_callback;                                 /* 0x0A8 */
    void *cc_callback;                                 /* 0x0AC */
    void (*hr_callback)(void *);                       /* 0x0B0 */
    unsigned int lastheartbeat;                        /* 0x0B4 */
    unsigned int lastka;                               /* 0x0B8 */
    int userstatechangerequested;                      /* 0x0BC */
    int listed_state;                                  /* 0x0C0 */
    int ispublic;                                      /* 0x0C4 */
    int qport;                                         /* 0x0C8 */
    int read_socket;                                   /* 0x0CC */
    int nat_negotiate;                                 /* 0x0D0 */
    char hbaddr[8];                                    /* 0x0D4 */
    void (*cdkeyprocess)(char *, int, SOCSockAddr *);  /* 0x0DC */
    int client_message_keys[10];                       /* 0x0E0 */
    int cur_message_key;                               /* 0x108 */
    unsigned int publicip;                             /* 0x10C */
    unsigned short publicport;                         /* 0x110 */
    void *udata;                                       /* 0x114 */
    unsigned char backendoptions;                      /* 0x118 */
} qr2_implementation_s;

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                   (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

extern qr2_implementation_s *current_rec;
extern unsigned char g_021A5A7C[];
extern char g_021A7874[];
extern char g_021A788C[];
extern char g_021A78B4[];
extern char g_021A78F0[];
extern char g_021A791C[];
extern char g_021A7944[];
extern char g_021A7960[];
extern char g_021A7980[];
extern char g_021A7988[];
extern char g_021A79A8[];
extern char g_021A79D8[];
extern char g_021A79F4[];
extern char g_021A7A14[];
extern char g_021A7A38[];
extern char g_021A7A58[];
extern char g_021A7A74[];

extern void func_0217D254(int theCat, int theType, unsigned char theLevel,
                          const char *theTokenStr, ...);
extern int func_020923F0(const void *s1, const void *s2, int n);
extern void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr);
extern void func_0219BA84(qr2_buffer_s *buf, char ptype, char *reqkey);
extern int func_0219C5B8(qr2_implementation_s *qrec, qr2_buffer_s *buf,
                         SOCSockAddrIn *sender);
extern int func_0219C724(qr2_implementation_s *qrec, SOCSockAddrIn *sender,
                         unsigned int ipverify);
extern void func_0219C154(qr2_implementation_s *qrec, qr2_buffer_s *buf,
                          unsigned char *qdata, int len, SOCSockAddr *sender);
extern int func_0208CF34(char *src, char *fmt, ...);
extern void func_0219BB54(qr2_implementation_s *qrec, char *buffer);
extern void func_0219BAB4(qr2_implementation_s *qrec, qr2_buffer_s *buf,
                          char *challenge, int challengelen);
extern void func_02092344(void *dst, void *src, unsigned long size);
extern int func_0219C554(qr2_implementation_s *qrec, int msgkey);
extern void func_0219C3A4(qr2_implementation_s *qrec, char *buf, int len);
extern int func_0217ECA4(int sock, char *buf, int len, int flags,
                         SOCSockAddr *addr, int tolen);
extern void func_0217D32C(int theCat, int theType, unsigned char theLevel,
                          char *theBuffer, int theLength);

void qr2_parse_queryA(qr2_implementation_s *qrec, char *query, int len,
                      SOCSockAddr *sender)
{
    qr2_buffer_s buf;
    char ptype;
    char *reqkey;
    char *pos;
    int i;
    unsigned int backendoptions;

    buf.len = 0;
    func_0217D254(3, 0, 0x40, g_021A7874);
    if (qrec == 0)
        qrec = current_rec;
    i = query[0];
    if (i == ';') {
        if (qrec->cdkeyprocess != 0) {
            func_0217D254(3, 0, 8, g_021A788C);
            qrec->cdkeyprocess(query, len, sender);
        } else {
            func_0217D254(3, 0, 2, g_021A78B4);
        }
        return;
    }
    if (len >= 6 && func_020923F0(query, g_021A5A7C, 6) == 0) {
        func_0217D254(3, 0, 8, g_021A78F0);
        func_0219AB8C(query, len, (SOCSockAddrIn *)sender);
        return;
    }
    if (len < 7 || (unsigned char)i != 0xfe || (unsigned char)query[1] != 0xfd)
        return;
    if (qrec->listed_state > 0)
        qrec->listed_state = 0;
    reqkey = query + 3;
    ptype = query[2];
    pos = query + 7;
    len -= 7;
    func_0219BA84(&buf, ptype, reqkey);

    switch (ptype) {
    case 9:
        func_0217D254(3, 0, 8, g_021A791C);
        if (func_0219C5B8(qrec, &buf, (SOCSockAddrIn *)sender) == 0)
            return;
        break;
    case 0:
        func_0217D254(3, 0, 8, g_021A7944);
        if ((qrec->backendoptions & 0x80) == 0x80) {
            if (len < 4)
                return;
            i = *(int *)pos;
            pos += 4;
            len -= 4;
            if (func_0219C724(qrec, (SOCSockAddrIn *)sender, SWAP32((unsigned int)i)) == 0)
                return;
        }
        func_0219C154(qrec, &buf, (unsigned char *)pos, len, sender);
        return;
    case 1:
        func_0217D254(3, 0, 8, g_021A7960);
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len >= 15) {
            func_0208CF34(pos + len - 15, g_021A7980, &backendoptions);
            qrec->backendoptions = (unsigned char)backendoptions;
            func_0217D254(3, 4, 8, g_021A7988, qrec->backendoptions);
            if (qrec->pa_callback != 0)
                func_0219BB54(qrec, pos + len - 13);
            else
                func_0217D254(3, 0, 8, g_021A79A8);
        }
        func_0219BAB4(qrec, &buf, pos, len);
        break;
    case 2:
        func_0217D254(3, 0, 8, g_021A79D8);
        if (len > 32)
            len = 32;
        buf.buffer[0] = 5;
        func_02092344(buf.buffer + buf.len, pos, len);
        buf.len += len;
        break;
    case 4:
        func_0217D254(3, 0, 2, g_021A79F4);
        if (qrec->listed_state == -1)
            return;
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len < 2)
            return;
        qrec->listed_state = -1;
        qrec->adderror_callback(pos[0], pos + 1, qrec->udata);
        return;
    case 6:
        func_0217D254(3, 0, 8, g_021A7A14);
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len < 4)
            return;
        buf.buffer[0] = 7;
        memcpy(buf.buffer + buf.len, pos, 4);
        buf.len += 4;
        memcpy(&i, pos, 4);
        if (func_0219C554(qrec, i) == 0)
            func_0219C3A4(qrec, pos + 4, len - 4);
        break;
    case 8:
        func_0217D254(3, 0, 0x10, g_021A7A38);
        return;
    case 10:
        func_0217D254(3, 0, 0x10, g_021A7A58);
        if (qrec->hr_callback == 0)
            return;
        qrec->hr_callback(qrec->udata);
        return;
    default:
        return;
    }

    func_0217ECA4(qrec->hbsock, buf.buffer, buf.len, 0, sender, 8);
    func_0217D254(3, 0, 0x10, g_021A7A74, buf.len);
    func_0217D32C(3, 0, 0x20, buf.buffer, buf.len);
}
