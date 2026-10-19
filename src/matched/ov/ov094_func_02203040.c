/*
 * function: BTLV_INPUT_StepFingerDemo
 * address:  0x02203040
 * packet:   pkt_ov094_02203040
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220A598     0x0220A598  data   a4
 *   BTLV_FINGER_CURSOR_Create  0x02209A7C  thumb  ov094
 *   BTLV_FINGER_CURSOR_Start  0x02209B60  thumb  ov094
 *   BTLV_FINGER_CURSOR_IsActive  0x02209C2C  thumb  ov094
 *   BTLV_INPUT_PlaySelectSe  0x02206B30  thumb  ov094
 */
typedef unsigned short u16;

typedef struct Main {
    unsigned char pad00[0x60];
    int f60;
    int f64;
    unsigned int f0b : 1;
    unsigned int st : 3;
    unsigned int pad4 : 11;
    unsigned int mode : 2;
    unsigned int pad17 : 6;
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int top : 1;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main;

typedef struct Pair {
    int x;
    int y;
} Pair;

typedef struct Tbl {
    Pair p[3];
} Tbl;

extern const Tbl d_0220A598;
extern int BTLV_FINGER_CURSOR_Create(int a, int b, int c);
extern int BTLV_FINGER_CURSOR_Start(int h, int x, int y, int k, int m, int n);
extern int BTLV_FINGER_CURSOR_IsActive(int h);
extern void BTLV_INPUT_PlaySelectSe(char *p);

int BTLV_INPUT_StepFingerDemo(Main *m)
{
    int r = 0;
    Tbl t;

    switch (m->a) {
    case 0:
        t = d_0220A598;
        if (m->f60 == 0)
            m->f60 = BTLV_FINGER_CURSOR_Create(m->f64, 0xb, m->h240);
        if (BTLV_FINGER_CURSOR_Start(m->f60, t.p[m->b].x, t.p[m->b].y, 2, 7, 0x10) != 0) {
            m->a = m->a + 1;
            m->b = m->b + 1;
        }
        break;
    case 1:
        r = BTLV_FINGER_CURSOR_IsActive(m->f60);
        if (r == 1)
            BTLV_INPUT_PlaySelectSe((char *)m);
        break;
    }
    return r;
}
