/*
 * function: sub_02034768
 * address:  0x02034768
 * packet:   pkt_02034734
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020808F4  0x020808F4  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_0207D534  0x0207D534  arm
 *   TEXTPRINT_Init  0x0204E130  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_Clear   0x02043B5C  arm
 *   unk_021469AC   0x021469AC  data
 *
 * Bring up the panic screen.  The assert path (sub_02034734 forwards here)
 * has to draw text after the game has already lost whatever video state it
 * was running, so this tears the display down to a known configuration and
 * rebuilds exactly one text layer on it:
 *
 *   - interrupts are masked (REG_IME latched and cleared), every layer is
 *     switched off in DISPCNT, and the VRAM/engine teardown helpers run;
 *   - POWCNT's LCD-swap bit is cleared so the screen this draws on is the
 *     one the user is looking at;
 *   - blend (0x04000050) and master brightness (0x0400006C) are neutralised;
 *   - DISPCNT is reduced to graphics mode 0 with BG0 alone enabled
 *     (~0xE000, then (x & ~0x1F00) | 0x100, then ~0x38000000 and
 *     ~0x07000000 for the VRAM-block and OBJ-mapping fields);
 *   - BG0CNT keeps only priority and mosaic and takes character base 4
 *     ((x & 0x43) | 0x10), then drops its priority to 0 (x & ~3), and BG0's
 *     scroll pair at 0x04000010 is zeroed as one 32-bit write;
 *   - the first two BG palette entries become white (0x7FFF) and the panic
 *     text colour (0x60E1);
 *   - a 0x20x8 4bpp character buffer is allocated, published at
 *     unk_021469AC, and cleared to pixel value 2.
 *
 * Two shapes here are compiler idiom rather than source:
 *
 *   0x7FFF is not an ARM rotated immediate, so it is rematerialised as
 *   `rsb r3, r4, #0x8000` off the register that already holds 1
 *   (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-\
 *   unless-an-argument-shares-it.md, read with 1 in place of 0).
 *
 *   The palette base pooled at 0x05000002 rather than 0x05000000 is the
 *   pool-base-masked-by-the-load's-reach idiom: the constant materialised
 *   is the address of the *first* access, and the second entry is reached
 *   at +2 from it.
 *
 * The two bitfield stores at +0xA are one register value, not two
 * read-modify-writes: the dead first `strb` is eliminated but the `and
 * r3, r3, #0xff` truncation between the statements survives, which is what
 * says these are two separate 4-bit field assignments and not a single
 * merged `(x & ~0xFF) | 0x21`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034768.c \
 *       --func sub_02034768 --addr 0x02034768 --cc 1.1p1 --arm
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;

typedef volatile u16       vu16;
typedef volatile u32       vu32;

#define REG_DISPCNT  (*(vu32 *)0x04000000)
#define REG_BG0CNT   (*(vu16 *)0x04000008)
#define REG_BG0OFS   (*(vu32 *)0x04000010)
#define REG_BLDCNT   (*(vu16 *)0x04000050)
#define REG_IME      (*(vu16 *)0x04000208)
#define REG_POWCNT   (*(vu16 *)0x04000304)

#define BG_PLTT_1    (*(vu16 *)0x05000002)
#define BG_PLTT_2    (*(vu16 *)0x05000004)

struct Console {
    void *chars;   /* 0x0 */
    u16   x;       /* 0x4 */
    u16   y;       /* 0x6 */
    u8    unk8;    /* 0x8 */
    u8    unk9;    /* 0x9 */
    u8    fg : 4;  /* 0xA */
    u8    bg : 4;
    u8    unkB;    /* 0xB */
};

extern struct Console unk_021469AC;

extern int func_020808F4(void);
extern void  func_0207FDCC(u32 a);
struct Bmp;
struct CharBuf;
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void  TEXTPRINT_Init(u32 a);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Clear(struct CharBuf *buf, u8 value);

void sub_02034768(void)
{
    u16 ime;
    void *chars;

    ime = REG_IME;
    REG_IME = 0;

    REG_DISPCNT = REG_DISPCNT & ~0x1f00;
    func_020808F4();
    func_0207FDCC(1);

    REG_POWCNT = REG_POWCNT & ~0x8000;
    func_0207D4B0(1, 0, 0);

    REG_BLDCNT = 0;
    func_0207D534((volatile u16 *)0x0400006c, 0);

    REG_DISPCNT = REG_DISPCNT & ~0xe000;
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x100;
    REG_DISPCNT = REG_DISPCNT & ~0x38000000;
    REG_DISPCNT = REG_DISPCNT & ~0x07000000;

    REG_BG0CNT = (REG_BG0CNT & 0x43) | 0x10;
    REG_BG0CNT = REG_BG0CNT & ~3;
    REG_BG0OFS = 0;

    BG_PLTT_1 = 0x7fff;
    BG_PLTT_2 = 0x60e1;

    TEXTPRINT_Init(0);

    chars = BMP_Create(0x20, 8, 0x20, 0);
    unk_021469AC.chars = chars;
    unk_021469AC.x = 0;
    unk_021469AC.y = 0;
    unk_021469AC.unk8 = 1;
    unk_021469AC.unk9 = 1;
    unk_021469AC.fg = 1;
    unk_021469AC.bg = 2;
    unk_021469AC.unkB = 0;

    BMP_Clear(chars, 2);
}
