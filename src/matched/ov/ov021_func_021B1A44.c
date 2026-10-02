/*
 * function: func_021B1A44
 * address:  0x021B1A44
 * packet:   pkt_ov021_021B1A44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_021B1E74  0x021B1E74  thumb  ov021
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216DE54  0x0216DE54  thumb  ov010
 *   func_0219BBA4  0x0219BBA4  thumb  ov021
 *   d_021EE71C     0x021EE71C  data  a1
 */

typedef unsigned char u8;

void *func_0215A5F4(void *p);
int func_02158F90(int a);
int func_021B1E74(int b);
int func_0215A5EC(int b);
int func_0216D454(int a);
void func_0216DAF8(int a);
int func_0216DA5C(int a);
int func_0216DE54(int a, int b);
int func_0219BBA4(int a);
extern u8 d_021EE71C;

int func_021B1A44(int a, int b)
{
    int r5;
    int r6;
    int r7;

    r5 = func_02158F90(func_0215A5F4((void *)b));
    r6 = func_021B1E74(b);
    r7 = func_0215A5EC(b);
    if (d_021EE71C & 1) {
        if (func_0216D454(r6) == 1) {
            func_0216DAF8(r6);
            d_021EE71C &= 0xfe;
        }
    }
    if (d_021EE71C & 4) {
        if (func_0216DA5C(r5) == 0) {
            func_0216DAF8(r5);
            d_021EE71C &= 0xfb;
        }
    }
    if (d_021EE71C & 2) {
        r6 = func_0216DE54(r7, 0x30);
        if (func_0216DA5C(r6) == 0) {
            func_0216DAF8(r6);
            d_021EE71C &= 0xfd;
        }
    }
    if (d_021EE71C & 8) {
        r5 = func_0219BBA4(r5);
        if (r5 == 0) {
            d_021EE71C &= 0xf7;
        } else if (func_0216DA5C(r5) == 0) {
            func_0216DAF8(r5);
            d_021EE71C &= 0xf7;
        }
    }
    if (d_021EE71C == 0) {
        return 1;
    }
    return 0;
}
