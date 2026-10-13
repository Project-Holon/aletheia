/*
 * function: func_0200F5EC
 * address:  0x0200F5EC
 * packet:   pkt_0200F5EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009860          0x02009860  thumb
 *   WIFILIST_GetDwcFriendData           0x020099C8  thumb
 *   WIFILIST_IsFriendDataValid           0x02009A1C  thumb
 *   sub_0200F34C           0x0200F34C  thumb
 *   sub_0200F594           0x0200F594  thumb
 *   sub_0201283C           0x0201283C  thumb
 *   DWC_IsValidFriendData  0x020596D8  arm
 *
 * Insert one friend record into a 32-entry list and mirror it into the three
 * case slots.  sub_0200F594's last argument picks the slot: 0 for the
 * "not valid yet" arm, 2 when sub_0200F34C reports equality and 1 when it
 * reports "newer".  The first arm is the only one that returns 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200F5EC.c \
 *       --func func_0200F5EC --addr 0x0200F5EC --cc 1.1p1 --thumb
 */

struct BigObj;
extern unsigned int sub_0201283C(const struct BigObj *p);
extern int   DWC_IsValidFriendData(const void *friendData);
typedef unsigned int   u32;
struct Sub020097BCFriend;
struct Sub020097BCObj;
extern struct Sub020097BCFriend *WIFILIST_GetDwcFriendData(struct Sub020097BCObj *obj, int i);
extern int WIFILIST_IsFriendDataValid(struct Sub020097BCObj *obj, u32 i);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int   sub_0200F34C(void *a, void *b, void *c);
extern void  sub_0200F594(void *a0, void *a1, void *a2, int a3, void *a4,
                          int mode);

int func_0200F5EC(void *a0, void *a1, void *a2, void *a3)
{
    void *obj = (void *)sub_0201283C(a0);
    int i;

    if (DWC_IsValidFriendData(a2) == 0) {
        return 0;
    }

    for (i = 0; i < 0x20; i++) {
        void *src = WIFILIST_GetDwcFriendData(obj, i);
        int mode;

        if (WIFILIST_IsFriendDataValid(obj, i) == 0) {
            sub_0200F594(a0, a1, a2, i, a3, 0);
            return 1;
        }
        mode = sub_0200F34C(a2, func_02009860(obj), src);
        if (mode == 0) {
            sub_0200F594(a0, a1, a2, i, a3, 2);
            return 0;
        }
        if (mode == 1) {
            sub_0200F594(a0, a1, a2, i, a3, 1);
            return 0;
        }
    }
    return 0;
}
