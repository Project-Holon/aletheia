/*
 * function: func_021BCBB4
 * address: 0x021BCBB4
 * packet: pkt_ov208_021BCBB4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC274 0x021BC274 thumb
 *   func_021BCC84 0x021BCC84 thumb
 *   func_021BDB08 0x021BDB08 thumb
 *   func_021BDB54 0x021BDB54 thumb
 *   func_021BC2F0 0x021BC2F0 thumb
 *   func_021BD974 0x021BD974 thumb
 *   func_021BE7A4 0x021BE7A4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021BCF18 0x021BCF18 thumb
 *   func_021BCF2C 0x021BCF2C thumb
 *   func_021BC310 0x021BC310 thumb
 *   func_021BCF3C 0x021BCF3C thumb
 * tail: 4 bytes at 0x021BCC80 are the unlabelled stub func_021BCC80 and its padding (listing extent runs to 0x021BCC84).
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Args { void *src; int f4; int f8; u16 fc; u16 fe; int f10; };
struct Ov208Main {
    u16 heap; u16 pad;
    void *disp; void *font; void *gfx; int task;
    void *f14; void *f18; void *fsm;
    void *obj; int f24; int f28;
};
struct State;
extern int func_021BC274(struct State *p, int arg);
struct Ov208Mode;
struct Ov208Slot;
extern void func_021BCC84(struct Ov208Mode *m, struct Ov208Slot *s);
struct Ov208Fade;
struct Ov208Icon;
struct PrintSys;
struct State;
extern unsigned func_021BDB08(const struct State *p);
extern unsigned func_021BDB54(const struct State *p);
extern void func_021BC2F0(char *p, int a, int b);
extern void func_021BD974(struct Ov208Fade *m);
extern void func_021BE7A4(struct Ov208Icon *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021BCF18(char *p);
extern void func_021BCF2C(char *p);
extern void func_021BC310(char *p, int v);
extern void func_021BCF3C(char *p);
int func_021BCBB4(void *unused, int *cnt, struct Ov208Args *a, struct Ov208Main *m)
{
    int done = 0;
    u32 v;
    if (*cnt <= 8)
        *cnt = *cnt + 1;
    if (func_021BC274(m->obj, (int)m->fsm) != 0) {
        if (m->f28 != 0) {
            a->f4 = m->f28;
            func_021BCC84((struct Ov208Mode *)a, (struct Ov208Slot *)m);
            m->f28 = 0;
            done = 1;
        } else {
            return 1;
        }
    }
    if (done == 0) {
        v = func_021BDB08(m->f14);
        if (v == 0)
            v = func_021BDB54(m->f14);
        func_021BC2F0(m->obj, (int)m->fsm, v);
        switch (v) {
        case 1: a->f10 = 0; break;
        case 2: a->f10 = 1; break;
        case 6: m->f28 = 1; break;
        case 7: m->f28 = 2; break;
        case 8: m->f28 = 3; break;
        case 9: m->f28 = 4; break;
        }
    }
    func_021BD974(m->f14);
    func_021BE7A4(m->f18);
    PRINTSYS_QUE_Main(m->gfx);
    func_021BCF18(m->disp);
    func_021BCF2C(m->disp);
    if (done == 0)
        func_021BC310(m->obj, (int)m->fsm);
    func_021BCF3C(m->disp);
    return 0;
}
