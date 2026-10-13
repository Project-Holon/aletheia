/*
 * function: SCRCMD_MSGWIN_SelectBalloonOffset
 * address:  0x021B0960
 * packet:   pkt_ov021_021B0960
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_MSGWIN_CalcBalloonOffset  0x021B0808  thumb  ov021
 *   SCRCMD_MSGWIN_RotateOffsetByCamera  0x021B090C  thumb  ov021
 *   sBalloonOffsetTable     0x021D939C  data   a4
 */

typedef unsigned char u8;
typedef struct { int x, y, z; } V;

extern V sBalloonOffsetTable[][4];
extern void SCRCMD_MSGWIN_CalcBalloonOffset(int, V *, int, int);
extern void SCRCMD_MSGWIN_RotateOffsetByCamera(V *, int);

void SCRCMD_MSGWIN_SelectBalloonOffset(int a, V *p, int q, int r3, u8 e)
{
    int i = 0;
    int j = 0;

    switch (e) {
    case 3:
        i = 1;
        break;
    case 4:
        i = 1;
        j = 1;
        break;
    case 5:
        i = 2;
        break;
    case 6:
        i = 2;
        j = 1;
        break;
    case 0:
    case 1:
    case 2:
        SCRCMD_MSGWIN_CalcBalloonOffset(a, p, q, r3);
        SCRCMD_MSGWIN_RotateOffsetByCamera(p, q);
        return;
    }
    *p = sBalloonOffsetTable[j][i];
    SCRCMD_MSGWIN_RotateOffsetByCamera(p, q);
}
