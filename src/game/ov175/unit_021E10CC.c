/*
 * file:     unit_021E10CC.c
 * unit:     yes
 * function: func_021E10CC, func_021E11F0, func_021E1340, func_021E13BC, func_021E1414, func_021E1434, func_021E1454, func_021E1464, func_021E1540, func_021E1618, func_021E16F0, func_021E17D8, func_021E1830, func_021E191C, func_021E1948, func_021E1D70, func_021E1DD0, func_021E1EAC, func_021E1EC4, func_021E1F18, func_021E1F6C, func_021E20B8, func_021E20D4, func_021E212C, func_021E214C, func_021E216C
 * address:  0x021E10CC
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
 *   func_0216AAE0  0x0216AAE0  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   func_0217CA40  0x0217CA40  arm  ov009
 *   func_021DD1EC  0x021DD1EC  arm  ov175
 *   func_021DD25C  0x021DD25C  arm  ov175
 *   func_021DD290  0x021DD290  arm  ov175
 *   func_021BF558  0x021BF558  arm  ov114
 *   g_021E5334  0x021E5334  data
 *   g_021E450C  0x021E450C  data
 *   g_021E452C  0x021E452C  data
 *   g_021AE01C  0x021AE01C  data
 *   g_021AE11C  0x021AE11C  data
 *   func_021DD560  0x021DD560  arm  ov175
 *   func_021C22D4  0x021C22D4  arm  ov114
 *   func_021C22A4  0x021C22A4  arm  ov114
 *   g_021E4548  0x021E4548  data
 *   g_021E4560  0x021E4560  data
 *   g_021E457C  0x021E457C  data
 *   func_021BF57C  0x021BF57C  arm  ov114
 *   func_021DD250  0x021DD250  arm  ov175
 *   g_021E4594     0x021E4594  data
 *   g_021E45A8     0x021E45A8  data
 *   func_021BF540  0x021BF540  arm  ov114
 *   func_021DD4D8  0x021DD4D8  arm  ov175
 *   func_021DD420  0x021DD420  arm  ov175
 *   g_021E4C88     0x021E4C88  data
 *   func_0217CE1C  0x0217CE1C  arm  ov009
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *   func_021BF5B8  0x021BF5B8  arm  ov114
 *   func_021DD358  0x021DD358  arm  ov175
 *   func_021DD2CC  0x021DD2CC  arm  ov175
 *   g_021E534C     0x021E534C  data
 *   g_021E45BC  0x021E45BC  data
 *   func_021DD380  0x021DD380  arm  ov175
 *   g_021E45DC  0x021E45DC  data
 *   func_021DD3A8  0x021DD3A8  arm  ov175
 *   g_021E45FC  0x021E45FC  data
 *   func_021DD3D0  0x021DD3D0  arm  ov175
 *   g_021E461C  0x021E461C  data
 *   func_02084F80  0x02084F80  arm
 *   OS_VSNPrintf  0x02084FA8  arm
 *   g_021E4640     0x021E4640  data
 *   DWCi_IsError      0x02059F38  arm
 *   DWC_GetLastError  0x02059E18  arm
 *   g_021E464C        0x021E464C  data
 *   g_021E4660        0x021E4660  data
 *   func_0217CD94  0x0217CD94  arm  ov009
 *   g_021E44D4     0x021E44D4  data
 *   g_021E4674     0x021E4674  data
 *   g_021E46A0     0x021E46A0  data
 *   g_021E46BC     0x021E46BC  data
 *   g_021E46E8     0x021E46E8  data
 *   g_021E4700     0x021E4700  data
 *   g_021E472C     0x021E472C  data
 *   g_021E4754     0x021E4754  data
 *   g_021E4768     0x021E4768  data
 *   g_021E477C     0x021E477C  data
 *   g_021E478C     0x021E478C  data
 *   g_021E47A0     0x021E47A0  data
 *   g_021E47B0   0x021E47B0  data
 *   DWCi_SetError  0x02059F54  arm
 *   g_021E47C4     0x021E47C4  data
 *   func_021BF520  0x021BF520  arm  ov114
 *   func_021DD4B0  0x021DD4B0  arm  ov175
 *   func_021DD3F8  0x021DD3F8  arm  ov175
 *   g_021E47DC  0x021E47DC  data
 *   g_021E4830  0x021E4830  data
 *   g_021E4878  0x021E4878  data
 *   g_021E48C4  0x021E48C4  data
 *   g_021E4914  0x021E4914  data
 *   g_021E495C  0x021E495C  data
 */
struct SAKEInternal;
typedef unsigned char u8;

typedef unsigned long u32;

typedef struct {
    int size;
    u32 pseudo[3];
    u32 authentic[3];
    int gs_profile_id;
    int flag;
    u32 gamecode;
    int reserved[5];
    u32 crc32;
} DWCstAccUserData;

typedef enum { DWC_GDB_PROCESS_NONE } DWCGdbProcess;

typedef void (*DWCGdbGetRecordsCallback)(int num, void **records, void *user_param);

typedef struct {
    void *request;
    char *mTableId;
    void *mFields;
    int mNumFields;
    int *recordId;
} CreateRecordWork;

typedef struct {
    void *request;
    char *mTableId;
    int mRecordId;
} DeleteRecordWork;

typedef struct {
    void *request;
    char *mTableId;
    int mRecordId;
    void *mFields;
    int mNumFields;
} UpdateRecordWork;

typedef struct {
    void *request;
    char *mTableId;
    char **mFieldNames;
    int mNumFields;
    DWCGdbGetRecordsCallback callback;
} GetMyRecordsWork;

typedef struct {
    void *request;
    char *mTableId;
    int *limit_num;
    int *owned_num;
} GetRecordLimitWork;

typedef struct {
    void *request;
    char *mTableId;
    int *mRecordIds;
    int mNumRecordIds;
    char **mFieldNames;
    int mNumFields;
    DWCGdbGetRecordsCallback callback;
} GetRecordsWork;

typedef struct {
    void *request;
    char *mTableId;
    int mRecordId;
    unsigned char mRating;
} RateRecordWork;

typedef struct {
    void *request;
    char pad4[0x34 - 0x4];
    DWCGdbGetRecordsCallback callback;
} SearchRecordsWork;

typedef struct {
    void *request;
    char *mTableId;
    char **mFieldNames;
    int mNumFields;
    char *mFilter;
    DWCGdbGetRecordsCallback callback;
} GetRandomRecordWork;

typedef struct {
    void *request;
    char *mTableId;
    char *mFilter;
    int mCacheFlag;
    int *count;
} GetRecordCountWork;

typedef union {
    struct {
        void *request;
    } sake;
    struct {
        int request;
    } ghttp;
    struct {
        int reserved;
        int request;
    } ghttp2;
    CreateRecordWork create;
    DeleteRecordWork del;
    UpdateRecordWork update;
    GetMyRecordsWork getMyRecords;
    GetRecordLimitWork getRecordLimit;
    GetRecordsWork getRecords;
    RateRecordWork rate;
    SearchRecordsWork search;
    GetRandomRecordWork getRandomRecord;
    GetRecordCountWork getRecordCount;
    unsigned char raw[56];
} DWCiGdbWork;

typedef struct {
    void *request;
    void *sake;
    int   state;
    DWCGdbProcess process;
    int   result;
    int   current_work;
    DWCiGdbWork work[2];
} DWCiGdbEntity;

typedef unsigned int u32_021E1454;

typedef unsigned int   u32_021E1464;

typedef struct {
    int mNumRecords;
    void **mRecords;
} RecordsOutput;

typedef int s32_021E1D70;

typedef signed int s32_021E1DD0;

typedef unsigned int u32_021E191C;

typedef signed int s32;

extern int func_0216AAE0(char *loginTicket);
extern void func_02059F54(int error, int errorCode);
extern void func_0217CA40(void);
extern int func_021DD1EC(struct SAKEInternal **sakePtr);
extern void func_021DD25C(char *p, int b, int c, int d);
extern void func_021DD290(struct SAKEInternal *sake, int profileId, const char *loginTicket);
extern int func_021BF558();
extern void func_021DD560();
extern int func_021C22D4(int request);
extern void func_021C22A4(int request);
extern int func_021BF57C(void);
extern void func_021DD250(void *sake);
extern int func_021BF540(char *url);
extern int func_021DD4D8(struct SAKEInternal *sake, char *url);
extern int func_021DD420(struct SAKEInternal *sake, int fileId, char *url);
extern int  func_0217CE1C(void);
extern void func_0217CCCC(unsigned int theMS);
extern int func_021BF5B8(void);
extern int func_02059F38(void);
extern void *func_021DD358(void *sake, void *input, void (*callback)(void), void *userData);
extern u32_021E1464 func_021DD2CC(char *obj);
extern void *func_021DD380(void *sake, void *input, void (*callback)(void), void *userData);
extern void *func_021DD3A8(void *sake, void *input, void (*callback)(void), void *userData);
extern void *func_021DD3D0(void *sake, void *input, void (*callback)(void), void *userData);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern int OS_VSNPrintf(char *s, unsigned int n, const char *format, void *arg);
extern int DWCi_IsError(void);
extern int DWC_GetLastError(int *errorCode);
extern void func_0217CD94(void);
extern void DWCi_SetError(int error, int errorCode);
extern int func_021BF520(int a);
extern int func_021DD4B0(char *a, char *b);
extern int func_021DD3F8(char *a, char *b);
int func_021E10CC(int game_id, DWCstAccUserData *userdata, int ssl_type);
int func_021E11F0(void);
int func_021E1340(void);
void func_021E13BC(void);
void func_021E1414(void);
int func_021E1434(void);
u32_021E1454 func_021E1454(void);
int func_021E1464(char *gdb_name, void *fields, int field_num, int *record_id);
int func_021E1540(char *gdb_name, int record_id, void *fields, int field_num);
int func_021E1618(char *gdb_name, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param);
int func_021E16F0(char *gdb_name, int *record_ids, int record_num, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param);
void func_021E17D8(int line, char *fmt, ...);
int func_021E1830(int *result);
void func_021E191C(void);
void func_021E1948(void *sake, void *request, int result, void *inputData, void *outputData, void *userData);
s32_021E1D70 func_021E1D70(s32_021E1D70 a, s32_021E1D70 *p);
s32_021E1DD0 func_021E1DD0(s32_021E1DD0 a, s32_021E1DD0 *st);
int func_021E1EAC(int a, int b);
int func_021E1EC4(int mode);
int func_021E1F18(int a, int mode);
s32 func_021E1F6C(s32 a, s32 *st);
int func_021E20B8(int a, int b);
int func_021E20D4(int process, int result);
void func_021E212C(u32 v);
void func_021E214C(void);
void func_021E216C(int ssl_type);
extern DWCiGdbEntity g_021E5334;
extern char g_021E450C[];
extern char g_021E452C[];
extern char g_021AE01C[];
extern char g_021AE11C[];
extern char g_021E4548[];
extern char g_021E4560[];
extern char g_021E457C[];
extern char g_021E4594[];
extern char g_021E45A8[];
extern char g_021E4C88[];
extern char g_021E45BC[];
extern char g_021E45DC[];
extern char g_021E45FC[];
extern char g_021E461C[];
extern char g_021E4640[];
extern char g_021E464C[];
extern char g_021E4660[];
extern char *g_021E44D4[];
extern char g_021E4674[];
extern char g_021E46A0[];
extern char g_021E46BC[];
extern char g_021E46E8[];
extern char g_021E4700[];
extern char g_021E472C[];
extern char g_021E4754[];
extern char g_021E4768[];
extern char g_021E477C[];
extern char g_021E478C[];
extern char g_021E47A0[];
extern u32_021E191C  g_021E47B0[];
extern char g_021E47C4[];
extern char g_021E47DC[];
extern char g_021E4830[];
extern char g_021E4878[];
extern char g_021E48C4[];
extern char g_021E4914[];
extern char g_021E495C[];





/*
 * sdk:      DWC_GdbInitialize (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 */
int func_021E10CC(int game_id, DWCstAccUserData *userdata, int ssl_type)
{
    char loginTicket[25];
    int result;

    if (g_021E5334.state != 0)
        return 18;
    if (!func_0216AAE0(loginTicket)) {
        func_021E17D8(0x11A, g_021E450C);
        func_02059F54(8, func_021E1EAC(1, 4));
        return 4;
    }
    func_0217CA40();
    result = func_021DD1EC((struct SAKEInternal **)(&g_021E5334.sake));
    if (result != 0) {
        func_021E17D8(0x127, g_021E452C, result);
        func_021E191C();
        return func_021E1EC4(result);
    }
    func_021DD25C(g_021E5334.sake, (int)g_021AE01C, game_id, (int)g_021AE11C);
    func_021DD290(g_021E5334.sake, userdata->gs_profile_id, loginTicket);
    func_021E216C(ssl_type);
    func_021BF558(0);
    g_021E5334.state = 1;
    g_021E5334.result = 0;
    g_021E5334.process = 0;
    g_021E5334.current_work = 0;
    return 0;
}







/*
 * 2026-10-01: closed. The image dispatches the switch in r2: the default arm's
 * printf takes s_tbl.process as its third argument (the value already in r2),
 * which also fixed the {r5,r6,r7} colouring of s_tbl / 0x38 / 3.
 *
 * sdk:      DWC_GdbCancelRequest (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 */
int func_021E11F0(void)
{
    if (g_021E5334.state != 2) {
        func_021E17D8(0x14F, g_021E4548);
        return 17;
    }
    g_021E5334.state = 3;
    switch (g_021E5334.process) {
    case 2:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 3:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 4:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 7:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 8:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 9:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 10:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 11:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 12:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 13:
        func_021DD560(g_021E5334.sake, g_021E5334.work[g_021E5334.current_work].sake.request);
        break;
    case 5:
        func_021E17D8(0x181, g_021E4560, func_021C22D4(g_021E5334.work[g_021E5334.current_work].ghttp.request));
        func_021C22A4(g_021E5334.work[g_021E5334.current_work].ghttp.request);
        break;
    case 6:
        func_021E17D8(0x188, g_021E4560, func_021C22D4(((DWCiGdbWork *)g_021E5334.work)[g_021E5334.current_work].ghttp2.request));
        func_021C22A4(((DWCiGdbWork *)g_021E5334.work)[g_021E5334.current_work].ghttp2.request);
        break;
    default:
        func_021E17D8(0x18F, g_021E457C, g_021E5334.process);
        break;
    }
    return 0;
}







/*
 * sdk:      DWC_GdbShutdown (dwc_gdb.o)
 */
int func_021E1340(void)
{
    if (g_021E5334.state == 0) {
        func_021E17D8(0x1a6, g_021E4594);
        return 0x13;
    }
    if (g_021E5334.state == 2) {
        func_021E17D8(0x1ab, g_021E45A8);
        return 0x14;
    }
    func_021E13BC();
    g_021E5334.state = 0;
    func_021BF57C();
    func_021DD250(g_021E5334.sake);
    func_021E191C();
    return 0;
}






void func_021E13BC(void)
{
    char upload_url[128];
    char download_url[128];

    func_021BF540(g_021E4C88);
    func_021DD4D8(g_021E5334.sake, upload_url);
    func_021BF540(upload_url);
    func_021DD420(g_021E5334.sake, 1, download_url);
    func_021BF540(download_url);
}






/*
 * Runs the ov009 status query 0x0217CE1C; unless it reports 2 it releases
 *  *  the ov009 object through 0x0217CCCC(0), then always finishes with the
 *  *  0x021BF5B8 (ov114) step.
 */
void func_021E1414(void)
{
    if (func_0217CE1C() != 2)
        func_0217CCCC(0);
    func_021BF5B8();
}






int func_021E1434(void)
{
    if (func_02059F38())
        return 4;
    return g_021E5334.state;
}





/*
 * SDK provenance: DWC_GdbGetAsyncResult (TwlDWC/libdwcgdb.TWL.HYB.a,
 * dwc_gdb.o), ov175.  Read the +0x10 async-result word.
 */
u32_021E1454 func_021E1454(void)
{
    return g_021E5334.result;
}






/*
 * sdk:      DWC_GdbCreateRecordAsync (dwc_gdb.o)
 */
int func_021E1464(char *gdb_name, void *fields, int field_num, int *record_id)
{
    int result;
    void *request;
    CreateRecordWork *work;

    if (func_021E1830(&result) != 0) {
        return result;
    }
    func_021E214C();
    work = &g_021E5334.work[g_021E5334.current_work].create;
    work->mTableId = gdb_name;
    work->mFields = fields;
    work->mNumFields = field_num;
    work->recordId = record_id;
    request = func_021DD358(g_021E5334.sake, &work->mTableId, (void (*)(void))func_021E1948, 0);
    if (request == 0) {
        int sake_result = func_021DD2CC(g_021E5334.sake);
        func_021E17D8(0x22f, g_021E45BC, sake_result);
        return func_021E1F18(2, sake_result);
    }
    g_021E5334.work[g_021E5334.current_work].sake.request = request;
    func_021E212C(2);
    return 0;
}






int func_021E1540(char *gdb_name, int record_id, void *fields, int field_num)
{
    int result;
    void *request;
    UpdateRecordWork *work;

    if (func_021E1830(&result) != 0) {
        return result;
    }
    func_021E214C();
    work = &g_021E5334.work[g_021E5334.current_work].update;
    work->mTableId = gdb_name;
    work->mRecordId = record_id;
    work->mFields = fields;
    work->mNumFields = field_num;
    request = func_021DD380(g_021E5334.sake, &work->mTableId, (void (*)(void))func_021E1948, 0);
    if (request == 0) {
        int sake_result = func_021DD2CC(g_021E5334.sake);
        func_021E17D8(0x29c, g_021E45DC, sake_result);
        return func_021E1F18(4, sake_result);
    }
    g_021E5334.work[g_021E5334.current_work].sake.request = request;
    func_021E212C(4);
    return 0;
}






/*
 * sdk:      DWC_GdbGetMyRecordsAsync (dwc_gdb.o)
 */
int func_021E1618(char *gdb_name, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param)
{
    int result;
    void *request;
    GetMyRecordsWork *work;

    if (func_021E1830(&result) != 0) {
        return result;
    }
    func_021E214C();
    work = &g_021E5334.work[g_021E5334.current_work].getMyRecords;
    work->mTableId = gdb_name;
    work->mFieldNames = field_names;
    work->mNumFields = field_num;
    work->callback = callback;
    request = func_021DD3A8(g_021E5334.sake, &work->mTableId, (void (*)(void))func_021E1948, user_param);
    if (request == 0) {
        int sake_result = func_021DD2CC(g_021E5334.sake);
        func_021E17D8(0x35b, g_021E45FC, sake_result);
        return func_021E1F18(7, sake_result);
    }
    g_021E5334.work[g_021E5334.current_work].sake.request = request;
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
    GetRecordsWork *work;

    if (func_021E1830(&result) != 0) {
        return result;
    }
    func_021E214C();
    work = &g_021E5334.work[g_021E5334.current_work].getRecords;
    work->mTableId = gdb_name;
    work->mRecordIds = record_ids;
    work->mNumRecordIds = record_num;
    work->mFieldNames = field_names;
    work->mNumFields = field_num;
    work->callback = callback;
    request = func_021DD3D0(g_021E5334.sake, &work->mTableId, (void (*)(void))func_021E1948, user_param);
    if (request == 0) {
        int sake_result = func_021DD2CC(g_021E5334.sake);
        func_021E17D8(0x3ca, g_021E461C, sake_result);
        return func_021E1F18(9, sake_result);
    }
    g_021E5334.work[g_021E5334.current_work].sake.request = request;
    func_021E212C(9);
    return 0;
}





/*
 * sdk:      DWCi_GdbPrintf (dwc_gdb.o)
 */
void func_021E17D8(int line, char *fmt, ...)
{
    char str_buf[256];
    int str_len;
    char *args;

    str_len = func_02084F80(str_buf, 256, g_021E4640, line);
    args = (char *)((((unsigned int)&fmt) & ~3) + 4);
    OS_VSNPrintf(str_buf + str_len, 256 - str_len, fmt, args);
}





int func_021E1830(int *result)
{
    if (DWCi_IsError()) {
        func_021E17D8(0x568, g_021E464C, DWC_GetLastError(0));
        if (result != 0) {
            *result = 0x16;
        }
        return 1;
    }
    switch (g_021E5334.state) {
    case 0:
        func_021E17D8(0x570, g_021E4594);
        if (result != 0) {
            *result = 0x13;
        }
        return 1;
    case 2:
        func_021E17D8(0x575, g_021E45A8);
        if (result != 0) {
            *result = 0x14;
        }
        return 1;
    case 3:
        func_021E17D8(0x57a, g_021E4660);
        if (result != 0) {
            *result = 0x17;
        }
        return 1;
    }
    return 0;
}







/*
 * Starts the ov009 transaction, releases the null handle, then checks
 *  *  the status: unless 0x0217CE1C reports 2 the null handle is released a
 *  *  second time.
 */
void func_021E191C(void)
{
    func_0217CD94();
    func_0217CCCC(0);
    if (func_0217CE1C() != 2)
        func_0217CCCC(0);
}







void func_021E1948(void *sake, void *request, int result, void *inputData, void *outputData, void *userData)
{
    DWCGdbProcess process = g_021E5334.process;

    if (g_021E5334.state != 2 && g_021E5334.state != 3)
        return;

    if (result == 0) {
        g_021E5334.result = 1;
        g_021E5334.state = 1;
        g_021E5334.process = 0;

        switch (process) {
        case 2: {
            CreateRecordWork *work = &g_021E5334.work[g_021E5334.current_work].create;
            *work->recordId = *(int *)outputData;
            func_021E17D8(0x5af, g_021E4674, g_021E44D4[process], work->mTableId, work->mNumFields, *work->recordId);
            break;
        }
        case 3: {
            DeleteRecordWork *work = &g_021E5334.work[g_021E5334.current_work].del;
            func_021E17D8(0x5b8, g_021E46A0, g_021E44D4[process], work->mTableId, work->mRecordId);
            break;
        }
        case 4: {
            UpdateRecordWork *work = &g_021E5334.work[g_021E5334.current_work].update;
            func_021E17D8(0x5c2, g_021E46BC, g_021E44D4[process], work->mTableId, work->mRecordId, work->mNumFields);
            break;
        }
        case 7: {
            GetMyRecordsWork *work = &g_021E5334.work[g_021E5334.current_work].getMyRecords;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5cb, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 8: {
            GetRecordLimitWork *work = &g_021E5334.work[g_021E5334.current_work].getRecordLimit;
            *work->limit_num = ((int *)outputData)[0];
            *work->owned_num = ((int *)outputData)[1];
            func_021E17D8(0x5d8, g_021E4700, g_021E44D4[process], work->mTableId, *work->limit_num, *work->owned_num);
            break;
        }
        case 9: {
            GetRecordsWork *work = &g_021E5334.work[g_021E5334.current_work].getRecords;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5e1, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 10: {
            RateRecordWork *work = &g_021E5334.work[g_021E5334.current_work].rate;
            func_021E17D8(0x5ec, g_021E472C, g_021E44D4[process], work->mTableId, work->mRecordId, work->mRating);
            break;
        }
        case 11: {
            SearchRecordsWork *work = &g_021E5334.work[g_021E5334.current_work].search;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5f5, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 12: {
            GetRandomRecordWork *work = &g_021E5334.work[g_021E5334.current_work].getRandomRecord;
            void **output = outputData;
            if (*output != 0) {
                func_021E17D8(0x5ff, g_021E4754, g_021E44D4[process]);
                work->callback(1, output, userData);
            } else {
                func_021E17D8(0x604, g_021E4768, g_021E44D4[process]);
                work->callback(0, 0, userData);
            }
            break;
        }
        case 13: {
            GetRecordCountWork *work = &g_021E5334.work[g_021E5334.current_work].getRecordCount;
            *work->count = *(int *)outputData;
            func_021E17D8(0x60d, g_021E477C, g_021E44D4[process], *work->count);
            break;
        }
        default:
            func_021E17D8(0x613, g_021E457C, process);
            break;
        }
    } else if (result == 0x17) {
        func_021E17D8(0x61a, g_021E478C, g_021E44D4[g_021E5334.process], result);
        g_021E5334.result = 0x20;
        g_021E5334.state = 1;
        g_021E5334.process = 0;
    } else {
        func_021E17D8(0x621, g_021E47A0, g_021E44D4[g_021E5334.process], result);
        g_021E5334.result = func_021E20D4(g_021E5334.process, result);
        g_021E5334.state = 1;
        g_021E5334.process = 0;
    }
}







/*
 * ARM jump-table selector: four values map to a threshold stored through the
 * out pointer and to a distinct status code, anything else is 0x11.
 */
s32_021E1D70 func_021E1D70(s32_021E1D70 a, s32_021E1D70 *p)
{
    switch (a) {
    case 0:
        *p = 0;
        return 0;
    case 1:
        *p = 8;
        return 2;
    case 2:
        *p = 8;
        return 3;
    case 3:
        *p = 9;
        return 1;
    }
    return 0x11;
}







/*
 * Session-state translation: the state word is parked at 0x13 up front, then
 * the caller's mode picks the reported code, with mode 0 also clearing the
 * word and mode 2 parking 9 and reporting 1.
 */
s32_021E1DD0 func_021E1DD0(s32_021E1DD0 a, s32_021E1DD0 *st)
{
    *st = 0x13;
    switch (a) {
    case 0:
        *st = 0;
        return 0;
    case 1:
        return 5;
    case 2:
        *st = 9;
        return 1;
    case 3:
        return 6;
    case 4:
        return 7;
    case 5:
        return 8;
    case 6:
        return 9;
    case 7:
        return 0xa;
    case 8:
        return 0xb;
    case 9:
        return 0xc;
    case 10:
        return 0xd;
    case 11:
        return 0xe;
    case 12:
        return 0xf;
    case 13:
        return 0x10;
    case 14:
        return 0x11;
    default:
        return 0x11;
    }
}






/*
 * Leaf: -40000 - (a * 100 + b), the plain two-term member of the
 *  *  func_021E20B8 family (that one adds the 50-byte header).
 */
int func_021E1EAC(int a, int b)
{
    return -40000 - (a * 100 + b);
}







/*
 * Acquire-by-mode wrapper: the mode the caller passed picks a handle; on
 * success the handle is announced (message 0x6db), a sub-id is allocated and
 * the pair is released.
 */
int func_021E1EC4(int mode)
{
    int local;
    int h = func_021E1D70(mode, &local);

    if (h != 0) {
        func_021E17D8(0x6db, (char *)((int)g_021E47B0), h);
        func_02059F54(local, func_021E1EAC(1, h));
    }
    return h;
}







int func_021E1F18(int a, int mode)
{
    int local;
    int h = func_021E1DD0(mode, &local);

    if (h != 0) {
        func_021E17D8(0x6ec, (char *)((int)g_021E47B0), h);
        func_02059F54(local, func_021E1EAC(a, h));
    }
    return h;
}







/*
 * Mode table, 24 entries: the state word starts at 0x13, modes 0 and 6 park a
 * replacement first, and the reported code walks up from 1 with 0x1e/0x20/0x16
 * at the top of the table; the default reports the same 0x16 as mode 0x17 but
 * from its own out-of-line block.
 */
s32 func_021E1F6C(s32 a, s32 *st)
{
    *st = 0x13;
    switch (a) {
    case 0:
        *st = 0;
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        return 6;
    case 6:
        *st = 9;
        return 7;
    case 7:
        return 8;
    case 8:
        return 9;
    case 9:
        return 0xa;
    case 10:
        return 0xb;
    case 11:
        return 0xc;
    case 12:
        return 0xd;
    case 13:
        return 0xe;
    case 14:
        return 0xf;
    case 15:
        return 0x10;
    case 16:
        return 0x11;
    case 17:
        return 0x12;
    case 18:
        return 0x13;
    case 19:
        return 0x14;
    case 20:
        return 0x15;
    case 21:
        return 0x1e;
    case 23:
        return 0x20;
    case 22:
        return 0x16;
    default:
        return 0x16;
    }
}






/*
 * Leaf: -40000 - (a * 100 + b + 50); the 100-stride and the 50-byte
 *  *  header are the record layout of the table the caller indexes.
 */
int func_021E20B8(int a, int b)
{
    return -40000 - (a * 100 + b + 50);
}






int func_021E20D4(int process, int result)
{
    int error_code;
    int dwc_error;
    int retval;

    retval = func_021E1F6C(result, &dwc_error);
    if (retval != 1) {
        func_021E17D8(0x75b, g_021E47C4, retval);
        error_code = func_021E20B8(process, retval);
        DWCi_SetError(dwc_error, error_code);
    }
    return retval;
}






/*
 * Leaf: writes the triple (2, argument, 0) into the ov175 bss descriptor
 *  *  at 0x021E5334 and reports success.  No lr save: no calls at all.
 */
void func_021E212C(u32 v)
{
    u32 *p = (u32 *)0x021E5334;
    p[2] = 2;
    p[3] = v;
    p[4] = 0;
}




void func_021E214C(void)
{
    if (g_021E5334.current_work == 0)
        g_021E5334.current_work = 1;
    else
        g_021E5334.current_work = 0;
}



void func_021E216C(int ssl_type)
{
    char upload_url[128];
    char download_url[128];

    switch (ssl_type) {
    case 1:
        func_02084F80(g_021E4C88, 128, g_021E47DC, g_021AE01C);
        func_021BF520((int)g_021E4C88);
        func_02084F80(upload_url, 128, g_021E4830, g_021AE01C);
        func_021BF520((int)upload_url);
        func_02084F80(download_url, 128, g_021E4878, g_021AE01C);
        func_021BF520((int)download_url);
        break;
    case 0:
    default:
        func_02084F80(g_021E4C88, 128, g_021E48C4, g_021AE01C);
        func_021BF520((int)g_021E4C88);
        func_02084F80(upload_url, 128, g_021E4914, g_021AE01C);
        func_021BF520((int)upload_url);
        func_02084F80(download_url, 128, g_021E495C, g_021AE01C);
        func_021BF520((int)download_url);
        break;
    }
    func_021DD4B0(g_021E5334.sake, upload_url);
    func_021DD3F8(g_021E5334.sake, download_url);
}
