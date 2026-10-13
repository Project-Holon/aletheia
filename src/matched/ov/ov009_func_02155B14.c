/*
 * function: DWC_RAP_SendMessage
 * address:  0x02155B14
 * packet:   pkt_ov009_02155B14
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   DWC_RAP_SendPacket  0x02155A80  thumb  ov009
 *   DWC_GetMyAID  0x0216B838  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad[0x280];
    void (*cb)(int, int, int);
    char pad2[0x7a6 - 0x284];
    u8 flag;
} G;

extern G *_pRapWork;
int DWC_RAP_SendPacket(void *src, int len, int c);
unsigned char DWC_GetMyAID(void);

int DWC_RAP_SendMessage(int a, int b)
{
    if (_pRapWork->flag == 0)
        return 0;
    if (DWC_RAP_SendPacket((void *)a, b, 1) == 0)
        return 0;
    _pRapWork->flag = 0;
    if (_pRapWork->cb != 0) {
        int r = DWC_GetMyAID();
        _pRapWork->cb(r, a, (u16)b);
    }
    return 1;
}
