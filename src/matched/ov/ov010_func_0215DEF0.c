/*
 * function: func_0215DEF0
 * address:  0x0215DEF0
 * packet:   pkt_ov010_0215DEF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_02172724     0x02172724  data
 */

typedef unsigned int u32;

typedef struct { u32 f0; } Ctx;

extern void *func_020124E4(void);
extern void func_020120F4(void);
extern void func_0201210C(void *);
extern void func_020120B4(void *, int, const char *, u32);
extern int func_020120F0(void *);
extern void func_020307B0(void *);
extern const char d_02172724[];

int func_0215DEF0(void *a, u32 *st, u32 *c)
{
    void *h = func_020124E4();
    func_020120F4();
    func_0201210C(h);
    switch (*st) {
    case 0:
        (*st)++;
        break;
    case 1:
        (*st)++;
        break;
    case 2:
        (*st)++;
        break;
    case 3:
        func_020120B4(h, -1, d_02172724, *c);
        (*st)++;
        break;
    case 4:
        if (func_020120F0(h) != 0)
            break;
        (*st)++;
        break;
    case 5:
        (*st)++;
        break;
    case 6:
        func_020307B0(((void **)*c)[1]);
        func_020307B0((void *)*c);
        return 1;
    }
    return 0;
}
