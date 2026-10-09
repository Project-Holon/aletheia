/*
 * file:     unit_021B96A8.c
 * function: APC_GetState
 * address:  0x021B96A8
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   atermset_bss  0x021DCFD0  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol APC_GetState (name from the vendor
 * object; a 12-byte local with no label in function_starts.txt, witnessed by the call
 * from AutoConfigThreadEx). atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126
 * (its .comment), which is the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B96A8.c \
 *       --func APC_GetState --addr 0x021B96A8 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
/*
 * atermset.o's .bss scalars from 0x021DCFD0 (btAutoResult), declared as one object in the
 * object's own order up to the member this function reads; see ov016_func_021B98A4.c.
 */
struct WCMConfig;

typedef struct {
    unsigned char             btAutoResult;
    void                   *(*gAtermAlloc)(unsigned long size);
    struct WCMConfig         *apci_IWConfig;
    void                    (*gAtermFree)(void *ptr);
    int                       bAtermApCanceled;
    int                       cbFrameData;
    int                       gAPId;
    int                       AutoPhase;          /* enum PHASE */
    int                       bApConnect;
    int                       bSO_Startup;
    unsigned char            *apci_Wep;
    int                       apci_state;         /* enum */
} ATERMSET_BSS;

extern ATERMSET_BSS atermset_bss;

static int APC_GetState(void)
{
    return atermset_bss.apci_state;
}
