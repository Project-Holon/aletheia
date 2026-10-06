/*
 * file:     unit_0206B780.c
 * unit:     yes
 * function: func_0206B780, func_0206B7A8
 * address:  0x0206B780
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

typedef struct Obj0206B780 Obj0206B780;

struct Obj0206B780 {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    void (*unk0c)(void *);
};

typedef struct Obj0206B7A8 Obj0206B7A8;

struct Obj0206B7A8 {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    u32   unk0c;
    void (*unk10)(void *);
};

void func_0206B780(Obj0206B780 *p);
void func_0206B7A8(Obj0206B7A8 *p);


/*
 * Calls the callback at +0x0C when it is set, handing it the object itself
 * (which is why the pointer is loaded into r1 and never r0), then bumps the
 * counter at +0x00.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206B780.c \
 *       --func func_0206B780 --addr 0x0206B780 --cc 1.1p1 --arm
 */
void func_0206B780(Obj0206B780 *p)
{
    if (p->unk0c != 0) {
        p->unk0c(p);
    }
    p->unk00++;
}


/*
 * Same shape as func_0206B780 one slot over: the callback at +0x10 is handed
 * the object itself, then bit 5 of the status word at +0x08 is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206B7A8.c \
 *       --func func_0206B7A8 --addr 0x0206B7A8 --cc 1.1p1 --arm
 */
void func_0206B7A8(Obj0206B7A8 *p)
{
    if (p->unk10 != 0) {
        p->unk10(p);
    }
    p->unk08 |= 0x20;
}
