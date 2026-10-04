/*
 * function: func_02174AE0
 * address:  0x02174AE0
 * packet:   pkt_ov011_02174AE0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_02174E14  0x02174E14  thumb ov011
 */

typedef unsigned int   u32;
struct BigObj;
u32 func_02026478(void *obj);
void *func_02012B38(const struct BigObj *p);
int func_02014484(int a);
typedef unsigned char  u8;
void func_02174E14(u8 *p, int a);

void func_02174AE0(unsigned char *p)
{
    int r;

    r = func_02014484((int)func_02012B38((const struct BigObj *)func_02026478((void *)(*(int *)(p + 4)))));
    switch (r) {
    case 0:
        if (((unsigned)(*(unsigned short *)(p + 0x86) << 17) >> 26) == 2) {
            func_02174E14(p, 0);
        }
        break;
    case 1:
        if (((unsigned)(*(unsigned short *)(p + 0x86) << 17) >> 26) == 0) {
            func_02174E14(p, 2);
        }
        break;
    }
}
