/*
 * function: BTLV_MCSS_AddTrainer
 * address:  0x021FF088
 * packet:   pkt_ov094_021FF088
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_Add  0x020159C8  thumb
 *   BTLV_MCSS_MakeAddWorkFromTrainer  0x022006A0  thumb  ov094
 *   BTLV_MCSS_ApplySlotScale  0x022006B4  thumb  ov094
 *   BTLV_MCSS_CalcSlotPosition  0x022018A8  thumb  ov094
 */
typedef unsigned int u32;
typedef struct {
    void *h;
    char pad04[0x44];
    int k48;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;
typedef struct {
    int pad00;
    void *obj;
    Entry e[14];
} Work;
typedef struct { u32 x, y, z; } Vec;

struct Obj;
struct Rec;
struct Sub150;
extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void BTLV_MCSS_MakeAddWorkFromTrainer(void *p, void *out, int key);
extern void BTLV_MCSS_ApplySlotScale(Work *w, int key);
extern void BTLV_MCSS_CalcSlotPosition(void *obj, void *out, int idx);

void BTLV_MCSS_AddTrainer(Work *w, void *src, int key)
{
    int i;
    char buf[0x24];
    Vec v;

    for (i = 0; i < 14; i++) {
        if (w->e[i].h == 0)
            break;
    }
    if (key < 14 && i < 14) {
        w->e[i].flip = 1;
        w->e[i].k48 = key;
        BTLV_MCSS_MakeAddWorkFromTrainer(src, buf, key);
        BTLV_MCSS_CalcSlotPosition(w, &v, key);
        w->e[i].h = MCSS_Add(w->obj, v.x, v.y, v.z, (const struct Sub150 *)buf);
        BTLV_MCSS_ApplySlotScale(w, key);
    }
}
