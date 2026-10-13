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
 *   func_02039CB4  0x02039CB4  arm
 */
struct NetHandle;
extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int func_02039CB4(struct NetHandle *handle, unsigned int syncNo, unsigned int syncGroup);

typedef struct PartyListCommWork {
    unsigned char unusedHead[0x62];
    unsigned char syncStep;
    unsigned char commFinished;
} PartyListCommWork;

int PLIST_COMM_IsSyncDoneOrFinished(PartyListCommWork *work, int syncNo)
{
    if (func_02039CB4(GFL_NET_HANDLE_GetCurrentHandle(), syncNo, 0x2d) == 1)
        return 1;
    if (work->commFinished == 1)
        return 1;
    return 0;
}
