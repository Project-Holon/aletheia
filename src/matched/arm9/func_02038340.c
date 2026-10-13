/*
 * function: GFL_NET_SYSTEM_SendMP
 * address:  0x02038340
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Promoted from src/pending/ on lane 1.  All 64 concrete bytes are right; the
 * one open site was the PC24 at +0x0038, the `bl` to GFL_NET_SYSTEM_SendParentData, which had
 * exactly one branch reference in the whole image (this one) and so no
 * `label` witness.  With src/matched/GFL_NET_SYSTEM_SendParentData.c filed EXACT the site
 * resolves through the `matched` class and the file prints EXACT with no
 * change to its C.
 *
 * The reading: refresh the UI object, ask its +0x340 owner's +0x70 virtual
 * whether the session is still up, then let the two teardown probes decide
 * whether GFL_NET_SYSTEM_PackSendData(1) and GFL_NET_SYSTEM_SendParentData are reached.  The first
 * GFL_NET_GetInitParam() result is discarded - the image overwrites r0 with
 * GFL_NET_GetSession()'s answer immediately - which is why the call stands on its
 * own statement rather than as an initialiser.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_SYSTEM_IsConnectMember  0x02039160  arm
 *   GFL_NET_SYSTEM_PackSendData  0x02037D98  arm
 *   GFL_NET_SYSTEM_SendParentData  0x02037E60  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_NET_SYSTEM_SendMP.c \
 *       --func GFL_NET_SYSTEM_SendMP --addr 0x02038340 --cc 1.1p1 --arm
 */

extern void *GFL_NET_GetInitParam(void);
extern void *GFL_NET_GetSession(void);
extern unsigned short GFL_NET_SYSTEM_GetCurrentAid(void);
extern int   GFL_NET_SYSTEM_IsConnectMember(unsigned int mode);
extern int GFL_NET_SYSTEM_PackSendData(int a);
extern void  GFL_NET_SYSTEM_SendParentData(void);

void GFL_NET_SYSTEM_SendMP(void)
{
    void *p;

    GFL_NET_GetInitParam();
    p = GFL_NET_GetSession();
    if (((int (*)(void))*(unsigned int *)(*(unsigned int *)((char *)p + 0x340) + 0x70))() == 0)
        return;
    if (GFL_NET_SYSTEM_IsConnectMember(GFL_NET_SYSTEM_GetCurrentAid()) == 0)
        return;
    GFL_NET_SYSTEM_PackSendData(1);
    GFL_NET_SYSTEM_SendParentData();
}
