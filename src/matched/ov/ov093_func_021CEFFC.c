/*
 * function: BTL_CLIENT_IsLoneFoeSemiInvulnerable
 * address:  0x021CEFFC
 * packet:   pkt_ov093_021CEFFC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_MAIN_GetActivePosPerSide  0x021B8670  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 */
#include "../include/Obj09993.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *BTL_MAIN_GetCompetitor(void ***p);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
struct Q1;
struct S2;
struct UtilWork;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
extern unsigned int BTL_MAIN_GetActivePosPerSide(unsigned int **p);
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);

u32 BTL_CLIENT_IsLoneFoeSemiInvulnerable(u8 *p)
{
    char *arr;
    u32 lim;
    u32 flag;
    u32 i;
    u32 c;
    u8 *w;
    u32 cnt;
    if (BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj09993 *)p)->f0) == 0) {
        arr = BTL_SIDE_GetSlotOfClientThunk(*(char * *)&((struct Obj09993 *)p)->f4, 1);
        cnt = BTL_SLOT_GetCount((struct Q1 *)arr);
        lim = BTL_MAIN_GetActivePosPerSide((unsigned int **)(*(void *** *)&((struct Obj09993 *)p)->f0));
        if (lim > cnt) {
            lim = cnt;
        }
        flag = 0;
        c = 0;
        for (i = 0; i < lim; i++) {
            w = BTL_SLOT_GetPokeParam((struct S2 *)arr, (u8)i);
            if (BTL_POKEPARAM_IsFainted(w) == 0) {
                c++;
                if (BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)w) != 0) {
                    flag = 1;
                }
            }
        }
        if (c == 1 && flag != 0) {
            return 1;
        }
    }
    return 0;
}
