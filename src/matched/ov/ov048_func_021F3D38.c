/*
 * function: func_021F3D38
 * address:  0x021F3D38
 * packet:   pkt_ov048_021F3D38
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F472C  0x021F472C  thumb
 *   func_021F3A50  0x021F3A50  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0201433C  0x0201433C  thumb
 */

typedef unsigned int   u32;
struct BigObj;
extern void func_021F472C(unsigned char *p, const void *q);
extern void func_021F3A50(char *p, int a, int b);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_0201433C(char *a0, int a1);

void func_021F3D38(int *p, int a, int b, int *c)
{
    func_021F472C((unsigned char *)p[5], (const void *)a);
    if (b == 8)
        func_021F3A50((char *)p, b, c[1]);
    else
        func_021F3A50((char *)p, b, 0);
    if (b == 8 && c[2] == 1) {
        func_0201433C((char *)func_0201296C((const struct BigObj *)p[2]), (unsigned short)c[1]);
    }
}
