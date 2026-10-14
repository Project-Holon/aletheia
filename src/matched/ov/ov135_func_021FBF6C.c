/*
 * function: WORLDTRADE_INPUT_CountSpeciesInList
 * address:  0x021FBF6C
 * packet:   pkt_021FBF6C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_DEPOSIT_LoadSpeciesList  0x021F8498  thumb
 *   WORLDTRADE_DEPOSIT_GetSpeciesRange  0x021F84BC  thumb
 *   WORLDTRADE_INPUT_CheckSpeciesSeen  0x021FB240  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x1C];
    u32 item;
    u8 pad20[0x2C - 0x20];
    u32 f2C;
} Menu;

extern u16 *WORLDTRADE_DEPOSIT_LoadSpeciesList(u32 heap, u32 unused, u32 *count);
extern void WORLDTRADE_DEPOSIT_GetSpeciesRange(u32 i, int *start, int *end);
extern int WORLDTRADE_INPUT_CheckSpeciesSeen(u32 unused, u32 item, u32 c, u16 *list, int start, int end);
extern u32 func_020307B0(void *p);

int WORLDTRADE_INPUT_CountSpeciesInList(Menu *m, u32 idx)
{
    u32 n;
    int start;
    int end;
    u16 *list;
    int r;

    list = WORLDTRADE_DEPOSIT_LoadSpeciesList(0x48, 0, &n);
    WORLDTRADE_DEPOSIT_GetSpeciesRange(idx, &start, &end);
    n = end - start;
    r = WORLDTRADE_INPUT_CheckSpeciesSeen(m->f2C, m->item, n, list, start, end);
    func_020307B0(list);
    return r;
}
