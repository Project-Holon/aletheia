/*
 * function: func_021EFEC0
 * address:  0x021EFEC0
 * packet:   pkt_ov035_021EFEC0
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFEC0 0x021EFEC0 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F0678    0x021F0678 data ov035 a1
 *   func_02012138 0x02012138 thumb
 *   func_021EFF78 0x021EFF78 thumb ov035
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0201214C 0x0201214C thumb
 *   func_021EFF3C 0x021EFF3C thumb ov035
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021F0678[];
extern int func_02012138(int);
extern void func_021EFF78(char *p, int a1);
extern int func_0202EB44(void);
extern int func_0201214C(int);
extern void func_021EFF3C(void *, int);

void *func_021EFEC0(int a0, int a1, int a2)
{
    char *p = (char *)func_02030734(a2, 0x50, 1, d_021F0678, 0x12D);
    *(int *)(p + 4) = a1;
    *(int *)(p + 8) = func_02012138(a1);
    *(int *)(p + 0xC) = a0;
    *(unsigned short *)p = a2;
    func_021EFF78(p, a2);
    if (func_0202EB44() == 0)
        *(unsigned short *)(p + 0x48) = 2;
    else if (func_0201214C(a1) == 1)
        *(unsigned short *)(p + 0x48) = 1;
    else
        *(unsigned short *)(p + 0x48) = 0;
    func_021EFF3C(p, 1);
    return p;
}
