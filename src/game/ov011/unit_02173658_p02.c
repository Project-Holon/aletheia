/*
 * file:     unit_02173658_p02.c
 * unit:     yes
 * function: func_021737A8, func_021737CC
 * address:  0x021737A8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02026478  0x02026478  thumb
 *   func_02174EAC  0x02174EAC  thumb  ov011
 *   func_02012B58  0x02012B58  thumb
 *   func_0203D378  0x0203D378  arm
 */
struct Entry;
struct BigObj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    u8 pad08[0x8fa];
    u8 n;
    u8 pad03[0x3c];
    u8 flag : 1;
} D;

typedef struct {
    u8 pad[0x4b];
    u8 lo : 6;
    u8 hit : 1;
} C;

extern int func_021736D8(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern unsigned int func_02026478(void *obj);
extern void func_02174EAC(u8 *p, int idx, u8 *q);
extern u8 func_02012B58(const struct BigObj *p);
extern u32 func_0203D378(void);
int func_021737A8(void);
void func_021737CC(int a, int b, C *c, D *d);

/*
 * Return-valued externs reflect r0 consumed after both forwarding calls.
 */
int func_021737A8(void)
{
    if (func_021736D8() == 0)
        return 0;
    return func_0203D3A8((struct Entry *)((unsigned int)func_020399A8()), 0x202, 0, 0);
}


void func_021737CC(int a, int b, C *c, D *d)
{
    int h;

    h = func_02026478((void *)d->f4);
    if (a < d->n) {
        func_02174EAC((u8 *)d, a, (u8 *)c);
        if (a != func_02012B58((const struct BigObj *)h) && func_0203D378() == 0 && a == 0 && c->hit == 1)
            d->flag = 1;
    }
}
