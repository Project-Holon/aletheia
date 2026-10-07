/*
 * file:     unit_0216C858_p02.c
 * unit:     yes
 * function: func_0216CB90, func_0216CC28, func_0216CD8C
 * address:  0x0216CB90
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02175FB8  0x02175FB8  arm  ov009
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_02175EB4  0x02175EB4  arm  ov009
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_02175F1C  0x02175F1C  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217601C  0x0217601C  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   func_02173B18  0x02173B18  arm  ov009
 *   func_0216F388  0x0216F388  arm  ov009
 *   func_02195E60  0x02195E60  arm  ov009
 *   func_02195E40  0x02195E40  arm  ov009
 *   func_0219AEB4  0x0219AEB4  arm  ov009
 *   func_0219B540  0x0219B540  arm  ov009
 *   func_02173E30  0x02173E30  arm  ov009
 *   func_0219B1AC  0x0219B1AC  arm  ov009
 *   func_0219B134  0x0219B134  arm  ov009
 *   func_0219B170  0x0219B170  arm  ov009
 *   func_02176ABC  0x02176ABC  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 *   func_02174AA0  0x02174AA0  arm  ov009
 *   func_02174C2C  0x02174C2C  arm  ov009
 *   func_02174C30  0x02174C30  arm  ov009
 *   func_02174C34  0x02174C34  arm  ov009
 *   func_02174CF0  0x02174CF0  arm  ov009
 *   func_02174CF8  0x02174CF8  arm  ov009
 *   func_02174D04  0x02174D04  arm  ov009
 *   func_02174D28  0x02174D28  arm  ov009
 *   func_02174ED0  0x02174ED0  arm  ov009
 */
struct qr2_implementation_s;
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
extern unsigned char func_02175FB8(void);
extern int func_0216B908(void);
extern int func_02175EB4(void);
extern unsigned char func_0216B838(void);
extern void  func_02175F1C(int a0);
extern void  func_02175F4C(int a0);
extern void  func_02082BCC(void *p, int v, int n);
extern void  func_0217601C(void);
extern void  func_0217653C(void);
extern void  func_02173B18(void);
extern int   func_0216F388(int a0);
extern int func_02195E60(const int *p);
extern unsigned short func_02195E40(const unsigned short *p);
extern int func_0219AEB4(void **qrec, int s, int boundport, char *gamename, char *secret_key,
                         int ispublic, int natnegotiate, void *server_key_callback,
                         void *player_key_callback, void *team_key_callback,
                         void *key_list_callback, void *playerteam_count_callback,
                         void *adderror_callback, void *userdata);
extern void func_0219B540(struct qr2_implementation_s *qrec);
extern int func_02173E30(int error);
extern void func_0219B1AC(void *qrec, void *cb);
extern void func_0219B134(void *qrec, void *cb);
extern void func_0219B170(void *qrec, void *cb);
extern void func_02176ABC(void);
extern void func_0219B490(void *qrec);
extern void func_02174AA0(int keyid, void *outbuf);
extern void func_02174C2C();
extern void func_02174C30();
extern void func_02174C34(int keytype, void *keybuffer);
extern int func_02174CF0();
extern void func_02174CF8();
extern void func_02174D04();
extern void func_02174D28(int cookie);
extern void func_02174ED0(char *data, int len);
int func_0216CB90(void);
int func_0216CC28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
int func_0216CD8C(int profileID);


/*
 * sdk:      DWC_GetSuspendMatch (dwc_match.o)
 */
int func_0216CB90(void)
{
    int bNew = -1;
    unsigned int bitmap;

    if (!func_02175F3C())
        return 0;
    if (!func_02175FB8())
        return 0;
    bitmap = *(unsigned int *)(func_02175F3C() + 0x1c);
    bitmap &= func_0216B908();
    if (!func_02175EB4())
        bitmap &= ~(1 << func_0216B838());
    if ((bitmap ^ func_0216B908()) == 0)
        bNew = 1;
    else if ((bitmap & func_0216B908()) == 0)
        bNew = 0;
    if (bNew != -1)
        *(int *)(func_02175F3C() + 0x28) = bNew == 1;
    return *(int *)(func_02175F3C() + 0x28);
}


/*
 * DWCi_MatchInit (dwc_match.o): seed the match parameter block returned by
 * func_02175F3C(), every field through a fresh getter call.  The +0x5f0/+0x5f4
 * pair is the one place a local reuses one getter result.
 */
int func_0216CC28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    char *q;

    func_02175F1C(a0);
    *(int *)(func_02175F3C() + 0x0) = a1;
    *(int *)(func_02175F3C() + 4) = a2;
    *(int *)(func_02175F3C() + 8) = a3;
    *(int *)(func_02175F3C() + 0x10) = 0;
    *(int *)(func_02175F3C() + 0x5d8) = 0;
    *(unsigned short *)(func_02175F3C() + 0x5d4) = 0;
    *(int *)(func_02175F3C() + 0x5e0) = 0;
    func_02175F4C(0);
    *(char *)(func_02175F3C() + 0x19) = 0;
    *(int *)(func_02175F3C() + 0x678) = 0;
    *(int *)(func_02175F3C() + 0x684) = a4;
    *(int *)(func_02175F3C() + 0x688) = a5;
    *(int *)(func_02175F3C() + 0x68c) = a6;
    *(int *)(func_02175F3C() + 0x690) = a7;
    func_02082BCC((void *)(func_02175F3C() + 0x694), 0, 0x40);
    *(int *)(func_02175F3C() + 0x6d4) = 0;
    *(int *)(func_02175F3C() + 0x770) = 0;
    *(int *)(func_02175F3C() + 0x774) = 0;
    *(int *)(func_02175F3C() + 0x780) = 0;
    *(int *)(func_02175F3C() + 0x784) = 0;
    *(int *)(func_02175F3C() + 0x788) = 0;
    *(int *)(func_02175F3C() + 0x78c) = 0;
    *(int *)(func_02175F3C() + 0x790) = 0;
    *(char *)(func_02175F3C() + 0x794) = 0;
    *(int *)(func_02175F3C() + 0x798) = 0;
    *(char *)(func_02175F3C() + 0x15) = 0;
    *(char *)(func_02175F3C() + 0x16) = 0;
    q = (char *)func_02175F3C();
    *(int *)(q + 0x5f0) = 0;
    *(int *)(q + 0x5f4) = 0;
    *(int *)(func_02175F3C() + 0x7c8) = 0;
    *(int *)(func_02175F3C() + 0x7d4) = 1;
    *(char *)(func_02175F3C() + 0x7b5) = 0;
    *(char *)(func_02175F3C() + 0x7b6) = 0;
    *(int *)(func_02175F3C() + 0x7b0) = 0;
    func_0217601C();
    func_0217653C();
    func_02173B18();
    return func_0216F388(0);
}


/*
 * notes:    the three callback stubs (0x02174C2C PlayerKey, 0x02174C30 TeamKey, 0x02174CF0 Count) were seeded and catalogued by w7_nm from this function's ABS32 pool words
 *
 * sdk:      DWCi_QR2Startup (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
int func_0216CD8C(int profileID)
{
    int i;
    int qr2Error;

    if (((DWCstMatchControl *)func_02175F3C())->qr2 != 0)
        return 0;
    for (i = 0; i < 1; i++) {
        qr2Error = func_0219AEB4(&((DWCstMatchControl *)func_02175F3C())->qr2,
                                 func_02195E60(*((DWCstMatchControl *)func_02175F3C())->gt2Socket),
                                 func_02195E40(*((DWCstMatchControl *)func_02175F3C())->gt2Socket),
                                 ((DWCstMatchControl *)func_02175F3C())->gameName,
                                 ((DWCstMatchControl *)func_02175F3C())->secretKey,
                                 1, 1,
                                 func_02174AA0, func_02174C2C, func_02174C30,
                                 func_02174C34, func_02174CF0, func_02174CF8,
                                 0);
        if (qr2Error == 0)
            break;
        func_0219B540(((DWCstMatchControl *)func_02175F3C())->qr2);
        ((DWCstMatchControl *)func_02175F3C())->qr2 = 0;
        if (qr2Error != 3 || i == 0) {
            func_02173E30(qr2Error);
            return qr2Error;
        }
    }
    ((DWCstMatchControl *)func_02175F3C())->qr2NNFinishCount = 0;
    ((DWCstMatchControl *)func_02175F3C())->qr2MatchType = 0;
    func_0219B1AC(((DWCstMatchControl *)func_02175F3C())->qr2, func_02174D04);
    func_0219B134(((DWCstMatchControl *)func_02175F3C())->qr2, func_02174D28);
    func_0219B170(((DWCstMatchControl *)func_02175F3C())->qr2, func_02174ED0);
    func_02176ABC();
    func_0219B490(((DWCstMatchControl *)func_02175F3C())->qr2);
    return qr2Error;
}
