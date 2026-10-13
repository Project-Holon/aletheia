/*
 * function: ENCEFF_StartScreenTexEffectFlash
 * address: 0x021F5260
 * packet: pkt_ov075_021F5260
 * region: ov075
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   ENCEFF_ScreenTexFlashEventMain 0x021F536C thumb ov075
 */
typedef unsigned int u32;
typedef struct Vec { int x,y,z; } Vec;
struct Desc;
struct Obj;
struct Work;
extern struct Desc *func_020122C0(void *, void *, void *, u32);
extern void *func_020124E8(struct Obj *);
extern void MI_CpuFill8(void *,int,u32);
extern int ENCEFF_ScreenTexFlashEventMain(void *, int *, struct Work *);
void *ENCEFF_StartScreenTexEffectFlash(void *a, Vec *src, u32 b, u32 c) {
    struct Desc *h;
    char *w;
    h = func_020122C0(a,0,(void *)ENCEFF_ScreenTexFlashEventMain,48);
    w = func_020124E8((struct Obj *)h);
    MI_CpuFill8(w,0,48);
    *(Vec *)(w+24) = *src;
    *(u32 *)(w+40) = b;
    *(u32 *)(w+44) = c;
    return h;
}
