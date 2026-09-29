/*
 * function: func_0217576C
 * address:  0x0217576C
 * packet:   pkt_ov009_0217576C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendServerPolling (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_0216BA08                0x0216BA08 arm   ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   _ll_udiv                     0x0209C00C arm
 *   func_0216B908                0x0216B908 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_02176344                0x02176344 arm   ov009
 *   func_0216FF2C                0x0216FF2C arm   ov009
 *   func_021719A4                0x021719A4 arm   ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

struct DWCstMatchControl {
    u8 pad0[0x61c];
    int f61c;
    u8 pad1[0x678 - 0x620];
    u32 f678;
    u8 pad2[0x7a0 - 0x67c];
    u64 f7a0;
    u8 pad3[0x7c8 - 0x7a8];
    u32 f7c8;
};

struct DWCstNodeInfo {
    int profileID;
    u32 ip;
    u8 pad0[0xc - 0x8];
    u16 port;
};

extern int func_0216BA08(void);
extern struct DWCstMatchControl *func_02175F3C(void);
extern u64 func_020870D0(void);
extern u32 func_0216B908(void);
extern int func_0217603C(void);
extern struct DWCstNodeInfo *func_0217637C(int index);
extern struct DWCstNodeInfo *func_02176344(void);
extern int func_0216FF2C(u8 command, int profileID, u32 ip, u16 port, u32 *data, int len);
extern int func_021719A4(int error);

int func_0217576C(int immediate)
{
    u32 sendData[3];
    struct DWCstNodeInfo *pNodeInfo;
    int result;
    int i;
    u64 tick;

    if (!func_0216BA08())
        return 1;
    if (func_02175F3C()->f61c == 0x13 || func_02175F3C()->f61c == 0x14)
        return 1;
    if (immediate == 0) {
        tick = func_020870D0();
        if (((tick - func_02175F3C()->f7a0) * 64) / 33514 <= 15000)
            goto done;
    }
    sendData[0] = func_02175F3C()->f678;
    sendData[1] = func_0216B908();
    sendData[2] = func_02175F3C()->f7c8;
    for (i = 0; i < func_0217603C(); i++) {
        pNodeInfo = func_0217637C(i);
        if (pNodeInfo != func_02176344()) {
            result = func_0216FF2C(0x83, pNodeInfo->profileID, pNodeInfo->ip, pNodeInfo->port, sendData, 3);
            if (func_021719A4(result))
                return -1;
        }
    }
    tick = func_020870D0();
    func_02175F3C()->f7a0 = tick;
done:
    return 1;
}
