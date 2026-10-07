/*
 * file:     wih_p04.c
 * unit:     yes
 * function: func_02177F48, func_02177FC4, func_02177FF0, func_02178034, func_0217807C, func_02178098, func_021780C4, func_021780E4, func_021780FC, func_02178118, func_02178138
 * address:  0x02177F48
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   d_02179678     0x02179678  data  a1
 *   func_02177AA8  0x02177AA8  thumb  ov014
 *   func_020056EC  0x020056EC  thumb
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_02179288  0x02179288  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_02177EFC  0x02177EFC  thumb
 *   func_021788FC 0x021788FC thumb ov014
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_021785B4  0x021785B4  thumb
 *   func_021773E0  0x021773E0  thumb  ov014
 *   func_0217758C  0x0217758C  thumb  ov014
 *   func_02177560  0x02177560  thumb  ov014
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 *   d_021797A4 0x021797A4 data ov014 a4
 *   func_02178714 0x02178714 thumb ov014
 *   g_021797A8 0x021797A8 data ov014 a4
 */
#include "../../matched/include/Obj04956.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

int func_02177AA8(void);
u32 func_020056EC(u32 n);
void func_0217778C(void);
int func_02179288(int mode, u16 a, int b, u16 c);
void func_0217727C(u32 *p, u32 v);
void func_02177EFC(u8 *a);
extern int func_021788FC(void);
int func_02178E4C(void);
int func_021785B4(u32 a, u16 *b, u32 c);
int func_021773E0(u8 *p);
void func_0217758C(u8 *p);
void func_02177560(void);
void func_0217933C(void *fn);
int func_021775AC(int a, int b, int c);
extern void func_02178714(u16, void *);
void func_02177F48(u8 *a);
void func_02177FC4(unsigned char *p);
void func_02177FF0(u8 *a);
int func_02178034(void);
void func_0217807C(void);
u8 func_02178098(u8 i);
void func_021780C4(u32 i);
void func_021780E4(int a);
void func_021780FC(u8 value);
void func_02178118(u32 callback, u32 value);
void func_02178138(int state);
extern u8 *g_021797A4;
extern u8 d_02179678[3];
extern u8 *d_021797A4;
extern u8 *g_021797A8;


void func_02177F48(u8 *a)
{
    u8 tab[3];
    if (func_02177AA8() != 0) {
        tab[0] = d_02179678[0];
        tab[1] = d_02179678[1];
        tab[2] = d_02179678[2];
        a[0xCF1] = func_020056EC(3);
        if (a[0xCF1] >= 3)
            a[0xCF1] = 0;
        func_0217778C();
        if (func_02179288(0, ((struct Obj04956 *)a)->fC68, tab[a[0xCF1]], 1) != 0) {
            a[0xCF2] = func_020056EC(0x98) + 0x3C;
            func_0217727C((u32 *)g_021797A4, (u32)func_02177EFC);
        }
    }
}

void func_02177FC4(unsigned char *p) { p[0xCF2]--; if (p[0xCF2] == 0) { func_021788FC(); func_0217727C((unsigned int *)g_021797A4, (unsigned int)func_02177F48); } }


void func_02177FF0(u8 *a)
{
    if (func_02178E4C() == 1) {
        if (func_021785B4((u32)func_021773E0, 0, 0) != 0) {
            a[0xCF2] = func_020056EC(0x28) + 0x3C;
            func_0217727C((u32 *)g_021797A4, (u32)func_02177FC4);
        }
    }
}


int func_02178034(void)
{
    u8 *p = g_021797A4;
    if (p == 0)
        return 0;
    func_021780E4(0);
    func_0217758C(p);
    func_02177560();
    func_0217933C(func_021775AC);
    p[0xCE8] = 1;
    func_0217727C((u32 *)g_021797A4, (u32)func_02177FF0);
    return 1;
}

void func_0217807C(void)
{
    if (g_021797A4[0xcec])
        g_021797A4[0xceb] = 1;
}


/*
 * Recursive MATCH unblocker: the unlabelled ov014 leaf that func_0201058C
 * calls at +005C.  Byte-identical to func_02177B80: read g_021797A4, test the
 * per-slot u16 flag at +0xC40 (stride 2), then return the slot's u8 state at
 * +0x5C of the 0xC0-byte record, or 0.
 */
u8 func_02178098(u8 i)
{
    u8 *base = g_021797A4;

    if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0)
        return *(u8 *)(base + 0x5C + i * 0xC0);
    return 0;
}

/*
 * Unlabelled overlay leaf blocking ov010 func_02157760.
 */
void func_021780C4(u32 i)
{
    u8 *p;
    u32 off;
    off = i * 0xC0;
    p = d_021797A4;
    func_02178714(*(u16 *)(p + off + 0x3E), p + 0xC + off);
}

void func_021780E4(int a)
{
    if (g_021797A4)
        *(u16 *)(g_021797A4 + 0xc6c) = 20;
}

void func_021780FC(u8 value)
{
    if (g_021797A4) {
        g_021797A4[0xcea] = value;
        func_0217778C();
    }
}

/*
 * blocker leaf for ov122 func_021D4B74; two stores to the game-global object.
 */
void func_02178118(u32 callback, u32 value)
{
    if (g_021797A4) {
        *(u32 *)(g_021797A4 + 0xc38) = callback;
        *(u32 *)(g_021797A4 + 0xc3c) = value;
    }
}

void func_02178138(int state)
{
    *(int *)(g_021797A8 + 0x1e70) = state;
}
