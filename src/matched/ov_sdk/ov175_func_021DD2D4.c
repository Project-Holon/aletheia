/*
 * function: func_021DD2D4
 * address:  0x021DD2D4
 * packet:   pkt_ov175_021DD2D4
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeiRunRequest (sakemain.o)
 *
 * symbols:
 *   func_021DD56C  0x021DD56C  arm  ov175
 *   func_021DD604  0x021DD604  arm  ov175
 */

typedef struct SAKEInternal {
    unsigned char pad0[0x48];
    int startResult;
} SAKEInternal;

typedef struct SAKERequestInternal SAKERequestInternal;
typedef void (*SAKERequestCallback)(SAKEInternal *sake, SAKERequestInternal *request, int result, void *inputData, void *outputData, void *userData);

extern int *func_021DD56C(int *ctx, int a1, int a2, int a3, int a4);
extern void func_021DD604(void *request);

SAKERequestInternal *func_021DD2D4(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData, int type, int (*startRequestFunc)(SAKERequestInternal *))
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
