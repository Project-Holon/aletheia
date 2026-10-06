/*
 * function: func_021BD3B8
 * address:  0x021BD3B8
 * packet:   pkt_ov114_021BD3B8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadExecReqQueue (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEFCC 0x021BEFCC arm ov114
 *   func_021BEF40 0x021BEF40 arm ov114
 *   func_021BAEC8 0x021BAEC8 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BEFD8 0x021BEFD8 arm ov114
 *   func_021BEF50 0x021BEF50 arm ov114
 *   func_021B9BF4 0x021B9BF4 arm ov114
 */

typedef struct {
    char pad[8];
    int a8;
} ReqList;

typedef struct {
    ReqList *reqCurrent;
} ReqInfo;

typedef struct {
    int result;
} ThreadData;

typedef unsigned char  u8;
extern u8 *func_021BEF08(void);
extern void *func_021BEF58();
extern void func_021BEFCC();
extern void *func_021BEF40(int p);
extern ReqList *func_021BAEC8();
extern void *func_021BEF48(int p);
extern void func_021BEFD8(void *mutexInfo_p);
extern void *func_021BEF50(void *sysInfo_p);
extern void func_021B9BF4(int a);

int func_021BD3B8(ThreadData *threadData_p)
{
    void *sysInfo_p;
    void *mutexInfo_p;
    void *listInfo_p;
    ReqList *list_p;
    ReqInfo *reqInfo_p;
    void *threadInfo_p;

    sysInfo_p = func_021BEF08();
    mutexInfo_p = func_021BEF58();
    func_021BEFCC();
    listInfo_p = func_021BEF40((int)sysInfo_p);
    list_p = func_021BAEC8(listInfo_p);
    if (list_p == 0) {
        threadData_p->result = -1;
    } else {
        reqInfo_p = func_021BEF48((int)sysInfo_p);
        threadData_p->result = list_p->a8;
        reqInfo_p->reqCurrent = list_p;
    }
    func_021BEFD8(mutexInfo_p);
    if (threadData_p->result >= 0) {
        return 1;
    }
    threadInfo_p = func_021BEF50(sysInfo_p);
    func_021B9BF4((int)threadInfo_p);
    return 0;
}
