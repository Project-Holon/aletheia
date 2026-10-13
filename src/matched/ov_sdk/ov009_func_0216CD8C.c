/*
 * function: DWCi_QR2Startup
 * address:  0x0216CD8C
 * packet:   pkt_ov009_0216CD8C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    the three callback stubs (0x02174C2C PlayerKey, 0x02174C30 TeamKey, 0x02174CF0 Count) were seeded and catalogued by w7_nm from this function's ABS32 pool words
 *
 * sdk:      DWCi_QR2Startup (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   gt2GetSocketSOCKET  0x02195E60  arm  ov009
 *   gt2GetLocalPort  0x02195E40  arm  ov009
 *   qr2_init_socketA  0x0219AEB4  arm  ov009
 *   qr2_shutdown  0x0219B540  arm  ov009
 *   DWCi_HandleQR2Error  0x02173E30  arm  ov009
 *   func_0219B1AC  0x0219B1AC  arm  ov009
 *   func_0219B134  0x0219B134  arm  ov009
 *   func_0219B170  0x0219B170  arm  ov009
 *   DWCi_RegisterMatchmakeKeys  0x02176ABC  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 *   DWCi_QR2ServerKeyCallback  0x02174AA0  arm  ov009
 *   DWCi_QR2PlayerKeyCallback  0x02174C2C  arm  ov009
 *   DWCi_QR2TeamKeyCallback  0x02174C30  arm  ov009
 *   DWCi_QR2KeyListCallback  0x02174C34  arm  ov009
 *   DWCi_QR2CountCallback  0x02174CF0  arm  ov009
 *   DWCi_QR2AddErrorCallback  0x02174CF8  arm  ov009
 *   func_02174D04  0x02174D04  arm  ov009
 *   DWCi_QR2NatnegCallback  0x02174D28  arm  ov009
 *   DWCi_QR2ClientMsgCallback  0x02174ED0  arm  ov009
 */

typedef struct DWCstMatchControl {
    char pad0[4];
    void **gt2Socket;
    char pad8[8];
    void *qr2;
    char pad14[0x5d4 - 0x14];
    unsigned short qr2MatchType;
    char pad5d6[2];
    int qr2NNFinishCount;
    char pad5dc[0x684 - 0x5dc];
    char *gameName;
    char *secretKey;
} DWCstMatchControl;

extern int func_02175F3C(void);
struct qr2_implementation_s;
extern int gt2GetSocketSOCKET(const int *p);
extern unsigned short gt2GetLocalPort(const unsigned short *p);
extern int qr2_init_socketA(void **qrec, int s, int boundport, char *gamename, char *secret_key,
                         int ispublic, int natnegotiate, void *server_key_callback,
                         void *player_key_callback, void *team_key_callback,
                         void *key_list_callback, void *playerteam_count_callback,
                         void *adderror_callback, void *userdata);
extern void qr2_shutdown(struct qr2_implementation_s *qrec);
extern int DWCi_HandleQR2Error(int error);
extern void func_0219B1AC(void *qrec, void *cb);
extern void func_0219B134(void *qrec, void *cb);
extern void func_0219B170(void *qrec, void *cb);
extern void DWCi_RegisterMatchmakeKeys(void);
extern void func_0219B490(void *qrec);
extern void DWCi_QR2ServerKeyCallback(int keyid, void *outbuf);
extern void DWCi_QR2PlayerKeyCallback();
extern void DWCi_QR2TeamKeyCallback();
extern void DWCi_QR2KeyListCallback(int keytype, void *keybuffer);
extern int DWCi_QR2CountCallback();
extern void DWCi_QR2AddErrorCallback();
extern void func_02174D04();
extern void DWCi_QR2NatnegCallback(int cookie);
extern void DWCi_QR2ClientMsgCallback(char *data, int len);

int DWCi_QR2Startup(int profileID)
{
    int i;
    int qr2Error;

    if (((DWCstMatchControl *)func_02175F3C())->qr2 != 0)
        return 0;
    for (i = 0; i < 1; i++) {
        qr2Error = qr2_init_socketA(&((DWCstMatchControl *)func_02175F3C())->qr2,
                                 gt2GetSocketSOCKET(*((DWCstMatchControl *)func_02175F3C())->gt2Socket),
                                 gt2GetLocalPort(*((DWCstMatchControl *)func_02175F3C())->gt2Socket),
                                 ((DWCstMatchControl *)func_02175F3C())->gameName,
                                 ((DWCstMatchControl *)func_02175F3C())->secretKey,
                                 1, 1,
                                 DWCi_QR2ServerKeyCallback, DWCi_QR2PlayerKeyCallback, DWCi_QR2TeamKeyCallback,
                                 DWCi_QR2KeyListCallback, DWCi_QR2CountCallback, DWCi_QR2AddErrorCallback,
                                 0);
        if (qr2Error == 0)
            break;
        qr2_shutdown(((DWCstMatchControl *)func_02175F3C())->qr2);
        ((DWCstMatchControl *)func_02175F3C())->qr2 = 0;
        if (qr2Error != 3 || i == 0) {
            DWCi_HandleQR2Error(qr2Error);
            return qr2Error;
        }
    }
    ((DWCstMatchControl *)func_02175F3C())->qr2NNFinishCount = 0;
    ((DWCstMatchControl *)func_02175F3C())->qr2MatchType = 0;
    func_0219B1AC(((DWCstMatchControl *)func_02175F3C())->qr2, func_02174D04);
    func_0219B134(((DWCstMatchControl *)func_02175F3C())->qr2, DWCi_QR2NatnegCallback);
    func_0219B170(((DWCstMatchControl *)func_02175F3C())->qr2, DWCi_QR2ClientMsgCallback);
    DWCi_RegisterMatchmakeKeys();
    func_0219B490(((DWCstMatchControl *)func_02175F3C())->qr2);
    return qr2Error;
}
