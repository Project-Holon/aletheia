/*
 * file:     unit_02174D04_p02.c
 * unit:     yes
 * function: func_02174E10, func_02174ED0
 * address:  0x02174E10
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
 *   DWC_GetState                    0x0216B994 arm
 *   DWCi_GetMatchCnt                0x02175F3C arm
 *   MI_CpuCopy8                     0x02082D44 arm
 *   DWCi_ProcessRecvMatchCommand    0x021702A0 arm
 *   func_0216B994                0x0216B994 arm   ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_02082D44                0x02082D44 arm
 *   func_020949F4                0x020949F4 arm
 *   func_021702A0                0x021702A0 arm   ov009
 *   g_021A2188                   0x021A2188 data
 */
struct DWCstBinaryMessage_02174E10 {
    unsigned long unk00;
    unsigned long type;
    unsigned char command;
    unsigned char length;
    unsigned short port;
    unsigned long ip;
    unsigned long pid;
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

struct DWCstMatchControl {
    u8 pad0[0x14];
    u8 f14;
};

struct DWCstBinaryMessage_02174ED0 {
    char keyword[4];
    int identifier;
    u8 command;
    u8 size;
    u16 port;
    u32 ip;
    int pid;
};

extern int DWC_GetState(void);
extern char *DWCi_GetMatchCnt(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int DWCi_ProcessRecvMatchCommand(unsigned char command, int srcPid,
    unsigned long srcIP, unsigned short srcPort, unsigned long *data, int len);
extern int func_0216B994(void);
extern int func_02175F3C(void);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int func_021702A0(u8 command, int srcPid, u32 srcIP, u16 srcPort, u32 *data, int len);
void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len);
void func_02174ED0(char *data, int len);
extern char g_021A2188[];


void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len)
{
    unsigned long payload[32];
    struct DWCstBinaryMessage_02174E10 binaryCommand;

    if (DWC_GetState() == 4 ||
        (DWC_GetState() == 5 && (*(unsigned char *)(DWCi_GetMatchCnt() + 0x14) == 2 ||
                                 *(unsigned char *)(DWCi_GetMatchCnt() + 0x14) == 3))) {
        MI_CpuCopy8(data, &binaryCommand, 0x14);
        binaryCommand.pid = (unsigned long)(binaryCommand.pid);
        if (binaryCommand.type != 0x5a || len != binaryCommand.length + 0x14)
            return;
        MI_CpuCopy8((char *)data + 0x14, payload, binaryCommand.length);
        DWCi_ProcessRecvMatchCommand(binaryCommand.command, binaryCommand.pid,
            binaryCommand.ip, binaryCommand.port, payload, binaryCommand.length >> 2);
    }
}


/*
 * sdk:      DWCi_QR2ClientMsgCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void func_02174ED0(char *data, int len)
{
    struct DWCstBinaryMessage_02174ED0 sbMsg;
    u32 payload[32];
    int boolResult;
    int offset = 0;

    if (func_0216B994() != 4) {
        if (func_0216B994() != 5)
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
