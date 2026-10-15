/*
 * function: DWC_RAP_SetupRecvTimeouts
 * address:  0x02155C8C
 * packet:   pkt_ov009_02155C8C
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
 *   DWC_SetRecvTimeoutTime  0x02177270  arm
 *   DWC_GetMyAID  0x0216B838  arm
 *   DWC_GetAIDBitmap  0x0216B908  arm
 *   func_02034714  0x02034714  arm
 *   DWC_RAP_ClearPeerCounters  0x02155C70  thumb  ov009
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x764];
    int n;
    char pad2[0x7a8 - 0x768];
    u8 flag;
} G;

extern G *_pRapWork;
extern char d_021A1C5C[];
int DWC_SetRecvTimeoutTime(u8 a, int b);
typedef unsigned int   u32;
unsigned char DWC_GetMyAID(void);
int DWC_GetAIDBitmap(void);
void func_02034714(const char *expr, u32 line, const char *file);
void DWC_RAP_ClearPeerCounters(void);

void DWC_RAP_SetupRecvTimeouts(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
        DWC_SetRecvTimeoutTime(i, 0);
    if (DWC_GetMyAID() == 0) {
        for (j = 0; j < _pRapWork->n; j++) {
            if (j != DWC_GetMyAID() && (DWC_GetAIDBitmap() & (1 << j)) != 0) {
                if (DWC_SetRecvTimeoutTime(j, 10000) == 0)
                    func_02034714(d_021A1C5C, 0, d_021A1C5C);
            }
        }
    } else {
        if (DWC_SetRecvTimeoutTime(0, 10000) == 0)
            func_02034714(d_021A1C5C, 0, d_021A1C5C);
    }
    _pRapWork->flag = 1;
    DWC_RAP_ClearPeerCounters();
}
