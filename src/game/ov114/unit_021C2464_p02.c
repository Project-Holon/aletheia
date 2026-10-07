/*
 * file:     unit_021C2464_p02.c
 * unit:     yes
 * function: func_021C24B4, func_021C2584
 * address:  0x021C24B4
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
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_02184234  0x02184234  arm  ov009
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

struct PostData {
	int type;
	int pad;
	void *xml;
	int rest[3];
};

struct Post {
	void *array;
	unsigned char pad0[8];
	int f0c;
	int f10;
	int f14;
};

extern char *func_0217F1E0(char *src);
extern void func_0217EAE0(void *ptr);
extern void func_02184234(void *array, void *newElem);
int func_021C24B4(GHIPost *_post, char *name, char *buffer, int bufferLen, char *reportFilename, char *contentType);
int func_021C2584(struct Post *_post, void *xml);


/*
 * sdk:      ghiPostAddFileFromMemory (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 */
int func_021C24B4(GHIPost *_post, char *name, char *buffer, int bufferLen,
                  char *reportFilename, char *contentType)
{
    char *nameLocal;
    char *reportFilenameLocal;
    char *contentTypeLocal;

    nameLocal = func_0217F1E0(name);
    reportFilenameLocal = func_0217F1E0(reportFilename);
    contentTypeLocal = func_0217F1E0(contentType);
    if (nameLocal == 0 || reportFilenameLocal == 0 || contentTypeLocal == 0) {
        func_0217EAE0(nameLocal);
        func_0217EAE0(reportFilenameLocal);
        func_0217EAE0(contentTypeLocal);
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
        func_02184234(post->data, &data);
        post->fC = 1;
        if (post->f10 == 1)
            post->f14 = 1;
    }
    return 1;
}


/*
 * sdk:      ghiPostAddXml (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
int func_021C2584(struct Post *_post, void *xml)
{
	struct Post *post;
	struct PostData data;

	post = _post;
	data.type = 3;
	data.xml = xml;
	func_02184234(post->array, &data);
	post->f10 = 1;
	if (post->f0c == 1)
		post->f14 = 1;
	return 1;
}
