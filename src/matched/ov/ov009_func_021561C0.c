/*
 * function: func_021561C0
 * address:  0x021561C0
 * packet:   pkt_ov009_021561C0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   func_02156CF4  0x02156CF4  thumb  ov009
 *   func_0216AE88  0x0216AE88  arm
 *   func_021567B8  0x021567B8  thumb  ov009
 *   func_021AEE14  0x021AEE14  thumb  ov013
 *   func_0216B908  0x0216B908  arm
 *   func_0216B838  0x0216B838  arm
 *   func_021AF238  0x021AF238  thumb  ov013
 *   func_02155F58  0x02155F58  thumb  ov009
 *   func_0215615C  0x0215615C  thumb  ov009
 *   func_02155C70  0x02155C70  thumb  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x754];
    int state;          /* 0x754 */
    char pad1[0x760 - 0x758];
    int f760;           /* 0x760 */
    int n;              /* 0x764 */
    int aid;            /* 0x768 */
    int f76c;           /* 0x76c */
    char pad2[0x782 - 0x770];
    short s782;         /* 0x782 */
    int cnt[3];         /* 0x784 */
    int f790;           /* 0x790 */
    u16 h794;           /* 0x794 */
    u16 h796;           /* 0x796 */
    char pad3[0x79f - 0x798];
    u8 b79f;            /* 0x79f */
} G;

extern G *d_021A8264;
void func_02156CF4(void);
void func_0216AE88(void);
void func_021567B8(void);
void func_021AEE14(int);
int func_0216B908(void);
int func_0216B838(void);
int func_021AF238(int, int);
int func_02155F58(void);
int func_0215615C(u32 idx);
void func_02155C70(void);

int func_021561C0(void)
{
    G *g;
    int i;

    func_02156CF4();
    func_0216AE88();
    func_021567B8();
    if (d_021A8264->f76c != 0) {
        int v;
        if (d_021A8264->h794 == 1 && d_021A8264->f790 == 1 && d_021A8264->h796 == 1)
            v = 0;
        else
            v = 1;
        func_021AEE14(v);
        g = d_021A8264;
        if (g->aid != func_0216B908() && g->b79f == 0 && g->s782 != 0) {
            if (func_021AF238(func_0216B908(), func_0216B838()) != 0)
                d_021A8264->aid = func_0216B908();
        }
    }
    if (d_021A8264->state == 0x14) {
        int r = func_02155F58();
        if (r == 0)
            return 0x3eb;
        return r;
    }
    if (d_021A8264->state == 0x13)
        return 0x3ec;
    if (d_021A8264->state == 9 || d_021A8264->state == 10) {
        for (i = 0; i < d_021A8264->n; i++) {
            if (d_021A8264->cnt[i]++ >= 0xf0 && d_021A8264->f760 == 0 && func_0215615C(i) != 0) {
                func_02155C70();
                break;
            }
        }
    }
    return func_02155F58();
}
