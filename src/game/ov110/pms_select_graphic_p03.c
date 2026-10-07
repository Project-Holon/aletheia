/*
 * file:     pms_select_graphic_p03.c
 * unit:     yes
 * function: func_021C15B4, func_021C1610, func_021C16B0, func_021C1704, func_021C1718, func_021C1724, func_021C1738
 * address:  0x021C15B4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02024120 0x02024120 thumb
 *   func_02024134 0x02024134 thumb
 *   func_02024918 0x02024918 thumb
 *   func_020240FC 0x020240FC thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021C17DC 0x021C17DC thumb ov110
 *   func_020056A0 0x020056A0 thumb
 *   d_021C3C98 0x021C3C98 data a1
 *   d_021C3A44 0x021C3A44 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021C181C 0x021C181C thumb ov110
 *   func_021C1798 0x021C1798 thumb ov110
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021C1838 0x021C1838 thumb ov110
 *   func_021C17D0 0x021C17D0 thumb ov110
 *   func_021C1848  0x021C1848  thumb  ov110
 *   func_021C17D4 0x021C17D4 thumb ov110
 *   func_021C1840 0x021C1840 thumb ov110
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021C3A18 0x021C3A18 data a4
 *   d_021C3A74 0x021C3A74 data a4
 */
#include "../../matched/include/Obj22414.h"
#include "../../matched/include/Obj22415.h"

struct Obj02024838;
struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
typedef unsigned char u8;

typedef signed int     s32_021C15B4;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

typedef signed char s8;

typedef int s32_021C1718;

extern int func_02024120(u8 *p);
extern void func_02024134(char *a, void *b);
extern void func_02024918(const struct Obj02024838 *p, s32_021C15B4 idx, void *dest);
extern void func_020240FC(void *);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,unsigned);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021C17DC(void **p, unsigned arg, unsigned heap);
extern void *func_020056A0(void *,void *,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_021C181C(void **p);
extern void func_021C1798(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021C1838(void *);
extern void func_021C17D0(void *);
extern u32 func_021C1848(u32 *p);
extern void func_021C17D4(void *);
extern void func_021C1840(void *);
extern void func_0203F8F4(u16);
extern void func_02045088(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
int func_021C15B4(int *state, u8 *p);
void *func_021C1610(unsigned arg, u16 heap);
void func_021C16B0(u8 *p);
void func_021C1704(u8 *p);
u32 func_021C1718(u8 *p);
void func_021C1724(int a,u8 *p);
void func_021C1738(void *p, u16 heap);
extern const char d_021C3C98[];
extern const unsigned d_021C3A44[];
extern const unsigned d_021C3A18[];
extern const unsigned d_021C3A74[][11];

int func_021C15B4(int *state, u8 *p) {
    unsigned pair[2];
    switch (*state) {
    case 0:
        if (func_02024120(*(void **)(p+0x90))) {
            func_02024134(*(void **)(p+0x90),pair);
            func_02024918(*(void **)(p+0x20),p[0x95],pair);
        }
        func_020240FC(*(void **)(p+0x90));
        ++*state;
        break;
    case 1: return 1;
    }
    return 0;
}

void *func_021C1610(unsigned arg, u16 heap) {
    u8 *p;
    p=func_02030734(heap,16,0,d_021C3C98,0x151);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021C3A44);
    func_0204363C(arg);
    func_0204361C(); func_020434CC(); func_02043588();
    func_0201DD60();
    func_021C1738(p,heap);
    func_021C17DC((void **)(p+4),(unsigned)d_021C3A44,heap);
    ((struct Obj22414 *)p)->fC=func_020056A0(func_021C1724,p,0);
    return p;
}

/*
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 re-read at 021C16D6 and 021C16E0.
 */
void func_021C16B0(u8 *p) {
    func_02030EAC(((struct Obj22415 *)p)->fC);
    func_021C181C((void **)(p+4));
    func_021C1798(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}

void func_021C1704(u8 *p) { func_021C1838(p+4); func_021C17D0(p); }

/*
 * Unblocked by matching func_021C1848 in ov110 (pkt_ov110_021C1848).
 */
u32 func_021C1718(u8 *p) { return func_021C1848((u32 *)(p + 4)); }

void func_021C1724(int a,u8 *p) { func_021C17D4(p); func_021C1840(p+4); }

void func_021C1738(void *p, u16 heap) {
    unsigned i;
    const unsigned *q;
    unsigned id;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021C3A18);
    for (i=0; i<6; i++) {
        q=d_021C3A74[i];
        id=q[0];
        func_0203FCA0((u8)id,(const struct BgTemplate *)(q+1),(u8)q[9]);
        func_020414AC(id);
        func_02040588(id,q[10]);
    }
}
