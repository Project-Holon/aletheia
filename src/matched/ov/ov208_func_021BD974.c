/*
 * function: func_021BD974
 * address: 0x021BD974
 * packet: pkt_ov208_021BD974
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BDD48 0x021BDD48 thumb
 *   func_021BD358 0x021BD358 thumb
 *   func_021BD23C 0x021BD23C thumb
 *   func_021BDFDC 0x021BDFDC thumb
 *   func_021BE20C 0x021BE20C thumb
 *   func_021BE6A8 0x021BE6A8 thumb
 *   d_021C8388 0x021C8388 data a4
 *   d_021C8384 0x021C8384 data a1
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
struct Ov208Fade {
    int f0; int f4; int state; int fc; int mode; int f14; int f18; int f1c;
    int idx;
    u8 cnt;
    char pad25[0x0b];
    void *f30; int f34; char pad38[0x7c];
    s16 pos;
};
extern const int d_021C8388[];
extern const u8 d_021C8384[];
extern int func_02040804(int a);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021BDD48(struct Ov208Fade *m, int pos);
extern void func_021BD358(char *p, int v);
extern void func_021BD23C(char *p);
extern void func_021BDFDC(struct Ov208Fade *m);
extern void func_021BE20C(struct Ov208Fade *m);
extern void func_021BE6A8(struct Ov208Fade *m);
void func_021BD974(struct Ov208Fade *m)
{
    int v;
    switch (m->state) {
    case 0:
    case 2:
        break;
    case 1:
        if (m->cnt == 0) {
            if (func_02040804(1) >= 0) {
                func_02041EE4(1, 3, 0);
                m->pos = 0;
                func_021BDD48(m, m->pos);
                m->state = 2;
                if (m->f34 != 0)
                    func_021BD358(m->f30, 1);
                break;
            }
            func_02041EE4(1, 4, d_021C8388[m->idx]);
            m->pos = m->pos - (s16)d_021C8388[m->idx];
            func_021BDD48(m, m->pos);
            m->cnt = d_021C8384[m->idx];
        } else {
            m->cnt--;
        }
        break;
    case 3:
        if (m->cnt == 0) {
            if (func_02040804(1) <= -24) {
                func_02041EE4(1, 3, -24);
                m->pos = 24;
                func_021BDD48(m, m->pos);
                m->state = 0;
            } else {
                func_02041EE4(1, 5, d_021C8388[m->idx]);
                m->pos = m->pos + (s16)d_021C8388[m->idx];
                func_021BDD48(m, m->pos);
                m->cnt = d_021C8384[m->idx];
            }
        } else {
            m->cnt--;
        }
        break;
    }
    func_021BD23C(m->f30);
    if (m->mode == 0) {
        func_021BDFDC(m);
        func_021BE20C(m);
    } else if (m->mode == 2) {
        func_021BE6A8(m);
    }
}
