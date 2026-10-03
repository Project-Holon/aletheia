/*
 * function: func_021EA4DC
 * address:  0x021EA4DC
 * packet:   pkt_ov170_021EA4DC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EA728 0x021EA728 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E152C 0x021E152C thumb
 */

typedef struct {
    unsigned char pad0[0x2C];
    char *work;
} Obj;

typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_021DEFEC(Obj *p, int b);
extern void func_021DF040(Obj *p);
extern void func_021EA728(void *p);
extern int func_021E8FC0(Obj *p, int (*cb)(Obj *), int n);
extern int func_021E152C(Obj *p);

#define OBJ(p) (*(void **)((p)->work + 0x70))

int func_021EA4DC(Obj *p)
{
    unsigned char v = func_020260E0(OBJ(p));
    if (v < 0x24)
        func_021DEFEC(p, v);
    else
        func_021DF040(p);
    func_021EA728(p);
    return func_021E8FC0(p, func_021E152C, 0x43);
}
