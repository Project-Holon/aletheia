/*
 * function: BACKUP_SYSTEM_LoadDoubleCopy
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
 *   svsys     0x02146994  data
 *   str_020A7848   0x020A7848  data
 *   BACKUP_SYSTEM_ClearBlockAreas  0x020333F8  arm
 *   func_02030734  0x02030734  arm
 *   BACKUP_SYSTEM_GetAreaAddr  0x02031EAC  arm
 *   FLASH_ACCESS_Read  0x020335E8  arm
 *   BACKUP_SYSTEM_FillBlockAreas  0x02033410  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020307B0  0x020307B0  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   BACKUP_SYSTEM_GetFooterInfo  0x02031F9C  arm
 *   func_02033BF0  0x02033BF0  arm
 *   BACKUP_SYSTEM_SetBlockArea  0x0203331C  arm
 *   SAVEDATA_GetBlockOffset  0x02033B68  arm
 *   SAVEDATA_GetBlockSize  0x02033BAC  arm
 *   func_02081B8C  0x02081B8C  arm
 *   BACKUP_SYSTEM_GetBlockArea  0x020332FC  arm
 *   BACKUP_SYSTEM_SetSaveCount  0x02031F94  arm
 *
 * backup_system.c.  The two-copy load: read both copies of the save area
 * (FLASH_ACCESS_Read at BACKUP_SYSTEM_GetAreaAddr(self, 1) into the staging buffer self->f34
 * and at (self, 2) into a heap block from func_02030734, line 0x429), repair
 * one copy from the other when only one read failed, check both footers
 * (BACKUP_SYSTEM_GetFooterInfo, the mode == 1 generation test), cross-copy the footer block
 * when exactly one is bad, pick the newer good copy, then walk every record
 * checking its CRC against both copies, marking each record 0/1/2 through
 * BACKUP_SYSTEM_SetBlockArea and retrying with the other copy if the walk breaks.  A
 * completed walk copies the marked records back and commits the generation
 * (BACKUP_SYSTEM_SetSaveCount).  The two-copy twin of BACKUP_SYSTEM_LoadSingleCopy
 * (docs/notes/pkt_02031FE0.c.txt holds the history from wave 11).
 *
 * Closed wave 19 by `unsigned long AB` together with the declaration order
 * AB, pa, pb, i, A, B: the long-typed A + B colours apart from the u32
 * locals (image: AB r4, B r8, A r7).  Either change alone is 13 or 22 bytes
 * out; the earlier 9-byte residue was this one register swap.  The inline
 * cnt16 on the two record-counter compares and the one-argument
 * BACKUP_SYSTEM_ClearBlockAreas are load-bearing (wave 12); func_02030734 uses its real
 * prototype with an explicit (u16) heap.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BACKUP_SYSTEM_LoadDoubleCopy.c \
 *       --func BACKUP_SYSTEM_LoadDoubleCopy --addr 0x02031FE0 --arm
 */
#include "../include/Obj08817.h"
#include "../include/Obj08818.h"
#include "../include/Obj15881.h"
#include "../include/G_SaveMain.h"
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

extern struct SaveMain *svsys;
extern const char str_020A7848[];

extern void  BACKUP_SYSTEM_ClearBlockAreas(Save *self);
static inline u16 cnt16(u8 *p){ return ((struct Obj15881 *)p)->f0; }
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
struct MATHCRC16Table;
struct Obj020332FC;
struct Obj02033410;
struct Obj02033BF0;
extern u32 BACKUP_SYSTEM_GetAreaAddr(u32 *p, u32 sel);
extern int FLASH_ACCESS_Read(u32 a0, u32 a1, u32 a2, void (*a3)(void));
extern void BACKUP_SYSTEM_FillBlockAreas(struct Obj02033410 *p, u32 val);
extern void  func_02082A7C(u32 v, void *dst, u32 size);
extern u32 func_020307B0(void *p);
extern void  MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void BACKUP_SYSTEM_GetFooterInfo(u32 *out, void *p, void *buf, u32 sel);
extern u32 func_02033BF0(struct Obj02033BF0 *p);
extern void BACKUP_SYSTEM_SetBlockArea(struct Obj020332FC *p, u32 idx, u32 val);
extern u32   SAVEDATA_GetBlockOffset(u8 *tbl, u32 idx);
extern u32   SAVEDATA_GetBlockSize(u8 *tbl, u32 idx);
extern u16 func_02081B8C(struct MATHCRC16Table *table, void *data, u32 dataLength);
extern u32 BACKUP_SYSTEM_GetBlockArea(struct Obj020332FC *p, u32 idx);
extern void BACKUP_SYSTEM_SetSaveCount(int *p, int v);

int BACKUP_SYSTEM_LoadDoubleCopy(Save *self, u32 heap, u32 mode, u32 gen)
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

    BACKUP_SYSTEM_ClearBlockAreas(self);
    h = self->f34;
    buf = func_02030734((u16)heap, self->f30, 0, str_020A7848, 0x429);
    okA = FLASH_ACCESS_Read(BACKUP_SYSTEM_GetAreaAddr((u32 *)self, 1), (u32)h, self->f30, (void (*)(void))svsys->unk204);
    okB = FLASH_ACCESS_Read(BACKUP_SYSTEM_GetAreaAddr((u32 *)self, 2), (u32)buf, self->f30, (void (*)(void))svsys->unk204);
    if (okA == 0 && okB == 0) {
        BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
        func_02082A7C(0, h, self->f30);
        func_020307B0(buf);
        return 0;
    }
    if (okA == 1 && okB == 0) {
        BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 2);
        MIi_CpuCopy16(h, buf, self->f30);
    } else if (okA == 0 && okB == 1) {
        BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
        MIi_CpuCopy16(buf, h, self->f30);
    }

    BACKUP_SYSTEM_GetFooterInfo(pairA, self, h, 0);
    BACKUP_SYSTEM_GetFooterInfo(pairB, self, buf, 1);
    if (mode == 1) {
        if (pairA[1] != gen)
            pairA[0] = 2;
        if (pairB[1] != gen)
            pairB[0] = 2;
    }

    if (pairA[0] == 0) {
        if (pairB[0] != 0) {
        BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c), 2);
        BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c) + 1, 2);
        off = self->f30 - 0x10 - self->f140;
        MIi_CpuCopy16(h + off, buf + off, self->f140 + 0x10);
        }
    } else if (pairB[0] == 0) {
        if (pairA[0] != 0) {
        BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c), 1);
        BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c) + 1, 1);
        off = self->f30 - 0x10 - self->f140;
        MIi_CpuCopy16(buf + off, h + off, self->f140 + 0x10);
        }
    } else {
        if (pairA[0] == 1 || pairB[0] == 1) {
            BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
            func_020307B0(buf);
            return 3;
        }
        BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
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
        for (i = 0; i < func_02033BF0((struct Obj02033BF0 *)self->f2c); i++) {
            A = SAVEDATA_GetBlockOffset(self->f2c, i);
            B = SAVEDATA_GetBlockSize(self->f2c, i);
            AB = A + B;
            pa = h + AB;
            pb = buf + AB;
            BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 0);
            if (((struct Obj08817 *)pa)->f2 != tbl[i]
                && ((struct Obj08818 *)pb)->f2 != tbl[i])
                break;
            if (((struct Obj08817 *)pa)->f2 == tbl[i]) {
                if (((struct Obj08817 *)pa)->f2 != func_02081B8C((struct MATHCRC16Table *)((u8 *)svsys + 4), h + A, B))
                    BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 1);
            } else {
                BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 1);
            }
            if (((struct Obj08818 *)pb)->f2 == tbl[i]) {
                if (((struct Obj08818 *)pb)->f2 != func_02081B8C((struct MATHCRC16Table *)((u8 *)svsys + 4), buf + A, B)) {
                    if (BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)self, i) == 1)
                        break;
                    BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 2);
                }
            } else {
                if (BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)self, i) == 1)
                    break;
                BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 2);
            }
            if (BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)self, i) == 0) {
                if (cnt16(pa) != *(u16 *)(bufs[k] + AB))
                    BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 1);
                if (cnt16(pb) != *(u16 *)(bufs[k] + AB)) {
                    if (BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)self, i) == 1)
                        break;
                    BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 2);
                }
            }
        }
        if (i >= func_02033BF0((struct Obj02033BF0 *)self->f2c)) {
            u32 id = ids[k ^ 1];

            BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c) + 1, id);
            BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c), id);
            break;
        }
    }
    if (k >= 2) {
        BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
        func_020307B0(buf);
        return 3;
    }

    off = self->f30 - 0x10 - self->f140;
    MIi_CpuCopy16(bufs[k] + off, h + off, self->f140 + 0x10);
    for (i = 0; i < func_02033BF0((struct Obj02033BF0 *)self->f2c); i++) {
        if (BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)self, i) == 1) {
            A = SAVEDATA_GetBlockOffset(self->f2c, i);
            B = SAVEDATA_GetBlockSize(self->f2c, i);
            MIi_CpuCopy16(buf + A, h + A, B + 4);
        }
    }
    BACKUP_SYSTEM_SetSaveCount((int *)self, gens[k]);
    func_020307B0(buf);
    for (i = 0; i < func_02033BF0((struct Obj02033BF0 *)self->f2c); i++)
        BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)self, i);
    return 1;
}
