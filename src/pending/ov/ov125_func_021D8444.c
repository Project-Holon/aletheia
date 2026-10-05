/*
 * function: func_021D8444
 * address: 0x021D8444
 * packet: pkt_ov125_021D8444
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 *
 * 2026-10-04 (wave D2 lane 14): DIFF, 23 bytes, structure right. Sav and Big are the two struct
 * copies (301 bytes by byte loop, 312 bytes by ldm/stm; Big must be a u32 array). Residue: in the
 * 301-byte copy the original puts the global destination in r5 and the stack source in r3; this
 * build swaps them (r3 destination, r5 source), which shifts the next block. The a/b stack order
 * is fixed by declaring b first. Tried: pointer locals for src/dst in both orders, typed extern
 * destination, struct-typed buf. The 312-byte copy source/destination go through d_021D9E40
 * directly (the original reloads the pool word into lr).
 *
 * symbols:
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_02168040 0x02168040 arm ov009
 *   func_02059E38 0x02059E38 arm
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021D9E46 0x021D9E46 data a4
 *   d_021D8D30 0x021D8D30 data a4
 */

/*
 * 2026-10-05 (wave D4 lane07): DIFF, unchanged 23 bytes. Re-read: the 301-byte copy uses r5 (the register that holds the constant 1 for func_021D8438(1)) for the destination d_021D9E46 and r3 for the stack source; the build swaps them, and the trailing byte schedules ldr lr first. No new form found beyond the earlier list; next idea: write the Big copy and the Sav copy through one struct type whose field order puts Sav first, or derive the 1 for func_021D8438 from a local.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 b[301]; } Sav;
typedef struct { u32 w[78]; } Big;
extern int func_02167FA8(const char *, void *);
extern int func_02168040(void);
extern int func_02059E38(int *, int *);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
extern char d_021D9E40[];
extern char d_021D9E46[];
extern const char d_021D8D30[];

int func_021D8444(void)
{
    char *g = d_021D9E40;
    u8 buf[0x174];
    int b, a;
    int r;

    if (*(int *)(g + 0x138) == 1)
        return 1;
    if (func_02167FA8(d_021D8D30, buf) == 0) {
        *(int *)(g + 0x250) = 0xE;
        return 0;
    }
    for (;;) {
        r = func_02168040();
        if (r == 3) {
            *(Sav *)d_021D9E46 = *(Sav *)(buf + 0x45);
            *(Big *)(*(char **)(d_021D9E40 + 0x258) + 8) = *(Big *)d_021D9E40;
            *(int *)(g + 0x138) = 1;
            return 1;
        }
        if (r == 4) {
            func_02059E38(&a, &b);
            *(int *)(g + 0x250) = 0xE;
            return 0;
        }
        if (r == 5) {
            *(int *)(g + 0x250) = 0xE;
            return 0;
        }
        func_021D7CAC();
        if (*(int *)(g + 0x268) == 1) {
            *(int *)(g + 0x250) = 0xD;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}
