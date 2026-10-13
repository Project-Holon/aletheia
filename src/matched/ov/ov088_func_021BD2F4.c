/*
 * function: func_021BD2F4
 * address:  0x021BD2F4
 * packet:   pkt_ov088_021BD2F4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BACKUP_SYSTEM_IsFlashBusy  0x02031E70  arm
 *   SAVE_CONTROL_MainSave  0x02007168  thumb
 *   func_02007214  0x02007214  thumb
 *   func_0200721C  0x0200721C  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    void *h;
    u8 s4;
    u8 s5;
    u8 s6;
    u8 s7;
    u32 v8;
    u32 vC;
} St;

extern int BACKUP_SYSTEM_IsFlashBusy(void);
struct Sub02007168;
extern u32 SAVE_CONTROL_MainSave(struct Sub02007168 *p);
extern void func_02007214(void *, u32);
extern void func_0200721C(void *, u32);

u32 func_021BD2F4(St *p)
{
    u32 r;

    if (p->s7 == 1)
        return 2;
    switch (p->s4) {
    case 1:
        if (p->s6 == 1 && BACKUP_SYSTEM_IsFlashBusy() == 0) {
            p->s5 = p->s4;
            p->s4 = 2;
            return 0;
        }
        r = SAVE_CONTROL_MainSave(p->h);
        if (r - 2 <= 1) {
            p->s4 = 3;
            func_02007214(p->h, p->v8);
            func_0200721C(p->h, p->vC);
        }
        return r;
    case 2:
        if (p->s6 == 0)
            p->s4 = p->s5;
        return 0;
    case 3:
        return 2;
    }
    return 0;
}
