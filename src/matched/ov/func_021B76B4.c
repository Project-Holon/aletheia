/*
 * function: PDW_POSTMAN_ReceiveItems
 * address:  0x021B76B4
 * packet:   pkt_021B76B4
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Iterates 0x14 slots of a container, matching each non-null entry through a
 * four-argument predicate and releasing the ones it accepts.
 *
 * symbols:
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02009364  0x02009364  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
void *GAME_DATA_GetMyItem(const struct BigObj *p);
struct Sub02009210Obj;
u16 func_02009310(const struct Sub02009210Obj *obj, int i);
u8 func_02009330(const struct Sub02009210Obj *obj, int i);
int func_02007E50(void *saved, int a, int b, int c);
void func_02009364(struct Sub02009210Obj *obj, int i);

void PDW_POSTMAN_ReceiveItems(void *a0, int a1, int a2)
{
    void *saved = GAME_DATA_GetMyItem(a0);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        int r6 = func_02009310((const struct Sub02009210Obj *)a2, i);
        int r2 = func_02009330((const struct Sub02009210Obj *)a2, i);
        if (r6 != 0) {
            if (func_02007E50(saved, r6, r2, a1) == 1)
                func_02009364((struct Sub02009210Obj *)a2, i);
        }
    }
}
