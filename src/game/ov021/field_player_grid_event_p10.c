/*
 * file:     field_player_grid_event_p10.c
 * unit:     yes
 * function: func_021BFDD0, func_021BFE00
 * address:  0x021BFDD0
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
 *   func_021C0398  0x021C0398  thumb  ov021
 *   func_021C04C0  0x021C04C0  thumb  ov021
 */
struct Desc;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021C0398(u32 task, int *st, u8 *p);
int func_021C04C0(int task, int *state, int *q);
void *func_021BFDD0(int a0, void *p, int a2, int a3);
void *func_021BFE00(int a0, void *p, int a2);


void *func_021BFDD0(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, (void *)a0, func_021C0398, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[4] = a3;
    return t;
}


/*
 * Spawns a 0x7C-byte task (callback func_021C04C0).
 */
void *func_021BFE00(int a0, void *p, int a2)
{
    void *t = func_020122C0(p, (void *)a0, func_021C04C0, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    return t;
}
