/*
 * file:     unit_021EAC54_p01.c
 * unit:     yes
 * function: func_021EAC54, func_021EAC64
 * address:  0x021EAC54
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
 *   func_0689B5CC   0x0689B5CC  thumb  ov095
 *   func_021E9984  0x021E9984  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y);
void func_021EAC54(E64 *p, u32 a2);
void func_021EAC64(u8 *p, u8 a, int c);


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
void func_021EAC54(E64 *p, u32 a2) { func_0689B5CC(p[0x6].f0, a2); }


void func_021EAC64(u8 *p, u8 a, int c)
{
    func_021E9984(p, p + 0x10c, 4, a, c);
    p[0x174] = 0;
}
