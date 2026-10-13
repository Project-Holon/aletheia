/*
 * function: FIELD_GROUND_ANIME_TexAnmSetFree
 * address:  0x021A7620
 * packet:   pkt_ov021_021A7620
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_GROUND_ANIME_TexAnmIsActive  0x021A78DC  thumb
 *   FIELD_GROUND_ANIME_TexAnmFree  0x021A77E8  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;

typedef struct {
    u8 b[0x40];
} E;

typedef struct {
    E e[16];
    void *p;
} S;

typedef unsigned int   u32;
extern int FIELD_GROUND_ANIME_TexAnmIsActive(u32 a);

extern void FIELD_GROUND_ANIME_TexAnmFree(E *e);
extern u32 func_020307B0(void *p);

void FIELD_GROUND_ANIME_TexAnmSetFree(S *s)
{
    int i;
    for (i = 0; i < 16; i++) {
        if (FIELD_GROUND_ANIME_TexAnmIsActive((u32)(&s->e[i]))) {
            FIELD_GROUND_ANIME_TexAnmFree(&s->e[i]);
        }
    }
    if (s->p != 0) {
        func_020307B0(s->p);
        s->p = 0;
    }
}
