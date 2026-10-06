/*
 * function: func_0216FF2C
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
 *   func_0216FEF0  0x0216FEF0  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 *   func_021700C8  0x021700C8  arm  ov009
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_02177848  0x02177848  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021861A8  0x021861A8  arm  ov009
 *   DWC_Base64Encode  0x02059B40  arm
 *   func_02170200  0x02170200  arm  ov009
 *   func_02170168  0x02170168  arm  ov009
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

extern int func_0216FEF0(unsigned char command, int pid);
struct DWCstBinaryMessage;
extern char *func_021763AC(int pid);
extern void func_021700C8(struct DWCstBinaryMessage *message, unsigned char command, unsigned long *data, int len);
extern unsigned char func_0216B838(void);
extern int func_02177848(unsigned char from, unsigned char to, const void *data, int size, int flag);
extern char *func_02175F3C(void);
extern int func_021861A8(void *conn, int pid);
extern int DWC_Base64Encode(const void *src, int srclen, char *dst, int dstlen);
extern int func_02170200(void *conn, unsigned char command, int pid, const char *data);
extern int func_02170168(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern unsigned long long OS_GetTick(void);
extern void MIi_CpuCopy32(const void *src, void *dst, int size);

int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len)
{
    MatchCtrl ctrl;
    char buf[0x200];
    unsigned char *node;
    int result;
    int n;
    unsigned long long t;

    if (func_0216FEF0(command, pid) != 0) {
        node = (unsigned char *)func_021763AC(pid);
        func_021700C8((struct DWCstBinaryMessage *)(&ctrl), command, (long unsigned int *)data, len);
        func_02177848(func_0216B838(), node[0x16], &ctrl, ctrl.len + 0x14, 0);
        result = 0;
    } else if (func_021861A8(*(void **)func_02175F3C(), pid) != 0) {
        n = 0;
        if (data != 0 && len != 0) {
            n = DWC_Base64Encode(data, len * 4, buf, 0x200);
        }
        buf[n] = 0;
        result = func_02170200(*(void **)func_02175F3C(), command, pid, buf);
    } else {
        if (ip == 0) {
            node = (unsigned char *)func_021763AC(pid);
            port = *(unsigned short *)(node + 0xc);
            ip = *(unsigned int *)(node + 4);
        }
        result = func_02170168(command, ip, port, data, len);
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
