/*
 * function: INTRUDE_COMM_IsJoinRequestValid
 * address:  0x02175FB8
 * packet:   pkt_ov011_02175FB8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_IsValidObjCode  0x021756B0  thumb  ov011
 *   INTRUDE_COMM_IsValidProfileCode  0x021756D0  thumb  ov011
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w0_lo : 15;
    u32 a : 7;
    u32 b : 10;
    u32 t : 4;
    u32 w4_mid : 3;
    u32 c : 11;
    u32 d : 11;
    u32 e : 3;
    u16 pad8;
    u16 h0a[3];
    u8  b10[4];
    u16 h14;
    u16 h16;
} Rec;

extern int INTRUDE_COMM_IsValidObjCode(int value);
extern int INTRUDE_COMM_IsValidProfileCode(u32 a);

int INTRUDE_COMM_IsJoinRequestValid(void *unused, Rec *p)
{
    int i;

    if (p->t >= 6 || p->a > 0x14 || p->b > 0xb4 || p->c >= 0x2e || p->d >= 0x53) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (p->b10[i] >= 5) return 0;
        if (INTRUDE_COMM_IsValidObjCode(p->h0a[i]) == 0) return 0;
    }
    for (i = 0; i < 2; i++) {
        if (p->t == 3) {
            if (INTRUDE_COMM_IsValidProfileCode(p->h14) == 0) return 0;
        } else if (p->t == 4) {
            if (INTRUDE_COMM_IsValidProfileCode(p->h16) == 0) return 0;
        }
    }
    return 1;
}
