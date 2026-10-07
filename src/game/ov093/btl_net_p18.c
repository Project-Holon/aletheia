/*
 * file:     btl_net_p18.c
 * unit:     yes
 * function: func_021D533C, func_021D5364, func_021D539C, func_021D53B8, func_021D53C0
 * address:  0x021D533C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D4EFC 0x021D4EFC thumb ov093
 *   func_021D5150 0x021D5150 thumb ov093
 *   func_021D51CC  0x021D51CC  thumb  ov093
 *   func_020307B0   0x020307B0  arm arm9
 *   func_021D53C8   0x021D53C8  thumb ov093
 */
struct Work;
typedef unsigned char u8;

typedef unsigned int u32;

struct S { void *f00; u8 pad04[0x17]; u8 lo : 5; u8 flag : 1; };

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct UtilEntry {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 f4;
    u16 f6;
    u8 f8;
    u8 f9;
    u16 fA;
    u8 fC;
    u8 fD;
};

struct UtilWork {
    void *f0;
    u8 pad4[0x100];
    struct UtilEntry e[4];
    u8 pad13C[4];
    u8 n140;
    u8 pad141[3];
    u8 f144;
    u8 pad145[5];
    u16 f14A;
    u16 f14C;
    u16 f14E;
    u8 pad150[3];
    u8 bits153[2];
    u8 bits155[2];
    u8 f157[5];
};

extern void func_021D4EFC(struct S *, void *, u32, u32);
extern void func_021D5150(struct Work *p);
extern void func_021D51CC(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_021D53C8(unsigned char *p);
void func_021D533C(struct S *p);
void func_021D5364(struct UtilWork *p);
void func_021D539C(struct UtilWork *p);
void func_021D53B8(void *p);
void func_021D53C0(unsigned char *p);

void func_021D533C(struct S *p)
{
    if (p->flag != 0) {
        func_021D4EFC(p, p->f00, 0, 1);
        func_021D5150((struct Work *)p);
        p->flag = 0;
    }
}


void func_021D5364(struct UtilWork *p)
{
    u32 i;
    for (i = 0; i < 4; i++) func_021D51CC((u8 *)(&p->e[i]));
    p->f14A = 0;
    p->f14C = 0;
    p->f144 = 0x11;
    p->f14E = 0;
}


void func_021D539C(struct UtilWork *p)
{
    u32 i;
    for (i = 0; i < 5; i++) p->f157[i] = 0;
}


/*
 * tail-call thunk to func_020307B0
 */
void func_021D53B8(void *p)
{
    func_020307B0(p);
}


/*
 * tail-call thunk to func_021D53C8
 */
void func_021D53C0(unsigned char *p)
{
    func_021D53C8(p);
}
