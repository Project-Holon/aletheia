/*
 * file:     unit_021DD2D4_p01.c
 * unit:     yes
 * function: func_021DD2D4, func_021DD328
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
 */
struct GSTask;
typedef struct SAKEInternal {
    unsigned char pad0[0x48];
    int startResult;
} SAKEInternal;

typedef struct SAKERequestInternal SAKERequestInternal;

typedef void (*SAKERequestCallback)(SAKEInternal *sake, SAKERequestInternal *request, int result, void *inputData, void *outputData, void *userData);

typedef unsigned long u32;

extern int *func_021DD56C(int *ctx, int a1, int a2, int a3, int a4);
extern void func_021DD604(void *request);
extern void func_0217CECC(struct GSTask *theTask);
SAKERequestInternal *func_021DD2D4(SAKEInternal *sake, void *input, SAKERequestCallback callback, void *userData, int type, int (*startRequestFunc)(SAKERequestInternal *));
int func_021DD328(char *a, char *b);


/*
 * sdk:      sakeiRunRequest (sakemain.o)
 */
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
