/*
 * function: func_021B7C88
 * address:  0x021B7C88
 * packet:   pkt_ov070_021B7C88
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7CD0  0x021B7CD0  thumb  ov070
 */

typedef unsigned int u32;

typedef struct Obj Obj;

extern int func_021BADF0(int p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021B80C4(struct Obj *o, int flag);
extern void func_021B6100(char *p, int k);
extern void func_021B7CD0(struct Obj *o);

void func_021B7C88(Obj *o)
{
    if (func_021BADF0((int)o) == 0)
        return;
    if (func_020362DC() & 3) {
        func_021B80C4(o, 1);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
        return;
    }
    if (func_02035C60() != 0) {
        func_021B80C4(o, 0);
        func_021B6100((char *)o, (int)((void *)func_021B7CD0));
    }
}
