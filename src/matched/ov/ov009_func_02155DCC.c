/*
 * function: DWC_RAP_OnReceive
 * address:  0x02155DCC
 * packet:   pkt_ov009_02155DCC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   DWC_GetMyAID  0x0216B838  arm
 *   DWC_RAP_UpdatePeerVchatFlag  0x02155DA4  thumb  ov009
 *   VCT_MAIN_HandlePacket  0x021AEF44  thumb  ov013
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef void (*Cb)(u32, u8 *, u16);

typedef struct {
    char pad[0x27c];
    Cb cb0;
    Cb cb1;
    char pad2[0x79d - 0x284];
    u8 b79d;
    char pad3[0x7a6 - 0x79e];
    u8 b7a6;
    u8 b7a7;
    u8 b7a8;
} G;

extern G *_pRapWork;
extern char d_021A1C5C[];
void func_02034714(const char *expr, u32 line, const char *file);
unsigned char DWC_GetMyAID(void);
void DWC_RAP_UpdatePeerVchatFlag(u32 x);
int VCT_MAIN_HandlePacket(int a, int b, int c);

void DWC_RAP_OnReceive(u32 a, u8 *p, int c)
{
    u32 x = p[0] | ((p[3] << 24) | (p[2] << 16) | (p[1] << 8));

    if (a >= 2)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (a < 2) {
        _pRapWork->b7a8 = 1;
        if ((u8)x == 1) {
            DWC_RAP_UpdatePeerVchatFlag(x);
            _pRapWork->b79d = p[2];
            _pRapWork->b7a7 = 1;
        } else if ((u8)x == 3) {
            _pRapWork->b7a6 = 1;
            return;
        } else {
            if (VCT_MAIN_HandlePacket(a, (int)p, c) == 0)
                return;
            return;
        }
        if (DWC_GetMyAID() == 0) {
            if (_pRapWork->cb0 != 0)
                _pRapWork->cb0(a, p + 4, (u16)(c - 4));
        } else {
            if (_pRapWork->cb1 != 0)
                _pRapWork->cb1(a, p + 4, (u16)(c - 4));
        }
    }
}
