/*
 * function: func_021B8454
 * address: 0x021B8454
 * packet: pkt_ov172_021B8454
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 wD4 lane05: EXACT. w is a u32 local (callee keeps its real u16 return) declared
 *   between me and base: declaration order me, w, base, e gives slots 0x10, 0xC, 8, 4.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D1C0 0x0203D1C0 arm
 *   func_0203E808 0x0203E808 arm
 *   func_0203E8C8 0x0203E8C8 arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE058 0x021BE058 thumb ov172
 *   func_021BE0A8 0x021BE0A8 thumb ov172
 *   func_021B7B20 0x021B7B20 thumb ov172
 *   func_021B7740 0x021B7740 thumb ov172
 *   func_021B8614 0x021B8614 thumb ov172
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_0203D1C0(u32 index);
extern void func_0203E808(u32 a, int b, u32 c, u32 d);
extern void func_0203E8C8(int a);
extern u16 func_021BE00C(u16 *p);
extern u32 func_021BDFDC(void *p);
extern void func_021BE058(void *p, u32 v);
extern void func_021BE0A8(void *p, u32 v);
extern void func_021B7B20(int unused, char *base, int i);
extern void func_021B7740(void *p, char *q, int a, int b);
extern void func_021B8614(int unused, int unused2, void *p);

void func_021B8454(void *a, char *q)
{
    u32 count = 0;
    int flag = 0;
    u8 i;
    u32 me;
    u32 w;
    u32 base;
    char *e;

    me = func_0203D1A4((struct Link *)func_020399A8());
    w = func_021BE00C((u16 *)a);
    for (i = 0; i < 4; i++) {
        if (func_0203D1C0(i) == 1) {
            e = q + i * 64;
            if (*(u32 *)(e + 0x64) == 0) {
                base = func_021BDFDC(a);
                *(u32 *)(e + 0x64) = 1;
                if (i == me) {
                    *(u32 *)(e + 0x70) = 1;
                } else {
                    u8 j;
                    for (j = 0; j < 3; j++) {
                        u32 m = 1 << j;
                        if (!(m & *(u8 *)(q + 0x170))) {
                            func_0203E808(0xC000, i, w, *(u32 *)(q + j * 4 + 0x164));
                            *(u8 *)(q + 0x170) |= (u8)m;
                            *(u8 *)(e + 0x78) = j;
                            break;
                        }
                    }
                    *(u8 *)(q + 0x182) |= (u8)(1 << i);
                    *(u32 *)(e + 0x7C) = 1;
                }
                func_021B7B20((int)a, (char *)base, i);
                flag = 1;
            }
            count = (u8)(count + 1);
        } else {
            u32 off = i << 6;
            char *e2 = q + off;
            if (*(u32 *)(e2 + 0x64) == 1) {
                *(u32 *)(e2 + 0x64) = 0;
                if (*(u32 *)(e2 + 0x70) == 0) {
                    func_0203E8C8(i);
                    *(u8 *)(q + 0x170) -= (u8)(1 << *(u8 *)(e2 + 0x78));
                }
                if (*(u8 *)(q + 0x3AE) == i)
                    *(u32 *)(q + 0x194) = 0;
                flag = 1;
                *(u8 *)(q + 0x182) -= (u8)(flag << i);
                func_021B8614((int)a, (int)q, q + 0x64 + off);
            }
        }
    }
    if (flag == 1) {
        func_021BE058(a, count);
        func_021BE0A8(a, me);
    }
    func_021B7740(a, (char *)func_021BDFDC(a), 0, 1);
}
