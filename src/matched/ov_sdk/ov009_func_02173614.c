/*
 * function: func_02173614
 * address:  0x02173614
 * packet:   pkt_ov009_02173614
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendCancelMatchSynCommand (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_020870D0  0x020870D0  arm
 */

extern int func_02175F3C(void);
extern char *func_021763AC(int profileID);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_021719A4(int result);
extern unsigned long long func_020870D0(void);

int func_02173614(int profileID, unsigned char command)
{
    char *pNodeInfo;
    int result;
    int len;
    unsigned long senddata[1];

    if (command != 13) {
        len = 0;
    } else {
        senddata[0] = *(unsigned long *)(func_02175F3C() + 0x680);
        len = 1;
    }
    pNodeInfo = func_021763AC(profileID);
    if (!pNodeInfo)
        return 0;
    result = func_0216FF2C(command, profileID, *(int *)(pNodeInfo + 4), *(unsigned short *)(pNodeInfo + 12), (const unsigned int *)senddata, len);
    if (func_021719A4(result))
        return 0;
    {
        unsigned long long t = func_020870D0();
        *(unsigned long long *)(func_02175F3C() + 0x660) = t;
    }
    return 1;
}
