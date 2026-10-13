/*
 * function: FIELD_MSGBG_CreateYesNoMenu
 * address:  0x02190BE4
 * packet:   pkt_ov021_02190BE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sYesNoMenuHeader     0x021D3F38  data   ov021  a4
 *   sYesNoMenuItems     0x021D3E68  data   ov021  a4
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateMenuItemsFromTable  0x02190A28  thumb  ov021
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELD_MSGBG_SetMenuHeaderRect  0x02190B08  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFuncPalette  0x02190860  thumb  ov021
 *   BMP_MENULIST_SetCancelDisabled  0x02020D10  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Blk32 { u32 w[8]; } Blk32;
typedef struct Blk16 { u32 w[4]; } Blk16;

extern Blk32 sYesNoMenuHeader;
extern Blk16 sYesNoMenuItems;

struct Pair;
struct Rec;
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
extern u32 FIELD_MSGBG_CreateMenuItemsFromTable(const struct Pair *arr, int n, u32 c, u16 d);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern int FIELD_MSGBG_SetMenuHeaderRect(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f);
extern u32 *FIELD_MSGBG_CreateMenuFuncPalette(u16 *a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
extern void BMP_MENULIST_SetCancelDisabled(u8 *p, u32 v);

u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b)
{
    Blk32 A = sYesNoMenuHeader;
    Blk16 B = sYesNoMenuItems;
    u32 r7;
    u32 r18;
    u32 *res;

    r7 = FIELD_MSGBG_CreateMsgData((u32)a, 0xe9);
    r18 = FIELD_MSGBG_CreateMenuItemsFromTable((const struct Pair *)(&B), 2, r7, a[0]);
    MSGDATA_Delete((struct Rec *)r7);
    FIELD_MSGBG_SetMenuHeaderRect((u32)(&A), 2, 0x18, 0xa, 7, 4);
    res = FIELD_MSGBG_CreateMenuFuncPalette(a, &A, r18, 0, (u16)b, a[3], 0, 0, 0);
    BMP_MENULIST_SetCancelDisabled((u8 *)res[4], 0);
    return res;
}
