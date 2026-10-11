/*
 * file:     unit_021DD2D4.c
 * unit:     yes
 * function: func_021DD2D4, func_021DD328, func_021DD358, func_021DD380, func_021DD3A8, func_021DD3D0, func_021DD3F8, func_021DD420, func_021DD4B0, func_021DD4D8, func_021DD560
 * address:  0x021DD2D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DD56C  0x021DD56C  arm  ov175
 *   func_021DD604  0x021DD604  arm  ov175
 *   func_0217CECC  0x0217CECC  arm  ov009
 *   g_021E4B88  0x021E4B88  data
 *   func_02084F80  0x02084F80  arm
 *   g_021E363C  0x021E363C  data
 *   g_021E365C  0x021E365C  data
 *   g_021E4C08  0x021E4C08  data
 *   g_021E36B0  0x021E36B0  data
 *   g_021E36C4  0x021E36C4  data
 *   func_021DD328  0x021DD328  arm  ov175
 */
struct GSTask;
typedef struct SAKEInternal_021DD2D4 {
    unsigned char pad0[0x48];
    int startResult;
} SAKEInternal_021DD2D4;

typedef struct SAKERequestInternal SAKERequestInternal;

typedef void (*SAKERequestCallback)(SAKEInternal_021DD2D4 *sake, SAKERequestInternal *request, int result, void *inputData, void *outputData, void *userData);

typedef unsigned long u32;

typedef struct SAKEInternal_021DD420 {
    int startedUp;
    char gameName[0x10];
    int gameId;
    unsigned char pad18[0xC];
    int profileSet;
    int profileId;
} SAKEInternal_021DD420;

typedef struct SAKEInternal {
    int startedUp;
    char gameName[0x10];
    int gameId;
    unsigned char pad18[0xC];
    int profileSet;
    int profileId;
} SAKEInternal;

extern int *func_021DD56C(int *ctx, int a1, int a2, int a3, int a4);
extern void func_021DD604(void *request);
extern void func_0217CECC(struct GSTask *theTask);
extern int func_021DE024(void *p);
extern int func_021DE0D4(void *p);
extern int func_021DEBE0(void *p);
extern int func_021DECE8(void *p);
extern char *func_02094798(char *dst, const char *src);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
SAKERequestInternal *func_021DD2D4(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData, int type, int (*startRequestFunc)(void *));
int func_021DD328(char *a, char *b);
SAKERequestInternal *func_021DD358(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData);
SAKERequestInternal *func_021DD380(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData);
SAKERequestInternal *func_021DD3A8(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData);
SAKERequestInternal *func_021DD3D0(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData);
int func_021DD3F8(char *a, char *b);
int func_021DD420(SAKEInternal_021DD420 *sake, int fileId, char *url);
int func_021DD4B0(char *a, char *b);
int func_021DD4D8(SAKEInternal *sake, char *url);
int func_021DD560(char *a, char *b);
extern char g_021E4B88[128];
extern char g_021E363C[];
extern char g_021E365C[];
extern char g_021E4C08[128];
extern char g_021E36B0[];
extern char g_021E36C4[];





/*
 * sdk:      sakeiRunRequest (sakemain.o)
 */
SAKERequestInternal *func_021DD2D4(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData, int type, int (*startRequestFunc)(void *))
{
    SAKERequestInternal *request;

    request = (SAKERequestInternal *)func_021DD56C((int *)sake, type, (int)input, (int)callback, (int)userData);
    if (!request)
        return 0;
    sake->startResult = startRequestFunc(request);
    if (sake->startResult != 0) {
        func_021DD604(request);
        return 0;
    }
    return request;
}





/*
 * Returns 3 unless both arguments, the word at +0x20 of the second and
 *  *  that word's +0x24 field are all non-null; otherwise hands the field to
 *  *  0x0217CECC (ov009) and returns 0.  One predicated cmpne chain, so the
 *  *  whole test is a single short-circuit expression.
 */
int func_021DD328(char *a, char *b)
{
    u32 v;
    if (a && b && *(char **)(b + 0x20)
        && (v = *(u32 *)(*(u32 *)(b + 0x20) + 0x24)) != 0) {
        func_0217CECC((struct GSTask *)v);
        return 0;
    }
    return 3;
}






/*
 * Register the 0x021DE024 callback with func_021DD2D4: forwards the four
 * incoming register arguments and appends (0, callback).
 */
SAKERequestInternal *func_021DD358(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData)
{
    return func_021DD2D4(sake, input, callback, userData, 0, func_021DE024);
}






SAKERequestInternal *func_021DD380(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData)
{
    return func_021DD2D4(sake, input, callback, userData, 1, func_021DE0D4);
}






/*
 * Register the 0x021DEBE0 callback with func_021DD2D4: forwards the four
 * incoming register arguments and appends (4, callback).
 */
SAKERequestInternal *func_021DD3A8(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData)
{
    return func_021DD2D4(sake, input, callback, userData, 4, func_021DEBE0);
}






/*
 * Register the 0x021DECE8 callback with func_021DD2D4: forwards the four
 * incoming register arguments and appends (5, callback).
 */
SAKERequestInternal *func_021DD3D0(SAKEInternal_021DD2D4 *sake, void *input, SAKERequestCallback callback, void *userData)
{
    return func_021DD2D4(sake, input, callback, userData, 5, func_021DECE8);
}






int func_021DD3F8(char *a, char *b)
{
    if (a == 0 || b == 0)
        return 0;
    func_02094798(g_021E4B88, b);
    return 1;
}




/*
 * sdk:      sakeGetFileDownloadURL (sakemain.o)
 */
int func_021DD420(SAKEInternal_021DD420 *sake, int fileId, char *url)
{
    int rcode;

    if (!sake || !url || !sake->startedUp || !sake->profileSet)
        return 0;
    if (g_021E4B88[0])
        rcode = func_02084F80(url, 128, g_021E363C, g_021E4B88, fileId, sake->gameId, sake->profileId);
    else
        rcode = func_02084F80(url, 128, g_021E365C, sake->gameName, fileId, sake->gameId, sake->profileId);
    if (rcode < 0)
        return 0;
    return 1;
}




int func_021DD4B0(char *a, char *b)
{
    if (a == 0 || b == 0)
        return 0;
    func_02094798(g_021E4C08, b);
    return 1;
}


/*
 * sdk:      sakeGetFileUploadURL (sakemain.o)
 */
int func_021DD4D8(SAKEInternal *sake, char *url)
{
    int rcode;

    if (!sake || !url || !sake->startedUp || !sake->profileSet)
        return 0;
    if (g_021E4C08[0])
        rcode = func_02084F80(url, 128, g_021E36B0, g_021E4C08, sake->gameId, sake->profileId);
    else
        rcode = func_02084F80(url, 128, g_021E36C4, sake->gameName, sake->gameId, sake->profileId);
    if (rcode < 0)
        return 0;
    return 1;
}

int func_021DD560(char *a, char *b)
{
    return func_021DD328(a, b);
}
