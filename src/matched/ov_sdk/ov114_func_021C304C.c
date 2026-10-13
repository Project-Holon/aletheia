/*
 * function: ghiPostFileMemoryStateDoPosting
 * address:  0x021C304C
 * packet:   pkt_ov114_021C304C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostFileMemoryStateDoPosting (ghttppost.o, static)
 *
 * symbols:
 *   ghiDoSend                    0x021c0684 arm  ov114
 *   ghiTrySendThenBuffer                    0x021c07b8 arm  ov114
 */

typedef struct GHIPostData {
    char pad0[0x8];
    char *buffer;               /* +0x08 */
    int len;                    /* +0x0c */
} GHIPostData;

typedef struct GHIPostState {
    GHIPostData *data;          /* +0x00 */
    int pos;                    /* +0x04 */
} GHIPostState;

typedef struct GHIPost {
    char pad0[0x14];
    int addPadding;             /* +0x14 */
} GHIPost;

typedef struct GHIConnection {
    char pad0[0x164];
    GHIPost *post;              /* +0x164 */
    char pad168[0x198 - 0x168];
    int engine;                 /* +0x198 */
} GHIConnection;

extern int ghiDoSend(struct GHIConnection *connection, char *buffer, int len);
extern int ghiTrySendThenBuffer(struct GHIConnection *connection, char *buffer, int len);

int ghiPostFileMemoryStateDoPosting(GHIPostState *state, GHIConnection *connection)
{
    if (state->data->len == 0)
        return 1;

    if (connection->engine == 0) {
        int rcode;
        do {
            rcode = ghiDoSend(connection, state->data->buffer + state->pos,
                                  state->data->len - state->pos);
            if (rcode == -1)
                return 0;
            state->pos += rcode;
            if (state->data->len == state->pos) {
                if (connection->post->addPadding) {
                    char pad[3] = { 0, 0, 0 };
                    int padlen = 4 - (state->data->len % 4);
                    if (padlen != 4 && padlen > 0) {
                        if (!ghiTrySendThenBuffer(connection, pad, padlen))
                            return 0;
                    }
                }
                return 1;
            }
        } while (rcode != 0);
        return 2;
    } else {
        int result;
        do {
            int len = state->data->len - state->pos;
            if (len >= 0x3f01)
                len = 0x3f01;
            result = ghiTrySendThenBuffer(connection, state->data->buffer + state->pos, len);
            if (!result)
                return 0;
            state->pos += len;
            if (state->data->len == state->pos) {
                if (connection->post->addPadding) {
                    char pad[3] = { 0, 0, 0 };
                    int padlen = 4 - (state->data->len % 4);
                    if (padlen != 4 && padlen > 0) {
                        if (!ghiTrySendThenBuffer(connection, pad, padlen))
                            return 0;
                    }
                }
                return 1;
            }
        } while (result == 1);
        return 2;
    }
}
