/*
 * file:     net_whpipe_p11.c
 * unit:     yes
 * function: func_02177B80, func_02177BAC, func_02177BCC, func_02177BF4, func_02177BFC
 * address:  0x02177B80
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4   0x021797A4  data  ov014  a4
 *   d_021797A4  0x021797A4  data  ov014  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 pad0[4];
    u8 kind;
    u8 pad5[3];
    u8 rec[4];
} Sub;

typedef struct {
    u8 pad0[0x50];
    Sub sub;
} S;

u8 func_02177B80(int i);
void func_02177BAC(u32 idx);
void func_02177BCC(void);
void func_02177BF4(unsigned int idx);
u8 *func_02177BFC(S *a0, u8 *out);
extern u8 *g_021797A4;
extern u8 *d_021797A4;



/*
 * Recursive MATCH unblocker: the unlabelled ov014 leaf that the arm9
 * wih_dwc.c pollers call (sub_020107FC +001E, func_0201058C +005C).  Reads
 * the per-slot u16 flag array at g_021797A4+0xC40 (stride 2) and returns the
 * slot's u8 state at +0x5C of the 0xC0-byte record, or 0 when the global or
 * the flag is clear.  func_02178098 is byte-identical.
 */
u8 func_02177B80(int i)
{
    u8 *base = g_021797A4;

    if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0)
        return *(u8 *)(base + 0x5C + i * 0xC0);
    return 0;
}


/*
 * Unlabelled leaf: clears halfword idx of the table at +0xC40 of the
 * object pointed to by the global at 0x021797A4. Blocks func_02177BF4.
 *
 * Addresses are Black-image addresses.
 */
void func_02177BAC(u32 idx)
{
    u8 *p = d_021797A4;
    u16 *h;
    if (p != 0) {
        h = (u16 *)(p + 0xc40);
        if (h[idx] != 0) {
            h[idx] = 0;
        }
    }
}

/*
 * Unlabelled overlay leaf blocking ov010 func_02157760.
 */
void func_02177BCC(void)
{
    u8 *p;
    int i;
    p = d_021797A4;
    if (p != 0) {
        for (i = 0; i < 16; i++)
            *(u16 *)(p + 0xC40 + i * 2) = 0;
    }
}


/*
 * Unlabelled tail-call thunk (ldr r3,[pc]; bx r3) to func_02177BAC.
 * Sole blocker of the func_02164E04 / func_02164D6C MATCHes (ov010).
 *
 * Addresses are Black-image addresses.
 */
void func_02177BF4(unsigned int idx)
{
    func_02177BAC(idx);
}


/*
 * Unlabelled Thumb leaf (prints as .word data in ov014.s), the sole blocker
 * of ov011 func_02173368 +004A: writes the byte at +0x54 through its second
 * argument and returns the address of +0x58.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02177BFC(S *a0, u8 *out)
{
    Sub *s = &a0->sub;

    *out = s->kind;
    return s->rec;
}
