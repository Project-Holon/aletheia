/*
 * function: func_02032688
 * address:  0x02032688
 * packet:   pkt_02031FE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146994     0x02146994  data
 *   func_020333F8  0x020333F8  arm
 *   func_02031EAC  0x02031EAC  arm
 *   func_020335E8  0x020335E8  arm
 *   func_02033410  0x02033410  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02031F9C  0x02031F9C  arm
 *   func_0203331C  0x0203331C  arm
 *   func_02081B8C  0x02081B8C  arm
 *   func_02033BF0  0x02033BF0  arm
 *   func_02033B68  0x02033B68  arm
 *   func_02033BAC  0x02033BAC  arm
 *   func_02031F94  0x02031F94  arm
 *   func_020332FC  0x020332FC  arm
 *
 * backup_system.c.  The one-copy load: read copy 1 of the save area into the
 * staging buffer self->f34 (func_020335E8 at func_02031EAC(self, 1)); on a
 * read failure clear the marks (func_02033410(self, 1)), zero the buffer and
 * answer 0.  Otherwise check the footer (func_02031F9C; with mode == 1 a
 * generation other than arg3 counts as bad), answer 3 or 0 for a bad footer,
 * then walk every record checking its stored CRC against the footer's CRC
 * table and recomputing it (func_02081B8C over g_02146994's inline table),
 * marking each record 0, or 1 on a recompute mismatch.  A completed walk marks
 * the two trailing slots 1 and commits the footer's generation
 * (func_02031F94); a broken one answers 3.  The one-copy twin of
 * func_02031FE0 (docs/notes/pkt_02031FE0.c.txt holds the history).
 *
 * Closed wave 12 by the callee's real argument list: func_020333F8 takes
 * self ONLY (src/matched/func_020333F8.c forwards self->+0x138/+0x13C to a
 * clear and never reads its other parameters).  Passing (self, mode, arg3)
 * as every earlier draft did left four instructions of the first read's
 * argument setup in the wrong order (10 bytes).  The redundant re-test
 * `if (crc == base[i])` after the `!= ... goto done` is in the image (a dead
 * second compare), and `u8 *h` first / `u32 i` last in the declarations set
 * the loop's registers.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02032688.c \
 *       --func func_02032688 --addr 0x02032688 --arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Save Save;
struct Save {
    u8   pad00[0x2c];
    u8  *f2c;
    u32  f30;
    u8  *f34;
    u8   pad38[0x108];
    u32  f140;
};

struct SaveMain { u8 pad000[0x204]; u32 unk204; };
extern struct SaveMain *g_02146994;

extern void func_020333F8(Save *self);
extern u32  func_02031EAC(Save *self, int a);
extern int  func_020335E8(u32 a, void *b, u32 c, u32 d);
extern void func_02033410(Save *self, int a);
extern void func_02082A7C(int a, void *b, u32 c);
extern void func_02031F9C(u32 *out, void *p, void *buf, u32 sel);
extern void func_0203331C(Save *self, u32 idx, int flag);
extern int  func_02081B8C(u8 *p, u8 *a, u32 b);
extern u32  func_02033BF0(u8 *p);
extern u32  func_02033B68(u8 *p, u32 idx);
extern u32  func_02033BAC(u8 *p, u32 idx);
extern void func_02031F94(Save *self, int a);
extern void func_020332FC(Save *self, u32 idx);

int func_02032688(Save *self, int mode, int arg3)
{
    u32 pair[2];
    u8 *h;
    u32 j, A, B;
    int saved;
    u8 *base;
    u8 *gp;
    u32 i;

    func_020333F8(self);
    h = self->f34;
    if (func_020335E8(func_02031EAC(self, 1), h, self->f30,
                      g_02146994->unk204) == 0) {
        func_02033410(self, 1);
        func_02082A7C(0, h, self->f30);
        return 0;
    }
    func_02031F9C(pair, self, h, 0);
    if (mode == 1) {
        if ((s32)pair[1] != arg3)
            pair[0] = 2;
    }
    if (pair[0] != 0) {
        if (pair[0] == 1) {
            func_02033410(self, 1);
            return 3;
        }
        func_02033410(self, 1);
        return 0;
    }

    base = h + (self->f30 - 0x10 - self->f140);
    saved = (s32)pair[1];
    for (i = 0; i < func_02033BF0(self->f2c); i++) {
        A = func_02033B68(self->f2c, i);
        B = func_02033BAC(self->f2c, i);
        gp = h + (A + B);
        func_0203331C(self, i, 0);
        if (*(u16 *)(gp + 2) != *(u16 *)(base + i * 2))
            goto done;
        if (*(u16 *)(gp + 2) == *(u16 *)(base + i * 2)) {
            if (*(u16 *)(gp + 2) != func_02081B8C((u8 *)g_02146994 + 4, h + A, B)) {
                func_0203331C(self, i, 1);
                goto done;
            }
        }
    }
done:
    if (i >= func_02033BF0(self->f2c)) {
        func_0203331C(self, func_02033BF0(self->f2c) + 1, 1);
        func_0203331C(self, func_02033BF0(self->f2c), 1);
    } else {
        func_02033410(self, 1);
        return 3;
    }
    func_02031F94(self, saved);
    for (j = 0; j < func_02033BF0(self->f2c); j++)
        func_020332FC(self, j);
    return 1;
}
