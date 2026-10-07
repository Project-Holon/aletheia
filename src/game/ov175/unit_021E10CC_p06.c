/*
 * file:     unit_021E10CC_p06.c
 * unit:     yes
 * function: func_021E191C, func_021E1948, func_021E1D70, func_021E1DD0, func_021E1EAC, func_021E1EC4
 * address:  0x021E191C
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
 *   func_0217CD94  0x0217CD94  arm  ov009
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *   func_0217CE1C  0x0217CE1C  arm  ov009
 *   func_021E17D8  0x021E17D8  arm   ov175
 *   func_021E20D4  0x021E20D4  arm   ov175
 *   g_021E5334     0x021E5334  data
 *   g_021E534C     0x021E534C  data
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
 *   g_021E457C     0x021E457C  data
 *   g_021E478C     0x021E478C  data
 *   g_021E47A0     0x021E47A0  data
 *   g_021E47B0   0x021E47B0  data
 */
typedef enum { DWC_GDB_PROCESS_NONE } DWCGdbProcess;

typedef void (*DWCGdbGetRecordsCallback)(int num, void **records, void *user_param);

typedef struct {
    int unk0;
    void *sake;
    int state;
    DWCGdbProcess process;
    int result;
    unsigned long current_work;
} Tbl;

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
    char size[0x38];
} Work;

typedef struct {
    int mNumRecords;
    void **mRecords;
} RecordsOutput;

typedef int s32_021E1D70;

typedef signed int s32_021E1DD0;

typedef unsigned int u32;

extern void func_0217CD94(void);
extern void func_0217CCCC(unsigned int theMS);
extern int  func_0217CE1C(void);
extern void func_021E17D8(int line, char *fmt, ...);
extern int func_021E20D4(int process, int result);
extern void func_02059F54(int a, int b);
void func_021E191C(void);
void func_021E1948(void *sake, void *request, int result, void *inputData, void *outputData, void *userData);
s32_021E1D70 func_021E1D70(s32_021E1D70 a, s32_021E1D70 *p);
s32_021E1DD0 func_021E1DD0(s32_021E1DD0 a, s32_021E1DD0 *st);
int func_021E1EAC(int a, int b);
int func_021E1EC4(int mode);
extern Tbl g_021E5334;
extern Work g_021E534C[];
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
extern char g_021E457C[];
extern char g_021E478C[];
extern char g_021E47A0[];
extern u32  g_021E47B0[];


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
            CreateRecordWork *work = &g_021E534C[g_021E5334.current_work].create;
            *work->recordId = *(int *)outputData;
            func_021E17D8(0x5af, g_021E4674, g_021E44D4[process], work->mTableId, work->mNumFields, *work->recordId);
            break;
        }
        case 3: {
            DeleteRecordWork *work = &g_021E534C[g_021E5334.current_work].del;
            func_021E17D8(0x5b8, g_021E46A0, g_021E44D4[process], work->mTableId, work->mRecordId);
            break;
        }
        case 4: {
            UpdateRecordWork *work = &g_021E534C[g_021E5334.current_work].update;
            func_021E17D8(0x5c2, g_021E46BC, g_021E44D4[process], work->mTableId, work->mRecordId, work->mNumFields);
            break;
        }
        case 7: {
            GetMyRecordsWork *work = &g_021E534C[g_021E5334.current_work].getMyRecords;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5cb, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 8: {
            GetRecordLimitWork *work = &g_021E534C[g_021E5334.current_work].getRecordLimit;
            *work->limit_num = ((int *)outputData)[0];
            *work->owned_num = ((int *)outputData)[1];
            func_021E17D8(0x5d8, g_021E4700, g_021E44D4[process], work->mTableId, *work->limit_num, *work->owned_num);
            break;
        }
        case 9: {
            GetRecordsWork *work = &g_021E534C[g_021E5334.current_work].getRecords;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5e1, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 10: {
            RateRecordWork *work = &g_021E534C[g_021E5334.current_work].rate;
            func_021E17D8(0x5ec, g_021E472C, g_021E44D4[process], work->mTableId, work->mRecordId, work->mRating);
            break;
        }
        case 11: {
            SearchRecordsWork *work = &g_021E534C[g_021E5334.current_work].search;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5f5, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 12: {
            GetRandomRecordWork *work = &g_021E534C[g_021E5334.current_work].getRandomRecord;
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
            GetRecordCountWork *work = &g_021E534C[g_021E5334.current_work].getRecordCount;
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
