/*
 * function: func_021C2F10
 * address:  0x021C2F10
 * packet:   pkt_ov114_021C2F10
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostFileDiskStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * symbols:
 *   func_020916D4  0x020916D4  arm
 *   func_021C07B8  0x021C07B8  arm   ov114
 */

typedef struct GHIPostData {
    char pad[0x14];
    int flag14;
} GHIPostData;

typedef struct GHIPostState {
    void *data;
    int pos;
    void *file;
    int length;
} GHIPostState;

typedef struct GHIConnection {
    char pad0[0x40];
    int state;
    char pad44[0x124 - 0x44];
    int completed;
    char pad128[0x164 - 0x128];
    GHIPostData *postData;
} GHIConnection;

extern int func_020916D4(void *, int, int, void *);
extern int func_021C07B8(GHIConnection *, char *, int);

int func_021C2F10(GHIPostState *state, GHIConnection *connection)
{
    char buffer[4096];
    int len;
    int result;

    do {
        len = func_020916D4(buffer, 1, 4096, state->file);
        if (len <= 0) {
            connection->state = 14;
            connection->completed = 1;
            return 0;
        }
        state->pos += len;
        if (state->pos > state->length) {
            connection->state = 14;
            connection->completed = 1;
            return 0;
        }
        result = func_021C07B8(connection, buffer, len);
        if (result == 0)
            return 0;
        if (state->pos == state->length) {
            if (connection->postData->flag14 != 0) {
                char pad[3] = {0, 0, 0};
                int padlen = 4 - (state->length % 4);

                if (padlen != 4 && padlen > 0) {
                    result = func_021C07B8(connection, pad, padlen);
                    if (result == 0)
                        return 0;
                }
            }
            return 1;
        }
    } while (result == 1);
    return 2;
}
