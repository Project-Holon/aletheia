/*
 * function: HAND_WAZA_AddMoveHandler
 * address:  0x021E02DC
 * packet:   pkt_ov093_021E02DC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWazaHandlerRegistry  0x021F3030  data
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   HAND_WAZA_CanAddMoveHandler  0x021E0354  thumb  ov093
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Handler { u16 key; int (*fn)(u32 *out); };
extern const struct Handler gWazaHandlerRegistry[0x102];
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int HAND_WAZA_CanAddMoveHandler(int sub, int key, u8 *found);
struct Node;
extern struct Node *BTL_EVENT_AddFactor(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);
int HAND_WAZA_AddMoveHandler(u8 *a, u16 key, u32 sub_pri)
{
    u32 i;
    u8 sub;
    u8 found;
    u32 out;
    int r;
    for (i = 0; i < 0x102; i++) {
        if (key == gWazaHandlerRegistry[i].key) {
            sub = BTL_POKEPARAM_GetPokeId(a);
            found = 0;
            if (HAND_WAZA_CanAddMoveHandler(sub, key, &found) != 0) {
                r = gWazaHandlerRegistry[i].fn(&out);
                if (r != 0) {
                    BTL_EVENT_AddFactor(0, key, 0, sub_pri, sub, r, out);
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}
