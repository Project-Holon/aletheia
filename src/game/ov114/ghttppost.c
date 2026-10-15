/*
 * file:     ghttppost.c
 * unit:     yes
 * function: ghiPostDataFree, ghiNewPost, ghiPostSetAutoFree, ghiFreePost, ghiFreePostAndUpdateConnection, ghiPostAddFileFromMemory, ghiPostAddXml, ghiPostGetContentType, ghiPostGetNoFilesContentLength, ghiPostGetHasFilesContentLength, ghiPostGetContentLength, ghiPostStateInit, ghiPostStateCleanup, ghiPostInitState, ghiPostCleanupState, ghiPostStringStateDoPosting, ghiPostXmlStateDoPosting, ghiPostFileDiskStateDoPosting, ghiPostFileMemoryStateDoPosting, ghiPostStateDoPosting, ghiPostDoPosting
 * address:  0x021C235C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Word setter at +0x18.
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm
 *   gsXmlFreeWriter  0x02181D84  arm
 *   func_0217EAB0                  0x0217EAB0  arm ov009
 *   func_02184144                  0x02184144  arm ov009
 *   ghiRequestToConnection  0x021C0DA4  arm  ov114
 *   ghiPostCleanupState  0x021C2BB0  arm  ov114
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_02184234  0x02184234  arm  ov009
 *   sGhttpPostEmptyContentType  0x021CEDCC  data
 *   sGhttpApplicationDime  0x021CEDD0  data
 *   sGhttpMultipartFormDataBoundaryQr  0x021CEDE4  data
 *   sGhttpTextXml  0x021CEE28  data
 *   sGhttpApplicationXWwwFormUrlencoded  0x021CEE34  data
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   gsXmlWriterGetDataLength  0x02181E20  arm  ov009
 *   strlen         0x0209477C  arm
 *   sGhttpQrGSDD     0x021CEE58  data
 *   sGhttpCidId     0x021CEE80  data
 *   sGhttpHttpSchemasXmlsoapOrgSoap     0x021CEE88  data
 *   func_02092004  0x02092004  arm
 *   func_02091D38  0x02091D38  arm
 *   func_02092120  0x02092120  arm
 *   fclose                  0x02091AE8  arm
 *   ghiPostStateCleanup  0x021C2A3C  arm   ov114
 *   func_021841B0  0x021841B0  arm   ov009
 *   ghiPostGetContentLength  0x021C297C  arm   ov114
 *   ArrayLength             0x02184200  arm
 *   ArrayNth                0x02184208  arm
 *   ArrayFree               0x021841B0  arm
 *   ghiFreePost             0x021C2464  arm  ov114
 *   func_02094A28  0x02094A28  arm
 *   ghiAppendCharToBuffer  0x021C0004  arm   ov114
 *   ghiAppendDataToBuffer  0x021BFCEC  arm   ov114
 *   ghiTrySendThenBuffer  0x021C07B8  arm   ov114
 *   ghiSendBufferedData  0x021C011C  arm   ov114
 *   ghiResetBuffer  0x021C00FC  arm   ov114
 *   sGhttpUrlEscapeTemplate     0x021CE0B4  data
 *   sGhttpHexDigits     0x021CEEB4  data
 *   sGhttpUrlSafeChars     0x021CED88  data
 *   gsXmlWriterGetData  0x02181E18  arm   ov009
 *   ghiEncryptDataToBuffer  0x021BFDEC  arm   ov114
 *   func_020916D4  0x020916D4  arm
 *   ghiDoSend                    0x021c0684 arm  ov114
 *   func_021803BC                    0x021803BC arm  ov009
 *   OS_SPrintf                       0x02084F40 arm
 *   sGhttpPostFirstFieldFormat                       0x021CEEC8 data
 *   sGhttpPostNextFieldFormat                       0x021CEECC data
 *   sGhttpQrGSDD2                       0x021CEED4 data
 *   sGhttpQrGSDD3                       0x021CEEFC data
 *   sGhttpContentDispositionFormDataName                       0x021CEF28 data
 *   sGhttpContentDispositionFormDataName2                       0x021CEF58 data
 *   ghiPostStateDoPosting  0x021C3218  arm  ov114
 *   sGhttpPostLineEnd     0x021CEFAC  data
 *   sGhttpQrGSDD4     0x021CEFB0  data
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
typedef signed int s32;

/* "%XX" escape sequence being built for URL-encoded post strings. */
typedef struct UrlEscape {
    char c[4];
} UrlEscape;

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

extern void func_0217EAE0(void *);
extern void gsXmlFreeWriter(void *);
extern void *func_0217EAB0(unsigned long size);
extern void *func_02184144(int, int, void (*)(void *));
extern void func_021841B0(void *);
extern GHIConnection *ghiRequestToConnection(int request);
extern void ghiPostCleanupState(GHIConnection *connection);
extern char *func_0217F1E0(char *src);
extern void func_02184234(void *array, void *newElem);
extern int func_02184200(const int *p);
extern void *func_02184208(void *, int);
extern int func_0209477C(const u8 *s);
extern int gsXmlWriterGetDataLength(void *);
extern int func_02092004(void *, int, int);
extern s32 func_02091D38(u32 a0);
extern int func_02092120(void *);
extern int fclose(void *stream);
void ghiPostStateCleanup(GHIPostState *state);
extern int ghiPostGetContentLength(GHIConnection *);
extern int ArrayLength(void *array);
extern void *ArrayNth(void *array, int n);
extern void ArrayFree(void *array);
extern void ghiFreePost(GHIPost *post);
extern u8 *func_02094A28(const u8 *s, int c);
extern int ghiAppendCharToBuffer(GHIBuffer *buffer, int ch);
extern int ghiAppendDataToBuffer(GHIBuffer *, char *, int);
extern GHITrySendResult ghiTrySendThenBuffer(GHIConnection *, char *, int);
extern int ghiSendBufferedData(GHIConnection *);
extern void ghiResetBuffer(GHIBuffer *);
extern char *gsXmlWriterGetData(void *);
extern int ghiEncryptDataToBuffer(struct GHIBuffer *buffer, const char *data, int dataLen);
extern s32 func_020916D4(void *a0, u32 a1, u32 a2, u32 a3);
extern int ghiDoSend(struct GHIConnection *connection, char *buffer, int len);
extern unsigned long func_021803BC(char *dst, char *src, unsigned long size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
GHIPostingResult ghiPostStateDoPosting(GHIPostState *state, GHIConnection *connection,
                                       GHTTPBool first, GHTTPBool last);
void ghiPostDataFree(void *elem);
GHIPost *ghiNewPost(void);
void ghiPostSetAutoFree(GHIPost *post, GHTTPBool autoFree);
void ghiFreePostAndUpdateConnection(int request, GHIPost *post);
int ghiPostAddFileFromMemory(GHIPost *_post, char *name, char *buffer, int bufferLen, char *reportFilename, char *contentType);
int ghiPostAddXml(struct GHIPost *_post, void *xml);
char *ghiPostGetContentType(struct GHIConnection *connection);
int ghiPostGetNoFilesContentLength(GHIConnection *connection);
int ghiPostGetHasFilesContentLength(GHIConnection *connection);
int ghiPostStateInit(GHIPostState *o);
int ghiPostInitState(GHIConnection *connection);
GHIPostingResult ghiPostStringStateDoPosting(GHIPostState *state, GHIConnection *connection);
GHIPostingResult ghiPostXmlStateDoPosting(GHIPostState *state, GHIConnection *connection);
int ghiPostFileDiskStateDoPosting(GHIPostState *state, GHIConnection *connection);
int ghiPostFileMemoryStateDoPosting(GHIPostState *state, GHIConnection *connection);
int ghiPostDoPosting(GHIConnection *connection);
extern char sGhttpPostEmptyContentType[];
extern char sGhttpApplicationDime[];
extern char sGhttpMultipartFormDataBoundaryQr[];
extern char sGhttpTextXml[];
extern char sGhttpApplicationXWwwFormUrlencoded[];
extern char sGhttpQrGSDD[];
extern char sGhttpCidId[];
extern char sGhttpHttpSchemasXmlsoapOrgSoap[];
extern UrlEscape sGhttpUrlEscapeTemplate;
extern char sGhttpHexDigits[];
extern char sGhttpUrlSafeChars[];
extern char sGhttpPostFirstFieldFormat[];
extern char sGhttpPostNextFieldFormat[];
extern char sGhttpQrGSDD2[];
extern char sGhttpQrGSDD3[];
extern char sGhttpContentDispositionFormDataName[];
extern char sGhttpContentDispositionFormDataName2[];
extern char sGhttpPostLineEnd[];
extern char sGhttpQrGSDD4[];



void ghiPostDataFree(void *element)
{
    GHIPostData *data = element;
    if (data->type != 3)
        func_0217EAE0(data->name);
    if (data->type == 0) {
        func_0217EAE0(data->data.string.string);
    } else if (data->type == 1) {
        func_0217EAE0(data->data.fileDisk.filename);
        func_0217EAE0(data->data.fileDisk.reportFilename);
        func_0217EAE0(data->data.fileDisk.contentType);
    } else if (data->type == 2) {
        func_0217EAE0(data->data.fileMemory.reportFilename);
        func_0217EAE0(data->data.fileMemory.contentType);
    } else if (data->type == 3) {
        gsXmlFreeWriter(data->data.xml.xml);
    }
}



/*
 * sdk:      ghiNewPost (ghttppost.o)
 */
GHIPost *ghiNewPost(void)
{
    GHIPost *post;

    post = func_0217EAB0(sizeof(GHIPost));
    if (post == 0)
        return 0;
    memset(post, 0, sizeof(GHIPost));
    post->autoFree = GHTTPTrue;
    post->data = func_02184144(0x18, 0, ghiPostDataFree);
    if (post->data == 0) {
        func_0217EAE0(post);
        return 0;
    }
    return post;
}


void ghiPostSetAutoFree(GHIPost *post, GHTTPBool autoFree)
{
    post->autoFree = autoFree;
}




/*
 * Frees the element array and the post record.
 */
void ghiFreePost(GHIPost *post)
{
    if (post->data != 0)
        func_021841B0(post->data);
    post->data = 0;
    func_0217EAE0(post);
}




/*
 * Cleans up the post state of the connection for `request`, then frees `post`.
 */
void ghiFreePostAndUpdateConnection(int request, GHIPost *post)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection != 0)
        ghiPostCleanupState(connection);
    ghiFreePost(post);
}




/*
 * sdk:      ghiPostAddFileFromMemory (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 */
int ghiPostAddFileFromMemory(GHIPost *_post, char *name, char *buffer, int bufferLen,
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
int ghiPostAddXml(struct GHIPost *_post, void *xml)
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
char *ghiPostGetContentType(struct GHIConnection *connection)
{
    struct GHIPost *post = connection->post;

    if (post == 0)
        return sGhttpPostEmptyContentType;
    if (post->useDIME)
        return sGhttpApplicationDime;
    if (post->hasFiles)
        return sGhttpMultipartFormDataBoundaryQr;
    if (post->hasSoap)
        return sGhttpTextXml;
    return sGhttpApplicationXWwwFormUrlencoded;
}




/*
 * sdk:      ghiPostGetNoFilesContentLength (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 */
int ghiPostGetNoFilesContentLength(GHIConnection *connection)
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
        if (data->type == 0) {
            total += func_0209477C((const u8 *)data->name);
            total += data->data.string.len;
            total += data->data.string.escapedCount * 2;
            total += 1;
        } else if (data->type == 3)
            total += gsXmlWriterGetDataLength(data->data.fileMemory.buffer);
    }
    return total + (num - 1);
}




/*
 * sdk:      ghiPostGetHasFilesContentLength (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 *
 * strlen must come from string.h: the compiler then knows it does not write
 * memory and keeps name, length and post->useDIME in registers across it.
 */
int ghiPostGetHasFilesContentLength(GHIConnection *connection)
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
        boundaryLen = strlen(sGhttpQrGSDD);
        stringBaseLen = boundaryLen + 47;
        fileBaseLen = boundaryLen + 76;
        xmlBaseLen = 0;
        endLen = boundaryLen + 4;
    }

    num = func_02184200(post->data);
    for (i = 0; i < num; i++)
    {
        data = func_02184208(post->data, i);
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
            state = func_02184208(connection->postingState.states, i);
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
            total += gsXmlWriterGetDataLength(data->data.xml.xml);
            GHI_DIME_PAD(total, gsXmlWriterGetDataLength(data->data.xml.xml));
            total += strlen(sGhttpCidId);
            GHI_DIME_PAD(total, (int)strlen(sGhttpCidId));
            total += strlen(sGhttpHttpSchemasXmlsoapOrgSoap);
            GHI_DIME_PAD(total, (int)strlen(sGhttpHttpSchemasXmlsoapOrgSoap));
        }
        else
        {
            return 0;
        }
    }

    return total + endLen;
}




int ghiPostGetContentLength(GHIConnection *connection)
{
    GHIPost *post = connection->post;

    if (!post)
        return 0;
    if (post->hasFiles)
        return ghiPostGetHasFilesContentLength(connection);
    return ghiPostGetNoFilesContentLength(connection);
}




int ghiPostStateInit(GHIPostState *state)
{
    int type = state->data->type;

    state->pos = -1;
    if (type == 0) {
    } else if (type == 1) {
        if (state->state.fileDisk.file == 0)
            return 0;
        if (func_02092004(state->state.fileDisk.file, 0, 2) != 0)
            return 0;
        state->state.fileDisk.len = func_02091D38((u32)state->state.fileDisk.file);
        if (state->state.fileDisk.len == -1)
            return 0;
        func_02092120(state->state.fileDisk.file);
    } else if (type != 2 && type != 3) {
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
int ghiPostInitState(GHIConnection *connection)
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
        GHIPostData *postData = func_02184208(connection->post->data, i);
        GHIPostState state = {0};

        state.data = postData;
        if (ghiPostStateInit(&state) == 0) {
            for (i--; i >= 0; i--)
                ghiPostStateCleanup(func_02184208(connection->postingState.states, i));
            func_021841B0(connection->postingState.states);
            connection->postingState.states = 0;
            return 0;
        }
        func_02184234(connection->postingState.states, &state);
    }
    connection->postingState.totalBytes = ghiPostGetContentLength(connection);
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
 * sGhttpUrlEscapeTemplate is the 4-byte "%00" template object (copied as a struct, not read
 * through a cast); sGhttpHexDigits is the hex digit table and sGhttpUrlSafeChars the set of
 * characters that need no escaping.
 */
GHIPostingResult ghiPostStringStateDoPosting(GHIPostState *state, GHIConnection *connection)
{
    int i;
    int c;
    char *string;
    UrlEscape hex;
    GHIBuffer *writeBuffer;
    int result;

    if (state->data->data.string.len == 0)
        return GHIPostingDone;
    if (connection->post->hasFiles == 0 && connection->post->hasSoap == 0 && state->data->data.string.encode != 0) {
        string = state->data->data.string.string;
        writeBuffer = &connection->sendBuffer;
        hex = sGhttpUrlEscapeTemplate;
        i = 0;
        if (connection->encryptor.engine != 0)
            writeBuffer = &connection->encodeBuffer;
        for (c = string[0]; c != 0; c = string[++i]) {
            if (func_02094A28((const u8 *)sGhttpUrlSafeChars, c) != 0) {
                result = ghiAppendCharToBuffer(writeBuffer, c);
            } else if (c == ' ') {
                result = ghiAppendCharToBuffer(writeBuffer, '+');
            } else {
                hex.c[1] = sGhttpHexDigits[c / 16];
                hex.c[2] = sGhttpHexDigits[c % 16];
                result = ghiAppendDataToBuffer(writeBuffer, hex.c, 3);
            }
        }
    } else {
        result = ghiTrySendThenBuffer(connection, state->data->data.string.string, state->data->data.string.len);
        if (result == GHITrySendError)
            return GHIPostingError;
        return GHIPostingDone;
    }
    if (connection->encryptor.engine == 0) {
        if (ghiSendBufferedData(connection) == 0)
            return 0;
        if (connection->sendBuffer.pos == connection->sendBuffer.len)
            ghiResetBuffer(&connection->sendBuffer);
        return 1;
    }
    return 1;
}






/*
 * sdk:      ghiPostXmlStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
GHIPostingResult ghiPostXmlStateDoPosting(GHIPostState *state, GHIConnection *connection)
{
    void *xml = state->data->data.xml.xml;
    char pad[3] = {0, 0, 0};
    int padlen = 0;
    int result;

    if (connection->post->useDIME != 0) {
        padlen = 4 - (gsXmlWriterGetDataLength(xml) % 4);
        if (padlen == 4)
            padlen = 0;
    }
    if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1) {
        if (ghiAppendDataToBuffer(&connection->encodeBuffer, gsXmlWriterGetData(xml), gsXmlWriterGetDataLength(xml)) == 0 ||
            ghiAppendDataToBuffer(&connection->encodeBuffer, pad, padlen) == 0 ||
            ghiEncryptDataToBuffer(&connection->sendBuffer, connection->encodeBuffer.data, connection->encodeBuffer.len) == 0)
            return 0;
        ghiResetBuffer(&connection->encodeBuffer);
        if (ghiSendBufferedData(connection) == 0)
            return 0;
        if (connection->sendBuffer.pos == connection->sendBuffer.len)
            ghiResetBuffer(&connection->sendBuffer);
        return 1;
    }
    if (ghiTrySendThenBuffer(connection, gsXmlWriterGetData(xml), gsXmlWriterGetDataLength(xml)) == 0)
        return 0;
    result = ghiTrySendThenBuffer(connection, pad, padlen);
    if (result == 0)
        return 0;
    return 1;
}






/*
 * sdk:      ghiPostFileDiskStateDoPosting (libdwcgsghttp.TWL.HYB.a(ghttppost.o))
 */
int ghiPostFileDiskStateDoPosting(GHIPostState *state, GHIConnection *connection)
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
        result = ghiTrySendThenBuffer(connection, buffer, len);
        if (result == 0)
            return 0;
        if (state->pos == state->state.fileDisk.len) {
            if (connection->post->useDIME != 0) {
                char pad[3] = {0, 0, 0};
                int padlen = 4 - (state->state.fileDisk.len % 4);

                if (padlen != 4 && padlen > 0) {
                    result = ghiTrySendThenBuffer(connection, pad, padlen);
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
int ghiPostFileMemoryStateDoPosting(GHIPostState *state, GHIConnection *connection)
{
    if (state->data->data.fileMemory.len == 0)
        return 1;

    if (connection->encryptor.engine == 0) {
        int rcode;
        do {
            rcode = ghiDoSend(connection, state->data->data.fileMemory.buffer + state->pos, state->data->data.fileMemory.len - state->pos);
            if (rcode == -1)
                return 0;
            state->pos += rcode;
            if (state->data->data.fileMemory.len == state->pos) {
                if (connection->post->useDIME) {
                    char pad[3] = { 0, 0, 0 };
                    int padlen = 4 - (state->data->data.fileMemory.len % 4);
                    if (padlen != 4 && padlen > 0) {
                        if (!ghiTrySendThenBuffer(connection, pad, padlen))
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
            result = ghiTrySendThenBuffer(connection, state->data->data.fileMemory.buffer + state->pos, len);
            if (!result)
                return 0;
            state->pos += len;
            if (state->data->data.fileMemory.len == state->pos) {
                if (connection->post->useDIME) {
                    char pad[3] = { 0, 0, 0 };
                    int padlen = 4 - (state->data->data.fileMemory.len % 4);
                    if (padlen != 4 && padlen > 0) {
                        if (!ghiTrySendThenBuffer(connection, pad, padlen))
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
                OS_SPrintf(buffer, sGhttpPostFirstFieldFormat, state->data->name);
            else
                OS_SPrintf(buffer, sGhttpPostNextFieldFormat, state->data->name);
        }
        else
        {
            if (state->data->type == 0)
            {
                OS_SPrintf(buffer, sGhttpContentDispositionFormDataName,
                           first ? sGhttpQrGSDD2 : sGhttpQrGSDD3,
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
                    header.mIdLength = htons((short)strlen(sGhttpCidId));
                    header.mTypeLength = htons((short)strlen(sGhttpHttpSchemasXmlsoapOrgSoap));
                    header.mDataLength = htonl(gsXmlWriterGetDataLength(state->data->data.xml.xml));
                    memcpy(&buffer[writePos], &header, sizeof(GSIDimeHeader));
                    writePos += sizeof(GSIDimeHeader);

                    writen = func_021803BC(&buffer[writePos], sGhttpCidId, sizeof(buffer) - writePos);
                    padBytes = (int)(4 - (writen % 4));
                    writePos += writen;
                    if (padBytes != 4)
                    {
                        while (padBytes-- > 0)
                            buffer[writePos++] = '\0';
                    }

                    writen = func_021803BC(&buffer[writePos], sGhttpHttpSchemasXmlsoapOrgSoap, sizeof(buffer) - writePos);
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
                    OS_SPrintf(buffer, sGhttpContentDispositionFormDataName2,
                               first ? sGhttpQrGSDD2 : sGhttpQrGSDD3,
                               state->data->name, filename, contentType);
                }
            }
        }

        if (connection->encryptor.engine != 0 &&
            connection->encryptor.encryptOnBuffer == GHTTPTrue)
        {
            if (len == 0)
                len = (int)strlen(buffer);
            if (!ghiEncryptDataToBuffer(&connection->sendBuffer, buffer, len))
                return GHIPostingError;
            if (!ghiSendBufferedData(connection))
                return GHIPostingError;
            if (connection->sendBuffer.pos < connection->sendBuffer.len)
                return GHIPostingWaitForContinue;
            ghiResetBuffer(&connection->sendBuffer);
        }
        else
        {
            if (len == 0)
                len = (int)strlen(buffer);
            result = ghiTrySendThenBuffer(connection, buffer, len);
            if (result == GHITrySendError)
                return GHIPostingError;
            if (result == GHITrySendBuffered)
                return GHIPostingWaitForContinue;
            ghiResetBuffer(&connection->sendBuffer);
        }
    }

    if (state->data->type == 0)
        return ghiPostStringStateDoPosting(state, connection);
    if (state->data->type == 3)
        return ghiPostXmlStateDoPosting(state, connection);
    if (state->data->type == 1)
        return ghiPostFileDiskStateDoPosting(state, connection);
    return ghiPostFileMemoryStateDoPosting(state, connection);
}





/*
 * sdk:      ghiPostDoPosting (libdwcgsghttp.TWL.HYB.a ghttppost.o)
 */
int ghiPostDoPosting(GHIConnection *connection)
{

    GHIPostState *postState;
    int len;
    int result;

    len = func_02184200(connection->postingState.states);

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
    {
        if (!ghiSendBufferedData(connection))
            return 0;
        if (connection->sendBuffer.pos < connection->sendBuffer.len)
            return 2;
        ghiResetBuffer(&connection->sendBuffer);
        if (connection->postingState.waitPostContinue)
            return 3;
        if (connection->postingState.index == len)
            return 1;
    }

    if (connection->postingState.waitPostContinue)
    {
        if (connection->post->hasFiles || connection->post->hasSoap)
        {
            result = ghiTrySendThenBuffer(connection, sGhttpPostLineEnd, func_0209477C((const u8 *)sGhttpPostLineEnd));
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
        result = ghiPostStateDoPosting(postState, connection, (connection->postingState.index == 0) ? 1 : 0, (connection->postingState.index == func_02184200(connection->postingState.states) - 1) ? 1 : 0);
        if (result == 0)
            return 0;
        if (result == 2)
            return 2;
    }

    if (connection->encryptor.engine != 0 && connection->encodeBuffer.len > 0)
    {
        if (!ghiEncryptDataToBuffer(&connection->sendBuffer, connection->encodeBuffer.data, connection->encodeBuffer.len))
            return 0;
        ghiResetBuffer(&connection->encodeBuffer);
    }

    if (connection->post->hasFiles && !connection->post->useDIME)
    {
        if (!ghiTrySendThenBuffer(connection, sGhttpQrGSDD4, func_0209477C((const u8 *)sGhttpQrGSDD4)))
            return 0;
    }

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
        return 2;
    return 1;
}
