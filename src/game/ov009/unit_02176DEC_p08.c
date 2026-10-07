/*
 * file:     unit_02176DEC_p08.c
 * unit:     yes
 * function: func_02177E64, func_02177E88
 * address:  0x02177E64
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
 *   DWCi_GetGT2Connection             0x0216BAF4 arm
 *   gt2GetOutgoingBufferFreeSpace     0x02195E50 arm
 *   DWCi_GetConnectionAID    0x0216BB54 arm
 *   DWC_GetMyAID             0x0216B838 arm
 *   OS_GetTick               0x020870D0 arm
 *   DWCs_GetTransConnection  0x02177770 arm
 */
extern void *DWCi_GetGT2Connection(unsigned char aid);
extern int gt2GetOutgoingBufferFreeSpace(void *connection);
extern unsigned char DWCi_GetConnectionAID(void *connection);
extern unsigned char DWC_GetMyAID(void);
extern unsigned long long OS_GetTick(void);
extern char *DWCs_GetTransConnection(unsigned char aid);
int DWCs_GetOutgoingBufferFreeSize(unsigned char aid);
void DWCs_UpdateConnectionKeepAliveTime(void *connection);


int DWCs_GetOutgoingBufferFreeSize(unsigned char aid)
{
    int free = gt2GetOutgoingBufferFreeSpace(DWCi_GetGT2Connection(aid));

    free += 0xfffffdf9;
    if (free <= 0)
        free = 0;
    return free;
}


void DWCs_UpdateConnectionKeepAliveTime(void *connection)
{
    unsigned char aid = DWCi_GetConnectionAID(connection);
    unsigned long long tick;

    if (aid >= 0x20)
        return;
    if (aid == DWC_GetMyAID())
        return;
    tick = OS_GetTick();
    *(unsigned long long *)(DWCs_GetTransConnection(aid) + 0x30) = tick;
}
