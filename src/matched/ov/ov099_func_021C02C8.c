/*
 * function: func_021C02C8
 * address: 0x021C02C8
 * packet: pkt_ov099_021C02C8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype-evidence: C23C8's forward target 0203C2B0 returns a boolean,
 *   unused here; BB954's complete body reads only r0/r1 before a six-input
 *   BAC24 call. 0290 reads r0 and explicitly sets each forwarding input.
 * symbols:
 *   func_0201AC80 0x0201AC80 thumb
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020200CC 0x020200CC thumb
 *   func_021C0290 0x021C0290 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BB954 0x021BB954 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021BDDD0 0x021BDDD0 thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0202EB14 0x0202EB14 thumb
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021C23D8 0x021C23D8 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct W; struct Obj;
extern u32 func_0201AC80(void *);
extern void func_021B9B64(char *);
extern int func_021BA928(struct W *);
extern int func_020200CC(struct Obj *);
extern void func_021C0290(char *);
extern void func_021C2408(char *);
extern void func_021BB954(char *, int);
extern int func_021C23C8(void *, void *);
extern int func_021BDDD0(char *);
extern int func_021BA8BC(void *);
extern void func_0202020C(struct Obj *, u16 *, u16 *);
extern void func_0201F868(void *);
extern void func_021BA8EC(char *);
extern void func_021BAAB8(char *, int, int);
extern int func_0202EB14(void);
extern u32 func_0202EB0C(void);
extern void func_021C23D8(char *, int);
int func_021C02C8(char *p, int ret)
{
    u32 choice;
    u8 *q;
    func_0201AC80(*(void **)(p + 0xc8));
    func_021B9B64(p + 0x274);
    if (!func_021BA928((struct W *)p)) return ret;
    choice = func_020200CC(*(struct Obj **)(p + 0xbc));
    switch (choice) {
    case (u32)-1:
        return ret;
    case (u32)-2:
        *(int *)(p + 0x1cc) = 11;
        func_021C0290(p);
        func_021C2408(p);
        return ret;
    case 7:
        func_021C0290(p);
        q = *(u8 **)(p + 0x248);
        *(u16 *)(p + 0x134c) = q[0x21];
        *(u16 *)(p + 0x134e) = q[0x22];
        q[0x48] = q[0x20];
        func_021BB954(p, 1);
        *(int *)(p + 0x1cc) = 0x54;
        return ret;
    case 4:
        if ((*(u8 **)(p + 0x248))[0x46] == 0) return ret;
        func_021C0290(p);
        func_021C23C8(p, (void *)-1);
        *(int *)(p + 0x1cc) = 0x9e;
        break;
    case 6:
        if (func_021BDDD0(p) == 0) {
            *(int *)(p + 0x1a4) = func_021BA8BC(*(void **)(p + 0x1a4));
            func_0202020C(*(struct Obj **)(p + 0xbc), 0, (u16 *)(p + 0x23c));
            func_0201F868(*(void **)(p + 0xb8));
            func_021BA8EC(p);
            func_021BAAB8(p, 0x79, 0);
            *(int *)(p + 0x1cc) = 0x71;
            return ret;
        } else {
            func_021C0290(p);
            func_021C23C8(p, (void *)-1);
            *(int *)(p + 0x1cc) = 0x9e;
        }
        break;
    case 5:
        if ((*(u8 **)(p + 0x248))[0x46] == 0) return ret;
        if (func_0202EB14() == 0 && func_0202EB0C() != 0) {
            func_021C0290(p);
            func_021BAAB8(p, 0x95, 0);
            *(int *)(p + 0x1cc) = 0xa0;
            return ret;
        } else {
            func_021C0290(p);
            func_021C23C8(p, (void *)-1);
            *(int *)(p + 0x1cc) = 0x9e;
        }
        break;
    case 0: case 1: case 2: case 3: default:
        break;
    }
    func_021C23D8(p, 1);
    *(int *)(p + 0x1e0) = 0;
    *(u16 *)(p + 0x246) = choice;
    *(int *)(p + 0x1cc) = 0xad;
    return ret;
}
