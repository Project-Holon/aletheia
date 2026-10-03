/*
 * function: func_021CF078
 * address: 0x021CF078
 * packet: pkt_ov093_021CF078
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021CF918 0x021CF918 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   func_021CE3B4 0x021CE3B4 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021CE0F8 0x021CE0F8 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021EABC4 0x021EABC4 thumb ov093
 *   func_021EAC54 0x021EAC54 thumb ov093
 *   func_021CE08C 0x021CE08C thumb ov093
 *   func_021D8414 0x021D8414 thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B86E4(unsigned int **p);
extern u32 func_021CF918(u8 *, u8 *, u16 *);
extern void func_021EAF18(u8 *, u32, u32);
extern void func_021EAF50(u8 *, u32);
extern void func_021EAF78(u8 *, u8);
extern void func_021CE3B4(u8 *p, void *q);
extern int func_021EA710(u32 *p);
extern void func_021CE0F8(u8 *, u8 *, u8 *);
extern void func_021EA65C(void *, u8 *);
extern int func_021EA720(void *);
extern void func_021EABC4(void *, u8 *, u8 *, int);
extern int func_021EAC54(void *, int *);
extern int func_021CE08C(u8 *);
extern void func_021D8414(u32 *p);
extern void func_021CE150(u8 *, u32);
extern void func_021CE4D0(void);
extern int func_021CE3C8(u8 *p, int *state);
extern u32 func_021CF220(u8 *p, int *st);
u32 func_021CF078(u8 *p, u32 *st)
{
    u8 id;
    u16 k;
    int result;
    switch (*st) {
    case 0:
        switch (func_021B86E4(*(void **)p)) {
        default:
        case 0:
            if (func_021CF918(p, &id, &k) == 4) {
                *st = 5;
                break;
            }
            if (k) {
                func_021EAF18(p + 0x58, 2, 0x365);
                func_021EAF50(p + 0x58, id);
                func_021EAF50(p + 0x58, k);
            } else {
                func_021EAF18(p + 0x58, 1, 0x4a);
            }
            func_021CE3B4(p, p + 0x58);
            *st = 1;
            break;
        case 1:
            func_021EAF18(p + 0x58, 1, 0x4c);
            func_021CE3B4(p, p + 0x58);
            *st = 1;
            break;
        case 2:
            func_021EAF18(p + 0x58, 1, 0x4d);
            func_021EAF78(p + 0x58, 0xff);
            func_021CE3B4(p, p + 0x58);
            *st = 3;
            break;
        }
        break;
    case 1:
        if (func_021EA710(*(void **)(p + 0x54))) {
            func_021CE0F8(p, *(u8 **)(p + 8), p + 0x58);
            func_021EA65C(*(void **)(p + 0x54), p + 0x58);
            *st = 2;
        }
        break;
    case 2:
        if (func_021EA710(*(void **)(p + 0x54)))
            func_021CE150(p, (u32)func_021CE4D0);
        break;
    case 3:
        func_021EA710(*(void **)(p + 0x54));
        if (func_021EA720(*(void **)(p + 0x54))) {
            func_021EAF18(p + 0x58, 3, 8);
            func_021EAF18(p + 0x7c, 3, 9);
            func_021EABC4(*(void **)(p + 0x54), p + 0x58, p + 0x7c, 1);
            *st = 4;
        }
        break;
    case 4:
        if (func_021EA710(*(void **)(p + 0x54))) {
            if (func_021EAC54(*(void **)(p + 0x54), &result)) {
                if (result == 0)
                    *st = 5;
                else
                    func_021CE150(p, (u32)func_021CE4D0);
            } else if (func_021CE08C(p)) {
                func_021CE150(p, (u32)func_021CE3C8);
            }
        }
        break;
    case 5:
        func_021D8414(*(void **)(p + 0xc));
        p[0x1b2] |= 4;
        func_021CE150(p, (u32)func_021CF220);
        break;
    }
    return 0;
}
