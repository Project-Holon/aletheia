/*
 * function: BTLV_INPUT_StartScreenFadeTask
 * address:  0x0220266C
 * packet:   pkt_ov094_0220266C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 * note: the two zero arguments of FADE_Start sit in r6 because the call is written in
 *   both arms of the if (the arms are cross-jumped and the shared zero is hoisted).
 * trailing: 022026FC..0220270C is an unlabelled getter (mode bits 15..16 of +0x68 != 0).
 *
 * symbols:
 *   BTLV_INPUT_LoadScreenResources  0x02202248  thumb  ov094
 *   BTLV_INPUT_RegisterTask  0x0220684C  thumb  ov094
 *   BTLV_INPUT_WaitFadeTaskMain  0x02204A3C  thumb  ov094
 *   BTLV_INPUT_WaitFadeTaskEnd  0x02204A70  thumb  ov094
 *   d_0220AEB0  0x0220AEB0  data  a4
 *   FADE_Start  0x0204E720  arm  arm9
 *   GXx_GetMasterBrightness_  0x0207D55C  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Bits { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits;
typedef struct Obj {
    void *h0;
    char pad[0x68 - 4];
    Bits f68;
    char pad2[0x240 - 0x6c];
    u16 heap;
} Obj;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int GXx_GetMasterBrightness_(volatile u16 *reg);
typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void BTLV_INPUT_LoadScreenResources(char *p);
extern void *func_02030DA8(void *, void (*)(void *, Obj **), void *, u32);
extern void BTLV_INPUT_RegisterTask(char *p, int a, int b);
extern void BTLV_INPUT_WaitFadeTaskMain(void *a, char **s);
extern void BTLV_INPUT_WaitFadeTaskEnd(void *);
extern const char d_0220AEB0[];

void BTLV_INPUT_StartScreenFadeTask(Obj *p)
{
    Obj **q;
    q = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x50c);
    if (GXx_GetMasterBrightness_((volatile u16 *)0x0400106c) <= 0)
        FADE_Start(2, 0x10, 0, 0);
    else
        FADE_Start(8, 0x10, 0, 0);
    BTLV_INPUT_LoadScreenResources((char *)p);
    p->f68.mode = 2;
    *q = p;
    BTLV_INPUT_RegisterTask((char *)p, (int)func_02030DA8(p->h0, (void (*)(void *, Obj **))BTLV_INPUT_WaitFadeTaskMain, q, 0), (int)BTLV_INPUT_WaitFadeTaskEnd);
}
