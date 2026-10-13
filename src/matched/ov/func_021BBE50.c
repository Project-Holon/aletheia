/*
 * function: WIFICLUB_FreezePartyIcons
 * address:  0x021BBE50
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   unit_0204B92C  0x0204B92C  arm
 *   unit_0204B3DC  0x0204B3DC  arm
 *
 * Releases the twelve pointers at +0x150, each through the same pair of arm9
 * calls.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct Obj;
extern void unit_0204B92C(struct Obj *p, unsigned int v);
extern void unit_0204B3DC(struct Obj *p, unsigned int v);

typedef struct {
    char pad[0x150];
    void *arr[12];
} S;

void WIFICLUB_FreezePartyIcons(S *s)
{
    int i;

    for (i = 0; i < 12; i++) {
        if (s->arr[i] != 0) {
            unit_0204B92C(s->arr[i], 0);
            unit_0204B3DC(s->arr[i], 0);
        }
    }
}
