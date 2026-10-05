/*
 * function: func_02185794
 * address: 0x02185794
 * packet: pkt_ov219_02185794
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD4 lane19): nested form with 'else if (w != 0xdc) S1 else ZERO' gives 24 bytes (was 25), same layout residue. Or-form (h==0 || (w!=0 && w!=0xdc)) and goto form give 140 bytes, worse.
 * note 2026-10-04 (D2): DIFF, 25 bytes, branch layout of the flag block only; prologue, calls, pool words match.
 *   Original: h==0 test is 'bne X; b S1' (ours 'beq S1'); w==0xdc test is 'bne S1; b ZERO' with one shared S1 block
 *   and S1 stored as 'movs r0,#1; subs r4,#0x60; strh r0,[r5,r4]' (ours reloads the pool offset). Nested if / ||
 *   / goto-to-s1 / goto-to-zero variants tried: the nested if/else-if form kept here is closest (the goto forms
 *   lose the shared zero in r6 and the prologue).
 * 2026-10-05 (wD5 lane20): derived the semantics as: store 0 when h != 0 and (w == 0 or w == 0xdc), else store 1, with the zero shared in r6. Tried the direct form if (h != 0 && (w == 0 || w == 0xdc)) 0 else 1 (73 bytes), the nested if with || in the else-arm form (43 and 32 bytes). The existing nested if / else-if form stays closest (24 bytes).
 * symbols:
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B80 0x02048B80 arm
 *   func_02048B94 0x02048B94 arm
 *   func_02048B60 0x02048B60 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02185AC8 0x02185AC8 thumb ov219
 *   d_02185E0C 0x02185E0C data a4
 *   d_02185DF4 0x02185DF4 data a4
 *   d_020A1C78 0x020A1C78 data
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec3;
typedef struct {char pad[0x30]; short a, b;} Cfg;
extern Vec3 d_02185E0C, d_02185DF4;
extern Cfg d_020A1C78;
extern void func_02048AFC(void *, Vec3 *);
extern void func_02048B44(void *, Vec3 *);
extern void func_02048B80(void *, int);
extern void func_02048B94(void *, int);
extern void func_02048B60(void *, u32 *);
extern void func_02048B6C(void *, u32 *);
extern int func_02185AC8(char *);

void func_02185794(char *p)
{
    u32 a = 0;
    u32 b = 0x19 << 14;
    func_02048AFC(*(void **)(p + 0xC36C), &d_02185E0C);
    func_02048B44(*(void **)(p + 0xC36C), &d_02185DF4);
    func_02048B80(*(void **)(p + 0xC36C), d_020A1C78.a);
    func_02048B94(*(void **)(p + 0xC36C), d_020A1C78.b);
    func_02048B60(*(void **)(p + 0xC36C), &a);
    func_02048B6C(*(void **)(p + 0xC36C), &b);
    if (*(u16 *)(p + 0xC31C) != 0) {
        if (*(u32 *)(p + 0xC33C) == 0)
            *(u16 *)(p + 0xC30C) = 0;
        else if (*(u32 *)(p + 0xC33C) == 0xdc)
            *(u16 *)(p + 0xC30C) = 0;
        else
            *(u16 *)(p + 0xC30C) = 1;
    } else
        *(u16 *)(p + 0xC30C) = 1;
    while (func_02185AC8(p) != 1)
        ;
}
