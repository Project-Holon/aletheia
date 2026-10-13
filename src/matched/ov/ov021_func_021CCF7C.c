/*
 * function: PARTY_SELECT_LIST_MenuSelectCallback
 * address:  0x021CCF7C
 * packet:   pkt_ov021_021CCF7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_MENULIST_GetUserData  0x02020D0C  thumb
 *   BMP_MENULIST_SetOverrideColors  0x02020298  thumb
 */

typedef struct {
    int pad[4];
    int f10;
} Info;

typedef unsigned int   u32;
extern u32 BMP_MENULIST_GetUserData(unsigned char *p);
typedef unsigned char  u8;
struct Obj;
extern void BMP_MENULIST_SetOverrideColors(struct Obj *obj, u8 a, u8 b, u8 c);

void PARTY_SELECT_LIST_MenuSelectCallback(void *p, int k)
{
    Info *i = (Info *)BMP_MENULIST_GetUserData(p);

    if (k == 0 && i->f10 == 1) {
        BMP_MENULIST_SetOverrideColors(p, 1, 0, 2);
        return;
    }
    if (k == 1) {
        BMP_MENULIST_SetOverrideColors(p, 1, 0, 2);
        return;
    }
    BMP_MENULIST_SetOverrideColors(p, 1, 0, 2);
}
