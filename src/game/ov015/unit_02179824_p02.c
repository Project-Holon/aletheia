/*
 * file:     unit_02179824_p02.c
 * unit:     yes
 * function: func_021798D4, func_021798DC
 * address:  0x021798D4
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0217A9E0  0x0217A9E0  data  a4
 *   d_0217AAAC     0x0217AAAC  data   ov015  a1
 *   d_0217AAC0     0x0217AAC0  data   ov015  a4
 *   d_0217AAD2     0x0217AAD2  data   ov015  a1
 *   d_0217AAC6     0x0217AAC6  data   ov015  a1
 *   d_0217AAC4     0x0217AAC4  data   ov015  a1
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0217A148  0x0217A148  arm    ov015
 */
typedef unsigned char u8;

typedef unsigned short u16;

struct s_aac0 {
    u8 pad0[4];
    u16 h4;
    u8 b6;
    u8 b7;
};

typedef unsigned int   u32;

extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern void func_02082D44(void *dst, void *src, int n);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_0217A148(int a0, int a1, int a2);
void *func_021798D4(void);
void func_021798DC(void *dst, int n, u8 a, u8 b);
extern u8 d_0217AAAC[];
extern struct s_aac0 d_0217AAC0;
extern u8 d_0217AAD2[];
extern u8 d_0217AAC6[];
extern u8 d_0217AAC4[];

void *func_021798D4(void)
{
    return (void *)0x0217A9E0;
}


void func_021798DC(void *dst, int n, u8 a, u8 b)
{
    if ((unsigned)n >= 0xA6)
        func_02034714((const char *)d_0217AAAC, 0, (const char *)d_0217AAAC);
    d_0217AAC0.b6 = a;
    d_0217AAC0.b7 = b;
    if (dst != 0)
        func_02082D44(dst, d_0217AAD2, 0xA6);
    d_0217AAC0.h4 = func_0203F1FC(d_0217AAC6, n + 12);
    func_0217A148((int)d_0217AAC4, (u8)(n + 14), a);
}
