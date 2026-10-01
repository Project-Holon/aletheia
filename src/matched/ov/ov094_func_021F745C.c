/*
 * function: func_021F745C
 * address: 0x021F745C
 * packet: pkt_ov094_021F745C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021B8FE4 0x021B8FE4 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B9000 0x021B9000 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8714 0x021B8714 thumb ov093
 *   func_021F73F0 0x021F73F0 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int w[4]; } Q;
extern int func_021B86C8(u8 *);
extern int func_021B8FE4(u8 *);
extern u8 func_021B8FF4(u8 *);
extern int func_021B9000(u8 *);
extern u16 func_021BA020(char *, int);
extern u8 func_021B904C(void *, int);
extern u32 func_021B8588(void *);
extern void *func_021B86B8(void ***);
extern char *func_021B8714(char **);
extern void *func_021F73F0(int, int, Q *, int, u16 *, int, int, u16);

void *func_021F745C(u8 *p, int a, u16 heap)
{
    u16 h[4];
    unsigned int i;
    int side, idx, other;
    int mode, type;
    Q *q;
    for (i = 0; i < 4; i++) h[i] = 0;
    if (func_021B86C8(p) == 1) {
        side = func_021B8FE4(p);
        idx = func_021B8FF4(p);
        other = func_021B9000(p);
        h[side * 2] = func_021BA020((char *)p, idx);
        if (other != 4) h[(side ^ 1) * 2] = func_021BA020((char *)p, other);
        h[1] = func_021BA020((char *)p, func_021B904C(p, 0));
        h[3] = func_021BA020((char *)p, func_021B904C(p, 1));
    } else {
        h[0] = func_021BA020((char *)p, func_021B8FF4(p));
        h[1] = func_021BA020((char *)p, func_021B904C(p, 0));
        h[2] = 0;
        h[3] = 0;
    }
    mode = func_021B8588(p);
    type = (int)func_021B86B8((void ***)p);
    q = (Q *)func_021B8714((char **)p);
    return func_021F73F0(mode, type, q, func_021B86C8(p), h, (int)p, a, heap);
}
