/*
 * function: TOUCHBAR_PollButtonPress
 * address:  0x021B6934
 * packet:   pkt_ov067_021B6934
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   KEY_GetTrg  0x020362DC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct S {
    u32 f00;
    u32 f04;
    u32 f08;
    void (*f0c)(struct S *);
    u8 pad10[0x1c - 0x10];
    s16 f1c;
    s16 f1e;
    u8 pad20[0x30 - 0x20];
    u32 f30;
} S;

struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);

int TOUCHBAR_PollButtonPress(S *p)
{
    u32 x;
    u32 y;
    int hit = 0;

    if (CLACT_GetActorDrawEnable((struct Obj *)p->f00) & p->f04) {
        if (TOUCHPANEL_GetPointTrg(&x, &y)) {
            if (x - p->f1c <= 0x18 && y - p->f1e <= 0x18) {
                hit = 1;
                UI_SetInputMode(1);
            }
        }
        if (p->f30 != 0 && (KEY_GetTrg() & p->f30)) {
            UI_SetInputMode(0);
            hit = 1;
        }
        if (hit) {
            p->f0c(p);
            return 1;
        }
    }
    return 0;
}
