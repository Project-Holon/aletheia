/*
 * function: func_02186EB8
 * address:  0x02186EB8
 * packet:   pkt_ov020_02186EB8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127C4  0x020127C4  thumb
 *   func_020127F0  0x020127F0  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_021869D0  0x021869D0  thumb  ov020
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *func_0215A5F4(void *a);
void *func_0215A5E4(void *a);
void func_020127C4(void *a);
int func_020127F0(int a0);
struct BigObj;
void *func_02012934(const struct BigObj *p);
u16 *func_02159AE8(void *a, void *b);
u32 func_0201AA18(void *a);
u16 func_021869D0(char *p);
struct RtcDate;
void func_0203F4E4(struct RtcDate *date);
void *func_0201AB28(void *a, u32 i);
u32 func_02017E1C(void *p, u32 id, u32 v);

int func_02186EB8(void *a0, void *a1)
{
    void *s;
    void *w;
    void *b;
    u16 *f0;
    u16 *f1;
    u16 *f2;
    u32 n;
    int key;
    int d[4];
    u32 i;
    void *e;
    int v5, v92, v93, v94, v96, v4c, v8f, v90, v91;

    func_0215A5F4(a1);
    s = func_0215A5E4(a1);
    func_020127C4(s);
    w = (void *)func_020127F0((int)s);
    b = func_02012934(s);
    f0 = func_02159AE8(a0, a1);
    f1 = func_02159AE8(a0, a1);
    f2 = func_02159AE8(a0, a1);
    n = func_0201AA18(b);
    key = func_021869D0(w);
    func_0203F4E4((struct RtcDate *)d);
    *f0 = 0;
    *f1 = 0;
    *f2 = 0xFFFF;
    for (i = 0; i < n; i++) {
        e = func_0201AB28(b, i);
        v5 = func_02017E1C(e, 5, 0);
        v92 = func_02017E1C(e, 0x92, 0);
        v93 = func_02017E1C(e, 0x93, 0);
        v94 = func_02017E1C(e, 0x94, 0);
        v96 = func_02017E1C(e, 0x96, 0);
        v4c = func_02017E1C(e, 0x4c, 0);
        v8f = func_02017E1C(e, 0x8f, 0);
        v90 = func_02017E1C(e, 0x90, 0);
        v91 = func_02017E1C(e, 0x91, 0);
        if (v5 == key && v4c == 0 && v96 == 0x33 && v8f + v91 + v90 == 0) {
            *f0 = 1;
            if (*f2 == 0xFFFF)
                *f2 = i;
            if (v92 == d[0] && v93 == d[1] && v94 == d[2]) {
                *f1 = 1;
                *f2 = i;
            }
        }
    }
    return 0;
}
