/*
 * function: BTL_CLIENT_FindTrapper
 * address: 0x021CF9B4
 * packet: pkt_ov093_021CF9B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_MAIN_CollectLivingPokeIds 0x021B8D38 thumb ov093
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_CLIENT_CanShadowTagTrap 0x021CFAC4 thumb ov093
 *   BTL_CLIENT_CanArenaTrapTrap 0x021CFADC thumb ov093
 *   BTL_CLIENT_CanMagnetPullTrap 0x021CFB8C thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 */
#include "../include/Obj01894.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *, void *, u32);
extern u8 BTL_MAIN_CollectLivingPokeIds(void *p, int a, int k, u8 *out);
struct Unk021D62A8;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int BTL_CLIENT_CanShadowTagTrap(void *p, void *q);
extern int BTL_CLIENT_CanArenaTrapTrap(u8 *, void *);
extern int BTL_CLIENT_CanMagnetPullTrap(void *p, void *q);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
u32 BTL_CLIENT_FindTrapper(u8 *g, void *m, u8 *a, u16 *b)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *q;
    u16 k;
    n = BTL_MAIN_CollectLivingPokeIds(((struct Obj01894 *)g)->f0, *(int *)&((struct Obj01894 *)g)->f4, (u16)(BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj01894 *)g)->f0, ((struct Obj01894 *)g)->f4, BTL_POKEPARAM_GetPokeId(m)) | 0x100), buf);
    for (i = 0; i < n; i++) {
        q = BTL_SIDE_GetPokeByIdThunk(((struct Obj01894 *)g)->f4, buf[i]);
        k = BTL_POKEPARAM_GetValue(q, 0x11);
        BTL_POKEPARAM_GetPokeId(q);
        if (k == 0x17 && BTL_CLIENT_CanShadowTagTrap(g, m)) {
            *a = BTL_POKEPARAM_GetPokeId(q);
            *b = k;
            return 0;
        }
        if (k == 0x47 && BTL_CLIENT_CanArenaTrapTrap(g, m)) {
            *a = BTL_POKEPARAM_GetPokeId(q);
            *b = k;
            return 0;
        }
        if (k == 0x2a && BTL_CLIENT_CanMagnetPullTrap(g, m)) {
            *a = BTL_POKEPARAM_GetPokeId(q);
            *b = k;
            return 0;
        }
    }
    if (BTL_POKEPARAM_HasSick(m, 0x16) || BTL_POKEPARAM_HasSick(m, 8) || BTL_POKEPARAM_HasSick(m, 0x15)) {
        *a = BTL_POKEPARAM_GetPokeId(m);
        *b = 0;
        return 3;
    }
    return 4;
}
