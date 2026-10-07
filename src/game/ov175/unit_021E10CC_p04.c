/*
 * file:     unit_021E10CC_p04.c
 * unit:     yes
 * function: func_021E1618, func_021E16F0
 * address:  0x021E1618
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
 *   func_021DD3D0  0x021DD3D0  arm  ov175
 *   g_021E461C  0x021E461C  data
 */
#include "../../matched/include/G_021E534C.h"

typedef struct {
    void *request;
    void *a;
    void *b;
    void *c;
    void *d;
    char pad[0x24];
} Work_021E1618;

typedef struct {
    int unk0;
    void *sake;
    int unk8;
    int unkc;
    int unk10;
    int index;
} Tbl;

typedef unsigned int   u32;

typedef struct {
    void *request;
    void *a;
    void *b;
    void *c;
    void *d;
    void *e;
    void *f;
    char pad[0x1c];
} Work_021E16F0;

extern int func_021E1830(int *result);
extern void func_021E214C(void);
extern void *func_021DD3A8(void *sake, void *input, void (*callback)(void), void *userData);
extern u32 func_021DD2CC(char *obj);
extern void func_021E17D8(int line, char *fmt, ...);
extern int func_021E1F18(int process, int result);
extern void func_021E212C(u32 v);
extern void func_021E1948(void *sake, void *request, int result, void *inputData, void *outputData, void *userData);
extern void *func_021DD3D0(void *sake, void *input, void (*callback)(void), void *userData);
int func_021E1618(char *gdb_name, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param);
int func_021E16F0(char *gdb_name, int *record_ids, int record_num, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param);
extern Tbl g_021E5334;
extern struct G_021E534C g_021E534C[];
extern char g_021E45FC[];
extern char g_021E461C[];


/*
 * sdk:      DWC_GdbGetMyRecordsAsync (dwc_gdb.o)
 */
int func_021E1618(char *gdb_name, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param)
{
    int result;
    void *request;
    Work_021E1618 *work;

    if (func_021E1830(&result) != 0) {
        return result;
    }
    func_021E214C();
    work = &((Work_021E1618 *)g_021E534C)[g_021E5334.index];
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


/*
 * sdk:      DWC_GdbGetRecordsAsync (dwc_gdb.o)
 */
int func_021E16F0(char *gdb_name, int *record_ids, int record_num, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param)
{
    int result;
    void *request;
    Work_021E16F0 *work;

    if (func_021E1830(&result) != 0) {
        return result;
    }
    func_021E214C();
    work = &((Work_021E16F0 *)g_021E534C)[g_021E5334.index];
    work->a = gdb_name;
    work->b = record_ids;
    work->c = (void *)record_num;
    work->d = field_names;
    work->e = (void *)field_num;
    work->f = callback;
    request = func_021DD3D0(g_021E5334.sake, &work->a, (void (*)(void))func_021E1948, user_param);
    if (request == 0) {
        int sake_result = func_021DD2CC(g_021E5334.sake);
        func_021E17D8(0x3ca, g_021E461C, sake_result);
        return func_021E1F18(9, sake_result);
    }
    g_021E534C[g_021E5334.index].request = request;
    func_021E212C(9);
    return 0;
}
