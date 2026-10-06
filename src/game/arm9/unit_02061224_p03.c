/*
 * file:     unit_02061224_p03.c
 * unit:     yes
 * function: func_02061330, func_02061344, func_02061358, func_02061370, func_02061378, func_02061380, func_02061388, func_02061390
 * address:  0x02061330
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02061330  0x02061330  arm
 *   func_02061344  0x02061344  arm
 *   func_02061358  0x02061358  arm
 *   func_02061370  0x02061370  arm
 *   func_02061378  0x02061378  arm
 *   func_02061380  0x02061380  arm
 *   func_02061388  0x02061388  arm
 *   g_020A1708     0x020A1708  data
 *   g_020A8150     0x020A8150  data
 *   g_020A816C     0x020A816C  data
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef void (*Vfn)(void *self, u32 x);

struct Vt02061330 { Vfn f0; Vfn f1; };

struct Obj02061330 { struct Vt02061330 *vt; };

struct S02061358 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

struct Ent020A816C {
    u32 w[6];
};

struct Ptrs020A8150 {
    u32 unk0;
    u32 unk4;
    u32 p[5];
};

void func_02061390(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u8 g_020A1708[];
extern struct Ent020A816C  g_020A816C[];
extern struct Ptrs020A8150 g_020A8150;



/*
 * functions:
 *   func_02061330  0x02061330  arm
 *   func_02061344  0x02061344  arm
 *
 * Two two-argument vtable forwarders, 20 bytes each, no relocations at all.
 * The object at r0 holds a pointer to a table of function pointers at r0[0];
 * the call dispatches through slot 0 (0x02061330) and slot 1 (0x02061344).
 *
 * The tell that the callee takes *two* arguments is the register the loaded
 * pointer lands in.  Written as a one-argument call (`o->vt->f0(o)`) mwcc
 * keeps the function pointer in r1, which is free; the original puts it in
 * r2, which is only necessary when r0 and r1 are both argument registers, so
 * the wrapper forwards its own second parameter.  Same bytes either way for
 * the load pair, four differing bytes for the register choice.
 *
 * The wrapper's own arity is not visible in its body (the caller's r1 is
 * simply passed on), so the two-parameter reading is the one that reproduces
 * the register numbering; the functions are only reachable through a pointer
 * table, so no call site can be consulted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061330.c \
 *       --addr 0x02061330 --arm
 *   EXACT, 40 bytes, 2 functions, 0 relocation sites.
 */
void func_02061330(struct Obj02061330 *o, u32 x)
{
    o->vt->f0(o, x);
}

/*
 * functions:
 *   func_02061330  0x02061330  arm
 *   func_02061344  0x02061344  arm
 *
 * Two two-argument vtable forwarders, 20 bytes each, no relocations at all.
 * The object at r0 holds a pointer to a table of function pointers at r0[0];
 * the call dispatches through slot 0 (0x02061330) and slot 1 (0x02061344).
 *
 * The tell that the callee takes *two* arguments is the register the loaded
 * pointer lands in.  Written as a one-argument call (`o->vt->f0(o)`) mwcc
 * keeps the function pointer in r1, which is free; the original puts it in
 * r2, which is only necessary when r0 and r1 are both argument registers, so
 * the wrapper forwards its own second parameter.  Same bytes either way for
 * the load pair, four differing bytes for the register choice.
 *
 * The wrapper's own arity is not visible in its body (the caller's r1 is
 * simply passed on), so the two-parameter reading is the one that reproduces
 * the register numbering; the functions are only reachable through a pointer
 * table, so no call site can be consulted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061330.c \
 *       --addr 0x02061330 --arm
 *   EXACT, 40 bytes, 2 functions, 0 relocation sites.
 */
void func_02061344(struct Obj02061330 *o, u32 x)
{
    o->vt->f1(o, x);
}


/*
 *           func_02061388
 *
 * functions:
 *   func_02061358  0x02061358  arm
 *   func_02061370  0x02061370  arm
 *   func_02061378  0x02061378  arm
 *   func_02061380  0x02061380  arm
 *   func_02061388  0x02061388  arm
 *
 * The four eight-byte functions after the first are the `0` / `-1` stub
 * pair the object's own dispatch table points at (the word stored at
 * 0x020A1708 is 0x0206128C, and the stubs sit right behind the table pointer
 * this function installs).  `disasm.py` never labels them, because a leaf
 * that saves no register has no prologue to sweep, so they print as a run of
 * `.word`s between two literal pools -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are read
 * out of the bytes here, and folding them into this unit is also what makes
 * the unit EXACT rather than EXACT*: on its own, func_02061358's inferred
 * extent runs 56 bytes to the next label at 0x02061390.
 *
 * The store order in the first function is the whole of its codegen: the zero
 * word has to be written *second* in the source (after the table pointer,
 * before the two arguments) for mwcc to fold the a/b/0 stores into a single
 * `stmib r0, {r1, r2, r3}`.  With `unkC = 0` written last the compiler emits
 * a two-register `stmib` plus a separate `str` and the literal pool moves
 * four bytes along.
 *
 * The one relocation site is the pool word for the data object at 0x020A1708;
 * it resolves as `data_table` (40 witnesses elsewhere in the image), which is
 * why this file is EXACT rather than the MATCH the single-function,
 * own-pool-witness reading would suggest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061358.c \
 *       --addr 0x02061358 --arm
 *   EXACT, 56 bytes, 5 functions, 1 relocation site, resolved.
 */
void func_02061358(struct S02061358 *s, u32 a, u32 b)
{
    s->unk0 = (u32)g_020A1708;
    s->unkC = 0;
    s->unk4 = a;
    s->unk8 = b;
}

/*
 *           func_02061388
 *
 * functions:
 *   func_02061358  0x02061358  arm
 *   func_02061370  0x02061370  arm
 *   func_02061378  0x02061378  arm
 *   func_02061380  0x02061380  arm
 *   func_02061388  0x02061388  arm
 *
 * The four eight-byte functions after the first are the `0` / `-1` stub
 * pair the object's own dispatch table points at (the word stored at
 * 0x020A1708 is 0x0206128C, and the stubs sit right behind the table pointer
 * this function installs).  `disasm.py` never labels them, because a leaf
 * that saves no register has no prologue to sweep, so they print as a run of
 * `.word`s between two literal pools -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are read
 * out of the bytes here, and folding them into this unit is also what makes
 * the unit EXACT rather than EXACT*: on its own, func_02061358's inferred
 * extent runs 56 bytes to the next label at 0x02061390.
 *
 * The store order in the first function is the whole of its codegen: the zero
 * word has to be written *second* in the source (after the table pointer,
 * before the two arguments) for mwcc to fold the a/b/0 stores into a single
 * `stmib r0, {r1, r2, r3}`.  With `unkC = 0` written last the compiler emits
 * a two-register `stmib` plus a separate `str` and the literal pool moves
 * four bytes along.
 *
 * The one relocation site is the pool word for the data object at 0x020A1708;
 * it resolves as `data_table` (40 witnesses elsewhere in the image), which is
 * why this file is EXACT rather than the MATCH the single-function,
 * own-pool-witness reading would suggest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061358.c \
 *       --addr 0x02061358 --arm
 *   EXACT, 56 bytes, 5 functions, 1 relocation site, resolved.
 */
int func_02061370(void)  { return 0; }
/*
 *           func_02061388
 *
 * functions:
 *   func_02061358  0x02061358  arm
 *   func_02061370  0x02061370  arm
 *   func_02061378  0x02061378  arm
 *   func_02061380  0x02061380  arm
 *   func_02061388  0x02061388  arm
 *
 * The four eight-byte functions after the first are the `0` / `-1` stub
 * pair the object's own dispatch table points at (the word stored at
 * 0x020A1708 is 0x0206128C, and the stubs sit right behind the table pointer
 * this function installs).  `disasm.py` never labels them, because a leaf
 * that saves no register has no prologue to sweep, so they print as a run of
 * `.word`s between two literal pools -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are read
 * out of the bytes here, and folding them into this unit is also what makes
 * the unit EXACT rather than EXACT*: on its own, func_02061358's inferred
 * extent runs 56 bytes to the next label at 0x02061390.
 *
 * The store order in the first function is the whole of its codegen: the zero
 * word has to be written *second* in the source (after the table pointer,
 * before the two arguments) for mwcc to fold the a/b/0 stores into a single
 * `stmib r0, {r1, r2, r3}`.  With `unkC = 0` written last the compiler emits
 * a two-register `stmib` plus a separate `str` and the literal pool moves
 * four bytes along.
 *
 * The one relocation site is the pool word for the data object at 0x020A1708;
 * it resolves as `data_table` (40 witnesses elsewhere in the image), which is
 * why this file is EXACT rather than the MATCH the single-function,
 * own-pool-witness reading would suggest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061358.c \
 *       --addr 0x02061358 --arm
 *   EXACT, 56 bytes, 5 functions, 1 relocation site, resolved.
 */
int func_02061378(void)  { return -1; }
/*
 *           func_02061388
 *
 * functions:
 *   func_02061358  0x02061358  arm
 *   func_02061370  0x02061370  arm
 *   func_02061378  0x02061378  arm
 *   func_02061380  0x02061380  arm
 *   func_02061388  0x02061388  arm
 *
 * The four eight-byte functions after the first are the `0` / `-1` stub
 * pair the object's own dispatch table points at (the word stored at
 * 0x020A1708 is 0x0206128C, and the stubs sit right behind the table pointer
 * this function installs).  `disasm.py` never labels them, because a leaf
 * that saves no register has no prologue to sweep, so they print as a run of
 * `.word`s between two literal pools -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are read
 * out of the bytes here, and folding them into this unit is also what makes
 * the unit EXACT rather than EXACT*: on its own, func_02061358's inferred
 * extent runs 56 bytes to the next label at 0x02061390.
 *
 * The store order in the first function is the whole of its codegen: the zero
 * word has to be written *second* in the source (after the table pointer,
 * before the two arguments) for mwcc to fold the a/b/0 stores into a single
 * `stmib r0, {r1, r2, r3}`.  With `unkC = 0` written last the compiler emits
 * a two-register `stmib` plus a separate `str` and the literal pool moves
 * four bytes along.
 *
 * The one relocation site is the pool word for the data object at 0x020A1708;
 * it resolves as `data_table` (40 witnesses elsewhere in the image), which is
 * why this file is EXACT rather than the MATCH the single-function,
 * own-pool-witness reading would suggest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061358.c \
 *       --addr 0x02061358 --arm
 *   EXACT, 56 bytes, 5 functions, 1 relocation site, resolved.
 */
int func_02061380(void)  { return 0; }
/*
 *           func_02061388
 *
 * functions:
 *   func_02061358  0x02061358  arm
 *   func_02061370  0x02061370  arm
 *   func_02061378  0x02061378  arm
 *   func_02061380  0x02061380  arm
 *   func_02061388  0x02061388  arm
 *
 * The four eight-byte functions after the first are the `0` / `-1` stub
 * pair the object's own dispatch table points at (the word stored at
 * 0x020A1708 is 0x0206128C, and the stubs sit right behind the table pointer
 * this function installs).  `disasm.py` never labels them, because a leaf
 * that saves no register has no prologue to sweep, so they print as a run of
 * `.word`s between two literal pools -- see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are read
 * out of the bytes here, and folding them into this unit is also what makes
 * the unit EXACT rather than EXACT*: on its own, func_02061358's inferred
 * extent runs 56 bytes to the next label at 0x02061390.
 *
 * The store order in the first function is the whole of its codegen: the zero
 * word has to be written *second* in the source (after the table pointer,
 * before the two arguments) for mwcc to fold the a/b/0 stores into a single
 * `stmib r0, {r1, r2, r3}`.  With `unkC = 0` written last the compiler emits
 * a two-register `stmib` plus a separate `str` and the literal pool moves
 * four bytes along.
 *
 * The one relocation site is the pool word for the data object at 0x020A1708;
 * it resolves as `data_table` (40 witnesses elsewhere in the image), which is
 * why this file is EXACT rather than the MATCH the single-function,
 * own-pool-witness reading would suggest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02061358.c \
 *       --addr 0x02061358 --arm
 *   EXACT, 56 bytes, 5 functions, 1 relocation site, resolved.
 */
int func_02061388(void)  { return -1; }


/*
 * The two pool words at 0x020613D0 / 0x020613D4 resolve through `literal`
 * witnesses in other functions (0x020614D0 for the table, 0x0206163C for the
 * global), so the file is EXACT; its section is 72 bytes, the 64 code bytes
 * the worklist records plus its own pool.
 *
 * The function indexes a table of 0x18-byte records (mla r6, r0, ip, r5 with
 * ip = 0x18) five times, once per parameter, and stores the five computed
 * addresses into consecutive words at +8..+0x18 of a global at 0x020A8150.
 * The fifth parameter arrives on the stack, at [sp, #0x10] before the push.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02061390.c \
 *       --func func_02061390 --addr 0x02061390 --arm --cc 1.1p1
 *   EXACT, 72 bytes, 2 relocation sites, all 2 resolved.
 */
void func_02061390(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    g_020A8150.p[0] = (u32)&g_020A816C[a];
    g_020A8150.p[1] = (u32)&g_020A816C[b];
    g_020A8150.p[2] = (u32)&g_020A816C[c];
    g_020A8150.p[3] = (u32)&g_020A816C[d];
    g_020A8150.p[4] = (u32)&g_020A816C[e];
}
