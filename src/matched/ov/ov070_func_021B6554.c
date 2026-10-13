/*
 * function: ITEMMENU_HandleListKeys
 * address:  0x021B6554
 * packet:   pkt_ov070_021B6554
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   KEY_GetRepeat  0x0203633C  arm
 *   ITEMMENU_MoveCursorDown  0x021B6300  thumb  ov070
 *   ITEMMENU_MoveCursorUp  0x021B6374  thumb  ov070
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct Obj;
extern int ITEMMENU_GetItemCount(u8 *p);
extern unsigned int KEY_GetRepeat(void);
extern int ITEMMENU_MoveCursorDown(struct Obj *o, int n, int k);
extern int ITEMMENU_MoveCursorUp(struct Obj *o, int n, int k);

int ITEMMENU_HandleListKeys(void *o)
{
    int res = 0;
    int k;
    u32 cnt;

    k = ITEMMENU_GetItemCount(o);
    if (KEY_GetRepeat() & 0x80) {
        res = ITEMMENU_MoveCursorDown(o, k, 1);
    } else if (KEY_GetRepeat() & 0x40) {
        res = ITEMMENU_MoveCursorUp(o, k, 1);
    } else if (KEY_GetRepeat() & 0x100) {
        cnt = res;
        do {
            if (ITEMMENU_MoveCursorDown(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    } else if (KEY_GetRepeat() & 0x200) {
        cnt = res;
        do {
            if (ITEMMENU_MoveCursorUp(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    }
    return res;
}
