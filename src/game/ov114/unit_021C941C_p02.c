/*
 * file:     unit_021C941C_p02.c
 * unit:     yes
 * function: func_021C9744, func_021C97E0
 * address:  0x021C9744
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
 *   d_021CF78C 0x021CF78C data a4
 *   d_021D4098 0x021D4098 data a4
 *   func_02087C6C 0x02087C6C arm
 *   func_02092344 0x02092344 arm
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 *   DWC_UpdateConnection 0x0205D074 arm
 *   DWC_ClearError 0x02059F18 arm
 */
#include "../../matched/include/G_Block.h"

typedef struct { unsigned words[103]; unsigned value; } State;

extern void func_02087C6C(void *);
extern void *func_02092344(void *, const void *, unsigned);
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
extern int DWC_UpdateConnection(void);
extern void DWC_ClearError(void);
void func_021C9744(unsigned char *p, unsigned x);
int func_021C97E0(unsigned type);
extern void *d_021D3EFC;
extern State d_021D4084;
extern struct Block d_021D4098;
extern unsigned d_021CF6D4[], d_021CF78C[];

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
