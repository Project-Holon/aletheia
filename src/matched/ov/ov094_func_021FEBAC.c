/*
 * function: func_021FEBAC
 * address: 0x021FEBAC
 * packet: pkt_ov094_021FEBAC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum loop counter keeps both entry guards; a separate local k for the
 *   first loop index puts idx at sp+8 and flag at sp+4 (one shared idx swapped them).
 * symbols:
 *   func_021FFD9C 0x021FFD9C thumb ov094
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_02016374 0x02016374 thumb
 *   func_02014C08 0x02014C08 thumb
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021F935C 0x021F935C thumb ov094
 *   func_021FF2D8 0x021FF2D8 thumb ov094
 *   func_021FF870 0x021FF870 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021FFF38 0x021FFF38 thumb ov094
 *   func_021F821C 0x021F821C thumb ov094
 *   func_021FFE24 0x021FFE24 thumb ov094
 *   func_021FF260 0x021FF260 thumb ov094
 *   func_021FF304 0x021FF304 thumb ov094
 *   func_021FF498 0x021FF498 thumb ov094
 *   func_021FFDF8 0x021FFDF8 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef enum { KEY_0 } Key;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int f2 : 5;
    unsigned int f7 : 1;
    unsigned int f8 : 1;
    unsigned int f9 : 2;
    unsigned int f11 : 1;
    int f50;                /* 0x50 */
    int f54;                /* 0x54 */
    int f58;                /* 0x58 */
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;
    int m518;
    int m51c;
    int m520;
    int m524;
    int m528;               /* 0x528 */
} Work;

extern int func_021FFD9C(char *p, int key);
extern int func_022019F4(char *p, int key);
extern void func_02016374(void *h);
extern void func_02014C08(char *self);
extern u32 func_0203F0A8(void);
extern int func_021F935C(int x);
extern int func_021FF2D8(Work *w, int key);
extern void func_021FF870(Work *w, int key, int kind, int a, int b);
extern int func_021F7EB4(void);
extern int func_021FFF38(char *p, int key);
extern int func_021F821C(int key, int *a, int *b);
extern void func_021FFE24(Work *w, int key);
extern void func_021FF260(Work *w, int key, int mode);
extern void func_021FF304(Work *w, int key, int mode);
extern void func_021FF498(char *p, int key, void *v);
extern void func_021FFDF8(Work *w, int key, int a, int b);

void func_021FEBAC(Work *w)
{
    Key i;
    int k;
    int idx;
    int flag;
    int a;
    int b;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            k = func_022019F4((char *)w, i);
            if (w->e[k].f11) {
                w->e[k].f11 = 0;
                func_02016374(w->e[k].h);
            }
        }
    }
    func_02014C08(w->obj);
    if (w->f510 == 0) {
        for (i = 0; i < 8; i++) {
            if (func_021FFD9C((char *)w, i)
                && (u32)(((u64)func_0203F0A8() * 100) >> 32) == 0
                && (func_021F935C(i) & w->m528) == 0
                && func_021FF2D8(w, i) == 0)
                func_021FF870(w, i, 2, 4, 1);
            if (func_021FFD9C((char *)w, i) == 0)
                continue;
            idx = func_022019F4((char *)w, i);
            flag = 0;
            if (func_021F7EB4() && w->e[idx].f8) {
                w->e[idx].f8 = 0;
                w->e[idx].f7 = 1;
            }
            if (func_021F7EB4() && w->e[idx].f7)
                continue;
            w->e[idx].f7 = 0;
            if (func_021FFF38((char *)w, i) & 4)
                continue;
            if (func_021F821C(i, &a, &b) == 0)
                continue;
            if (w->e[idx].f1 == 1) {
                if (w->e[idx].f54 == 0)
                    w->e[idx].f54 = 1;
                if (w->e[idx].f58++ > 0x18) {
                    flag = 1;
                    w->e[idx].f58 = 0;
                    w->e[idx].f50 += w->e[idx].f54;
                    if (w->e[idx].f50 == 0 || w->e[idx].f50 == 12)
                        w->e[idx].f54 *= -1;
                }
            }
            switch (b) {
            case 3:
                func_021FFE24(w, i);
                func_021FF260(w, i, 3);
                func_021FF304(w, i, 3);
                func_021FF498((char *)w, i, (void *)0x555);
                w->e[idx].f1 = 1;
                break;
            case 1:
                if (flag == 1)
                    func_021FFDF8(w, i, (u8)w->e[idx].f50, 0x1ef);
                func_021FF260(w, i, 4);
                func_021FF304(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 2:
                if (flag == 1)
                    func_021FFDF8(w, i, 8, 0x7def);
                func_021FF260(w, i, 4);
                func_021FF304(w, i, 2);
                w->e[idx].f1 = 1;
                break;
            case 5:
                if (flag == 1)
                    func_021FFDF8(w, i, (u8)w->e[idx].f50, 0xf);
                func_021FF260(w, i, 4);
                func_021FF304(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 4:
            case 7:
                if (flag == 1)
                    func_021FFDF8(w, i, (u8)w->e[idx].f50, 0x3c0f);
                func_021FF260(w, i, 4);
                func_021FF304(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 8:
            default:
                if (w->e[idx].f1 == 1) {
                    func_021FFE24(w, i);
                    func_021FF260(w, i, 4);
                    func_021FF304(w, i, 3);
                    func_021FF498((char *)w, i, (void *)0x1000);
                    w->e[idx].f1 = 0;
                    w->e[idx].f54 = 0;
                    w->e[idx].f50 = 0;
                    w->e[idx].f58 = 0;
                }
                break;
            }
            if (b == 8) {
                if ((u32)(a - 2) <= 1)
                    func_021FF498((char *)w, i, (void *)0x555);
                else
                    func_021FF498((char *)w, i, (void *)0x1000);
            }
        }
    }
}
