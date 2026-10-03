/*
 * function: func_021BF53C
 * address: 0x021BF53C
 * packet: pkt_ov110_021BF53C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   func_021BF6CC 0x021BF6CC thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BAC0C 0x021BAC0C thumb ov110
 *   func_020245AC 0x020245AC thumb
 *   func_020241E0 0x020241E0 thumb
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BF4C4 0x021BF4C4 thumb ov110
 *   func_021BF500 0x021BF500 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *, void *);
struct T245;
struct T241;
extern int func_021B9C74(void *);
extern int func_021BF680(u8 *);
extern void func_021BF6CC(u8 *, u8, u8);
extern void func_021B9BEC(u8 *, int);
extern int func_021BAC0C(u8 *p);
extern void func_020245AC(struct T245 *, u32);
extern void func_020241E0(struct T241 *, u16 *, u16 *);
extern void func_021BD7A0(u8 *, Handler);
extern int func_021BF4C4(u8 *p, int *q);
extern void func_021BF500(u8 *);
void func_021BF53C(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (func_021B9C74(*(void **)(p + 20))) {
            if (func_021BF680(p)) {
                func_021BF6CC(p + 107, 1, 0);
                *(u16 *)(p + 72) = 0;
                func_021B9BEC(*(u8 **)(p + 20), 21);
                *q = 1;
            } else *q = 3;
        }
        break;
    case 1:
        switch (func_021BAC0C(*(void **)(p + 20))) {
        case 0:
            func_021B9BEC(*(u8 **)(p + 20), 23);
            *q = 3;
            break;
        case 1:
            if (*(u32 *)(p + 4) == 2) func_020245AC((struct T245 *)(p + 8), 42);
            func_020241E0(*(struct T241 **)p, (u16 *)(p + 16), (u16 *)(p + 8));
            func_021BD7A0(p, (Handler)func_021BF4C4);
            *q = 3;
            break;
        }
        break;
    case 2:
        if (*(u16 *)(p + 52) & 243) *q = 3;
        break;
    case 3:
        if (func_021B9C74(*(void **)(p + 20))) func_021BF500(p);
        break;
    }
}
