/*
 * function: DWC_RAP_OnLogin
 * address:  0x02155B98
 * packet:   pkt_ov009_02155B98
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   DWC_CheckDirtyFlag  0x0205984C  arm
 *   DWC_ClearDirtyFlag  0x02059870  arm
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x108];
    int h;
    char pad2[0x7a2 - 0x10c];
    u8 flag;
} G;

extern G *_pRapWork;
int DWC_CheckDirtyFlag(void *userdata);
void DWC_ClearDirtyFlag(int h);
void DWC_RAP_SetState(int n);

void DWC_RAP_OnLogin(int a)
{
    if (DWC_CheckDirtyFlag((void *)_pRapWork->h) != 0) {
        DWC_ClearDirtyFlag(_pRapWork->h);
        _pRapWork->flag = 1;
    }
    if (a == 0)
        DWC_RAP_SetState(4);
    else
        DWC_RAP_SetState(14);
}
