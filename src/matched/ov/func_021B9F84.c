/*
 * function: WIFICLUBACTOR_HideCursor
 * address:  0x021B9F84
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Tail call onto the arm9 routine on the pointer at +0x28 with a zero selector.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x28];
    void *f28;
} S;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void WIFICLUBACTOR_HideCursor(S *s)
{
    CLACT_SetActorDrawEnable(s->f28, 0);
}
