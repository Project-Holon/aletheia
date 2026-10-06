/*
 * function: func_021F4314
 * address:  0x021F4314
 * packet:   pkt_ov048_021F4314
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F47B4  0x021F47B4  thumb  ov048
 *   func_0201EC64  0x0201EC64  thumb
 *   func_021F3AB4  0x021F3AB4  thumb  ov048
 *   func_021F3AD4  0x021F3AD4  thumb  ov048
 *   func_021F3B64  0x021F3B64  thumb  ov048
 *   func_0201EE60  0x0201EE60  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021F3D38  0x021F3D38  thumb  ov048
 *   func_0201ED04  0x0201ED04  thumb
 *   d_021F50C0     0x021F50C0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021F47B4(void *p);
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern int func_021F3AB4(void *p);
extern void func_021F3AD4(const u16 *p, u32 *out, int *cnt);
extern void func_021F3B64(u16 *p, u32 *out, int *cnt);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021F3D38(int *p, int unused, int b, int *c);
extern void func_0201ED04(struct WordSet *p);
extern u8 d_021F50C0[];

void func_021F4314(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    u32 buf[6];
    int cnt;
    void *h;
    int i;
    int f;

    h = func_0201EC64(func_021F47B4((void *)p[5]));
    if (func_021F3AB4(p))
        func_021F3AD4((const u16 *)p, buf, &cnt);
    else
        func_021F3B64((u16 *)p, buf, &cnt);
    switch (cnt) {
    case 0: break;
    case 1: f = 0xcd; break;
    case 2: f = 0xce; break;
    case 3: f = 0xcf; break;
    case 4: f = 0xd0; break;
    case 5: f = 0xd1; break;
    case 6: f = 0xd2; break;
    }
    for (i = 0; i < cnt; i++)
        func_0201EE60(h, i, buf[i]);
    func_0201F02C(h, 6, func_02012944((void *)p[2]));
    s.a = *(u16 *)(d_021F50C0 + 0xa);
    s.b = *(int *)(d_021F50C0 + 0x38);
    s.c = *(int *)(d_021F50C0 + 0x54);
    s.d = 2;
    s.e = 0x26;
    s.f = f;
    s.g = (int)h;
    func_021F3D38(p, (int)&s, 9, 0);
    func_0201ED04(h);
}
