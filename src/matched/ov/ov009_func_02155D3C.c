/*
 * function: DWC_RAP_OnMatched
 * address:  0x02155D3C
 * packet:   pkt_ov009_02155D3C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   DWC_RAP_EnterConnected  0x02155D2C  thumb  ov009
 *   DWC_RAP_EndCancel  0x02155904  thumb  ov009
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 *   DWC_GetMyAID  0x0216B838  arm
 */

typedef struct {
    char pad[0x29c];
    void (*cb)(int, int);
    int arg;
} G;

extern G *_pRapWork;
void DWC_RAP_EnterConnected(int e);
void DWC_RAP_EndCancel(void);
void DWC_RAP_SetState(int n);
unsigned char DWC_GetMyAID(void);

void DWC_RAP_OnMatched(int a, int b, int c, int d, int e)
{
    G *g;

    if (a == 0) {
        if (b == 0)
            DWC_RAP_EnterConnected(e);
        else
            DWC_RAP_EndCancel();
    } else {
        DWC_RAP_SetState(14);
    }
    g = _pRapWork;
    if (g->cb != 0) {
        int r = DWC_GetMyAID();
        _pRapWork->cb(r, g->arg);
    }
}
