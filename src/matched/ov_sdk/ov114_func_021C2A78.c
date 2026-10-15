/*
 * function: ghiPostInitState
 * address:  0x021C2A78
 * packet:   pkt_ov114_021C2A78
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostInitState (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * symbols:
 *   ArrayLength  0x02184200  arm   ov009
 *   func_02184144  0x02184144  arm   ov009
 *   func_02184208  0x02184208  arm   ov009
 *   ghiPostStateInit  0x021C29AC  arm   ov114
 *   ghiPostStateCleanup  0x021C2A3C  arm   ov114
 *   func_021841B0  0x021841B0  arm   ov009
 *   ArrayAppend  0x02184234  arm   ov009
 *   ghiPostGetContentLength  0x021C297C  arm   ov114
 */

typedef struct GHIPostData {
    void *objects;
    int type;
    int p8;
    int pC;
    int mode;
} GHIPostData;

typedef struct GHIPostState {
    void *data;
    int f4;
    void *f8;
    int fC;
} GHIPostState;

typedef struct GHIConnection {
    char pad[0x164];
    GHIPostData *postData;
    void *states;
    int i16C;
    int i170;
    int contentLength;
    int i178;
    int i17C;
    int isPost;
    int i184;
} GHIConnection;

extern int ArrayLength(const int *p);
extern void *func_02184144(int, int, void (*)(void *));
extern void *func_02184208(void *, int);
struct Obj;
extern int ghiPostStateInit(struct Obj *o);
extern void ghiPostStateCleanup(void *);
extern void func_021841B0(void *);
extern void ArrayAppend(void *, void *);
extern int ghiPostGetContentLength(GHIConnection *);

int ghiPostInitState(GHIConnection *connection)
{
    int i;
    int len;
    GHIPostData *data;

    data = connection->postData;
    if (data == 0)
        return 0;
    connection->i16C = 0;
    connection->i170 = 0;
    connection->contentLength = 0;
    connection->i184 = 0;
    connection->i178 = data->type;
    connection->i17C = data->p8;
    len = ArrayLength(data->objects);
    connection->states = func_02184144(0x10, len, 0);
    if (connection->states == 0)
        return 0;
    for (i = 0; i < len; i++) {
        void *obj = func_02184208(connection->postData->objects, i);
        GHIPostState state = {0};

        state.data = obj;
        if (ghiPostStateInit((struct Obj *)(&state)) == 0) {
            for (i--; i >= 0; i--)
                ghiPostStateCleanup(func_02184208(connection->states, i));
            func_021841B0(connection->states);
            connection->states = 0;
            return 0;
        }
        ArrayAppend(connection->states, &state);
    }
    connection->contentLength = ghiPostGetContentLength(connection);
    if (connection->postData->mode == 1)
        connection->isPost = 1;
    else
        connection->isPost = 0;
    return 1;
}
