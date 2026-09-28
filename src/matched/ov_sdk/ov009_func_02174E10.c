/*
 * function: DWCi_HandleGT2UnreliableMatchCommandMessage
 * address:  0x02174E10
 * packet:   pkt_ov009_02174E10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HandleGT2UnreliableMatchCommandMessage (libdwcmatch.TWL.HYB.a dwc_match.o)
 * symbols:
 *   DWC_GetState                    0x0216B994 arm
 *   DWCi_GetMatchCnt                0x02175F3C arm
 *   MI_CpuCopy8                     0x02082D44 arm
 *   DWCi_ProcessRecvMatchCommand    0x021702A0 arm
 */

extern int DWC_GetState(void);
extern char *DWCi_GetMatchCnt(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int DWCi_ProcessRecvMatchCommand(unsigned char command, int srcPid,
    unsigned long srcIP, unsigned short srcPort, unsigned long *data, int len);

struct DWCstBinaryMessage {
    unsigned long unk00;
    unsigned long type;
    unsigned char command;
    unsigned char length;
    unsigned short port;
    unsigned long ip;
    unsigned long pid;
};

void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len)
{
    unsigned long payload[32];
    struct DWCstBinaryMessage binaryCommand;

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
