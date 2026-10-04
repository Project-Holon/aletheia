/*
 * function: func_021B81DC
 * address: 0x021B81DC
 * packet: pkt_ov093_021B81DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAACC 0x021BAACC thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B6994 0x021B6994 thumb ov093
 *   func_021BAB10 0x021BAB10 thumb ov093
 *   func_021CD960 0x021CD960 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;
extern int func_021B6818(int *);
extern int func_021D4270(void);
struct Copy24;
struct QB;
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern int func_021CD6F0(void *, void *, int, int, u16, u8, u8, int, u8, void *, u16);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, int c, u8 d);
extern void func_021BAACC(int, int, int, u8, u8);
extern int func_021B8B9C(u8 *, u8);
extern int func_021B6994(u8 *, u8);
extern void func_021BAB10(int, u8, int);
extern void func_021CD960(int, int);
int func_021B81DC(u8 *p)
{
    u8 idx;
    u8 *q;
    int t;
    u32 i;
    idx = p[0x46c];
    q = *(u8 **)p;
    t = func_021B6818((int *)q);
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        *(int *)(p + 8) = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, *(u16 *)(p + 0x468));
        ((int *)(p + 0x10))[idx] = func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), idx, 1, 0, t, 0, p + 0x3f0, *(u16 *)(p + 0x468));
        func_021BAA94((char *)(*(int *)(p + 8)), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, 1);
        for (i = 0; i < p[0x46b]; i++) {
            if (i != idx)
                func_021BAACC(*(int *)(p + 8), q[0x20], *(int *)(q + 0x1c), i, 1);
        }
    } else {
        ((int *)(p + 0x10))[idx] = func_021CD6F0(p, p + 0xc8, q[0x20], *(int *)(q + 0x1c), idx, 1, 0, t, 0, p + 0x3f0, *(u16 *)(p + 0x468));
        *(int *)(p + 0xc) = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, *(u16 *)(p + 0x468));
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10(*(int *)(p + 0xc), i, func_021B6994(p, i));
        }
        func_021CD960(((int *)(p + 0x10))[idx], *(int *)(p + 0xc));
    }
    return 1;
}
