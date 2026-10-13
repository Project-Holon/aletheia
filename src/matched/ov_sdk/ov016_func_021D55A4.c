/*
 * function: DWCi_EFFlFade
 * address:  0x021D55A4
 * packet:   pkt_ov016_021D55A4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G2x_SetBlendBrightness_          0x0207D658  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   sEffectTable3                       0x021DAA6C  data
 *   MemEffect                        0x021DE67C  data
 *   taskFade                         0x021D566C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(effect.o), symbol DWCi_EFFlFade (name, prototype
 * and both struct layouts from the vendor object DWARF). Callee of procInit/endScene1
 * (sceneoptmovconf*). 0x021DAA6C is DWARF @12142, the signed-char table the object
 * copies into its stack BRIGHT[4]; taskFade reads its own copies at 0x021DAA64/68.
 *
 * The blend window select is written with the CALL in both arms, not as an `addr`
 * local. Selecting into a local (`addr = lcd == 1 ? A : B;`, ternary or if/else)
 * if-converts to `ldr`/`ldrne` and lands 192 bytes; repeating the call in both arms
 * makes the front end keep the `bne` / `ldr` / `b` / `ldr` join for the window word
 * while still tail-merging the single `bl`, which is the object's 200 bytes. Same
 * lever as the matched taskFade at 0x021D566C.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef _Bool bool;

typedef struct { s8 b[4]; } S4;

struct tagEFFPRM {
    void *task;
    s16 conut;
    u16 frame;
    u8 kind;
    bool flag;
};

struct tagMEMEFFECT {
    struct tagEFFPRM param[2];
};

extern void G2x_SetBlendBrightness_(unsigned long addr, int plane, int brightness);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work,
                           unsigned char prio);
extern struct tagMEMEFFECT *MemEffect;
extern S4 sEffectTable3;

static void taskFade(void *task, void *work);

bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame)
{
    S4 BRIGHT = sEffectTable3;
    struct tagEFFPRM *prm;
    bool ok;

    if (lcd == 1)
        prm = &MemEffect->param[0];
    else
        prm = &MemEffect->param[1];
    if (prm->flag)
        return 0;
    if (lcd == 1)
        G2x_SetBlendBrightness_(0x04001050, plane, BRIGHT.b[kind]);
    else
        G2x_SetBlendBrightness_(0x04000050, plane, BRIGHT.b[kind]);
    ok = 1;
    prm->task = DWCi_TSKlForm(ok, taskFade, prm, 0xc8);
    prm->conut = 0;
    prm->kind = kind;
    prm->frame = frame;
    prm->flag = ok;
    return ok;
}
