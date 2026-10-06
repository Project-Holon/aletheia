/*
 * function: func_021E754C
 * address: 0x021E754C
 * packet: pkt_ov170_021E754C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_021ECB60 0x021ECB60 thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021EA750 0x021EA750 thumb ov170
 *   func_021EBFEC 0x021EBFEC thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_020260F4 0x020260F4 thumb
 *   func_021EF68C 0x021EF68C thumb ov170
 */
extern void func_020061E4(unsigned se);
extern void func_021ECB60(char *w, int i, int f);
extern void func_021ED6E4(char **p, int v);
extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EA750(char *p);
extern u32 func_021EBFEC(char *p, int i);
extern void func_021DEFEC(char *p, int b);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021EF68C(char *w);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
int func_021E754C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_020061E4(0x667);
        func_021ECB60(WORK(p), **(unsigned short **)(WORK(p) + 0x60), 0);
        func_021ED6E4((char **)p, 0);
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16] - 0x1E);
        func_021EA750((char *)p);
        STEP(p)++;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) == 1)
            break;
        func_021DEFEC((char *)p, p[0x16]);
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021EF68C(WORK(p));
        return 0x46;
    }
    return 0x4A;
}
