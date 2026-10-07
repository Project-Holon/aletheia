/*
 * file:     zukan_detail_graphic_p01.c
 * unit:     yes
 * function: func_021BCE10, func_021BCEC0, func_021BCF18, func_021BCF2C, func_021BCF3C, func_021BCF4C, func_021BCF58, func_021BCF6C, func_021BCF84, func_021BCF98, func_021BCFF8, func_021BD030, func_021BD034
 * address:  0x021BCE10
 * region:   ov208
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
 *   func_021BD03C 0x021BD03C thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   d_021C8DC0 0x021C8DC0 data a1
 *   d_021C8184 0x021C8184 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BD07C 0x021BD07C thumb ov208
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BD098 0x021BD098  thumb  ov208
 *   func_021BD12C 0x021BD12C  thumb  ov208
 *   func_021BD140 0x021BD140  thumb  ov208
 *   func_021BD0A8 0x021BD0A8 thumb
 *   func_021BD0AC 0x021BD0AC  thumb  ov208
 *   func_021BD11C 0x021BD11C  thumb  ov208
 *   func_021BD0A0 0x021BD0A0  thumb  ov208
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021C8138 0x021C8138 data a4
 *   d_021C81B4 0x021C81B4 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4  arm
 */
#include "../../matched/include/Obj04613.h"
#include "../../matched/include/Obj18203.h"
#include "../../matched/include/Obj18204.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {u32 bg,tmpl[8],type,on;} BgEntry;

struct Ov208Bg { u32 bg; u8 pad[0x28]; };

extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BD03C(unsigned char *,int,int);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_021BD07C(char *p);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BD098(char *);
extern void func_021BD12C(int *p);
extern void func_021BD140(char *);
extern int func_021BD0A8(int *p);
extern void func_021BD0AC(char *, int);
extern void func_021BD11C(int *p);
extern void func_021BD0A0(char *);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
char *func_021BCE10(unsigned display,unsigned heap,int threeD);
void func_021BCEC0(char *p);
void func_021BCF18(char *p);
void func_021BCF2C(char *p);
void func_021BCF3C(char *p);
int func_021BCF4C(char *p);
void func_021BCF58(char *p, int x);
void func_021BCF6C(char *p);
void func_021BCF84(int unused, char *p);
void func_021BCF98(void *p,u32 heap);
void func_021BCFF8(void *p);
void func_021BD030(char *a0);
void func_021BD034(char *a0);
extern const char d_021C8DC0[];
extern const unsigned d_021C8184[];
extern const u32 d_021C8138[];
extern const BgEntry d_021C81B4[];

/*
 * volatile: hardware 04000050/04001050 writes at 021BCE36/021BCE3C and 04000000/04001000 read-write at 021BCE40-021BCE4E.
 */
char *func_021BCE10(unsigned display,unsigned heap,int threeD)
{
    char *p=func_02030734(heap,20,0,d_021C8DC0,0x1db);
    func_02082BCC(p,0,20);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021C8184);
    func_0204363C(display);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    ((struct Obj04613 *)p)->f10=0;
    func_021BCF98(p,heap);
    func_021BD03C((unsigned char *)p+4,(int)d_021C8184,heap);
    if(threeD)func_021BCF58(p,heap);
    ((struct Obj04613 *)p)->fC=func_020056A0((unsigned)func_021BCF84,(unsigned)p,0);
    return p;
}

/*
 * volatile: hardware writes 021BCEE4/021BCEEA and read-modify-write 021BCEEC/021BCEF4, 021BCEF6/021BCEFA.
 */
void func_021BCEC0(char *p)
{
    func_02030EAC(((struct Obj04613 *)p)->fC);
    func_021BCF6C(p);
    func_021BD07C(p+4);
    func_021BCFF8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,0x14);
    func_020307B0((void *)((unsigned)p));
}


void func_021BCF18(char *p)
{
    func_021BD098(p + 4);
    func_021BD030(p);
}


/*
 * Calls func_021BD12C on +8 when the word at +0x10 is set.
 */
void func_021BCF2C(char *p)
{
    if (((struct Obj18203 *)p)->f10 != 0)
        func_021BD12C((int *)(p + 8));
}


/*
 * Calls func_021BD140 on +8 when the word at +0x10 is set.
 */
void func_021BCF3C(char *p)
{
    if (((struct Obj18204 *)p)->f10 != 0)
        func_021BD140(p + 8);
}

int func_021BCF4C(char *p)
{
    return func_021BD0A8((int *)(p + 4));
}


/*
 * Lazy setup: sets the flag at +0x10 and initialises the sub-object at +8.
 * The second argument is only forwarded to func_021BD0AC, which is why the
 * compiler parks the flag temp in r2 rather than r1.
 */
void func_021BCF58(char *p, int x)
{
    if (((struct Obj04613 *)p)->f10 == 0) {
        ((struct Obj04613 *)p)->f10 = 1;
        func_021BD0AC(p + 8, x);
    }
}


void func_021BCF6C(char *p)
{
    if (((struct Obj04613 *)p)->f10 != 0) {
        func_021BD11C((int *)(p + 8));
        ((struct Obj04613 *)p)->f10 = 0;
    }
}


void func_021BCF84(int unused, char *p)
{
    func_021BD034(p);
    func_021BD0A0(p + 4);
}

void func_021BCF98(void *p,u32 heap)
{
    u32 i=0;
    const BgEntry *row;
    u32 bg;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021C8138);
    for(;i<8;i++) {
        row=&d_021C81B4[i];
        bg=row->bg;
        func_0203FCA0((u8)bg,(const struct BgTemplate *)row->tmpl,(u8)row->type);
        func_020414AC(bg);
        func_02040588(bg,row->on);
    }
}

void func_021BCFF8(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4((u8)d_021C81B4[i].bg);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}

/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void func_021BD030(char *a0)
{
}


/*
 * Tail call to the ARM9 function at 0x020419E4: loads the pointer from the pool and branches through it.
 */
void func_021BD034(char *a0)
{
    func_020419E4();
}
