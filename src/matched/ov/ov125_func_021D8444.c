/*
 * function: func_021D8444
 * address: 0x021D8444
 * packet: pkt_ov125_021D8444
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * note: pass 5 2026-10-06 P5L06: EXACT (also with --lang c). Written in the style of the matched sibling
 *   021D7A10: d_021D9E40 as a char array read through a D() offset macro (no named base pointer), the
 *   token copy through a named Sav pointer and the 0x138-byte record copy as an int-array struct, under
 *   opt_propagation off. The earlier 14-byte form differed only by a named `char *g` base pointer; with it
 *   the Sav destination took ip and the record copy counter (mov r5,#0x13) was scheduled above the trailing
 *   strb. Without the pragma this form gives the old 18 bytes (source and destination colours swapped).
 * symbols:
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_02168040 0x02168040 arm ov009
 *   func_02059E38 0x02059E38 arm
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021D8D30 0x021D8D30 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[301]; } Sav;
typedef struct { int w[0x138 / 4]; } Blob;
extern int func_02167FA8(const char *, void *);
extern int func_02168040(void);
extern int func_02059E38(int *, int *);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
extern char d_021D9E40[];
extern const char d_021D8D30[];
#define D(o) (*(int *)(d_021D9E40 + (o)))

#pragma opt_propagation off
int func_021D8444(void)
{
    u8 buf[0x174];
    int b, a;
    int r;

    if (D(0x138) == 1)
        return 1;
    if (func_02167FA8(d_021D8D30, buf) == 0) {
        D(0x250) = 0xE;
        return 0;
    }
    for (;;) {
        r = func_02168040();
        if (r == 3) {
            Sav *t = (Sav *)(d_021D9E40 + 6);
            *t = *(Sav *)(buf + 0x45);
            *(Blob *)(*(char **)&D(0x258) + 8) = *(Blob *)d_021D9E40;
            D(0x138) = 1;
            return 1;
        }
        if (r == 4) {
            func_02059E38(&a, &b);
            D(0x250) = 0xE;
            return 0;
        }
        if (r == 5) {
            D(0x250) = 0xE;
            return 0;
        }
        func_021D7CAC();
        if (D(0x268) == 1) {
            D(0x250) = 0xD;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}
#pragma opt_propagation reset
