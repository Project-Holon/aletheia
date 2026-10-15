/*
 * function: ghiPostAddFileFromMemory
 * address:  0x021C24B4
 * packet:   pkt_ov114_021C24B4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostAddFileFromMemory (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * symbols:
 *   goastrdup  0x0217F1E0  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   ArrayAppend  0x02184234  arm  ov009
 */

typedef struct GHIPostData {
    int type;
    char *name;
    char *buffer;
    int bufferLen;
    char *reportFilename;
    char *contentType;
} GHIPostData;

typedef struct GHIPost {
    void *data;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} GHIPost;

extern char *goastrdup(char *src);
extern void gsifree(void *ptr);
extern void ArrayAppend(void *array, void *newElem);

int ghiPostAddFileFromMemory(GHIPost *_post, char *name, char *buffer, int bufferLen,
                  char *reportFilename, char *contentType)
{
    char *nameLocal;
    char *reportFilenameLocal;
    char *contentTypeLocal;

    nameLocal = goastrdup(name);
    reportFilenameLocal = goastrdup(reportFilename);
    contentTypeLocal = goastrdup(contentType);
    if (nameLocal == 0 || reportFilenameLocal == 0 || contentTypeLocal == 0) {
        gsifree(nameLocal);
        gsifree(reportFilenameLocal);
        gsifree(contentTypeLocal);
        return 0;
    }
    {
        GHIPost *post;
        GHIPostData data = {0};
        data.type = 2;
        data.name = nameLocal;
        data.buffer = buffer;
        data.bufferLen = bufferLen;
        data.reportFilename = reportFilenameLocal;
        data.contentType = contentTypeLocal;
        post = _post;
        ArrayAppend(post->data, &data);
        post->fC = 1;
        if (post->f10 == 1)
            post->f14 = 1;
    }
    return 1;
}
