/*
 * function: ghiPostStateCleanup
 * address:  0x021C2A3C
 * packet:   pkt_ov114_021C2A3C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostStateCleanup (ghttppost)
 *
 * symbols:
 *   fclose                  0x02091AE8  arm
 */

typedef struct {
    int type;
} GHIPost;

typedef struct {
    GHIPost *post;
    int field04;
    void *stream;
} GHIPostState;

extern int fclose(void *stream);

static void ghiPostStateCleanup(GHIPostState *state)
{
    int type = state->post->type;

    if (type == 0)
        return;
    if (type != 1)
        return;
    if (state->stream != 0)
        fclose(state->stream);
    state->stream = 0;
}
