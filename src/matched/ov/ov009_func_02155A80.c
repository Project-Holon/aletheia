/*
 * function: DWC_RAP_SendPacket
 * address:  0x02155A80
 * packet:   pkt_ov009_02155A80
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   MI_CpuCopy8  0x02082D44  arm
 *   DWC_GetAIDBitmap  0x0216B908  arm
 *   func_02176FD4  0x02176FD4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int hdr;            /* 0x000 */
    u8 b4;
    char pad[0x760 - 5];
    int busy;           /* 0x760 */
    char pad2[0x34 - 4];
    u16 v794;           /* 0x794 */
    char pad3[6];
    u8 cnt;             /* 0x79c */
} G;

extern G *_pRapWork;
void MI_CpuCopy8(void *src, void *dst, int n);
int DWC_GetAIDBitmap(void);
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);

int DWC_RAP_SendPacket(void *src, int len, int c)
{
    int r;

    if (len >= 0x100)
        return 0;
    if (_pRapWork->busy != 0)
        return 0;
    _pRapWork->hdr = c | (_pRapWork->v794 << 8);
    _pRapWork->cnt = _pRapWork->cnt + 1;
    ((u8 *)_pRapWork)[2] = _pRapWork->cnt;
    MI_CpuCopy8(src, (char *)_pRapWork + 4, len);
    _pRapWork->busy = 1;
    r = (u16)DWC_GetAIDBitmap();
    if (r != func_02176FD4(r, _pRapWork, len + 4)) {
        _pRapWork->busy = 0;
        return 0;
    }
    return 1;
}
