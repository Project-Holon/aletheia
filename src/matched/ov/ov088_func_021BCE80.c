/*
 * function: func_021BCE80
 * address:  0x021BCE80
 * packet:   pkt_ov088_021BCE80
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD188  0x021BD188  thumb  ov088
 *   func_0202EE30  0x0202EE30  thumb
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02005654  0x02005654  thumb
 *   func_021BCE70  0x021BCE70  thumb  ov088
 *   func_020070A4  0x020070A4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021DFF18  0x021DFF18  thumb  ov228
 *   func_02034A5C  0x02034A5C  arm
 *   func_02007230  0x02007230  thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_02007400  0x02007400  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_0200566C  0x0200566C  thumb
 *   func_02087BCC  0x02087BCC  arm
 *   d_021BDA20     0x021BDA20  data  a4
 *   ov228_id       0x000000E4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *d_021BDA20;
extern char ov228_id[];

extern int func_021BD188(u8 *);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, u16 heap);
extern u8 func_02045730(void *);
extern void func_020409B4(u32 index);
extern void func_02005654(void (*fn)(void), int a);
extern void func_021BCE70(void);
extern void *func_020070A4(void);
extern void func_02034AC4(u32);
extern void func_021DFF18(int);
extern void func_02034A5C(u32);
extern void func_02007230(void *);
extern int func_0200725C(void *, u32, int);
extern void func_02007400(void *, u32, int);
extern void func_020072A4(void *, u32);
extern void func_0200566C(void);
extern void func_02087BCC(int);

void func_021BCE80(u8 *p)
{
    void *r;
    u32 i;

    if (func_021BD188(p) == 0) {
        d_021BDA20 = func_0202EE30(0, *(void **)(p + 0x1c), 0xf, 0x10, 0x81);
        func_020409B4(func_02045730(*(void **)(p + 0x1c)));
        func_02005654(func_021BCE70, 0);
        r = func_020070A4();
        func_02034AC4((u32)ov228_id);
        func_021DFF18(0x81);
        func_02034A5C((u32)ov228_id);
        func_02007230(r);
        for (i = 0; i < 9; i++) {
            if (func_0200725C(r, i, 0x81) == 1)
                func_02007400(r, i, 0x81);
            func_020072A4(r, i);
        }
        func_0200566C();
        func_02087BCC(0);
    }
}
