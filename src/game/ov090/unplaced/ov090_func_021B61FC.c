/*
 * function: PLIST_COMM_IsSyncDoneOrFinished
 * address:  0x021B61FC
 * packet:   pkt_ov090_021B61FC
 * region:   ov090
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 */
struct NetHandle;
extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct NetHandle *handle, unsigned int syncNo, unsigned int syncGroup);

typedef struct PartyListCommWork {
    unsigned char unusedHead[0x62];
    unsigned char syncStep;
    unsigned char commFinished;
} PartyListCommWork;

int PLIST_COMM_IsSyncDoneOrFinished(PartyListCommWork *work, int syncNo)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), syncNo, 0x2d) == 1)
        return 1;
    if (work->commFinished == 1)
        return 1;
    return 0;
}
