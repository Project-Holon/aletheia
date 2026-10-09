/*
 * file:     unit_021C2464.c
 * unit:     yes
 * function: func_021C2464, func_021C2490, func_021C24B4, func_021C2584, func_021C25C8, func_021C2620, func_021C26B8, func_021C297C, func_021C29AC, func_021C2A3C, func_021C2A78, func_021C2BB0, func_021C2C28, func_021C2DB0, func_021C2F10, func_021C304C, ghiPostStateDoPosting, func_021C3834
 * address:  0x021C2464
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
 *   func_021C0DA4  0x021C0DA4  arm  ov114
 *   func_021C2BB0  0x021C2BB0  arm  ov114
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_02184234  0x02184234  arm  ov009
 *   g_021CEDCC  0x021CEDCC  data
 *   g_021CEDD0  0x021CEDD0  data
 *   g_021CEDE4  0x021CEDE4  data
 *   g_021CEE28  0x021CEE28  data
 *   g_021CEE34  0x021CEE34  data
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_02181E20  0x02181E20  arm  ov009
 *   strlen         0x0209477C  arm
 *   g_021CEE58     0x021CEE58  data
 *   g_021CEE80     0x021CEE80  data
 *   g_021CEE88     0x021CEE88  data
 *   func_02092004  0x02092004  arm
 *   func_02091D38  0x02091D38  arm
 *   func_02092120  0x02092120  arm
 *   fclose                  0x02091AE8  arm
 *   func_02184144  0x02184144  arm   ov009
 *   func_021C2A3C  0x021C2A3C  arm   ov114
 *   func_021841B0  0x021841B0  arm   ov009
 *   func_021C297C  0x021C297C  arm   ov114
 *   ArrayLength             0x02184200  arm
 *   ArrayNth                0x02184208  arm
 *   ArrayFree               0x021841B0  arm
 *   ghiFreePost             0x021C2464  arm  ov114
 *   func_02094A28  0x02094A28  arm
 *   func_021C0004  0x021C0004  arm   ov114
 *   func_021BFCEC  0x021BFCEC  arm   ov114
 *   func_021C07B8  0x021C07B8  arm   ov114
 *   func_021C011C  0x021C011C  arm   ov114
 *   func_021C00FC  0x021C00FC  arm   ov114
 *   g_021CE0B4     0x021CE0B4  data
 *   g_021CEEB4     0x021CEEB4  data
 *   g_021CED88     0x021CED88  data
 *   func_02181E18  0x02181E18  arm   ov009
 *   func_021BFDEC  0x021BFDEC  arm   ov114
 *   func_020916D4  0x020916D4  arm
 *   func_021C0684                    0x021c0684 arm  ov114
 *   func_021803BC                    0x021803BC arm  ov009
 *   OS_SPrintf                       0x02084F40 arm
 *   g_021CEEC8                       0x021CEEC8 data
 *   g_021CEECC                       0x021CEECC data
 *   g_021CEED4                       0x021CEED4 data
 *   g_021CEEFC                       0x021CEEFC data
 *   g_021CEF28                       0x021CEF28 data
 *   g_021CEF58                       0x021CEF58 data
 *   func_021C3218  0x021C3218  arm  ov114
 *   g_021CEFAC     0x021CEFAC  data
 *   g_021CEFB0     0x021CEFB0  data
 */
#include "ghttp_types.h"
#include "../../matched/arm9_sdk/libc/string.h"

#define GHI_DIME_PAD(total, len)                \
    {                                           \
        int padBytes = 4 - ((len) % 4);         \
        if (padBytes != 4)                      \
            (total) += padBytes;                \
    }
#define GHI_DIME_VERSION         (0x1 << 3)
#define GHI_DIMEFLAG_FIRSTRECORD (1 << 2)
#define GHI_DIMEFLAG_LASTRECORD  (1 << 1)
#define GHI_DIMETYPE_T_MEDIA     (0x1 << 4)
#define GHI_DIMETYPE_T_URI       (0x2 << 4)
#define htons(s) ((u16)((((u16)(s) >> 8) & 0x00ff) | (((u16)(s) << 8) & 0xff00)))
#define htonl(l) ((u32)((((u32)(l) >> 24) & 0x000000ff) | (((u32)(l) >> 8) & 0x0000ff00) | \
                        (((u32)(l) << 8) & 0x00ff0000) | (((u32)(l) << 24) & 0xff000000)))
struct Ctx;
typedef signed int     s32;

typedef enum { GERR, GOK, GBUF } GRes;

typedef struct Hex4 {
    char c[4];
} Hex4;

typedef enum { GHIPostingError, GHIPostingDone, GHIPostingWaitForContinue } GHIPostingResult;

typedef enum { GHITrySendError, GHITrySendSent, GHITrySendBuffered } GHITrySendResult;

typedef struct GSIDimeHeader {
    u8 mVersionAndFlags;
    u8 mTypeT;
    u16 mOptionsLength;
    u16 mIdLength;
    u16 mTypeLength;
    u32 mDataLength;
} GSIDimeHeader;

extern void func_021841B0(void *);
extern void func_0217EAE0(void *);
extern GHIConnection *func_021C0DA4(int request);
extern void func_021C2BB0(GHIConnection *connection);
extern char *func_0217F1E0(char *src);
extern void func_02184234(void *array, void *newElem);
extern int func_02184200(const int *p);
extern void *func_02184208(void *, int);
extern int func_0209477C(const u8 *s);
extern int func_02181E20(void *);
extern int func_02092004(void *, int, int);
extern s32 func_02091D38(u32 a0);
extern int func_02092120(void *);
extern int fclose(void *stream);
extern void *func_02184144(int, int, void (*)(void *));
extern void func_021C2A3C(void *);
extern int func_021C297C(GHIConnection *);
extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern void ArrayFree(void *array);
extern void ghiFreePost(GHIPost *post);
extern u8 *func_02094A28(const u8 *s, int c);
extern int func_021C0004(struct Ctx *ctx, int ch);
extern int func_021BFCEC(GHIBuffer *, char *, int);
extern GRes func_021C07B8(GHIConnection *, char *, int);
extern int func_021C011C(GHIConnection *);
extern void func_021C00FC(GHIBuffer *);
extern char *func_02181E18(void *);
extern int func_021BFDEC(struct GHIBuffer *buffer, const char *data, int dataLen);
extern s32 func_020916D4(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_021C0684(struct GHIConnection *connection, char *buffer, int len);
extern unsigned long func_021803BC(char *dst, char *src, unsigned long size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int func_021C3218(GHIPostState *state, GHIConnection *connection, int first, int last);
void func_021C2464(GHIPost *post);
void func_021C2490(int request, GHIPost *post);
int func_021C24B4(GHIPost *_post, char *name, char *buffer, int bufferLen, char *reportFilename, char *contentType);
int func_021C2584(struct GHIPost *_post, void *xml);
char *func_021C25C8(struct GHIConnection *connection);
int func_021C2620(GHIConnection *connection);
int func_021C26B8(GHIConnection *connection);
int ghiPostGetContentLength(void *connection);
int func_021C29AC(GHIPostState *o);
int func_021C2A78(GHIConnection *connection);
void ghiPostCleanupState(GHIConnection *connection);
GRes func_021C2C28(GHIPostState *state, GHIConnection *connection);
GRes func_021C2DB0(GHIPostState *state, GHIConnection *connection);
int func_021C2F10(GHIPostState *state, GHIConnection *connection);
int func_021C304C(GHIPostState *state, GHIConnection *connection);
int func_021C3834(GHIConnection *connection);
extern char g_021CEDCC[];
extern char g_021CEDD0[];
extern char g_021CEDE4[];
extern char g_021CEE28[];
extern char g_021CEE34[];
extern char g_021CEE58[];
extern char g_021CEE80[];
extern char g_021CEE88[];
extern Hex4 g_021CE0B4;
extern char g_021CEEB4[];
extern char g_021CED88[];
extern char g_021CEEC8[];
extern char g_021CEECC[];
extern char g_021CEED4[];
extern char g_021CEEFC[];
extern char g_021CEF28[];
extern char g_021CEF58[];
extern char g_021CEFAC[];
extern char g_021CEFB0[];



/*
 * Releases the +0x00 handle, clears it, then tears the record down.
 */
void func_021C2464(GHIPost *post)
{
    if (post->data != 0)
        func_021841B0(post->data);
    post->data = 0;
    func_0217EAE0(post);
}



/*
 * Cleans up the post state of the connection for `request`, then frees `post`.
 */
/*
 * Flushes the object selected by `a`, then applies `b`.
 */
void func_021C2490(int request, GHIPost *post)
{
    GHIConnection *connection = func_021C0DA4(request);
    if (connection != 0)
        func_021C2BB0(connection);
    func_021C2464(post);
}



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
        func_0217EAE0((u8 *)nameLocal);
        func_0217EAE0((u8 *)reportFilenameLocal);
        func_0217EAE0((u8 *)contentTypeLocal);
        return 0;
    }
    {
        GHIPost *post;
        GHIPostData data = {0};
        data.type = 2;
        data.name = nameLocal;
        data.data.fileMemory.buffer = buffer;
        data.data.fileMemory.len = bufferLen;
        data.data.fileMemory.reportFilename = reportFilenameLocal;
        data.data.fileMemory.contentType = contentTypeLocal;
        post = _post;
        func_02184234(post->data, &data);
        post->hasFiles = 1;
        if (post->hasSoap == 1)
            post->useDIME = 1;
    }
    return 1;
}



/*
 * sdk:      ghiPostAddXml (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
int func_021C2584(struct GHIPost *_post, void *xml)
{
	struct GHIPost *post;
	struct GHIPostData data;

	post = _post;
	data.type = 3;
	data.data.xml.xml = xml;
	func_02184234(post->data, &data);
	post->hasSoap = 1;
	if (post->hasFiles == 1)
		post->useDIME = 1;
	return 1;
}



/*
 * sdk:      ghiPostGetContentType (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
char *func_021C25C8(struct GHIConnection *connection)
{
	struct GHIPost *post = connection->post;

	if (post == 0)
		return g_021CEDCC;
	if (post->useDIME)
		return g_021CEDD0;
	if (post->hasFiles)
		return g_021CEDE4;
	if (post->hasSoap)
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
            { total += func_0209477C((const u8 *)data->name); total += data->data.fileMemory.len; total += (int)data->data.fileMemory.contentType * 2; total += 1; }
        else if (data->type == 3)
            total += func_02181E20(data->data.fileMemory.buffer);
    }
    return total + (num - 1);
}



/*
 * sdk:      ghiPostGetHasFilesContentLength (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * strlen comes from src/matched/arm9_sdk/libc/string.h: mwccarm treats strlen
 * as not writing memory (so name, length and post->useDIME stay cached in
 * callee-saved registers across it) only when strlen is declared in a header
 * named string.h.  Declared in this file instead, every mismatch is register
 * allocation (DIFF).  The two calls to func_02181E20 (ov009,
 * gsXmlWriterGetDataLength) resolve through its catalog row and matched body.
 */
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
            total += strlen(data->data.fileDisk.contentType);
            state = (GHIPostState *)func_02184208(connection->postingState.states, i);
            total += state->state.fileDisk.len;
            if (!post->useDIME)
                total += strlen(data->data.fileDisk.reportFilename);
            if (post->useDIME)
            {
                GHI_DIME_PAD(total, (int)strlen(data->name));
                GHI_DIME_PAD(total, (int)strlen(data->data.fileDisk.contentType));
                GHI_DIME_PAD(total, state->state.fileDisk.len);
            }
        }
        else if (data->type == 2)
        {
            total += fileBaseLen;
            total += strlen(data->name);
            total += strlen(data->data.fileMemory.contentType);
            total += data->data.fileMemory.len;
            if (!post->useDIME)
                total += strlen(data->data.fileMemory.reportFilename);
            if (post->useDIME)
            {
                GHI_DIME_PAD(total, (int)strlen(data->name));
                GHI_DIME_PAD(total, (int)strlen(data->data.fileMemory.contentType));
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



int ghiPostGetContentLength(void *connection)
{
    void *post = *(void **)((char *)connection + 0x164);

    if (!post)
        return 0;
    if (*(void **)((char *)post + 0xC))
        return func_021C26B8(connection);
    return func_021C2620(connection);
}



int func_021C29AC(GHIPostState *o)
{
    int t = o->data->type;

    o->pos = -1;
    if (t == 0) {
    } else if (t == 1) {
        if (o->state.fileDisk.file == 0)
            return 0;
        if (func_02092004(o->state.fileDisk.file, 0, 2) != 0)
            return 0;
        o->state.fileDisk.len = func_02091D38((u32)o->state.fileDisk.file);
        if (o->state.fileDisk.len == -1)
            return 0;
        func_02092120(o->state.fileDisk.file);
    } else if (t != 2 && t != 3) {
        return 0;
    }
    return 1;
}





static void ghiPostStateCleanup(GHIPostState *state)
{
    int type = state->data->type;

    if (type == 0)
        return;
    if (type != 1)
        return;
    if (state->state.fileDisk.file != 0)
        fclose(state->state.fileDisk.file);
    state->state.fileDisk.file = 0;
}





/*
 * sdk:      ghiPostInitState (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
int func_021C2A78(GHIConnection *connection)
{
    int i;
    int len;
    GHIPost *data;

    data = connection->post;
    if (data == 0)
        return 0;
    connection->postingState.index = 0;
    connection->postingState.bytesPosted = 0;
    connection->postingState.totalBytes = 0;
    connection->postingState.field_1C = 0;
    connection->postingState.callback = data->callback;
    connection->postingState.param = data->param;
    len = func_02184200(data->data);
    connection->postingState.states = func_02184144(0x10, len, 0);
    if (connection->postingState.states == 0)
        return 0;
    for (i = 0; i < len; i++) {
        void *obj = func_02184208(connection->post->data, i);
        GHIPostState state = {0};

        state.data = obj;
        if (func_021C29AC(&state) == 0) {
            for (i--; i >= 0; i--)
                func_021C2A3C(func_02184208(connection->postingState.states, i));
            func_021841B0(connection->postingState.states);
            connection->postingState.states = 0;
            return 0;
        }
        func_02184234(connection->postingState.states, &state);
    }
    connection->postingState.totalBytes = func_021C297C(connection);
    if (connection->post->hasSoap == 1)
        connection->postingState.waitPostContinue = 1;
    else
        connection->postingState.waitPostContinue = 0;
    return 1;
}





void ghiPostCleanupState(GHIConnection *connection)
{
    int i;
    int len;

    if (connection->postingState.states != 0)
    {
        len = ArrayLength(connection->postingState.states);
        for (i = 0; i < len; i++)
        {
            GHIPostState *state = ArrayNth(connection->postingState.states, i);
            ghiPostStateCleanup(state);
        }
        ArrayFree(connection->postingState.states);
        connection->postingState.states = 0;
    }
    if (connection->post != 0 && connection->post->autoFree != 0)
    {
        ghiFreePost(connection->post);
        connection->post = 0;
    }
}





/*
 * sdk:      ghiPostStringStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 *
 * Two spellings were wrong, both invisible to the C semantics:
 *   1. `g_021CE0B4` is a 4-byte object, not `char[]`.  Declaring it
 *      `extern Hex4 g_021CE0B4;` and writing `hex = g_021CE0B4;` makes the
 *      copy the pair-at-a-time struct copy the image has (2 ldrb, 2 strb,
 *      2 ldrb, 2 strb, with the independent `add sb,#0x58` / `mov r6,#0`
 *      scheduled into the gaps).  The `*(Hex4 *)g_021CE0B4` cast form made
 *      MWCC emit four loads then four stores in one solid block (48 concrete
 *      bytes, 20 of them this copy).
 *   2. The two pool globals were swapped: the image's hex table is
 *      `g_021CEEB4` and the character-set string handed to func_02094A28 is
 *      `g_021CED88` (image pool +0x180 = 0x021CEEB4 feeding r4, the table
 *      indexed at +0x0E4/+0x0E8; +0x184 = 0x021CED88 feeding r5, the
 *      func_02094A28 argument).  The parked draft had them the other way
 *      round, which is the last 4 concrete bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov114_func_021C2C28.c \
 *       --func func_021C2C28 --addr 0x021C2C28 --region ov114 --arm \
 *       --cc 1.1p1 --lang c99 --diff
 */
GRes func_021C2C28(GHIPostState *state, GHIConnection *connection)
{
    int i;
    int c;
    char *string;
    Hex4 hex;
    GHIBuffer *writeBuffer;
    GRes result;

    if (state->data->data.string.len == 0)
        return 1;
    if (connection->post->hasFiles == 0 && connection->post->hasSoap == 0 && state->data->data.string.encode != 0) {
        string = state->data->data.string.string;
        writeBuffer = &connection->sendBuffer;
        hex = g_021CE0B4;
        i = 0;
        if (connection->encryptor.engine != 0)
            writeBuffer = &connection->encodeBuffer;
        for (c = string[0]; c != 0; c = string[++i]) {
            if (func_02094A28((const u8 *)g_021CED88, c) != 0) {
                result = func_021C0004((struct Ctx *)writeBuffer, c);
            } else if (c == ' ') {
                result = func_021C0004((struct Ctx *)writeBuffer, '+');
            } else {
                hex.c[1] = g_021CEEB4[c / 16];
                hex.c[2] = g_021CEEB4[c % 16];
                result = func_021BFCEC(writeBuffer, hex.c, 3);
            }
        }
    } else {
        result = func_021C07B8(connection, state->data->data.string.string, state->data->data.string.len);
        if (result == GERR)
            return GERR;
        return GOK;
    }
    if (connection->encryptor.engine == 0) {
        if (func_021C011C(connection) == 0)
            return 0;
        if (connection->sendBuffer.pos == connection->sendBuffer.len)
            func_021C00FC(&connection->sendBuffer);
        return 1;
    }
    return 1;
}





/*
 *           getters) have no catalog row and no verified shard, so the 5 relocations to them
 *           cannot be attested; needs those two ov009 leaves matched first.
 *
 * sdk:      ghiPostXmlStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
GRes func_021C2DB0(GHIPostState *state, GHIConnection *connection)
{
    void *xml = state->data->data.xml.xml;
    char pad[3] = {0, 0, 0};
    int padlen = 0;
    GRes result;

    if (connection->post->useDIME != 0) {
        padlen = 4 - (func_02181E20(xml) % 4);
        if (padlen == 4)
            padlen = 0;
    }
    if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1) {
        if (func_021BFCEC(&connection->encodeBuffer, func_02181E18(xml), func_02181E20(xml)) == 0 ||
            func_021BFCEC(&connection->encodeBuffer, pad, padlen) == 0 ||
            func_021BFDEC(&connection->sendBuffer, connection->encodeBuffer.data, connection->encodeBuffer.len) == 0)
            return 0;
        func_021C00FC(&connection->encodeBuffer);
        if (func_021C011C((GHIConnection *)connection) == 0)
            return 0;
        if (connection->sendBuffer.pos == connection->sendBuffer.len)
            func_021C00FC(&connection->sendBuffer);
        return 1;
    }
    if (func_021C07B8((GHIConnection *)connection, func_02181E18(xml), func_02181E20(xml)) == 0)
        return 0;
    result = func_021C07B8((GHIConnection *)connection, pad, padlen);
    if (result == 0)
        return 0;
    return 1;
}





/*
 * sdk:      ghiPostFileDiskStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
int func_021C2F10(GHIPostState *state, GHIConnection *connection)
{
    char buffer[4096];
    int len;
    int result;

    do {
        len = func_020916D4(buffer, 1, 4096, (u32)state->state.fileDisk.file);
        if (len <= 0) {
            connection->result = 14;
            connection->completed = 1;
            return 0;
        }
        state->pos += len;
        if (state->pos > state->state.fileDisk.len) {
            connection->result = 14;
            connection->completed = 1;
            return 0;
        }
        result = func_021C07B8(connection, buffer, len);
        if (result == 0)
            return 0;
        if (state->pos == state->state.fileDisk.len) {
            if (connection->post->useDIME != 0) {
                char pad[3] = {0, 0, 0};
                int padlen = 4 - (state->state.fileDisk.len % 4);

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





/*
 * sdk:      ghiPostFileMemoryStateDoPosting (ghttppost.o, static)
 */
int func_021C304C(GHIPostState *state, GHIConnection *connection)
{
    if (state->data->data.fileMemory.len == 0)
        return 1;

    if (connection->encryptor.engine == 0) {
        int rcode;
        do {
            rcode = func_021C0684((struct GHIConnection *)connection, state->data->data.fileMemory.buffer + state->pos, state->data->data.fileMemory.len - state->pos);
            if (rcode == -1)
                return 0;
            state->pos += rcode;
            if (state->data->data.fileMemory.len == state->pos) {
                if (connection->post->useDIME) {
                    char pad[3] = { 0, 0, 0 };
                    int padlen = 4 - (state->data->data.fileMemory.len % 4);
                    if (padlen != 4 && padlen > 0) {
                        if (!func_021C07B8(connection, pad, padlen))
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
            int len = state->data->data.fileMemory.len - state->pos;
            if (len >= 0x3f01)
                len = 0x3f01;
            result = func_021C07B8(connection, state->data->data.fileMemory.buffer + state->pos, len);
            if (!result)
                return 0;
            state->pos += len;
            if (state->data->data.fileMemory.len == state->pos) {
                if (connection->post->useDIME) {
                    char pad[3] = { 0, 0, 0 };
                    int padlen = 4 - (state->data->data.fileMemory.len % 4);
                    if (padlen != 4 && padlen > 0) {
                        if (!func_021C07B8(connection, pad, padlen))
                            return 0;
                    }
                }
                return 1;
            }
        } while (result == 1);
        return 2;
    }
}




static GHIPostingResult ghiPostStateDoPosting(GHIPostState *state, GHIConnection *connection,
                                       GHTTPBool first, GHTTPBool last)
{
    int len = 0;
    GHITrySendResult result;

    if (state->pos == -1)
    {
        char buffer[2048];

        state->pos = 0;

        if (!connection->post->hasFiles && !connection->post->hasSoap)
        {
            if (first)
                OS_SPrintf(buffer, g_021CEEC8, state->data->name);
            else
                OS_SPrintf(buffer, g_021CEECC, state->data->name);
        }
        else
        {
            if (state->data->type == 0)
            {
                OS_SPrintf(buffer, g_021CEF28,
                           first ? g_021CEED4 : g_021CEEFC,
                           state->data->name);
            }
            else if (state->data->type == 3)
            {
                if (connection->post->useDIME)
                {
                    int writePos = 0;
                    int padBytes;
                    unsigned long writen;
                    GSIDimeHeader header;

                    header.mVersionAndFlags = GHI_DIME_VERSION;
                    if (first)
                        header.mVersionAndFlags |= GHI_DIMEFLAG_FIRSTRECORD;
                    if (last)
                        header.mVersionAndFlags |= GHI_DIMEFLAG_LASTRECORD;
                    header.mTypeT = GHI_DIMETYPE_T_URI;
                    header.mOptionsLength = 0;
                    header.mIdLength = htons((short)strlen(g_021CEE80));
                    header.mTypeLength = htons((short)strlen(g_021CEE88));
                    header.mDataLength = htonl(func_02181E20(state->data->data.xml.xml));
                    memcpy(&buffer[writePos], &header, sizeof(GSIDimeHeader));
                    writePos += sizeof(GSIDimeHeader);

                    writen = func_021803BC(&buffer[writePos], g_021CEE80, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    writen = func_021803BC(&buffer[writePos], g_021CEE88, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    len = writePos;
                }
                else
                {
                    buffer[0] = '\0';
                }
            }
            else if (state->data->type == 1 || state->data->type == 2)
            {
                char *filename;
                char *contentType;
                int filelen;

                if (state->data->type == 1)
                {
                    filelen = (int)state->state.fileDisk.len;
                    filename = state->data->data.fileDisk.reportFilename;
                    contentType = state->data->data.fileDisk.contentType;
                }
                else
                {
                    filelen = state->data->data.fileMemory.len;
                    filename = state->data->data.fileMemory.reportFilename;
                    contentType = state->data->data.fileMemory.contentType;
                }

                if (connection->post->useDIME)
                {
                    int writePos = 0;
                    int padBytes;
                    unsigned long writen;
                    GSIDimeHeader header;

                    header.mVersionAndFlags = GHI_DIME_VERSION;
                    if (first)
                        header.mVersionAndFlags |= GHI_DIMEFLAG_FIRSTRECORD;
                    if (last)
                        header.mVersionAndFlags |= GHI_DIMEFLAG_LASTRECORD;
                    header.mTypeT = GHI_DIMETYPE_T_MEDIA;
                    header.mOptionsLength = 0;
                    header.mIdLength = htons((short)strlen(state->data->name));
                    header.mTypeLength = htons((short)strlen(contentType));
                    header.mDataLength = htonl(filelen);
                    memcpy(&buffer[writePos], &header, sizeof(GSIDimeHeader));
                    writePos += sizeof(GSIDimeHeader);

                    writen = func_021803BC(&buffer[writePos], state->data->name, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    writen = func_021803BC(&buffer[writePos], contentType, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    len = writePos;
                }
                else
                {
                    OS_SPrintf(buffer, g_021CEF58,
                               first ? g_021CEED4 : g_021CEEFC,
                               state->data->name, filename, contentType);
                }
            }
        }

        if (connection->encryptor.engine != 0 &&
            connection->encryptor.encryptOnBuffer == GHTTPTrue)
        {
            if (len == 0)
                len = (int)strlen(buffer);
            if (!func_021BFDEC(&connection->sendBuffer, buffer, len))
                return GHIPostingError;
            if (!func_021C011C(connection))
                return GHIPostingError;
            if (connection->sendBuffer.pos < connection->sendBuffer.len)
                return GHIPostingWaitForContinue;
            func_021C00FC(&connection->sendBuffer);
        }
        else
        {
            if (len == 0)
                len = (int)strlen(buffer);
            result = func_021C07B8(connection, buffer, len);
            if (result == GHITrySendError)
                return GHIPostingError;
            if (result == GHITrySendBuffered)
                return GHIPostingWaitForContinue;
            func_021C00FC(&connection->sendBuffer);
        }
    }

    if (state->data->type == 0)
        return func_021C2C28(state, connection);
    if (state->data->type == 3)
        return func_021C2DB0(state, connection);
    if (state->data->type == 1)
        return func_021C2F10(state, connection);
    return func_021C304C(state, connection);
}




/*
 * sdk:      ghiPostDoPosting (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 */
int func_021C3834(GHIConnection *connection)
{

    GHIPostState *postState;
    int len;
    int result;

    len = func_02184200(connection->postingState.states);

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
    {
        if (!func_021C011C(connection))
            return 0;
        if (connection->sendBuffer.pos < connection->sendBuffer.len)
            return 2;
        func_021C00FC((GHIBuffer *)(&connection->sendBuffer));
        if (connection->postingState.waitPostContinue)
            return 3;
        if (connection->postingState.index == len)
            return 1;
    }

    if (connection->postingState.waitPostContinue)
    {
        if (connection->post->hasFiles || connection->post->hasSoap)
        {
            result = func_021C07B8(connection, g_021CEFAC, func_0209477C((const u8 *)g_021CEFAC));
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
        result = func_021C3218((GHIPostState *)postState, (GHIConnection *)connection, (connection->postingState.index == 0) ? 1 : 0, (connection->postingState.index == func_02184200(connection->postingState.states) - 1) ? 1 : 0);
        if (result == 0)
            return 0;
        if (result == 2)
            return 2;
    }

    if (connection->encryptor.engine != 0 && connection->encodeBuffer.len > 0)
    {
        if (!func_021BFDEC((GHIBuffer *)((struct GHIBuffer *)(&connection->sendBuffer)), (char *)(connection->encodeBuffer.data), connection->encodeBuffer.len))
            return 0;
        func_021C00FC((GHIBuffer *)(&connection->encodeBuffer));
    }

    if (connection->post->hasFiles && !connection->post->useDIME)
    {
        if (!func_021C07B8(connection, g_021CEFB0, func_0209477C((const u8 *)g_021CEFB0)))
            return 0;
    }

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
        return 2;
    return 1;
}
