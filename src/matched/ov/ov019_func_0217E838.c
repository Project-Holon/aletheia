/*
 * function: func_0217E838
 * address:  0x0217E838
 * packet:   pkt_ov019_0217E838
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217F22C  0x0217F22C  thumb  ov019
 *   func_0217F268  0x0217F268  thumb  ov019
 *   func_0217F24C  0x0217F24C  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 */

typedef unsigned char u8;

int func_0217BB20(u8 *w);
typedef unsigned short u16;
typedef unsigned int   u32;
void func_0217F074(void *p);
void func_0217F210(u8 *w, void *a, int msg);
u32 func_0217F1EC(u8 *p);
void func_0217F22C(u8 *w, void *a);
int func_0217F268(u8 *w, int *flag);
void func_0217F24C(u8 *w);
int func_0217B8E4(u8 *w, int v);
void *func_02188CB4(u8 *p);
void *func_021A3074(u8 *p);
int func_0216D3CC(void *h);
void func_0216D410(void *a0, u16 a1);
int func_0216D454(void *h);
int func_0216D480(char *p);

int func_0217E838(u8 *w, void *obj, void *a2, u8 *state)
{
    void *h;
    int flag;

    h = func_021A3074(func_02188CB4(a2));
    if (func_0217BB20(w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        func_0217F210(w, a2, 0x14e);
        (*state)++;
        break;
    case 1:
        if (func_0217F1EC(w) != 0) {
            func_0217F22C(w, a2);
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F268(w, &flag) == 1) {
            func_0217F24C(w);
            if (flag == 0) {
                *state = 3;
            } else {
                func_0217B8E4(w, 0x32);
                return 1;
            }
        }
        break;
    case 3:
        if (func_0216D3CC(h) == 1) {
            func_0216D410(h, 8);
            (*state)++;
        }
        break;
    case 4:
        if (func_0216D454(h) == 1) {
            func_0216D480(h);
            func_0217B8E4(w, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}
