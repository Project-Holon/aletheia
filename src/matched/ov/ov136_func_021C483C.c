/*
 * function: func_021C483C
 * address: 0x021C483C
 * packet: pkt_ov136_021C483C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 0x021C48FA..0x021C48FC is a zero alignment halfword.
 * symbols:
 *   func_0202822C 0x0202822C thumb
 *   func_021C47C4 0x021C47C4 thumb ov136
 *   func_021C44FC 0x021C44FC thumb ov136
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202822C(void *, int);
extern void func_02028218(void *, int);
extern int func_02028230(void *);
extern void func_020282A4(void *);
extern void func_021C47C4(u8 *, int);
extern int func_0201CE30(void *);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201CE48(void *);
extern void func_0201F7A8(void *, int);
extern void func_020456F8(void *);
extern void *func_02045730(void *);
extern void func_020409B4(void *);
extern void func_021C44FC(u8 *);
int func_021C483C(u8 *p)
{
    void *q;
    switch (*(u16 *)(p + 8)) {
    case 0:
        func_0202822C(*(void **)(p + 0x128), 1);
        func_02028218(*(void **)(p + 0x12C), 0);
        *(u16 *)(p + 8) = 1;
        break;
    case 1:
        if (func_02028230(*(void **)(p + 0x128)) != 0) {
            func_020282A4(*(void **)(p + 0x128));
            func_02028218(*(void **)(p + 0x128), 1);
            func_021C47C4(p, 2);
            *(u16 *)(p + 8) = 2;
        }
        break;
    case 2:
        if (func_0201CE30(*(void **)(p + 0x9C)) == 2) {
            if ((func_020362DC() & 1) || func_02035C60()) {
                func_0201CE48(*(void **)(p + 0x9C));
                *(u16 *)(p + 8) = 3;
            }
        }
        break;
    case 3:
        func_0201F7A8(*(void **)(p + 0x5C), 2);
        q = *(void **)(p + 0x5C);
        func_020456F8(q);
        func_020409B4(func_02045730(q));
        func_021C44FC(p);
        *(u16 *)(p + 8) = 0;
        p[0xB] = p[0xC];
        break;
    }
    return 0;
}
