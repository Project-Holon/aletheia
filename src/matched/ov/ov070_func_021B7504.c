/*
 * function: func_021B7504
 * address:  0x021B7504
 * packet:   pkt_ov070_021B7504
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_021BA9AC  0x021BA9AC  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_020414EC  0x020414EC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B9AAC  0x021B9AAC  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 *   func_021BB1AC  0x021BB1AC  thumb  ov070
 */

typedef struct Obj {
    unsigned char pad000[0x6A8];
    void *f6A8;
    unsigned char pad6AC[0x77C - 0x6AC];
    void *f77C;
    unsigned char pad780[0x844 - 0x780];
    int f844;
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021BA9AC(char *p);
extern void func_021B6100(char *p, int k);
extern void func_020414EC(u32 i);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BB3F4(int p, int mode);
extern u8 func_020355C4(void);
extern void func_021B9AAC(char *p);
extern void func_021B80C4(Obj *o, int v);
extern void func_021B8AF4(void *p);
extern void func_021BB1AC(char *p);

void func_021B7504(Obj *o)
{
    if (func_020279E8(o->f77C) == 0)
        return;
    if (func_02027A04(o->f77C) == 0) {
        func_021BA9AC((char *)o);
        o->f844 = 6;
        func_021B6100((char *)o, 0);
    } else {
        func_021BA9AC((char *)o);
        func_020414EC(3);
        func_0204B92C(o->f6A8, 1);
        func_021BB3F4((int)o, 1);
        if (func_020355C4() == 1) {
            func_021B9AAC((char *)o);
            func_021B80C4(o, 0);
        } else {
            func_021B80C4(o, 1);
        }
        func_021B8AF4(o);
    }
    func_021BB1AC((char *)o);
}
