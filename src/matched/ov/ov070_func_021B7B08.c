/*
 * function: func_021B7B08
 * address:  0x021B7B08
 * packet:   pkt_ov070_021B7B08
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB0F8  0x021BB0F8  thumb  ov070
 *   func_021B619C  0x021B619C  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BADAC  0x021BADAC  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7B80  0x021B7B80  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    void *f520;
    unsigned int f524;
    void *f528;
    unsigned char pad52C[0x544 - 0x52C];
    u16 f544;
    unsigned char pad546[0x7F4 - 0x546];
    int f7F4;
    unsigned char pad7F8[0x84C - 0x7F8];
    unsigned int f84C;
} Obj;

extern void func_021BB0F8(int p);
extern int func_021B619C(int a, int b, unsigned int id);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, unsigned int index, void *dest);
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BADAC(void *p);
extern void func_021B6100(char *p, int k);
extern void func_021B7B80(struct Obj *o);

void func_021B7B08(Obj *o)
{
    int v;

    func_021BB0F8((int)o);
    v = func_021B619C(o->f84C, o->f7F4, o->f544);
    func_02045CAC(o->f51C, 0x4F, (void *)o->f524);
    func_0201EFA4(o->f520, 0, v, 7, 0, 1);
    func_0201F250(o->f520, o->f528, (void *)o->f524);
    func_021BADAC(o);
    func_021B6100((char *)o, (int)((void *)func_021B7B80));
}
