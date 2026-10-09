/*
 * file:     unit_021BEA20.c
 * unit:     yes
 * function: func_021BEA20, func_021BEA64, func_021BEA98, func_021BEAB8, func_021BEB88, func_021BEBA8, func_021BEBC8, func_021BEBE0, func_021BEBF0, func_021BEC00, func_021BEC10, func_021BEC2C, func_021BEC48, func_021BEC74, func_021BED04, func_021BED90, func_021BEE1C, func_021BEE4C, func_021BEE74, func_021BEEC4, func_021BEF08
 * address:  0x021BEA20
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9B4C 0x021B9B4C arm ov114
 *   func_021BEFCC 0x021BEFCC arm ov114
 *   func_021BEFD8 0x021BEFD8 arm ov114
 *   func_021BA7DC  0x021BA7DC  arm  ov114
 *   func_021BACEC  0x021BACEC  arm  ov114
 *   func_021BB3C0  0x021BB3C0  arm  ov114
 *   func_021BBE94  0x021BBE94  arm  ov114
 *   func_021BEF3C  0x021BEF3C  arm  ov114
 *   func_021BEF40  0x021BEF40  arm  ov114
 *   func_021BEF48  0x021BEF48  arm  ov114
 *   func_021BEF50  0x021BEF50  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   func_021BEF98  0x021BEF98  arm  ov114
 *   g_021CF984 0x021CF984 data
 *   g_021CF984_hdr 0x021CF984 data
 *   g_021CF98C 0x021CF98C data
 *   g_021CF9C0  0x021CF9C0  data
 *   g_021CF964  0x021CF964  data
 */
#include "nhttp_types.h"

typedef struct {
    int unique;
    int mutex[6];
    int f1c;
    int f20;
} Res;

typedef struct {
    u8 pad_0[0xc];
    u32 queue;
} Waiters;

typedef struct {
    char *label;
    void *value;
    unsigned long length;
    int offset;
} PostSendArg;

typedef struct {
    void *buf;
    unsigned long length;
    unsigned long offset;
} BodyBufArg;

extern void func_021B9B4C(int *mutex_p);
extern void func_020857B0(void *);
extern void func_02085800(void *, int);
extern void func_021BEFCC(void);
extern void func_021BEFD8(void *mutexInfo_p);
extern void func_021BA7DC(void);
extern void func_021BACEC(u8 *);
extern void func_021BB3C0(u8 *);
extern void func_021BBE94(u8 *);
extern void func_021BEF3C(void);
extern void *func_021BEF40(int p);
extern void *func_021BEF48(int p);
extern void *func_021BEF50(int p);
extern void *func_021BEF58(int p);
extern void func_021BEF98(u8 *);
Res *func_021BEA20(void);
void func_021BEA64(Waiters *p);
void func_021BEA98(Waiters *p);
Conn *func_021BEAB8(void *mutexInfo_p, Conn *handle_p, unsigned long order);
int func_021BEB88(void *mutexInfo_p, Conn *handle_p);
int func_021BEBA8(void *mutexInfo_p, Conn *handle_p);
void *func_021BEBC8(void *mutexInfo_p, Conn *handle_p);
void func_021BEBE0(void *mutexInfo_p, Conn *handle_p);
Conn *func_021BEBF0(void *mutexInfo_p, Conn *handle_p);
Conn *func_021BEC00(void *mutexInfo_p, Conn *handle_p);
void *func_021BEC10(void *mutexInfo_p, void *d);
void *func_021BEC2C(void *mutexInfo_p, void *d);
u32 func_021BEC48(void);
int func_021BEC74(void *mutexInfo_p, Conn *connection_p, char *label_p, int offset);
void func_021BED04(void *mutexInfo_p, Conn *connection_p);
void func_021BED90(void *mutexInfo_p, Conn *connection_p);
void func_021BEE1C(void *mutexInfo_p, Conn *connection_p);
int func_021BEE4C(void *mutexInfo_p, Conn *connection_p, void *buf_p, unsigned long length);
int func_021BEE74(void *mutexInfo_p, Conn *connection_p, void *buf_p, unsigned long length, unsigned long offset);
void func_021BEEC4(u8 *p);
u8 *func_021BEF08(void);
extern ConnList g_021CF984;
extern ConnList g_021CF984_hdr;
extern Res g_021CF98C;
extern u8 g_021CF9C0[];


/*
 * sdk:      NHTTPi_GetStaticResource (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 */
Res *func_021BEA20(void)
{
    Res *r = &g_021CF98C;
    if (g_021CF984.init == 0) {
        func_021B9B4C(&r->mutex[0]);
        r->f20 = 0;
        r->f1c = 0;
        r->unique = 1;
    }
    return r;
}


/*
 * Drains the +0x0c queue of `p` by releasing the +0x1c resource each time.
 */
void func_021BEA64(Waiters *p)
{
    Res *q = func_021BEA20();
    while (p->queue != 0)
        func_020857B0(&q->f1c);
}


/*
 * Clears the +0x0c queue of `p` and re-arms the +0x1c resource.
 */
void func_021BEA98(Waiters *p)
{
    Res *q = func_021BEA20();
    p->queue = 0;
    func_02085800(&q->f1c, 0);
}


Conn *func_021BEAB8(void *mutexInfo_p, Conn *handle_p, unsigned long order)
{
    Conn *ret_p = 0;
    Conn **connection_pp;
    Conn *connection_p;

    func_021BEFCC();
    if (order == 3) {
        ret_p = handle_p;
        handle_p->next = g_021CF984.head;
        g_021CF984.head = handle_p;
    } else {
        connection_pp = &g_021CF984_hdr.head;
        connection_p = g_021CF984.head;
        while (connection_p != 0) {
            switch (order) {
            case 0:
                if (connection_p == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 1:
                if (connection_p->f10 == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 2:
                if (connection_p->f14 == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 4:
                if (connection_p == handle_p) {
                    ret_p = *connection_pp;
                    *connection_pp = ret_p->next;
                }
                break;
            }
            if (ret_p != 0) {
                break;
            }
            connection_pp = &(*connection_pp)->next;
            connection_p = *connection_pp;
        }
    }
    func_021BEFD8(mutexInfo_p);
    return ret_p;
}


int func_021BEB88(void *mutexInfo_p, Conn *handle_p)
{
    return -(func_021BEAB8(mutexInfo_p, handle_p, 3) == 0);
}


int func_021BEBA8(void *mutexInfo_p, Conn *handle_p)
{
    return -(func_021BEAB8(mutexInfo_p, handle_p, 4) == 0);
}


void *func_021BEBC8(void *mutexInfo_p, Conn *handle_p)
{
    Conn *p = func_021BEC00(mutexInfo_p, handle_p);

    return p ? p->f14 : 0;
}


/*
 * ov114 tail-call thunk: func_021BEAB8(a, b, 1) via `ldr ip,pool; bx ip`.
 */
void func_021BEBE0(void *mutexInfo_p, Conn *handle_p)
{
    func_021BEAB8(mutexInfo_p, handle_p, 1);
}


/*
 * ov114 tail-call thunk: func_021BEAB8(a, b, 2) via `ldr ip,pool; bx ip`.
 */
Conn *func_021BEBF0(void *mutexInfo_p, Conn *handle_p)
{
    return func_021BEAB8(mutexInfo_p, handle_p, 2);
}


Conn *func_021BEC00(void *mutexInfo_p, Conn *handle_p)
{
    return func_021BEAB8(mutexInfo_p, handle_p, 0);
}


/*
 * Looks node `a` up and returns its +0x10 field, or `d` when absent.
 */
void *func_021BEC10(void *mutexInfo_p, void *d)
{
    Conn *p = func_021BEC00(mutexInfo_p, d);
    if (p != 0)
        d = p->f10;
    return d;
}


void *func_021BEC2C(void *mutexInfo_p, void *d)
{
    Conn *p = func_021BEC00(mutexInfo_p, d);
    if (p != 0)
        d = p->f14;
    return d;
}


/*
 * Counts the entries on the +0x20 list hanging off the module object.
 */
u32 func_021BEC48(void)
{
    u32 n = 0;
    Conn *p = g_021CF984.head;
    while (p != 0) {
        p = p->next;
        n++;
    }
    return n;
}


/*
 * sdk:      NHTTPi_PostSendCallback (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 */
int func_021BEC74(void *mutexInfo_p, Conn *connection_p, char *label_p, int offset)
{
    PostSendArg arg;
    void *res_p;
    int ret = -1;

    if (func_021BEC00(mutexInfo_p, connection_p) != 0) {
        res_p = func_021BEBC8(mutexInfo_p, connection_p);
        if (res_p != 0 && connection_p->callback != 0) {
            arg.label = label_p;
            arg.value = connection_p->f24;
            arg.length = connection_p->f28;
            arg.offset = offset;
            ret = connection_p->callback(connection_p, 1, &arg);
            func_021BEE4C(mutexInfo_p, connection_p, arg.value, arg.length);
        }
    }
    return ret;
}


void func_021BED04(void *mutexInfo_p, Conn *connection_p)
{
    BodyBufArg arg;
    ConnBody *res_p;

    if (func_021BEC00(mutexInfo_p, connection_p) != 0) {
        res_p = func_021BEBC8(mutexInfo_p, connection_p);
        if (res_p != 0 && connection_p->callback != 0) {
            arg.buf = res_p->buf;
            arg.length = res_p->length;
            arg.offset = res_p->offset;
            connection_p->callback(connection_p, 2, &arg);
            func_021BEE74(mutexInfo_p, connection_p, arg.buf, arg.length, arg.offset);
        }
    }
}


/*
 * sdk:      NHTTPi_ReceivedCallback (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 */
void func_021BED90(void *mutexInfo_p, Conn *connection_p)
{
    BodyBufArg arg;
    ConnBody *res_p;

    if (func_021BEC00(mutexInfo_p, connection_p) != 0) {
        res_p = func_021BEBC8(mutexInfo_p, connection_p);
        if (res_p != 0 && connection_p->callback != 0) {
            arg.buf = res_p->buf;
            arg.length = res_p->length;
            arg.offset = res_p->offset;
            connection_p->callback(connection_p, 3, &arg);
            func_021BEE74(mutexInfo_p, connection_p, arg.buf, arg.length, arg.offset);
        }
    }
}


void func_021BEE1C(void *mutexInfo_p, Conn *connection_p)
{
    int (*g)(Conn *, int, void *);
    if (func_021BEC00(mutexInfo_p, connection_p) == 0)
        return;
    g = connection_p->callback;
    if (g == 0)
        return;
    g(connection_p, 4, 0);
}


/*
 * Stores the +0x24/+0x28 pair on node `a`; -1 when the node is absent.
 */
int func_021BEE4C(void *mutexInfo_p, Conn *connection_p, void *buf_p, unsigned long length)
{
    Conn *p = func_021BEC00(mutexInfo_p, connection_p);
    if (p == 0)
        return -1;
    p->f24 = buf_p;
    p->f28 = length;
    return 0;
}


int func_021BEE74(void *mutexInfo_p, Conn *connection_p, void *buf_p, unsigned long length, unsigned long offset)
{
    Conn *found_p = func_021BEC00(mutexInfo_p, connection_p);
    if (found_p) {
        ConnBody *res_p = func_021BEBC8(mutexInfo_p, found_p);
        if (res_p == 0) {
            return -1;
        }
        res_p->buf = buf_p;
        res_p->length = length;
        res_p->offset = offset;
        return 0;
    }
    return -1;
}


void func_021BEEC4(u8 *p)
{
    func_021BEF3C();
    func_021BA7DC();
    func_021BACEC(func_021BEF40((int)p));
    func_021BB3C0(func_021BEF48((int)p));
    func_021BEF98(func_021BEF58((int)p));
    func_021BBE94(func_021BEF50((int)p));
}


u8 *func_021BEF08(void)
{
    u8 *p = g_021CF984.cur;
    if (p == 0) {
        p = g_021CF9C0;
        g_021CF984.cur = p;
        func_021BEEC4(p);
    }
    return p;
}
