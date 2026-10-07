/*
 * file:     unit_021C2464_p05.c
 * unit:     yes
 * function: func_021C2A3C, func_021C2A78
 * address:  0x021C2A3C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   fclose                  0x02091AE8  arm
 *   func_02184200  0x02184200  arm   ov009
 *   func_02184144  0x02184144  arm   ov009
 *   func_02184208  0x02184208  arm   ov009
 *   func_021C29AC  0x021C29AC  arm   ov114
 *   func_021C2A3C  0x021C2A3C  arm   ov114
 *   func_021841B0  0x021841B0  arm   ov009
 *   func_02184234  0x02184234  arm   ov009
 *   func_021C297C  0x021C297C  arm   ov114
 */
struct Obj;
typedef struct {
    int type;
} GHIPost;

typedef struct {
    GHIPost *post;
    int field04;
    void *stream;
} GHIPostState_021C2A3C;

typedef struct GHIPostData {
    void *objects;
    int type;
    int p8;
    int pC;
    int mode;
} GHIPostData;

typedef struct GHIPostState_021C2A78 {
    void *data;
    int f4;
    void *f8;
    int fC;
} GHIPostState_021C2A78;

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

extern int fclose(void *stream);
extern int func_02184200(const int *p);
extern void *func_02184144(int, int, void (*)(void *));
extern void *func_02184208(void *, int);
extern int func_021C29AC(struct Obj *o);
extern void func_021C2A3C(void *);
extern void func_021841B0(void *);
extern void func_02184234(void *, void *);
extern int func_021C297C(GHIConnection *);
int func_021C2A78(GHIConnection *connection);


static void ghiPostStateCleanup(GHIPostState_021C2A3C *state)
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


/*
 * sdk:      ghiPostInitState (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
int func_021C2A78(GHIConnection *connection)
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
    len = func_02184200(data->objects);
    connection->states = func_02184144(0x10, len, 0);
    if (connection->states == 0)
        return 0;
    for (i = 0; i < len; i++) {
        void *obj = func_02184208(connection->postData->objects, i);
        GHIPostState_021C2A78 state = {0};

        state.data = obj;
        if (func_021C29AC((struct Obj *)(&state)) == 0) {
            for (i--; i >= 0; i--)
                func_021C2A3C(func_02184208(connection->states, i));
            func_021841B0(connection->states);
            connection->states = 0;
            return 0;
        }
        func_02184234(connection->states, &state);
    }
    connection->contentLength = func_021C297C(connection);
    if (connection->postData->mode == 1)
        connection->isPost = 1;
    else
        connection->isPost = 0;
    return 1;
}
