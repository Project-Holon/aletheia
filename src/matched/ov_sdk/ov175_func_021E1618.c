/*
 * function: func_021E1618
 * address:  0x021E1618
 * packet:   pkt_ov175_021E1618
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GdbGetMyRecordsAsync (dwc_gdb.o)
 *
 * symbols:
 *   func_021E1830  0x021E1830  arm  ov175
 *   func_021E214C  0x021E214C  arm  ov175
 *   func_021DD3A8  0x021DD3A8  arm  ov175
 *   func_021DD2CC  0x021DD2CC  arm  ov175
 *   func_021E17D8  0x021E17D8  arm  ov175
 *   func_021E1F18  0x021E1F18  arm  ov175
 *   func_021E212C  0x021E212C  arm  ov175
 *   func_021E1948  0x021E1948  arm  ov175
 *   g_021E5334     0x021E5334  data
 *   g_021E534C     0x021E534C  data
 *   g_021E45FC  0x021E45FC  data
 */

typedef struct {
    void *request;
    void *a;
    void *b;
    void *c;
    void *d;
    char pad[0x24];
} Work;
typedef struct {
    int unk0;
    void *sake;
    int unk8;
    int unkc;
    int unk10;
    int index;
} Tbl;
extern Tbl g_021E5334;
extern Work g_021E534C[];
extern char g_021E45FC[];
extern int func_021E1830(int *result);
extern void func_021E214C(void);
extern void *func_021DD3A8(void *sake, void *input, void (*callback)(void), void *userData);
typedef unsigned int   u32;
extern u32 func_021DD2CC(char *obj);
extern void func_021E17D8(int line, char *fmt, ...);
extern int func_021E1F18(int process, int result);
extern void func_021E212C(u32 v);
extern void func_021E1948(void *sake, void *request, int result, void *inputData, void *outputData, void *userData);

int func_021E1618(char *gdb_name, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param)
{
    int result;
    void *request;
    Work *work;

    if (func_021E1830(&result) != 0) {
        return result;
    }
    func_021E214C();
    work = &g_021E534C[g_021E5334.index];
    work->a = gdb_name;
    work->b = field_names;
    work->c = (void *)field_num;
    work->d = callback;
    request = func_021DD3A8(g_021E5334.sake, &work->a, (void (*)(void))func_021E1948, user_param);
    if (request == 0) {
        int sake_result = func_021DD2CC(g_021E5334.sake);
        func_021E17D8(0x35b, g_021E45FC, sake_result);
        return func_021E1F18(7, sake_result);
    }
    g_021E534C[g_021E5334.index].request = request;
    func_021E212C(7);
    return 0;
}
