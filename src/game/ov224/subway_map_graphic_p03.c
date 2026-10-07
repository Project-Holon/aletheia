/*
 * file:     subway_map_graphic_p03.c
 * unit:     yes
 * function: func_021B9A58, func_021B9A6C, func_021B9ACC, func_021B9B04, func_021B9B08, func_021B9B10, func_021B9B50, func_021B9B6C, func_021B9B74, func_021B9B7C
 * address:  0x021B9A58
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   config 0x021B9C54 data
 *   table 0x021B9CD0 data ov224
 *   d_021B9CD0 0x021B9CD0 data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021B989C 0x021B989C thumb ov224
 *   vecA 0x021B9C3C data
 *   vecB 0x021B9C30 data
 *   vecC 0x021B9C48 data
 *   cfg 0x020A1EB8 data
 */
#include "../../matched/include/Obj14800.h"
#include "../../matched/include/Obj26111.h"

struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned char u8;

typedef unsigned int u32;

struct Record { u32 id; u32 bg[8]; u32 kind; u32 visible; };

typedef signed short s16;

extern void func_02082BCC(void *, u32, u32);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021B989C(void);
extern void func_02046440(u32,u32,u32,u32,unsigned short,u32,void(*)(void));
extern void *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,void *,void *,void *,u32);
void func_021B9A58(void *unused, char *p);
void func_021B9A6C(void *p, u32 heap);
void func_021B9ACC(void *p);
void func_021B9B04(void *a0);
void func_021B9B08(void *a0);
void func_021B9B10(unsigned char *p, int a, int b);
void func_021B9B50(char *p);
void func_021B9B6C(void *a0);
void func_021B9B74(void *a0);
void func_021B9B7C(void **p,u32 heap);
extern u32 config[];
extern struct Record table[];
extern const u8 d_021B9CD0[];
extern const s16 cfg[];
extern u32 vecA[],vecB[],vecC[];


/*
 * Addresses are Black-image addresses.
 */
void func_021B9A58(void *unused, char *p)
{
    func_021B9B08(p);
    func_021B9B74(p + 4);
}

void func_021B9A6C(void *p, u32 heap)
{
    u32 i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)config);
    for (; i < 2; i++) {
        struct Record *r = &table[i];
        u32 id = r->id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)r->bg, (u8)r->kind);
        func_020414AC(id);
        func_02040588(id, r->visible);
    }
}

void func_021B9ACC(void *p) {
    u32 i;
    for (i=0; i<2; i++) func_020403F4((u8)(*(const u32 *)(d_021B9CD0+i*44)));
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p,0,4);
}

void func_021B9B04(void *a0) {}

void func_021B9B08(void *a0) { func_020419E4(); }


void func_021B9B10(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021B9C64, a, b);
    ((struct Obj14800 *)p)->f0 = (int)func_0204B100(0x80, 0, b);
    func_0204B270((void *)((struct Obj14800 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_021B9B50(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26111 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}

void func_021B9B6C(void *a0) { func_0204A600(); }

void func_021B9B74(void *a0) { func_0204A648(); }

void func_021B9B7C(void **p,u32 heap)
{
    func_02046440(0,1,0,1,0,heap,func_021B989C);
    *p = func_02048A24(0,cfg[6],cfg[7],0x1555,0,0x1000,0x400000,0,
        vecA,vecB,vecC,heap);
}
