/*
 * function: func_021D9DC4
 * address: 0x021D9DC4
 * packet: pkt_ov119_021D9DC4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DB0A0 0x021DB0A0 thumb ov119
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_0207D658 0x0207D658 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9D60 0x021D9D60 thumb ov119
 *   d_021E7584 0x021E7584 data a4
 */

typedef struct { int a,b; } Pair;
extern const Pair d_021E7584;
typedef unsigned int   u32;
extern int func_021DB0A0(char *p);
extern void func_021E1410(void *p, int *ids, int count);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021D8E84(void *,int);
extern void func_021D9D60(char *p);
void func_021D9DC4(void *p)
{
    if (func_021DB0A0(p)) {
        Pair t = d_021E7584;
        func_021E1410(p,(int *)(&t),2);
        func_0207D658(0x04001050,0x1B,-8);
        func_021D8E84(p,(int)func_021D9D60);
    }
}
