/*
 * file:     unit_0689B8CC.c
 * unit:     yes
 * function: func_0689B8CC, func_0689B92C, func_0689B974
 * address:  0x0689B8CC
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
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021D5B68  0x021D5B68  thumb
 *   func_021D6314  0x021D6314  thumb
 *   func_021D631C  0x021D631C  thumb
 *   func_021E8AFC  0x021E8AFC  thumb
 *   func_0689C104   0x0689C104  thumb  ov095
 */
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef struct Word { int v; } Word;

extern void func_021C8838(void *, int, u16);
extern u32 func_021D5440(u32);
extern void func_021C8860(void *, u32);
extern int func_021D5B68(void *);
extern void func_021D6314(void *, int);
extern Word func_021E8AFC(void);
extern int func_021D631C(void *, int);
extern void func_0689C104(void *, void *, u8);
int func_0689B8CC(void *p, u32 b, int kind);
int func_0689B92C(int a);
void func_0689B974(void *a, void *b, int c);

int func_0689B8CC(void *p, u32 b, int kind)
{
    int message;
    message = func_0689B92C(kind);
    if (message > 0) {
        func_021C8838(p, 2, message);
        func_021C8860(p, func_021D5440(b));
    }
    return 0;
}


int func_0689B92C(int a)
{
    switch (a) {
    case 5:
        return 0xf3;
    case 4:
        return 0x105;
    case 9:
        return 0x144;
    case 10:
        return 0x42f;
    }
    return -1;
}


void func_0689B974(void *a, void *b, int c)
{
    int t;
    int d;

    if (func_021D5B68(b) == 0) {
        func_021D6314(b, 0x14);
        t = func_021E8AFC().v;
        d = t - func_021D631C(b, 0x14);
        if (d > 0)
            func_0689C104(a, b, d);
    }
}
