/*
 * file:     unit_0207312C_p04.c
 * unit:     yes
 * function: func_02073710, func_02073760
 * address:  0x02073710
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214E464  0x0214E464  data
 *   g_0214E018  0x0214E018  data
 */
struct DList;
struct Obj_02073548;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct A_02073710 { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; };

struct E { u8 p0[0xc]; u8 f0c; u8 pad[0x24 - 0xd]; };

struct A_02073760 { u32 f0; u32 f4; u8 p8[0x3d - 8]; u8 f3d; };

extern void func_02074758(void **a0);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_02073548(void *list, struct Obj_02073548 *obj);
extern void func_02073598(struct Obj_02073548 *obj);
void func_02073710(struct A_02073710 *a);
void func_02073760(struct A_02073760 *o, u32 v);
extern struct E g_0214E464[];
extern u8 g_0214E018[];

void func_02073710(struct A_02073710 *a) {
    if (a->f8 == 0) return;
    func_02074758((void **)a->f8);
    if (a->fc != 0) { *(u32 *)(a->fc + 8) = 0; return; }
    func_020605B4((volatile struct DList *)(&g_0214E464[a->f10].f0c), a);
}

void func_02073760(struct A_02073760 *o, u32 v) {
    u32 q = o->f4;
    if (q != 0) { func_020605B4((void *)q, o); o->f4 = 0; }
    func_020605B4((volatile struct DList *)g_0214E018, o);
    o->f3d = (u8)v;
    if (q != 0) func_02073548((void *)q, (struct Obj_02073548 *)o);
    func_02073598((struct Obj_02073548 *)o);
}
