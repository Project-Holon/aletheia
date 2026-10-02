/*
 * function: func_021B8628
 * address: 0x021B8628
 * packet: pkt_ov172_021B8628
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE0D8 0x021BE0D8 thumb ov172
 *   func_021BE2F0 0x021BE2F0 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_0203EA70 0x0203EA70 arm
 *   func_021B7724 0x021B7724 thumb ov172
 *   func_021B7830 0x021B7830 thumb ov172
 *   func_021B77B8 0x021B77B8 thumb ov172
 *   func_021B77E8 0x021B77E8 thumb ov172
 *   func_0203E96C 0x0203E96C arm
 *   func_0203E9DC 0x0203E9DC arm
 *   func_021BFFC4 0x021BFFC4 arm ov172
 *   func_021B7714 0x021B7714 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char *func_021BDFDC(void *p);
extern int func_021BE0D8(void *p);
extern void func_021BE2F0(u32 *p, void *q);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern int func_0203EA70(int a);
extern void func_021B7724(void *a, char *b, int c);
extern int func_021B7830(void *a0, char *a1, int a2);
extern u32 func_021B77B8(void *p, char *q);
extern u32 func_021B77E8(void *p, char *q);
extern int func_0203E96C(unsigned int idx);
extern int func_0203E9DC(unsigned int idx);
extern int func_021BFFC4(unsigned char *data, unsigned long size, void *dst,
                         short *width, short *height, unsigned long option);
extern void func_021B7714(void *a, char *b, int c);
void func_021B8628(void *a, int b, int *t, int c)
{
    char *r;
    int x, data;
    short dims[2];
    r = func_021BDFDC(a);
    if (t[0] != 0 && t[3] != 1) {
        if (t[2] == 0 && t[1] == 1) {
            if (func_021BE0D8(a) == 0)
                func_021BE2F0((u32 *)a, t + 7);
            t[2] = 1;
        }
        switch (t[6]) {
        case 0:
        case 4:
            break;
        case 1:
            if (func_021B8740((int)a, b, 0, 0) == 1)
                t[6] = 2;
            break;
        case 2:
            if (func_0203EA70(c) == 0) {
                func_021B7724(a, r, c);
                t[6] = 3;
            }
            break;
        case 3:
            if (func_0203EA70(c) == 1) {
                x = func_021B7830(a, r, c);
                dims[1] = func_021B77B8(a, r);
                dims[0] = func_021B77E8(a, r);
                data = func_0203E96C(c);
                func_021BFFC4((unsigned char *)data, func_0203E9DC(c), (void *)x, &dims[1], &dims[0], 0);
                func_021B7714(a, r, c);
                t[6] = 1;
            }
            break;
        }
    }
}
