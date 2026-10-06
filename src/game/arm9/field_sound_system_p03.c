/*
 * file:     field_sound_system_p03.c
 * unit:     yes
 * function: func_02028DCC, func_02028E0C
 * address:  0x02028DCC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02028E48  0x02028E48  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Cmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct Sys_02028DCC {
    u8          pad_00[0x28];
    struct Cmd  queue[10];
    u8          tail;
    volatile u8 head;
};

struct Sys_02028E0C {
    u8         pad_00[0x28];
    struct Cmd queue[10];   /* 0x28 */
    u8         pad_A0;
    u8         head;        /* 0xa1 */
};

extern u32 func_02028E48(struct Sys_02028E0C *s, u32 kind);


u8 func_02028DCC(struct Sys_02028DCC *s, u32 target)
{
    s32 curr = s->tail;
    u32 count = 0;

    if (curr != s->head) {
        do {
            if (s->queue[curr].unk00 == target) {
                count++;
            }
            curr = (curr + 1) % 10;
        } while (curr != s->head);
    }
    return count;
}


/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * Blocked at MATCH: all 60 concrete bytes are right; the runtime divide
 * resolves `runtime`, and the only open site is func_02028E48, whose sole
 * branch reference image-wide is this call.  src/pending/func_02028E48.c is
 * byte-correct and capped by the table at 0x0209FD90, so this file is capped
 * with it.
 *
 * field_sound_system.c: enqueue one twelve-byte command.  The ring is ten
 * slots at +0x28 with the write cursor in the byte at +0xA1; a slot whose
 * first word is non-zero is still occupied and the command is dropped.  The
 * cursor is read into a local before the filter call, which is what puts the
 * `ldrb` above the `bl` rather than after it.
 *
 * The copy is one aggregate assignment, `ldm`/`stm` of two words plus the
 * trailing word (docs/idioms/aggregate-assignment-is-ldm-stm.md), and the
 * cursor advance is a real `%`: the call to the runtime's signed divide
 * helper returns the remainder in r1, which is what gets stored back
 * (docs/idioms/runtime-helper-reloc.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02028E0C.c \
 *       --func func_02028E0C --addr 0x02028E0C --cc 1.1p1 --thumb
 */
void func_02028E0C(struct Sys_02028E0C *s, struct Cmd *cmd)
{
    s32 n;

    n = s->head;
    if (func_02028E48(s, cmd->unk00) == 0) {
        return;
    }
    if (s->queue[n].unk00 != 0) {
        return;
    }
    s->queue[n] = *cmd;
    s->head = (n + 1) % 10;
}
