/*
 * docs/families/net_save.h -- shared declarations for the net_save.c family
 * (0x0201088C..0x020111EC in the ARM9 image).  The __FILE__ anchor that names
 * the unit is "net_save.c" at 0x020A7258 (the allocation sites pass
 * 0x020A725C, two bytes in); see src/matched/unit_0201088C.c.
 *
 * The family is three layers that share one file:
 *
 *   0x0201088C..0x02010A5C  the WIFI-SAVE STATE MACHINE: a 0x14-byte object
 *                           whose +0x08 field is the next step to run.  Each
 *                           step calls func_02010888(p, next) to advance.
 *   0x02010A5C..0x02010D98  the SAVE TASK: a 0x1D8-byte task record allocated
 *                           at heap id 0x67, plus its per-frame poll.
 *   0x02010D98..0x020111EC  the PLAY-TIME / COUNTER TABLES: a thirteen-entry
 *                           u32 counter array (g_021461E8) with a parallel
 *                           byte-state array (g_0214621C) and a small control
 *                           block (g_02146208 / g_02146228) of mode bytes and
 *                           u16 scale factors.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and match.py never sees it.  Every declaration below is
 * derived from a file in src/matched that is EXACT, and the matched function
 * that evidences each field or parameter is named in the comment beside it.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout; the
 * thirteen-entry table size (0xd) is a content constant and is flagged as
 * such where it appears.
 */

#ifndef NET_SAVE_H
#define NET_SAVE_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;
typedef unsigned long long u64;

/* ------------------------------------------------------------------ *
 * 1.  THE WIFI-SAVE STATE MACHINE OBJECT  (0x14 bytes)
 *
 * Allocated by func_0201088C / func_020108C4 with func_02030734(heap, 0x14,
 * 1, "net_save.c", line).  The object is driven one step per poll: every
 * step function stores its successor into +0x08 through func_02010888, and
 * the terminal step stores 0 (func_02010A3C).
 *
 * Evidence: src/matched/unit_0201088C.c (both constructors and the poll),
 * src/matched/func_02010888.c (the setter), and the step chain
 * func_0201093C -> func_02010964 -> func_02010994 -> func_020109B8 ->
 * func_020109E0 -> func_02010A04 -> func_02010A3C.
 * ------------------------------------------------------------------ */
struct NetSaveObj {
    u32 f0;                             /* +0x00  user callback, called with
                                         *        f4 as its one argument;
                                         *        func_02010A04 */
    u32 f4;                             /* +0x04  that callback's argument;
                                         *        func_020108C4, func_02010A04 */
    void (*step)(struct NetSaveObj *p); /* +0x08  next step; func_02010888 */
    u32 save_handle;                    /* +0x0C  handed to func_02012DAC /
                                         *        func_02012DD0 / func_02012E08;
                                         *        cleared by func_02010A04 */
    u32 timer;                          /* +0x10  frame countdown, set to
                                         *        func_020056EC(0x3c) by
                                         *        func_02010964 and decremented
                                         *        SIGNED by func_020109B8 (the
                                         *        test is `v < 0` after a
                                         *        plain subtract) */
};

/* The setter every step goes through.  Its second parameter is a u32, not a
 * function pointer: every caller casts the successor's address to u32 first
 * (src/matched/func_0201093C.c and its five siblings). */
void func_02010888(u8 *p, u32 v);                    /* 0x02010888 */

/* Constructors and poll; src/matched/unit_0201088C.c. */
void *func_0201088C(u32 heap, u32 save_handle);      /* 0x0201088C  line 0x75 */
void *func_020108C4(u32 heap, u32 save_handle,
                    u32 cb, u32 cb_arg);             /* 0x020108C4  line 0x87 */
u32   func_02010904(struct NetSaveObj *p);           /* 0x02010904 */
void  func_02010934(void);                           /* 0x02010934  tail-call
                                                      * stub to func_020307B0 */

/* The step chain, in order.  Each takes the object; none returns anything. */
void func_0201093C(u8 *p);   /* 0x0201093C  wait sync 0x71, then start save  */
void func_02010964(u8 *p);   /* 0x02010964  save begun -> arm the 0x3c timer */
void func_02010994(u8 *p);   /* 0x02010994  wait sync 0x72                   */
void func_020109B8(u8 *p);   /* 0x020109B8  tick the timer, sync 0x73 at 0   */
void func_020109E0(u8 *p);   /* 0x020109E0  wait sync 0x73                   */
void func_02010A04(u8 *p);   /* 0x02010A04  fire f0(f4), finish save, 0x74   */
void func_02010A3C(u8 *p);   /* 0x02010A3C  wait sync 0x74, then step = 0    */

/* ------------------------------------------------------------------ *
 * 2.  THE NETWORK SYNCHRONISATION PAIR
 *
 * Every step in the chain is one half of a barrier: func_02039C68 POSTS a
 * tag, func_02039CB4 POLLS for it and answers non-zero when every peer has
 * posted.  Both take the session handle from func_020399A8() first, then the
 * tag, then a size that is always 8.  The tags used by this family run
 * 0x71..0x75 (0x75 is unused here; 0x71..0x74 are the four barriers above).
 *
 * All three are ARM.  Evidence: every step file in src/matched.
 * ------------------------------------------------------------------ */
u32  func_020399A8(void);                            /* 0x020399A8  arm */
void func_02039C68(u32 handle, u32 tag, u32 size);   /* 0x02039C68  arm  post  */
u32  func_02039CB4(u32 handle, u32 tag, u32 size);   /* 0x02039CB4  arm  poll  */

/* The save back end the chain drives.  func_02012DD0 returns a small state
 * code: 1 means "started" (func_02010964), 2 means "finished"
 * (func_02010A04). */
void func_02012DAC(u32 save_handle);                 /* 0x02012DAC  thumb */
u32  func_02012DD0(u32 save_handle);                 /* 0x02012DD0  thumb */
void func_02012E08(u32 save_handle);                 /* 0x02012E08  thumb */
u32  func_020056EC(u32 frames);                      /* 0x020056EC  thumb */
u32  func_0200FB24(void);                            /* 0x0200FB24  thumb */

/* ------------------------------------------------------------------ *
 * 3.  THE SAVE TASK RECORD  (0x1D8 bytes, heap id 0x67)
 *
 * src/matched/sub_02010A5C.c is the constructor and names every offset it
 * touches; func_02010B98 and func_02010D98 are the two four-argument task
 * entry points that reach the record through their fourth parameter.
 * ------------------------------------------------------------------ */
struct NetSaveTask {
    u32 flag_a;     /* +0x00 ... +0x40  untyped head, zeroed by the ctor  */
    /* +0x44  void *  sub_020124F4(0x67) result; sub_02010A5C, func_02010B98
     *                reads it through *(int *)((char *)a3 + 0x44)         */
    /* +0x54  u32     1 when sub_020092EC() != 0, else 0; sub_02010A5C     */
    /* +0x1D0 u16     the heap id 0x67 written back into the record        */
    /* +0x1D4 u32     the same flag as +0x54                               */
};

void  func_0203064C(int a, int heap_id, int size);        /* 0x0203064C  arm  */
u8   *func_0203159C(void *a, int size, int heap_id);      /* 0x0203159C  arm  */
void  func_02082BCC(void *dst, int val, unsigned n);      /* 0x02082BCC  arm
                                                           * MI_CpuFill8      */
void *sub_020124F4(int heap_id);                          /* 0x020124F4 thumb */
void  sub_02012EBC(void);                                 /* 0x02012EBC thumb */
void  sub_02009448(void);                                 /* 0x02009448 thumb */
int   sub_020092EC(void);                                 /* 0x020092EC thumb */

int sub_02010A5C(void *heap_ctx);                         /* 0x02010A5C */
int func_02010B98(int a0, int a1, int a2, int a3);        /* 0x02010B98 */
int func_02010BB8(void *heap_ctx, int a1, int a2);        /* 0x02010BB8  the
                                                           * save-SCREEN ctor:
                                                           * blanks both display
                                                           * engines, then a
                                                           * 0x1A8-byte record
                                                           * at heap 0x5b */
int func_02010D98(int a0, int a1, int a2, int a3);        /* 0x02010D98 */

/* ------------------------------------------------------------------ *
 * 4.  THE COUNTER TABLES
 *
 * Three globals, all bss/data, reached only through pool words:
 *
 *   g_021461E8   thirteen u32 counters, indexed 0..0xc.  Evidence:
 *                src/matched/func_02010EC0.c (`((u32 *)g_021461E8)[i]`),
 *                src/matched/func_02010EEC.c (declared `extern u32 []`),
 *                src/matched/func_02010F50.c (slot cleared to 0),
 *                src/matched/func_02010DB4.c (the whole 0x60-byte array is
 *                MI_CpuFill8'd to zero -- 0x60 = 13 * 4 rounded up to 0x60,
 *                so the array's declared extent is 0x60 bytes).
 *   g_0214621C   thirteen parallel STATE BYTES.  0x30 means "empty"; the
 *                value is an ASCII '0', so the table is very likely a string
 *                of digits in the original.  Evidence:
 *                src/matched/func_02010EC0.c (`g_0214621C[i] == 0x30`),
 *                src/matched/func_02010F50.c (`g_0214621C[idx] = 0x30`).
 *   g_02146208   the MODE-BYTE block.  Bytes +0x14..+0x1e each gate one
 *                scaling function; 0x30 means "off", the same sentinel as
 *                g_0214621C.  NOTE that g_02146208 + 0x14 == g_0214621C, so
 *                the two names are two views of one object and the mode bytes
 *                ARE the state bytes; both spellings appear in src/matched
 *                because they were written by different lanes.
 *   g_02146228   the CONTROL BLOCK: u16 scale factors at +2, +4, +6, +8, +0xa,
 *                +0x10, +0x12, +0x14, +0x16, and at +0x1c the u8 SELECTED
 *                SLOT (0..0xc, with 0xd meaning "none").  Evidence:
 *                src/matched/func_02010EEC.c (+0x1c as the index, 0xd = none),
 *                src/matched/func_02010F50.c (+0x1c reset to 0xd),
 *                and the nine scaling functions below for the u16 offsets.
 *
 * THIRTEEN IS A CONTENT CONSTANT.  Every loop and bound test in this block
 * uses 0xd; it is the number of counter slots and could differ between
 * versions.  The bound test in func_02010F50 is SIGNED (`bge`, not `bhs`),
 * so the index parameter is `int`, not `u32`.
 * ------------------------------------------------------------------ */
extern u32 g_021461E8[];    /* 0x021461E8  thirteen counters, 0x60 bytes */
extern u8  g_0214621C[];    /* 0x0214621C  thirteen state bytes, 0x30 = empty */
extern u8  g_02146208[];    /* 0x02146208  mode-byte block; +0x14 == g_0214621C */
extern u8  g_0214622A[];    /* 0x0214622A  thirteen u16s, parallel to the
                             * counters; == g_02146228 + 2, so it is the same
                             * object as the first scale factor below and the
                             * two spellings are two views of one table.
                             * Evidence: src/matched/sub_02010E14.c */
extern u8  g_02146228[];    /* 0x02146228  control block; +0x1c = selected slot */

/* The empty placeholder callback the tables' reset tail-calls; a pool word in
 * the image holds 0x02010FAD, so the two-byte `bx lr` is a real entry point.
 * src/matched/sub_02010FAC.c. */
void sub_02010FAC(void);                                  /* 0x02010FAC */

void func_02010DB4(void);          /* 0x02010DB4  zero the array, then reset  */
void func_02010DCC(void);          /* 0x02010DCC  decrement every counter > 1 */
void func_02010DF4(void);          /* 0x02010DF4  clear every slot, deselect  */
/* Both loops use an ENUM counter (Slot, SLOT_MAX = 13): that is what keeps
 * the image's unfolded `cmp; bge` entry guard with a plain increment. */
void sub_02010E14(int slot, u8 *rec, int select);         /* 0x02010E14 */
u8   sub_02010EA0(int slot, u8 *rec);                     /* 0x02010EA0  the
                                                           * state byte of the
                                                           * record's own slot */
u8   sub_02010EB4(int k);                                 /* 0x02010EB4  the
                                                           * state byte of slot
                                                           * k */
u32  func_02010EC0(u32 i);         /* 0x02010EC0  slot i in minutes, min 1    */
int  func_02010EEC(void);          /* 0x02010EEC  selected slot in minutes    */
void func_02010F50(int idx);       /* 0x02010F50  clear slot idx              */

/* ------------------------------------------------------------------ *
 * 5.  THE SCALING FUNCTIONS
 *
 * Nine variations on one shape: if the mode byte is not 0x30, scale the
 * argument by a u16 factor and divide by 100.  The multiply is spelled
 * TABLE-VALUE-FIRST (`factor * v`, never `v * factor`) or the result lands in
 * r1 and the function is four bytes too long -- see the header of
 * src/matched/func_02010FF4.c.  The divide is unsigned (`_u32_div_f` at
 * 0x0209C2B0) in every one of them except func_020111BC, which is 64-bit
 * signed (`_ll_mul` 0x0209C054, `_ll_div` 0x0209BE5C).
 *
 *   func  addr        mode byte        scale u16        extra
 *   ----  ----------  ---------------  ---------------  ---------------------
 *   FB0   0x02010FB0  +0x14 and +0x15  +2 and +4        clamps each arm to 100
 *   FF4   0x02010FF4  +0x16            +6
 *   014   0x02011014  +0x17            +8               ADDS the factor, no
 *                                                       multiply or divide
 *   02C   0x0201102C  +0x18            +0xa
 *   04C   0x0201104C  +0x19            +0xc             EXACT; not a scaling
 *                                                       function: adds +0xc to
 *                                                       a record field, 999 =
 *                                                       special
 *   0CC   0x020110CC  +0x1a            +0xe             EXACT; four-slot
 *                                                       variant of 04C
 *   168   0x02011168  +0x1b and +0x1c  +0x10 and +0x12  first arm returns early
 *   19C   0x0201119C  +0x1d            +0x14
 *   1BC   0x020111BC  +0x1e            +0x16            64-bit signed; OPEN,
 *                                                       3 bytes out, see
 *                                                       docs/notes/func_020111BC.c.txt
 * ------------------------------------------------------------------ */
extern u32 _u32_div_f(u32 a, u32 b);   /* 0x0209C2B0  arm */

u32 func_02010FB0(u32 v);       /* 0x02010FB0 */
u32 func_02010FF4(u32 v);       /* 0x02010FF4 */
int func_02011014(int v);       /* 0x02011014 */
u32 func_0201102C(u32 v);       /* 0x0201102C */
u32 func_02011168(u32 v);       /* 0x02011168 */
u32 func_0201119C(u32 v);       /* 0x0201119C */

/* 04C / 0CC: the callees take the pointer (func_0201BA34(box),
 * func_0201AB08(box) is a forwarder that passes r0 through,
 * func_02017D30(rec) opens the access bracket that func_02017D70(rec, h)
 * closes), and the record func_0201AB28(box, idx) returns is its own local.
 * With `void` prototypes the pool load lands after the parameter copy (the
 * "entry-order" residue of the old notes). */
u32   func_0201AB08(void *box);                 /* 0x0201AB08 */
void *func_0201AB28(void *box, u32 idx);        /* 0x0201AB28 box+8+idx*0xdc */
u32   func_02017D30(void *rec);                 /* 0x02017D30 */
void  func_02017D70(void *rec, u32 h);          /* 0x02017D70 */
void  func_0201BA34(void *box);                 /* 0x0201BA34 */
u32   func_0201104C(void *box);                 /* 0x0201104C */
u32   func_020110CC(void *box);                 /* 0x020110CC */

/* The constant getter that closes the family; src/matched/sub_020111E8.c. */
u32 func_020111E8(void);        /* 0x020111E8  returns 0x15 */

#endif /* NET_SAVE_H */
