/*
 * function: IRCBATTLEMENU_DeleteMenuActors
 * address:  0x02197058
 * packet:   pkt_ov021_02197058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u8 pad[0x294]; void *arr[5]; } Obj;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void IRCBATTLEMENU_DeleteMenuActors(Obj *a)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (a->arr[i] != 0) {
            CLACT_DeleteActor(a->arr[i]);
            a->arr[i] = 0;
        }
    }
}
