/*
 * file:     btlv_effvm_p64.c
 * unit:     yes
 * function: func_021FF6B0, func_021FF730
 * address:  0x021FF6B0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02015CC4  0x02015CC4  thumb
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_0220074C  0x0220074C  thumb  ov094
 *   func_02200B48  0x02200B48  thumb  ov094
 *   func_02200BD4  0x02200BD4  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015CF8  0x02015CF8  thumb
 *   func_02200C0C  0x02200C0C  thumb  ov094
 *   func_02200C98  0x02200C98  thumb  ov094
 */
typedef unsigned char u8;

typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad510[0x518 - 0x510];
    int mask[4];            /* 0x518 */
    char pad528[0x550 - 0x528];
    u8 cnt[4][14];          /* 0x550 */
} Work;

typedef unsigned int   u32;

extern int func_022019F4(char *p, int key);
extern void func_02015CC4(void *p, u32 *out);
extern int func_021F935C(int x);
extern void func_0220074C(Work *w, int i, int kind, VecFx32 *p, VecFx32 *q, int n,
                          int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50);
extern void func_02200B48(void);
extern void func_02200BD4(void *p);
extern void func_02015CF8(void *p, u32 *out);
extern void func_02200C0C(void);
extern void func_02200C98(void *p);
void func_021FF6B0(Work *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c);
void func_021FF730(Work *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c);


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Byte-correct; MATCH blocked on one unlabelled ARM9 Thumb leaf (Ilias's; no
 * witness outside the range): func_02015CC4 (copies three words from +0x128).
 * Verified C (match.py one, no --region, --thumb, EXACT):
 *   typedef unsigned int u32;
 *   void func_02015CC4(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x128);
 *       out[1] = *(u32 *)((char *)p + 0x12C);
 *       out[2] = *(u32 *)((char *)p + 0x130);
 *   }
 * Twin of matched func_021FF630.
 */
void func_021FF6B0(Work *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    func_02015CC4(w->e[idx].h, (u32 *)(&cur));
    w->cnt[2][i]++;
    func_0220074C(w, i, kind, &cur, q, n, f48, f4c, (void *)func_02200B48, func_02200BD4, 0, w->cnt[2][i]);
    w->mask[3] |= func_021F935C(i);
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Byte-correct; MATCH blocked on one unlabelled ARM9 Thumb leaf (Ilias's; no
 * witness outside the range): func_02015CF8 (copies three words from +0xF8).
 * Verified C (match.py one, no --region, --thumb, EXACT):
 *   typedef unsigned int u32;
 *   void func_02015CF8(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0xF8);
 *       out[1] = *(u32 *)((char *)p + 0xFC);
 *       out[2] = *(u32 *)((char *)p + 0x100);
 *   }
 * Twin of matched func_021FF630.
 */
void func_021FF730(Work *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    func_02015CF8(w->e[idx].h, (u32 *)(&cur));
    w->cnt[3][i]++;
    func_0220074C(w, i, kind, &cur, q, n, f48, f4c, (void *)func_02200C0C, func_02200C98, 1, w->cnt[3][i]);
    w->mask[1] |= func_021F935C(i);
}
