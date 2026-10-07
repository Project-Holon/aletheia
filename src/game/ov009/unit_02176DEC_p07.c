/*
 * file:     unit_02176DEC_p07.c
 * unit:     yes
 * function: func_02177C1C, func_02177CE4
 * address:  0x02177C1C
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
 *   DWCs_GetRecvState  0x021777A4 arm
 *   DWCs_DecodeHeader  0x021771E0 arm
 *   MI_CpuCopy8        0x02082D44 arm
 *   g_021AB180         0x021AB180 data
 *   DWCi_SetError      0x02059F54 arm
 *   OS_GetTick         0x020870D0 arm
 */
struct DWCstTransportHeader {
    unsigned long size;
    unsigned short type;
    unsigned short pad;
};

typedef void (*DWCiRecvCallback_t)(unsigned char aid, void *buffer, int size, int arg);

extern int DWCs_GetRecvState(unsigned char aid);
extern unsigned short DWCs_DecodeHeader(void *message);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void DWCi_SetError(int error, int errorCode);
extern unsigned long long OS_GetTick(void);
void DWCs_RecvDataHeader(unsigned char aid, void *message, int size);
void DWCs_RecvDataBody(unsigned char aid, void *message, int size);
extern char g_021AB180[];


void DWCs_RecvDataHeader(unsigned char aid, void *message, int size)
{
    struct DWCstTransportHeader header;
    char *connection;
    unsigned short type;

    connection = *(char **)g_021AB180 + aid * 0x38;
    *(char *)(connection + 0x1e) = DWCs_GetRecvState(aid);
    type = DWCs_DecodeHeader(message);
    switch (type) {
    case 1:
        if (size != 8)
            return;
        MI_CpuCopy8(message, &header, 8);
        {
            unsigned long s = header.size;

            header.size = s;
            *(int *)(connection + 0x18) = s;
        }
        *(int *)(connection + 0x10) = 0;
        if (*(int *)(connection + 4) != 0 &&
            *(int *)(connection + 8) >= *(int *)(connection + 0x18))
            *(char *)(connection + 0x1d) = 2;
        else
            *(char *)(connection + 0x1d) = 4;
        break;
    case 2:
    case 3:
    case 4:
        *(char *)(connection + 0x1d) = 3;
        break;
    }
    *(unsigned short *)(connection + 0x22) = type;
}


void DWCs_RecvDataBody(unsigned char aid, void *message, int size)
{
    char *connection;
    int totalSize;

    connection = *(char **)g_021AB180 + aid * 0x38;
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
        if (*(DWCiRecvCallback_t *)(*(char **)g_021AB180 + 0x704) != 0) {
            (*(DWCiRecvCallback_t *)(*(char **)g_021AB180 + 0x704))(aid,
                *(void **)(connection + 4), totalSize,
                *(int *)(*(char **)g_021AB180 + 0x714));
        }
    }
    if (*(int *)(*(char **)g_021AB180 + 0x708) != 0 &&
        *(int *)(connection + 0x2c) != 0) {
        unsigned long long tick = OS_GetTick();

        *(unsigned long long *)(connection + 0x24) = tick;
    }
}
