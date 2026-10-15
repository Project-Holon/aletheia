/*
 * function: GSYNC_STATE_BuildMonEntry
 * address: 0x021D7D18
 * packet: pkt_ov123_021D7D18
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: f,v,h,kind,mapped declaration order reproduces the spill slots.
 * interfaces: original outgoing mapped stack words are not narrowed;
 * widen the caller externs accordingly. E0B0 returns its tail target's
 * r0, consumed explicitly by E1A8 here (matched E0B0 says void).
 * symbols:
 *   func_0202A128 0x0202A128 thumb
 *   func_02019D30 0x02019D30 thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_02019D58 0x02019D58 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_0202A19C 0x0202A19C thumb
 *   SYMBOL_SAVE_GetBlock 0x0200E0B0 thumb
 *   SYMBOL_SAVE_WriteRecord 0x0200E1A8 thumb
 *   func_0202A170 0x0202A170 thumb
 */
#include "../include/Obj10446.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0202A128(int);
extern u32 func_02019D30(u32 a, u32 n);
extern int func_02019C90(u16, int, int);
extern int func_02019D58(u16, int);
extern u32 func_020056EC(u32 range);
extern int func_0202A19C(u32, void *, u16, u16, int);
extern void *SYMBOL_SAVE_GetBlock(void *);
extern void SYMBOL_SAVE_WriteRecord(void *, u16, u16, u8, int, u8, u32);
extern void func_0202A170(void *);
void GSYNC_STATE_BuildMonEntry(u8 *p, int unused, int species, int gender, int form, int n, int value)
{
    int f;
    u8 v = value;
    void *h;
    int kind;
    int mapped;
    int g;
    if (species == 0 || species > 493) return;
    h = func_0202A128(((struct Obj10446 *)p)->f0);
    kind = 3;
    f = (int)func_02019D30((u16)species, (u8)form);
    g = func_02019C90(species, f, 20);
    mapped = func_02019D58(species, f);
    switch (g) {
    case 0: gender = 0; break;
    case 254: gender = 1; break;
    case 255: gender = 2; break;
    default: if (gender > 1) gender = func_020056EC(2); break;
    }
    if (func_0202A19C(((struct Obj10446 *)p)->f2C, h, species, gender, mapped)) kind = 2;
    if (v > 8) v = 0;
    SYMBOL_SAVE_WriteRecord(SYMBOL_SAVE_GetBlock(((struct Obj10446 *)p)->f28), species, n, gender, mapped, v, kind);
    func_0202A170(h);
}
