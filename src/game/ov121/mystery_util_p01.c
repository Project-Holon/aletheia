/*
 * file:     mystery_util_p01.c
 * unit:     yes
 * function: func_021D9624, func_021D96C4, func_021D9718, func_021D972C, func_021D9738, func_021D9744, func_021D9750
 * address:  0x021D9624
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
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021D97C8 0x021D97C8 thumb ov121
 *   func_021D986C 0x021D986C thumb ov121
 *   func_021D97B4 0x021D97B4 thumb ov121
 *   func_020056A0 0x020056A0 thumb
 *   d_021DFB8C 0x021DFB8C data a1
 *   d_021DF604 0x021DF604 data a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D98C0 0x021D98C0 thumb ov121
 *   func_021D9828 0x021D9828 thumb ov121
 *   func_021D98E0  0x021D98E0  thumb
 *   func_021D9860  0x021D9860  thumb
 *   func_021D9974 0x021D9974 thumb ov121
 *   func_021D9994 0x021D9994 thumb ov121
 *   func_021D98F0 0x021D98F0 thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02050B80 0x02050B80 arm
 *   func_021D98F4 0x021D98F4 thumb ov121
 *   d_021DF598 0x021DF598 data a4
 */
#include "../../matched/include/Obj13944.h"
#include "../../matched/include/Obj22873.h"
#include "../../matched/include/Obj13945.h"

struct DispVram;
struct Node;
struct DispConfig;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { int a,b,c,d; } Config;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021D97C8(void *p, u32 a);
extern void func_021D986C(void **p, u32 a, u32 heap);
extern void func_021D97B4(void *,u8 *);
extern void *func_020056A0(void (*)(void *,u8 *),void *,int);
extern void func_02030EAC(struct Node *n);
extern void func_021D98C0(u8 *p);
extern void func_021D9828(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021D98E0(void *);
extern void func_021D9860(void *);
extern void func_021D9974(void **);
extern void func_021D9994(void **);
extern unsigned func_021D98F0(unsigned *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02050B80(u32 heap);
extern void func_021D98F4(u32 *p, u32 heap);
u8 *func_021D9624(int arg,u16 heap);
void func_021D96C4(u8 *p);
void func_021D9718(u8 *p);
void func_021D972C(char *p);
void func_021D9738(char *p);
unsigned func_021D9744(char *p);
void func_021D9750(u8 *p);
extern const char d_021DFB8C[];
extern const int d_021DF604[];
extern const Config d_021DF598;

/*
 * volatile: hardware reads at 021D9654 and 021D965E
 */
u8 *func_021D9624(int arg,u16 heap)
{
    u8 *p;
    p=func_02030734(heap,28,0,d_021DFB8C,448);
    func_02082BCC(p,0,28);
    ((struct Obj13944 *)p)->f18=heap;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021DF604);
    func_0204363C(arg);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021D97C8(p,heap);
    func_021D986C((void **)(p+4),(u32)d_021DF604,heap);
    ((struct Obj13944 *)p)->f14=func_020056A0(func_021D97B4,p,0);
    return p;
}

/*
 * volatile: hardware reads at 021D96EA and 021D96F4
 */
void func_021D96C4(u8 *p)
{
    func_02030EAC(((struct Obj22873 *)p)->f14);
    func_021D98C0(p+4);
    func_021D9828(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,28);
    func_020307B0(p);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D9718(u8 *p)
{
    func_021D98E0(p + 4);
    func_021D9860(p);
}

void func_021D972C(char *p) { func_021D9974((void **)(p+12)); }

void func_021D9738(char *p) { func_021D9994((void **)(p+12)); }

unsigned func_021D9744(char *p) { return func_021D98F0((unsigned *)(p+4)); }

void func_021D9750(u8 *p)
{
    Config c;
    func_02040588(0,0);
    c=d_021DF598;
    c.d=1;
    func_0203FC28((struct DispConfig *)(&c));
    func_021D98F4((u32 *)(p+12),((struct Obj13945 *)p)->f18);
    func_02050B80(((struct Obj13945 *)p)->f18);
}
