/*
 * function: func_021B7640
 * address:  0x021B7640
 * packet:   pkt_ov070_021B7640
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021350  0x02021350  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B761C  0x021B761C  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    unsigned char pad000[0x51C];
    void *f51C;
    unsigned char pad520[0x528 - 0x520];
    unsigned int f528;
    unsigned char pad52C[0x84C - 0x52C];
    unsigned int f84C;
} Obj;

extern u8 func_02021350(u16 id);
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021BACF0(int p, int mode);
extern void func_021B6100(char *p, int k);
extern void func_021B761C(int p);

void func_021B7640(Obj *o)
{
    if (func_02021350(o->f84C) == 0xFF)
        func_02045CAC(o->f51C, 0x3C, (void *)o->f528);
    else
        func_02045CAC(o->f51C, 0x3D, (void *)o->f528);
    func_021BACF0((int)o, 1);
    func_021B6100((char *)o, (int)((void *)func_021B761C));
}
