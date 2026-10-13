/*
 * function: FIELD_GROUND_ANIME_AnmSetFree
 * address:  0x021A7484
 * packet:   pkt_ov021_021A7484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GROUND_ANIME_AnmEntryFree  0x021A752C  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

typedef struct {
    u32 w[3];
} E;

typedef struct {
    E *arr;
    u32 n;
    void *p8;
} S;

extern int FIELD_GROUND_ANIME_AnmEntryFree(u32 a);
extern u32 func_020307B0(void *p);

void FIELD_GROUND_ANIME_AnmSetFree(S *s)
{
    u32 i;
    if (s->p8 != 0) {
        for (i = 0; i < s->n; i++) {
            FIELD_GROUND_ANIME_AnmEntryFree((u32)(&s->arr[i]));
        }
        func_020307B0(s->arr);
        s->arr = 0;
        func_020307B0(s->p8);
        s->p8 = 0;
    }
}
