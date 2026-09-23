/*
 * docs/families/actor_tool.h -- shared declarations for the actor_tool.c
 * family, 0x02025318..0x02025518 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Written wave 16
 * from src/matched/func_02025318.c (the constructor) and
 * src/matched/func_020253D4.c.
 *
 * THE OBJECT, 0x28 bytes (func_02025318 allocates 0x28 and seeds every
 * slot to 0xFF): two banks of sixteen one-byte slots, each bank with its own
 * slot count.  A slot holds 0xFF when free, else the index of the first slot
 * of the run that owns it.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ActorTool {
    u32 f00;
    u8  count[2];         /* +0x04: usable slots per bank (ctor args) */
    u8  slot[2][16];      /* +0x06: 0xFF free, else run start index */
};

/* Every function selects the bank with exactly this shape (the image keeps
 * `movs rN, #1; cmp bank, #0; bne; movs rN, #0`):
 *     u32 sel = 1;
 *     if (bank == 0) sel = 0;
 * and addresses slots as p->slot[sel][j] (`adds rX, base, j; ldrb [rX, #6]`),
 * never as a byte-offset expression, which folds the +6 into the index.   */

struct ActorTool *func_02025318(u32 heap, u8 count0, u8 count1);   /* EXACT* */
int  func_02025360(struct ActorTool *p, int len, u32 bank);   /* DIFF 57, alloc */
void func_020253D4(struct ActorTool *p, u32 i, u32 bank);     /* EXACT, free */

/* LEVER THAT CLOSED func_020253D4: the loop cursor is an `int` while the
 * index it starts from is the u32 parameter (permuter --types).  The open
 * allocator func_02025360 parks p in ip in the image; see
 * docs/notes/pkt_02025360.c.txt for what has been ruled out. */
