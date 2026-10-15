/*
 * function: DWCi_FNTlFormBgEx
 * address:  0x021D5A58
 * packet:   pkt_ov016_021D5A58
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes: EXACT.  Two passes: const-qualifying the three read-only tables
 *        (`extern const u16 sFontTable2[]/sFontTable3[]/sFontTable1[]`) collapsed
 *        the +D0..+0104 argument-setup residue (33 differing bytes -> 10).
 *        The last residue was the +00AC..+00B4 field-run order: image stores
 *        `str r5,[r5,#0x18]` (cv->self) before `add r0,r0,r4,lsl #3` /
 *        `str r0,[r5,#0x1c]` (cv->font).  Writing the source self-first put
 *        cv->self in place but recoloured the block (g into r1, the constant
 *        1 into r0), 21 bytes.  Binding the loaded global pointer to a named
 *        local -- `char *base = gFontWork;` before `cv->self = cv;`, then
 *        `cv->font = base + font * 8;` -- keeps the self store first and the
 *        add base in r0.  See
 *        docs/idioms/a-named-local-for-the-loaded-global-base-settles-a-field-store-run.md.
 *
 * sdk:      DWCi_FNTlFormBgEx (libdwcutil.TWL.HYB.a font.o)
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm    ov016
 *   func_02068FC4  0x02068FC4  arm
 *   func_0207DF94  0x0207DF94  arm
 *   G2_GetBG0ScrPtr  0x0207DF60  arm
 *   func_02069078  0x02069078  arm
 *   DWCi_FNTlClear  0x021D5F14  arm    ov016
 *   DWCi_TSKlForm  0x021D7680  arm    ov016
 *   func_021D5BC0  0x021D5BC0  arm    ov016
 *   gFontWork     0x021DE680  data
 *   sFontTable3     0x021DAA76  data
 *   sFontTable2     0x021DAA74  data
 *   sFontTable1     0x021DAA70  data
 */

typedef unsigned short u16;

struct canvas {
    char pad0[0x18];
    struct canvas *self;
    void *font;
    int f20;
    int f24;
    void *buf;
    void *task;
};

extern char *gFontWork;
extern const u16 sFontTable2[];
extern const u16 sFontTable3[];
extern const u16 sFontTable1[];

extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern void func_02068FC4(int a, int b, int c, int d, int e);
extern void *func_0207DF94(void);
extern void *G2_GetBG0ScrPtr(void);
extern void func_02069078(void *scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, int scnWidth, int charNo, int cplt);
extern void DWCi_FNTlClear(void *c, int col);
extern void *DWCi_TSKlForm(int kind, void (*f)(void *), void *w, unsigned char prio);
extern void func_021D5BC0(void *task, void *work);

void *DWCi_FNTlFormBgEx(int lcd, int font)
{
    struct canvas *cv;
    void *scr;
    u16 w, h, chr;

    h = sFontTable3[lcd * 2];
    w = sFontTable2[lcd * 2];
    cv = (struct canvas *)(gFontWork + 0x610) + lcd;
    cv->buf = DWCi_HEAPlAllocEx(w * h * 32, 32);
    if (lcd == 1) {
        *(volatile u16 *)0x04001008 &= 0xFFBF;
        *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & 0x43) | 0xC00;
    } else {
        *(volatile u16 *)0x04000008 &= 0xFFBF;
        *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & 0x43) | 0xC00;
    }
    func_02068FC4((int)cv, (int)cv->buf, w, h, 4);
    char *base = gFontWork;
    cv->self = cv;
    cv->font = base + font * 8;
    cv->f20 = 1;
    cv->f24 = 1;
    if (lcd == 1)
        scr = func_0207DF94();
    else
        scr = G2_GetBG0ScrPtr();
    chr = sFontTable1[lcd];
    func_02069078(scr, w, h, 0, 0, 0x20, chr, 0xF);
    DWCi_FNTlClear(cv, 0);
    cv->task = DWCi_TSKlForm(1, (void (*)(void *))func_021D5BC0, gFontWork + 0x67C + lcd, 0xC8);
    return cv;
}
