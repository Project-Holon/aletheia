/*
 * function: ghiPostGetNoFilesContentLength
 * address:  0x021C2620
 * packet:   pkt_ov114_021C2620
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiPostGetNoFilesContentLength (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * symbols:
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   strlen  0x0209477C  arm
 *   gsXmlWriterGetDataLength  0x02181E20  arm  ov009
 *
 * The callee gsXmlWriterGetDataLength (ov009, 8 bytes, gsXmlWriterGetDataLength) was the last
 * blocker; it now has a catalog row and a matched body (w3_tools, 2026-09-29).
 */

typedef struct GHIPostData {
    int type;
    char *f4;
    void *f8;
    int fC;
    int f10;
    int f14;
} GHIPostData;

typedef struct GHIPost {
    void *data;
} GHIPost;

typedef struct GHIConnection {
    unsigned char pad0[0x164];
    GHIPost *post;
} GHIConnection;

extern int ArrayLength(const int *p);
extern void *func_02184208(void *, int);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int gsXmlWriterGetDataLength(void *);

int ghiPostGetNoFilesContentLength(GHIConnection *connection)
{
    GHIPost *post;
    GHIPostData *data;
    int i;
    int num;
    int total;

    post = connection->post;
    total = 0;
    num = ArrayLength(post->data);
    if (num == 0)
        return 0;
    for (i = 0; i < num; i++) {
        data = func_02184208(post->data, i);
        if (data->type == 0)
            { total += strlen((const u8 *)data->f4); total += data->fC; total += data->f14 * 2; total += 1; }
        else if (data->type == 3)
            total += gsXmlWriterGetDataLength(data->f8);
    }
    return total + (num - 1);
}
