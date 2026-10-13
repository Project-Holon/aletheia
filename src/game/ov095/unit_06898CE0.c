/*
 * file:     unit_06898CE0.c
 * unit:     yes
 * function: func_06898CE0, func_06898CF4, func_06898D10, func_06898D54, func_06898DE0
 * address:  0x06898CE0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb
 *   g_0689E7E0     0x0689E7E0  data
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    void *p;
    u32 type : 3;
    u32 lim : 6;
    u32 rest : 23;
    u32 n;
    u32 en;
} E;

typedef struct {
    E e[14];
} Row;

extern void BTL_EVENT_RemoveFactor(void *p);
extern int BTL_EVENT_GetFactorKey(int);
u32 func_06898CE0(u32 a, u32 b);
int func_06898CF4(int a, int b);
int func_06898D10(u32 a, u32 b);
void func_06898D54(void (*cb)(u8, u32, u32), u32 arg);
int func_06898DE0(int a, u32 b);
extern Row g_0689E7E0[2];


u32 func_06898CE0(u32 a, u32 b)
{
    return g_0689E7E0[a].e[b].en;
}


/*
 * Indexed presence test: entry b of table a holds a pointer.
 */
int func_06898CF4(int a, int b)
{
    return g_0689E7E0[a].e[b].p != 0;
}


int func_06898D10(u32 a, u32 b)
{
    E *e = &g_0689E7E0[a].e[b];
    if (e->p != 0) {
        BTL_EVENT_RemoveFactor(e->p);
        e->p = 0;
        e->en = 0;
        e->type = 0;
        return 1;
    }
    return 0;
}


void func_06898D54(void (*cb)(u8, u32, u32), u32 arg)
{
    u32 j;
    u32 i;

    for (j = 0; j < 2; j++) {
        Row *row;

        i = 0;
        row = &g_0689E7E0[j];

        for (; i < 14; i++) {
            E *e = &row->e[i];

            if (e->en != 0 && e->type == 2) {
                e->n++;
                if (e->n >= e->lim) {
                    e->en = 0;
                    e->type = 0;
                    BTL_EVENT_RemoveFactor(e->p);
                    e->p = 0;
                    cb(j, i, arg);
                }
            }
        }
    }
}

int func_06898DE0(int a, u32 b)
{
    int index;
    index = BTL_EVENT_GetFactorKey(a);
    if (index < 14 && b < 2)
        return (u8)g_0689E7E0[b].e[index].en;
    return 0;
}
