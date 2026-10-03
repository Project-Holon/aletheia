/*
 * function: func_0217CA84
 * address:  0x0217CA84
 * packet:   pkt_ov018_0217CA84
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0217C094  0x0217C094  thumb
 *   func_0217CAFC  0x0217CAFC  thumb
 */

typedef struct {
    unsigned char pad00[0x20];
    int f20;
    int f24;
} Ov018Work;

void *func_02012138(void *);
int func_020122C0(void *, int, void (*)(void), int);
Ov018Work *func_020124E8(int);
typedef unsigned int   u32;
struct Ctx;
u32 func_02026454(void *obj);
unsigned char *func_02026474(void *);
u32 func_0202647C(void *obj);
u32 func_02012204(const struct Ctx *p);
void func_020061E4(u32 a);
void func_0217C094(unsigned char *);
void func_0217CAFC(void);

int func_0217CA84(void *a, int b)
{
    void *sys;
    int ret;
    Ov018Work *work;
    unsigned char *x;

    sys = func_02012138(a);
    ret = func_020122C0(a, 0, func_0217CAFC, 0x28);
    work = func_020124E8(ret);
    work->f20 = b;
    if (func_02026454(sys) == 2) {
        x = func_02026474(sys);
        if (x != 0) {
            func_0217C094(func_02026474(sys));
            x[0x8F8] |= 0x80;
        }
    }
    if (func_02012204(a) == 1) {
        if (func_0202647C(sys) == 1) {
            work->f24 = 1;
        }
    }
    func_020061E4(0x737);
    return ret;
}
