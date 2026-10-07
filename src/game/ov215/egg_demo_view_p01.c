/*
 * file:     egg_demo_view_p01.c
 * unit:     yes
 * function: func_021F63CC, func_021F6474, func_021F64D0, func_021F64E4, func_021F64F0, func_021F64FC, func_021F6508, func_021F651C, func_021F657C, func_021F65B4, func_021F65B8, func_021F65C0
 * address:  0x021F63CC
 * region:   ov215
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
 *   func_021F6630 0x021F6630 thumb ov215
 *   func_020056A0 0x020056A0 thumb
 *   d_021F73E0 0x021F73E0 data a4
 *   d_021F71C4 0x021F71C4 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021F669C 0x021F669C thumb ov215
 *   func_021F6600 0x021F6600 thumb ov215
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021F661C 0x021F661C thumb
 *   func_021F66AC 0x021F66AC thumb ov215
 *   func_021F66C0 0x021F66C0 thumb ov215
 *   func_021F662C 0x021F662C thumb ov215
 *   func_021F6624 0x021F6624 thumb
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021F7178 0x021F7178 data a4
 *   d_021F71F4 0x021F71F4 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 */
#include "../../matched/include/Obj25749.h"
#include "../../matched/include/Obj25750.h"
#include "../../matched/include/Obj14709.h"

struct DispVram;
struct Node;
struct DispConfig;
struct Cfg;
struct Bank;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

struct BgTemplate { unsigned words[8]; };

struct BgConfig { unsigned layer; struct BgTemplate template; unsigned type,enable; };

extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021F6630(void **out, u16 heap);
extern void *func_020056A0(void (*)(int,char *),char *,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_021F669C(int *p);
extern void func_021F6600(char *p);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021F661C(void *);
extern void func_021F66AC(void *);
extern void func_021F66C0(void *);
extern int func_021F662C(void *);
extern void func_021F6624(void *);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
char *func_021F63CC(unsigned mode,u16 heap);
void func_021F6474(char *p);
void func_021F64D0(char *a);
void func_021F64E4(char *p);
void func_021F64F0(char *p);
int func_021F64FC(char *p);
void func_021F6508(int a, char *b);
void func_021F651C(void *out,unsigned heap);
void func_021F657C(void *p);
void func_021F65B4(void *a0);
void func_021F65B8(void *a0);
void func_021F65C0(unsigned char *p, int a, u32 b);
extern const char d_021F73E0[];
extern const unsigned d_021F71C4[];
extern const unsigned d_021F7178[];
extern const struct BgConfig d_021F71F4[];

/*
 * volatile: hardware 021F63F2,63F4,63F8,6400,6402,6406.
 */
char *func_021F63CC(unsigned mode,u16 heap)
{
    char *p;
    p=func_02030734(heap,16,0,d_021F73E0,466);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021F71C4);
    func_0204363C(mode);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021F651C(p,heap);
    func_021F65C0((unsigned char *)(p+4),(int)d_021F71C4,heap);
    func_021F6630((void **)(p+8),heap);
    ((struct Obj25749 *)p)->fC=func_020056A0(func_021F6508,p,0);
    return p;
}

void func_021F6474(char *p)
{
    func_02030EAC(((struct Obj25750 *)p)->fC);
    func_021F669C((int *)(p+8));
    func_021F6600(p+4);
    func_021F657C(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}


void func_021F64D0(char *a)
{
    func_021F661C(a + 4);
    func_021F65B4(a);
}

void func_021F64E4(char *p){func_021F66AC(p+8);}

void func_021F64F0(char *p){func_021F66C0(p+8);}

int func_021F64FC(char *p){return func_021F662C(p+4);}


void func_021F6508(int a, char *b)
{
    func_021F65B8(b);
    func_021F6624(b + 4);
}

void func_021F651C(void *out,unsigned heap)
{
    unsigned i;
    func_02082BCC(out,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021F7178);
    for(i=0;i<6;i++) {
        func_0203FCA0((u8)d_021F71F4[i].layer,&d_021F71F4[i].template,(u8)d_021F71F4[i].type);
        func_020414AC(d_021F71F4[i].layer);
        func_02040588(d_021F71F4[i].layer,d_021F71F4[i].enable);
    }
}

/*
 * evidence: the caller truncates the 020403F4 argument with lsl/lsr #24,
 * so its extern is u8 although the callee's own source uses a word.
 * lever: a named unsigned byte-address base keeps the table in r4 and
 * index in r5; the inline address swaps them, and word indexing adds lsl #2.
 */
void func_021F657C(void *p){unsigned base=(unsigned)d_021F71F4;unsigned i;for(i=0;i<6;i++)func_020403F4((unsigned char)(*(const unsigned *)(base+i*44)));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}

/*
 * extent: two-byte alignment padding follows the body.
 */
void func_021F65B4(void *a0){}

void func_021F65B8(void *a0){func_020419E4();}


void func_021F65C0(unsigned char *p, int a, u32 b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021F7188, a, b);
    ((struct Obj14709 *)p)->f0 = func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14709 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
