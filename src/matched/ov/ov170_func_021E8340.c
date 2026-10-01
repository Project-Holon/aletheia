/*
 * function: func_021E8340
 * address: 0x021E8340
 * packet: pkt_ov170_021E8340
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC9D8 0x021EC9D8 thumb ov170
 *   func_021ECA38 0x021ECA38 thumb ov170
 *   func_021DE7B4 0x021DE7B4 thumb ov170
 *   func_021ED588 0x021ED588 thumb ov170
 *   func_021EBBC8 0x021EBBC8 thumb ov170
 *   func_021E912C 0x021E912C thumb ov170
 */
extern int func_021EC9D8(char *p);
extern void func_021ECA38(char *p);
extern void func_021DE7B4(unsigned char *p);
extern void func_021ED588(unsigned char *p);
extern void func_021EBBC8(unsigned char *p, int kind, int i);
extern int func_021E912C(unsigned char *p);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define SLOT(p) (*(char **)(WORK(p) + 0xA190))
int func_021E8340(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        if (func_021EC9D8(SLOT(p)) != 0)
            break;
        func_021ECA38(SLOT(p));
        func_021DE7B4(p);
        func_021ED588(p);
        func_021EBBC8(p, 4, 0x18);
        *(int *)(p + 0x28) = 0x5C;
        STEP(p)++;
        return 6;
    case 1:
        func_021EBBC8(p, 5, 0x18);
        *(int *)(p + 0x28) = 0x5C;
        STEP(p)++;
        return 6;
    case 2:
        STEP(p) = 0;
        return func_021E912C(p);
    }
    return 0x5C;
}
