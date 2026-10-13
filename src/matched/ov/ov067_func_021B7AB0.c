/*
 * function: FRAME_LIST_Update
 * address:  0x021B7AB0
 * packet:   pkt_ov067_021B7AB0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   FRAME_LIST_HandleInput  0x021B806C  thumb  ov067
 *   FRAME_LIST_StepScroll  0x021B8460  thumb  ov067
 *   FRAME_LIST_StepScrollBarDrag  0x021B8B74  thumb  ov067
 *   FRAME_LIST_StepRowDrag  0x021B8C4C  thumb  ov067
 *   func_020355C4  0x020355C4  arm
 *   func_020362DC  0x020362DC  arm
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   FRAME_LIST_UpdateWindows  0x021B9344  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct S {
    u8 pad00[0x30];
    void *f30;
    u8 pad34[0x4e - 0x34];
    u16 f4e;
    u8 pad50[0x54 - 0x50];
    int f54;
    int f58;
    s16 f5c;
    u8 pad5e[0x86 - 0x5e];
    u8 f86_lo : 5;
    u8 f86_b5 : 1;
    u8 f86_hi : 2;
    u8 pad87[0x96 - 0x87];
    u8 f96;
} S;

extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int FRAME_LIST_HandleInput(S *p);
extern int FRAME_LIST_StepScroll(S *p);
extern int FRAME_LIST_StepScrollBarDrag(S *p);
extern int FRAME_LIST_StepRowDrag(S *p);
struct Row;
extern u8 func_020355C4(void);
extern u32 func_020362DC(void);
typedef signed int     s32;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void FRAME_LIST_UpdateWindows(S *p);

int FRAME_LIST_Update(S *p)
{
    int buf;
    int ret = -1;

    if (TOUCHPANEL_GetPointCont((u32 *)(&buf), (u32 *)(&p->f54)) == 0) {
        p->f54 = -1;
        p->f86_b5 = 0;
    }
    switch (p->f4e) {
    case 0:
        ret = FRAME_LIST_HandleInput(p);
        break;
    case 1:
        if (FRAME_LIST_StepScroll(p) == 1)
            ret = -10;
        break;
    case 2:
        if (FRAME_LIST_StepScrollBarDrag(p) == 1)
            ret = -9;
        break;
    case 3:
        if (FRAME_LIST_StepRowDrag(p) == 1)
            ret = -8;
        break;
    case 4:
        if (func_020355C4() == 0 && (func_020362DC() & 1))
            ret = p->f5c;
        if (p->f96 == 0)
            p->f4e = 0;
        else
            p->f96--;
        break;
    }
    p->f58 = p->f54;
    BLINK_PALANM_Update(p->f30);
    FRAME_LIST_UpdateWindows(p);
    return ret;
}
