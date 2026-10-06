/*
 * function: func_02073760
 * address:  0x02073760
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E018  0x0214E018  data
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct A { u32 f0; u32 f4; u8 p8[0x3d - 8]; u8 f3d; };
struct DList;
struct Obj_02073548;
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_02073548(void *list, struct Obj_02073548 *obj);
extern void func_02073598(struct Obj_02073548 *obj);
extern u8 g_0214E018[];
void func_02073760(struct A *o, u32 v) {
    u32 q = o->f4;
    if (q != 0) { func_020605B4((void *)q, o); o->f4 = 0; }
    func_020605B4((volatile struct DList *)g_0214E018, o);
    o->f3d = (u8)v;
    if (q != 0) func_02073548((void *)q, (struct Obj_02073548 *)o);
    func_02073598((struct Obj_02073548 *)o);
}
