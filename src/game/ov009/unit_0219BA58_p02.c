/*
 * file:     unit_0219BA58_p02.c
 * unit:     yes
 * function: func_0219C3A4
 * address:  0x0219C3A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand (round 5, lane s06): types from qr2_types.h.
 * Kept as its own part: the natneg template relocation at +0x198 resolves only
 * when the compare starts at this function's own SDK row.
 *
 * symbols:
 *   gsDebugFormat          0x0217D254  arm  ov009
 *   gsiSafeStrcpyA         0x021803BC  arm  ov009
 *   NNBeginNegotiationWithSocket 0x02199DFC  arm  ov009
 *   g_021A7858             0x021A7858  data
 *   g_021ACEF8             0x021ACEF8  data
 *   g_021ACEFC             0x021ACEFC  data
 *   func_0219BA54          0x0219BA54  arm  ov009
 *   func_0219BA58          0x0219BA58  arm  ov009
 *   @13818                 0x021A1B64  data
 *   memcpy                 0x02092344  arm
 */

#include "../../matched/arm9_sdk/libc/string.h"
#include "qr2_types.h"

extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern int NNBeginNegotiationWithSocket(int gamesocket, int cookie, int clientindex,
                                        void (*progresscallback)(int, void *),
                                        void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
extern char g_021A7858[];
extern int g_021ACEF8;
extern char g_021ACEFC[];
extern void func_0219BA54(int state, void *userdata);
extern void func_0219BA58(int result, int gamesocket, SOCSockAddrIn *remoteaddr, void *userdata);

/*
 * sdk:      qr_process_client_message (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * The six natneg magic bytes are a local initialiser; the vendor object's
 * template for them sits at 0x021A1B64.
 */
void func_0219C3A4(qr2_implementation_s *qrec, char *buf, int len)
{
    unsigned char natNegBytes[6] = {0xFD, 0xFC, 0x1E, 0x66, 0x6A, 0xB2};
    int i;
    int isnatneg = 1;
    int cookie;

    gsDebugFormat(3, 4, 8, g_021A7858);

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
                gsiSafeStrcpyA(g_021ACEFC, qrec->gamename, 64);
            }
            NNBeginNegotiationWithSocket(qrec->hbsock, cookie, 1, func_0219BA54, func_0219BA58, qrec);
        } else if (qrec->nn_callback)
            qrec->nn_callback(cookie, qrec->udata);
    } else if (qrec->cm_callback)
        qrec->cm_callback(buf, len, qrec->udata);
}
