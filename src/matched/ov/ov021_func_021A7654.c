/*
 * function: FIELD_GROUND_ANIME_TexAnmSetUpdate
 * address:  0x021A7654
 * packet:   pkt_ov021_021A7654
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GROUND_ANIME_TexAnmIsActive  0x021A78DC  thumb
 *   FIELD_GROUND_ANIME_TexAnmUpdate  0x021A7818  thumb
 */

typedef unsigned char u8;

typedef struct {
    u8 b[0x40];
} E;

typedef struct {
    E e[16];
    void *p;
} S;

typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
extern int FIELD_GROUND_ANIME_TexAnmIsActive(u32 a);

extern void FIELD_GROUND_ANIME_TexAnmUpdate(struct Obj *a, s32 dt);

void FIELD_GROUND_ANIME_TexAnmSetUpdate(S *s, int x)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (FIELD_GROUND_ANIME_TexAnmIsActive((u32)(&s->e[i]))) {
            FIELD_GROUND_ANIME_TexAnmUpdate((struct Obj *)(&s->e[i]), x);
        }
    }
}
