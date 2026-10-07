/*
 * file:     unit_021D4CF4_p02.c
 * unit:     yes
 * function: func_021D4F60, func_021D4FE0
 * address:  0x021D4F60
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6D8C  0x021D6D8C  arm
 *   func_021D546C  0x021D546C  arm
 *   g_021DE670     0x021DE670  data
 */
typedef unsigned char u8;

typedef unsigned int  u32;

extern void func_021D6D8C(void *p);
extern void func_021D546C(void *queue, void *data);
void func_021D4F60(u8 *p);
char *func_021D4FE0(char *p, unsigned int i);
extern u8  *g_021DE670;


void func_021D4F60(u8 *p)
{
    u32 *q;
    int i;
    int sel = 0;
    u8 *base;

    q = *(u32 **)(p + 8);
    for (i = 0; i < p[0xc]; i++) {
        *q = (*q & 0xC1FFFCFF) | 0x200;
        q += 2;
    }
    func_021D6D8C(p);
    base = g_021DE670;
    if (p >= base + 0x228)
        sel = 1;
    func_021D546C((void *)(*(u32 *)(base + sel * 0x228 + 0x224)), p);
}

/*
 * Index into the i-th 8-byte record of the table at p+8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D4FE0.c \
 *       --func func_021D4FE0 --addr 0x021D4FE0 --region ov016 --cc dsi/1.1p1 --arm
 */
char *func_021D4FE0(char *p, unsigned int i)
{
    return *(char **)(p + 8) + (i << 3);
}
