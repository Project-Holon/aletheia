/*
 * function: func_021FCAA8
 * address: 0x021FCAA8
 * packet: pkt_ov132_021FCAA8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: state machine on p+0x4c (22-entry jump table; cases 20 and 21 are explicit
 * so the table keeps its size). Players are a 0x30-byte struct array at p+0x64. The final
 * packed-id draw is a 64-bit multiply high (_ull_mul) through an inline helper; the id is
 * added into sum (sum += list[k] << 16) before the call, which fixed the last 2 bytes.
 * Callees 021FD84C, 021FCEA8 and 021FD350 are void in their matched files but the caller
 * tests r0 == 1: their last call (a u32-returning arm9 function) leaves the result in r0,
 * so the originals return it. They are declared with return values here. Callee 021FD14C
 * and 021FD400 have no source yet (symbols resolve as labels).
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021FCEA8 0x021FCEA8 thumb ov132
 *   func_021FD14C 0x021FD14C thumb ov132
 *   func_021FD22C 0x021FD22C thumb ov132
 *   func_021FD84C 0x021FD84C thumb ov132
 *   func_021FD6C8 0x021FD6C8 thumb ov132
 *   func_021FD704 0x021FD704 thumb ov132
 *   func_021FD6DC 0x021FD6DC thumb ov132
 *   func_021FD6F0 0x021FD6F0 thumb ov132
 *   func_021FD76C 0x021FD76C thumb ov132
 *   func_021FD7D4 0x021FD7D4 thumb ov132
 *   func_021FD6A4 0x021FD6A4 thumb ov132
 *   func_021FD350 0x021FD350 thumb ov132
 *   func_021FD400 0x021FD400 thumb ov132
 *   func_021FD550 0x021FD550 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Pl {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 pad[3];
    u32 x;
    u32 e;
    u8 rest[0x18];
};
extern u32 func_0200FB24(void);
extern int func_0203CDBC(void);
extern int func_0203CEAC(int a0);
extern void func_0203D7BC(u8 a0);
extern u32 func_0203D1B4(void);
extern u32 func_0203F0A8(void);
extern void func_021FCDEC(int a, int b);
extern int func_021FCE00(char *, int);
extern u32 func_021FCEA8(int unused, int kind, u32 value, u32 id);
extern int func_021FD14C(char *);
extern int func_021FD22C(char *);
extern int func_021FD84C(u8 *p);
extern int func_021FD6C8(u8 *p);
extern int func_021FD704(u8 *p);
extern int func_021FD6DC(char *);
extern int func_021FD6F0(char *);
extern int func_021FD76C(u8 *p);
extern int func_021FD7D4(u8 *p);
extern int func_021FD6A4(char *);
extern int func_021FD350(char *p, char *src);
extern int func_021FD400(const char *p);
extern void func_021FD550(char *);
static inline u32 random_below(u32 n)
{
    u32 draw;
    draw = func_0203F0A8();
    return ((u64)draw * n) >> 32;
}
struct G {
    u8 pad[0x64];
    struct Pl pl[4];
};
void func_021FCAA8(char *p)
{
    u8 i, j, n;
    u8 cnt;
    u8 list[4];
    u32 v;
    u32 ok;
    if (func_0200FB24()) {
        *(int *)(p + 4) = 1;
        if (func_0203CDBC() == 0) func_0203CEAC(0);
    }
    if (*(int *)(p + 4) == 1) return;
    switch (*(u32 *)(p + 0x4c)) {
    case 0:
        return;
    case 1:
        func_0203D7BC(1);
        func_021FCDEC((int)p, 0x46);
        *(int *)(p + 0x4c) = 2;
        break;
    case 2:
        if (func_021FCE00(p, 0x46) == 1 && func_021FD14C(p) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 3;
            else *(int *)(p + 0x4c) = 5;
        }
        break;
    case 3:
        if (func_021FD84C((u8 *)p) == 1) *(int *)(p + 0x4c) = 4;
        break;
    case 4:
        cnt = 0;
        for (i = 0; i < 4; i++)
            if (((struct G *)p)->pl[i].b == 1) cnt++;
        if (cnt == func_0203D1B4() && func_021FD22C(p) == 1) *(int *)(p + 0x4c) = 5;
        break;
    case 6:
        if (func_021FCE00(p, 0x40) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 7;
            else *(int *)(p + 0x4c) = 0xb;
        }
        break;
    case 7:
        if (func_021FCEA8((int)p, 8, *(u32 *)(p + 0x144), 0xff) == 1) *(int *)(p + 0x4c) = 8;
        break;
    case 8:
        if (func_021FCEA8((int)p, 9, *(u32 *)(p + 0x148), 0xff) == 1) *(int *)(p + 0x4c) = 9;
        break;
    case 9:
        if (func_021FD6C8((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xa;
        break;
    case 10:
        if (*(int *)(p + 0x164) == 1 && func_021FD704((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xb;
        break;
    case 12:
        if (func_021FCE00(p, 0x42) == 1) {
            if (*(int *)(p + 0x48) == 1) {
                if (func_021FD6DC(p) == 1) *(int *)(p + 0x4c) = 0xd;
            } else *(int *)(p + 0x4c) = 0x11;
        }
        break;
    case 13:
        if (*(int *)(p + 0x168) == 1 && func_021FD6F0(p) == 1) *(int *)(p + 0x4c) = 0xe;
        break;
    case 14:
        if (*(int *)(p + 0x16c) == 1 && func_021FD76C((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xf;
        break;
    case 15:
        if (*(int *)(p + 0x174) == 1 && func_021FD7D4((u8 *)p) == 1) *(int *)(p + 0x4c) = 0x10;
        break;
    case 16:
        *(int *)(p + 0x4c) = 0x11;
        break;
    case 17:
        if (*(int *)(p + 0x178) == 1) func_021FD6A4(p);
        break;
    case 18:
        if (func_021FD350(p, (char *)(*(u32 *)(p + 0x120))) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 0x13;
            else *(int *)(p + 0x4c) = 0x15;
        }
        break;
    case 19:
        cnt = 0;
        for (i = 0; i < 4; i++)
            if (((struct G *)p)->pl[i].a == 1) cnt++;
        if (cnt == func_0203D1B4() && func_021FD400(p) == 1) *(int *)(p + 0x4c) = 0x15;
        break;
    case 20:
    case 21:
        break;
    default:
        break;
    }
    if (*(int *)(p + 0x184) == 1) {
        v = 0;
        v += ((struct G *)p)->pl[0].e;
        v += ((struct G *)p)->pl[1].e << 4;
        v += ((struct G *)p)->pl[2].e << 8;
        v += ((struct G *)p)->pl[3].e << 12;
        if (func_021FCEA8((int)p, 3, v, 0xff) == 1) *(int *)(p + 0x184) = 0;
    }
    {
        u32 sum = 0;
        n = 0;
        for (i = 0; i < 4; i++) {
            if (((struct G *)p)->pl[i].c == 1) {
                list[n] = i;
                n++;
            }
            sum += ((struct G *)p)->pl[i].d << (i * 4);
        }
        if (n != 0) {
            u32 k = random_below(n);
            sum += list[k] << 16;
            if (func_021FCEA8((int)p, 0xb, sum, 0xff) == 1) {
                for (j = 0; j < n; j++) {
                    ((struct G *)p)->pl[list[j]].c = 0;
                    ((struct G *)p)->pl[list[j]].d = 10;
                }
            }
        }
    }
    if (*(int *)(p + 0x188) == 1) {
        ok = 1;
        for (i = 0; i < 8; i++) {
            if (*(u32 *)(p + i * 4 + 0x18c) != 0xFFFF) {
                if (func_021FCEA8((int)p, 0xc, *(u32 *)(p + i * 4 + 0x18c), 0xff) == 1) *(u32 *)(p + i * 4 + 0x18c) = 0xFFFF;
                ok = 0;
            }
        }
        if (ok == 1) *(int *)(p + 0x188) = 0;
    }
    func_021FD550(p);
}
