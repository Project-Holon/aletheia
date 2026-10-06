/*
 * function: func_021FD1C4
 * address:  0x021FD1C4
 * packet:   pkt_ov186_021FD1C4
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wave P2, lane Q6, pengy share): first full draft, 1148 B,
 * same size as the original, 12 bytes differ. Constructor of the GDS
 * profile screen (pair of func_021FD640, the matched destructor): 0x44 B
 * object, 7 text windows from the 8-byte table d_02200B34 (switch on the
 * row: 0 name, 1 and 3 and 4 number rows, 6 optional record with a
 * fallback draw, 2 and 5 plain message), then an arc load that builds the
 * object at +0x24 when the profile has a icon and a second one at +0x28
 * chosen by mode (0, 1, other). The earlier layout residue is closed:
 * the table row is read as d_02200B34[i].f at every use (CSE gives the
 * r6 address), the pair constant d_02200B6C is read twice by initialiser
 * (Pair b = d at function level, Pair c = d in case 6, which gives the
 * hidden copy at [sp,#0x38]), the two position records are memset with
 * func_02082BCC(&r,0,8) then only x,y,z / x,y are stored, hf is a u32 so
 * the u16 truncation is repeated per call, mode is a switch.
 * Residue (12 B, two spots): (1) in the icon block the original builds the
 * z=1 store and the later func_0204B688(obj,1) argument with separate
 * movs r1,#1; mine pools the 1 in r7 (movs r7,#1; strh r7; adds r1,r7,#0).
 * (2) in mode 0 the original schedules movs r7,#4 and movs r7,#6 before the
 * str of k2 (the [sp,#0x20] slot); mine stores first. Tried, no change:
 * store order z first (moves the pooled 1 earlier), scheduling off,
 * opt_lifetimes off. opt_common_subs off breaks the whole body. Not
 * tried: opt_propagation off, peephole off, opt_dead_assignments off.
 * Callee prototypes for the unlabelled arm9 getters func_0200D6FC,
 * 70C, 72C, 73C, 810, 820 are guessed (u32 f(void *)); func_0200D774
 * takes the 4-halfword record out pointer.
 *
 * 2026-10-05 (wave P2, lane Q6b): 12 B -> 4 B, and now compiles in --lang c
 * (Pair b moved into a block that wraps the row loop, Req r declared at the
 * top of its block). Residue (2) closed: assign k3 first in each mode-0 arm
 * (k3=4;k1=0x14;k2=0x12;k4=0x13; and k3=6;k1=0x17;...), which gives the
 * original's movs r7 before the str to [sp,#0x20]; k1,k3,k2,k4 also works.
 * Residue left (4 B, icon block): original `movs r1,#1; strh r1,[r0,#0x14]`
 * and later `movs r1,#1` for func_0204B688(obj,1); mine pools the 1 in r7
 * (movs r7,#1; strh r7; adds r1,r7,#0). Pragmas opt_propagation off and
 * opt_dead_assignments off break the whole body (960+ B); peephole off: no
 * change. Tried, no change: B688 second parameter u8 or int; Req as
 * {short x,y,z;u8 a,b} (the ov183 021DCBD8 Position shape); z and the B688
 * argument spelled as an enum TRUE (each alone); z from a u16 local and the
 * argument from an int local; Req as u16 r[4]. In block 2 the same two 1s
 * (B6F4 arg and B688 arg, call between) are not pooled, so the pooling is
 * caused by the strh of a constant before the call; no source spelling found
 * that keeps the store value apart from the later argument.
 *
 * 2026-10-05 (wave P2, lane Q6c): still 4 B (same icon-block residue). New
 * tries, all unchanged (movs r7,#1; strh r7; adds r1,r7,#0): z=1 inside a
 * static inline SetPos(&r,x,y) (ov183 021DCBD8 shape); z and the B688 argument
 * both as enum BOOL TRUE; z as 1u; z as (u16)1; z stored between x and y;
 * B688 prototype unprototyped (K&R); object kept in a local `icon` (breaks
 * the body: the original reloads [r4,#0x24]); B688 (alone, or with B6F4) moved
 * into a second `if(B)` (the branch stays and B moves to r7, breaks layout);
 * one function-level Req shared by both blocks (moves the slots); pragmas
 * opt_lifetimes off and scheduling off on the current shape. z first moves the
 * pooled 1 to the top (as before). Reading: docs/idioms/a-repeated-constant-
 * pools-only-within-one-block-... says the pooler works per block, so the
 * original probably has a block boundary between the strh and the B688 call
 * that emits no branch; none found. In block 2 the same two 1s (both call
 * arguments, precoloured r2 and r1) do not pool, so only a store operand 1
 * followed by an argument 1 merges. Not tried: opt_common_subs off alone
 * (breaks the body per Q6).
 *
 * recoup 2026-10-05 (lane R10): still 4 B, same icon-block residue
 * (movs r7,#1; strh r7; adds r1,r7,#0 vs original movs r1,#1 twice). New
 * tries, all unchanged or worse: tail B6F4+B688 as a static inline (1152 B,
 * 326 off); opt_common_subs off alone (1176 B); z stored through
 * *(u16 *)((char *)&r+4) (4 B); z as *(u32 *)&r.z (5 B); B688 argument as
 * r.z (14 B); Req reached through a pointer rp (4 B); block locals declared
 * Req first, or Req then hf,h,t (4 B each); B688 second parameter u16, short
 * or char (4 B each). Matched twins read: ov183 021DF428 and 021DCBD8,
 * ov208 021C0B6C, ov206 021BB304 and 021BB534 (none has a strh of 1 before a
 * later literal 1 argument in one block). Reading: only a store operand 1
 * followed by an argument 1 merges, and no real source form splits them.
 *
 * final push 2026-10-05 G1L6: still 4 B (same icon-block residue). Research
 * first (idioms: repeated-constant-pools-only-within-one-block, repeated-small-
 * constant-takes-a-callee-saved-register, small-constant-is-rematerialised...,
 * store-stays-above-the-argument-constant, pool-constant-kept-live-past-a-join,
 * narrow-flag-local-is-spilled, sub-word-parameter-type..., one-element-array-
 * initialiser; twins ov183 021DCBD8/021DF428, ov206, ov208, ov218 021BA328:
 * none has a constant strh then a literal 1 argument in one block with a free
 * register). New tries, bytes off: aggregate initialiser `Req r={0x4b,0x40,1,0}`
 * (246 B: compiler copies the record from a pool table, no memset); do/while(0)
 * around B6F4+B688 (4); mid-function `#pragma opt_common_subs off` before the
 * if(B) (1093); B688 through a static inline SetVis(obj,v) or SetVis(obj) (4
 * each); stores through a static inline SetReq(&r,x,y,z) with int or u16
 * params (4 each); Req of short fields with B688 arg 1u (4); z as 1u with arg
 * -1+2 (4); keeping h live past the stores (func_02049238 moved after B688)
 * to test register pressure: still pooled (r6 instead of r7), so pressure is
 * not the cause; the whole icon block as a static inline MakeIcon (11 B, slots
 * move, still pooled). Conclusion unchanged: store operand 1 followed by an
 * argument 1 in one block always merges; no human source form found.
 *
 * final push 2026-10-05 G1R5: still 4 B (same icon-block residue). Control
 * test: B688 argument 2 instead of 1 gives 1 B off (only the constant), so
 * the merge is a plain value-number CSE of the two literal 1s, and with them
 * apart the whole block matches. New tries, all 4 B (movs r7,#1 pooled) unless
 * noted: Req stores and B294 in an inner block; function-level int vis=1 for
 * the argument, and for both z and argument; goto/label, switch(1), for(;;)
 * around B6F4+B688; z through a u16 *zp; B688 argument as (u8)1, (u16)1,
 * (char)1, (short)1, 1u, 1L, (u32)1, (unsigned long)1; per-function pragmas
 * opt_strength_reduction, opt_dead_code, opt_unroll_loops, opt_vectorize_loops,
 * optimize_for_size off (no change), opt_loop_invariants off (948 B off);
 * argument as B!=0, B>0, !!B, mode>=0 (real compares, 328+ B off); z stored
 * after B294 (42 B off, registers shift). Matched-assembly search (strh of a
 * fresh movs #1 followed later by a fresh movs #1 before a call): hits ov070
 * 021B6A14, 021B7688, 021B7CD0 (p->f83E = 1 then B92C(..,1), BB3F4(p,1)), plus
 * ov103/ov170/ov035 with no call-arg 1. ov070 021B6A14's C stores through a
 * pointer member and does not merge; our store goes to an address-taken stack
 * record and merges. No source form found that separates them.
 *
 * pass 2 2026-10-06 P2L06: still 4 B (same icon-block residue), form unchanged.
 * 40 compiles. Findings: compiler pins dsi/1.2 and 1.3 give the same 4 B, 1.6sp2
 * 7 lines, 2.0 1188 B. opt_common_subs off and optimization_level 3 keep the
 * merge (it is backend, not IRO CSE). Diagnostics: replacing BB5C(B,C,D,A) by
 * constants (or the B6F4 argument by 5) removes the merge, so it appears only
 * while the spilled A..D stay live across the icon tail; tiny repros never merge
 * the 1. Stores through a walking or indexed u16 pointer from &r.x also remove
 * the merge but use r6 as the base instead of sp+0x70 (60 lines off). Tried, all
 * 4 B: A..D as a local struct, a u32 info[4] array, an array with a call
 * initialiser, BB5C result in a local, one function-level h, declaration orders
 * of A..D and of the icon-block locals, z first, B294 stack arg changes.
 * Open lead: a form that keeps A..D in real memory (not spilled registers).
 *
 * pass 3 2026-10-06 P3L02: EXACT (c99 and c). The icon-block residue was the
 * callee declaration, not the block: func_0204B6F4 declared `void *` (returns
 * its object) instead of `void`. With a void declaration r0 is dead after the
 * call and mwcc keeps the constant 1 in r7 across it (store z=1, later
 * func_0204B688(obj,1)); with a value return it rebuilds `movs r1,#1` at each
 * use, as the image does (docs/idioms/a-callee-declared-void-that-returns-a-
 * value-changes-later-constant-copies.md). Evidence: the ARM body of
 * func_0204B6F4 (src/matched/arm9/unit_0204B6F4.c, written there as void) never
 * writes r0, so it is byte-identical to a definition that ends `return o;`.
 * The integrator should know that the matched definition is spelled void.
 * Also: t inlined into the func_0204AF28 call (same bytes, one fewer local).
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_0202DB0C 0x0202DB0C thumb
 *   func_0202DCFC 0x0202DCFC thumb
 *   func_0202DE5C 0x0202DE5C thumb
 *   func_0202DE64 0x0202DE64 thumb
 *   func_0202DC60 0x0202DC60 thumb
 *   func_0200D6D0 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   func_0200D6FC 0x0200D6FC thumb
 *   func_0200D70C 0x0200D70C thumb
 *   func_0200D72C 0x0200D72C thumb
 *   func_0200D73C 0x0200D73C thumb
 *   func_0200D74C 0x0200D74C thumb
 *   func_0200D760 0x0200D760 thumb
 *   func_0200D774 0x0200D774 thumb
 *   func_0200D810 0x0200D810 thumb
 *   func_0200D820 0x0200D820 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045874 0x02045874 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F230 0x0201F230 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B688 0x0204B688 arm
 *   d_02200D5C 0x02200D5C data a1
 *   d_02200B34 0x02200B34 data a4
 *   d_02200B6C 0x02200B6C data a4
 *   d_02200AFC 0x02200AFC data a1
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct {u32 x,y;} Pair;
typedef struct {u16 x,y,z,w;} Req;
typedef struct {u8 x,y,w,h; u32 msg;} Ent;
extern const char d_02200D5C[];
extern const Ent d_02200B34[];
extern const Pair d_02200B6C;
extern const u8 d_02200AFC[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,u32);
typedef signed int     s32;
struct Actor;
struct GdsProfile;
struct GdsRecord;
struct MsgBank;
struct Obj;
struct Obj0202DCC4;
struct PmsDraw;
struct RecGet;
struct U16Vec;
struct WordSet;
extern u32 func_021FC20C(char *);
extern int func_021FC214(char *p);
extern int func_021FC21C(char *p);
extern void func_021FB964(void *,u32,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC7C4(char *p, void *text, void *font, unsigned short value);
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void func_0202DCFC(struct Obj0202DCC4 *p, u32 i, u32 val);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern void func_0202DE64(struct PmsDraw *p, u16 v);
extern void func_0202DC60(struct Obj *p, u32 a, void *w, u32 i, u32 e);
extern void *func_0200D6D0(const void *,u32);
extern u32 func_0200D6EC(struct RecGet *p);
extern u32 func_0200D6FC(struct RecGet *p);
extern u32 func_0200D70C(struct RecGet *p);
extern u32 func_0200D72C(struct RecGet *p);
extern u32 func_0200D73C(struct RecGet *p);
struct GdsProfile;
extern u32 func_0200D74C(struct GdsProfile *p);
extern u32 func_0200D760(struct GdsProfile *p);
extern u32 func_0200D810(struct GdsProfile *p);
extern u32 func_0200D820(struct GdsProfile *p);
extern void *func_0200D774(struct GdsProfile *p, struct GdsRecord *out, u32 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F230(struct WordSet *p, u32 i, u32 v);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void *func_020490F4(u32,u16);
extern void func_02049238(void *);
extern int func_0201BC3C(void),func_0201BC40(void),func_0201BCB4(void);
extern u32 func_0201BABC(u32,u32,u32,u32),func_0201BB5C(u32,u32,u32,u32);
extern int func_0204ACEC(void *,u32,u32,u32,u16);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void *func_0204B6F4(void *,u32,u32);
extern void func_0204B688(struct Actor *actor, u32 value);
char *func_021FD1C4(void *prof,char *q,void *a2,void *a3,int mode,u16 heap)
{
    char *p;
    void *font;
    int i;
    void *bank;
    void *words;
    int ready;
    u32 k2,k1,k3,k4;
    void *text;
    u32 A,B,C,D;
    p=func_02030734(heap,0x44,0,d_02200D5C,0x541);
    func_02082BCC(p,0,0x44);
    *(char **)(p+0x1c)=q;
    font=(void *)func_021FC20C(q);
    *(void **)(p+0x20)=func_0202DB0C((u32)a2,0,(u32)a3,(u32)font,7,1,heap);
    func_0202DCFC(*(void **)(p+0x20),0,1);
    func_021FB964(*(void **)(p+0x1c),8,heap);
    bank=(void *)(u32)func_021FC214(q);
    words=(void *)(u32)func_021FC21C(q);
    {
    Pair b=d_02200B6C;
    for(i=0;i<7;i++) {
        *(void **)(p+i*4)=func_021FC6A4(1,d_02200B34[i].x,d_02200B34[i].y,d_02200B34[i].w,d_02200B34[i].h,14,a3,heap);
        func_021FC868(*(void **)(p+i*4),0,1,0);
        ready=1;
        switch(i) {
        case 0:
            {
            void *name;
            void *msg;
            text=func_020457B0(0x80,(u16)heap);
            name=func_0200D6D0(prof,heap);
            msg=func_02045EC0(bank,d_02200B34[i].msg);
            func_0201EE0C(words,0,name,func_0200D6EC(prof),1,2);
            func_0201F250(words,text,msg);
            func_02045808(name);
            func_02045808(msg);
            break;
            }
        case 1:
            {
            u32 v;
            void *msg;
            v=func_0200D810(prof);
            text=func_020457B0(0x80,(u16)heap);
            msg=func_02045EC0(bank,d_02200B34[i].msg);
            func_0201F230(words,0,v);
            func_0201F250(words,text,msg);
            func_02045808(msg);
            break;
            }
        case 3:
            {
            u32 v;
            void *msg;
            v=func_0200D74C(prof);
            text=func_020457B0(0x80,(u16)heap);
            msg=func_02045EC0(bank,d_02200B34[i].msg);
            func_0201F048(words,0,v);
            func_0201F250(words,text,msg);
            func_02045808(msg);
            func_021FC868(*(void **)(p+i*4),8,1,0);
            break;
            }
        case 4:
            {
            u32 v,w;
            void *msg;
            v=func_0200D74C(prof);
            w=func_0200D760(prof);
            text=func_020457B0(0x80,(u16)heap);
            msg=func_02045EC0(bank,d_02200B34[i].msg);
            func_0201F094(words,0,v,w);
            func_0201F250(words,text,msg);
            func_02045808(msg);
            func_021FC868(*(void **)(p+i*4),8,1,0);
            break;
            }
        case 6:
            {
            u16 rec[4];
            void *msg;
            msg=func_0200D774(prof,(struct GdsRecord *)rec,heap);
            if(msg) {
                text=func_02045874(msg,heap);
                func_02045808(msg);
                func_021FC868(*(void **)(p+i*4),8,1,0);
            } else {
                Pair c=d_02200B6C;
                func_0202DE5C(*(void **)(p+0x20),0);
                func_0202DE64(*(void **)(p+0x20),0x3da0);
                func_0202DC60(*(void **)(p+0x20),(u32)(*(void **)(*(char **)(p+i*4)+0xc)),rec,0,(u32)(&c));
                ready=0;
            }
            break;
            }
        default:
            text=func_02045EC0(bank,d_02200B34[i].msg);
            break;
        }
        if(ready) {
            func_021FC7C4(*(void **)(p+i*4),text,font,0x3da0);
            func_02045808(text);
        }
    }
    }
    A=func_0200D73C(prof);
    B=func_0200D6FC(prof);
    C=func_0200D70C(prof);
    D=func_0200D72C(prof);
    if(B) {
        u32 hf;
        void *h;
        Req r;
        hf=(heap&0x7fff)|0x8000;
        h=func_020490F4(7,hf);
        *(int *)(p+0x2c)=func_0204ACEC(h,func_0201BC3C(),0,0x80,hf);
        *(int *)(p+0x34)=func_0204AF28(h,func_0201BC40(),func_0201BCB4(),(u16)hf);
        *(int *)(p+0x30)=func_0204A6C8(h,func_0201BABC(B,C,D,A),0,0,hf);
        func_02049238(h);
        func_02082BCC(&r,0,8);
        r.x=0x4b;r.y=0x40;r.z=1;
        *(void **)(p+0x24)=func_0204B294(a2,*(u32 *)(p+0x30),*(u32 *)(p+0x2c),*(u32 *)(p+0x34),&r,0,heap);
        func_0204B6F4(*(void **)(p+0x24),func_0201BB5C(B,C,D,A),0);
        func_0204B688(*(void **)(p+0x24),1);
    }
    switch(mode) {
    case 0:
        {
        void *h;
        if(!func_0200D6EC(prof)) {
            k3=4;k1=0x14;k2=0x12;k4=0x13;
        } else {
            k3=6;k1=0x17;k2=0x15;k4=0x16;
        }
        h=func_020490F4(0x1f,(heap&0x7fff)|0x8000);
        *(int *)(p+0x38)=func_0204AC18(h,k3,0,0x1a0,0,1,heap);
        *(int *)(p+0x40)=func_0204AF28(h,k2,k4,(u16)heap);
        *(int *)(p+0x3c)=func_0204A6C8(h,k1,0,0,heap);
        func_02049238(h);
        break;
        }
    case 1:
        {
        u32 k;
        void *h;
        k=func_0200D820(prof);
        h=func_020490F4(0x20,(heap&0x7fff)|0x8000);
        *(int *)(p+0x38)=func_0204AC18(h,0,0,0x1a0,d_02200AFC[k],1,heap);
        *(int *)(p+0x40)=func_0204AF28(h,0x41,0x42,(u16)heap);
        *(int *)(p+0x3c)=func_0204A6C8(h,k+0x31,0,0,heap);
        func_02049238(h);
        break;
        }
    }
    {
        Req r;
        func_02082BCC(&r,0,8);
        r.x=0x30;r.y=0x40;
        *(void **)(p+0x28)=func_0204B294(a2,*(u32 *)(p+0x3c),*(u32 *)(p+0x38),*(u32 *)(p+0x40),&r,0,heap);
        func_0204B6F4(*(void **)(p+0x28),0,1);
        func_0204B688(*(void **)(p+0x28),1);
    }
    return p;
}
