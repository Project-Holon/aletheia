/*
 * function: FRAME_LIST_StepRowDrag
 * address:  0x021B8C4C
 * packet:   pkt_ov067_021B8C4C
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   FRAME_LIST_StartFlick  0x021B8EA0  thumb  ov067
 *   FRAME_LIST_StartJump  0x021B8DF0  thumb  ov067
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u32 f0;
    u32 f4;
};

struct S {
    u8 _0[0x1c];
    struct Ent *f1c;
    u8 _20[0x2c - 0x20];
    void *f2c;
    u8 _30[0x34 - 0x30];
    int f34;
    u8 _38[0x4e - 0x38];
    u16 f4e;
    u8 _50[0x54 - 0x50];
    u32 f54;
    u8 _58[0x70 - 0x58];
    u32 f70;
    u8 _74[0x84 - 0x74];
    u8 f84;
    s8 f85;
    u8 f86 : 5;
    u8 f86_5 : 1;
    u8 f86_6 : 2;
    u8 f87;
    u8 f88;
    u8 _89[0x8c - 0x89];
    u32 f8c;
    u32 f90;
};

struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int TOUCHPANEL_HitCont(const void *p);
extern int FRAME_LIST_StartFlick(struct S *s);
extern int FRAME_LIST_StartJump(struct S *s, int a1);

int FRAME_LIST_StepRowDrag(struct S *s)
{
    int r;

    if (PRINTSYS_QUE_IsFinished((const struct PrintSys *)s->f34) == 0)
        return 1;
    r = TOUCHPANEL_HitCont(s->f2c);
    switch (s->f84) {
    case 0:
        if (r == -1) {
            if (s->f8c != -1 && s->f90 != -1) {
                s->f85 = s->f90 - s->f8c;
                s->f86 = 0;
                if (FRAME_LIST_StartFlick(s) == 1)
                    break;
            }
            s->f70 = 0;
            s->f4e = 0;
            return 0;
        }
        if (s->f1c[r].f4 != 0) {
            if (s->f8c != -1 && s->f90 != -1) {
                s->f85 = s->f90 - s->f8c;
                s->f86 = 0;
                if (FRAME_LIST_StartFlick(s) == 1)
                    break;
            }
            s->f70 = 0;
            s->f4e = 0;
            return 0;
        }
        if (s->f87 != r) {
            s->f88 = r;
            s->f85 = s->f87 - r;
            s->f86 = 0;
            s->f84 = 1;
        }
        s->f90 = s->f8c;
        s->f8c = s->f54;
        break;
    case 1:
        if (r == -1) {
            s->f84 = 0;
            return FRAME_LIST_StartFlick(s);
        }
        if (s->f1c[r].f4 != 0) {
            s->f84 = 0;
            return FRAME_LIST_StartFlick(s);
        }
        if (s->f86 == 5) {
            s->f86 = 0;
            s->f84 = 0;
            if (FRAME_LIST_StartJump(s, r) == 1)
                s->f86_5 = 1;
        } else {
            s->f88 = r;
            s->f8c = s->f54;
            s->f86++;
        }
        break;
    }
    return 1;
}
