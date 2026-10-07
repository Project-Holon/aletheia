/*
 * file:     unit_021F5260.c
 * unit:     yes
 * function: func_021F5260, func_021F526C, func_021F5278, func_021F5284, func_021F5290, func_021F529C, func_021F52A8, func_021F52B4, func_021F52C0, func_021F52CC, func_021F52D8, func_021F52E4, func_021F52F0, func_021F52FC, func_021F5308, func_021F5314, func_021F5320, func_021F532C, func_021F5338, func_021F5344, func_021F5350, func_021F535C, func_021F5368, func_021F5374, func_021F5380, func_021F538C, func_021F5398, func_021F53C8
 * address:  0x021F5260
 * region:   ov073
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF52C 0x021CF52C thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_021C1DCC  0x021C1DCC  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021F5488  0x021F5488  thumb  ov073
 */
struct Ctx;
struct Desc;
struct Obj;
struct Evt;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed int     s32;

extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 *func_021CF52C(void *,u32,u32);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern u32 func_021CF560(u32 *p);
extern void *func_02189A00(u8 *p);
extern int func_021C1DCC(int a, char *b, int c, int d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern int func_021F5488(void *task, int *st);
void func_021F5260(int a, int b, int c);
void func_021F526C(int a, int b, int c);
void func_021F5278(int a, int b, int c);
void func_021F5284(int a, int b, int c);
void func_021F5290(int a, int b, int c);
void func_021F529C(int a, int b, int c);
void func_021F52A8(int a, int b, int c);
void func_021F52B4(int a, int b, int c);
void func_021F52C0(int a, int b, int c);
void func_021F52CC(int a, int b, int c);
void func_021F52D8(int a, int b, int c);
void func_021F52E4(int a, int b, int c);
void func_021F52F0(int a, int b, int c);
void func_021F52FC(int a, int b, int c);
void func_021F5308(int a, int b, int c);
void func_021F5314(int a, int b, int c);
void func_021F5320(int a, int b, int c);
void func_021F532C(int a, int b, int c);
void func_021F5338(int a, int b, int c);
void func_021F5344(int a, int b, int c);
void func_021F5350(int a, int b, int c);
void func_021F535C(int a, int b, int c);
void func_021F5368(int a, int b, int c);
void func_021F5374(int a, int b, int c);
void func_021F5380(int a, int b, int c);
void func_021F538C(int a, int b, int c);
void *func_021F5398(void *a,int unused,u32 b,u32 c);
int func_021F53C8(void *task, int *st);


void func_021F5260(int a, int b, int c)
{
    func_021F5398((void *)a, b, 0, c);
}


/*
 * 26 thin wrappers over func_021F5398, each passing a distinct index.
 */
void func_021F526C(int a, int b, int c)
{
    func_021F5398((void *)a, b, 1, c);
}


void func_021F5278(int a, int b, int c)
{
    func_021F5398((void *)a, b, 2, c);
}


void func_021F5284(int a, int b, int c)
{
    func_021F5398((void *)a, b, 3, c);
}


void func_021F5290(int a, int b, int c)
{
    func_021F5398((void *)a, b, 4, c);
}


void func_021F529C(int a, int b, int c)
{
    func_021F5398((void *)a, b, 5, c);
}


void func_021F52A8(int a, int b, int c)
{
    func_021F5398((void *)a, b, 6, c);
}


void func_021F52B4(int a, int b, int c)
{
    func_021F5398((void *)a, b, 7, c);
}


void func_021F52C0(int a, int b, int c)
{
    func_021F5398((void *)a, b, 8, c);
}


void func_021F52CC(int a, int b, int c)
{
    func_021F5398((void *)a, b, 9, c);
}


void func_021F52D8(int a, int b, int c)
{
    func_021F5398((void *)a, b, 10, c);
}


void func_021F52E4(int a, int b, int c)
{
    func_021F5398((void *)a, b, 11, c);
}


void func_021F52F0(int a, int b, int c)
{
    func_021F5398((void *)a, b, 12, c);
}


void func_021F52FC(int a, int b, int c)
{
    func_021F5398((void *)a, b, 13, c);
}


void func_021F5308(int a, int b, int c)
{
    func_021F5398((void *)a, b, 14, c);
}


void func_021F5314(int a, int b, int c)
{
    func_021F5398((void *)a, b, 15, c);
}


void func_021F5320(int a, int b, int c)
{
    func_021F5398((void *)a, b, 16, c);
}


void func_021F532C(int a, int b, int c)
{
    func_021F5398((void *)a, b, 17, c);
}


void func_021F5338(int a, int b, int c)
{
    func_021F5398((void *)a, b, 18, c);
}


void func_021F5344(int a, int b, int c)
{
    func_021F5398((void *)a, b, 19, c);
}


void func_021F5350(int a, int b, int c)
{
    func_021F5398((void *)a, b, 20, c);
}


void func_021F535C(int a, int b, int c)
{
    func_021F5398((void *)a, b, 21, c);
}


void func_021F5368(int a, int b, int c)
{
    func_021F5398((void *)a, b, 22, c);
}


void func_021F5374(int a, int b, int c)
{
    func_021F5398((void *)a, b, 23, c);
}


void func_021F5380(int a, int b, int c)
{
    func_021F5398((void *)a, b, 24, c);
}


void func_021F538C(int a, int b, int c)
{
    func_021F5398((void *)a, b, 25, c);
}

void *func_021F5398(void *a,int unused,u32 b,u32 c) {
    u32 *w;
    w=func_021CF52C((void *)func_02189A08((unsigned char *)((int)func_0201210C(a))),12,0x50);
    w[0]=0; w[1]=b; w[2]=c;
    return func_020122C0(a,0,(void *)func_021F53C8,0);
}


int func_021F53C8(void *task, int *st)
{
    void *t;
    void *v;
    int *w;
    int r;

    t = func_020124E4(task);
    v = func_0201210C(t);
    w = (int *)func_021CF560((u32 *)func_02189A08((unsigned char *)((int)v)));
    switch (*st) {
    case 0:
        func_0204E720(4, 0, 0x10, 0);
        *st = *st + 1;
    case 1:
        if (func_0204E804() == 0) {
            func_0204E720(4, 0x10, 0, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            w[0] = w[0] + 1;
            if (w[0] < 2) {
                func_0204E720(4, 0, 0x10, 0);
                *st = 1;
            } else {
                r = func_021C1DCC((int)t, func_02189A00((u8 *)v), w[1], w[2]);
                if (r != 0) {
                    func_02012374(task, (struct Evt **)r);
                } else {
                    r = (int)func_020122C0(t, task, (void *)func_021F5488, 0);
                    func_02012374(task, (struct Evt **)r);
                }
                *st = *st + 1;
            }
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
