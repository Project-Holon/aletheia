/*
 * function: func_0216F830
 * address:  0x0216F830
 * packet:   pkt_ov010_0216F830
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Counts how many of five save-data conditions hold.
 *
 * Byte-correct (MATCH*, the 136-byte extent includes two bytes of pad).
 * Blocker: the call to 0x02012EF0 has no witness. 0x02012EF0 is an
 * unlabelled ARM9 Thumb thunk (`ldr r0, [r0]; ldr r3, =0x020071CD;
 * movs r1, #0x3a; bx r3`, i.e. `return func_020071CC(*p, 0x3A);`, with the
 * sibling at 0x02012F00 passing 0x3B) whose only caller is this function.
 * Matching that thunk (ARM9 territory) or seeding its start closes this file.
 *
 * symbols:
 *   func_02012EF0  0x02012EF0  thumb
 *   func_02012F44  0x02012F44  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200A73C  0x0200A73C  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef signed int     s32;
struct Big;
struct Blk1AC;
struct Rec1B0;
extern void *func_02012EF0(void **p);
extern void *func_02012F44(void *save);
extern void *func_020127B8(void *save);
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, int id);
extern void *func_0200CA1C(void *save);
extern int func_0200D298(void *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern u32 func_0200A73C(struct Big *p);
extern u16 func_0200BDF8(struct Rec1B0 *p);
extern u16 func_0200BDFC(struct Rec1B0 *p);

int func_0216F830(void *save)
{
    int n;
    void *a;
    void *b;
    void *c;

    n = 0;
    a = func_02012EF0(save);
    b = func_02012F44(save);
    c = func_020127B8(save);
    if (func_020142E8((void *)func_0201296C(save), 0x960))
        n++;
    if (func_0200D298(func_0200CA1C(save)))
        n++;
    if (func_0200DBA0(a, 7, 0) && func_0200DBA0(a, 8, 0))
        n++;
    if (func_0200A73C(b))
        n++;
    if (func_0200BDF8(c) >= 30 && func_0200BDFC(c) >= 30)
        n++;
    return n;
}
