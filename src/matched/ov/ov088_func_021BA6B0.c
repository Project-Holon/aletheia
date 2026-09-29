/*
 * function: func_021BA6B0
 * address:  0x021BA6B0
 * packet:   pkt_ov088_021BA6B0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC080  0x021BC080  thumb  ov088
 *   func_021BBBAC  0x021BBBAC  thumb  ov088
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021BBD10  0x021BBD10  thumb  ov088
 *   func_021BB840  0x021BB840  thumb  ov088
 *   func_021BB810  0x021BB810  thumb  ov088
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021BC080(char *p, int v);
extern void func_021BBBAC(char *p);
extern int func_0201C6B4(void *p);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_021BBD10(char *p, int mode);
extern int func_021BB840(void *, int);
extern void func_021BB810(void *, int, int, int);
extern int func_0201C4E4(void *p);
extern void *func_02045770(void *p);
extern int func_0201C6C4(void *t, void *p);
extern void func_02045334(void *p);

int func_021BA6B0(char *p)
{
    void *t;
    switch (*(u8 *)(p + 0x12a)) {
    case 0:
        if (*(u8 *)(p + 0x120) == 1) {
            *(u8 *)(p + 0x129) = 1;
            *(u8 *)(p + 0x12a) = 0;
            return func_021BC080(p, 1);
        }
        func_021BBBAC(p);
        *(u8 *)(p + 0x12a) = *(u8 *)(p + 0x12a) + 1;
        break;
    case 1:
        if (func_0201C6B4(*(void **)(p + 0x68)) == 1)
            *(u8 *)(p + 0x12a) = *(u8 *)(p + 0x12a) + 1;
        break;
    case 2:
        if (func_020362DC() & 1) {
            func_020061E4(0x54c);
            func_021BBD10(p, 1);
            *(u8 *)(p + 0x129) = 1;
            *(u8 *)(p + 0x12a) = 0;
            return func_021BC080(p, 1);
        }
        if (func_020362DC() & 2) {
            func_020061E4(0x551);
            func_021BBD10(p, 0);
            func_021BB810(p, *(u8 *)(p + *(u8 *)(p + 0x128) + 0x120),
                          func_021BB840(p, *(signed char *)(p + 0x12f)), 2);
            *(u8 *)(p + 0x12a) = 0;
            return 5;
        }
        break;
    }
    func_0201C4E4(*(void **)(p + 0x68));
    t = *(void **)(p + 0x68);
    if (*(u8 *)(p + 0xf4) != 0 && func_0201C6C4(t, func_02045770(*(void **)(p + 0xf0))) == 0) {
        func_02045334(*(void **)(p + 0xf0));
        *(u8 *)(p + 0xf4) = 0;
    }
    return 8;
}
