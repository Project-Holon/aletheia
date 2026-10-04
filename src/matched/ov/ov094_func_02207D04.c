/*
 * function: func_02207D04
 * address:  0x02207D04
 * packet:   pkt_ov094_02207D04
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02208D50  0x02208D50  thumb  ov094
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B898  0x0204B898  arm
 */

typedef unsigned int u32;

typedef struct E {
    int f0;
    char p4[12];
    int f10;
    int f14;
    char p18[0x58];
    u32 lo : 29;
    u32 flag : 1;
    u32 hi : 2;
    char p74[12];
} E;

typedef struct O {
    char pad[0x40];
    E e[8];
} O;

extern void func_02208D50(O *obj, int idx, int a);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int func_0204B898(int h);

void func_02207D04(O *obj, int a, int idx)
{
    obj->e[idx].flag = a;
    func_0204B3DC((struct Obj *)obj->e[idx].f0, a);
    func_02208D50(obj, idx, a);
    if (obj->e[idx].f10 != 0) {
        func_0204B3DC((struct Obj *)obj->e[idx].f10, a);
    }
    if (obj->e[idx].f14 != 0) {
        if (func_0204B898(obj->e[idx].f14) != 0) {
            func_0204B3DC((struct Obj *)obj->e[idx].f14, a);
        }
    }
}
