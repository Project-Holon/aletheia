/*
 * function: func_021B97A0
 * address:  0x021B97A0
 * packet:   pkt_ov093_021B97A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B985C  0x021B985C  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_0201AA18  0x0201AA18  thumb
 *   POKEPARTY_Init  0x0201A948  thumb
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_WriteBackToParam  0x021D6B84  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   func_0201A98C  0x0201A98C  thumb
 *   BTL_POKEPARAM_IsLevelUpPending  0x021D67D0  thumb  ov093
 *   func_0201AC2C  0x0201AC2C  thumb
 *   data_021EFCF0  0x021EFCF0  data  ov093
 */
#include "../include/Obj07747.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern const u8 data_021EFCF0[4];

struct S2;
extern int func_021B985C(char *p, int i);
extern char *func_021B9AEC(char *p, int i);
struct Party;
struct PartyMon;
struct R3;
struct Rec534;
extern u32 func_0201AA18(void *p);
extern void POKEPARTY_Init(struct Party *p);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_POKEPARAM_WriteBackToParam(void *m, int k);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern int BTL_POKEPARAM_IsLevelUpPending(struct R3 *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);

void func_021B97A0(char *a, char *b, int k)
{
    void *list;
    char *g;
    u32 n;
    u32 t;
    u32 i;
    u32 j;
    void *m;

    list = (void *)func_021B985C(a, k);
    g = func_021B9AEC(a, k);
    n = func_0201AA18(list);
    POKEPARTY_Init(((struct Obj07747 *)b)->f2B8);
    t = data_021EFCF0[k];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m = (void *)func_021B9BF0((struct S2 *)g, (u8)j);
            if (t + i == BTL_POKEPARAM_GetPokeId(m)) {
                BTL_POKEPARAM_WriteBackToParam(m, 1);
                func_0201A98C(((struct Obj07747 *)b)->f2B8, BTL_POKEPARAM_GetMon(m));
                if (BTL_POKEPARAM_IsLevelUpPending(m) != 0)
                    *(u8 *)(*(char * *)&((struct Obj07747 *)b)->f0 + i + 0xc2) = 1;
                break;
            }
        }
    }
    func_0201AC2C(((struct Obj07747 *)b)->f2B8, list);
}
