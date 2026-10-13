/*
 * function: UNION_SUBDISP_CheckLineTouch
 * address:  0x021F0DB0
 * packet:   pkt_ov031_021F0DB0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_SUBDISP_CheckLineTouch  0x021F0DB0  thumb
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   UNION_SUBDISP_SetLinePalette  0x021F0F68  thumb  ov031
 *   UNION_SUBDISP_StartLineHighlight  0x021F0ED8  thumb  ov031
 *   UNION_CHAT_LOG_GetLine  0x021BBC2C  thumb  ov021
 *   MI_CpuCopy8  0x02082D44  arm
 *   UNION_SUBDISP_CancelOtherHighlights  0x021F0F40  thumb  ov031
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    char pad[0x43C];
    int a;
    int n;
} B;

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int UNION_SUBDISP_SetLinePalette(void *, int, int);
extern void UNION_SUBDISP_StartLineHighlight(void *, B *, int);
extern u8 *UNION_CHAT_LOG_GetLine(B *, int);
extern void MI_CpuCopy8(void *dst, void *src, int n);
extern void UNION_SUBDISP_CancelOtherHighlights(void *, B *, int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int UNION_SUBDISP_CheckLineTouch(char *a0, void *a1, B *a2)
{
    u32 x;
    u32 y;
    int i;
    int t;
    u8 *e;

    if (TOUCHPANEL_GetPointTrg(&x, &y) == 0)
        return 0;
    if (x <= 0xE8) {
        for (i = 0; i < 3; i++) {
            if (y >= (u32)(i * 0x38) && y <= (u32)(i * 0x38 + 0x38))
                break;
        }
    }
    if (i >= 3 || i > a2->a)
        return 0;
    if (UNION_SUBDISP_SetLinePalette(a1, i, 1) == 1) {
        t = i;
        i = a2->n;
        if (i >= 3)
            i = i - 2 + t;
        else
            i = t;
        UNION_SUBDISP_StartLineHighlight(a1, a2, i);
        e = UNION_CHAT_LOG_GetLine(a2, i);
        if (e != 0)
            MI_CpuCopy8(e + 0x1A, a0 + 0x28A4, 6);
        UNION_SUBDISP_CancelOtherHighlights(a1, a2, i);
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return 1;
    }
    return 0;
}
