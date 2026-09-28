/*
 * function: DWCi_AC_CallBackWCM
 * address:  0x0205B148
 * packet:   pkt_0205A2DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * TwlDWC libdwcac callback.o.
 */
extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern void DWCi_AC_GetBeacon(long parameter);

typedef union {
    long n;
    void *p;
} WCMNoticeParameter;

typedef struct {
    short notify;
    short result;
    WCMNoticeParameter parameter[3];
} WCMNotice;

typedef struct {
    unsigned char pad[0x14c4];
    unsigned char field;
} ACWORK;

void func_0205B148(WCMNotice *notice)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(16);

    if (notice->notify == 5) {
        if (notice->result == 0) {
            return;
        }
        switch (notice->parameter[1].n) {
        case 13:
            wk->field = 1;
            break;
        case 15:
            wk->field = 2;
            break;
        case 17:
            wk->field = 3;
            break;
        default:
            wk->field = 4;
            break;
        }
    } else if (notice->notify == 7) {
        DWCi_AC_GetBeacon(notice->parameter[0].n);
    }
}
