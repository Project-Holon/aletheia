/*
 * function: func_021B7804
 * address:  0x021B7804
 * packet:   pkt_ov070_021B7804
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7D9C  0x021B7D9C  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_021B6204  0x021B6204  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7868  0x021B7868  thumb  ov070
 */

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x7F4 - 0x52C];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

typedef unsigned char  u8;
extern void func_021B7D9C(u8 *p, int v);
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B6204(u8 *p, int a, unsigned int b, int c, int d);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BADAC(void *p);
extern void func_021B6100(char *p, int k);
extern void func_021B7868(struct Obj *o);

void func_021B7804(Obj *o)
{
    o->f7F4 = 1;
    func_021B7D9C((u8 *)o, 1);
    func_02045CAC(o->f51C, 0x35, (void *)o->f524);
    func_021B6204((u8 *)o, 0, o->f84C, 1, 0);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7868));
}
