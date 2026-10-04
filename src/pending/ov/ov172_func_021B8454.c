/*
 * function: func_021B8454
 * address: 0x021B8454
 * packet: pkt_ov172_021B8454
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04 wD2 lane01: still 7 bytes (e/w slot swap). Also tried: block-scoped e and base (7), block-scoped e only (9), declaration orders w,e,me / me,w,base,e / me,base,e,w (9-10). Original slots e=sp+4, base=sp+8, w=sp+0xC.
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
  * note 2026-10-04 (wD1 lane03): DIFF, 7 bytes, 380 size right. Only residue: stack slot
 * numbers of e/w (target e=sp+4, base=sp+8, w=sp+0xC, me=sp+0x10; ours e and w swapped).
 * Tried declaration orders of the four locals, u32 w, separate else-path pointer,
 * (u8)-cast callee params replaced by wide params. Key lever: else path uses
 * off = i << 6 (kept in r6) and passes q + 0x64 + off.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_020399A8(void);
extern int func_0203D1A4(void *);
extern int func_0203D1C0(int a);
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
    char *e;
    u16 w;
    u32 base;

    me = func_0203D1A4(func_020399A8());
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
