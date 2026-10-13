/*
 * function: DWCi_SendMatchCommand
 * address:  0x0216FF2C
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_SendMatchCommand: sends a match command over gt2, as a GP buddy message, or through the server browser.
 *
 * symbols:
 *   DWCi_CanSendMatchCommandDirect  0x0216FEF0  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID  0x021763AC  arm  ov009
 *   DWCi_EncodeBinaryMsgCommand  0x021700C8  arm  ov009
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 *   func_02177848  0x02177848  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021861A8  0x021861A8  arm  ov009
 *   DWC_Base64Encode  0x02059B40  arm
 *   DWCi_SendGPBuddyMsgCommand  0x02170200  arm  ov009
 *   DWCi_SendSBMsgCommand  0x02170168  arm  ov009
 *   OS_GetTick  0x020870D0  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 */

typedef struct {
    char id[5];
} MatchId;

typedef struct {
    MatchId id;
    unsigned char pad[3];
    unsigned char command;
    unsigned char len;
    unsigned short port;
    int ip;
    int pid;
    unsigned int data[32];
} MatchCtrl;

extern int DWCi_CanSendMatchCommandDirect(unsigned char command, int pid);
struct DWCstBinaryMessage;
extern char *DWCi_NodeInfoList_GetNodeInfoForProfileID(int pid);
extern void DWCi_EncodeBinaryMsgCommand(struct DWCstBinaryMessage *message, unsigned char command, unsigned long *data, int len);
extern unsigned char DWC_GetMyAID(void);
extern int func_02177848(unsigned char from, unsigned char to, const void *data, int size, int flag);
extern char *func_02175F3C(void);
extern int func_021861A8(void *conn, int pid);
extern int DWC_Base64Encode(const void *src, int srclen, char *dst, int dstlen);
extern int DWCi_SendGPBuddyMsgCommand(void *conn, unsigned char command, int pid, const char *data);
extern int DWCi_SendSBMsgCommand(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern unsigned long long OS_GetTick(void);
extern void MIi_CpuCopy32(const void *src, void *dst, int size);

int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len)
{
    MatchCtrl ctrl;
    char buf[0x200];
    unsigned char *node;
    int result;
    int n;
    unsigned long long t;

    if (DWCi_CanSendMatchCommandDirect(command, pid) != 0) {
        node = (unsigned char *)DWCi_NodeInfoList_GetNodeInfoForProfileID(pid);
        DWCi_EncodeBinaryMsgCommand((struct DWCstBinaryMessage *)(&ctrl), command, (long unsigned int *)data, len);
        func_02177848(DWC_GetMyAID(), node[0x16], &ctrl, ctrl.len + 0x14, 0);
        result = 0;
    } else if (func_021861A8(*(void **)func_02175F3C(), pid) != 0) {
        n = 0;
        if (data != 0 && len != 0) {
            n = DWC_Base64Encode(data, len * 4, buf, 0x200);
        }
        buf[n] = 0;
        result = DWCi_SendGPBuddyMsgCommand(*(void **)func_02175F3C(), command, pid, buf);
    } else {
        if (ip == 0) {
            node = (unsigned char *)DWCi_NodeInfoList_GetNodeInfoForProfileID(pid);
            port = *(unsigned short *)(node + 0xc);
            ip = *(unsigned int *)(node + 4);
        }
        result = DWCi_SendSBMsgCommand(command, ip, port, data, len);
    }
    if (command == 2 || command == 6 || command == 8 || command == 9) {
        *(unsigned char *)(func_02175F3C() + 0x6d8) = command;
        *(unsigned short *)(func_02175F3C() + 0x6da) = port;
        *(unsigned int *)(func_02175F3C() + 0x6dc) = ip;
        *(int *)(func_02175F3C() + 0x760) = pid;
        *(int *)(func_02175F3C() + 0x764) = len;
        t = OS_GetTick();
        *(unsigned long long *)(func_02175F3C() + 0x768) = t;
        if (data != 0 && len != 0) {
            MIi_CpuCopy32(data, func_02175F3C() + 0x6e0, len * 4);
        }
    }
    return result;
}
