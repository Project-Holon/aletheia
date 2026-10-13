/*
 * function: DSP_InitProcessContext
 * address:  0x027058D8
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
typedef unsigned int u32;
typedef int s32;

typedef struct Obj150 {
    void *f0;
    u32 f4[4];
    u32 f14;
    u32 f18;
    void *f1c;
    u32 f20;
    u32 f24;
    s32 a28[8];
    s32 a48[8];
    u32 f68;
    void *h6c[19];
    void *hb8[19];
    void *h104[19];
} Obj150;
extern void func_02082BCC(void *p, s32 v, u32 n);
extern void func_0208CADC(void *dst, void *src);
void DSP_InitProcessContext(Obj150 *o, void *src)
{
    s32 i;
    func_02082BCC(o, 0, 0x150);
    o->f0 = 0;
    o->f1c = 0;
    if (src == 0) {
        src = (void *)0x02732D74;
    }
    func_0208CADC(&o->f4, src);
    o->f14 = 0;
    o->f20 = 0;
    o->f24 = 0;
    for (i = 0; i < 8; i++) {
        o->a28[i] = -1;
    }
    for (i = 0; i < 8; i++) {
        o->a48[i] = -1;
    }
    o->f68 = 0;
    for (i = 0; i < 19; i++) {
        o->h6c[i] = 0;
        o->hb8[i] = 0;
        o->h104[i] = 0;
    }
}
