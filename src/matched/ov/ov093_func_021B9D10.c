/*
 * function: BTL_SLOT_UpdateIllusion
 * address:  0x021B9D10
 * packet:   pkt_ov093_021B9D10
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 168, compiled 166, trailing padding)
 *
 * symbols:
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_MAIN_CountClientTrainers  0x021B8B78  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTL_POKEPARAM_SetFakeMon  0x021D5848  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   BTL_POKEPARAM_ClearFakeMon  0x021D5854  thumb  ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 */
#include "../include/Obj20995.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Arr { void *e[6]; u8 n; };

extern int BTL_POKEPARAM_IsAbleToBattle(void *m);
extern u32 BTL_MAIN_GetRule(void **p);
extern unsigned int BTL_MAIN_CountClientTrainers(unsigned char *p, int k);
extern int func_021D59B4(u8 *p, int k);
extern void *BTL_POKEPARAM_GetMon(void *m);
struct QH;
struct R4;
struct Work;
extern void BTL_POKEPARAM_SetFakeMon(struct QH *p, void *v);
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void BTL_POKEPARAM_ClearFakeMon(struct Work *p);
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);

void BTL_SLOT_UpdateIllusion(char *a, struct Arr *arr, int k)
{
    int j;
    void *m;
    void *h;

    for (j = arr->n - 1; j > 0; j--) {
        if (BTL_POKEPARAM_IsAbleToBattle(arr->e[j]) != 0)
            break;
    }
    if (BTL_MAIN_GetRule((void **)a) != 3)
        k = BTL_MAIN_CountClientTrainers((unsigned char *)a, k);
    else
        k = 3;
    for (; k < arr->n; k++) {
        m = arr->e[k];
        if (func_021D59B4(m, 0x11) == 0x95) {
            if (k < j) {
                BTL_POKEPARAM_SetFakeMon(m, BTL_POKEPARAM_GetMon(arr->e[j]));
            } else {
                h = BTL_POKEPARAM_GetDisplayMon(m);
                if (h != ((struct Obj20995 *)a)->f2C0)
                    BTL_POKEPARAM_ClearFakeMon(m);
            }
        }
    }
    for (k = 0; k < arr->n; k++)
        BTL_POKEPARAM_IsIllusionActive(arr->e[k]);
}
