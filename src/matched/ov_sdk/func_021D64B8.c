/*
 * function: DWCi_IPTlInit
 * address:  0x021D64B8
 * packet:   pkt_021D64B8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm
 *   TP_GetUserInfo  0x0208A998  arm
 *   OS_Terminate  0x02088234  arm
 *   TP_SetCalibrateParam  0x0208AA2C  arm
 *   TP_RequestAutoSamplingStartAsync  0x0208AC0C  arm
 *   TP_WaitBusy  0x0208B220  arm
 *   TP_CheckError  0x0208B238  arm
 *   DWCi_IPTlUpdate  0x021D656C  arm
 *   gInputStatics     0x021DE688  data
 */

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
struct TPCalibrateParam;
extern int TP_GetUserInfo(struct TPCalibrateParam *calibrate);
extern void  OS_Terminate(void);
extern void TP_SetCalibrateParam(const struct TPCalibrateParam *param);
extern void  TP_RequestAutoSamplingStartAsync(int a, int b, void *c, int d);
extern void TP_WaitBusy(unsigned int command_flgs);
extern unsigned int TP_CheckError(unsigned int command_flgs);
extern void  DWCi_IPTlUpdate(void);
extern void *gInputStatics[];

void DWCi_IPTlInit(void)
{
    char buf[8];

    gInputStatics[1] = DWCi_HEAPlAllocEx(0x3a, 4);
    if (TP_GetUserInfo((struct TPCalibrateParam *)buf) == 0)
        OS_Terminate();
    TP_SetCalibrateParam((const struct TPCalibrateParam *)buf);
    TP_RequestAutoSamplingStartAsync(0, 4, gInputStatics[1], 5);
    TP_WaitBusy(2);
    if (TP_CheckError(2) != 0)
        OS_Terminate();
    DWCi_IPTlUpdate();
}
