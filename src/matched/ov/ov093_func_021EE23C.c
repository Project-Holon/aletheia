/*
 * unit:     yes
 * function: BTLV_SCU_ClearWaitWindow, BTLV_SCU_GetWaitState, BTLV_SCU_StartBallWindowOpen
 * address:  0x021EE23C
 * packet:   pkt_ov093_021EE23C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   FADE_Start  0x0204E720  arm
 *   func_021EB318  0x021EB318  thumb  ov093
 *   BTLV_SCU_StepBallWindowOpen  0x021EE3E8  thumb  ov093
 */
#include "../include/Obj06295.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Q {
    int f00;
    int f04;
};

struct T {
    u16 v[7];
};

struct O {
    u8 pad00[0xe0];
    int (*fe0)(void *, void *);
    int (*fe4)(void *, void *);
    void *fe8;
    int fec;
};

struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern u32 func_021EB318(void);
struct C;
extern int BTLV_SCU_StepBallWindowOpen(int *st, struct C *c);

void BTLV_SCU_ClearWaitWindow(struct Q *q)
{
    BMP_Clear((struct CharBuf *)q->f04, 12);
    BMP_WIN_TransferChars((struct Descriptor *)q->f00);
    FADE_Start(1, 16, 0, -3);
}

int BTLV_SCU_GetWaitState(void)
{
    return func_021EB318();
}

void BTLV_SCU_StartBallWindowOpen(char *o, int a, struct T *src)
{
    ((struct Obj06295 *)o)->f16C = a;
    *(struct T *)(o + 0x170) = *src;
    ((struct O *)o)->fe0 = 0;
    ((struct O *)o)->fe4 = (int (*)(void *, void *))BTLV_SCU_StepBallWindowOpen;
    ((struct O *)o)->fe8 = o;
    ((struct O *)o)->fec = 0;
}
