/*
 * function: func_021E81D0
 * address:  0x021E81D0
 * packet:   pkt_ov170_021E81D0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBBC8 0x021EBBC8 thumb
 *   func_021DD314 0x021DD314 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EDAB0 0x021EDAB0 thumb
 *   func_021EDB34 0x021EDB34 thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED508 0x021ED508 thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E002C 0x021E002C thumb
 *   func_021EA1E8 0x021EA1E8 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EF68C 0x021EF68C thumb
 *
 * Four-step machine on the work word at 0xA194 for releasing a Pokemon:
 * two confirmation messages, then the release itself (box slot in place,
 * party slot with a fade), then the view is restored.
 */

extern void func_021EBBC8(unsigned char *p, int kind, int i);
extern void func_021DD314(unsigned char *p, int box, int pos);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(unsigned char *p);
extern void func_021DF040(unsigned char *p);
extern void func_021EDAB0(unsigned char *p, int box);
extern void func_021EDB34(unsigned char *p, int box);
extern void func_021EF670(char *w);
extern void func_020260E4(void *obj, unsigned char sel);
extern void func_021EE3E4(unsigned char *p, unsigned idx);
extern void func_021ED55C(unsigned char *p, int flag);
extern void func_021ED888(char *w, int a);
extern void func_021ECB20(unsigned char *p, int f, int c);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021EA1C0(unsigned char *p);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E002C(unsigned char *p);
extern void func_021EA1E8(unsigned char *p);
extern void func_021DEFEC(unsigned char *p, int b);
extern void func_021EF68C(char *w);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))
#define MODE(p) (*(int *)(*(char **)(p) + 0x24))

int func_021E81D0(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021EBBC8(p, 1, 0x18);
        STATE(p) = 0x5B;
        STEP(p)++;
        return 6;
    case 1:
        func_021EBBC8(p, 2, 0x18);
        STATE(p) = 0x5B;
        STEP(p)++;
        return 6;
    case 2:
        func_021DD314(p, p[0x14], p[0x16]);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        func_021DF040(p);
        if (p[0x16] < 0x1E) {
            func_021EDAB0(p, p[0x14]);
            func_021EDB34(p, p[0x14]);
            if (MODE(p) == 1) {
                STATE(p) = 0x2C;
            } else {
                STATE(p) = 0x11;
                func_021EF670(WORK(p));
            }
            func_020260E4(OBJ(p), p[0x16]);
            func_021EE3E4(p, p[0x16]);
            func_021ED55C(p, 1);
            func_021ED888(WORK(p), 1);
            func_021ECB20(p, 1, 0);
            func_021ED508(p, 0xE, 1);
            p[0x16] = 0xFF;
            STEP(p) = 0;
            return STATE(p);
        }
        func_021EA1C0(p);
        p[0x1A] = 1;
        func_021ECB20(p, 2, 0);
        STEP(p)++;
        return func_021E8FC0(p, func_021E002C, 0x5B);
    case 3:
        STEP(p) = 0;
        func_021EA1E8(p);
        func_021DEFEC(p, p[0x16]);
        func_020260E4(OBJ(p), p[0x16] - 0x1E);
        func_021EE3E4(p, p[0x16] - 0x1E);
        func_021ED55C(p, 1);
        p[0x16] = 0xFF;
        if (MODE(p) == 0)
            return 0x31;
        func_021ED508(p, 0xE, 1);
        func_021EF68C(WORK(p));
        return 0x1B;
    }
    return 0x5B;
}
