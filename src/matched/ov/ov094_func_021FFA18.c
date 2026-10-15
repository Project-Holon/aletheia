/*
 * function: BTLV_MCSS_StartShakeTask
 * address: 0x021FFA18
 * packet: pkt_ov094_021FFA18
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the 4/5 kind test is an unsigned range check; individual equality tests cost two bytes.
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   BTLV_EFFECT_GetBitMask 0x021F935C thumb ov094
 *   BTLV_MCSS_ShakeTaskMain 0x02200E1C thumb ov094
 *   BTLV_MCSS_ShakeTaskEnd 0x02201098 thumb ov094
 *   gBtlvMcssSourceFileName 0x0220AE7C data ov094 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    void *owner;
    char pad04[0x514 - 4];
    int mask;
    char pad518[0x540 - 0x518];
    u16 heap;
    u8 cnt[14];
} Work;
typedef struct {
    Work *w;
    int key, kind, direction, f10, f14, f18, f1c, f20, f24;
    int f28, f2c, f30, f34, f38;
} Obj;
extern const char gBtlvMcssSourceFileName[];
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern int BTLV_EFFECT_GetBitMask(int x);
extern void BTLV_MCSS_ShakeTaskMain(void *task, char *q);
extern void BTLV_MCSS_ShakeTaskEnd(void *p);
void BTLV_MCSS_StartShakeTask(Work *w, Obj *s)
{
    Obj *o = GFL_HEAP_Alloc((u16)((w->heap & 0x7fff) | 0x8000), 0x3c, 0, gBtlvMcssSourceFileName, 0x627);
    o->w = w;
    o->key = s->key;
    o->kind = s->kind;
    o->direction = s->direction;
    o->f10 = s->f10;
    o->f14 = s->f14;
    o->f18 = s->f18;
    o->f1c = s->f1c;
    o->f20 = s->f20;
    o->f24 = s->f24;
    o->f30 = 0;
    o->f34 = 0;
    if (o->key & 1) {
        if ((o->kind != 0 && o->kind != 1 && (unsigned)(o->kind - 4) > 1)
            || (s->direction != 2 && s->direction != 3))
            o->direction ^= 1;
    }
    o->f28 = (o->kind & 1) ? 0x10000 : 0;
    o->f2c = 0x10000 / s->f18;
    w->cnt[o->key]++;
    o->f38 = w->cnt[o->key];
    BTLV_EFFECT_RegisterTask(func_02030DA8(w->owner, (void *)BTLV_MCSS_ShakeTaskMain, o, 0), BTLV_MCSS_ShakeTaskEnd, 2);
    w->mask |= BTLV_EFFECT_GetBitMask(o->key);
}
