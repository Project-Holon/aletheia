/*
 * function: func_02031FE0
 * address:  0x02031FE0
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
 *   str_020A7848   0x020A7848  data
 *   func_020333F8  0x020333F8  arm
 *   func_02030734  0x02030734  arm
 *   func_02031EAC  0x02031EAC  arm
 *   func_020335E8  0x020335E8  arm
 *   func_02033410  0x02033410  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02031F9C  0x02031F9C  arm
 *   func_02033BF0  0x02033BF0  arm
 *   func_0203331C  0x0203331C  arm
 *   func_02033B68  0x02033B68  arm
 *   func_02033BAC  0x02033BAC  arm
 *   func_02081B8C  0x02081B8C  arm
 *   func_020332FC  0x020332FC  arm
 *   func_02031F94  0x02031F94  arm
 *
 * backup_system.c.  The two-copy load: read both copies of the save area
 * (func_020335E8 at func_02031EAC(self, 1) into the staging buffer self->f34
 * and at (self, 2) into a heap block from func_02030734, line 0x429), repair
 * one copy from the other when only one read failed, check both footers
 * (func_02031F9C, the mode == 1 generation test), cross-copy the footer block
 * when exactly one is bad, pick the newer good copy, then walk every record
 * checking its CRC against both copies, marking each record 0/1/2 through
 * func_0203331C and retrying with the other copy if the walk breaks.  A
 * completed walk copies the marked records back and commits the generation
 * (func_02031F94).  The two-copy twin of func_02032688
 * (docs/notes/pkt_02031FE0.c.txt holds the history from wave 11).
 *
 * Closed wave 19 by `unsigned long AB` together with the declaration order
 * AB, pa, pb, i, A, B: the long-typed A + B colours apart from the u32
 * locals (image: AB r4, B r8, A r7).  Either change alone is 13 or 22 bytes
 * out; the earlier 9-byte residue was this one register swap.  The inline
 * cnt16 on the two record-counter compares and the one-argument
 * func_020333F8 are load-bearing (wave 12); func_02030734 uses its real
 * prototype with an explicit (u16) heap.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02031FE0.c \
 *       --func func_02031FE0 --addr 0x02031FE0 --arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

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
extern const char str_020A7848[];

extern void  func_020333F8(Save *self);
static inline u16 cnt16(u8 *p){ return *(u16 *)p; }
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32   func_02031EAC(Save *self, u32 sel);
extern int func_020335E8(u32 a0, u32 a1, u32 a2, void (*a3)(void));
extern void  func_02033410(Save *self, u32 a);
extern void  func_02082A7C(u32 v, void *dst, u32 size);
extern void  func_020307B0(void *p);
extern void  func_02082A60(const void *src, void *dst, u32 size);
extern void func_02031F9C(u32 *out, void *p, void *buf, u32 sel);
extern u32   func_02033BF0(u8 *tbl);
extern void  func_0203331C(Save *self, u32 idx, u32 v);
extern u32   func_02033B68(u8 *tbl, u32 idx);
extern u32   func_02033BAC(u8 *tbl, u32 idx);
extern u16   func_02081B8C(const void *table, const void *p, u32 size);
extern u32   func_020332FC(Save *self, u32 idx);
extern void  func_02031F94(Save *self, u32 gen);

int func_02031FE0(Save *self, u32 heap, u32 mode, u32 gen)
{
    u32 pairB[2];
    u32 pairA[2];
    u8 *bufs[2];
    u32 gens[2];
    u32 ids[2];
    u8 *h;
    u16 *tbl;
    u8 *cur;
    u32 k;
    u8 *buf;
    int okA;
    int okB;
    unsigned long AB;
    u8 *pa;
    u8 *pb;
    u32 i;
    u32 A;
    u32 B;
    u32 off;

    func_020333F8(self);
    h = self->f34;
    buf = func_02030734((u16)heap, self->f30, 0, str_020A7848, 0x429);
    okA = func_020335E8(func_02031EAC(self, 1), (u32)h, self->f30, (void (*)(void))g_02146994->unk204);
    okB = func_020335E8(func_02031EAC(self, 2), (u32)buf, self->f30, (void (*)(void))g_02146994->unk204);
    if (okA == 0 && okB == 0) {
        func_02033410(self, 1);
        func_02082A7C(0, h, self->f30);
        func_020307B0(buf);
        return 0;
    }
    if (okA == 1 && okB == 0) {
        func_02033410(self, 2);
        func_02082A60(h, buf, self->f30);
    } else if (okA == 0 && okB == 1) {
        func_02033410(self, 1);
        func_02082A60(buf, h, self->f30);
    }

    func_02031F9C(pairA, self, h, 0);
    func_02031F9C(pairB, self, buf, 1);
    if (mode == 1) {
        if (pairA[1] != gen)
            pairA[0] = 2;
        if (pairB[1] != gen)
            pairB[0] = 2;
    }

    if (pairA[0] == 0) {
        if (pairB[0] != 0) {
        func_0203331C(self, func_02033BF0(self->f2c), 2);
        func_0203331C(self, func_02033BF0(self->f2c) + 1, 2);
        off = self->f30 - 0x10 - self->f140;
        func_02082A60(h + off, buf + off, self->f140 + 0x10);
        }
    } else if (pairB[0] == 0) {
        if (pairA[0] != 0) {
        func_0203331C(self, func_02033BF0(self->f2c), 1);
        func_0203331C(self, func_02033BF0(self->f2c) + 1, 1);
        off = self->f30 - 0x10 - self->f140;
        func_02082A60(buf + off, h + off, self->f140 + 0x10);
        }
    } else {
        if (pairA[0] == 1 || pairB[0] == 1) {
            func_02033410(self, 1);
            func_020307B0(buf);
            return 3;
        }
        func_02033410(self, 1);
        func_020307B0(buf);
        return 0;
    }

    if (pairA[0] == 0
        && ((pairA[1] == 0 && pairB[1] == 0xFFFFFFFF) || pairA[1] >= pairB[1]
            || pairB[0] != 0)) {
        bufs[0] = h;
        bufs[1] = buf;
        ids[0] = 1;
        ids[1] = 2;
        gens[0] = pairA[1];
        gens[1] = pairB[1];
    } else {
        ids[0] = 2;
        bufs[0] = buf;
        bufs[1] = h;
        ids[1] = 1;
        gens[0] = pairB[1];
        gens[1] = pairA[1];
    }

    for (k = 0; k < 2; k++) {
        off = self->f30 - 0x10 - self->f140;
        cur = bufs[k];
        tbl = (u16 *)(bufs[k] + off);
        for (i = 0; i < func_02033BF0(self->f2c); i++) {
            A = func_02033B68(self->f2c, i);
            B = func_02033BAC(self->f2c, i);
            AB = A + B;
            pa = h + AB;
            pb = buf + AB;
            func_0203331C(self, i, 0);
            if (*(u16 *)(pa + 2) != tbl[i]
                && *(u16 *)(pb + 2) != tbl[i])
                break;
            if (*(u16 *)(pa + 2) == tbl[i]) {
                if (*(u16 *)(pa + 2) != func_02081B8C((u8 *)g_02146994 + 4, h + A, B))
                    func_0203331C(self, i, 1);
            } else {
                func_0203331C(self, i, 1);
            }
            if (*(u16 *)(pb + 2) == tbl[i]) {
                if (*(u16 *)(pb + 2) != func_02081B8C((u8 *)g_02146994 + 4, buf + A, B)) {
                    if (func_020332FC(self, i) == 1)
                        break;
                    func_0203331C(self, i, 2);
                }
            } else {
                if (func_020332FC(self, i) == 1)
                    break;
                func_0203331C(self, i, 2);
            }
            if (func_020332FC(self, i) == 0) {
                if (cnt16(pa) != *(u16 *)(bufs[k] + AB))
                    func_0203331C(self, i, 1);
                if (cnt16(pb) != *(u16 *)(bufs[k] + AB)) {
                    if (func_020332FC(self, i) == 1)
                        break;
                    func_0203331C(self, i, 2);
                }
            }
        }
        if (i >= func_02033BF0(self->f2c)) {
            u32 id = ids[k ^ 1];

            func_0203331C(self, func_02033BF0(self->f2c) + 1, id);
            func_0203331C(self, func_02033BF0(self->f2c), id);
            break;
        }
    }
    if (k >= 2) {
        func_02033410(self, 1);
        func_020307B0(buf);
        return 3;
    }

    off = self->f30 - 0x10 - self->f140;
    func_02082A60(bufs[k] + off, h + off, self->f140 + 0x10);
    for (i = 0; i < func_02033BF0(self->f2c); i++) {
        if (func_020332FC(self, i) == 1) {
            A = func_02033B68(self->f2c, i);
            B = func_02033BAC(self->f2c, i);
            func_02082A60(buf + A, h + A, B + 4);
        }
    }
    func_02031F94(self, gens[k]);
    func_020307B0(buf);
    for (i = 0; i < func_02033BF0(self->f2c); i++)
        func_020332FC(self, i);
    return 1;
}
