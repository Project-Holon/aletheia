/*
 * file:     btlv_effvm_p87.c
 * unit:     yes
 * function: func_02202238, func_02202248, func_022023D0, func_0220255C
 * address:  0x02202238
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FC6C 0x0203FC6C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204B100 0x0204B100 arm
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
 *   func_0220270C 0x0220270C thumb ov094
 *   d_0220A3D4 0x0220A3D4 data ov094 a4
 *   func_02205F64 0x02205F64 thumb ov094
 *   func_02205E30 0x02205E30 thumb ov094
 *   func_02205F40 0x02205F40 thumb ov094
 *   func_02205AB8 0x02205AB8 thumb ov094
 *   func_02205D34 0x02205D34 thumb ov094
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020452E8 0x020452E8 arm
 *   func_02024DCC 0x02024DCC thumb
 *   func_022025B4 0x022025B4 thumb ov094
 *   func_02030EAC 0x02030EAC arm
 *   func_02049238 0x02049238 arm
 *   func_02204960  0x02204960  thumb  ov094
 *   d_0220A8BC  0x0220A8BC  data  a4
 */
#include "../../matched/include/Obj00083.h"
#include "../../matched/include/Obj01049.h"

#define DROP_ID(k, f) if (*(int *)(p + (k)) != -1) { f(*(int *)(p + (k))); *(int *)(p + (k)) = -1; }
#define DROP_ZERO_ID(k, f) if (*(int *)(p + (k)) != 0) { f(*(int *)(p + (k))); *(int *)(p + (k)) = 0; }
#define DROP_PTR(k, f) if (*(void **)(p + (k)) != 0) { f(*(void **)(p + (k))); *(void **)(p + (k)) = 0; }
struct BgVramReq;
struct Main;
struct Bank;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
struct Node;
struct BgTemplate;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Ent { char pad[0x20]; int f20; } Ent;

extern void *func_02030D28(void *);
extern void func_02024ABC(void *);
extern void func_0203FC6C(const struct BgVramReq *req, u32 which);
extern void *func_020490F4(u32 id, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_022033F4(struct Main *m);
extern void func_02205E80(char *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void func_02024A20(u8, u8, void *, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0203D34C(u32, u32);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_0220270C(char *s, int mode, void *arg);
extern void func_02205F64(char *);
extern void func_02205E30(char *);
extern void func_02205F40(char *);
extern void func_02205AB8(char *);
extern void func_02205D34(char *);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B1CC(int);
extern u32 func_020452E8(struct Descriptor *d);
extern int func_02024DCC(void);
extern void func_022025B4(void);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204152C(int channel, u16 val);
extern void func_02204960(struct Main *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void func_02202238(void *unused, void **p);
void func_02202248(char *p);
void func_022023D0(char *p);
void func_0220255C(void *p);
extern char d_0220A3D4[];
extern const Ent d_0220A8BC[];


void func_02202238(void *unused, void **p)
{
    func_02024ABC(func_02030D28(*p));
}

void func_02202248(char *p)
{
    func_0203FC6C((const struct BgVramReq *)d_0220A3D4, 1);
    ((struct Obj00083 *)p)->f48 = func_020490F4(0xb, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f1F8 = (int)func_0204B100(4, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f118 = (int)func_0204B100(0xc, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f17C = (int)func_0204B100(6, 0, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f1C4 = (int)func_0204B100(3, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f20C = (int)func_0204B100(2, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f218 = (int)func_0204B100(1, 1, ((struct Obj00083 *)p)->f240);
    func_0220255C(p);
    func_022033F4((struct Main *)p);
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
        ((struct Obj00083 *)p)->f238 = func_02030DA8(func_021F86D4(), (void (*)(void *, void *))func_02202238, p, 0);
    func_0220270C(p, 0, 0);
}

void func_022023D0(char *p)
{
    int i;
    func_02205F64(p);
    func_02205E30(p);
    func_02205F40(p);
    func_02205AB8(p);
    func_02205D34(p);
    DROP_ID(0x104, func_0204A8D4);
    DROP_ID(0x108, func_0204ADA4);
    DROP_ID(0x10c, func_0204AFD8);
    DROP_ID(0x110, func_0204A8D4);
    DROP_ID(0x114, func_0204AFD8);
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x1e0) != -1) {
            func_0204A8D4(*(int *)(p + i * 4 + 0x1e0));
            *(int *)(p + i * 4 + 0x1e0) = -1;
        }
    }
    DROP_ID(0x1f4, func_0204AFD8);
    DROP_ID(0x1f0, func_0204ADA4);
    DROP_ZERO_ID(0x1f8, func_0204B1CC);
    DROP_ZERO_ID(0x118, func_0204B1CC);
    DROP_ZERO_ID(0x17c, func_0204B1CC);
    DROP_ZERO_ID(0x1c4, func_0204B1CC);
    DROP_ZERO_ID(0x20c, func_0204B1CC);
    DROP_ZERO_ID(0x218, func_0204B1CC);
    DROP_PTR(0x228, func_020452E8);
    DROP_PTR(0x230, func_020452E8);
    func_02024DCC();
    func_022025B4();
    DROP_PTR(0x238, func_02030EAC);
    DROP_ZERO_ID(0x48, func_02049238);
    ((struct Obj01049 *)p)->f58 = 0;
}


void func_0220255C(void *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0203FCA0((u8)(i + 4), (const struct BgTemplate *)(&d_0220A8BC[i]), (u8)d_0220A8BC[i].f20);
        func_0204152C((u8)(i + 4), (int)0x3ff);
        func_02204960(p, i + 4, 0, 0, 2, 2, 2, 2);
    }
}
