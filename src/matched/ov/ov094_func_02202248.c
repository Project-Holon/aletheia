/*
 * function: func_02202248
 * address: 0x02202248
 * packet: pkt_ov094_02202248
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FC6C 0x0203FC6C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0220255C 0x0220255C thumb ov094
 *   func_022033F4 0x022033F4 thumb ov094
 *   func_02205E80 0x02205E80 thumb ov094
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02024A20 0x02024A20 thumb
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020216D4 0x020216D4 thumb
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_02202238 0x02202238 thumb ov094
 *   func_0220270C 0x0220270C thumb ov094
 *   d_0220A3D4 0x0220A3D4 data ov094 a4
 */
#include "../include/Obj00083.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220A3D4[];
extern void func_0203FC6C(void *, int);
extern void *func_020490F4(unsigned int id, u16 heap);
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
extern void func_0220255C(void *p);
extern void func_022033F4(char *);
extern void func_02205E80(char *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void func_02024A20(u8, u8, void *, u16);
extern void func_02040588(u32 which, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0203D34C(u32, u32);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_02202238(void *, void *);
extern void func_0220270C(char *s, int mode, void *arg);
void func_02202248(char *p)
{
    func_0203FC6C(d_0220A3D4, 1);
    ((struct Obj00083 *)p)->f48 = func_020490F4(0xb, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f1F8 = (int)func_0204B100(4, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f118 = (int)func_0204B100(0xc, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f17C = (int)func_0204B100(6, 0, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f1C4 = (int)func_0204B100(3, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f20C = (int)func_0204B100(2, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f218 = (int)func_0204B100(1, 1, ((struct Obj00083 *)p)->f240);
    func_0220255C(p);
    func_022033F4(p);
    func_02205E80(p);
    ((struct Obj00083 *)p)->f228 = (void *)func_020450F0(6, 0, 4, 32, 12, 13, 1);
    ((struct Obj00083 *)p)->f22C = func_02045770(((struct Obj00083 *)p)->f228);
    ((struct Obj00083 *)p)->f230 = (void *)func_020450F0(6, 3, 22, 3, 2, 13, 1);
    ((struct Obj00083 *)p)->f234 = func_02045770(((struct Obj00083 *)p)->f230);
    func_02043B5C(((struct Obj00083 *)p)->f22C, 0);
    func_02043B5C(((struct Obj00083 *)p)->f234, 0);
    func_02045334(((struct Obj00083 *)p)->f228);
    func_02045334(((struct Obj00083 *)p)->f230);
    func_02045374(((struct Obj00083 *)p)->f228);
    func_02045374(((struct Obj00083 *)p)->f230);
    func_020409B4(6);
    func_02024A20(6, 15, ((struct Obj00083 *)p)->f4C, ((struct Obj00083 *)p)->f240);
    func_02040588(6, 1);
    func_02043598(16, 1);
    func_0203D34C(0, ((struct Obj00083 *)p)->f240);
    func_020216D4(((struct Obj00083 *)p)->f64, 3, 0xe0, 0x20);
    ((struct Obj00083 *)p)->f68 |= 0x2000;
    if (((struct Obj00083 *)p)->f23C == 1)
        ((struct Obj00083 *)p)->f238 = func_02030DA8(func_021F86D4(), func_02202238, p, 0);
    func_0220270C(p, 0, 0);
}
