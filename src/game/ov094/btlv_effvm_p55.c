/*
 * file:     btlv_effvm_p55.c
 * unit:     yes
 * function: func_021FE38C, func_021FE410, func_021FE4D0, func_021FE4F8, func_021FE520, func_021FE54C, func_021FE580, func_021FE594
 * address:  0x021FE38C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_022003C4  0x022003C4  thumb  ov094
 *   func_0202142C  0x0202142C  thumb
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F9154  0x021F9154  thumb  ov094
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021FE768  0x021FE768  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_022004BC  0x022004BC  thumb  ov094
 *   func_021FF470  0x021FF470  thumb  ov094
 *   func_021FDB40  0x021FDB40  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_02030EE8  0x02030EE8  arm
 *   func_02006138 0x02006138 thumb
 *   func_02006268 0x02006268 thumb
 *   func_02072F34 0x02072F34 arm
 */
#include "../../matched/include/Obj00325.h"
#include "../../matched/include/Obj13601.h"

struct S02030EE8;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    unsigned int f0 : 9;
    unsigned int f9 : 1;
    unsigned int f10 : 1;
} Flags;

typedef struct {
    Flags *fl;
    int a;
    int b;
    int v[3];
} Rec;

typedef struct {
    Flags fl;
    char pad04[4];
    int h;
    char pad0c[0xd0];
    unsigned int heap : 32;
} Obj;

typedef enum { KEY_0 } Key;

typedef unsigned char u8;

extern int func_021F8694(void);
extern int func_022003C4(char *p, int key);
extern unsigned short func_0202142C(int a0);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02030DA8(int owner, void *fn, void *arg, int n);
extern void func_021F9154(int a, int b, int *out, int c);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE768(void *h, int *s);
extern int func_021FFD9C(char *p, int key);
extern void func_022004BC(void *w, int key);
extern void func_021FF470(char *p, int key, void *v);
extern void func_021FDB40(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g);
extern void func_021F89BC(void *h);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern unsigned int *func_02006138(int i);
extern void func_02006268(int i, u32 a, u32 b, u32 c);
extern void func_02072F34(char *, unsigned int);
unsigned int func_021FE38C(char *p, unsigned int k);
void func_021FE410(Obj *o, int a, int b, int n);
int func_021FE4D0(char *p);
void func_021FE4F8(void);
void func_021FE520(void);
void func_021FE54C(void *h, int *s);
void func_021FE580(void *h);
void func_021FE594(void *h, int *s);
extern char d_0220AE68[];


/*
 * Levers: v and k unsigned (bhi/bhs/blo compares); the middle arm is
 * `mode != 8` and the mode==8 arm last, which puts its block after the
 * cross-jumped func_022003C4 call.
 */
unsigned int func_021FE38C(char *p, unsigned int k)
{
    int mode = ((struct Obj00325 *)p)->f25C;
    unsigned int v;

    if (mode == 9)
        v = func_022003C4((char *)func_021F8694(), ((struct Obj00325 *)p)->fDC);
    else if (mode != 8)
        v = func_022003C4((char *)func_021F8694(), mode);
    else
        v = func_0202142C(((struct Obj00325 *)p)->f254);
    if (v == 0 || v > 0x19)
        v = 4;
    v--;
    switch (k) {
    case 3:
        k += v;
        break;
    case 0x1d:
        if (v + 1 == 0x19)
            v = 0x10;
        else if (v + 1 >= 0x10)
            v = 3;
        k += v;
        break;
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
        k += v << 2;
        break;
    }
    return k;
}


/*
 * Sets/clears the 0x200/0x400 flag bits of *o, allocates a 0x10-byte record
 * (heap from the u16 at +0x238), converts n to fx32 (n<<12, +-0.5 rounding)
 * and registers func_021FE768 as a task callback through func_02030DA8.
 */
void func_021FE410(Obj *o, int a, int b, int n)
{
    Rec *r;
    int fx;

    if (a > b) {
        if (o->fl.f9) {
            o->fl.f10 = 1;
            return;
        }
        o->fl.f9 = 1;
    } else {
        o->fl.f9 = 0;
    }
    r = func_02030734((u16)(((u16)((struct Obj13601 *)o)->f238 & 0x7fff) | 0x8000), 0x10, 0, d_0220AE68, 0x1d78);
    r->a = a;
    r->b = b;
    r->fl = (Flags *)o;
    if (n > 0)
        fx = _ffix(_fadd(0.5f, _fflt(n << 12)));
    else
        fx = _ffix(_fsub(_fflt(n << 12), 0.5f));
    func_021F9154(r->a, r->b, r->v, fx);
    func_021F896C((void *)func_02030DA8(((struct Obj13601 *)o)->f8, (void *)func_021FE768, r, 0), 0, 1);
}

/*
 * lane O10 candidate
 */
int func_021FE4D0(char *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(int *)(p + 0x26c + i * 4) == -1)
            break;
    }
    if (i == 6)
        i = 0;
    return i;
}

void func_021FE4F8(void)
{
    Key i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i) == 1)
            func_022004BC((void *)func_021F8694(), i);
    }
}


void func_021FE520(void)
{
    Key i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i) == 1)
            func_021FF470((char *)func_021F8694(), i, 0);
    }
}


void func_021FE54C(void *h, int *s)
{
    if (--s[4] == 0) {
        func_021FDB40(s[1], s[2], s[3], s[5], s[6], s[7], s[8]);
        func_021F89BC(h);
    }
}


void func_021FE580(void *h)
{
    unsigned int *p = *((unsigned int **)func_02030EE8(h));

    *p &= ~4u;
}

/*
 * trailing: two zero alignment bytes at 0x021FE68E.
 */
void func_021FE594(void *h, int *s)
{
    int done;
    int v;
    done = 0;
    if (s[8] != 0) {
        s[8]--;
        return;
    }
    if (s[11] == 0) {
        s[11] = s[12];
        s[6] += s[7];
        v = s[6] >> 12;
        if (s[13] & 1) {
            if (s[7] < 0) {
                if (v < s[4])
                    v = s[4];
            } else {
                if (v > s[4])
                    v = s[4];
            }
        } else {
            if (s[7] < 0) {
                if (v < s[5])
                    v = s[5];
            } else {
                if (v > s[5])
                    v = s[5];
            }
        }
        if (v > 0)
            s[6] = _ffix(_fadd(0.5f, _fflt(v << 12)));
        else
            s[6] = _ffix(_fsub(_fflt(v << 12), 0.5f));
        switch (s[3]) {
        case 0: func_02006268(s[1], -1, v, -1); break;
        case 1: func_02072F34((char *)func_02006138(s[1]), v); break;
        case 2: func_02006268(s[1], -1, -1, v); break;
        }
        if (s[9] == 0) {
            s[9] = s[10];
            switch (s[2]) {
            case 0: done = 1; break;
            case 1:
                s[13]--;
                if (s[13] != 0)
                    s[7] *= -1;
                else
                    done = 1;
                break;
            }
        } else {
            s[9]--;
        }
    } else {
        s[11]--;
    }
    if (done == 1)
        func_021F89BC(h);
}
