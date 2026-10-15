/*
 * function: DWCs_RecvDataBody
 * address:  0x02177CE4
 * packet:   pkt_ov009_02177CE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_RecvDataBody (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCs_GetRecvState  0x021777A4 arm
 *   DWCi_SetError      0x02059F54 arm
 *   MI_CpuCopy8        0x02082D44 arm
 *   OS_GetTick         0x020870D0 arm
 *   gDwcTransInfo         0x021AB180 data
 */

extern int DWCs_GetRecvState(unsigned char aid);
extern void DWCi_SetError(int error, int errorCode);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern unsigned long long OS_GetTick(void);
extern char gDwcTransInfo[];

typedef void (*DWCiRecvCallback_t)(unsigned char aid, void *buffer, int size, int arg);

void DWCs_RecvDataBody(unsigned char aid, void *message, int size)
{
    char *connection;
    int totalSize;

    connection = *(char **)gDwcTransInfo + aid * 0x38;
    if (DWCs_GetRecvState(aid) == 2) {
        if (*(int *)(connection + 0x10) + size > *(int *)(connection + 8)) {
            DWCi_SetError(6, 0xfffe82ac);
            return;
        }
        MI_CpuCopy8(message, *(char **)(connection + 4) + *(int *)(connection + 0x10),
            size);
    }
    *(int *)(connection + 0x10) += size;
    totalSize = *(int *)(connection + 0x18);
    if (*(int *)(connection + 0x10) == totalSize) {
        *(char *)(connection + 0x1d) = 1;
        *(int *)(connection + 0x10) = 0;
        *(int *)(connection + 0x18) = 0;
        if (*(DWCiRecvCallback_t *)(*(char **)gDwcTransInfo + 0x704) != 0) {
            (*(DWCiRecvCallback_t *)(*(char **)gDwcTransInfo + 0x704))(aid,
                *(void **)(connection + 4), totalSize,
                *(int *)(*(char **)gDwcTransInfo + 0x714));
        }
    }
    if (*(int *)(*(char **)gDwcTransInfo + 0x708) != 0 &&
        *(int *)(connection + 0x2c) != 0) {
        unsigned long long tick = OS_GetTick();

        *(unsigned long long *)(connection + 0x24) = tick;
    }
}
