/*
 * function: func_022004BC
 * address:  0x022004BC
 * packet:   pkt_ov094_022004BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * MATCH: bytes identical; blocked on 0x02015C60, an unfiled unlabelled ARM9
 * Thumb leaf (Ilias's) with no witness outside this range. Verified C for it
 * (EXACT, `one --thumb`, no --region, cc 1.1p1, -O4,p; packet pkt_02015C60,
 * 64 B extent, out-direction twin of func_02015C78):
 *
 *   typedef unsigned int u32;
 *   void func_02015C60(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x11C);
 *       out[1] = *(u32 *)((char *)p + 0x120);
 *       out[2] = *(u32 *)((char *)p + 0x124);
 *   }
 *
 * symbols:
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015C60  0x02015C60  thumb
 *   func_02015C78  0x02015C78  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_022018A8  0x022018A8  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    u32 flags;              /* 0x4c */
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_022019F4(Work *w, int key);
extern void func_022018A8(Work *w, Vec *out, int key);
extern void func_02015C30(void *h, Vec *out);
extern void func_02015C60(void *h, Vec *out);
extern void func_02015C48(void *h, Vec *in);
extern void func_02015C78(void *h, Vec *in);
extern void func_02015EA0(void *h);

void func_022004BC(Work *w, int key)
{
    Vec want;
    Vec cur;
    Vec off;
    int i = func_022019F4(w, key);

    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    func_022018A8(w, &want, key);
    func_02015C30(w->e[i].h, &cur);
    func_02015C60(w->e[i].h, &off);
    w->e[i].flags &= ~0x40;
    if (want.x == cur.x && want.y == cur.y && want.z == cur.z
        && off.x == 0 && off.y == 0 && off.z == 0)
        return;
    w->e[i].flags |= 0x40;
    off.x = 0;
    off.y = 0;
    off.z = 0;
    func_02015C48(w->e[i].h, &want);
    func_02015C78(w->e[i].h, &off);
    func_02015EA0(w->e[i].h);
}
