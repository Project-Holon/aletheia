/*
 * function: func_021D4214
 * address:  0x021D4214
 * packet:   pkt_ov016_021D4214
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _DWCi_MOV_WaitandDownloadandBoot_Child (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   DWCi_MOV_MBP_GetState 0x021D2780 arm ov016
 *   DWCi_MOV_MBP_Start 0x021D1E54 arm ov016
 *   DWCi_MOV_MBP_GetChildBmp 0x021D2794 arm ov016
 *   DWCi_MOV_MBP_IsBootableAll 0x021D22AC arm ov016
 *   DWCi_MOV_MBP_StartRebootAll 0x021D2314 arm ov016
 *   DWCi_MOV_MBP_Cancel 0x021D240C arm ov016
 *   func_021D3250 0x021D3250 arm ov016
 *   DWCi_MOV_WH_End 0x021D3AC8 arm ov016
 *   gDwcMoveidWork 0x021DE668 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    char pad0[0xa90];
    u8 state;
} WkS;

extern WkS *gDwcMoveidWork;

extern u16 DWCi_MOV_MBP_GetState(void);
extern void DWCi_MOV_MBP_Start(void *gameInfo, u16 channel);
extern u16 DWCi_MOV_MBP_GetChildBmp(int bmpType);
extern int DWCi_MOV_MBP_IsBootableAll(void);
extern void DWCi_MOV_MBP_StartRebootAll(void);
extern void DWCi_MOV_MBP_Cancel(void);
extern unsigned int func_021D3250(void);
extern int DWCi_MOV_WH_End(void);

void func_021D4214(void)
{
    switch (DWCi_MOV_MBP_GetState()) {
    case 1:
        DWCi_MOV_MBP_Start((char *)gDwcMoveidWork + 0x2b4 + 0x800, *(u16 *)((char *)gDwcMoveidWork + 0x600 + 0x4a));
        return;
    case 2:
        if (DWCi_MOV_MBP_GetChildBmp(2) != 0) {
            gDwcMoveidWork->state = 5;
            return;
        }
        if (DWCi_MOV_MBP_GetChildBmp(3) != 0 || DWCi_MOV_MBP_GetChildBmp(4) != 0) {
            gDwcMoveidWork->state = 6;
            return;
        }
        if (gDwcMoveidWork->state != 5)
            return;
        if (DWCi_MOV_MBP_GetChildBmp(2) == 0)
            gDwcMoveidWork->state = 0xd;
        return;
    case 3:
        if (DWCi_MOV_MBP_IsBootableAll() != 0) {
            DWCi_MOV_MBP_StartRebootAll();
            return;
        }
        if (gDwcMoveidWork->state == 6 || gDwcMoveidWork->state == 7) {
            if (DWCi_MOV_MBP_GetChildBmp(3) == 0)
                gDwcMoveidWork->state = 0x12;
        }
        return;
    case 5:
        gDwcMoveidWork->state = 7;
        return;
    case 7:
        DWCi_MOV_MBP_Cancel();
        gDwcMoveidWork->state = 1;
        return;
    case 0:
        switch (func_021D3250()) {
        case 1:
            DWCi_MOV_WH_End();
            break;
        case 0:
            gDwcMoveidWork->state = 0x1f;
            break;
        case 3:
            break;
        default:
            gDwcMoveidWork->state = 0x1f;
            break;
        }
        return;
    }
}
