/*
 * function: func_021D4C50
 * address: 0x021D4C50
 * packet: pkt_ov122_021D4C50
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02158630 0x02158630 thumb ov010
 *   func_021D4BF4 0x021D4BF4 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 */
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
extern int func_02158630(void *);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_021D4BF4(char *p);
extern void func_021D4244(char *, void *, int);
int func_021D4C50(int value, char *p)
{
    void *obj;
    obj = (void *)func_02012138(*(void **)(p + 0x354));
    *(int *)(p + 0x35c) = value;
    switch (value) {
    case 0:
    case 3:
        *(int *)(*(char **)(p + 0x344) + 0x28) = func_02158630(obj);
        *(int *)(p + 8) = 0;
        func_020061E4(0x73b);
        func_021D4244(p, func_021D4BF4, 0x3c4);
        break;
    case 1:
    case 4:
        *(int *)(p + 8) = 1;
        func_020061E4(0x73b);
        func_021D4244(p, func_021D4BF4, 0x3cd);
        break;
    case 2:
        func_020061E4(0x73c);
        *(int *)(p + 8) = 2;
        func_021D4244(p, func_021D4BF4, 0x3d3);
        break;
    }
    return 1;
}
