/*
 * file:     unit_02176DEC_p04.c
 * unit:     yes
 * function: func_02177160, func_02177188, func_021771B0, func_021771E0, func_0217721C, func_02177270, func_021772B8, func_021772DC, func_021772F8
 * address:  0x02177160
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
 *   g_021AB180  0x021AB180  data
 *   strncpy      0x02094860 arm
 *   g_021A2344   0x021A2344 data
 *   MI_CpuCopy8  0x02082D44 arm
 *   memcmp       0x020923F0 arm
 *   DWCi_NodeInfoList_GetCount  0x0217603C arm
 *   OS_GetTick   0x020870D0 arm
 *   MI_CpuFill8                    0x02082BCC arm
 *   DWC_SetConnectionKeepAliveTime 0x021772B8 arm
 *   DWCi_InitReliableQueue         0x02176B68 arm
 */
extern void strncpy(char *dst, const char *src, int n);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int memcmp(const void *a, const void *b, unsigned int n);
extern int DWCi_NodeInfoList_GetCount(void);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWC_SetConnectionKeepAliveTime(unsigned long time);
extern void DWCi_InitReliableQueue(void);
int func_02177160(int a, int b);
int func_02177188(int a, int b);
void DWCs_EncodeHeader(void *header, unsigned short type, int size);
unsigned short DWCs_DecodeHeader(void *message);
long DWCs_GetRequiredHeaderSize(unsigned short type);
int DWC_SetRecvTimeoutTime(unsigned char aid, unsigned long time);
int func_021772B8(int v);
int func_021772DC(void);
void DWCi_InitTransport(char *info);
extern char g_021AB180[];
extern char g_021A2344[];


int func_02177160(int a, int b)
{
    int *p = *(int **)g_021AB180;

    if (p == 0)
        return 0;
    *(int *)((char *)p + 0x704) = a;
    *(int *)((char *)*(int **)g_021AB180 + 0x714) = b;
    return 1;
}


/*
 * Word at +0x708 of the block the module pointer holds, and the block again at
 * +0x718 of the second copy the pointer holds, or zero when there is no block.
 */
int func_02177188(int a, int b)
{
    int *p = *(int **)g_021AB180;

    if (p == 0)
        return 0;
    *(int *)((char *)p + 0x708) = a;
    *(int *)((char *)*(int **)g_021AB180 + 0x718) = b;
    return 1;
}


void DWCs_EncodeHeader(void *header, unsigned short type, int size)
{
    char *h = header;

    strncpy(h + 6, g_021A2344, 2);
    *(unsigned short *)(h + 4) = type;
    *(int *)h = size;
}


unsigned short DWCs_DecodeHeader(void *message)
{
    char header[8];

    MI_CpuCopy8(message, header, 8);
    if (memcmp(header + 6, g_021A2344, 2) == 0)
        return *(unsigned short *)(header + 4);
    return 0;
}


long DWCs_GetRequiredHeaderSize(unsigned short type)
{
    int clientCount;

    switch (type) {
    case 2:
        return 0x24;
    case 3:
        return 0x0c;
    case 4:
        clientCount = DWCi_NodeInfoList_GetCount();
        return (clientCount - 1 == 0) ? 0x10 : (clientCount - 1) * 0x18 + 0x10;
    default:
        return 8;
    }
}


int DWC_SetRecvTimeoutTime(unsigned char aid, unsigned long time)
{
    unsigned long long tick;

    if (*(char **)g_021AB180 == 0)
        return 0;
    *(unsigned long *)(*(char **)g_021AB180 + aid * 0x38 + 0x2c) = time;
    tick = OS_GetTick();
    *(unsigned long long *)(*(char **)g_021AB180 + aid * 0x38 + 0x24) = tick;
    return 1;
}


/*
 * Sets the word at +0x724 of the state block when both are present.
 */
int func_021772B8(int v)
{
    char *p = *(char **)g_021AB180;

    if (p == 0 || v == 0) {
        return 0;
    }

    *(int *)(p + 0x724) = v;

    return 1;
}


/*
 * Word at +0x724 of the block held at +0x0 of the module state object, zero when the block is unset.
 */
int func_021772DC(void)
{
    int *p = *(int **)g_021AB180;

    return p != 0 ? *(int *)((char *)p + 0x724) : 0;
}


void DWCi_InitTransport(char *info)
{
    *(char **)g_021AB180 = info;
    MI_CpuFill8(info, 0, 0x728);
    *(unsigned short *)(*(char **)g_021AB180 + 0x720) = 0x5b9;
    DWC_SetConnectionKeepAliveTime(0x4e20);
    DWCi_InitReliableQueue();
}
