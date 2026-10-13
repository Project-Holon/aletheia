/*
 * function: BTL_MAIN_SetupOwnClient
 * address:  0x021B6848
 * packet:   pkt_ov093_021B6848
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   BTL_MAIN_InitClientParties  0x021B68D8  thumb  ov093
 *   BTL_MAIN_GetOwnsSlots  0x021B9114  thumb  ov093
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02007B20  0x02007B20  thumb
 *   func_02007C20  0x02007C20  thumb
 *   BTL_MAIN_GetClientVoiceFlag  0x021B997C  thumb  ov093
 *   BTL_MAIN_GetRelativeClientIndex  0x021BA710  thumb  ov093
 */
#include "../include/Obj03184.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct P {
    u8 pad00[0x44];
    u8 f44[4];
};

struct T {
    u8 pad00[0x21];
    u8 f21;
    u8 pad22[0x36];
    u32 f58;
};

extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *s, u32 k, u8 n);
extern void BTL_MAIN_InitClientParties(u8 *s, struct T *t);
struct PerapVoice;
struct Sub02007AC8Entry;
extern u8 BTL_MAIN_GetOwnsSlots(u8 **p);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void *func_02007B20(u32 heap);
extern void func_02007C20(struct PerapVoice *dest, const struct PerapVoice *src);
extern int BTL_MAIN_GetClientVoiceFlag(u8 *p, unsigned int i);
extern u8 BTL_MAIN_GetRelativeClientIndex(int a, int b);

void BTL_MAIN_SetupOwnClient(u8 *s, struct T *t)
{
    u32 i;
    u32 v;
    u8 tmp[4];
    u8 k = t->f21;

    i = 0;
    s[0x46c] = k;
    s[0x46d] = BTL_MAIN_GetClientTrainerIndex(s, k, 0);
    BTL_MAIN_InitClientParties(s, t);
    if (BTL_MAIN_GetOwnsSlots((u8 **)s) == 0) {
        v = (u32)func_02007B44(GAME_DATA_GetSaveControl((void *)t->f58));
        ((struct Obj03184 *)s)->f3E0 = (u32)func_02007B20(((struct Obj03184 *)s)->f468);
        func_02007C20((struct PerapVoice *)(((struct Obj03184 *)s)->f3E0), (const struct PerapVoice *)v);
        (*(struct P * *)&((struct Obj03184 *)s)->f0)->f44[0] = BTL_MAIN_GetClientVoiceFlag(s, i);
    } else {
        for (i = 0; i < 4; i++) {
            tmp[(int)BTL_MAIN_GetRelativeClientIndex(s[0x46c], (u8)i)] = (*(struct P * *)&((struct Obj03184 *)s)->f0)->f44[i];
        }
        for (i = 0; i < 4; i++) {
            (*(struct P * *)&((struct Obj03184 *)s)->f0)->f44[i] = tmp[i];
        }
    }
}
