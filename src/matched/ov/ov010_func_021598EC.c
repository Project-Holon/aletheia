/*
 * function: func_021598EC
 * address:  0x021598EC
 * packet:   pkt_ov010_021598EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_021B1BE8  0x021B1BE8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_GetQueueDepth  0x020288C4  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAllTask  0x0202972C  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
typedef signed int     s32;
typedef unsigned short u16;
struct Ctx;
struct Sys;
extern void *func_020120F4(const struct Ctx *p);
extern void func_021B1BE8(int);
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
extern s32 FIELD_SOUND_SYSTEM_GetQueueDepth(struct Sys *s);
extern void *FIELD_SOUND_SYSTEM_StartPopAllTask(void *a, u16 b);
extern void func_0215897C(void *vm, void *task);

int func_021598EC(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int h = (int)func_020120F4(y);
    int r = 0;
    func_021B1BE8(b);
    if (FIELD_SOUND_SYSTEM_GetQueueDepth((struct Sys *)((int)func_02012A30((const struct BigObj *)h)))) {
        func_0215897C(x, FIELD_SOUND_SYSTEM_StartPopAllTask(y, r));
        r = 1;
    }
    return r;
}
