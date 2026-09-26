/*
 * function: func_02701AA0
 * address:  0x02701AA0
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   func_02087988  0x02087988  code twl a2
 *   func_0208799C  0x0208799C  code twl a2
 *   func_02701FE8  0x02701FE8  code twl a2
 *   func_027001F0  0x027001F0  code twl a2
 */

typedef unsigned int u32;
typedef signed int s32;

extern u32 data_02732FC8[];
extern u32 data_02733FC8[];
extern void func_02087988(void);
extern void func_0208799C(void);
extern void func_02701FE8(u32);
extern void func_027001F0(void);

void func_02701AA0(s32 a0) {
    u32 *p = data_02733FC8;
    u32 r6;
    u32 v1A0, v1A4, v1A8;

    func_02087988();

    if (a0 < -4 || a0 > 30) {
        if (a0 == -5) {
            r6 = 1;
        } else if (a0 == 0xFF) {
            r6 = 6;
        } else {
            r6 = 7;
        }
    } else {
        v1A0 = p[0x1A0/4];
        v1A4 = p[0x1A4/4];
        v1A8 = p[0x1A8/4];
        r6 = 0;

        switch (a0) {
        case -4:
            if (v1A0 & 1) p[0x140/4] = v1A8;
            if (v1A0 & 2) p[0x180/4] = v1A8;
            break;
        case -3:
            if (v1A0 & 1) p[0x144/4] = v1A8;
            if (v1A0 & 2) p[0x184/4] = v1A8;
            break;
        default:
            break;
        }
    }

    func_02701FE8(r6);
    if (r6 == 6) {
        func_027001F0();
    }
}
