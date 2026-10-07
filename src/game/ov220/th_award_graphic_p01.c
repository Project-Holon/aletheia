/*
 * file:     th_award_graphic_p01.c
 * unit:     yes
 * function: func_021BA0D8, func_021BA178, func_021BA1CC, func_021BA1E0, func_021BA1EC, func_021BA200
 * address:  0x021BA0D8
 * region:   ov220
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
 *   func_021BA2A4 0x021BA2A4 thumb ov220
 *   func_020056A0 0x020056A0 thumb
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA428 0x021BA428 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA2E4 0x021BA2E4 thumb ov220
 *   func_021BA260 0x021BA260 thumb ov220
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BA300  0x021BA300  thumb  ov220
 *   func_021BA298  0x021BA298  thumb  ov220
 *   func_021BA310 0x021BA310 thumb ov220
 *   func_021BA29C  0x021BA29C  thumb  ov220
 *   func_021BA308  0x021BA308  thumb  ov220
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BA3FC 0x021BA3FC data a4
 *   d_021BA458 0x021BA458 data a4
 */
#include "../../matched/include/Obj26061.h"
#include "../../matched/include/Obj26062.h"

struct DispVram;
struct Node;
struct DispConfig;
struct BgTemplate;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,unsigned,unsigned);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BA2A4(unsigned char *,int,int);
extern void *func_020056A0(void *,void *,int);
extern void func_02030EAC(struct Node *);
extern void func_021BA2E4(char *);
extern void func_021BA260(void *p);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BA300(void *);
extern void func_021BA298(void *);
extern u32 func_021BA310(u32*);
extern void func_021BA29C(void *);
extern void func_021BA308(void *);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void *func_021BA0D8(unsigned mode,unsigned heap);
void func_021BA178(unsigned char *p);
void func_021BA1CC(char *p);
u32 func_021BA1E0(u8*p);
void func_021BA1EC(void *unused, char *p);
void func_021BA200(void *p, unsigned heap);
extern char d_021BA4F8[];
extern const struct DispVram d_021BA428;
extern const unsigned d_021BA458[][11];
extern struct DispConfig d_021BA3FC;

void *func_021BA0D8(unsigned mode,unsigned heap)
{
    unsigned char *p;
    p=func_02030734(heap,16,0,d_021BA4F8,0x1CA);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0(&d_021BA428);
    func_0204363C(mode);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BA200(p,heap);
    func_021BA2A4(p+4,(int)&d_021BA428,heap);
    ((struct Obj26061 *)p)->fC=func_020056A0((void *)func_021BA1EC,p,0);
    return p;
}

void func_021BA178(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj26062 *)p)->fC);
    func_021BA2E4((char *)p+4);
    func_021BA260(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}


void func_021BA1CC(char *p)
{
    func_021BA300(p + 4);
    func_021BA298(p);
}

u32 func_021BA1E0(u8*p){return func_021BA310((u32*)(p+4));}


void func_021BA1EC(void *unused, char *p)
{
    func_021BA29C(p);
    func_021BA308(p + 4);
}

void func_021BA200(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(&d_021BA3FC);
    for (i = 0; i < 3; i++) {
        row = d_021BA458[i];
        layer = row[0];
        func_0203FCA0((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        func_020414AC(layer);
        func_02040588(layer, row[10]);
    }
}
