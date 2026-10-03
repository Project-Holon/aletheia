/*
 * function: func_021E432C
 * address: 0x021E432C
 * packet: pkt_ov170_021E432C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF3EC 0x021EF3EC thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned int u32;
#define W(p) (*(u8 **)((p) + 44))
extern void func_021EC000(u8 *, int, int);
extern void func_021EE038(u8 *, int, int, int);
extern void func_021EF3A0(int);
extern void func_021ECB20(u8 *, int, int);
extern void func_021ED888(u8 *, int);
extern void func_021EF3EC(int);
extern void func_020061E4(unsigned);
extern int func_021E8FC0(u8 *, int (*)(u8 *), int);
extern int func_021E01B0(u8 *);
extern u8 func_020260E0(void *);
extern void func_021DEFEC(u8 *, int);
extern void func_021ED544(u8 *, int);
extern void func_021ED508(u8 *, int, int);
extern void func_021EE364(u8 *, int, int);
extern void func_021EF68C(u8 *);
extern void func_021EF670(u8 *);
int func_021E432C(u8 *p)
{
    u8 index;
    u8 selection;
    switch (*(u32 *)(W(p) + 0xa194)) {
    case 0:
        func_021EC000(W(p), 4, 0);
        func_021EE038(p, 0, 0, 1);
        if (p[27] == 0) {
            func_021EF3A0(*(int *)(W(p) + 116));
            *(u32 *)(W(p) + 0xa194) = 2;
        } else {
            func_021ECB20(p, 1, 1);
            func_021ED888(W(p), 0);
            func_021EF3EC(*(int *)(W(p) + 116));
            *(u32 *)(W(p) + 0xa194) = 1;
        }
        func_020061E4(0x669);
        return func_021E8FC0(p, func_021E01B0, 33);
    case 1:
        *(u32 *)(W(p) + 0xa194) = 0;
        index = func_020260E0(*(void **)(W(p) + 112));
        if (index < 30 || index >= 36)
            selection = 0;
        else
            selection = index - 30;
        func_021DEFEC(p, selection + 30);
        func_021ED544(p, 6);
        func_021ED508(p, 14, 1);
        if (*(int *)(*(u8 **)p + 36) == 2) {
            func_021EE364(p, 5, selection);
            return 27;
        }
        func_021EF68C(W(p));
        func_021EE364(p, 14, selection);
        return 39;
    case 2:
        *(u32 *)(W(p) + 0xa194) = 0;
        index = func_020260E0(*(void **)(W(p) + 112));
        if (index >= 30)
            index = 0;
        func_021DEFEC(p, index);
        func_021EF670(W(p));
        func_021ED544(p, 6);
        func_021ED508(p, 14, 1);
        if (*(int *)(*(u8 **)p + 36) == 4) {
            func_021EE364(p, 13, index);
            return 35;
        }
        func_021EE364(p, 3, index);
        return 17;
    }
    return 33;
}
