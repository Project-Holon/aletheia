/*
 * file:     unit_021C941C.c
 * unit:     yes
 * function: func_021C941C, func_021C94A0, func_021C9530, func_021C9634, func_021C96CC, func_021C9744, func_021C97E0
 * address:  0x021C941C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D3EFC 0x021D3EFC data a4
 *   d_021D4084 0x021D4084 data a4
 *   d_021CF6D4 0x021CF6D4 data a4
 *   d_021CF714 0x021CF714 data a4
 *   d_021D4098 0x021D4098 data a4
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 *   d_021CF734 0x021CF734 data a4
 *   d_021D3F00 0x021D3F00 data a4
 *   d_021D3FF8 0x021D3FF8 data a4
 *   d_021D4000 0x021D4000 data a4
 *   d_021D4090 0x021D4090 data a4
 *   d_021CF754 0x021CF754 data a4
 *   func_02092344 0x02092344 arm
 *   func_021CA188 0x021CA188 arm ov114
 *   g_021D4084 0x021D4084 data a4
 *   d_021CF770 0x021CF770 data a4
 *   d_021CF78C 0x021CF78C data a4
 *   func_02087C6C 0x02087C6C arm
 *   DWC_UpdateConnection 0x0205D074 arm
 *   DWC_ClearError 0x02059F18 arm
 */
#include "../../matched/include/G_Block.h"
#include "../../matched/arm9_sdk/libc/string.h"

typedef struct {
    unsigned words[5];
    unsigned char first, second;
    unsigned char gap[0x186];
    unsigned value;
} State;

typedef unsigned char u8;

typedef unsigned int u32;

extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
extern void *func_02092344(void *, const void *, u32);
extern void func_021CA188(void);
extern void func_02087C6C(void *);
extern int DWC_UpdateConnection(void);
extern void DWC_ClearError(void);
void func_021C941C(unsigned x);
void func_021C94A0(unsigned x, unsigned y, unsigned z);
void func_021C9530(u32 a, u32 b, u32 c, const void *p, const void *q, u32 v);
void func_021C9634(void);
void func_021C96CC(void);
void func_021C9744(unsigned char *p, unsigned x);
int func_021C97E0(unsigned type);
extern void *d_021D3EFC;
extern struct Block d_021D4098;
extern State d_021D4084;
extern unsigned d_021CF6D4[], d_021CF714[];
extern unsigned d_021CF6D4[], d_021CF734[];
extern struct Block d_021D3F00;
extern u32 d_021D3FF8[], d_021D4000[];
extern u32 d_021D4090[];
extern unsigned d_021CF6D4[], d_021CF754[];
extern unsigned g_021D4084;
extern unsigned d_021CF6D4[], d_021CF770[];
extern unsigned d_021CF6D4[], d_021CF78C[];




void func_021C941C(unsigned x)
{
    d_021D4084.first = x - 1;
    func_021C9EE4((int)d_021D3EFC, (char *)d_021CF6D4);
    if (func_021CA470(d_021CF714, d_021D4084.words[2], ((unsigned *)&d_021D4098), 1, 0) == 0) {
        d_021D4084.words[0] = 2;
        return;
    }
    d_021D4084.words[0] = 12;
    d_021D4084.words[1] = -5;
    func_021CA1B4();
}




void func_021C94A0(unsigned x, unsigned y, unsigned z)
{
    d_021D4084.value = z;
    d_021D4084.first = x - 1;
    d_021D4084.second = y - 1;
    func_021C9EE4((int)d_021D3EFC, (char *)d_021CF6D4);
    if (func_021CA470(d_021CF734, d_021D4084.words[2], ((unsigned *)&d_021D4098), 2, 0) == 0) {
        d_021D4084.words[0] = 4;
        return;
    }
    d_021D4084.words[0] = 12;
    d_021D4084.words[1] = -5;
    func_021CA1B4();
}



/*
 * final push 2026-10-05 G6L6: the pair copy is memcpy(d_021D3FF8, d_021D4090, 8) from its own pool word 0x4090 (non-const extern; a const source gave 38 B off).
 */
void func_021C9530(u32 a, u32 b, u32 c, const void *p, const void *q, u32 v)
{
    func_02092344(d_021D3F00.buf, p, 240);
    d_021D3F00.first = a - 1;
    d_021D3F00.second = b - 1;
    d_021D3F00.third = c;
    memcpy(d_021D3FF8, d_021D4090, 8);
    func_02092344(d_021D4000, q, 128);
    d_021D3F00.value = v;
    d_021D4098 = d_021D3F00;
    func_021C9EE4((int)d_021D3EFC, (char *)d_021CF6D4);
    if (func_021CA470(d_021CF754, d_021D4084.words[2], &d_021D4098, 388, 0) == 0) {
        d_021D4084.words[0] = 6;
        return;
    }
    d_021D4084.words[0] = 12;
    d_021D4084.words[1] = -5;
    func_021CA1B4();
}



void func_021C9634(void)
{
    switch (g_021D4084) {
    case 2: func_021CA188(); g_021D4084 = 3; break;
    case 4: func_021CA188(); g_021D4084 = 5; break;
    case 6: func_021CA188(); g_021D4084 = 7; break;
    case 8: func_021CA188(); g_021D4084 = 9; break;
    case 10: func_021CA188(); g_021D4084 = 11; break;
    }
}



void func_021C96CC(void)
{
    func_021C9EE4((int)d_021D3EFC, (char *)d_021CF6D4);
    if (func_021CA470(d_021CF770, d_021D4084.words[2], ((unsigned *)&d_021D4098), 0, 0) == 0) {
        d_021D4084.words[0] = 8;
        return;
    }
    d_021D4084.words[0] = 12;
    d_021D4084.words[1] = -5;
    func_021CA1B4();
}


void func_021C9744(unsigned char *p, unsigned x)
{
    func_02087C6C(p + 0x1c);
    func_02092344(((unsigned *)&d_021D4098), p, 100);
    d_021D4084.value = x;
    func_021C9EE4((int)d_021D3EFC, (char *)d_021CF6D4);
    if (func_021CA470(d_021CF78C, d_021D4084.words[2], ((unsigned *)&d_021D4098), 100, 0) == 0) {
        d_021D4084.words[0] = 10;
        return;
    }
    d_021D4084.words[0] = 12;
    d_021D4084.words[1] = -5;
    func_021CA1B4();
}


int func_021C97E0(unsigned type)
{
    int r;
    switch (type) {
    case 0: case 1: case 2: r = -7; break;
    case 3: r = -6; break;
    case 5: r = -6; break;
    case 4: r = -7; break;
    case 6: r = -6; break;
    case 7: r = -5; break;
    default: r = -6; break;
    }
    if (r != -5) {
        if (DWC_UpdateConnection() != 0) r = -6;
        DWC_ClearError();
    }
    return r;
}
