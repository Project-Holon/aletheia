/*
 * function: func_021B1B08
 * address:  0x021B1B08
 * packet:   pkt_ov021_021B1B08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_021B1E74  0x021B1E74  thumb  ov021
 *   func_0216DE54  0x0216DE54  thumb  ov010
 *   func_0219BBA4  0x0219BBA4  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021B1A44  0x021B1A44  thumb  ov021
 *   d_021EE71C     0x021EE71C  data  a1
 */

typedef unsigned char u8;
typedef unsigned int u32;

void *func_0215A5F4(void *p);
void *func_0215A5EC(void *b);
void *func_02158F90(void *a);
void *func_021B1E74(void *b);
void *func_0216DE54(void *map, u32 kind);
void *func_0219BBA4(void *a);
void func_0216D9A0(void *map);
int func_0216D454(void *a);
void func_0216DB04(void *a);
int func_0216DA5C(void *a);
void func_020113D0(int a, int (*f)(int, int));
int func_021B1A44(int a, int b);
extern u8 d_021EE71C;

int func_021B1B08(int a, void *b)
{
    void *r4;
    void *r6;
    void *r7;

    r4 = func_0215A5F4(b);
    r6 = func_0215A5EC(b);
    r4 = func_02158F90(r4);
    r7 = func_021B1E74(b);
    func_0216DE54(r6, 0x30);
    b = func_0219BBA4(r4);
    d_021EE71C = 0;
    func_0216D9A0(r6);
    if (func_0216D454(r7) == 0) {
        d_021EE71C |= 1;
        func_0216DB04(r7);
    }
    if (r4 != 0) {
        if (func_0216DA5C(r4) == 1) {
            d_021EE71C |= 4;
            func_0216DB04(r4);
        }
    }
    if (b != 0) {
        if (func_0216DA5C(b) == 1) {
            d_021EE71C |= 8;
            func_0216DB04(b);
        }
    }
    func_020113D0(a, func_021B1A44);
    return 1;
}
