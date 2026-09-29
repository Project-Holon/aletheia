/*
 * function: func_021F5BE0
 * address:  0x021F5BE0
 * packet:   pkt_ov107_021F5BE0
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_StartCommon (libmb.TWL.HYB.a(mb_wm_base.o))
 *
 * symbols:
 *   func_021F6148 0x021F6148 arm ov107
 *   func_0208F370 0x0208F370 arm
 *   func_0208EAC8 0x0208EAC8 arm
 *   func_021F4628 0x021F4628 arm ov107
 *   g_021F6F90 0x021F6F90 data
 */

typedef struct {
    unsigned short dmaNo;
    unsigned short pad;
    void *wmSysBuf;
    int pad2;
    unsigned char *work;
    unsigned char *ext;
} WmBase;

extern WmBase g_021F6F90;

extern void func_021F6148(unsigned short time);
extern int func_0208F370(void *wmSysBuf, void *callback, unsigned short dmaNo);
extern int func_0208EAC8(void *callback);
extern void func_021F4628(void);

int func_021F5BE0(void)
{
    int errcode = 0;

    *(unsigned short *)(g_021F6F90.work + 0x528) = errcode;
    *(unsigned short *)(g_021F6F90.work + 0x52A) = errcode;
    *(unsigned short *)(g_021F6F90.work + 0x526) = errcode;
    *(unsigned short *)(g_021F6F90.work + 0x548) = errcode;
    func_021F6148(0x1E);
    if (*(int *)(g_021F6F90.ext + 0x1320) == 0) {
        do {
            errcode = func_0208F370(g_021F6F90.wmSysBuf, *(void **)(g_021F6F90.work + 0x508), g_021F6F90.dmaNo);
        } while (errcode == 4);
        if (errcode != 2) {
            return 8;
        }
        func_0208EAC8(*(void **)(g_021F6F90.work + 0x508));
        g_021F6F90.work[0x50D] = 1;
        return 0;
    }
    func_0208EAC8(*(void **)(g_021F6F90.work + 0x508));
    g_021F6F90.work[0x50D] = 1;
    func_021F4628();
    return errcode;
}
