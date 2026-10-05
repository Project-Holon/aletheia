/*
 * function: func_021C0AC8
 * address: 0x021C0AC8
 * packet: pkt_ov110_021C0AC8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD7 lane18): still DIFF (128 vs 124 B), store order now target, size, x, y, z, flag,
 *   e[2].term, mode, w. Finding: the original's `str r1,[sp,#0x38]` is the loop's last `add r1,sp,#0xc`
 *   (the frame address is rematerialised after the call in the loop and still sits in r1 at the exit).
 *   mwcc reuses it only when the constant 1 is not live across the target store; it then emits
 *   `adds r0,r1,#0; str r0` (one copy too many) and the 1 is materialised late in r1 instead of early
 *   in r3. Tried: c.mode = e[2].term = 1 chained (copy), term/mode before size (copy), flag or w before
 *   target (worse, 39 lines), an aggregate initialiser for c (template copy, 5 relocs, worse).
 * 2026-10-05 (wD6 lane14): still DIFF 74 B. Tried: sibling ov021 02197534 store order (size, flag, target, mode, x..w, then term: 68 B), target first after the loop (72), do-while loop (74), an Entry *ep set before the loop and used for every access and for target (74/98), &e as target (74), e and c as one struct {Entry e[3]; Config c;} (75), a temp for the 02045EC0 result (101). Callee arguments checked: none read extra registers. Residue unchanged: target reuses the loop's r1 = sp+0xC.
 * 2026-10-05 (wD5 lane19): still DIFF 74 B (ours 128 B, orig 124). Tried: store orders with target first / mode before size, Entry *target field type, Entry e declared before Config c (71 B), i declared after r, const bank. Orig reuses the loop's `add r1,sp,#0xc` for c.target and puts constant 1 in r3; the compiler never sees the CSE across the loop exit.
 * 2026-10-05 (wD4 lane19): still DIFF 74 bytes. Tried an Entry *ep alias for the loop and c.target = &e[0]: no change. Orig reuses r1 (add r1,sp,#0xC from the loop body) as c.target and keeps constant 1 in r3; ours rematerialises the address.
 * note: 2026-10-04 (wD1 lane17): DIFF. Layout right: 3 entries {void *str; u16 flag=0x39E3; u32 term} at sp+0xC, Config{size,flag,target,mode,x,y,z,w} at sp+0x30, e[2].term=1 stored at [sp,#0x2C]. Residue: orig keeps r3=1 for e[2].term and Config.mode and r1 (left over from the loop's `add r1,sp,#0xC`) as Config.target; ours rematerialises. Decl order Config then Entry, u32 loop counter, store order size,target,x,y,z,flag,mode,w. Tried several store orders.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 *   d_021C3C94 0x021C3C94 data ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Entry { void *str; u16 flag; u16 pad; u32 term; } Entry;
typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x, y, z, w; } Config;
extern const u8 d_021C3C94[];
extern void *func_02045EC0(void *bank, u32 idx);
extern int func_02027778(Config *, void *);
extern void func_02045808(void *);
int func_021C0AC8(void *parent, void *bank, u32 size)
{
    Config c;
    Entry e[3];
    u32 i;
    int r;
    for (i = 0; i < 3; i++) {
        e[i].str = func_02045EC0(bank, d_021C3C94[i]);
        e[i].flag = 0x39E3;
        e[i].term = 0;
    }
c.target = e;
    c.size = size;
    c.x = 0x20;
    c.y = 0x18;
    c.z = 13;
    c.flag = 3;
    e[2].term = 1;
    c.mode = 1;
    c.w = 3;
    
    r = func_02027778(&c, parent);
    for (i = 0; i < 3; i++)
        func_02045808(e[i].str);
    return r;
}
