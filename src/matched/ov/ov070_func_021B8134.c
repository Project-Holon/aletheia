/*
 * function: ITEMMENU_ToggleRegisteredItem
 * address:  0x021B8134
 * packet:   pkt_ov070_021B8134
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   ITEMMENU_GetSlot  0x021B616C  thumb  ov070
 *   func_0202E448  0x0202E448  thumb
 *   ITEMMENU_IsItemRegistered  0x021B83A0  thumb  ov070
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned short u16;

typedef struct Obj {
    void *f000;
    unsigned char pad004[0x80C - 0x4];
    int f80C;
    unsigned char pad810[0x814 - 0x810];
    int f814;
    int f818;
} Obj;

typedef unsigned char  u8;
extern int ITEMMENU_GetItemCount(u8 *p);
extern void *ITEMMENU_GetSlot(u8 *p, int i);
typedef unsigned int   u32;
extern u32 func_0202E448(u32 id);
extern int ITEMMENU_IsItemRegistered(char *p, int value);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int id);

int ITEMMENU_ToggleRegisteredItem(Obj *o, int k)
{
    u16 *p;
    int v;

    k += o->f814 + 1;
    if (o->f80C == 4) {
        if (ITEMMENU_GetItemCount((u8 *)o) <= k)
            return 0;
        p = ITEMMENU_GetSlot((u8 *)o, k);
        v = func_0202E448(*p);
        if (v == 0x19)
            return 0;
        if (ITEMMENU_IsItemRegistered((char *)o, *p) == 1)
            GAME_DATA_SetSaveFlag(o->f000, v, 0);
        else
            GAME_DATA_SetSaveFlag(o->f000, v, 1);
        GFL_USE_PlaySeDefaultVolume(0x646);
        o->f818 = 0xFFFF;
        return 1;
    }
    return 0;
}
