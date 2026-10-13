/*
 * function: WIFICLUB_StateUpdatePartyMenu
 * address:  0x021BD1A4
 * packet:   pkt_ov099_021BD1A4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   BMP_MENULIST_GetPos 0x020202FC thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   WIFICLUB_DrawPartyListWindow 0x021BBA4C thumb ov099
 *   WIFICLUB_ShowPartyIconHalf 0x021BBDD0 thumb ov099
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   WIFICLUB_CheckPartyAgainstRules 0x021BCB70 thumb ov099
 *   WIFICLUB_CheckSavedRegulation 0x021BCBBC thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_DeleteMenuAndIcons 0x021BC0C4 thumb ov099
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;

extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
typedef signed int     s32;
struct BigObj;
struct Obj;
struct Rec534;
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern void BMP_MENULIST_GetPos(struct Obj *obj, u16 *a, u16 *b);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void WIFICLUB_DrawPartyListWindow(char *p, void *x);
extern void WIFICLUB_ShowPartyIconHalf(void *pv, int flag);
extern u32 GFL_NET_IsParentAid(void);
extern int WIFICLUB_CheckPartyAgainstRules(void *rules, const struct BigObj *obj, u32 *mask);
extern int WIFICLUB_CheckSavedRegulation(int a, int b, int *out);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
extern void WIFICLUB_DeleteMenuAndIcons(char *p);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern void WIFICLUB_ClearTalkWindow(char *p);

int WIFICLUB_StateUpdatePartyMenu(char *p, int v)
{
    int five;
    void *q;
    int r;
    int out;
    u16 x[2];

    five = 0;
    q = *(void **)(p + 0x1b8);
    if (*(u8 *)(p + 0x1b0) != 0) {
        if (PRINTSYS_QUE_IsExistTarget(q, BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x1ac))) == 0) {
            BMP_WIN_TransferChars(*(struct Descriptor **)(p + 0x1ac));
            *(u8 *)(p + 0x1b0) = 0;
        }
    }
    r = BMP_MENULIST_Main(*(void **)(p + 0xbc));
    BMP_MENULIST_GetPos(*(void **)(p + 0xbc), &x[1], &x[0]);
    if (x[0] != *(u8 *)(p + 0x1354)) {
        *(u8 *)(p + 0x1354) = x[0];
        if (x[0] == 0) {
            WIFICLUB_DrawPartyListWindow(p, GAME_DATA_GetMyParty(*(void **)(p + 0xc4)));
            WIFICLUB_ShowPartyIconHalf(p, 1);
        } else {
            WIFICLUB_DrawPartyListWindow(p, *(void **)(p + 0xcc));
            WIFICLUB_ShowPartyIconHalf(p, 0);
        }
    }
    if (GFL_NET_IsParentAid() == 0) {
        five = 1;
    }
    switch (r) {
    case -1:
        return v;
    case -2:
        return v;
    case 0:
        if (WIFICLUB_CheckPartyAgainstRules(*(void **)(p + 0x1348), *(void **)(p + 0xc4), (u32 *)(&out)) != 0) {
            WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
            *(u32 *)(p + 0x1cc) = 0x6b;
            WIFICLUB_DeleteMenuAndIcons(p);
            return v;
        }
        POKEPARTY_Copy(GAME_DATA_GetMyParty(*(void **)(p + 0xc4)), *(void **)(*(char **)(p + 0x248) + five * 4 + 0x14));
        *(u32 *)(p + 0x1cc) = 0x67;
        break;
    case 1:
        if (WIFICLUB_CheckSavedRegulation((int)(*(void **)(p + 0x1348)), (int)(*(void **)(p + 0xcc)), &out) != 0) {
            WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
            *(u32 *)(p + 0x1cc) = 0x6c;
            WIFICLUB_DeleteMenuAndIcons(p);
            return v;
        }
        POKEPARTY_Copy(*(void **)(p + 0xcc), *(void **)(*(char **)(p + 0x248) + five * 4 + 0x14));
        *(u32 *)(p + 0x1cc) = 0x67;
        break;
    }
    WIFICLUB_DeleteMenuAndIcons(p);
    WIFICLUB_ClearTalkWindow(p);
    return v;
}
