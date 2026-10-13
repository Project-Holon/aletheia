/*
 * function: func_02174ED0
 * address:  0x02174ED0
 * packet:   pkt_ov009_02174ED0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_QR2ClientMsgCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWC_GetState                0x0216B994 arm   ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_02082D44                0x02082D44 arm
 *   func_020949F4                0x020949F4 arm
 *   func_021702A0                0x021702A0 arm   ov009
 *   g_021A2188                   0x021A2188 data
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl {
    u8 pad0[0x14];
    u8 f14;
};

struct DWCstBinaryMessage {
    char keyword[4];
    int identifier;
    u8 command;
    u8 size;
    u16 port;
    u32 ip;
    int pid;
};

extern int DWC_GetState(void);
extern int func_02175F3C(void);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int func_021702A0(u8 command, int srcPid, u32 srcIP, u16 srcPort, u32 *data, int len);
extern char g_021A2188[];

void func_02174ED0(char *data, int len)
{
    struct DWCstBinaryMessage sbMsg;
    u32 payload[32];
    int boolResult;
    int offset = 0;

    if (DWC_GetState() != 4) {
        if (DWC_GetState() != 5)
            return;
        if (((struct DWCstMatchControl *)func_02175F3C())->f14 != 2 && ((struct DWCstMatchControl *)func_02175F3C())->f14 != 3)
            return;
    }
    while (offset + 0x14 <= len) {
        func_02082D44(data, &sbMsg, 0x14);
        *(volatile int *)&sbMsg.pid = sbMsg.pid;
        if (func_020949F4((const u8 *)sbMsg.keyword, (const u8 *)g_021A2188, 4) != 0 || sbMsg.identifier != 0x5a)
            return;
        func_02082D44(data + 0x14, payload, sbMsg.size);
        boolResult = func_021702A0(sbMsg.command, sbMsg.pid, sbMsg.ip, sbMsg.port, payload, sbMsg.size >> 2);
        if (boolResult == 0)
            return;
        offset += sbMsg.size + 0x14;
    }
}
