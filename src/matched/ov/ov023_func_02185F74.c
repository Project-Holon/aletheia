/*
 * function: func_02185F74
 * address:  0x02185F74
 * packet:   pkt_ov023_02185F74
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_02186170  0x02186170  thumb  ov023
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_02008500  0x02008500  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w;
    u8 f;
} Ent;

typedef struct {
    char pad0[0xc];
    u32 f0c;
    char pad10[0x8];
    u32 arr18[5];
    char pad2c[0x6c];
    u32 arr98[5];
    char padac[0x58];
    u32 win[7];
    char pad120[0xc];
    Ent ent[7];
    u32 f164;
    u32 f168;
    u32 f16c;
    u32 f170;
    char pad174[0x54];
    Ent e1c8[5];
} W;

extern u16 func_02039338(void);
extern int  func_02186170(W *p);
extern void func_0204B3DC(u32 a, int b);
extern void func_0201C6EC(u32 a);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_02043AF4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02008500(u32 a, u32 b);
extern void func_0201C724(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02045334(u32 a);
extern void func_02045374(u32 a);
extern u32  func_02045730(u32 a);
extern void func_020409B4(u32 a);

void func_02185F74(u32 *win, u16 color, W *p)
{
    int sel;
    int i;
    u32 w;
    u32 t;

    sel = func_02039338();
    if (!func_02186170(p))
        return;
    for (i = 0; i < 5; i++) {
        if (p->e1c8[i].w == 0)
            func_0204B3DC(p->arr98[i], 0);
        else
            func_0204B3DC(p->arr98[i], 1);
    }
    func_0201C6EC(p->f164);
    for (i = 0; i < 5; i++)
        func_02043AF4((u32)func_02045770((struct Descriptor *)win[i]), 0, 0, 0x50, 0x10, 0);
    for (i = 0; i < 5; i++) {
        if (p->e1c8[i].w != 0) {
            func_02008500(p->e1c8[i].w, p->arr18[i]);
            if (sel == i) {
                t = p->f164;
                func_0201C724(t, (u32)func_02045770((struct Descriptor *)p->ent[i].w), 0, 0, p->arr18[i], p->f0c, 0xc80);
                p->ent[i].f = 1;
            } else {
                t = p->f164;
                func_0201C724(t, (u32)func_02045770((struct Descriptor *)p->ent[i].w), 0, 0, p->arr18[i], p->f0c, color);
                p->ent[i].f = 1;
            }
        }
        w = win[i];
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
    }
}
