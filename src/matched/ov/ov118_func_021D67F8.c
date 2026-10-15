/*
 * function: func_021D67F8
 * address:  0x021D67F8
 * packet:   pkt_ov118_021D67F8
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6738  0x021D6738  thumb  ov118
 *   func_02030734  0x02030734  arm
 *   func_021D6734  0x021D6734  thumb  ov118
 *   POKETRADE_SAVE_FreeIfSet  0x021DFD24  thumb  ov119
 *   POKETRADE_MCSS_SlideCreate  0x021DFB84  thumb  ov119
 *   MCSS_SetAnimCallback  0x02015F2C  thumb
 *   POKETRADE_MCSS_StopAnimation  0x021DFD0C  thumb  ov119
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   POKETRADE_SAVE_CloseMessageWindow  0x021E106C  thumb  ov119
 *   func_02040EBC  0x02040EBC  arm
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_DEMO_MIDDLE_StepStartPlayback  0x021D6918  thumb  ov118
 *   d_021D8650     0x021D8650  data
 *   d_021D7CC4     0x021D7CC4  data
 *   d_021D7CD0     0x021D7CD0  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D6738(u8 *p, u32 v);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021D6734(int);
struct McssFade;
extern void POKETRADE_SAVE_FreeIfSet(u32 *p);
extern void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId);
extern void MCSS_SetAnimCallback(u32 obj, void *arg, void (*cb)(void), int a);
extern void POKETRADE_MCSS_StopAnimation(char *p);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void POKETRADE_SAVE_CloseMessageWindow(char *p);
extern void func_02040EBC(u32 a0, u32 a1);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_DEMO_MIDDLE_StepStartPlayback(u8 *p);
extern const char d_021D8650[];
extern const Vec d_021D7CC4;
extern const Vec d_021D7CD0;

#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))
#define FADE (*(s8 **)(p + 0x818))

void func_021D67F8(u8 *p)
{
    Vec a;
    Vec b;

    func_021D6738(p, 0);
    FADE = func_02030734(HEAP, 4, 1, d_021D8650, 0xF5);
    FADE[0] = func_021D6734(0xE);
    FADE[1] = 0;
    FADE[2] = 0;
    FADE[3] = -0x10;
    a = d_021D7CC4;
    POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
    SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(0), (void *)func_021D6734(0x2A), &a, HEAP);
    b = d_021D7CD0;
    POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
    SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(1), (void *)func_021D6734(0x54), &b, HEAP);
    MCSS_SetAnimCallback(OBJ(0), p, (void (*)(void))POKETRADE_MCSS_StopAnimation, 1);
    MCSS_SetPaletteFade((struct McssFade *)OBJ(1), 0, 0x10, (s8)(func_021D6734(0xE) / 16), 0);
    POKETRADE_SAVE_CloseMessageWindow((char *)p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
    func_021D6738(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepStartPlayback);
}
