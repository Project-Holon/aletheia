/*
 * file:     unit_021B9C80_p01.c
 * unit:     yes
 * function: func_021B9C80, func_021B9CA4, func_021B9CE4, func_021B9CFC
 * address:  0x021B9C80
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
 *   g_021CF964  0x021CF964  data
 *   func_0215F644 0x0215F644 arm
 *   func_02085A38 0x02085A38 arm
 *   func_0215EBB4 0x0215EBB4 arm
 *   func_021BA850 0x021BA850 arm ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    char pad[0xac];
    void *pSslCon;
} Req;

extern void func_02088168(u32 *buffer);
extern void func_02162248(void *, int);
extern int func_0215F4DC(int, int *, int, int);
extern void func_0215F428(int, int, int);
extern int func_0215F644(int socket);
extern void func_02085A38(unsigned long msec);
extern void func_0215EBB4(void);
extern void func_021BA850(int a);
void func_021B9C80(void);
int func_021B9CA4(int a);
void func_021B9CE4(void);
int func_021B9CFC(int unused, Req *req_p, int socket);
extern u8 g_021CF964[];


void func_021B9C80(void)
{
    func_02088168((u32 *)g_021CF964);
    func_02162248(g_021CF964, 0x20);
}


int func_021B9CA4(int a)
{
    int v = 0;
    if (a == -1) {
        v = -1;
    } else {
        int n = 4;
        int tmp;
        if (func_0215F4DC(a, &tmp, 1, n) != n - 10)
            v = n - 5;
    }
    return v;
}


void func_021B9CE4(void)
{
    func_0215F428(2, 1, 0);
}


int func_021B9CFC(int unused, Req *req_p, int socket)
{
    int error;
    int elapsed;

    error = func_0215F644(socket);
    if (error == 0 || error == -26) {
        for (elapsed = 0; (error = func_0215F644(socket)) == -26 && elapsed <= 10000; elapsed += 500) {
            func_02085A38(500);
            func_0215EBB4();
        }
    }
    if (error != -26 && req_p != 0 && req_p->pSslCon != 0) {
        func_021BA850((int)req_p->pSslCon);
        req_p->pSslCon = 0;
    }
    return error;
}
