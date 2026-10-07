/*
 * file:     mystery_util_p02.c
 * unit:     yes
 * function: func_021D9790, func_021D97B4, func_021D97C8, func_021D9828, func_021D9860, func_021D9864, func_021D986C, func_021D98C0
 * address:  0x021D9790
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02050ED4 0x02050ED4 arm
 *   func_021D9960 0x021D9960 thumb ov121
 *   func_0203FC28 0x0203FC28 arm
 *   d_021DF598 0x021DF598 data a4
 *   func_021D98E8  0x021D98E8  thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   d_021DF634 0x021DF634 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021DF5A8 0x021DF5A8 data a4
 *   d_021DF5C4 0x021DF5C4 data a4
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 */
#include "../../matched/include/Obj13946.h"

struct DispConfig;
struct BgTemplate;
struct Cfg;
struct Bank;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct { u32 id; u32 config[8]; u32 a; u32 b; } Entry;

extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02050ED4(void);
extern void func_021D9960(char *p);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_021D98E8(void *);
extern void func_02082BCC(void *, int, u32);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204B084(void *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021D9790(char *p);
void func_021D97B4(void *a, u8 *q);
void func_021D97C8(void *p, u32 a);
void func_021D9828(void *p);
void func_021D9860(void *a0);
void func_021D9864(void *a0);
void func_021D986C(void **p, u32 a, u32 heap);
void func_021D98C0(u8 *p);
extern const unsigned d_021DF598[];
extern const Entry d_021DF634[];
extern const u32 d_021DF5A8[];
extern const u32 d_021DF5C4[];

void func_021D9790(char *p) { func_02040588(0,0);func_02050ED4();func_021D9960(p+12);func_0203FC28((struct DispConfig *)d_021DF598); }


void func_021D97B4(void *a, u8 *q)
{
    func_021D9864(q);
    func_021D98E8(q + 4);
}

void func_021D97C8(void *p, u32 a)
{
    u32 i;
    const Entry *e;
    u32 id;
    i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(a);
    func_02045088(a);
    func_0203FC28((struct DispConfig *)d_021DF598);
    do {
        e = &d_021DF634[i];
        id = e->id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)e->config, (u8)e->a);
        func_020414AC((u8)id);
        func_02040588((u8)id, (u8)e->b);
        ++i;
    } while (i < 7);
}

/*
 * note: u8 extern parameter reproduces original truncation before BLX.
 */
void func_021D9828(void *p) {
    u32 i=0;
    do { func_020403F4((u8)d_021DF634[i].id); ++i; } while(i<7);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p,0,4);
}

/*
 * note: two trailing zero alignment bytes.
 */
void func_021D9860(void *a0) {}

void func_021D9864(void *a0) { func_020419E4(); }

void func_021D986C(void **p, u32 a, u32 heap)
{
    void *q;
    func_02082BCC(p, 0, 8);
    func_0204A48C((const struct Cfg *)d_021DF5A8, a, heap);
    p[0] = func_0204B100(128, 0, heap);
    q = func_0204B034((unsigned char *)d_021DF5C4, 2, heap);
    p[1] = q;
    func_0204B258(p[0], q);
    func_020434DC(16, 1);
    func_02043598(16, 1);
}

void func_021D98C0(u8 *p) {
    func_0204B084(((struct Obj13946 *)p)->f4);
    func_0204B1CC(((struct Obj13946 *)p)->f0);
    func_0204A5AC();
    func_02082BCC(p,0,8);
}
