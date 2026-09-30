/*
 * function: func_0215BF88
 * address:  0x0215BF88
 * packet:   (none, pending)
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * RESIDUE (lane U34): 41 concrete bytes, 34 sites, size exact at 880.  The
 *           image uses r3 for the bumped `s` and ip for the `mode` mask; this
 *           build is the mirror (s=ip, mode=r3) - both live only in the
 *           caller-saved pool.  Re-tested and inert on the 41-byte residue:
 *           `mode` declared inside the QR2-style inner block vs at function
 *           scope.  First divergence: image `ldrbeq r0, [r5, #0xef]` then
 *           `addeq r3, r5, #0xf0` | ours `addeq ip, r5, #0xf0` then
 *           `ldrbeq r0, [ip, #-1]`; the add and the load are the same two
 *           instructions in either order, only the destination differs.
 *
 * lane4 (w10): a separate pointer `p = s + 0xf0` set inside the `&&` chain as
 *           `(p = s + 0xf0, s[0xef] == 0x63)` (s kept as the un-bumped base, all
 *           option reads through p) puts the `ldrbeq [r5,#0xef]` before the
 *           predicated `add` exactly as the image does: 41 -> 34 bytes.  What is
 *           left is only the r3/ip swap of p and mode (34 sites).  Declaration
 *           order of p/mode (function scope, block scope, first, last) and a
 *           300-compile permuter run are inert.
 *
 * wave8:    re-confirmed 34-byte residue is the pure p/mode r3<->ip swap (34
 *           sites, all uses of both webs; the add, the `and`, every `[r3]`
 *           load and the loop-tail `add r3,r3,r5`).  All inert again:
 *           `u8`/`u16`/`long`/`unsigned long` mode, const pointee, `p = p;`
 *           (block and in the comma), `s = s;`, `result = result;`,
 *           `mode = mode;`, redundant `p = s+0xf0;` in the block, mask operand
 *           order, `if (!mode)`, `mode` function-scope first/last, `p`/`mode`
 *           declaration adjacency, `mode = dhcp_mode; mode &= 2;`, `&s[0xf0]`,
 *           `s[0xef]==.. && (p=..,1)` (predication lost), and removing the
 *           `mode` local so case 6 tests the field directly (868 B, 678 diff:
 *           the explicit local is what makes the compiler hoist it).  Only
 *           `p = p + *p + 1` moved it, to 39.  This is a caller-saved colour
 *           tie the front end resolves against the source order; no source
 *           lever found.
 *
 * sdk:      dhcp_analyze_response (libcps.TWL.HYB.a network.o)
 * notes:    the option-pointer bump is predicated into the `&&` chain by the
 *           vendor front end.  Reachable from C: put the bump INSIDE the
 *           condition as a comma expression,
 *
 *               if (s[0xec] == 0x63 && s[0xed] == 0x82 && s[0xee] == 0x53 &&
 *                   (s += 0xf0, s[-1] == 0x63)) { mode = ...; ... }
 *
 *           which took the residue from 65 to 41 bytes (was: unconditional
 *           `add ip, r5, #0xf0` after the `bne`).  `s[-1] == 0x63` after the
 *           bump is the same byte as the old `s[0xef] == 0x63`, so the
 *           semantics are unchanged.
 *           Residue (34 sites, 41 bytes): the option pointer and the `mode`
 *           mask are one register apart, mirrored.  Image `addeq r3, r5, #0xf0`
 *           (pointer r3) + `and ip, r0, #2` (mask ip) + `ldrbeq r0, [r5, #0xef]`
 *           (load off the OLD base, before the add); ours `addeq ip, r5, #0xf0`
 *           + `ldrbeq r0, [ip, #-1]` (folded onto the NEW base) + `and r3, r0,
 *           #2`.  Every use of the pointer (and every field load off it) follows
 *           the swap.  Inert on the 41-byte residue: `mode` at function scope,
 *           in the inner block, as a declaration initialiser, `int` vs `u32`,
 *           `s = s + 0xf0` inside the comma, `(s += 0xf0, 1)` as a trailing
 *           term, `(s += 0xf0) != 0 && s[-1] == 0x63`, `(s[-1] == 0x63, s +=
 *           0xf0)` (drops the predication, 491), a named `u8 *opt = s` mirror
 *           (65), and `(s += 0xf0)` alone (884).
 *
 * sdk:      dhcp_analyze_response (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_GetTick                       0x020870d0 arm
 *   func_0215B504                    0x0215b504 arm ov009
 *   func_02157390                    0x02157390 arm ov009
 *   func_0215AEB0                    0x0215aeb0 arm ov009
 *   func_021579BC                    0x021579bc arm ov009
 *   func_0215B064                    0x0215b064 arm ov009
 *   g_021A1C9C                       0x021a1c9c data
 *   g_021A82D4                       0x021a82d4 data
 *   g_021A826C                       0x021a826c data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct CPSVars {
    u8 pad0[0xc];
    u32 dhcp_mode;
    u32 netmask;
    u8 pad14[4];
    int (*link_is_on)(void);
    u32 dhcp_server;
    u8 pad20[0x2c - 0x20];
    u32 gateway;
    u8 pad30[0x38 - 0x30];
    u32 offered_myip;
    u32 lease_time;
    u8 pad40[0x50 - 0x40];
    u32 myip;
    u8 pad54[0x70 - 0x54];
    u32 dns[2];
};

extern u8 g_021A1C9C[];
extern u8 g_021A82D4[];
extern struct CPSVars g_021A826C;
extern unsigned long long OS_GetTick(void);
extern u32 func_0215B504(void);
extern void func_02157390(void);
extern u8 *func_0215AEB0(u32 *len);
extern int func_021579BC(u8 *a, u8 *b);
extern void func_0215B064(u32 len);

#define TICK() ((u32)(OS_GetTick() >> 16))
#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))
#define G16(p) ((u16)(((p)[0] << 8) | (p)[1]))
#define G32(p) (((u32)G16(p) << 16) | G16((p) + 2))

int func_0215BF88(u32 id, int retry)
{
    u8 *s;
    u8 *p;
    u8 *end;
    u32 len;
    u32 start;
    int result;
    u32 myip_tmp;
    u8 c;
    long timeout;

    timeout = g_021A1C9C[retry] * 7;
    start = TICK();
    result = 0;
    while (g_021A826C.link_is_on() && result == 0 && (long)(TICK() - start) < timeout) {
        if (func_0215B504() == 0) {
            func_02157390();
            continue;
        }
        s = func_0215AEB0(&len);
        if (len > 0xf0 && s[0] == 2 && NTOHL(s + 4) == id && func_021579BC(s + 0x1c, g_021A82D4) == 0) {
            myip_tmp = G32(s + 0x10);
            end = s + len;
            result = 3;
            u32 mode;
            if (s[0xec] == 0x63 && s[0xed] == 0x82 && s[0xee] == 0x53 && (p = s + 0xf0, s[0xef] == 0x63)) {
                mode = g_021A826C.dhcp_mode & 2;
                while (p < end && (c = *p++) != 0xff) {
                    if (c == 0)
                        continue;
                    switch (c) {
                    case 1:
                        g_021A826C.netmask = G32(p + 1);
                        break;
                    case 3:
                        g_021A826C.gateway = G32(p + 1);
                        break;
                    case 6:
                        if (mode == 0) {
                            if (p[0] < 8)
                                g_021A826C.dns[1] = 0;
                            else
                                g_021A826C.dns[1] = G32(p + 5);
                            g_021A826C.dns[0] = G32(p + 1);
                        }
                        break;
                    case 0x33:
                        g_021A826C.lease_time = G32(p + 1);
                        break;
                    case 0x35:
                        switch (p[1]) {
                        case 2:
                            result = 1;
                            g_021A826C.offered_myip = myip_tmp;
                            break;
                        case 5:
                            result = 2;
                            g_021A826C.myip = myip_tmp;
                            break;
                        }
                        break;
                    case 0x36:
                        g_021A826C.dhcp_server = G32(p + 1);
                        break;
                    }
                    p += *p + 1;
                }
            }
        }
        func_0215B064(len);
    }
    return result;
}
