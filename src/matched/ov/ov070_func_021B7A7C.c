/*
 * function: func_021B7A7C
 * address:  0x021B7A7C
 * packet:   pkt_ov070_021B7A7C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_021B7DF4  0x021B7DF4  thumb  ov070
 *   func_021B8DAC  0x021B8DAC  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021B7DD0  0x021B7DD0  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B7B08  0x021B7B08  thumb  ov070
 *   func_021B8E08  0x021B8E08  thumb  ov070
 */

typedef unsigned int u32;

typedef struct Obj Obj;

extern int func_021BADF0(int p);
typedef unsigned char  u8;
extern int func_021B7DF4(struct Obj *o);
extern int func_021B8DAC(void);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(unsigned int id);
extern void func_021B7DD0(Obj *o);
extern void func_021B6100(char *p, int k);
extern void func_021B8C1C(int p, int a, int b);
extern void func_021B7B08(struct Obj *o);
extern void func_021B8E08(int p);

void func_021B7A7C(Obj *o)
{
    int r;

    if (func_021BADF0((int)o) == 0)
        return;
    if (func_021B7DF4(o) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0(o);
        func_021B6100((char *)o, (int)((void *)func_021B7B08));
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C((int)o, 4, (int)((void *)func_021B8E08));
    }
}
