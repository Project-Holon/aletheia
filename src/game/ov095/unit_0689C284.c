/*
 * file:     unit_0689C284.c
 * unit:     yes
 * function: func_0689C284, func_0689C364
 * address:  0x0689C284
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8A78  0x021E8A78  thumb
 *   func_021C8810  0x021C8810  thumb
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021E8B80  0x021E8B80  thumb
 */
/* stand-in: a 4-byte by-value struct is the only form that gives the varargs-style push {r0-r3} and a stack-read second argument */
typedef struct { int v; } Word;

typedef unsigned short u16;

extern int func_021E8A78(Word);
extern void func_021C8838(void *, int, u16);
extern int func_021D5440(void *);
extern void func_021C8860(void *, int);
extern int func_021E8B80(Word);
extern void func_021C8810(void *);
int func_0689C284(unsigned int selector, Word value);
void func_0689C364(int a, Word b, void *c, void *d);

int func_0689C284(unsigned int selector, Word value)
{
    int result = -1;
    switch (selector) {
    case 4: result = 0xff; break;
    case 1: result = 0x111; break;
    case 3: result = 0x120; break;
    case 2: result = 0x132; break;
    case 6: result = 0x159; break;
    case 7: result = 0x147; break;
    case 9: result = 0x141; break;
    case 11: result = 0x238; break;
    case 12: result = 0x241; break;
    case 14: result = 0x29b; break;
    case 18: result = 0x25f; break;
    case 17: result = 0x171; break;
    case 21: result = 0x2e0; break;
    case 19: result = 0x2d7; break;
    case 13: result = 0x250; break;
    case 15: result = 0x371; break;
    case 5:
        if (func_021E8A78(value) != 0) result = 0xed;
        else result = 0xea;
        break;
    }
    return result;
}


void func_0689C364(int a, Word b, void *c, void *d)
{
    int k;

    k = func_0689C284(a, b);
    if (k >= 0) {
        func_021C8838(d, 2, k);
        func_021C8860(d, func_021D5440(c));
        if (a == 8 || a == 13)
            func_021C8860(d, func_021E8B80(b));
    } else {
        func_021C8810(d);
    }
}
