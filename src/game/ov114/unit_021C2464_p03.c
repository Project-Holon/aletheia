/*
 * file:     unit_021C2464_p03.c
 * unit:     yes
 * function: func_021C25C8, func_021C2620
 * address:  0x021C25C8
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
 *   g_021CEDCC  0x021CEDCC  data
 *   g_021CEDD0  0x021CEDD0  data
 *   g_021CEDE4  0x021CEDE4  data
 *   g_021CEE28  0x021CEE28  data
 *   g_021CEE34  0x021CEE34  data
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_02181E20  0x02181E20  arm  ov009
 */
struct Post {
	unsigned char pad0[0xc];
	int f0c;
	int f10;
	int f14;
};

struct Conn {
	unsigned char pad0[0x164];
	struct Post *post;
};

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

typedef unsigned char  u8;

extern int func_02184200(const int *p);
extern void *func_02184208(void *, int);
extern int func_0209477C(const u8 *s);
extern int func_02181E20(void *);
char *func_021C25C8(struct Conn *connection);
int func_021C2620(GHIConnection *connection);
extern char g_021CEDCC[];
extern char g_021CEDD0[];
extern char g_021CEDE4[];
extern char g_021CEE28[];
extern char g_021CEE34[];


/*
 * sdk:      ghiPostGetContentType (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
char *func_021C25C8(struct Conn *connection)
{
	struct Post *post = connection->post;

	if (post == 0)
		return g_021CEDCC;
	if (post->f14)
		return g_021CEDD0;
	if (post->f0c)
		return g_021CEDE4;
	if (post->f10)
		return g_021CEE28;
	return g_021CEE34;
}


/*
 * sdk:      ghiPostGetNoFilesContentLength (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * The callee func_02181E20 (ov009, 8 bytes, gsXmlWriterGetDataLength) was the last
 * blocker; it now has a catalog row and a matched body (w3_tools, 2026-09-29).
 */
int func_021C2620(GHIConnection *connection)
{
    GHIPost *post;
    GHIPostData *data;
    int i;
    int num;
    int total;

    post = connection->post;
    total = 0;
    num = func_02184200(post->data);
    if (num == 0)
        return 0;
    for (i = 0; i < num; i++) {
        data = func_02184208(post->data, i);
        if (data->type == 0)
            { total += func_0209477C((const u8 *)data->f4); total += data->fC; total += data->f14 * 2; total += 1; }
        else if (data->type == 3)
            total += func_02181E20(data->f8);
    }
    return total + (num - 1);
}
