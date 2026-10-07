/*
 * file:     unit_021BEA20_p04.c
 * unit:     yes
 * function: func_021BED90, func_021BEE1C, func_021BEE4C, func_021BEE74, func_021BEEC4, func_021BEF08
 * address:  0x021BED90
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
 *   func_021BEC00 0x021BEC00 arm ov114
 *   func_021BEBC8 0x021BEBC8 arm ov114
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
 *   g_021CF984  0x021CF984  data
 *   g_021CF98C  0x021CF98C  data
 *   g_021CF9C0  0x021CF9C0  data
 *   g_021CF964  0x021CF964  data
 */
struct Conn;
typedef struct {
    void *buf;
    unsigned long length;
    unsigned long offset;
} BodyBufArg;

typedef struct {
    int f0;
    unsigned long offset;
    char pad[0x14];
    unsigned long length;
    char pad2[8];
    void *buf;
} Res_021BED90;

typedef struct Conn {
    char pad[0x1c];
    int (*callback)(struct Conn *, int, BodyBufArg *);
} Conn;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    char pad[0x14];
    int f1c;
    char pad2[8];
    void *f28;
} Res_021BEE74;

extern struct Conn *func_021BEC00(int a, int b);
extern int func_021BEBC8(int a, int b);
void func_021BEF3C(void);
void func_021BA7DC(void);
void *func_021BEF40(int p);
void func_021BACEC(u8 *);
void *func_021BEF48(int p);
void func_021BB3C0(u8 *);
void *func_021BEF58(int p);
void func_021BEF98(u8 *);
void *func_021BEF50(int p);
void func_021BBE94(u8 *);
void func_021BED90(void *mutexInfo_p, Conn *connection_p);
void func_021BEE1C(int a, u8 *b);
int func_021BEE4C(int a, int b, int c, int d);
int func_021BEE74(void *mutexInfo_p, void *handle, void *buf_p, unsigned long length, unsigned long offset);
void func_021BEEC4(u8 *p);
u8 *func_021BEF08(void);
extern u8 g_021CF984[];
extern u8 g_021CF9C0[];


/*
 * sdk:      NHTTPi_ReceivedCallback (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 */
void func_021BED90(void *mutexInfo_p, Conn *connection_p)
{
    BodyBufArg arg;
    Res_021BED90 *res_p;

    if (func_021BEC00((int)mutexInfo_p, (int)connection_p) != 0) {
        res_p = (Res_021BED90 *)func_021BEBC8((int)mutexInfo_p, (int)connection_p);
        if (res_p != 0 && connection_p->callback != 0) {
            arg.buf = res_p->buf;
            arg.length = res_p->length;
            arg.offset = res_p->offset;
            connection_p->callback(connection_p, 3, &arg);
            func_021BEE74(mutexInfo_p, connection_p, arg.buf, arg.length, arg.offset);
        }
    }
}


void func_021BEE1C(int a, u8 *b)
{
    void (*g)(u8 *, int, int);
    if (func_021BEC00(a, (int)b) == 0)
        return;
    g = *(void (**)(u8 *, int, int))(b + 0x1c);
    if (g == 0)
        return;
    g(b, 4, 0);
}


/*
 * Stores the +0x24/+0x28 pair on node `a`; -1 when the node is absent.
 */
int func_021BEE4C(int a, int b, int c, int d)
{
    u8 *p = (u8 *)func_021BEC00(a, b);
    if (p == 0)
        return -1;
    *(u32 *)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = d;
    return 0;
}


int func_021BEE74(void *mutexInfo_p, void *handle, void *buf_p, unsigned long length, unsigned long offset)
{
    void *connection_p = func_021BEC00((int)mutexInfo_p, (int)handle);
    if (connection_p) {
        Res_021BEE74 *res_p = (Res_021BEE74 *)func_021BEBC8((int)mutexInfo_p, (int)connection_p);
        if (res_p == 0) {
            return -1;
        }
        res_p->f28 = buf_p;
        res_p->f1c = length;
        res_p->f4 = offset;
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
    u8 *p = *(u8 **)(g_021CF984 + 4);
    if (p == 0) {
        p = g_021CF9C0;
        *(u8 **)(g_021CF984 + 4) = p;
        func_021BEEC4(p);
    }
    return p;
}
