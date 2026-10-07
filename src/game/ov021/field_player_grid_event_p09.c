/*
 * file:     field_player_grid_event_p09.c
 * unit:     yes
 * function: func_021BFD34, func_021BFD70, func_021BFDA0
 * address:  0x021BFD34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BFE2C  0x021BFE2C  thumb  ov021
 *   func_021C00C8  0x021C00C8  thumb  ov021
 *   func_021C021C  0x021C021C  thumb  ov021
 */
struct Desc;
struct Obj;
typedef struct { int x, y, z; } V3;

typedef unsigned int   u32;

typedef unsigned char  u8;

struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021BFE2C(int task, int *state, int *q);
int func_021C00C8(void *task, int *state, void **q);
int func_021C021C(u32 a, int *st, u8 *p);
void *func_021BFD34(int a0, void *p, int a2, const V3 *v);
void *func_021BFD70(int a0, void *p, int a2, int a3);
void *func_021BFDA0(int a0, void *p, int a2, int a3);


static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}


/*
 * Spawns a 0x7C-byte task and seeds it with a position triple.
 */
void *func_021BFD34(int a0, void *p, int a2, const V3 *v)
{
    void *t = func_020122C0(p, (void *)a0, func_021BFE2C, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[8] = 0;
    V3_Set((V3 *)&w[5], v->x, v->y, v->z);
    return t;
}


/*
 * Spawns a 0x7C-byte task (callback func_021C00C8).
 */
void *func_021BFD70(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, (void *)a0, func_021C00C8, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[29] = 0;
    w[30] = a3;
    return t;
}


/*
 * Spawns a 0x7C-byte task (callback func_021C021C).
 */
void *func_021BFDA0(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, (void *)a0, func_021C021C, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[29] = 0;
    w[30] = a3;
    return t;
}
