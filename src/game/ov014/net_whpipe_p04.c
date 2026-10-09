/*
 * file:     net_whpipe_p04.c
 * unit:     yes
 * function: func_02177888, func_0217796C, func_021779F4, func_02177A34, func_02177A74, func_02177A94, func_02177AA8, func_02177ACC, func_02177AEC, func_02177B0C, func_02177B2C, func_02177B58, func_02177B80, func_02177BAC, func_02177BCC, func_02177BF4, func_02177BFC
 * address:  0x02177888
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
 *   g_021797A4     0x021797A4  data  a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_021777FC  0x021777FC  thumb  ov014
 *   func_021795A4  0x021795A4  thumb  ov014
 *   func_02178E68  0x02178E68  thumb  ov014
 *   func_02177704  0x02177704  thumb  ov014
 *   func_02179570  0x02179570  thumb  ov014
 *   func_0203D720  0x0203D720  arm
 *   func_0203D754  0x0203D754  arm
 *   func_02177C1C  0x02177C1C  thumb
 *   func_02177744  0x02177744  thumb
 *   func_02179664  0x02179664  thumb
 *   func_021793F8  0x021793F8  thumb
 *   func_02178E38  0x02178E38  thumb  ov014
 *   ctrdgi_task_work 0x021797a4 data
 *   d_021797A4  0x021797A4  data  ov014  a4
 */
#include "../../matched/include/Obj02358.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct Ent {
    u8 b0[4];
    u8 mac[6];
    u8 rest[0xC0 - 10];
} Ent;

typedef struct W {
    u8 pad0[8];
    Ent ent[16];
    u8 pad1[0x38];
    u16 age[16];
    u8 pad2[0xAF - 0x20];
    u8 flag;
} W;

typedef struct Head Head;

struct Head {
    void (*fn)(Head *);
};

typedef struct {
    u8 pad0[4];
    u8 kind;
    u8 pad5[3];
    u8 rec[4];
} Sub;

typedef struct {
    u8 pad0[0x50];
    Sub sub;
} S;

int func_02178E4C(void);
void func_021777FC(void);
unsigned short func_021795A4(void);
int func_02178E68(void);
void func_02177704(void);
int func_02179570(void (*cb)(int));
void func_0203D720(u32 a);
void func_0203D754(u32 a);
int func_02177C1C(void);
void func_02177744(void);
void func_02179664(unsigned char v);
void func_021793F8(void);
extern u16 func_02178E38(void);
void func_02177888(u32 arg);
void func_0217796C(u32 arg);
int func_021779F4(void);
int func_02177A34(u16 n);
int func_02177A74(void);
int CTRDGi_IsTaskAvailable(void);
int func_02177AA8(void);
unsigned int func_02177ACC(void);
int func_02177AEC(void);
void func_02177B0C(u8 v);
u8 *func_02177B2C(int i);
u8 *func_02177B58(int i);
u8 func_02177B80(int i);
void func_02177BAC(u32 idx);
void func_02177BCC(void);
void func_02177BF4(unsigned int idx);
u8 *func_02177BFC(S *a0, u8 *out);
extern struct W *g_021797A4;
extern void *ctrdgi_task_work;
extern u8 *d_021797A4;






void func_02177888(u32 arg)
{
    int mode = func_02178E4C();
    u8 *base = ((u8 *)g_021797A4);

    if (func_02177AEC() == 0)
        func_021777FC();
    if (((struct Obj02358 *)base)->fC6A == 0xFFFF)
        ((struct Obj02358 *)base)->fC6A = arg;
    if (base[0xCEC] != 0) {
        if (func_021795A4() == 0 && func_02177ACC() == 0)
            base[0xCEB] = 1;
        if (((struct Obj02358 *)base)->fC6A > arg)
            base[0xCEB] = 1;
    }
    if (func_02178E68() == 0x19)
        func_0203D720(0);
    switch (mode) {
    case 0:
        if (base[0xCE7] == 1)
            func_02177704();
        break;
    case 1:
        if (base[0xCE7] == 1 && func_02179570(0) != 0)
            return;
        if (base[0xCE7] == 2 && func_02179570(0) != 0)
            return;
        break;
    case 8:
    case 9:
        if (base != 0) {
            if (base[0xCEB] == 0)
                func_0203D754(func_02178E68());
            base[0xCEB] = 1;
        }
        break;
    }
}






void func_0217796C(u32 arg)
{
    Head *p = (Head *)*(u32 *)0x021797A4;
    if (p != 0 && p->fn != 0)
        p->fn(p);
    if (*(u32 *)0x021797A4 != 0)
        func_02177888(arg);
    if (*(u32 *)0x021797A4 != 0) {
        if (func_02177C1C() != 0)
            func_02177744();
    }
    if (*(u32 *)0x021797A4 != 0) {
        if (*(u16 *)((u8 *)*(u32 *)0x021797A4 + 0xC6C) != 0) {
            func_02179664(1);
            ((u8 *)*(u32 *)0x021797A4)[0xCF3] = 1;
            if (((u8 *)*(u32 *)0x021797A4)[0xCF4] == 0)
                *(u16 *)((u8 *)*(u32 *)0x021797A4 + 0xC6C) -= 1;
        } else {
            func_02179664(0);
            ((u8 *)*(u32 *)0x021797A4)[0xCF3] = 0;
        }
    }
    func_021793F8();
}






int func_021779F4(void)
{
    if (((u8 *)g_021797A4) == 0)
        return 0;
    if (func_021795A4() == 0 && func_02177ACC() == 0)
        return 0;
    if (func_02178E4C() == 4 || func_02178E4C() == 5)
        return 1;
    return 0;
}






int func_02177A34(u16 n)
{
    if (((u8 *)g_021797A4) == 0)
        return 0;
    if (func_02178E4C() != 4 && func_02178E4C() != 5)
        return 0;
    if (func_02178E38() & (1 << n))
        return 1;
    return 0;
}





/*
 * evidence: original truncates the index to u16 before calling A34; extern follows caller width.
 * extent: trailing two zero bytes are alignment padding.
 */
int func_02177A74(void) { int count = 0; int i = 0; for (; i < 8; i++) { if (func_02177A34(i) != 0) count++; } return count; }






int CTRDGi_IsTaskAvailable(void)
{
    return ctrdgi_task_work != 0;
}





int func_02177AA8(void) { if (g_021797A4 != 0) { if (func_02178E4C() == 1) return 1; return 0; } return 1; }




unsigned int func_02177ACC(void) { if (g_021797A4 != 0) return func_02178E38() & 0xFFFE; return 0; }





int func_02177AEC(void)
{
    u8 *w = ((u8 *)g_021797A4);

    if (w != 0 && w[0xCEB] != 0)
        return 1;
    return 0;
}


void func_02177B0C(u8 v)
{
    u8 *w = ((u8 *)g_021797A4);
    if (w != 0) {
        w[0xCEC] = v;
        *(u16 *)(w + 0xC6A) = 0xFFFF;
    }
}



/*
 * lever: integer address sum preserves base+0x58 and the final pointer+8;
 * plain pointer additions fold these into base+0x60 (r1 DIFF, r2 EXACT).
 */
u8 *func_02177B2C(int i) { u8 *base = ((u8 *)g_021797A4); if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return (u8 *)((unsigned int)(base + 0x58) + i * 0xC0) + 8; return 0; }



u8 *func_02177B58(int i) { u8 *base = ((u8 *)g_021797A4); if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return base + 0xC + i * 0xC0; return 0; }





/*
 * Recursive MATCH unblocker: the unlabelled ov014 leaf that the arm9
 * wih_dwc.c pollers call (sub_020107FC +001E, func_0201058C +005C).  Reads
 * the per-slot u16 flag array at g_021797A4+0xC40 (stride 2) and returns the
 * slot's u8 state at +0x5C of the 0xC0-byte record, or 0 when the global or
 * the flag is clear.  func_02178098 is byte-identical.
 */
u8 func_02177B80(int i)
{
    u8 *base = ((u8 *)g_021797A4);

    if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0)
        return *(u8 *)(base + 0x5C + i * 0xC0);
    return 0;
}




/*
 * Unlabelled leaf: clears halfword idx of the table at +0xC40 of the
 * object pointed to by the global at 0x021797A4. Blocks func_02177BF4.
 *
 * Addresses are Black-image addresses.
 */
void func_02177BAC(u32 idx)
{
    u8 *p = d_021797A4;
    u16 *h;
    if (p != 0) {
        h = (u16 *)(p + 0xc40);
        if (h[idx] != 0) {
            h[idx] = 0;
        }
    }
}



/*
 * Unlabelled overlay leaf blocking ov010 func_02157760.
 */
void func_02177BCC(void)
{
    u8 *p;
    int i;
    p = d_021797A4;
    if (p != 0) {
        for (i = 0; i < 16; i++)
            *(u16 *)(p + 0xC40 + i * 2) = 0;
    }
}




/*
 * Unlabelled tail-call thunk (ldr r3,[pc]; bx r3) to func_02177BAC.
 * Sole blocker of the func_02164E04 / func_02164D6C MATCHes (ov010).
 *
 * Addresses are Black-image addresses.
 */
void func_02177BF4(unsigned int idx)
{
    func_02177BAC(idx);
}




/*
 * Unlabelled Thumb leaf (prints as .word data in ov014.s), the sole blocker
 * of ov011 func_02173368 +004A: writes the byte at +0x54 through its second
 * argument and returns the address of +0x58.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02177BFC(S *a0, u8 *out)
{
    Sub *s = &a0->sub;

    *out = s->kind;
    return s->rec;
}
