/*
 * file:     unit_021D7CEC_p07.c
 * unit:     yes
 * function: func_021D88BC, func_021D88F0, func_021D891C, func_021D89EC, func_021D8B3C
 * address:  0x021D88BC
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D7A10 0x021D7A10 arm ov125
 *   d_021D8CD0 0x021D8CD0 data a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {int a,b,c;} Triple;

typedef struct {int a,b;} Pair;

typedef struct { int words[8]; } Table;

extern int func_021D7A10(int id, void *buf, int x, int sz);
int func_021D88BC(u32 a, u32 b, u32 c, u32 n);
int func_021D88F0(u32 a, u32 b, u32 n);
int func_021D891C(int n);
int func_021D89EC(int n);
int func_021D8B3C(void);
extern const Table d_021D8CD0;

int func_021D88BC(u32 a, u32 b, u32 c, u32 n)
{
    Triple p;
    p.a=a; p.b=b; p.c=c;
    return func_021D7A10(0x55f2, &p, n, -1);
}

int func_021D88F0(u32 a, u32 b, u32 n)
{
    Pair p;
    p.a=a; p.b=b;
    return func_021D7A10(0x55f3, &p, n, -1);
}

int func_021D891C(int n)
{
    int size;
    switch (n) {
    case 0: size = 0x400; break;
    case 0x5208: size = 0x230; break;
    case 0x5209: size = 12; break;
    case 0x55f0: size = 0x19a8; break;
    case 0x55f1: size = 28; break;
    case 0x55f2: size = 12; break;
    case 0x55f3: size = 8; break;
    default: return -1;
    }
    return size + 0x140;
}

int func_021D89EC(int n)
{
    Table table = d_021D8CD0;
    int size;
    int i;
    int got;
    switch (n) {
    case -1:
        size = -1;
        for (i = 0; ; i++) {
            if (table.words[i] == -1) break;
            got = func_021D89EC(table.words[i]);
            if (got > size) size = got;
        }
        if (size == -1) return -1;
        break;
    case 0: size = 0x400; break;
    case 0x5208: size = 8; break;
    case 0x5209: size = 0xb30; break;
    case 0x55f0: size = 8; break;
    case 0x55f1: size = 0x1864; break;
    case 0x55f2: size = 0x18b0; break;
    case 0x55f3: size = 0; break;
    default: return -1;
    }
    return size + 8;
}

/*
 * extent: eight-byte leaf ends at the handed lead 0x021D8B44.
 */
int func_021D8B3C(void) { return 0; }
