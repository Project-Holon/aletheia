/*
 * function: func_022053E8
 * address:  0x022053E8
 * packet:   pkt_022053E8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020355D8  0x020355D8  arm
 *
 * blocker: codegen only, same 132-byte size, 64 concrete bytes differ, all 11
 *   relocations resolve. The original keeps the argument pointer in r4 and the
 *   result in r5; mwccarm assigns the pointer r5 and the result r4 here, which
 *   cascades into the ternary branch polarity and the shared `return 0`
 *   epilogue. Tried `int r; r = 0;`, `char *p = a;`, and a direct `return
 *   0;`/`return 1;` shape. The 0x547 pool literal itself is byte-identical.
 */

typedef unsigned int u32;

extern u32 func_0201CE30(u32);
extern u32 func_0201CE5C(u32, int);
extern u32 func_0201CE38(u32);
extern u32 func_020061E4(int);
extern u32 func_0203630C(void);
extern u32 func_02035C38(void);
extern u32 func_020362DC(void);
extern u32 func_02035C60(void);
extern void func_020355D8(int);

int func_022053E8(char *a)
{
    char *p = a;
    int r = 0;

    switch (func_0201CE30(*(u32 *)(p + 0x64))) {
    case 0:
        if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
            func_0201CE5C(*(u32 *)(p + 0x64), 0);
            func_020355D8((func_0203630C() & 3) != 0 ? 0 : 1);
        }
        break;
    case 1:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
            func_020061E4(0x547);
            func_0201CE38(*(u32 *)(p + 0x64));
            func_020355D8((func_020362DC() & 3) != 0 ? 0 : 1);
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}
