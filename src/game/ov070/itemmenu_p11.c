/*
 * file:     itemmenu_p11.c
 * unit:     yes
 * function: func_021B8E84, func_021B8EA8, func_021B8F0C, func_021B8F68, func_021B8F90, func_021B8F98, func_021B913C
 * address:  0x021B8E84
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021B809C  0x021B809C  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021BA9AC  0x021BA9AC  thumb  ov070
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 *   func_02012B70 0x02012B70 thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   func_020414EC  0x020414EC  arm
 *   d_021BBB40     0x021BBB40  data  a4
 *   d_021BBB60     0x021BBB60  data  a4
 *   d_021BBB80     0x021BBB80  data  a4
 *   d_021BBB20     0x021BBB20  data  a4
 *   d_021BBAC0     0x021BBAC0  data  a4
 *   d_021BBAE0     0x021BBAE0  data  a4
 *   d_021BBB00     0x021BBB00  data  a4
 */
#include "../../matched/include/Obj09878.h"
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj09879.h"

#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
#define REG_GX_POWCNT_DSEL_MASK 0x8000
#define REG_GX_POWCNT_DSEL_SHIFT 15
struct PalAnmSlot;
struct Actor;
struct MsgBank;
struct Obj;
struct BigObj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef enum {
    GX_DISP_SELECT_SUB_MAIN = 0,
    GX_DISP_SELECT_MAIN_SUB = 1
} GXDispSelect;

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B809C(u8 *p);
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021BACF0(int p, int mode);
extern void func_021BB580(char *p, int v);
extern void func_021BB3F4(int p, int mode);
extern void func_021B6100(char *p, int k);
extern u32 func_020362DC(void);
extern int func_02035C60();
extern void func_021B80C4(struct Obj *o, int flag);
extern void func_021B6138(char *p);
extern void func_021BA9AC(char *p);
extern void func_021B8AF4(void *p);
extern int func_02012B70(const struct BigObj *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(int bg);
extern void func_020409B4(u32 layer);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_020414EC(u32 i);
void func_021B8E84(char *p);
void func_021B8EA8(int p);
void func_021B8F0C(int p);
int func_021B8F68(char *p, int value);
void func_021B8F90(void *o);
void func_021B8F98(void);
void func_021B913C(void);
extern const BgTemplate d_021BBB40;
extern const BgTemplate d_021BBB60;
extern const BgTemplate d_021BBB80;
extern const BgTemplate d_021BBB20;
extern const BgTemplate d_021BBAC0;
extern const BgTemplate d_021BBAE0;
extern const BgTemplate d_021BBB00;

/*
 * 02021540 forwards r0 to the allocator's free; name the pointer here
 * despite its legacy ARM9 thunk definition omitting that argument.
 */
void func_021B8E84(char *p)
{
    func_020215A0(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854, 0);
    func_020215A0(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854, 2);
    func_02021540(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854);
}


void func_021B8EA8(int p)
{
    if (func_0204B98C((struct Actor *)(*(int *)&((struct Obj00002 *)p)->f72C)) == 0) {
        func_0204B878((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C), 0);
        func_021B809C((u8 *)p);
        func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 0);
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x8A, (void *)(*(int *)&((struct Obj00002 *)p)->f528));
        func_021BACF0(p, 0);
        func_021BB580((char *)p, 0);
        func_021BB3F4(p, 0);
        func_021B6100((char *)p, (int)func_021B8F0C);
    }
}


void func_021B8F0C(int p)
{
    if (func_020362DC() & 3) {
        func_021B80C4((struct Obj *)p, 1);
    } else if (func_02035C60()) {
        func_021B80C4((struct Obj *)p, 0);
    } else {
        return;
    }
    ((struct Obj00002 *)p)->f818 = 0xFFFF;
    func_021B6138((char *)p);
    func_021BA9AC((char *)p);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4(p, 1);
    func_021B8AF4((void *)p);
}

int func_021B8F68(char *p, int value)
{
    if (((struct Obj09879 *)p)->f10 == 3 || ((struct Obj09879 *)p)->f10 == 1)
        return 0;
    if (func_02012B70((const struct BigObj *)(((struct Obj09879 *)p)->f0)) == 1 && value == 4)
        return 0;
    return 1;
}


/*
 * Unlabelled tail-call stub (00 4b 18 47 + pool word) after func_021B8F68;
 * installed as a callback by func_021B7250 and at 0x021B85E0.
 */
void func_021B8F90(void *o)
{
    func_021B8AF4(o);
}


static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~REG_GX_POWCNT_DSEL_MASK) |
                          (sel << REG_GX_POWCNT_DSEL_SHIFT));
}


/*
 * BG setup: GX_SetDispSelect(0), then seven 32-byte BG templates copied
 * to the stack and handed to func_0203FCA0 for BGs 0-6, each followed by
 * its clear/enable calls.
 *
 * volatile: 0x04000304 (POWCNT1, read-modify-write at 0x021B8FA0/0x021B8FA8)
 */
void func_021B8F98(void)
{
    BgTemplate t0;
    BgTemplate t1;
    BgTemplate t2;
    BgTemplate t3;
    BgTemplate t4;
    BgTemplate t5;
    BgTemplate t6;

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    t0 = d_021BBB40;
    func_0203FCA0(0, &t0, 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 0);

    t1 = d_021BBB60;
    func_0203FCA0(1, &t1, 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 0);

    t2 = d_021BBB80;
    func_0203FCA0(2, &t2, 0);
    func_020414AC(2);
    func_020409B4(2);
    func_02040588(2, 0);

    t3 = d_021BBB20;
    func_0203FCA0(3, &t3, 0);
    func_02040C14(3, 0, 1, 0);
    func_020414AC(3);
    func_020409B4(3);
    func_02040588(3, 0);

    t4 = d_021BBAC0;
    func_0203FCA0(4, &t4, 0);
    func_02040588(4, 0);
    func_020409B4(4);

    t5 = d_021BBAE0;
    func_0203FCA0(5, &t5, 0);
    func_02040588(5, 0);

    t6 = d_021BBB00;
    func_0203FCA0(6, &t6, 0);
    func_02040588(6, 0);
    func_02040C14(6, 0, 1, 0);
    func_020414EC(6);
}

void func_021B913C(void)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
}
