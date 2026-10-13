/*
 * function: FIELD_MENU_StartLeave
 * address:  0x021A90A4
 * packet:   pkt_ov021_021A90A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   FIELD_MENU_GetSlotIndex  0x021A8E78  thumb
 */

typedef unsigned char u8;

typedef struct {
    int pad0;
    int f0;
    int pad8[5];
} E;

typedef struct {
    int pad0[3];
    int fc;
    int pad10[3];
    char pad1c[2];
    u8 b1e;
    u8 b1f;
    int pad20[2];
    int f28;
    int pad2c;
    int f30;
    int pad34;
    E e[7];
    char padfc[0x128 - 0xfc];
    int f128;
} S;

typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef unsigned int   u32;
extern int FIELD_MENU_GetSlotIndex(u32 a, u32 b);

void FIELD_MENU_StartLeave(S *s, int m)
{
    if (m == 1) {
        s->f28 = 1;
        s->fc = 4;
        CLACT_SetActorAnimSeq((struct Obj *)s->f128, 8);
    } else {
        s->f28 = 0;
        s->fc = 5;
        s->f30 = s->e[FIELD_MENU_GetSlotIndex(s->b1e, s->b1f)].f0;
    }
}
