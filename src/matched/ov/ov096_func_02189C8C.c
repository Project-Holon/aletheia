/*
 * function: TR_AI_CmdLoadPokeValueSimple
 * address:  0x02189C8C
 * packet:   pkt_ov096_02189C8C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   d_0218A58C     0x0218A58C  data   ov096  a4
 *
 * Lever: the second parameter is a struct pointer (fields at 0x38, 0xc4);
 * with an int base and a local `int *p = b + 0x38` the store/adds order and
 * the r4/r5 roles were wrong.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { int v[7]; } Seven;
typedef struct { u8 p0[0x38]; int f38; u8 p1[0x88]; int fc4; } Obj;

extern const Seven d_0218A58C;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);

int TR_AI_CmdLoadPokeValueSimple(struct Cursor *a, Obj *b) {
    u8 s;
    int v;
    u32 i;
    Seven t;
    s = TR_AI_GetPosition((u8 *)b, VM_GetU32(a));
    t = d_0218A58C;
    i = 0;
    b->f38 = 0;
    for (; i < 7; i++) {
        v = BTL_POKEPARAM_GetValue(TR_AI_GetPoke((u8 *)b, s), t.v[i]);
        if (v > 6) {
            b->f38 += v - 6;
        }
    }
    return b->fc4;
}
