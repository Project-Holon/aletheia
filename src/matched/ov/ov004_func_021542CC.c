/*
 * function: EVENT_WORLDTRADE_Create
 * address:  0x021542CC
 * packet:   pkt_ov004_021542CC
 * region:   ov004
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200AD6C  0x0200AD6C  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_0201AD0C  0x0201AD0C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_02009CC0  0x02009CC0  thumb
 *   EVENT_WORLDTRADE_Main  0x02154390  thumb  ov004
 */

typedef unsigned int   u32;
struct Big;
struct BigObj;
struct Blk37;
struct Comm;
struct Ctx;
struct Desc;
struct Obj;
struct Sub0200852CObj;
struct Sub02008700Obj;
struct Sub02008AECObj;
struct Sub02008C20Obj;
struct Sub02009470Obj;
void *func_020120F4(const struct Ctx *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Ctx;
unsigned int func_02012138(const struct Ctx *p);
u32 func_02026454(void *obj);
void func_02026400(struct Comm *p);
void *func_020124E8(struct Obj *p);
void func_02082BCC(void *p, int v, int n);
void *func_02012EBC(struct Big *p);
void *func_0200AD6C(void *sys);
struct Sub02008AECObj *func_02008B08(void *sys);
void *func_0201AD0C(void *sys);
u32 func_0201293C(const struct BigObj *p);
void *func_0200CA1C(void *a);
u32 func_0201283C(const struct BigObj *p);
struct Sub02009470Obj *func_02009470(void *sys);
struct Sub0200852CObj *func_02008730(void *sys);
struct Sub02008700Obj *func_0200873C(void *sys);
struct Sub02008C20Obj *func_02008C58(void *sys);
void *func_0201292C(const struct BigObj *p);
u32 func_0200CA38(struct Blk37 *p);
int func_02009CC0(void *a0);
u32 EVENT_WORLDTRADE_Main(void *obj, u32 *mode, u32 *args);

int EVENT_WORLDTRADE_Create(int a, int b, int c)
{
    int r6;
    int h;
    int *p;

    r6 = (int)func_020120F4((const struct Ctx *)a);
    h = (int)func_020122C0((void *)a, 0, EVENT_WORLDTRADE_Main, 0x54);
    if (func_02026454((void *)func_02012138((const struct Ctx *)a)))
        func_02026400((struct Comm *)func_02012138((const struct Ctx *)a));
    p = func_020124E8((struct Obj *)h);
    func_02082BCC(p, 0, 0x54);
    p[1] = a;
    p[2] = b;
    p[18] = (int)func_02012EBC((struct Big *)r6);
    p[3] = (int)func_0200AD6C((void *)p[18]);
    p[4] = (int)func_02008B08((void *)p[18]);
    p[5] = (int)func_0201AD0C((void *)p[18]);
    p[6] = func_0201293C((const struct BigObj *)r6);
    p[7] = (int)func_0200CA1C((void *)r6);
    p[8] = func_0201283C((const struct BigObj *)r6);
    p[9] = (int)func_02009470((void *)p[18]);
    p[10] = (int)func_02008730((void *)p[18]);
    p[11] = (int)func_0200873C((void *)p[18]);
    p[12] = (int)func_02008C58((void *)p[18]);
    *(void **)&p[13] = func_0201292C((const struct BigObj *)r6);
    p[19] = a;
    p[14] = func_0200CA38((struct Blk37 *)p[7]);
    p[15] = func_02009CC0((void *)p[8]);
    p[16] = 0;
    p[17] = 0;
    return h;
}
