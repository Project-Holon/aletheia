/*
 * function: func_0219C3A4
 * address:  0x0219C3A4
 * packet:   pkt_ov009_0219C3A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      qr_process_client_message (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021803BC  0x021803BC  arm  ov009
 *   func_02199DFC  0x02199DFC  arm  ov009
 *   func_0219BA58  0x0219BA58  arm  ov009
 *   func_0219BA54  0x0219BA54  arm  ov009
 *   @13818         0x021A1B64  data
 *   g_021A7858     0x021A7858  data
 *   g_021ACEF8     0x021ACEF8  data
 *   g_021ACEFC     0x021ACEFC  data
 *
 * MATCH: every byte equal, one relocation without a witness.
 *   - @13818 (0x021A1B64), the initializer template of natNegBytes: the
 *     six bytes FD FC 1E 66 6A B2 recur in the image (0x021A1A64 and
 *     NNMagicData at 0x021A5A7C), so the template class does not fire.
 *   - func_0219BA54 (NatNegProgressCallback) now attests as sdk (w5_nm:
 *     seed, catalog row and stub ov009_func_0219BA54.c); @13818 is the only
 *     unresolved site left.
 */

#include "../../matched/arm9_sdk/libc/string.h" /* "../arm9_sdk/libc/string.h" once under src/matched */

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

typedef struct qr2_implementation_s {
    int hbsock;                                              /* 0x000 */
    char gamename[64];                                       /* 0x004 */
    char pad044[0xA0 - 0x44];
    void (*nn_callback)(int cookie, void *userdata);         /* 0x0A0 */
    void (*cm_callback)(char *data, int len, void *userdata); /* 0x0A4 */
    void *pa_callback;                                       /* 0x0A8 */
    void *cc_callback;                                       /* 0x0AC */
    char pad0b0[0x114 - 0xB0];
    void *udata;                                             /* 0x114 */
} *qr2_t;

extern void func_0217D254(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern unsigned long func_021803BC(char *dst, const char *src, unsigned long size);
extern int func_02199DFC(int gamesocket, int cookie, int clientindex,
                         void (*progresscallback)(int, void *),
                         void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
extern void func_0219BA58(int result, int gamesocket, SOCSockAddrIn *remoteaddr, void *userdata);
extern void func_0219BA54(int state, void *userdata);

extern char g_021A7858[];
extern int g_021ACEF8;
extern char g_021ACEFC[];

void func_0219C3A4(qr2_t qrec, char *buf, int len)
{
    unsigned char natNegBytes[6] = {0xFD, 0xFC, 0x1E, 0x66, 0x6A, 0xB2};
    int i;
    int isnatneg = 1;
    int cookie;

    func_0217D254(3, 4, 8, g_021A7858);

    if (len >= 10) {
        for (i = 0; i < 6; i++) {
            if ((unsigned char)buf[i] != natNegBytes[i]) {
                isnatneg = 0;
                break;
            }
        }
    } else
        isnatneg = 0;

    if (isnatneg) {
        memcpy(&cookie, buf + 6, 4);
        cookie = (int)((((unsigned int)cookie >> 24) & 0xFF) | (((unsigned int)cookie >> 8) & 0xFF00)
                       | (((unsigned int)cookie << 8) & 0xFF0000) | (((unsigned int)cookie << 24) & 0xFF000000));
        if (qrec->cc_callback) {
            if (g_021ACEF8 != 1) {
                g_021ACEF8 = 1;
                func_021803BC(g_021ACEFC, qrec->gamename, 64);
            }
            func_02199DFC(qrec->hbsock, cookie, 1, func_0219BA54, func_0219BA58, qrec);
        } else if (qrec->nn_callback)
            qrec->nn_callback(cookie, qrec->udata);
    } else if (qrec->cm_callback)
        qrec->cm_callback(buf, len, qrec->udata);
}
