/*
 * function: WCM_ConnectAsync
 * address:  0x021652A4
 * packet:   pkt_ov009_021652A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_ConnectAsync (libwcm.TWL.HYB.a(system.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   WCMi_GetSystemWork         0x021657C8  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   MI_CpuCopy8           0x02082D44  arm
 *   MI_CpuFill8           0x02082BCC  arm
 *   WCM_UpdateOption         0x021656D0  arm  ov009
 *   WCMi_WmifConnectAsync         0x02166B2C  arm  ov009
 *   OS_IsRunOnTwl         0x02085D3C  arm
 *   WCMi_NwmifConnectAsync         0x02731BF8  arm  twl
 *
 * The 0x40 bound reads keyLen from the work area before it is stored, as the object does.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct WCMPrivacy {
    u8 key[80];
    u8 mode;
    union {
        u8 keyId;
        u8 keyLen;
    } u;
    u8 reserved[2];
} WCMPrivacy;

typedef struct WCMWork {
    u8 pad0[0x1240];
    WCMPrivacy privacyDesc;         /* +0x1240 */
    u8 pad1[0x12DE - 0x1294];
    u8 phase;                       /* +0x12DE */
    u8 deviceId;                    /* +0x12DF */
    u8 bssDesc[0xC0];               /* +0x12E0 */
} WCMWork;

typedef struct WCMWepDesc {
    u8 mode;
    union {
        u8 keyId;
        u8 keyLen;
    } u;
    u8 key[80];
} WCMWepDesc;

extern unsigned long OS_DisableInterrupts(void);
extern int WCMi_GetSystemWork(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned long WCM_UpdateOption(unsigned long option);
extern long WCMi_WmifConnectAsync(void);
extern int OS_IsRunOnTwl(void);
extern long WCMi_NwmifConnectAsync();

long WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option)
{
    unsigned long e;
    WCMWork *wcmw;
    long wcmResult;
    WCMWepDesc *privacyDesc;

    e = OS_DisableInterrupts();
    wcmw = (WCMWork *)WCMi_GetSystemWork();
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->phase) {
    case 3:
        if (bssDesc == 0) {
            OS_RestoreInterrupts(e);
            return 1;
        }
        if (((u16 *)bssDesc)[0x1E] != 0) {
            OS_RestoreInterrupts(e);
            return 1;
        }
        privacyDesc = (WCMWepDesc *)wepDesc;
        if (privacyDesc != 0) {
            if ((privacyDesc->mode <= 3 && privacyDesc->u.keyId >= 4) || wcmw->privacyDesc.u.keyLen > 0x40) {
                OS_RestoreInterrupts(e);
                return 1;
            }
            wcmw->privacyDesc.mode = privacyDesc->mode;
            if (privacyDesc->mode == 0) {
                MI_CpuFill8(wcmw->privacyDesc.key, 0, 0x50);
            } else if (privacyDesc->mode <= 3) {
                wcmw->privacyDesc.u.keyId = privacyDesc->u.keyId;
                MI_CpuCopy8(privacyDesc->key, wcmw->privacyDesc.key, 0x50);
            } else {
                wcmw->privacyDesc.u.keyLen = privacyDesc->u.keyLen;
                MI_CpuCopy8(privacyDesc->key, wcmw->privacyDesc.key, wcmw->privacyDesc.u.keyLen);
            }
        } else {
            MI_CpuFill8(&wcmw->privacyDesc, 0, 0x54);
        }
        MI_CpuCopy8(bssDesc, wcmw->bssDesc, 0xC0);
        WCM_UpdateOption(option);
        break;
    case 8:
        OS_RestoreInterrupts(e);
        return 2;
    case 9:
        OS_RestoreInterrupts(e);
        return 0;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->deviceId) {
    case 1:
        wcmResult = WCMi_WmifConnectAsync();
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifConnectAsync();
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}
