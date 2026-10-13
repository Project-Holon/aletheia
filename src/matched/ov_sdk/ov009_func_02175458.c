/*
 * function: func_02175458
 * address:  0x02175458
 * packet:   pkt_ov009_02175458
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendServerDownQuery (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_02173CFC  0x02173CFC  arm  ov009
 */

extern int func_02175F3C(void);
extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern int DWC_GetAIDBitmap(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_021719A4(int result);
extern void func_02173CFC(void);

int func_02175458(void)
{
    int i;
    int result;
    int hostCount;
    unsigned long aidBitmap;
    char *pNodeInfo;
    unsigned char command;

    func_02175F3C();
    hostCount = func_0217603C();
    for (i = 1; i < hostCount; i++) {
        pNodeInfo = func_0217637C(i);
        aidBitmap = DWC_GetAIDBitmap();
        if (*(unsigned int *)(func_02175F3C() + 0x788) & (1 << *(unsigned char *)(pNodeInfo + 0x16)))
            command = 0x55;
        else
            command = 0x52;
        result = func_0216FF2C(command, *(int *)pNodeInfo, *(int *)(pNodeInfo + 4), *(unsigned short *)(pNodeInfo + 12), (const unsigned int *)(&aidBitmap), 1);
        if (func_021719A4(result))
            return 0;
    }
    func_02173CFC();
    return 1;
}
