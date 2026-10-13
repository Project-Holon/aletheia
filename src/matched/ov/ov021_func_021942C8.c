/*
 * function: FIELD_COMM_ACTOR_CTRL_Delete
 * address:  0x021942C8
 * packet:   pkt_ov021_021942C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_COMM_ACTOR_DeleteActor  0x02194418  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u32 key; u32 x4; u32 x8; } Item;
typedef struct { u16 n; u16 pad; u32 x4; Item *items; } List;
extern int FIELD_COMM_ACTOR_DeleteActor(u32 a);
extern u32 func_020307B0(void *p);

void FIELD_COMM_ACTOR_CTRL_Delete(List *p)
{
    u16 i;
    Item *it;

    i = 0;
    it = p->items;
    if (i < p->n) {
        for (; i < p->n; i++) {
            if (it->x8 != 0) {
                FIELD_COMM_ACTOR_DeleteActor((u32)it);
            }
            it++;
        }
    }
    func_020307B0(p->items);
    func_020307B0(p);
}
