/*
 * function: func_021EFEC0
 * address:  0x021EFEC0
 * packet:   pkt_ov031_021EFEC0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: 0x021EFF9A/0x021EFFA6 ldrh re-reads of 0x0400104A (REG_WINOUT_SUB) and 0x021EFFB8 ldr of 0x04001000 (hardware registers, SDK window inlines; twin ov018 func_0217CFE4)
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_021F01F0  0x021F01F0  thumb  ov031
 *   func_021F0250  0x021F0250  thumb  ov031
 *   func_021F0430  0x021F0430  thumb  ov031
 *   func_021F0490  0x021F0490  thumb  ov031
 *   func_021F04EC  0x021F04EC  thumb  ov031
 *   func_021F0378  0x021F0378  thumb  ov031
 *   func_02049238  0x02049238  arm
 *   PMS_DRAW_Create  0x0202DB0C  thumb
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb
 *   func_02026474  0x02026474  thumb
 *   UNION_MAIN_GetAppealNo  0x02173940  thumb  ov012
 *   func_021F09A0  0x021F09A0  thumb  ov031
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02037174  0x02037174  arm
 *   str_021F10C0   0x021F10C0  data  ov031  a1
 *   d_021F1038     0x021F1038  data  ov031  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char str_021F10C0[];
extern u8 d_021F1038[];

struct Ctx;
extern unsigned int func_02012138(const struct Ctx *);
struct PmsDraw;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021F01F0(u32 *p);
struct Obj;
extern void func_021F0250(void *p, u32 h);
extern void func_021F0430(struct Obj *p);
extern void func_021F0490(char *p, u32 heap);
extern void func_021F04EC(int *p, void *h);
extern void func_021F0378(u32 *p);
extern void func_02049238(void *h);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern u32 func_02026474(void *obj);
extern u8 UNION_MAIN_GetAppealNo(u8 *p);
extern void func_021F09A0(void *a, char *b);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02037174(void);

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)

u32 *func_021EFEC0(void *a)
{
    void *s;
    u32 *w;
    void *h;
    u8 *q;
    u32 i;
    u32 tmp;

    s = (void *)func_02012138(a);
    w = func_02030734(0x15, 0x80, 1, str_021F10C0, 0x10F);
    w[0] = (u32)a;
    h = func_020490F4(0x59, 0x15);
    func_021F01F0(w);
    func_021F0250(w, (u32)h);
    func_021F0430((struct Obj *)w);
    func_021F0490((char *)w, (u32)h);
    func_021F04EC((int *)w, h);
    func_021F0378(w);
    func_02049238(h);
    w[0x1F] = (u32)PMS_DRAW_Create(w[5], 1, w[0x10], w[0x11], 9, 3, 0x15);
    PMS_DRAW_SetNullColorPalette((void *)w[0x1F], 0);
    q = (u8 *)func_02026474(s);
    if (q != 0) {
        *((u8 *)w + 0x30) = UNION_MAIN_GetAppealNo(q);
        func_021F09A0(w, (char *)(q + 0x30E0));
        if (*((u8 *)w + 0x30) != 0) {
            for (i = 0; (i < 5) ? 1 : 0; i++) {
                if (d_021F1038[i] == *((u8 *)w + 0x30)) {
                    func_0204B6F4((struct Obj *)(*(u32 *)((u8 *)w + 0x18 + i * 4)), 1, 1);
                    break;
                }
            }
        }
    }
    func_0203D34C(0, 0x15);
    func_02037174();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    tmp = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    tmp |= 0x20;
    REG_WINOUT_SUB = (u16)tmp;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    return w;
}
