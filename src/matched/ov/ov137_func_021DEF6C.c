/*
 * function: func_021DEF6C
 * address: 0x021DEF6C
 * packet: pkt_ov137_021DEF6C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DEFB2.
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_0200ED48 0x0200ED48 thumb
 */
typedef unsigned char u8;
typedef struct { u8 pad[0x90]; void *slots[5]; } Obj;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct L0200ED54;
struct Sub0200852CObj;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *);
extern u16 func_02039338(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
void func_021DEF6C(Obj *obj)
{
    u8 *p = (u8 *)obj;
    void *q;
    int i;
    q = func_0200ED48(func_02012EBC(*(void **)(*(u8 **)(*(u8 **)(p + 0xd8) + 0x14) + 4)));
    for (i = 0; i < 5; i++) {
        if (obj->slots[i] && i != func_02039338())
            func_0200ED54(q, func_02008530(obj->slots[i]));
    }
}
