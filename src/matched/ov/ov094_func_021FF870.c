/*
 * function: func_021FF870
 * address:  0x021FF870
 * packet:   pkt_ov094_021FF870
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021FF260  0x021FF260  thumb  ov094
 *   func_02200CD0  0x02200CD0  thumb  ov094
 *   func_02200D30  0x02200D30  thumb  ov094
 *   d_0220AE7C     0x0220AE7C  data   ov094  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x520 - 4];
    int mask[4];            /* 0x520 */
    char pad530[0x540 - 0x530];
    u16 heap;               /* 0x540 */
    char pad542[0x588 - 0x542];
    u8 cnt[4][14];          /* 0x588 */
} Work;

typedef struct {
    Work *w;                /* 0x00 */
    int i;                  /* 0x04 */
    char pad08[0x0c];
    int kind;               /* 0x14 */
    char pad18[0x2c];
    int f44;                /* 0x44 */
    int f48;                /* 0x48 */
    int f4c;                /* 0x4c */
    int f50;                /* 0x50 */
} Obj;

extern const char d_0220AE7C[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern int func_021F935C(int x);
extern void func_021FF260(Work *w, int key, int flag);
extern void func_02200CD0(void);
extern void func_02200D30(void *p);

void func_021FF870(Work *w, int key, int kind, int a, int b)
{
    Obj *o;

    switch (kind) {
    case 3:
        func_021FF260(w, key, 1);
        return;
    case 4:
        func_021FF260(w, key, 0);
        return;
    case 2:
        o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, d_0220AE7C, 0x5e5);
        o->w = w;
        o->i = key;
        o->kind = kind;
        o->f44 = 0;
        o->f48 = a;
        o->f4c = b * 2;
        w->cnt[0][key]++;
        o->f50 = w->cnt[0][key];
        func_021F896C(func_02030DA8(w->owner, (void *)func_02200CD0, o, 0), func_02200D30, 2);
        w->mask[2] |= func_021F935C(key);
        return;
    }
}
