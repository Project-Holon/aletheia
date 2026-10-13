/*
 * function: func_02201408
 * address:  0x02201408
 * packet:   pkt_ov094_02201408
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: the slot test written as char-pointer arithmetic (p + k * 0x5c + 0x30)
 * swaps the row and base registers in the case-0 loop; indexing a 0x5c-byte
 * Slot struct array evaluates the row first, as the original does.
 *
 * symbols:
 *   d_0220A0C8     0x0220A0C8  data
 *   d_0220A0B0     0x0220A0B0  data
 *   d_0220A0E0     0x0220A0E0  data
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   _ll_mul        0x0209C054  arm
 *   func_021F86A4  0x021F86A4  thumb  ov094
 *   func_021F6AA8  0x021F6AA8  thumb  ov094
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_021FF4C0  0x021FF4C0  thumb  ov094
 *   func_022018A8  0x022018A8  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   BTLV_GAUGE_HideSlot  0x022089BC  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    int v[2][3];
} Tab6;

typedef struct {
    int v[2][2][3];
} Tab12;

typedef struct {
    char pad00[0x30];
    int busy;           /* 0x30 */
    char pad34[0x1c];
    int target;         /* 0x50 */
    char pad54[0x08];
} Slot;

typedef struct {
    char *p;            /* 0x00 */
    u32 state : 31;     /* 0x04 */
    u32 sound : 1;
    int idx;            /* 0x08 */
    int dir;            /* 0x0c */
    int ang[3];         /* 0x10 */
    int cnt;            /* 0x1c */
    int step;           /* 0x20 */
} Work;

extern const Tab6 d_0220A0C8;
extern const Tab6 d_0220A0B0;
extern const Tab12 d_0220A0E0;
extern const s16 FX_SinCosTable_[];

extern int func_021F86A4(void);
extern void func_021F6AA8(int p, int i, int j, int a, int b);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern void GFL_USE_StopSeSlot(int a);
extern int func_021FFD9C(char *p, int key);
extern void func_021FF4C0(char *p, int key, int b, Vec *v, int d, int e, int f);
extern void func_022018A8(char *p, Vec *out, int key);
extern int func_022019F4(char *p, int key);
extern int func_021F86B4(void);
extern void BTLV_GAUGE_HideSlot(char *p, int i);
extern void func_021F89BC(void *task);

#define MUL(a, b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

void func_02201408(void *task, Work *w)
{
    Tab6 keys = d_0220A0C8;
    Tab6 angs = d_0220A0B0;
    Tab12 tgt = d_0220A0E0;
    Vec v;
    Vec pos;
    int idx[3];
    int i;
    int step;

    switch (w->state) {
    case 0:
        for (i = 0; i < 3; i++) {
            if (((Slot *)w->p)[keys.v[w->idx][i]].busy != 0)
                break;
        }
        if (i != 3)
            return;
        for (i = 0; i < 3; i++)
            w->ang[i] = angs.v[w->idx][i];
        step = (w->dir == 0) ? 0x1000 : -0x1000;
        func_021F6AA8(func_021F86A4(), w->idx, 0, step, 0x3c);
        w->step = (w->dir == 0) ? 0x16c : -0x16c;
        w->cnt = 0x3c;
        if (w->sound)
            GFL_USE_PlaySeInSlot((void *)0x6ca, 2);
        w->state++;
        return;
    case 1:
        for (i = 0; i < 3; i++) {
            if (func_021FFD9C(w->p, keys.v[w->idx][i])) {
                v.x = MUL(FX_SinCosTable_[((u16)w->ang[i] >> 4) * 2], 0x5000);
                v.y = 0x666;
                v.z = (w->idx == 0) ? 0xc000 : -0xd000;
                v.z += MUL(FX_SinCosTable_[((u16)w->ang[i] >> 4) * 2 + 1], 0x5000);
                func_021FF4C0(w->p, keys.v[w->idx][i], 0, &v, 0, 0, 0);
            }
            w->ang[i] += w->step;
        }
        if (--w->cnt != 0)
            return;
        for (i = 0; i < 3; i++) {
            if (func_021FFD9C(w->p, keys.v[w->idx][i])) {
                func_022018A8(w->p, &pos, tgt.v[w->dir][w->idx][i]);
                func_021FF4C0(w->p, keys.v[w->idx][i], 0, &pos, 0, 0, 0);
            }
        }
        w->state++;
        return;
    case 2:
        if (*(int *)(w->p + 0x514) != 0)
            return;
        for (i = 0; i < 3; i++) {
            idx[i] = func_022019F4(w->p, keys.v[w->idx][i]);
            BTLV_GAUGE_HideSlot((char *)func_021F86B4(), keys.v[w->idx][i]);
        }
        for (i = 0; i < 3; i++) {
            if (idx[i] != -1)
                ((Slot *)w->p)[idx[i]].target = tgt.v[w->dir][w->idx][i];
        }
        if (w->sound) {
            GFL_USE_StopSeSlot(2);
            GFL_USE_PlaySeInSlot((void *)0x57a, 1);
        }
        func_021F89BC(task);
        return;
    }
}
