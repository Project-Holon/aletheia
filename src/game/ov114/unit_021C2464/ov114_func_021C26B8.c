/*
 * function: func_021C26B8
 * address:  0x021C26B8
 * packet:   pkt_ov114_021C26B8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostGetHasFilesContentLength (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * symbols:
 *   strlen         0x0209477C  arm
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_02181E20  0x02181E20  arm  ov009
 *   g_021CEE58     0x021CEE58  data
 *   g_021CEE80     0x021CEE80  data
 *   g_021CEE88     0x021CEE88  data
 *
 * strlen comes from src/matched/arm9_sdk/libc/string.h: mwccarm treats strlen
 * as not writing memory (so name, length and post->useDIME stay cached in
 * callee-saved registers across it) only when strlen is declared in a header
 * named string.h.  Declared in this file instead, every mismatch is register
 * allocation (DIFF).  The two calls to func_02181E20 (ov009,
 * gsXmlWriterGetDataLength) resolve through its catalog row and matched body.
 */

typedef struct {
    int type;                   /* 0x00 */
    char *name;                 /* 0x04 */
    union {
        struct {
            char *string;       /* 0x08 */
            int len;            /* 0x0C */
        } string;
        struct {
            char *filename;     /* 0x08 */
            char *contentType;  /* 0x0C */
            char *reportFilename; /* 0x10 */
        } fileDisk;
        struct {
            char *buffer;       /* 0x08 */
            int len;            /* 0x0C */
            char *contentType;  /* 0x10 */
            char *reportFilename; /* 0x14 */
        } fileMemory;
        struct {
            void *xml;          /* 0x08 */
        } xml;
    } data;
} GHIPostData;

typedef struct {
    char pad00[0x0C];
    int size;                   /* 0x0C */
} GHIPostState;

typedef struct {
    void *data;                 /* 0x00 */
    char pad04[0x10];
    int useDIME;                /* 0x14 */
} GHIPost;

typedef struct {
    char pad000[0x164];
    GHIPost *post;              /* 0x164 */
    void *postStates;           /* 0x168 */
} GHIConnection;

#include "../../../matched/arm9_sdk/libc/string.h"
extern int func_02184200(void *array);
extern void *func_02184208(void *array, int n);
extern int func_02181E20(void *writer);
extern char g_021CEE58[];
extern char g_021CEE80[];
extern char g_021CEE88[];

#define GHI_DIME_PAD(total, len)                \
    {                                           \
        int padBytes = 4 - ((len) % 4);         \
        if (padBytes != 4)                      \
            (total) += padBytes;                \
    }

int func_021C26B8(GHIConnection *connection)
{
    GHIPost *post = connection->post;
    GHIPostData *data;
    int i;
    int num;
    int total = 0;
    int boundaryLen;
    int stringBaseLen;
    int fileBaseLen;
    int endLen;
    int xmlBaseLen;

    if (post->useDIME)
    {
        stringBaseLen = 12;
        fileBaseLen = 12;
        xmlBaseLen = 12;
        endLen = 0;
    }
    else
    {
        boundaryLen = strlen(g_021CEE58);
        stringBaseLen = boundaryLen + 47;
        fileBaseLen = boundaryLen + 76;
        xmlBaseLen = 0;
        endLen = boundaryLen + 4;
    }

    num = func_02184200(post->data);
    for (i = 0; i < num; i++)
    {
        data = (GHIPostData *)func_02184208(post->data, i);
        if (data->type == 0)
        {
            total += stringBaseLen;
            total += strlen(data->name);
            total += data->data.string.len;
        }
        else if (data->type == 1)
        {
            GHIPostState *state;

            total += fileBaseLen;
            total += strlen(data->name);
            total += strlen(data->data.fileDisk.reportFilename);
            state = (GHIPostState *)func_02184208(connection->postStates, i);
            total += state->size;
            if (!post->useDIME)
                total += strlen(data->data.fileDisk.contentType);
            if (post->useDIME)
            {
                GHI_DIME_PAD(total, (int)strlen(data->name));
                GHI_DIME_PAD(total, (int)strlen(data->data.fileDisk.reportFilename));
                GHI_DIME_PAD(total, state->size);
            }
        }
        else if (data->type == 2)
        {
            total += fileBaseLen;
            total += strlen(data->name);
            total += strlen(data->data.fileMemory.reportFilename);
            total += data->data.fileMemory.len;
            if (!post->useDIME)
                total += strlen(data->data.fileMemory.contentType);
            if (post->useDIME)
            {
                GHI_DIME_PAD(total, (int)strlen(data->name));
                GHI_DIME_PAD(total, (int)strlen(data->data.fileMemory.reportFilename));
                GHI_DIME_PAD(total, data->data.fileMemory.len);
            }
        }
        else if (data->type == 3)
        {
            total += xmlBaseLen;
            total += func_02181E20(data->data.xml.xml);
            GHI_DIME_PAD(total, func_02181E20(data->data.xml.xml));
            total += strlen(g_021CEE80);
            GHI_DIME_PAD(total, (int)strlen(g_021CEE80));
            total += strlen(g_021CEE88);
            GHI_DIME_PAD(total, (int)strlen(g_021CEE88));
        }
        else
        {
            return 0;
        }
    }

    return total + endLen;
}
