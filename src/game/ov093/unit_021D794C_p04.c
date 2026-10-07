/*
 * file:     unit_021D794C_p04.c
 * unit:     yes
 * function: func_021D7D78, func_021D7D9C, func_021D7DC0, func_021D7E10
 * address:  0x021D7D78
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
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021D7B8C  0x021D7B8C  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021D7E34 0x021D7E34 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
struct Unk021D62A8;
typedef unsigned int u32;

typedef unsigned char u8;

union Slot { u32 raw; struct {u32 kind:3; u32 lo:6; u32 hi:6; u32 rest:17;} s; };

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 v; } Word;

extern Word func_021D7D18(int x);
extern u8 func_021D5440(u8 *p);
extern Word func_021E899C(u32 a);
extern u32 func_021D7B8C(u32 lo, u32 hi);
extern Word func_021E8940(u8 a);
extern Word func_021E89C0(void);
extern int func_021D7E34(int);
extern int func_021D62C4(struct Unk021D62A8 *,int);
union Slot func_021D7D78(u32 x);
union Slot func_021D7D9C(u32 x);
void func_021D7DC0(int a, int b, Word *out);
int func_021D7E10(struct Unk021D62A8 *p);

union Slot func_021D7D78(u32 x) { union Slot s; s.raw=0; s.s.kind=2; s.s.lo=x; return s; }

union Slot func_021D7D9C(u32 x) { union Slot s; s.raw=0; s.s.kind=3; s.s.lo=x; return s; }


void func_021D7DC0(int a, int b, Word *out)
{
    u8 y;

    if (a < 6) {
        *out = func_021D7D18(a);
        return;
    }
    out->v = 0;
    switch (a) {
    case 7:
        *out = func_021E899C(func_021D5440((u8 *)b));
        break;
    case 6:
        y = func_021D7B8C(2, 5);
        *out = func_021E8940(y);
        break;
    default:
        *out = func_021E89C0();
        break;
    }
}

/*
 * lever: declare n before i; both exits return n to retain r0 on the zero path.
 * extent: trailing two-byte alignment before Thumb-to-ARM veneer 021D7E34.
 */
int func_021D7E10(struct Unk021D62A8 *p) { int n; int i=0; for (;;) { n=func_021D7E34(i++); if(n==0) return n; if(func_021D62C4(p,n)) return n; } }
