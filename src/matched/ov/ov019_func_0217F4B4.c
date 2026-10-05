/*
 * function: func_0217F4B4
 * address:  0x0217F4B4
 * packet:   pkt_ov019_0217F4B4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: final push 2026-10-05 G4L6. Case -2 reads the entry table by byte offset (off = st[3] * 8,
 *   set after the zero test) with opt_propagation off, so the table address stays one live value
 *   for the pair-pointer load (indexed) and the count byte (+4). Struct-index forms and the
 *   un-pragma'd forms propagate the address into each use (two pool words) or hoist the pool load.
 * symbols:
 *   func_0217F310  0x0217F310  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   d_021805A4     0x021805A4  data  ov019  a4
 *   d_021803A0     0x021803A0  data  ov019  a1
 *   d_0218050C     0x0218050C  data  ov019  a4
 *   d_021804B4     0x021804B4  data  ov019  a4
 *   d_021807F8     0x021807F8  data  ov019  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Pair {
    u32 f0;
    u32 f4;
} Pair;

typedef struct Ent {
    Pair *p;
    u8    b;
    u8    pad5[3];
} Ent;

extern int  func_0217F310(char *p, u32 a1);
extern void func_02034714(const char *a, u32 b, const char *c);

extern const Ent d_021805A4[];
extern const u8  d_021803A0[][2][2];
extern const u32 d_0218050C[];
extern const u32 d_021804B4[];
extern u32 d_021807F8[];

#pragma opt_propagation off
int func_0217F4B4(char *p, int *hit, u8 *st, int *flag, u32 a4)
{
    u32 key;
    u32 i;
    const Pair *pairs;

    *hit = 0;
    *flag = 0;
    key = func_0217F310(p, a4);
    switch (key) {
    case (u32)-1:
        return key;
    case (u32)-2: {
        u32 off;
        const u8 *base;
        if (st[3] == 0)
            return key;
        off = st[3] * 8;
        base = (const u8 *)d_021805A4;
        pairs = *(const Pair * const *)(base + off);
        key = pairs[*(base + off + 4) - 1].f4;
        break;
    }
    case 0x64:
        return d_021803A0[st[0]][st[1]][st[2]];
    case 0x96:
        *flag = 1;
        return d_021803A0[st[0]][st[1]][st[2]];
    }

    if (st[3] == 0) {
        if (key == (u32)d_0218050C) {
            if (st[0] == 4)
                st[0] = 0;
        } else if (key == (u32)d_021804B4) {
            st[0] = 4;
        }
    }

    for (i = 0; (i < 8) ? 1 : 0; i++) {
        if (d_021805A4[i].p == (const Pair *)key) {
            *hit = 1;
            return i;
        }
        switch (st[3]) {
        case 0:
        case 1:
            break;
        case 2:
            if (key < 5) {
                st[0] = key;
                *hit = 1;
                return 1;
            }
            break;
        case 3:
        case 6:
            if (key < 2) {
                st[1] = key;
                *hit = 1;
                if (st[3] == 6)
                    return 5;
                return 1;
            }
            break;
        case 4:
        case 7:
            if (key < 2) {
                st[2] = key;
                *hit = 1;
                if (st[3] == 7)
                    return 5;
                return 1;
            }
            break;
        case 5:
            break;
        }
    }
    func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    return 0;
}
#pragma opt_propagation reset
#pragma opt_propagation reset
