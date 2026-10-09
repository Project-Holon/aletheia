/*
 * file:     unit_0219BA58_p03.c
 * unit:     yes
 * function: qr_got_recent_message, func_0219C5B8, qr2_check_ip_verify, qr2_expire_ip_verify, qr2_parse_queryA, func_0219CDBC, func_0219CE58
 * address:  0x0219C554
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand (round 5, lane s06): one canonical qr2 type block in qr2_types.h.
 *
 * symbols:
 *   gsDebugFormat          0x0217D254  arm  ov009
 *   gsDebugBinary          0x0217D32C  arm  ov009
 *   sendto                 0x0217ECA4  arm  ov009
 *   current_time           0x0217F264  arm  ov009
 *   SOC_InetNtoA           0x0215FA9C  arm  ov009
 *   STD_TSScanf            0x0208CF34  arm
 *   OS_SPrintf             0x02084F40  arm
 *   memcmp                 0x020923F0  arm
 *   rand                   0x02094694  arm  ov009
 *   NNProcessData          0x0219AB8C  arm  ov009
 *   qr2_buffer_add_int     0x0219B628  arm  ov009
 *   qr2_buffer_addA        0x0219B660  arm  ov009
 *   current_rec            0x021A6600  data
 *   g_021A5A7C             0x021A5A7C  data
 *   g_021A7874             0x021A7874  data
 *   g_021A788C             0x021A788C  data
 *   g_021A78B4             0x021A78B4  data
 *   g_021A78F0             0x021A78F0  data
 *   g_021A791C             0x021A791C  data
 *   g_021A7944             0x021A7944  data
 *   g_021A7960             0x021A7960  data
 *   g_021A7980             0x021A7980  data
 *   g_021A7988             0x021A7988  data
 *   g_021A79A8             0x021A79A8  data
 *   g_021A79D8             0x021A79D8  data
 *   g_021A79F4             0x021A79F4  data
 *   g_021A7A14             0x021A7A14  data
 *   g_021A7A38             0x021A7A38  data
 *   g_021A7A58             0x021A7A58  data
 *   g_021A7A74             0x021A7A74  data
 *   g_021A7A9C             0x021A7A9C  data
 *   g_021A7AB8             0x021A7AB8  data
 *   g_021A7AC4             0x021A7AC4  data
 *   g_021A7AD0             0x021A7AD0  data
 *   g_021A7AD8             0x021A7AD8  data
 *   g_021A7ADC             0x021A7ADC  data
 *   g_021A7AE0             0x021A7AE0  data
 *   g_021A7AF0             0x021A7AF0  data
 *   g_021A7AFC             0x021A7AFC  data
 *   g_021A7B08             0x021A7B08  data
 *   g_021A7B14             0x021A7B14  data
 *   num_local_ips          0x021AE9A0  data
 *   local_ip_list          0x021AE9A4  data
 *   func_0219BA84          0x0219BA84  arm  ov009
 *   func_0219BAB4          0x0219BAB4  arm  ov009
 *   func_0219BB54          0x0219BB54  arm  ov009
 *   func_0219BE80          0x0219BE80  arm  ov009
 *   func_0219C154          0x0219C154  arm  ov009
 *   func_0219C3A4          0x0219C3A4  arm  ov009
 *   memcpy                 0x02092344  arm
 */

#include "../../matched/arm9_sdk/libc/string.h"
#include "qr2_types.h"

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                   (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

#define QR2_OPTION_USE_QUERY_CHALLENGE 0x80
#define QR2_IPVERIFY_ARRAY_SIZE 200
#define QR2_IPVERIFY_MAXDUPLICATES 5

/* SOC_HtoNl, nitroWiFi/soc.h */
#define SOC_HtoNl(hostlong) \
    ((unsigned int)((((unsigned int)(hostlong) >> 24) & 0x000000ff) | (((unsigned int)(hostlong) >> 8) & 0x0000ff00) | \
                    (((unsigned int)(hostlong) << 8) & 0x00ff0000) | (((unsigned int)(hostlong) << 24) & 0xff000000)))

extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern void gsDebugBinary(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);
extern int sendto(int sock, char *buf, int len, int flags, SOCSockAddr *addr, int tolen);
extern unsigned int current_time(void);
extern char *SOC_InetNtoA(SOCInAddr in);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int memcmp(const void *s1, const void *s2, int n);
extern int rand(void);
extern void NNProcessData(char *data, int len, SOCSockAddrIn *fromaddr);
extern int qr2_buffer_add_int(qr2_buffer_s *outbuf, int value);
extern int qr2_buffer_addA(qr2_buffer_s *outbuf, char *value);
extern qr2_implementation_s *current_rec;
extern struct Magic6 g_021A5A7C;
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
extern char g_021A7A9C[];
extern char g_021A7AB8[];
extern char g_021A7AC4[];
extern char g_021A7AD0[];
extern char g_021A7AD8[];
extern char g_021A7ADC[];
extern char g_021A7AE0[];
extern char g_021A7AF0[];
extern char g_021A7AFC[];
extern char g_021A7B08[];
extern char g_021A7B14[];
extern int num_local_ips;
extern SOCInAddr local_ip_list[5];
extern void func_0219BA84(qr2_buffer_s *buf, char ptype, char *reqkey);
extern void func_0219BAB4(qr2_implementation_s *qrec, qr2_buffer_s *buf, char *challenge, int challengelen);
extern void func_0219BB54(qr2_implementation_s *qrec, char *buffer);
extern void func_0219BE80(qr2_implementation_s *qrec, qr2_buffer_s *buf, int serverkeycount, unsigned char *serverkeys, int playerkeycount, unsigned char *playerkeys, int teamkeycount, unsigned char *teamkeys);
extern void func_0219C154(qr2_implementation_s *qrec, qr2_buffer_s *buf, unsigned char *qdata, int len, SOCSockAddr *sender);
extern void func_0219C3A4(qr2_implementation_s *qrec, char *buf, int len);

/* sdk:      qr_got_recent_message (qr2.o) */
static int qr_got_recent_message(qr2_implementation_s *qrec, int msgkey)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (msgkey == qrec->client_message_keys[i])
            return 1;
    }
    qrec->cur_message_key = (qrec->cur_message_key + 1) % 10;
    qrec->client_message_keys[qrec->cur_message_key] = msgkey;
    return 0;
}

/*
 * sdk:      qr2_process_ip_verify (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * The vendor's own spelling: the declarations carry their initialisers in the
 * vendor's order (i, now, firstFreeIndex, numDuplicates) and the loop's init is
 * empty, which is what puts i in r5 and numDuplicates in r0.
 */
int func_0219C5B8(qr2_implementation_s *qrec, qr2_buffer_s *buf, SOCSockAddrIn *sender)
{
    int i = 0;
    unsigned int now = current_time();
    int firstFreeIndex = -1;
    int numDuplicates = 0;

    /* if the query challenge is disabled, return 0 as the challenge */
    if ((qrec->backendoptions & QR2_OPTION_USE_QUERY_CHALLENGE) == 0) {
        qr2_buffer_add_int(buf, 0);
        return 1;
    }

    /* check if this ip/port combo is already in the list */
    for (; i < QR2_IPVERIFY_ARRAY_SIZE; i++) {
        /* Mark the first free index when/if found */
        if (firstFreeIndex == -1 && qrec->ipverify[i].addr.addr.addr == 0)
            firstFreeIndex = i;
        /* Count any indexes that match this IP/port */
        if (qrec->ipverify[i].addr.addr.addr == sender->addr.addr &&
            qrec->ipverify[i].addr.port == sender->port) {
            numDuplicates++;
        }
    }

    /* discard if too many duplicates or no index found */
    if (numDuplicates > QR2_IPVERIFY_MAXDUPLICATES)
        return 0;
    if (firstFreeIndex == -1)
        return 0; /* no free indexes */

    /* create a random challenge for this ip/port combo */
    qrec->ipverify[firstFreeIndex].addr = *sender;
    qrec->ipverify[firstFreeIndex].challenge = SOC_HtoNl((rand() << 16) | rand());
    qrec->ipverify[firstFreeIndex].time = now;

    qr2_buffer_add_int(buf, (int)qrec->ipverify[firstFreeIndex].challenge);
    return 1; /* buffer ready to be sent */
}

/* sdk:      qr2_check_ip_verify (qr2.o) */
static int qr2_check_ip_verify(qr2_implementation_s *qrec, SOCSockAddrIn *sender, unsigned int ipverify)
{
    int i;

    for (i = 0; i < 200; i++) {
        if (sender->addr.addr == qrec->ipverify[i].addr.addr.addr &&
            sender->port == qrec->ipverify[i].addr.port &&
            ipverify == qrec->ipverify[i].challenge) {
            qrec->ipverify[i].addr.addr.addr = 0;
            qrec->ipverify[i].addr.port = 0;
            return 1;
        }
    }
    return 0;
}

/* sdk:      qr2_expire_ip_verify (qr2.o) */
void qr2_expire_ip_verify(qr2_implementation_s *qrec)
{
    int i = 0;
    unsigned int now = current_time();

    for (; i < 0xc8; i++) {
        if (qrec->ipverify[i].addr.addr.addr != 0 &&
            now - qrec->ipverify[i].time > 0xfa0)
            qrec->ipverify[i].addr.addr.addr = 0;
    }
}

/* sdk:      qr2_parse_queryA (qr2.o) */
void qr2_parse_queryA(qr2_implementation_s *qrec, char *query, int len, SOCSockAddr *sender)
{
    qr2_buffer_s buf;
    char ptype;
    char *reqkey;
    char *pos;
    int i;
    unsigned int backendoptions;

    buf.len = 0;
    gsDebugFormat(3, 0, 0x40, g_021A7874);
    if (qrec == 0)
        qrec = current_rec;
    i = query[0];
    if (i == ';') {
        if (qrec->cdkeyprocess != 0) {
            gsDebugFormat(3, 0, 8, g_021A788C);
            qrec->cdkeyprocess(query, len, sender);
        } else {
            gsDebugFormat(3, 0, 2, g_021A78B4);
        }
        return;
    }
    if (len >= 6 && memcmp(query, ((unsigned char *)&g_021A5A7C), 6) == 0) {
        gsDebugFormat(3, 0, 8, g_021A78F0);
        NNProcessData(query, len, (SOCSockAddrIn *)sender);
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
        gsDebugFormat(3, 0, 8, g_021A791C);
        if (func_0219C5B8(qrec, &buf, (SOCSockAddrIn *)sender) == 0)
            return;
        break;
    case 0:
        gsDebugFormat(3, 0, 8, g_021A7944);
        if ((qrec->backendoptions & 0x80) == 0x80) {
            if (len < 4)
                return;
            i = *(int *)pos;
            pos += 4;
            len -= 4;
            if (qr2_check_ip_verify(qrec, (SOCSockAddrIn *)sender, SWAP32((unsigned int)i)) == 0)
                return;
        }
        func_0219C154(qrec, &buf, (unsigned char *)pos, len, sender);
        return;
    case 1:
        gsDebugFormat(3, 0, 8, g_021A7960);
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len >= 15) {
            STD_TSScanf(pos + len - 15, g_021A7980, &backendoptions);
            qrec->backendoptions = (unsigned char)backendoptions;
            gsDebugFormat(3, 4, 8, g_021A7988, qrec->backendoptions);
            if (qrec->pa_callback != 0)
                func_0219BB54(qrec, pos + len - 13);
            else
                gsDebugFormat(3, 0, 8, g_021A79A8);
        }
        func_0219BAB4(qrec, &buf, pos, len);
        break;
    case 2:
        gsDebugFormat(3, 0, 8, g_021A79D8);
        if (len > 32)
            len = 32;
        buf.buffer[0] = 5;
        memcpy(buf.buffer + buf.len, pos, len);
        buf.len += len;
        break;
    case 4:
        gsDebugFormat(3, 0, 2, g_021A79F4);
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
        gsDebugFormat(3, 0, 8, g_021A7A14);
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len < 4)
            return;
        buf.buffer[0] = 7;
        memcpy(buf.buffer + buf.len, pos, 4);
        buf.len += 4;
        memcpy(&i, pos, 4);
        if (qr_got_recent_message(qrec, i) == 0)
            func_0219C3A4(qrec, pos + 4, len - 4);
        break;
    case 8:
        gsDebugFormat(3, 0, 0x10, g_021A7A38);
        return;
    case 10:
        gsDebugFormat(3, 0, 0x10, g_021A7A58);
        if (qrec->hr_callback == 0)
            return;
        qrec->hr_callback(qrec->udata);
        return;
    default:
        return;
    }

    sendto(qrec->hbsock, buf.buffer, buf.len, 0, sender, 8);
    gsDebugFormat(3, 0, 0x10, g_021A7A74, buf.len);
    gsDebugBinary(3, 0, 0x20, buf.buffer, buf.len);
}

/* sdk:      send_keepalive (qr2.o) */
void func_0219CDBC(qr2_implementation_s *qrec)
{
    qr2_buffer_s buf;

    buf.len = 0;
    func_0219BA84(&buf, 8, qrec->instance_key);
    sendto(qrec->hbsock, buf.buffer, buf.len, 0, (SOCSockAddr *)&qrec->hbaddr, 8);
    qrec->lastka = current_time();
    gsDebugFormat(3, 0, 0x10, g_021A7A9C, buf);
}

/* sdk:      send_heartbeat (qr2.o) */
void func_0219CE58(qr2_implementation_s *qrec, int statechanged)
{
    qr2_buffer_s buf;
    int i;
    char ipkey[20];

    buf.len = 0;
    func_0219BA84(&buf, 3, qrec->instance_key);
    for (i = 0; i < num_local_ips; i++) {
        OS_SPrintf(ipkey, g_021A7AB8, i);
        qr2_buffer_addA(&buf, ipkey);
        qr2_buffer_addA(&buf, SOC_InetNtoA(local_ip_list[i]));
    }
    qr2_buffer_addA(&buf, g_021A7AC4);
    qr2_buffer_add_int(&buf, qrec->qport);
    qr2_buffer_addA(&buf, g_021A7AD0);
    qr2_buffer_addA(&buf, qrec->nat_negotiate ? g_021A7AD8 : g_021A7ADC);
    if (statechanged) {
        qr2_buffer_addA(&buf, g_021A7AE0);
        qr2_buffer_add_int(&buf, statechanged);
    }
    qr2_buffer_addA(&buf, g_021A7AF0);
    qr2_buffer_addA(&buf, qrec->gamename);
    if (qrec->pa_callback) {
        qr2_buffer_addA(&buf, g_021A7AFC);
        qr2_buffer_add_int(&buf, (int)qrec->publicip);
        qr2_buffer_addA(&buf, g_021A7B08);
        qr2_buffer_add_int(&buf, qrec->publicport);
    }
    if (statechanged != 2) {
        qr2_buffer_s temp;

        memcpy(&temp, &buf, buf.len);
        temp.len = buf.len;
        func_0219BE80(qrec, &temp, 0xff, 0, 0xff, 0, 0xff, 0);
        if (0x578 - temp.len < 1) {
            temp.len = buf.len;
            func_0219BE80(qrec, &temp, 0xff, 0, 0, 0, 0, 0);
        }
        memcpy(&buf, &temp, temp.len);
        buf.len = temp.len;
    } else {
        if (0x578 - buf.len >= 1)
            buf.buffer[buf.len++] = 0;
    }
    sendto(qrec->hbsock, buf.buffer, buf.len, 0, (SOCSockAddr *)&qrec->hbaddr, sizeof(SOCSockAddrIn));
    qrec->lastheartbeat = current_time();
    qrec->lastka = qrec->lastheartbeat;
    if (statechanged)
        qrec->userstatechangerequested = 0;
    gsDebugFormat(3, 0, 0x10, g_021A7B14, buf.len);
    gsDebugBinary(3, 0, 0x20, buf.buffer, buf.len);
}
