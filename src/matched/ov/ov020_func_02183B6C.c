/*
 * function: func_02183B6C
 * address: 0x02183B6C
 * packet: pkt_ov020_02183B6C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02183C34 0x02183C34 thumb ov020
 *   func_02183F5C 0x02183F5C thumb ov020
 *   func_02183D68 0x02183D68 thumb ov020
 */
extern void *func_02183C34(void *owner, void *input);
extern int func_02183F5C(int a, unsigned char *p);
extern int func_02183D68(int a);
void func_02183B6C(int a, int *p)
{
    switch (*p) {
    case 0: func_02183C34((void *)a, p); break;
    case 1: func_02183F5C(a, (unsigned char *)p); break;
    case 2: func_02183D68(a); break;
    }
}
