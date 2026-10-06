/*
 * function: func_021C3834
 * address:  0x021C3834
 * packet:   pkt_ov114_021C3834
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostDoPosting (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * symbols:
 *   func_02184200  0x02184200  arm  ov009
 *   func_021C011C  0x021C011C  arm  ov114
 *   func_021C00FC  0x021C00FC  arm  ov114
 *   func_0209477C  0x0209477C  arm
 *   func_021C07B8  0x021C07B8  arm  ov114
 *   func_02184208  0x02184208  arm  ov009
 *   func_021C3218  0x021C3218  arm  ov114
 *   func_021BFDEC  0x021BFDEC  arm  ov114
 *   g_021CEFAC     0x021CEFAC  data
 *   g_021CEFB0     0x021CEFB0  data
 */

typedef struct {
    void *connection;
    char *data;
    int size;
    int len;
    int pos;
    char pad14[0x10];
} GHIBuffer;

typedef struct {
    char pad00[0x0C];
    int hasFiles;               /* 0x0C */
    int useDIME;                /* 0x10 */
    int hasSoap;                /* 0x14 */
} GHIPost;

typedef struct {
    void *states;               /* 0x168 */
    int index;                  /* 0x16C */
    int bytePosted;             /* 0x170 */
    int totalBytes;             /* 0x174 */
    void *callback;             /* 0x178 */
    void *param;                /* 0x17C */
    int waitPostContinue;       /* 0x180 */
} GHIPostingState;

typedef struct {
    char pad000[0x58];
    GHIBuffer sendBuffer;       /* 0x058 */
    GHIBuffer encodeBuffer;     /* 0x07C */
    char pad0A0[0xC4];
    GHIPost *post;              /* 0x164 */
    GHIPostingState postingState; /* 0x168 */
    char pad184[0x14];
    void *encryptEngine;        /* 0x198 */
} GHIConnection;

typedef struct GHIPostState GHIPostState;

extern int func_02184200(const int *p);
typedef unsigned char  u8;
struct GHIBuffer;
struct GHIConnection;
extern int func_021C011C(struct GHIConnection *connection);
extern void func_021C00FC(GHIBuffer *buffer);
extern int func_0209477C(const u8 *s);
extern int func_021C07B8(struct GHIConnection *connection, char *buffer, int len);
extern void *func_02184208(void *array, int n);
extern int func_021C3218(GHIPostState *state, GHIConnection *connection, int first, int last);
extern int func_021BFDEC(struct GHIBuffer *buffer, const char *data, int dataLen);
extern char g_021CEFAC[];
extern char g_021CEFB0[];

int func_021C3834(GHIConnection *connection)
{

    GHIPostState *postState;
    int len;
    int result;

    len = func_02184200(connection->postingState.states);

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
    {
        if (!func_021C011C((struct GHIConnection *)connection))
            return 0;
        if (connection->sendBuffer.pos < connection->sendBuffer.len)
            return 2;
        func_021C00FC(&connection->sendBuffer);
        if (connection->postingState.waitPostContinue)
            return 3;
        if (connection->postingState.index == len)
            return 1;
    }

    if (connection->postingState.waitPostContinue)
    {
        if (connection->post->hasFiles || connection->post->useDIME)
        {
            result = func_021C07B8((struct GHIConnection *)connection, g_021CEFAC, func_0209477C((const u8 *)g_021CEFAC));
            if (result == 0)
                return 0;
            if (result == 2)
                return 2;
            if (connection->postingState.waitPostContinue == 1)
                return 3;
        }
        else
        {
            connection->postingState.waitPostContinue = 0;
        }
    }

    for (; connection->postingState.index < len; connection->postingState.index++)
    {
        postState = func_02184208(connection->postingState.states, connection->postingState.index);
        result = func_021C3218(postState, connection, (connection->postingState.index == 0) ? 1 : 0,
                               (connection->postingState.index == func_02184200(connection->postingState.states) - 1) ? 1 : 0);
        if (result == 0)
            return 0;
        if (result == 2)
            return 2;
    }

    if (connection->encryptEngine != 0 && connection->encodeBuffer.len > 0)
    {
        if (!func_021BFDEC((struct GHIBuffer *)(&connection->sendBuffer), connection->encodeBuffer.data, connection->encodeBuffer.len))
            return 0;
        func_021C00FC(&connection->encodeBuffer);
    }

    if (connection->post->hasFiles && !connection->post->hasSoap)
    {
        if (!func_021C07B8((struct GHIConnection *)connection, g_021CEFB0, func_0209477C((const u8 *)g_021CEFB0)))
            return 0;
    }

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
        return 2;
    return 1;
}
