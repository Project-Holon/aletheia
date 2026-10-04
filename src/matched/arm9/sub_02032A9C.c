/*
 * function: sub_02032A9C
 * address:  0x02032A9C
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020319A4  0x020319A4  arm
 *   func_02031EAC  0x02031EAC  arm
 *   func_020335E8  0x020335E8  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02033B68  0x02033B68  arm
 *   func_02033BAC  0x02033BAC  arm
 *   unk_02146994   0x02146994  data
 *
 * savedata.c.  One resumable step of a record copy: read the record out of
 * Flash into the 0x38 scratch area 0x100 bytes at a time and hand each
 * chunk to 0x0203EFC8, stopping either when the record is exhausted (answer
 * 2) or when the running byte budget in *pb crosses 0x800 (answer 0, with
 * the remaining length and the progress written back through *pa and *pc so
 * the caller can call again).  A read or write failure answers 1.
 *
 * The seven arguments mean the last three arrive on the stack; the compiler
 * keeps the sixth in its own incoming slot and reloads it, which is why
 * there is a `ldr r2, [sp, #0x2c]` / `str r2, [sp, #0x2c]` pair that looks
 * like a no-op in the prologue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02032A9C.c \
 *       --func sub_02032A9C --addr 0x02032A9C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct SaveBackup {
    u8 pad00[0x2C];
    u32 unk2C;
    u8 pad30[8];
    u8 unk38[1];
};

extern struct { u8 pad000[0x204]; u32 unk204; } *unk_02146994;

extern u32 func_020319A4(u8 *p, u32 id);
extern u32 func_02031EAC(struct SaveBackup *p, u32 mode);
extern int func_020335E8(u32 a0, u32 a1, u32 a2, void (*a3)(void));
typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern u32 func_02033B68(u8 *p, u32 i);
extern u32 func_02033BAC(u8 *p, u32 i);

u32 sub_02032A9C(struct SaveBackup *p, u32 id, u32 mode, u32 *pa, u32 *pb,
                 u32 *pc, u32 *pd)
{
    u32 off;
    u32 rem;
    u32 chunk;
    u32 done;
    u8 *src;
    u32 acc;

    off = func_02031EAC(p, mode);
    off = off + func_02033B68((u8 *)p->unk2C, id);

    rem = *pa;
    if (rem != 0) {
        done = *pc;
        off = off + done;
    } else {
        rem = func_02033BAC((u8 *)p->unk2C, id);
        done = 0;
    }

    src = (u8 *)func_020319A4((u8 *)p, id);

    *pa = 0;
    *pc = 0;
    *pd = 0;

    do {
        if (rem > 0x100) {
            chunk = 0x100;
            rem = rem - 0x100;
        } else {
            chunk = rem;
            rem = 0;
        }

        acc = *pb + chunk;
        *pb = acc;
        if (acc > 0x800) {
            *pd = 1;
            *pb = 0;
        }

        if (func_020335E8(off, (u32)p->unk38, chunk, (void (*)(void))unk_02146994->unk204) == 0) {
            return 1;
        }

        if (func_0203EFC8(p->unk38, src + done, chunk) != 0) {
            return 1;
        }

        done = done + chunk;
        off = off + chunk;

        if (*pd == 1) {
            if (rem == 0) {
                return 2;
            }
            *pa = rem;
            *pc = done;
            return 0;
        }
    } while (rem != 0);

    return 2;
}
