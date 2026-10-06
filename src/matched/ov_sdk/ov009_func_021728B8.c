/*
 * function: func_021728B8
 * address:  0x021728B8
 * packet:   pkt_ov009_021728B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_DoCancelMatch (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02172A58  0x02172A58  arm  ov009
 *   func_0216BB6C  0x0216BB6C  arm  ov009
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   func_02195DE4  0x02195DE4  arm  ov009
 *   func_02171F68  0x02171F68  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_02172B08  0x02172B08  arm  ov009
 *
 * The DWARF declares DWCi_CancelReservation(void); every call site here loads
 * r0 = 0 first, so the file passes the argument.
 */

typedef unsigned char u8;

typedef struct GTI2Socket GTI2Socket;

typedef struct DWCstMatchControl {
    char pad0[4];
    GTI2Socket **pGt2Socket;    /* +0x004 */
    char pad8[0x14 - 8];
    u8 qr2MatchType;            /* +0x014 */
    char pad15[0x618 - 0x15];
    int nnCookie;               /* +0x618 */
    int state;                  /* +0x61c */
    char pad620[0x62a - 0x620];
    u8 cancelState;             /* +0x62a */
    char pad62b[0x67c - 0x62b];
    int reservation;            /* +0x67c */
    int w680;                   /* +0x680 */
} DWCstMatchControl;

extern int func_02175F3C(void);
extern void func_02172A58(void);
extern int func_0216BB6C(void);
extern void func_02199FB4(int cookie);
extern void func_02195DE4(int *p);
extern int func_02171F68(int arg);
extern int func_021719A4(int error);
extern int func_02172B08(void);

static void func_021728B8(void)
{
    int anyGT2ConnectionExist;
    int result;

    ((DWCstMatchControl *)func_02175F3C())->w680 = 0;
    anyGT2ConnectionExist = 0;
    if (((DWCstMatchControl *)func_02175F3C())->state == 22) {
        func_02172A58();
        return;
    }
    if (func_0216BB6C())
        anyGT2ConnectionExist = 1;
    ((DWCstMatchControl *)func_02175F3C())->cancelState = 1;

    if (((DWCstMatchControl *)func_02175F3C())->qr2MatchType == 3) {
        if (((DWCstMatchControl *)func_02175F3C())->nnCookie) {
            func_02199FB4(((DWCstMatchControl *)func_02175F3C())->nnCookie);
            ((DWCstMatchControl *)func_02175F3C())->nnCookie = 0;
        }
        ((DWCstMatchControl *)func_02175F3C())->cancelState = 1;
        if (anyGT2ConnectionExist) {
            func_02195DE4((int *)(*((DWCstMatchControl *)func_02175F3C())->pGt2Socket));
        } else {
            result = func_021719A4(func_02171F68(0));
            if (result)
                return;
        }
        func_02172A58();
        return;
    }

    if (((DWCstMatchControl *)func_02175F3C())->state == 3 || ((DWCstMatchControl *)func_02175F3C())->state == 4 ||
        ((DWCstMatchControl *)func_02175F3C())->state == 5 || ((DWCstMatchControl *)func_02175F3C())->state == 6 ||
        ((DWCstMatchControl *)func_02175F3C())->state == 14 || ((DWCstMatchControl *)func_02175F3C())->state == 15) {
        if (((DWCstMatchControl *)func_02175F3C())->reservation) {
            result = func_021719A4(func_02171F68(0));
            if (result)
                return;
        }
        result = func_021719A4(func_02172B08());
        if (result)
            return;
    }
    if (((DWCstMatchControl *)func_02175F3C())->nnCookie) {
        func_02199FB4(((DWCstMatchControl *)func_02175F3C())->nnCookie);
        ((DWCstMatchControl *)func_02175F3C())->nnCookie = 0;
    }
    if (anyGT2ConnectionExist) {
        ((DWCstMatchControl *)func_02175F3C())->cancelState = 1;
        func_02195DE4((int *)(*((DWCstMatchControl *)func_02175F3C())->pGt2Socket));
    }
    func_02172A58();
}
