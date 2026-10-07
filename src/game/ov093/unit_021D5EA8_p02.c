/*
 * file:     unit_021D5EA8_p02.c
 * unit:     yes
 * function: func_021D5FC0, func_021D5FE4, func_021D6008, func_021D6034
 * address:  0x021D5FC0
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
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021D61F0 0x021D61F0 thumb ov093
 */
struct UtilSlots;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

struct Slot { u32 a : 3; u32 rest : 29; };

extern int func_021D7D6C(int);
extern void func_021D61F0(struct UtilSlots *);
void func_021D5FC0(struct UtilWork *p, u32 n);
void func_021D5FE4(u8 *p, unsigned int n);
void func_021D6008(u8 *p, unsigned int n);
void func_021D6034(struct UtilSlots *p, int k, struct Slot v);


void func_021D5FC0(struct UtilWork *p, u32 n)
{
    p->bits153[(u8)(n >> 3)] |= (u8)(1 << (n & 7));
}

/*
 * lever: index the offset base (p + 0x155), preserving its separate add.
 */
void func_021D5FE4(u8 *p, unsigned int n)
{
    (p + 0x155)[(u8)(n >> 3)] |= (u8)(1 << (n & 7));
}

void func_021D6008(u8 *p, unsigned int n)
{
    (p + 0x155)[(u8)(n >> 3)] &= (u8)~(u8)(1 << (n & 7));
}

void func_021D6034(struct UtilSlots *p, int k, struct Slot v)
{
    if (func_021D7D6C(k)) func_021D61F0(p);
    ((struct Slot *)((u8 *)p + 0x1c))[(u32)k] = v;
    ((u8 *)p + (u32)k)[0xac] = 0;
}
