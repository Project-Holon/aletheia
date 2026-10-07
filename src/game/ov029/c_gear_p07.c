/*
 * file:     c_gear_p07.c
 * unit:     yes
 * function: func_021F26E0, func_021F279C
 * address:  0x021F26E0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_021585E0  0x021585E0  thumb
 *   func_02158614  0x02158614  thumb
 *   func_021F2E5C  0x021F2E5C  thumb  ov029
 *   func_02035010  0x02035010  arm
 *   func_02035040  0x02035040  arm
 *   func_0203D8AC  0x0203D8AC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_02049238  0x02049238  arm
 *   func_021F1F24  0x021F1F24  thumb  ov029
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734 0x02030734 arm
 *   func_021F251C 0x021F251C thumb ov029
 *   d_021F3554 0x021F3554 data a4
 */
struct BigObj;
struct Ctx;
struct Node;
struct PalAnmSlot;
struct SoundSys;
typedef unsigned int   u32;

typedef unsigned char u8;

extern u32 func_02012138(const struct Ctx *p);
extern int func_021585E0(int r);
extern void func_02158614(int a);
extern void func_021F2E5C(char *a);
extern void func_02035010(u32 a, u32 b);
extern void func_02035040(u32 a, u32 b);
extern void func_0203D8AC(void);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030DA4(int a);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern void func_02049238(int a);
extern void func_021F1F24(char *p);
extern void func_02082BCC(char *p, int a, int b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, unsigned short tag);
extern void func_021F251C(u8 *, int, int, int, int);
void func_021F26E0(char *p);
void *func_021F279C(int a, int b, int c, int d);
extern int d_021F3554;


void func_021F26E0(char *p)
{
    int r = func_02012138((const struct Ctx *)(*(int *)(p + 0x1c)));

    if (r != 0) {
        if (func_021585E0(r) == 2)
            func_02158614(r);
    }
    func_021F2E5C(p + 0x21c);
    func_02035010(0, 0);
    func_02035040(0, 0);
    func_0203D8AC();
    func_0203D34C(0, *(unsigned short *)(p + 0xc));
    func_020215A0((struct PalAnmSlot *)(*(int *)(p + 0x210)), 3);
    func_020215A0((struct PalAnmSlot *)(*(int *)(p + 0x210)), 1);
    func_02021540((void *)(*(int *)(p + 0x210)));
    func_02030DA4(*(int *)(p + 0x204));
    func_020307B0((void *)(*(int *)(p + 0x20c)));
    func_02030EAC((struct Node *)(*(int *)(p + 0x208)));
    if (*(int *)(p + 0x218) != 5) {
        func_02028A70((struct SoundSys *)func_02012A30(func_020120F4((const struct Ctx *)(*(int *)(p + 0x1c)))));
    }
    func_02049238(*(int *)(p + 0x24));
    func_021F1F24(p);
    *(volatile unsigned short *)0x04001050 = 0;
    func_02082BCC(p, 0, 0x468);
}

void *func_021F279C(int a, int b, int c, int d)
{
    u8 *p;
    p = func_02030734(0x70, 0x468, 1, (const char *)&d_021F3554, 0x1147);
    func_021F251C(p, a, b, c, d);
    return p;
}
