/*
 * file:     btlv_effvm_p67.c
 * unit:     yes
 * function: func_021FFD9C, func_021FFDB4, func_021FFDF8
 * address:  0x021FFD9C
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
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_02015F50  0x02015F50  thumb
 *   func_020160D4  0x020160D4  thumb
 */
struct McssFade;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned int u32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    u32 flags;              /* 0x4c */
    char pad50[0x0c];
} Entry_021FFDB4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFDB4 e[14];            /* 0x008 */
} Work;

typedef signed int     s32;

typedef struct {
    int w[9];
} Rec;

typedef struct {
    void *h;                /* 0x00 */
    Rec rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_021FFDF8;

extern int func_022019F4(char *p, int key);
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void func_020160D4(void *obj, void *h, int a, int b);
int func_021FFD9C(char *p, int key);
void func_021FFDB4(Work *w, int key, u8 cur, u8 target, s8 step, u32 e);
void func_021FFDF8(Work *w, int key, int a, int b);


/*
 * lane O10 candidate
 */
int func_021FFD9C(char *p, int key)
{
    if (func_022019F4(p, key) != -1)
        return 1;
    return 0;
}


void func_021FFDB4(Work *w, int key, u8 cur, u8 target, s8 step, u32 e)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    func_02015F50(w->e[idx].h, cur, target, step, e);
    w->e[idx].flags |= 0x100;
}


void func_021FFDF8(Work *w, int key, int a, int b)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    func_020160D4(w->obj, w->e[idx].h, a, b);
}
