/*
 * function: func_021BA88C
 * address:  0x021BA88C
 * packet:   pkt_ov114_021BA88C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_Startup (libnhttp.TWL.HYB.a(nhttp_bgnend.o))
 *
 * symbols:
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BEF40 0x021BEF40 arm ov114
 *   func_021BEF48 0x021BEF48 arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEF50 0x021BEF50 arm ov114
 *   func_021BACEC 0x021BACEC arm ov114
 *   func_021BB3C0 0x021BB3C0 arm ov114
 *   func_021BEFA4 0x021BEFA4 arm ov114
 *   func_021BEF6C 0x021BEF6C arm ov114
 *   func_021BA820 0x021BA820 arm ov114
 *   func_021BA874 0x021BA874 arm ov114
 *   func_021BEFC8 0x021BEFC8 arm ov114
 *   func_021B9B64 0x021B9B64 arm ov114
 *   func_021BA850 0x021BA850 arm ov114
 */

typedef struct {
    void *(*alloc)(unsigned long, int);
    void (*free)(void *);
    int opened;
    int fc;
    int f10;
    int f14;
    int f18;
    void *buf;
    int f20;
    int f24;
} BgnEnd;

extern BgnEnd *func_021BEF3C(void);
extern void *func_021BEF40(void *sysInfo_p);
extern void *func_021BEF48(void *sysInfo_p);
extern void *func_021BEF58(void *sysInfo_p);
extern void *func_021BEF50(void *sysInfo_p);
typedef unsigned char  u8;
extern void func_021BACEC(u8 *p);
extern void func_021BB3C0(u8 *p);
extern void func_021BEFA4(u8 *p);
extern void func_021BEF6C(void);
extern void *func_021BA820(unsigned long size, int align);
extern void func_021BA874(BgnEnd *bgnEndInfo_p, int error);
extern void func_021BEFC8();
extern int func_021B9B64(void *threadInfo_p, unsigned long priority, unsigned long *stack_p);
extern void func_021BA850(void *ptr_p);

int func_021BA88C(void *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio)
{
    void *threadInfo_p;
    void *mutexInfo_p;
    void *reqInfo_p;
    void *listInfo_p;
    BgnEnd *bgnEndInfo_p;
    unsigned long *stack_p;

    bgnEndInfo_p = func_021BEF3C();
    listInfo_p = func_021BEF40(sysInfo_p);
    reqInfo_p = func_021BEF48(sysInfo_p);
    mutexInfo_p = func_021BEF58(sysInfo_p);
    threadInfo_p = func_021BEF50(sysInfo_p);
    bgnEndInfo_p->alloc = alloc;
    bgnEndInfo_p->free = free;
    bgnEndInfo_p->f14 = 0;
    bgnEndInfo_p->f10 = 0;
    bgnEndInfo_p->f18 = 0;
    bgnEndInfo_p->f24 = 0;
    func_021BACEC(listInfo_p);
    func_021BB3C0(reqInfo_p);
    func_021BEFA4(mutexInfo_p);
    func_021BEF6C();
    bgnEndInfo_p->fc = -1;
    bgnEndInfo_p->buf = func_021BA820(0x2000, 8);
    stack_p = bgnEndInfo_p->buf;
    if (stack_p == 0) {
        func_021BA874(bgnEndInfo_p, 1);
        func_021BEFC8();
        return 0;
    }
    if (func_021B9B64(threadInfo_p, threadprio, stack_p) != 0) {
        bgnEndInfo_p->opened = 1;
        return 1;
    }
    func_021BA874(bgnEndInfo_p, 9);
    func_021BA850(bgnEndInfo_p->buf);
    bgnEndInfo_p->buf = 0;
    func_021BEFC8();
    return 0;
}
