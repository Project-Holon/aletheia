/*
 * function: func_021B7CD0
 * address:  0x021B7CD0
 * packet:   pkt_ov070_021B7CD0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020414EC  0x020414EC  arm
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_021BB0BC  0x021BB0BC  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 */

typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x818 - 0x6AC];
    int f818;
    unsigned char pad81C[0x83E - 0x81C];
    u16 f83E;
} Obj;

typedef unsigned int   u32;
extern void func_020414EC(u32 i);
extern void func_021B6138(char *p);
extern void func_021BA6A4(char *p);
extern void func_021BB0BC(char *p);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BB3F4(int p, int mode);
extern void func_021B8AF4(void *p);

void func_021B7CD0(Obj *o)
{
    func_020414EC(3);
    o->f818 = 0xFFFF;
    func_021B6138((char *)o);
    o->f83E = 1;
    func_021BA6A4((char *)o);
    func_021BB0BC((char *)o);
    func_0204B92C(o->f6A8, 1);
    func_021BB3F4((int)o, 1);
    func_021B8AF4(o);
}
