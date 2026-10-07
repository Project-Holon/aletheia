/*
 * file:     btl_server_p96.c
 * unit:     yes
 * function: func_021C84AC, func_021C84D0, func_021C84D8, func_021C84E0, func_021C84E8, func_021C84F4, func_021C8534
 * address:  0x021C84AC
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
 *   func_021C2128 0x021C2128 thumb ov093
 *   func_021BDBB8   0x021BDBB8  thumb ov093
 *   func_021CC668   0x021CC668  thumb ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021C8578  0x021C8578  thumb  ov093
 */
typedef unsigned char u8;

struct Flags { u8 low:5; u8 flag:1; u8 high:2; };

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021C2128(u8 *p, u8 *a);
extern void func_021BDBB8(u8 *p, u8 *a);
extern int func_021CC668(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern int func_021C8578(u8 *p, int v, u32 *out);
int func_021C84AC(u8 *p, u8 *a, u8 *out);
void func_021C84D0(u8 *p, u8 *a);
int func_021C84D8(u8 *p);
void func_021C84E0(unsigned char *p, unsigned int v);
void func_021C84E8(u8 *p);
void func_021C84F4(unsigned char *p, unsigned int v);
int func_021C8534(u8 *p);

int func_021C84AC(u8 *p, u8 *a, u8 *out)
{
    int r;
    ((struct Flags *)(p + 0x78a))->flag = 0;
    r = func_021C2128(p, a);
    *out = ((struct Flags *)(p + 0x78a))->flag;
    return r;
}


/*
 * tail-call thunk to func_021BDBB8
 */
void func_021C84D0(u8 *p, u8 *a)
{
    func_021BDBB8(p, a);
}


/*
 * tail-call thunk to func_021CC668
 */
int func_021C84D8(u8 *p)
{
    return func_021CC668(p);
}


/*
 * Was MATCH (pool word to the unlabelled 0x021C84F4 had no witness); the
 * matched func_021C84F4 now resolves it, verified EXACT.
 */
void func_021C84E0(unsigned char *p, unsigned int v)
{
    func_021C84F4(p, v);
}


void func_021C84E8(u8 *p)
{
    p[0x785] = 0;
}

/*
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021C84F4..0x021C8534
 * (64 bytes, including a 2-byte pool-alignment nop and two pool words).
 * Searches the u8 set at p+0x791 for v; if absent and i < 0x18, appends v
 * and bumps the count at p+0x785.
 */
void func_021C84F4(unsigned char *p, unsigned int v)
{
    unsigned int i;
    unsigned int n = p[0x785];

    for (i = 0; i < n; i++) {
        if (v == p[0x791 + i])
            return;
    }
    if (i < 0x18) {
        *(p + i + 0x791) = v;
        p[0x785] = p[0x785] + 1;
    }
}


int func_021C8534(u8 *p)
{
    u32 i;
    u32 buf;
    for (i = 0; i < p[0x785]; i++) {
        if (func_021C8578(p + 0x1ab8, func_021B8DDC(p[0x791 + i]), &buf)) {
            return 1;
        }
    }
    return 0;
}
