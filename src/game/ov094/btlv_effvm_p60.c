/*
 * file:     btlv_effvm_p60.c
 * unit:     yes
 * function: func_021FF144, func_021FF16C
 * address:  0x021FF144
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
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015C48  0x02015C48  thumb
 *   sub_02015BF0   0x02015BF0  thumb
 *   func_022006B4  0x022006B4  thumb  ov094
 */
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry_021FF144;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF144 e[14];            /* 0x008 */
} Work_021FF144;

typedef unsigned int   u32;

typedef long long s64;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF16C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF16C e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work_021FF16C;

extern int func_022019F4(char *p, int key);
extern void func_02015C48(void *p, u32 *src);
extern void sub_02015BF0(void *obj);
extern void func_022006B4(Work_021FF16C *w, int i);
void func_021FF144(Work_021FF144 *w, int key, fx32 x, fx32 y, fx32 z);
void func_021FF16C(Work_021FF16C *w);


void func_021FF144(Work_021FF144 *w, int key, fx32 x, fx32 y, fx32 z)
{
    int idx = func_022019F4((char *)w, key);
    VecFx32 v;

    v.x = x;
    v.y = y;
    v.z = z;
    func_02015C48(w->e[idx].h, (u32 *)(&v));
}


void func_021FF16C(Work_021FF16C *w)
{
    int i;
    int idx;

    sub_02015BF0(w->obj);
    w->active = 1;
    for (i = 0; i < 14; i++) {
        idx = func_022019F4((char *)w, i);
        if (idx != -1) {
            w->e[idx].flip = 1;
            func_022006B4(w, i);
        }
    }
}
